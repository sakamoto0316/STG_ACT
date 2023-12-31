//========================================================================================
//
//　入力デバイスの処理[input.cpp]
//	Author:sakamoto kai
//
//========================================================================================
#include "input.h"

//マクロ定義
#define GAMEPAD_TRIGGER_DEADZONE (100)	//トリガーのデッドゾーン
#define TRIGGER_MAX (255)	//トリガーのマックス
#define NUM_KEY_MAX (256)	//キーの最大数

//静的メンバ変数宣言
LPDIRECTINPUT8 CInput::m_pInput = NULL;

//入力全体---------------------------------------------------------------------------------------
//====================================================================
//コンストラクタ
//====================================================================
CInput::CInput()
{

}

//====================================================================
//デストラクタ
//====================================================================
CInput::~CInput()
{

}

//====================================================================
//初期化処理
//====================================================================
HRESULT CInput::Init(HINSTANCE hInstance, HWND hWnd)
{
	if (m_pInput == NULL)
	{
		if (FAILED(DirectInput8Create
		(
			hInstance,
			DIRECTINPUT_VERSION,
			IID_IDirectInput8,
			(void**)&m_pInput,
			NULL
		)))
		{
			return E_FAIL;
		}
	}

	return S_OK;
}

//====================================================================
//終了処理
//====================================================================
void CInput::Uninit(void)
{
	//入力デバイスの破棄
	if (pDevice != NULL)
	{
		pDevice->Unacquire();
		pDevice->Release();
		pDevice = NULL;
	}

	//DirectInputオブジェクトの破棄
	if (m_pInput != NULL)
	{
		m_pInput->Release();
		m_pInput = NULL;
	}
}

//====================================================================
//コンストラクタ
//====================================================================
CInputKeyboard::CInputKeyboard()
{

}

//====================================================================
//デストラクタ
//====================================================================
CInputKeyboard::~CInputKeyboard()
{

}

//キーボード---------------------------------------------------------------------------------------
//====================================================================
//初期化処理
//====================================================================
HRESULT CInputKeyboard::Init(HINSTANCE hInstance, HWND hWnd)
{
	CInput::Init(hInstance, hWnd);

	//入力デバイスの設定
	if (FAILED(m_pInput->CreateDevice(GUID_SysKeyboard, &pDevice, NULL)))
	{
		return E_FAIL;
	}

	//データフォーマットを設定
	if (FAILED(pDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}

	//協調モードを設定
	if (FAILED(pDevice->SetCooperativeLevel
	(
		hWnd,
		(DISCL_FOREGROUND | DISCL_NONEXCLUSIVE)
	)))
	{
		return E_FAIL;
	}

	//キーボードへのアクセス権を獲得
	pDevice->Acquire();

	return S_OK;
}

//====================================================================
//終了処理
//====================================================================
void CInputKeyboard::Uninit(void)
{
	CInput::Uninit();
}

//====================================================================
//更新処理
//====================================================================
void CInputKeyboard::Update(void)
{
	BYTE aKeyState[NUM_KEY_MAX]; //キーボードの入力情報

	//入力デバイスからデータを取得
	if (SUCCEEDED(pDevice->GetDeviceState(sizeof(aKeyState), &aKeyState[0])))
	{
		for (int nCntKey = 0; nCntKey < NUM_KEY_MAX; nCntKey++)
		{
			m_aKeyStateRerease[nCntKey] = ~aKeyState[nCntKey] & ((m_aKeyState[nCntKey] ^ aKeyState[nCntKey]) & m_aKeyState[nCntKey]); //キーボードのリリース情報を保存
			m_aKeyStateTrigger[nCntKey] = (m_aKeyState[nCntKey] ^ aKeyState[nCntKey]) & aKeyState[nCntKey]; //キーボードのトリガー情報の保存
			m_aKeyState[nCntKey] = aKeyState[nCntKey]; //キーボードのプレス情報の保存
		}
	}
	else
	{
		pDevice->Acquire(); //キーボードのアクセス権
	}
}

//====================================================================
//キーボードのプレス情報を所得
//====================================================================
bool CInputKeyboard::GetPress(int nKey)
{
	return (m_aKeyState[nKey] & 0x80) ? true : false;
}

//====================================================================
//キーボードのトリガー情報を所得
//====================================================================
bool CInputKeyboard::GetTrigger(int nKey)
{
	return (m_aKeyStateTrigger[nKey] & 0x80) ? true : false;
}

//====================================================================
//キーボードのリリース情報を所得
//====================================================================
bool CInputKeyboard::GetRerease(int nKey)
{
	return (m_aKeyStateRerease[nKey] & 0x80) ? true : false;
}

////ジョイパッド---------------------------------------------------------------------------------------
//====================================================================
//コンストラクタ
//====================================================================
CInputJoypad::CInputJoypad()
{

}

//====================================================================
//デストラクタ
//====================================================================
CInputJoypad::~CInputJoypad()
{

}

//====================================================================
//初期化処理
//====================================================================
HRESULT CInputJoypad::Init(HINSTANCE hInstance, HWND hWnd)
{
	CInput::Init(hInstance, hWnd);

	//Xinputのステートの設定
	XInputEnable(true);
	int nCount;

	for (nCount = 0; nCount < MAX_PLAYER; nCount++)
	{
		//メモリーをクリアする
		memset(&m_JoyKeyState[nCount], 0, sizeof(XINPUT_STATE));
		memset(&m_JoyKeyStateTrigger[nCount], 0, sizeof(XINPUT_STATE));
		memset(&m_JoyKeyStateRelease[nCount], 0, sizeof(XINPUT_STATE));

		m_LStickInput = LSTICK_UP;
		m_OutputDOK = false;
		m_OutputUOK = false;
		m_OutputLOK = false;
		m_OutputROK = false;
	}
	return S_OK;
}

//====================================================================
//終了処理
//====================================================================
void CInputJoypad::Uninit(void)
{
	CInput::Uninit();

	//Xinputのステートの設定
	XInputEnable(false);
}

//====================================================================
//更新処理
//====================================================================
void CInputJoypad::Update(void)
{
	XINPUT_STATE aGamepadState[MAX_PLAYER];	//ゲームパッドの入力処理
	static int nCountSpece = 0;
	int nCntPad = 0;

	for (nCntPad = 0; nCntPad < MAX_PLAYER; nCntPad++)
	{
		//入力デバイスからデータを所得
		if (XInputGetState(nCntPad, &aGamepadState[nCntPad]) == ERROR_SUCCESS)
		{
			m_JoyKeyStateTrigger[nCntPad].Gamepad.wButtons =
				~m_JoyKeyState[nCntPad].Gamepad.wButtons
				& aGamepadState[nCntPad].Gamepad.wButtons;	//トリガー

			m_JoyKeyStateRelease[nCntPad].Gamepad.wButtons =
				((m_JoyKeyState[nCntPad].Gamepad.wButtons
					^ aGamepadState[nCntPad].Gamepad.wButtons)
					& m_JoyKeyState[nCntPad].Gamepad.wButtons);	//リリース

			m_JoyKeyStateTrigger[nCntPad].Gamepad.bLeftTrigger =
				~m_JoyKeyState[nCntPad].Gamepad.bLeftTrigger
				& aGamepadState[nCntPad].Gamepad.bLeftTrigger;	//トリガー

			m_JoyKeyStateTrigger[nCntPad].Gamepad.bRightTrigger =
				~m_JoyKeyState[nCntPad].Gamepad.bRightTrigger
				& aGamepadState[nCntPad].Gamepad.bRightTrigger;	//トリガー

			//m_JoyKeyStateTrigger[nCntPad].Gamepad.bRightTrigger = aGamepadState[nCntPad].Gamepad.bRightTrigger;	//プレス

			m_JoyKeyStateTrigger[nCntPad].Gamepad.sThumbLY =
				~m_JoyKeyState[nCntPad].Gamepad.sThumbLY
				& aGamepadState[nCntPad].Gamepad.sThumbLY;	//トリガー

			m_JoyKeyStateTrigger[nCntPad].Gamepad.sThumbLX =
				~m_JoyKeyState[nCntPad].Gamepad.sThumbLX
				& aGamepadState[nCntPad].Gamepad.sThumbLX;	//トリガー

			m_JoyKeyStateRelease[nCntPad].Gamepad.sThumbLY =
				((m_JoyKeyState[nCntPad].Gamepad.sThumbLY
					^ aGamepadState[nCntPad].Gamepad.sThumbLY)
					& m_JoyKeyState[nCntPad].Gamepad.sThumbLY);	//リリース

			m_JoyKeyState[nCntPad] = aGamepadState[nCntPad];	//プレス
		}
	}
}

//====================================================================
//キーボードのプレス情報を所得
//====================================================================
bool CInputJoypad::GetPress(JOYKEY nKey, int nPlayer)
{
	return (m_JoyKeyState[nPlayer].Gamepad.wButtons & (0x01 << nKey)) ? true : false;
}

//====================================================================
//キーボードのトリガー情報を所得
//====================================================================
bool CInputJoypad::GetTrigger(JOYKEY nKey, int nPlayer)
{
	return (m_JoyKeyStateTrigger[nPlayer].Gamepad.wButtons & (0x01 << nKey)) ? true : false;
}

//====================================================================
//キーボードのリリース情報を所得
//====================================================================
bool CInputJoypad::GetRelease(JOYKEY nKey, int nPlayer)
{
	return (m_JoyKeyStateRelease[nPlayer].Gamepad.wButtons & (0x01 << nKey)) ? true : false;
}

//====================================================================
//ゲームパッドのLスティックの情報を所得
//====================================================================
D3DXVECTOR3 CInputJoypad::Get_Stick_Left(int nPlayer)
{
	//ローカル変数宣言
	D3DXVECTOR3 Stick = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	Stick.x = (float)m_JoyKeyState[nPlayer].Gamepad.sThumbLX / (float)SHRT_MAX;
	//if (fabsf(Stick.x) < (float)XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE / (float)SHRT_MAX)
	//{
	//	Stick.x = 0.0f;
	//}

	Stick.y = (float)m_JoyKeyState[nPlayer].Gamepad.sThumbLY / (float)SHRT_MAX;
	//if (fabsf(Stick.y) < (float)XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE / (float)SHRT_MAX)
	//{
	//	Stick.y = 0.0f;
	//}

	if (Stick.x > 0.5f || Stick.x < -0.5f &&Stick.y > 0.5f || Stick.x < -0.5f)
	{
		D3DXVec3Normalize(&Stick, &Stick);	//ベクトルを正規化する
	}

	return Stick;
}

//====================================================================
//ゲームパッドのLスティックの情報を所得
//====================================================================
bool CInputJoypad::Get_LStick_Trigger(JOYPAD_LSTICK Type, int nPlayer)
{
	//ローカル変数宣言
	float StickX = 0.0f;
	float StickY = 0.0f;
	bool Output = false;

	StickX = (float)m_JoyKeyState[nPlayer].Gamepad.sThumbLX / (float)SHRT_MAX;
	if (fabsf(StickX) < (float)XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE / (float)SHRT_MAX)
	{
		StickX = 0.0f;
	}

	StickY = (float)m_JoyKeyState[nPlayer].Gamepad.sThumbLY / (float)SHRT_MAX;
	if (fabsf(StickY) < (float)XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE / (float)SHRT_MAX)
	{
		StickY = 0.0f;
	}

	switch (Type)
	{
	case LSTICK_UP:
		if (StickY >= 0.8f)
		{
			if (m_OutputUOK == false)
			{
				Output = true;
				m_OutputUOK = true;
			}
		}
		else
		{
			m_OutputUOK = false;
		}
		break;

	case LSTICK_DOWN:

		if (StickY <= -0.8f)
		{
			if (m_OutputDOK == false)
			{
				Output = true;
				m_OutputDOK = true;
			}
		}
		else
		{
			m_OutputDOK = false;
		}
		break;
	case LSTICK_RIGHT:

		if (StickX >= 0.8f)
		{
			if (m_OutputROK == false)
			{
				Output = true;
				m_OutputROK = true;
			}
		}
		else
		{
			m_OutputROK = false;
		}
		break;

	case LSTICK_LEFT:
		if (StickX <= -0.8f)
		{
			if (m_OutputLOK == false)
			{
				Output = true;
				m_OutputLOK = true;
			}
		}
		else
		{
			m_OutputLOK = false;
		}
		break;
	}

	return Output;
}
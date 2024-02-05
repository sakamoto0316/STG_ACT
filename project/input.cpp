//========================================================================================
//
//�@���̓f�o�C�X�̏���[input.cpp]
//	Author:sakamoto kai
//
//========================================================================================
#include "input.h"

//�}�N����`
#define GAMEPAD_TRIGGER_DEADZONE (100)	//�g���K�[�̃f�b�h�]�[��
#define TRIGGER_MAX (255)	//�g���K�[�̃}�b�N�X
#define NUM_KEY_MAX (256)	//�L�[�̍ő吔

//�ÓI�����o�ϐ��錾
LPDIRECTINPUT8 CInput::m_pInput = NULL;

//���͑S��---------------------------------------------------------------------------------------
//====================================================================
//�R���X�g���N�^
//====================================================================
CInput::CInput()
{

}

//====================================================================
//�f�X�g���N�^
//====================================================================
CInput::~CInput()
{

}

//====================================================================
//����������
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
//�I������
//====================================================================
void CInput::Uninit(void)
{
	//���̓f�o�C�X�̔j��
	if (pDevice != NULL)
	{
		pDevice->Unacquire();
		pDevice->Release();
		pDevice = NULL;
	}

	//DirectInput�I�u�W�F�N�g�̔j��
	if (m_pInput != NULL)
	{
		m_pInput->Release();
		m_pInput = NULL;
	}
}

//====================================================================
//�R���X�g���N�^
//====================================================================
CInputKeyboard::CInputKeyboard()
{

}

//====================================================================
//�f�X�g���N�^
//====================================================================
CInputKeyboard::~CInputKeyboard()
{

}

//�L�[�{�[�h---------------------------------------------------------------------------------------
//====================================================================
//����������
//====================================================================
HRESULT CInputKeyboard::Init(HINSTANCE hInstance, HWND hWnd)
{
	CInput::Init(hInstance, hWnd);

	//���̓f�o�C�X�̐ݒ�
	if (FAILED(m_pInput->CreateDevice(GUID_SysKeyboard, &pDevice, NULL)))
	{
		return E_FAIL;
	}

	//�f�[�^�t�H�[�}�b�g��ݒ�
	if (FAILED(pDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}

	//�������[�h��ݒ�
	if (FAILED(pDevice->SetCooperativeLevel
	(
		hWnd,
		(DISCL_FOREGROUND | DISCL_NONEXCLUSIVE)
	)))
	{
		return E_FAIL;
	}

	//�L�[�{�[�h�ւ̃A�N�Z�X�����l��
	pDevice->Acquire();

	return S_OK;
}

//====================================================================
//�I������
//====================================================================
void CInputKeyboard::Uninit(void)
{
	CInput::Uninit();
}

//====================================================================
//�X�V����
//====================================================================
void CInputKeyboard::Update(void)
{
	BYTE aKeyState[NUM_KEY_MAX]; //�L�[�{�[�h�̓��͏��

	//���̓f�o�C�X����f�[�^���擾
	if (SUCCEEDED(pDevice->GetDeviceState(sizeof(aKeyState), &aKeyState[0])))
	{
		for (int nCntKey = 0; nCntKey < NUM_KEY_MAX; nCntKey++)
		{
			m_aKeyStateRerease[nCntKey] = ~aKeyState[nCntKey] & ((m_aKeyState[nCntKey] ^ aKeyState[nCntKey]) & m_aKeyState[nCntKey]); //�L�[�{�[�h�̃����[�X����ۑ�
			m_aKeyStateTrigger[nCntKey] = (m_aKeyState[nCntKey] ^ aKeyState[nCntKey]) & aKeyState[nCntKey]; //�L�[�{�[�h�̃g���K�[���̕ۑ�
			m_aKeyState[nCntKey] = aKeyState[nCntKey]; //�L�[�{�[�h�̃v���X���̕ۑ�
		}
	}
	else
	{
		pDevice->Acquire(); //�L�[�{�[�h�̃A�N�Z�X��
	}
}

//====================================================================
//�L�[�{�[�h�̃v���X��������
//====================================================================
bool CInputKeyboard::GetPress(int nKey)
{
	return (m_aKeyState[nKey] & 0x80) ? true : false;
}

//====================================================================
//�L�[�{�[�h�̃g���K�[��������
//====================================================================
bool CInputKeyboard::GetTrigger(int nKey)
{
	return (m_aKeyStateTrigger[nKey] & 0x80) ? true : false;
}

//====================================================================
//�L�[�{�[�h�̃����[�X��������
//====================================================================
bool CInputKeyboard::GetRerease(int nKey)
{
	return (m_aKeyStateRerease[nKey] & 0x80) ? true : false;
}

////�W���C�p�b�h---------------------------------------------------------------------------------------
//====================================================================
//�R���X�g���N�^
//====================================================================
CInputJoypad::CInputJoypad()
{

}

//====================================================================
//�f�X�g���N�^
//====================================================================
CInputJoypad::~CInputJoypad()
{

}

//====================================================================
//����������
//====================================================================
HRESULT CInputJoypad::Init(HINSTANCE hInstance, HWND hWnd)
{
	CInput::Init(hInstance, hWnd);

	//Xinput�̃X�e�[�g�̐ݒ�
	XInputEnable(true);
	int nCount;

	for (nCount = 0; nCount < MAX_PLAYER; nCount++)
	{
		//�������[���N���A����
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
//�I������
//====================================================================
void CInputJoypad::Uninit(void)
{
	CInput::Uninit();

	//Xinput�̃X�e�[�g�̐ݒ�
	XInputEnable(false);
}

//====================================================================
//�X�V����
//====================================================================
void CInputJoypad::Update(void)
{
	XINPUT_STATE aGamepadState[MAX_PLAYER];	//�Q�[���p�b�h�̓��͏���
	static int nCountSpece = 0;
	int nCntPad = 0;

	for (nCntPad = 0; nCntPad < MAX_PLAYER; nCntPad++)
	{
		//���̓f�o�C�X����f�[�^������
		if (XInputGetState(nCntPad, &aGamepadState[nCntPad]) == ERROR_SUCCESS)
		{
			m_JoyKeyStateTrigger[nCntPad].Gamepad.wButtons =
				~m_JoyKeyState[nCntPad].Gamepad.wButtons
				& aGamepadState[nCntPad].Gamepad.wButtons;	//�g���K�[

			m_JoyKeyStateRelease[nCntPad].Gamepad.wButtons =
				((m_JoyKeyState[nCntPad].Gamepad.wButtons
					^ aGamepadState[nCntPad].Gamepad.wButtons)
					& m_JoyKeyState[nCntPad].Gamepad.wButtons);	//�����[�X

			m_JoyKeyStateTrigger[nCntPad].Gamepad.bLeftTrigger =
				~m_JoyKeyState[nCntPad].Gamepad.bLeftTrigger
				& aGamepadState[nCntPad].Gamepad.bLeftTrigger;	//�g���K�[

			m_JoyKeyStateTrigger[nCntPad].Gamepad.bRightTrigger =
				~m_JoyKeyState[nCntPad].Gamepad.bRightTrigger
				& aGamepadState[nCntPad].Gamepad.bRightTrigger;	//�g���K�[

			//m_JoyKeyStateTrigger[nCntPad].Gamepad.bRightTrigger = aGamepadState[nCntPad].Gamepad.bRightTrigger;	//�v���X

			m_JoyKeyStateTrigger[nCntPad].Gamepad.sThumbLY =
				~m_JoyKeyState[nCntPad].Gamepad.sThumbLY
				& aGamepadState[nCntPad].Gamepad.sThumbLY;	//�g���K�[

			m_JoyKeyStateTrigger[nCntPad].Gamepad.sThumbLX =
				~m_JoyKeyState[nCntPad].Gamepad.sThumbLX
				& aGamepadState[nCntPad].Gamepad.sThumbLX;	//�g���K�[

			m_JoyKeyStateRelease[nCntPad].Gamepad.sThumbLY =
				((m_JoyKeyState[nCntPad].Gamepad.sThumbLY
					^ aGamepadState[nCntPad].Gamepad.sThumbLY)
					& m_JoyKeyState[nCntPad].Gamepad.sThumbLY);	//�����[�X

			m_JoyKeyState[nCntPad] = aGamepadState[nCntPad];	//�v���X
		}
	}
}

//====================================================================
//�L�[�{�[�h�̃v���X��������
//====================================================================
bool CInputJoypad::GetPress(JOYKEY nKey, int nPlayer)
{
	return (m_JoyKeyState[nPlayer].Gamepad.wButtons & (0x01 << nKey)) ? true : false;
}

//====================================================================
//�L�[�{�[�h�̃g���K�[��������
//====================================================================
bool CInputJoypad::GetTrigger(JOYKEY nKey, int nPlayer)
{
	return (m_JoyKeyStateTrigger[nPlayer].Gamepad.wButtons & (0x01 << nKey)) ? true : false;
}

//====================================================================
//�L�[�{�[�h�̃����[�X��������
//====================================================================
bool CInputJoypad::GetRelease(JOYKEY nKey, int nPlayer)
{
	return (m_JoyKeyStateRelease[nPlayer].Gamepad.wButtons & (0x01 << nKey)) ? true : false;
}

//====================================================================
//�Q�[���p�b�h��L�X�e�B�b�N�̏�������
//====================================================================
D3DXVECTOR3 CInputJoypad::Get_Stick_Left(int nPlayer)
{
	//���[�J���ϐ��錾
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
		D3DXVec3Normalize(&Stick, &Stick);	//�x�N�g���𐳋K������
	}

	return Stick;
}

//====================================================================
//�Q�[���p�b�h��L�X�e�B�b�N�̏�������
//====================================================================
bool CInputJoypad::Get_LStick_Trigger(JOYPAD_LSTICK Type, int nPlayer)
{
	//���[�J���ϐ��錾
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
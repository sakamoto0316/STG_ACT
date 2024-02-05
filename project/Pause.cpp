//============================================
//
//	�|�[�Y���� [Pause.cpp]
//	Author:sakamoto kai
//
//============================================
#include "Pause.h"
#include "manager.h"
#include "input.h"
#include "texture.h"
#include "object2D.h"
#include "Fade.h"
#include "sound.h"

//�ÓI�����o�ϐ��錾
CObject2D *CPause::m_pPauseUI[MAX_PAUSE] = {};
CObject2D *CPause::m_pPauseFG = NULL;

//====================================================================
//�R���X�g���N�^
//====================================================================
CPause::CPause()
{
	m_PauseSelect = 0;
	m_Appear = false;
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CPause::~CPause()
{

}

//====================================================================
//��������
//====================================================================
CPause *CPause::Create()
{
	CPause *pPause = NULL;

	if (pPause == NULL)
	{
		//�G�̐���
		pPause = new CPause();
	}

	//�I�u�W�F�N�g�̏���������
	if (FAILED(pPause->Init()))
	{//���������������s�����ꍇ
		return NULL;
	}

	return pPause;
}

//====================================================================
//����������
//====================================================================
HRESULT CPause::Init(void)
{
	m_pPauseFG = CObject2D::Create();
	m_pPauseFG->SetPos(D3DXVECTOR3(640.0f, 360.0f, 0.0f));
	m_pPauseFG->SetWight(1280.0f);
	m_pPauseFG->SetHeight(720.0f);
	m_pPauseFG->SetColor(D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.5f));

	for (int nCnt = 0; nCnt < MAX_PAUSE; nCnt++)
	{
		m_pPauseUI[nCnt] = CObject2D::Create();
		switch (nCnt)
		{
		case 0:
			m_pPauseUI[nCnt]->SetWight(200.0f);
			m_pPauseUI[nCnt]->SetHeight(100.0f);
			break;
		case 1:
			m_pPauseUI[nCnt]->SetWight(220.0f);
			m_pPauseUI[nCnt]->SetHeight(120.0f);
			break;
		case 2:
			m_pPauseUI[nCnt]->SetWight(240.0f);
			m_pPauseUI[nCnt]->SetHeight(140.0f);
			break;
		case 3:
			m_pPauseUI[nCnt]->SetWight(200.0f);
			m_pPauseUI[nCnt]->SetHeight(100.0f);
			break;
		}
		m_pPauseUI[nCnt]->SetPos(D3DXVECTOR3(640.0f, 300.0f + nCnt * 100.0f, 0.0f));
		m_pPauseUI[nCnt]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.75f));
	}
	m_pPauseUI[0]->SetTexture("data\\TEXTURE\\BACK_GAME.png");
	m_pPauseUI[1]->SetTexture("data\\TEXTURE\\BACK_RETRY.png");
	m_pPauseUI[2]->SetTexture("data\\TEXTURE\\BACK_TUTORIAL.png");
	m_pPauseUI[3]->SetTexture("data\\TEXTURE\\BACK_TITLE.png");

	return S_OK;
}

//====================================================================
//�I������
//====================================================================
void CPause::Uninit(void)
{

}

//====================================================================
//�X�V����
//====================================================================
void CPause::Update(void)
{
	//�L�[�{�[�h�̎擾
	CInputKeyboard *pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();
	CInputJoypad *pInputJoypad = CManager::GetInstance()->GetInputJoyPad();

	if (CManager::GetInstance()->GetPause() == true)
	{
		if (pInputKeyboard->GetTrigger(DIK_W) == true ||
			pInputJoypad->GetTrigger(CInputJoypad::BUTTON_UP, 0) == true ||
			pInputJoypad->Get_LStick_Trigger(CInputJoypad::LSTICK_UP, 0) == true)
		{
			CManager::GetInstance()->GetSound()->PlaySoundA(CSound::SOUND_LABEL_SE_SELECT_PUSH);
			m_PauseSelect--;

			if (m_PauseSelect < 0)
			{
				m_PauseSelect = MAX_PAUSE - 1;
			}
		}

		if (pInputKeyboard->GetTrigger(DIK_S) == true ||
			pInputJoypad->GetTrigger(CInputJoypad::BUTTON_DOWN, 0) == true ||
			pInputJoypad->Get_LStick_Trigger(CInputJoypad::LSTICK_DOWN, 0) == true)
		{
			CManager::GetInstance()->GetSound()->PlaySoundA(CSound::SOUND_LABEL_SE_SELECT_PUSH);
			m_PauseSelect++;

			if (m_PauseSelect > MAX_PAUSE - 1)
			{
				m_PauseSelect = 0;
			}
		}

		for (int nCnt = 0; nCnt < MAX_PAUSE; nCnt++)
		{
			if (nCnt == m_PauseSelect)
			{
				m_pPauseUI[nCnt]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
			}
			else
			{
				m_pPauseUI[nCnt]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.75f));
			}
		}

		if (CManager::GetInstance()->GetInputKeyboard()->GetTrigger(DIK_RETURN) == true ||
			CManager::GetInstance()->GetInputJoyPad()->GetTrigger(CInputJoypad::BUTTON_A, 0) == true ||
			CManager::GetInstance()->GetInputJoyPad()->GetTrigger(CInputJoypad::BUTTON_B, 0) == true)
		{
			CManager::GetInstance()->GetSound()->PlaySoundA(CSound::SOUND_LABEL_SE_ENTER_PUSH);

			switch (m_PauseSelect)
			{
			case 0:
				break;
			case 1:
				CManager::GetInstance()->SetTutorialStart(false);
				CFade::SetFade(CScene::MODE_GAME);
				break;
			case 2:
				CManager::GetInstance()->SetTutorialStart(true);
				CFade::SetFade(CScene::MODE_GAME);
				break;
			case 3:
				CFade::SetFade(CScene::MODE_TITLE);
				break;
			default:
				CFade::SetFade(CScene::MODE_GAME);
				break;
			}
			CManager::GetInstance()->SetPause(false);
			m_Appear = false;
		}
	}

	if (m_Appear == true)
	{
		for (int nCnt = 0; nCnt < MAX_PAUSE; nCnt++)
		{
			m_pPauseUI[nCnt]->SetAppear(true);
		}
		m_pPauseFG->SetAppear(true);
	}
	else
	{
		for (int nCnt = 0; nCnt < MAX_PAUSE; nCnt++)
		{
			m_pPauseUI[nCnt]->SetAppear(false);
		}
		m_pPauseFG->SetAppear(false);
	}
}

//====================================================================
//�`�揈��
//====================================================================
void CPause::Draw(void)
{

}
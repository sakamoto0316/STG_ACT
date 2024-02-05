//============================================
//
//	�}�l�[�W�� [manager.cpp]
//	Author:sakamoto kai
//
//============================================
#include "manager.h"
#include "renderer.h"
#include "debugproc.h"
#include "input.h"
#include "camera.h"
#include "light.h"
#include "LevelUP.h"
#include "objectX.h"
#include "texture.h"
#include "XModel.h"
#include "title.h"
#include "game.h"
#include "result.h"
#include "fade.h"
#include "Pause.h"
#include "sound.h"
#include "Map2D.h"

#define SET_MODE (CScene::MODE_TITLE)

//�ÓI�����o�ϐ��錾
CManager* CManager::pManager = NULL;
CScene::MODE CScene::m_mode = SET_MODE;

//====================================================================
//�R���X�g���N�^
//====================================================================
CManager::CManager()
{
	m_bEdit = false;
	m_bStop = false;
	m_SetTutorial = false;
	m_Pause = false;
	m_SetScoreResult = false;
	m_SetJoyPad = false;
	m_PauseOK = false;
	m_EndScore = 0;
	m_EndCombo = 0;
	m_EndFall = 0;
	m_EndDepth = 0;
	m_pRenderer = NULL;
	m_pDebugProc = NULL;
	m_pInputKeyboard = NULL;
	m_pInputJoyPad = NULL;
	m_pCamera = NULL;
	m_pLight = NULL;
	m_pTexture = NULL;
	m_pXModel = NULL;
	m_pScene = NULL;
	m_LevelUP = NULL;
	m_Fade = NULL;
	m_pSound = NULL;
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CManager::~CManager()
{

}

//====================================================================
//����������
//====================================================================
CManager* CManager::GetInstance(void)
{
	if (pManager == NULL)
	{
		pManager = new CManager;
	}
	return pManager;
}

//====================================================================
//����������
//====================================================================
HRESULT CManager::Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	if (m_pRenderer == NULL)
	{
		//�����_���[�̐���
		m_pRenderer = new CRenderer;
	}

	//�����_���[�̏���������
	if (FAILED(m_pRenderer->Init(hInstance, hWnd, TRUE)))
	{//���������������s�����ꍇ
		return E_FAIL;
	}

	if (m_pDebugProc == NULL)
	{
		//�f�o�b�O�\���̐���
		m_pDebugProc = new CDebugProc;

		if (m_pDebugProc != NULL)
		{
			m_pDebugProc->Init();
		}
	}

	if (m_pSound == NULL)
	{
		//�T�E���h�̐���
		m_pSound = new CSound;
	}

	//�T�E���h�̏���������
	if (FAILED(m_pSound->InitSound(hWnd)))
	{//���������������s�����ꍇ
		return E_FAIL;
	}

	if (m_pInputKeyboard == NULL)
	{
		//�L�[�{�[�h�̐���
		m_pInputKeyboard = new CInputKeyboard;
	}

	if (m_pInputJoyPad == NULL)
	{
		//�W���C�p�b�h�̐���
		m_pInputJoyPad = new CInputJoypad;
	}

	//�L�[�{�[�h�̏���������
	if (FAILED(m_pInputKeyboard->Init(hInstance, hWnd)))
	{//���������������s�����ꍇ
		return E_FAIL;
	}

	if (m_pCamera == NULL)
	{
		//�J�����̐���
		m_pCamera = new CCamera;
	}

	//�J�����̏���������
	if (FAILED(m_pCamera->Init()))
	{//���������������s�����ꍇ
		return E_FAIL;
	}

	if (m_pLight == NULL)
	{
		//���C�g�̐���
		m_pLight = new CLight;
	}

	//���C�g�̏���������
	if (FAILED(m_pLight->Init()))
	{//���������������s�����ꍇ
		return E_FAIL;
	}

	if (m_pTexture == NULL)
	{
		//�e�N�X�`���̐���
		m_pTexture = new CTexture;
	}

	//�S�Ẵe�N�X�`���̓ǂݍ���
	if (FAILED(m_pTexture->Load()))
	{//�ǂݍ��݂����s�����ꍇ
		return E_FAIL;
	}

	if (m_pXModel == NULL)
	{
		//X���f���̐���
		m_pXModel = new CXModel;
	}

	//�S�Ă�X���f���̓ǂݍ���
	if (FAILED(m_pXModel->Load()))
	{//�ǂݍ��݂����s�����ꍇ
		return E_FAIL;
	}

	if (m_pScene == NULL)
	{
		m_pScene = CScene::Create(SET_MODE);
	}

	if (m_Fade == NULL)
	{
		//�t�F�[�h�̐���
		m_Fade = new CFade;

		if (m_Fade != NULL)
		{
			m_Fade->Init(SET_MODE);
		}
	}

	//////�w�i�e�N�X�`���̓ǂݍ���
	////CObjectBG::Load();

	//////���d�w�i�̐���
	////CMultiBG::Create();

	return S_OK;
}

//====================================================================
//�I������
//====================================================================
void CManager::Uninit(void)
{
	//BGM�̒�~
	m_pSound->StopSound();

	//�S�ẴI�u�W�F�N�g�̔j��
	CObject::ReleaseAll();

	////�S�ẴI�u�W�F�N�g�̔j��
	//CObjectMap2D::ReleaseAll();

	////�w�i�e�N�X�`���̔j��
	//CObjectBG::Unload();

	////�A�C�e���e�N�X�`���̔j��
	//CGuide::Unload();

	if (m_Fade != NULL)
	{
		//�t�F�[�h�̏I������
		m_Fade->Uninit();

		delete m_Fade;
		m_Fade = NULL;
	}

	if (m_pScene != NULL)
	{
		//�V�[���̏I������
		m_pScene->Uninit();

		delete m_pScene;
		m_pScene = NULL;
	}

	if (m_pTexture != NULL)
	{
		//�e�N�X�`���̏I������
		m_pTexture->Unload();

		delete m_pTexture;
		m_pTexture = NULL;
	}

	if (m_pXModel != NULL)
	{
		//X���f���̏I������
		m_pXModel->Unload();

		delete m_pXModel;
		m_pXModel = NULL;
	}

	if (m_pLight != NULL)
	{
		//���C�g�̏I������
		m_pLight->Uninit();

		delete m_pLight;
		m_pLight = NULL;
	}

	if (m_pCamera != NULL)
	{
		//�J�����̏I������
		m_pCamera->Uninit();

		delete m_pCamera;
		m_pCamera = NULL;
	}

	if (m_pInputJoyPad != NULL)
	{
		//�W���C�p�b�h�̏I������
		m_pInputJoyPad->Uninit();

		delete m_pInputJoyPad;
		m_pInputJoyPad = NULL;
	}

	if (m_pInputKeyboard != NULL)
	{
		//�L�[�{�[�h�̏I������
		m_pInputKeyboard->Uninit();

		delete m_pInputKeyboard;
		m_pInputKeyboard = NULL;
	}

	if (m_pDebugProc != NULL)
	{
		//�f�o�b�O�\���̏I������
		m_pDebugProc->Uninit();

		delete m_pDebugProc;
		m_pDebugProc = NULL;
	}

	if (m_pRenderer != NULL)
	{
		//�����_���[�̏I������
		m_pRenderer->Uninit();

		delete m_pRenderer;
		m_pRenderer = NULL;
	}

	if (m_pSound != NULL)
	{
		//�T�E���h�̏I������
		m_pSound->UninitSound();

		delete m_pSound;
		m_pSound = NULL;
	}
}

//====================================================================
//�X�V����
//====================================================================
void CManager::Update(void)
{
	if (m_LevelUP != NULL)
	{
		m_LevelUP->Update();
	}

	//�J�����̍X�V����
	m_pCamera->Update();

	//���C�g�̍X�V����
	m_pLight->Update();

	//�L�[�{�[�h�̍X�V����
	m_pInputKeyboard->Update();

	//�W���C�p�b�h�̍X�V����
	m_pInputJoyPad->Update();

	//�f�o�b�O�\���̍X�V����
	m_pDebugProc->Update();

	//�f�o�b�O�\��
	m_pDebugProc->Print("FPS : %d\n", GetFps());
	m_pDebugProc->Print("�ړ� ([A:��] [D:��])\n");
	m_pDebugProc->Print("�W�����v [W]\n");
	m_pDebugProc->Print("�e���� [SPACE]\n");
	m_pDebugProc->Print("���Z�b�g���� [R]\n");
	m_pDebugProc->Print("�e���˕������� ([Q:��] [E:��])\n");

#ifdef _DEBUG

	if (CManager::GetInputKeyboard()->GetTrigger(DIK_F2) == true &&
		CScene::GetMode() == CScene::MODE_GAME)
	{
		//�����H �����P�F�����Q;
		m_bEdit = m_bEdit ? false : true;
		CObject::DeleteBlock();
		CGame::GetMap2D()->CleanBlockUse();
	}
#endif

	if ((CManager::GetInputKeyboard()->GetTrigger(DIK_P) == true ||
		CManager::GetInputJoyPad()->GetTrigger(CInputJoypad::BUTTON_START, 0) == true) &&
		CScene::GetMode() == CScene::MODE_GAME &&
		m_PauseOK == true)
	{
		if (CGame::GetTutorial() == false)
		{
			//�����H �����P�F�����Q;
			m_Pause = m_Pause ? false : true;

			if (m_Pause == true)
			{
				CGame::GetPause()->SetAppear(true);
			}
			else
			{
				CGame::GetPause()->SetAppear(false);
			}
		}
	}

	//�V�[���̍X�V����
	m_pScene->Update();

	//�����_���[�̍X�V����
	m_pRenderer->Update();

	//�t�F�[�h�̍X�V����
	m_Fade->Update();
}

//====================================================================
//�`�揈��
//====================================================================
void CManager::Draw(void)
{
	//�����_���[�̕`�揈��
	m_pRenderer->Draw();
}

//====================================================================
//��������
//====================================================================
CScene *CScene::Create(MODE mode)
{
	CScene *pScene = NULL;

	if (pScene == NULL)
	{
		//�V�[���̐���
		switch (mode)
		{
		case MODE_TITLE:
			pScene = new CTitle();
			break;
		case MODE_GAME:
			pScene = new CGame();
			break;
		case MODE_RESULT:
			pScene = new CResult();
			break;
		}
	}

	CManager::GetInstance()->GetCamera()->ResetCamera();

	CManager::GetInstance()->SetEdit(false);

	m_mode = mode;

	if (m_mode == MODE_GAME)
	{
		CGame::SetTutorialStart(CManager::GetInstance()->GetTutorialStart());
	}

	//�I�u�W�F�N�g�̏���������
	if (FAILED(pScene->Init()))
	{//���������������s�����ꍇ
		return NULL;
	}

	return pScene;
}

//====================================================================
//�R���X�g���N�^
//====================================================================
CScene::CScene()
{

}

//====================================================================
//�f�X�g���N�^
//====================================================================
CScene::~CScene()
{
}

//====================================================================
//����������
//====================================================================
HRESULT CScene::Init(void)
{
	CScene *m_pScene = CManager::GetInstance()->GetScene();

	m_pScene->Init();

	return S_OK;
}

//====================================================================
//�I������
//====================================================================
void CScene::Uninit(void)
{
	CScene *m_pScene = CManager::GetInstance()->GetScene();

	m_pScene->Uninit();
}

//====================================================================
//�X�V����
//====================================================================
void CScene::Update(void)
{
	CScene *m_pScene = CManager::GetInstance()->GetScene();

	m_pScene->Update();
}

//====================================================================
//�`�揈��
//====================================================================
void CScene::Draw(void)
{
	CScene *m_pScene = CManager::GetInstance()->GetScene();

	m_pScene->Draw();
}

//====================================================================
//���[�h�ݒ菈��
//====================================================================
void CScene::SetMode(MODE mode)
{
	CScene *pScene = CManager::GetInstance()->GetScene();
	CManager::GetInstance()->GetSound()->StopSound();

	if (pScene != NULL)
	{
		//�V�[���̏I������
		pScene->Uninit();

		delete pScene;
		pScene = NULL;
	}

	//���[�h�̐���
	pScene = Create(mode);

	CManager::GetInstance()->SetScene(pScene);
}
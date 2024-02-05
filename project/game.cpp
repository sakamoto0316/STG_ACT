//============================================
//
//	�Q�[����� [game.cpp]
//	Author:sakamoto kai
//
//============================================
#include "game.h"
#include "manager.h"
#include "fade.h"
#include "input.h"
#include "object.h"
#include "object2D.h"
#include "map2D.h"
#include "player3D.h"
#include "score.h"
#include "playerlevel.h"
#include "bosslevel.h"
#include "break_block3D.h"
#include "Edit.h"
#include "TutorialUI.h"
#include "ForeGround2D.h"
#include "Pause.h"
#include "ranking.h"
#include "camera.h"
#include "Break.h"
#include "game.h"
#include "sound.h"

//�ÓI�����o�ϐ��錾
CPlayer3D *CGame::m_pPlayer3D = NULL;
CMap2D *CGame::m_pMap2D = NULL;
CPlayerLevel *CGame::m_pPlayerLevel = NULL;
CBossLevel *CGame::m_pBossLevel = NULL;
CBreak_Block3D *CGame::m_pBlock3D = NULL;
CEdit *CGame::m_pEdit = NULL;
CTutorialUI *CGame::m_pTutorialUI = NULL;
CObject2D *CGame::m_pTutorialBG = NULL;
CObject2D *CGame::m_pTutorialText = NULL;
CPause *CGame::m_pPause = NULL;
CScore *CGame::m_pScore = NULL;
CObject2D* CGame::m_pScoreText = NULL;
CObject2D* CGame::m_pEventText = NULL;
CObject2D *CGame::m_pEventTextBG = NULL;
bool CGame::m_bGSEvent = false;
bool CGame::m_bGSEventCamera = false;
bool CGame::m_bEvent = false;
bool CGame::m_bEventStart = false;
bool CGame::m_bGameEnd = false;
bool CGame::m_bTutorial = true;
int CGame::m_nTutorialCount = 0;
bool CGame::m_bUseTutorialUI = false;
int CGame::m_bGameEndTime = 0;
bool CGame::m_bTextColor = false;
float CGame::m_fTextColor = 0.0f;
float CGame::m_fEventTextColor = 0.0f;

//====================================================================
//�R���X�g���N�^
//====================================================================
CGame::CGame()
{
	m_nTutorialCount = 0;
	m_bTextColor = false;
	m_bEventStart = false;
	m_fTextColor = 0.0f;

	m_GSEventCount = 0;
	m_bGSEvent = false;
	m_bGSEventEnd = false;
	m_bGSEventCamera = false;
	m_fEventTextColor = 0.0f;

	CManager::GetInstance()->SetPauseOK(false);
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CGame::~CGame()
{

}

//====================================================================
//����������
//====================================================================
HRESULT CGame::Init(void)
{
	CManager::GetInstance()->GetSound()->PlaySoundA(CSound::SOUND_LABEL_BGM_TUTORIAL);

	m_bGameEnd = false;

	//�}�b�v�̐���
	if (m_pMap2D == NULL)
	{
		m_pMap2D = CMap2D::Create();
	}

	m_pScoreText = CObject2D::Create();
	m_pScoreText->SetPos(D3DXVECTOR3(910.0f, 45.0f, 0.0f));
	m_pScoreText->SetWight(150.0f);
	m_pScoreText->SetHeight(40.0f);
	m_pScoreText->SetTexture("data\\TEXTURE\\SCORE_UI.png");

	//�X�R�A�̐���
	m_pScore = CScore::Create();
	m_pScore->SetPos(D3DXVECTOR3(980.0f, 45.0f, 0.0f));
	m_pScore->SetWight(45.0f);
	m_pScore->SetHeight(45.0f);
	m_pScore->SetScore(0);

	//�e�X�g�p
	m_pBlock3D = CBreak_Block3D::Create();
	m_pBlock3D->bUseSet();
	m_pBlock3D->SetPos(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	m_pBlock3D->SetWNumber(5);
	m_pBlock3D = CBreak_Block3D::Create();
	m_pBlock3D->SetPos(D3DXVECTOR3(-80.0f, 0.0f, 0.0f));
	m_pBlock3D->SetWNumber(5);
	m_pBlock3D = CBreak_Block3D::Create();
	m_pBlock3D->SetPos(D3DXVECTOR3(80.0f, 0.0f, 0.0f));
	m_pBlock3D->SetWNumber(5);
	m_pBlock3D = CBreak_Block3D::Create();
	m_pBlock3D->SetPos(D3DXVECTOR3(-40.0f, 0.0f, 0.0f));
	m_pBlock3D->SetWNumber(5);
	m_pBlock3D = CBreak_Block3D::Create();
	m_pBlock3D->SetPos(D3DXVECTOR3(40.0f, 0.0f, 0.0f));
	m_pBlock3D->SetWNumber(5);

	//�e�X�g�p
	for (int nCnt = 0; nCnt < 13; nCnt++)
	{
		m_pBlock3D = CBreak_Block3D::Create();
		m_pBlock3D->SetPos(D3DXVECTOR3(-240 + 40.0f * nCnt, -2540.0f, 0.0f));
		m_pBlock3D->SetWNumber(5);
	}

	m_pTutorialBG = CObject2D::Create(7);
	m_pTutorialBG->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
	m_pTutorialBG->SetType(CObject::TYPE_TUTORIALUI);
	m_pTutorialBG->SetTexture("data\\TEXTURE\\Test.jpg");
	m_pTutorialBG->SetPos(D3DXVECTOR3(640.0f, 620.0f, 0.0f));
	m_pTutorialBG->SetWight(1000.0f);
	m_pTutorialBG->SetHeight(200.0f);

	m_pEventTextBG = CObject2D::Create(7);
	m_pEventTextBG->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
	m_pEventTextBG->SetType(CObject::TYPE_TUTORIALUI);
	m_pEventTextBG->SetTexture("data\\TEXTURE\\EventTextBG.png");
	m_pEventTextBG->SetPos(D3DXVECTOR3(640.0f, 720.0f, 0.0f));
	m_pEventTextBG->SetWight(1280.0f);
	m_pEventTextBG->SetHeight(250.0f);

	m_pEventText = CObject2D::Create(7);
	m_pEventText->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
	m_pEventText->SetType(CObject::TYPE_TUTORIALUI);
	m_pEventText->SetTexture("data\\TEXTURE\\EventText.png");
	m_pEventText->SetPos(D3DXVECTOR3(640.0f, 670.0f, 0.0f));
	m_pEventText->SetWight(750.0f);
	m_pEventText->SetHeight(125.0f);

	m_pTutorialText = CObject2D::Create(7);
	m_pTutorialText->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
	m_pTutorialText->SetType(CObject::TYPE_TUTORIALUI);
	if (CManager::GetInstance()->GetSetTutorialPad() == false)
	{
		m_pTutorialText->SetTexture("data\\TEXTURE\\TutorialUnder000.png");
	}
	else
	{
		m_pTutorialText->SetTexture("data\\TEXTURE\\TutorialUnderPad000.png");
	}
	m_pTutorialText->SetPos(D3DXVECTOR3(640.0f, 620.0f, 0.0f));
	m_pTutorialText->SetWight(1000.0f);
	m_pTutorialText->SetHeight(200.0f);

	//CEnemy3D *pEnemy = CEnemy3D::Create(CEnemy3D::ENEMY_NORMAL);
	//pEnemy->SetPos(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	//pEnemy = CEnemy3D::Create(CEnemy3D::ENEMY_GROUND);
	//pEnemy->SetPos(D3DXVECTOR3(0.0f, -100.0f, 0.0f));
	//pEnemy = CEnemy3D::Create(CEnemy3D::ENEMY_NORMAL);
	//pEnemy->SetPos(D3DXVECTOR3(0.0f, -200.0f, 0.0f));
	//pEnemy = CEnemy3D::Create(CEnemy3D::ENEMY_WALLD);
	//pEnemy->SetPos(D3DXVECTOR3(0.0f, -300.0f, 0.0f));


	//////3D�I�u�W�F�N�g�̐���
	////CObject3D *Obj3D = CObject3D::Create();

	//////�r���{�[�h�̐���
	////CObjectBillboard *ObjBillboard = CObjectBillboard::Create();
	////ObjBillboard->SetPos(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	//3D�v���C���[���f���̓ǂݍ���
	//CPlayer3D::Load();

	if (m_bTutorial == true)
	{
		//3D�v���C���[���f���̐���
		m_pPlayer3D = CPlayer3D::Create();
		m_pPlayer3D->SetPos(D3DXVECTOR3(0.0f, 500.0f, 0.0f));
	}
	else
	{
		//3D�v���C���[���f���̐���
		m_pPlayer3D = CPlayer3D::Create();
		m_pPlayer3D->SetPos(D3DXVECTOR3(0.0f, -1800.0f, 0.0f));
	}

	//�K�w�\���̃{�X���f���̐���
	m_pBossLevel = CBossLevel::Create();
	m_pBossLevel->SetPos(D3DXVECTOR3(0.0f, 2000.0f, -350.0f));

	if (m_pPause == NULL)
	{
		m_pPause = CPause::Create();
	}

	//�G�f�B�b�g���[�h�̐���
	if (m_pEdit == NULL)
	{
		m_pEdit = CEdit::Create();
	}

	CManager::GetInstance()->SetStop(false);

	return S_OK;
}

//====================================================================
//�I������
//====================================================================
void CGame::Uninit(void)
{
	m_bEvent = false;
	m_bEventStart = false;

	//�S�ẴI�u�W�F�N�g�̔j��
	CObject::ReleaseAll();

	if (m_pMap2D != NULL)
	{
		//�}�b�v�̏I������
		m_pMap2D->Uninit();

		delete m_pMap2D;
		m_pMap2D = NULL;
	}

	if (m_pPause != NULL)
	{
		delete m_pPause;
		m_pPause = NULL;
	}

	if (m_pEdit != NULL)
	{
		//�G�f�B�b�g���[�h�̏I������
		m_pEdit->Uninit();

		delete m_pEdit;
		m_pEdit = NULL;
	}

	if (m_pTutorialUI != NULL)
	{
		//�`���[�g���A��UI�̏I������
		m_pTutorialUI->Uninit();

		delete m_pTutorialUI;
		m_pTutorialUI = NULL;
	}
}

//====================================================================
//�I������
//====================================================================
void CGame::DeleteTutorial(void)
{
	if (m_pTutorialUI != NULL)
	{
		delete m_pTutorialUI;
		m_pTutorialUI = NULL;
	}
}

//====================================================================
//�X�V����
//====================================================================
void CGame::Update(void)
{
#if _DEBUG
	//���Z�b�g����
	if (CManager::GetInstance()->GetInputKeyboard()->GetTrigger(DIK_R) == true)
	{
		ReSetGame();
	}

	//�`���[�g���A���̃X�L�b�v�@�\
	if (CManager::GetInstance()->GetInputKeyboard()->GetTrigger(DIK_7) == true)
	{
		CBreak *pPiece = CBreak::Create(m_pPlayer3D->GetPos());
	}

#endif

	//�|�[�Y�̍X�V����
	m_pPause->Update();

	//�`���[�g���A����UI�\������
	UpdateTutorial();

	////�`���[�g���A���̃X�L�b�v�@�\
	//if (m_bTutorial == true && CManager::GetInstance()->GetInputKeyboard()->GetTrigger(DIK_U) == true)
	//{
	//	SkipTutorial();
	//}


	//�`���[�g���A���̍X�V����
	if (m_pTutorialUI != NULL)
	{
		m_pTutorialUI->Update();
	}

	if (m_pPlayer3D->GetPos().y <= -2500.0f && m_bGSEventEnd == false)
	{
		CManager::GetInstance()->GetSound()->StopSound();
		CManager::GetInstance()->GetSound()->PlaySoundA(CSound::SOUND_LABEL_SE_CAMERA_WAVE);
		m_bGSEventEnd = true;
		m_bTutorial = false;
		m_bGSEvent = true;
		CManager::GetInstance()->GetCamera()->SetBib(true);
		CManager::GetInstance()->SetStop(true);
		CManager::GetInstance()->GetCamera()->SetCameraPosY(m_pPlayer3D->GetPos().y);
		m_GSEventCount = 240;
	}

	//�Q�[���X�^�[�g�C�x���g�̍X�V����
	if (m_bGSEvent == true)
	{
		GameStartEvent();
	}

	if (m_bEventStart == true)
	{
		if (sinf(m_fEventTextColor) > 0.3f)
		{
			m_fEventTextColor += 0.03f;
		}
		else
		{
			m_fEventTextColor += 0.3f;
		}

		m_pEventTextBG->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f));
		m_pEventText->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, sinf(m_fEventTextColor)));
	}
	else
	{
		m_pEventTextBG->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
		m_pEventText->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
	}

	if (CManager::GetInstance()->GetEdit() == true)
	{
		//�G�f�B�b�g���[�h�̍X�V����
		m_pEdit->Update();
	}
	else
	{
		//�}�b�v�̍X�V����
		m_pMap2D->Update();
	}

	//�Q�[�����[�h�I������
	if (m_bGameEnd == true)
	{
		if (m_bGameEndTime > 0)
		{
			m_bGameEndTime--;
		}
		else
		{
			CManager::GetInstance()->SetStop(false);
			CManager::GetInstance()->SetEndScore(m_pScore->GetScore());
			CManager::GetInstance()->SetEndCombo(m_pPlayer3D->GetComboScore());
			CManager::GetInstance()->SetEndFall(m_pPlayer3D->GetFallScore());
			CManager::GetInstance()->SetEndDepth((int)(m_pPlayer3D->GetPos().y * -1));
			CRanking::ChangeRanking(true);
			CManager::GetInstance()->SetSetScoreResult(true);
			CFade::SetFade(CScene::MODE_RESULT);
		}
	}
}

//====================================================================
//���Z�b�g����
//====================================================================
void CGame::ReSetGame(void)
{
	CObject::ResetObjectMap();

	if (m_pMap2D != NULL)
	{
		//�}�b�v�̏I������
		m_pMap2D->Uninit();

		delete m_pMap2D;
		m_pMap2D = NULL;
	}

	//�}�b�v�̐���
	if (m_pMap2D == NULL)
	{
		m_pMap2D = CMap2D::Create();
	}

	//3D�v���C���[���f���̐���
	m_pPlayer3D = CPlayer3D::Create();
	m_pPlayer3D->SetPos(D3DXVECTOR3(0.0f, 500.0f, 0.0f));

	//�K�w�\���̃{�X���f���̐���
	m_pBossLevel = CBossLevel::Create();
	m_pBossLevel->SetPos(D3DXVECTOR3(0.0f, 0.0f, 100.0f));
}

//====================================================================
//�`���[�g���A����UI�\������
//====================================================================
void CGame::UpdateTutorial(void)
{
	if (m_bTutorial == true && CManager::GetInstance()->GetStop() == false)
	{
		if ((m_pPlayer3D->GetMove().x > -0.1f &&
			m_pPlayer3D->GetMove().x < 0.1f) &&
			m_pPlayer3D->GetMove().y >= 0.0f)
		{
			if (m_fTextColor < 1.0f)
			{
				m_fTextColor += 0.05f;
			}
		}
		else
		{
			if (m_fTextColor > 0.5f)
			{
				m_fTextColor -= 0.025f;
			}
		}

		switch (m_nTutorialCount)
		{
		case 0:
		case 1:
			m_pTutorialBG->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
			m_pTutorialText->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
			break;
		default:
			m_pTutorialBG->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, m_fTextColor));
			m_pTutorialText->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, m_fTextColor));
			break;
		}

		if (m_nTutorialCount == 0 && m_pPlayer3D->GetPos().y <= 50.0f)
		{
			SetTutorial();
		}
		else if (m_nTutorialCount == 1 && m_pPlayer3D->GetPos().y <= 50.0f)
		{
			SetTutorial();
		}
		else if (m_nTutorialCount == 2 && m_pPlayer3D->GetPos().y <= -1000.0f)
		{
			SetTutorial();
		}
		else if (m_nTutorialCount == 3 && m_pPlayer3D->GetPos().y <= -1250.0f)
		{
			SetTutorial();
		}
		else if (m_nTutorialCount == 4 && m_pPlayer3D->GetPos().y <= -1600.0f)
		{
			SetTutorial();
		}
		else if (m_nTutorialCount == 5 && m_pPlayer3D->GetPos().y <= -1840.0f)
		{
			SetTutorial();
		}
	}
	else
	{
		m_pTutorialBG->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
		m_pTutorialText->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
	}
}

//====================================================================
//�`���[�g���A���̃X�L�b�v�@�\
//====================================================================
void CGame::SkipTutorial(void)
{
	m_bTutorial = false;
	CManager::GetInstance()->SetTutorialStart(false);
	CManager::GetInstance()->SetStop(false);
	CFade::SetFade(CScene::MODE_GAME);
}

//====================================================================
//�Q�[���X�^�[�g�C�x���g�̍X�V����
//====================================================================
void CGame::GameStartEvent(void)
{
	if (m_GSEventCount > 0)
	{
		m_GSEventCount--;
	}
	else
	{
		CManager::GetInstance()->GetSound()->PlaySoundA(CSound::SOUND_LABEL_BGM_GAME);
		m_pScore->SetScore(0);
		m_bGSEvent = false;
		m_bGSEventCamera = false;
		CManager::GetInstance()->GetCamera()->SetBib(false);
		CManager::GetInstance()->SetStop(false);
		CManager::GetInstance()->SetPauseOK(true);
	}

	if (m_GSEventCount == 120)
	{
		m_bGSEventCamera = true;
	}
}

//====================================================================
//�`���[�g���A���̌Ăяo������
//====================================================================
void CGame::SetTutorial(void)
{
	CManager::GetInstance()->GetSound()->PlaySoundA(CSound::SOUND_LABEL_SE_PLAYER_TEXT);
	m_pTutorialUI = CTutorialUI::Create(m_nTutorialCount);
	m_nTutorialCount++;
	CManager::GetInstance()->SetStop(true);
}

//====================================================================
//�`���[�g���A���̌Ăяo������
//====================================================================
void CGame::SetTutorialUnderText(char *cName)
{
	m_pTutorialText->SetTexture(cName);
}


//====================================================================
//�`�揈��
//====================================================================
void CGame::Draw(void)
{

}

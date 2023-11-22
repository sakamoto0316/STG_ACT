//============================================
//
//	ゲーム画面 [game.cpp]
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

//静的メンバ変数宣言
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
CObject2D *CGame::m_pScoreText = NULL;
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

//====================================================================
//コンストラクタ
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

	CManager::SetPauseOK(false);
}

//====================================================================
//デストラクタ
//====================================================================
CGame::~CGame()
{

}

//====================================================================
//初期化処理
//====================================================================
HRESULT CGame::Init(void)
{
	CManager::GetSound()->PlaySoundA(CSound::SOUND_LABEL_BGM_TUTORIAL);

	m_bGameEnd = false;

	//マップの生成
	if (m_pMap2D == NULL)
	{
		m_pMap2D = CMap2D::Create();
	}

	m_pScoreText = CObject2D::Create();
	m_pScoreText->SetPos(D3DXVECTOR3(975.0f, 60.0f, 0.0f));
	m_pScoreText->SetWight(300.0f);
	m_pScoreText->SetHeight(70.0f);
	m_pScoreText->SetTexture("data\\TEXTURE\\SCORE_UI.png");

	//スコアの生成
	m_pScore = CScore::Create();
	m_pScore->SetPos(D3DXVECTOR3(780.0f, 140.0f, 0.0f));
	m_pScore->SetWight(90.0f);
	m_pScore->SetHeight(90.0f);
	m_pScore->SetScore(0);

	//テスト用
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

	//テスト用
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

	m_pTutorialText = CObject2D::Create(7);
	m_pTutorialText->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
	m_pTutorialText->SetType(CObject::TYPE_TUTORIALUI);
	if (CManager::GetSetTutorialPad() == false)
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


	//////3Dオブジェクトの生成
	////CObject3D *Obj3D = CObject3D::Create();

	//////ビルボードの生成
	////CObjectBillboard *ObjBillboard = CObjectBillboard::Create();
	////ObjBillboard->SetPos(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	//3Dプレイヤーモデルの読み込み
	//CPlayer3D::Load();

	if (m_bTutorial == true)
	{
		//3Dプレイヤーモデルの生成
		m_pPlayer3D = CPlayer3D::Create();
		m_pPlayer3D->SetPos(D3DXVECTOR3(0.0f, 500.0f, 0.0f));
	}
	else
	{
		//3Dプレイヤーモデルの生成
		m_pPlayer3D = CPlayer3D::Create();
		m_pPlayer3D->SetPos(D3DXVECTOR3(0.0f, -1800.0f, 0.0f));
	}

	////階層構造のプレイヤーモデルの生成
	//m_pPlayerLevel = CPlayerLevel::Create();
	//m_pPlayerLevel->SetPos(D3DXVECTOR3(-300.0f, 0.0f, 0.0f));

	//階層構造のボスモデルの生成
	m_pBossLevel = CBossLevel::Create();
	m_pBossLevel->SetPos(D3DXVECTOR3(0.0f, 2000.0f, -350.0f));

	////3D敵モデルの読み込み
	//CEnemy3D::Load();

	////3D敵モデルの生成
	//CEnemy3D::Create();

	//////BGMの再生
	//m_pSound->PlaySoundA(CSound::SOUND_LABEL_BGM_TITLE);

	if (m_pPause == NULL)
	{
		m_pPause = CPause::Create();
	}

	//エディットモードの生成
	if (m_pEdit == NULL)
	{
		m_pEdit = CEdit::Create();
	}

	CManager::SetStop(false);

	return S_OK;
}

//====================================================================
//終了処理
//====================================================================
void CGame::Uninit(void)
{
	m_bEvent = false;
	m_bEventStart = false;

	//全てのオブジェクトの破棄
	CObject::ReleaseAll();

	if (m_pMap2D != NULL)
	{
		//マップの終了処理
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
		//エディットモードの終了処理
		m_pEdit->Uninit();

		delete m_pEdit;
		m_pEdit = NULL;
	}

	if (m_pTutorialUI != NULL)
	{
		//チュートリアルUIの終了処理
		m_pTutorialUI->Uninit();

		delete m_pTutorialUI;
		m_pTutorialUI = NULL;
	}
}

//====================================================================
//終了処理
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
//更新処理
//====================================================================
void CGame::Update(void)
{
#if _DEBUG
	//リセット処理
	if (CManager::GetInputKeyboard()->GetTrigger(DIK_R) == true)
	{
		ReSetGame();
	}

	//チュートリアルのスキップ機能
	if (CManager::GetInputKeyboard()->GetTrigger(DIK_7) == true)
	{
		CBreak *pPiece = CBreak::Create(m_pPlayer3D->GetPos());
	}

#endif

	//ポーズの更新処理
	m_pPause->Update();

	//チュートリアルのUI表示処理
	UpdateTutorial();

	////チュートリアルのスキップ機能
	//if (m_bTutorial == true && CManager::GetInputKeyboard()->GetTrigger(DIK_U) == true)
	//{
	//	SkipTutorial();
	//}


	//チュートリアルの更新処理
	if (m_pTutorialUI != NULL)
	{
		m_pTutorialUI->Update();
	}

	if (m_pPlayer3D->GetPos().y <= -2500.0f && m_bGSEventEnd == false)
	{
		CManager::GetSound()->StopSound();
		CManager::GetSound()->PlaySoundA(CSound::SOUND_LABEL_SE_CAMERA_WAVE);
		m_bGSEventEnd = true;
		m_bTutorial = false;
		m_bGSEvent = true;
		CManager::GetCamera()->SetBib(true);
		CManager::SetStop(true);
		CManager::GetCamera()->SetCameraPosY(m_pPlayer3D->GetPos().y);
		m_GSEventCount = 240;
	}

	//ゲームスタートイベントの更新処理
	if (m_bGSEvent == true)
	{
		GameStartEvent();
	}

	if (CManager::GetEdit() == true)
	{
		//エディットモードの更新処理
		m_pEdit->Update();
	}
	else
	{
		//マップの更新処理
		m_pMap2D->Update();
	}

	//ゲームモード終了処理
	if (m_bGameEnd == true)
	{
		if (m_bGameEndTime > 0)
		{
			m_bGameEndTime--;
		}
		else
		{
			CManager::SetStop(false);
			CManager::SetEndScore(m_pScore->GetScore());
			CManager::SetEndCombo(m_pPlayer3D->GetComboScore());
			CManager::SetEndFall(m_pPlayer3D->GetFallScore());
			CManager::SetEndDepth((int)(m_pPlayer3D->GetPos().y * -1));
			CRanking::ChangeRanking(true);
			CManager::SetSetScoreResult(true);
			CFade::SetFade(CScene::MODE_RESULT);
		}
	}
}

//====================================================================
//リセット処理
//====================================================================
void CGame::ReSetGame(void)
{
	CObject::ResetObjectMap();

	if (m_pMap2D != NULL)
	{
		//マップの終了処理
		m_pMap2D->Uninit();

		delete m_pMap2D;
		m_pMap2D = NULL;
	}

	//マップの生成
	if (m_pMap2D == NULL)
	{
		m_pMap2D = CMap2D::Create();
	}

	//3Dプレイヤーモデルの生成
	m_pPlayer3D = CPlayer3D::Create();
	m_pPlayer3D->SetPos(D3DXVECTOR3(0.0f, 500.0f, 0.0f));

	//階層構造のボスモデルの生成
	m_pBossLevel = CBossLevel::Create();
	m_pBossLevel->SetPos(D3DXVECTOR3(0.0f, 0.0f, 100.0f));
}

//====================================================================
//チュートリアルのUI表示処理
//====================================================================
void CGame::UpdateTutorial(void)
{
	if (m_bTutorial == true && CManager::GetStop() == false)
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
//チュートリアルのスキップ機能
//====================================================================
void CGame::SkipTutorial(void)
{
	m_bTutorial = false;
	CManager::SetTutorialStart(false);
	CManager::SetStop(false);
	CFade::SetFade(CScene::MODE_GAME);
}

//====================================================================
//ゲームスタートイベントの更新処理
//====================================================================
void CGame::GameStartEvent(void)
{
	if (m_GSEventCount > 0)
	{
		m_GSEventCount--;
	}
	else
	{
		CManager::GetSound()->PlaySoundA(CSound::SOUND_LABEL_BGM_GAME);
		m_pScore->SetScore(0);
		m_bGSEvent = false;
		m_bGSEventCamera = false;
		CManager::GetCamera()->SetBib(false);
		CManager::SetStop(false);
		CManager::SetPauseOK(true);
	}

	if (m_GSEventCount == 120)
	{
		m_bGSEventCamera = true;
	}
}

//====================================================================
//チュートリアルの呼び出し処理
//====================================================================
void CGame::SetTutorial(void)
{
	CManager::GetSound()->PlaySoundA(CSound::SOUND_LABEL_SE_PLAYER_TEXT);
	m_pTutorialUI = CTutorialUI::Create(m_nTutorialCount);
	m_nTutorialCount++;
	CManager::SetStop(true);
}

//====================================================================
//チュートリアルの呼び出し処理
//====================================================================
void CGame::SetTutorialUnderText(char *cName)
{
	m_pTutorialText->SetTexture(cName);
}


//====================================================================
//描画処理
//====================================================================
void CGame::Draw(void)
{

}

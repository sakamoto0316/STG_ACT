//============================================
//
//	�}�b�v�̎����������� [map2D.cpp]
//	Author:sakamoto kai
//
//============================================
#include "map2D.h"
#include "object.h"
#include "renderer.h"
#include "break_block3D.h"
#include "manager.h"
#include "game.h"
#include "player3D.h"
#include "input.h"
#include "debugproc.h"
#include "Enemy3D.h"
#include "camera.h"
#include "DirectionParticle.h"
#include "ForeGround2D.h"
#include "effect.h"
#include "bosslevel.h"
#include "Sideblock3D.h"

//�}�N����`
#define SPOWN_MAP (1000)
#define GAME_WIGHT (240.0f)			//��ʉ��̈ړ�����
#define MAP_EBENT (15000.0f)		//�C�x���g�}�b�v�̔����Ԋu
#define START_OK ("STARTSETSTAGE")	//�X�^�[�g���b�Z�[�W�����邩�ǂ����̊m�F
#define END_SET_OK ("ENDSETSTAGE")	//�G���h���b�Z�[�W�����邩�ǂ����̊m�F

//�ÓI�����o�ϐ��錾

//====================================================================
//�R���X�g���N�^
//====================================================================
CMap2D::CMap2D()
{
	m_MapLevel = 1;
	m_BreakPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_BreakEnd = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_DepthOld = 0.0f;
	m_Depth = 0.0f;
	m_bCreate = false;
	m_bSpownMove = false;
	m_fCreatePoint = 0.0f;
	CreateEnemy = 2;
	CreateEnemyCount = 0;
	CreateNumber = 0;
	m_pNormalBlock = NULL;
	m_pBreakBlock3D = NULL;
	m_pEnemy = NULL;
	m_pItem = NULL;
	m_DepthOld = 100.0f;
	m_Depth = 0.0f;
	m_TestCount = 0;
	m_EventEnemy = 0;
	m_EventStartLine = 0.0f;
	m_EventEndBreakPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_EndDirectionTime = 0;
	m_bEndDirection = false;
	m_fCirclePos = 0.0f;
	m_bColorCircle = false;
	m_BreakSelect = 451;
	m_EnemySelect = 0;
	m_EnemySelect2 = 0;
	m_nCntCreateEventMap = 0;
	m_nCreateEventMap = 0;
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CMap2D::~CMap2D()
{

}

//====================================================================
//��������
//====================================================================
CMap2D *CMap2D::Create()
{
	CMap2D *pMap = NULL;

	if (pMap == NULL)
	{
		//�I�u�W�F�N�g2D�̐���
		pMap = new CMap2D();
	}

	return pMap;
}

//====================================================================
//�I������
//====================================================================
void CMap2D::Uninit(void)
{

}

//====================================================================
//�X�V����
//====================================================================
void CMap2D::Update(void)
{
	//�L�[�{�[�h�̎擾
	CInputKeyboard *pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();
	CDebugProc *pD = CManager::GetInstance()->GetDebugProc();

	CPlayer3D *pPlayer = CGame::GetPlayer3D();

	if (CGame::GetTutorial() == true &&
		m_bCreate == false)
	{
		LoadBlock("data\\TXT\\Stage00", D3DXVECTOR3(-400.0f, -1000.0f, 0.0f));
		CEnemy3D *pEnemy = CEnemy3D::Create(CEnemy3D::ENEMY_NORMAL);
		pEnemy->SetPos(D3DXVECTOR3(0.0f, -1450.0f, 0.0f));
		m_bCreate = true;
	}
	else if(CGame::GetTutorial() == false)
	{
		//�}�b�v�̎�����������
		if (m_bCreate == false)
		{
			if (
				((int)m_DepthOld % SPOWN_MAP) < ((int)m_Depth % SPOWN_MAP) &&
				pPlayer->GetMove().y < 0.0f
				)
			{//�}�b�v�𐶐����A�����t���O��true�ɂ���
				int nRand = rand() % 100;
				if (pPlayer->GetPos().y < m_MapLevel * -MAP_EBENT && nRand <= 50)
				{
					CreateEventMap();
				}
				else
				{
					CreateMap();
					BreakBlck();
					BreakBlck();

					m_bCreate = true;
					m_fCreatePoint = m_Depth;
				}
			}
		}
		else
		{
			if (
				(m_fCreatePoint - 800.0f) > m_Depth &&
				pPlayer->GetMove().y < 0.0f &&
				CGame::GetEvent() == false
				)
			{//����������̋����𗎉������Ƃ������t���O��false�ɂ���
				m_bCreate = false;
				CreateEnemyCount = 0;
			}
		}
	}

	if (
		((int)m_DepthOld % SPOWN_MAP) < ((int)m_Depth % SPOWN_MAP) &&
		pPlayer->GetMove().y < 0.0f
		)
	{
		CreateSideMap();
	}

	if (CGame::GetEvent() == true && m_bEndDirection == false)
	{
		if (CGame::GetEventStart() == true)
		{
			EventUpdate();
		}
		else
		{
			if (pPlayer->GetPos().y < m_EventStartLine)
			{
 				EventStart();
				m_EventEndBreakPos = D3DXVECTOR3(20.0f, m_EventStartLine - 680.0f, 0.0f);
			}
		}
	}

	if (m_bEndDirection == true)
	{
		EndDirection();
	}

	if (m_bColorCircle == true)
	{
		ColorCircle(m_DirectionPos);
	}
}

//====================================================================
//�}�b�v�̐���
//====================================================================
void CMap2D::CreateMap(void)
{
	SetBlock();
}

//====================================================================
//���E�̃}�b�v����
//====================================================================
void CMap2D::CreateSideMap(void)
{
	CSide_Block3D *pSideBlock = CSide_Block3D::Create();
	pSideBlock->SetPos(D3DXVECTOR3(620.0f, ((float)((int)m_Depth / SPOWN_MAP) * 1000.0f) - 2000.0f, 0.0f));

	pSideBlock = CSide_Block3D::Create();
	pSideBlock->SetPos(D3DXVECTOR3(-580.0f, ((float)((int)m_Depth / SPOWN_MAP) * 1000.0f) - 2000.0f, 0.0f));
}

//====================================================================
//�C�x���g�ƃ}�b�v�̐���
//====================================================================
void CMap2D::CreateEventMap(void)
{
	m_nCntCreateEventMap++;
	if (m_nCntCreateEventMap == 1)
	{
		LoadBlock("data\\TXT\\Stage01", D3DXVECTOR3(-400.0f, -2000.0f, 0.0f));
		m_nCreateEventMap = 1;
	}
	else if (m_nCntCreateEventMap == 2)
	{
		LoadBlock("data\\TXT\\Stage02", D3DXVECTOR3(-400.0f, -2000.0f, 0.0f));
		m_nCreateEventMap = 2;
	}
	else if (m_nCntCreateEventMap == 3)
	{
		LoadBlock("data\\TXT\\Stage03", D3DXVECTOR3(-400.0f, -2000.0f, 0.0f));
		m_nCreateEventMap = 3;
	}
	else if (m_nCntCreateEventMap == 4)
	{
		LoadBlock("data\\TXT\\Stage04", D3DXVECTOR3(-400.0f, -2000.0f, 0.0f));
		m_nCreateEventMap = 4;
	}
	else
	{
		int nRandMap = rand() % 4;
		switch (nRandMap)
		{
		case 0:
			LoadBlock("data\\TXT\\Stage01", D3DXVECTOR3(-400.0f, -2000.0f, 0.0f));
			break;
		case 1:
			LoadBlock("data\\TXT\\Stage02", D3DXVECTOR3(-400.0f, -2000.0f, 0.0f));
			break;
		case 2:
			LoadBlock("data\\TXT\\Stage03", D3DXVECTOR3(-400.0f, -2000.0f, 0.0f));
			break;
		case 3:
			LoadBlock("data\\TXT\\Stage04", D3DXVECTOR3(-400.0f, -2000.0f, 0.0f));
			break;
		default:
			LoadBlock("data\\TXT\\Stage01", D3DXVECTOR3(-400.0f, -2000.0f, 0.0f));
			break;
		}
		m_nCreateEventMap = nRandMap + 1;
	}

	m_EventEnemy = 0;
	m_EventStartLine = ((float)((int)m_Depth / SPOWN_MAP) * 1000.0f) - 2200.0f;
	CGame::SetEventStart(false);

	CGame::SetEvent(true);
	m_bCreate = true;
}

//====================================================================
//�C�x���g�ƃ}�b�v�̐���
//====================================================================
void CMap2D::EventStart(void)
{
	//�G�̔j��
	CObject::ReleaseEnemy();

	CEnemy3D *pEnemy = NULL;

	switch (m_nCreateEventMap)
	{
	case 1:
		for (int nCnt = 0; nCnt < 3; nCnt++)
		{
			CEnemy3D *pEnemy = CEnemy3D::Create(CEnemy3D::ENEMY_NORMAL);
			pEnemy->SetPos(D3DXVECTOR3(-300.0f + (nCnt * 300.0f), ((float)((int)m_Depth / SPOWN_MAP) * 1000.0f) - 750.0f, 0.0f));
			m_EventEnemy++;
		}
		break;

	case 2:
		for (int nCnt = 0; nCnt < 2; nCnt++)
		{
			CEnemy3D *pEnemy = CEnemy3D::Create(CEnemy3D::ENEMY_GROUND);
			pEnemy->SetPos(D3DXVECTOR3(-160.0f + (nCnt * 360.0f), ((float)((int)m_Depth / SPOWN_MAP) * 1000.0f) - 650.0f, 0.0f));
			m_EventEnemy++;
		}

		for (int nCnt = 0; nCnt < 3; nCnt++)
		{
			CEnemy3D *pEnemy = CEnemy3D::Create(CEnemy3D::ENEMY_NORMAL);
			pEnemy->SetPos(D3DXVECTOR3(-200.0f + (nCnt * 200.0f), ((float)((int)m_Depth / SPOWN_MAP) * 1000.0f) - 850.0f, 0.0f));
			m_EventEnemy++;
		}
		break;

	case 3:
		for (int nCnt = 0; nCnt < 2; nCnt++)
		{
			CEnemy3D *pEnemy = CEnemy3D::Create(CEnemy3D::ENEMY_WALLD);
			pEnemy->SetPos(D3DXVECTOR3(-40.0f + (nCnt * 80.0f), ((float)((int)m_Depth / SPOWN_MAP) * 1000.0f) - 760.0f, 0.0f));
			m_EventEnemy++;
		}

		for (int nCnt = 0; nCnt < 2; nCnt++)
		{
			CEnemy3D *pEnemy = CEnemy3D::Create(CEnemy3D::ENEMY_NORMAL);
			pEnemy->SetPos(D3DXVECTOR3(-160.0f + (nCnt * 280.0f), ((float)((int)m_Depth / SPOWN_MAP) * 1000.0f) - 680.0f, 0.0f));
			m_EventEnemy++;
		}

		for (int nCnt = 0; nCnt < 1; nCnt++)
		{
			CEnemy3D *pEnemy = CEnemy3D::Create(CEnemy3D::ENEMY_NORMAL);
			pEnemy->SetPos(D3DXVECTOR3(-0.0f, ((float)((int)m_Depth / SPOWN_MAP) * 1000.0f) - 450.0f, 0.0f));
			m_EventEnemy++;
		}
		break;

	case 4:
		for (int nCnt = 0; nCnt < 2; nCnt++)
		{
			CEnemy3D *pEnemy = CEnemy3D::Create(CEnemy3D::ENEMY_GROUND);
			pEnemy->SetPos(D3DXVECTOR3(-240.0f + (nCnt * 520.0f), ((float)((int)m_Depth / SPOWN_MAP) * 1000.0f) - 760.0f, 0.0f));
			m_EventEnemy++;
		}

		for (int nCnt = 0; nCnt < 2; nCnt++)
		{
			CEnemy3D *pEnemy = CEnemy3D::Create(CEnemy3D::ENEMY_NORMAL);
			pEnemy->SetPos(D3DXVECTOR3(-160.0f + (nCnt * 360.0f), ((float)((int)m_Depth / SPOWN_MAP) * 1000.0f) - 600.0f, 0.0f));
			m_EventEnemy++;
		}

		for (int nCnt = 0; nCnt < 1; nCnt++)
		{
			CEnemy3D *pEnemy = CEnemy3D::Create(CEnemy3D::ENEMY_NORMAL);
			pEnemy->SetPos(D3DXVECTOR3(-0.0f, ((float)((int)m_Depth / SPOWN_MAP) * 1000.0f) - 800.0f, 0.0f));
			m_EventEnemy++;
		}

		break;

	default:
		for (int nCnt = 0; nCnt < 3; nCnt++)
		{
			CEnemy3D *pEnemy = CEnemy3D::Create(CEnemy3D::ENEMY_NORMAL);
			pEnemy->SetPos(D3DXVECTOR3(-300.0f + (nCnt * 300.0f), ((float)((int)m_Depth / SPOWN_MAP) * 1000.0f) - 750.0f, 0.0f));
			m_EventEnemy++;
		}
		break;
	}

	CManager::GetInstance()->GetCamera()->SetCameraPosY(((float)((int)m_Depth / SPOWN_MAP) * 1000.0f) - 700.0f);
	CGame::SetEventStart(true);
}

//====================================================================
//�C�x���g���̍X�V
//====================================================================
void CMap2D::EventUpdate(void)
{
	if (m_EventEnemy <= 0)
	{//�����X�^�[�n�E�X���̓G���S�Ď��S�����Ƃ�
		m_EndDirectionTime = 60;
		CFG *pFG = CFG::Create(60, 1);
		m_bEndDirection = true;
		CManager::GetInstance()->SetStop(true);
	}
}

//====================================================================
//�C�x���g�I�����̉��o
//====================================================================
void CMap2D::EndDirection(void)
{
	if (m_EndDirectionTime <= 0)
	{
		CGame::SetEventStart(false);
		CGame::SetEvent(false);
		CManager::GetInstance()->SetStop(false);
		m_bEndDirection = false;
		m_fCirclePos = 0.0f;
		m_bColorCircle = true;
		m_MapLevel++;
		SetLevelUP();

		CollisionSquare(m_EventEndBreakPos);
	}
	else
	{
		m_EndDirectionTime--;

		if (m_EndDirectionTime % 5 == 0)
		{
			//�p�[�e�B�N���̐���
			CDirectionParticle::Create
			(
				m_DirectionPos,
				D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f),
				250.0f,
				20,
				50.0f,
				1
			);
		}
	}
}

//====================================================================
//�F�ύX�����p�̉~������L���鏈��
//====================================================================
void CMap2D::ColorCircle(D3DXVECTOR3 pos)
{
	for (int nCntPriority = 0; nCntPriority < PRIORITY_MAX; nCntPriority++)
	{
		//�I�u�W�F�N�g���擾
		CObject *pObj = CObject::GetTop(nCntPriority);

		while (pObj != NULL)
		{
			CObject *pObjNext = pObj->GetNext();
			CObject::TYPE type = pObj->GetType();				//��ނ��擾
			D3DXVECTOR3 CollsionPos = pObj->GetPos();			//�ʒu���擾

			if (type == CObject::TYPE_BREAKBLOCK3D)
			{//��ނ��G�̎�
				if (CollisionCircleOut(pos, CollsionPos, m_fCirclePos, m_fCirclePos - 15.0f) == true)
				{//�~�̔��肪��������

					CBreak_Block3D *pBlock = (CBreak_Block3D*)pObj;

					pBlock->ChangeColor(m_MapLevel);
				}
			}
			else if (type == CObject::TYPE_SIDEBLOCK3D)
			{//��ނ��G�̎�
				if (CollisionCircleOut(pos, CollsionPos, m_fCirclePos, m_fCirclePos - 15.0f) == true)
				{//�~�̔��肪��������

					CSide_Block3D *pBlock = (CSide_Block3D*)pObj;

					pBlock->ChangeColor(m_MapLevel);
				}
			}
			pObj = pObjNext;
		}
	}

	m_fCirclePos += 15.0f;

	CEffect *pEffect = NULL;

	for (int nCnt = 0; nCnt < 32; nCnt++)
	{
		//�f�o�b�O�p�G�t�F�N�g�̐���
		pEffect = CEffect::Create();
		pEffect->SetPos(D3DXVECTOR3(
			pos.x + sinf(D3DX_PI * 0.0625f * nCnt) * m_fCirclePos,
			pos.y + cosf(D3DX_PI * 0.0625f * nCnt) * m_fCirclePos,
			pos.z
		));
		pEffect->SetColor(D3DXCOLOR(0.5f, 0.5f, 0.5f, 1.0f));
		pEffect->SetRadius(40.0f);
		pEffect->SetDel(0.5f);
		pEffect->SetLife(100);
	}

	if (m_fCirclePos > 2000.0f)
	{
		m_bColorCircle = false;
	}
}

//====================================================================
//�}�b�v��S�Ė��߂Đ���
//====================================================================
void CMap2D::SetBlock(void)
{
	CreateNumber++;
	if (CreateNumber >= 100)
	{
		CreateNumber = 0;
	}

	for (int nCntObjHeight = 0; nCntObjHeight < SET_BLOCK_HEIGHT; nCntObjHeight++)
	{
		for (int nCntObjWight = 0 + 1; nCntObjWight < SET_BLOCK_WIGHT + 1; nCntObjWight++)
		{
			m_pBreakBlock3D = CBreak_Block3D::Create();
			m_pBreakBlock3D->SetPos(D3DXVECTOR3(-400.0f + 40.0f * nCntObjWight, ((float)((int)m_Depth / SPOWN_MAP) * 1000.0f) - 2000.0f - 40.0f * nCntObjHeight, 0.0f));
			m_pBreakBlock3D->SetCNumber(CreateNumber);
			m_pBreakBlock3D->SetWNumber(nCntObjWight);
			m_pBreakBlock3D->SetHNumber(nCntObjHeight);
			m_pBreakBlock3D->SetUse(CreateNumber, nCntObjWight, nCntObjHeight, true);
		}
	}
}

//====================================================================
//�}�b�v��S�Ė��߂Đ���
//====================================================================
void CMap2D::LoadBlock(char *Name, D3DXVECTOR3 pos)
{
	FILE *pFile; //�t�@�C���|�C���^��錾

	//�t�@�C�����J��
	pFile = fopen(Name, "r");

	if (pFile != NULL)
	{//�t�@�C�����J�����ꍇ

		CreateNumber++;

		char aString[128] = {};			//�S�~��
		char aStartMessage[32] = {};	//�X�^�[�g���b�Z�[�W
		char aSetMessage[32] = {};		//�Z�b�g���b�Z�[�W
		char aEndMessage[32] = {};		//�I�����b�Z�[�W
		char aType[32] = {};			//�I�����b�Z�[�W

		fscanf(pFile, "%s", &aStartMessage[0]);
		if (strcmp(&aStartMessage[0], START_OK) == 0)
		{
			while (1)
			{
				fscanf(pFile, "%s", &aSetMessage[0]);
				if (strcmp(&aSetMessage[0], END_SET_OK) == 0)
				{
					break;
				}
				else if (strcmp(&aSetMessage[0], "STARTSETBLOCK") == 0)
				{
					fscanf(pFile, "%d", &m_CreateNumber);
					fscanf(pFile, "%d", &m_WightNumber);
					fscanf(pFile, "%d", &m_HeightNumber);
					fscanf(pFile, "%s", &aSetMessage[0]);

					CBreak_Block3D::TrueUse(CreateNumber, m_WightNumber, m_HeightNumber);
				}
			}
		}
		fclose(pFile);
	}
	else
	{//�t�@�C�����J���Ȃ������ꍇ
		printf("***�t�@�C�����J���܂���ł���***\n");
	}
	CBreak_Block3D::CreateMapBlocks(CreateNumber , pos);
}

//====================================================================
//�}�b�v��S�Ė��߂Đ���
//====================================================================
void CMap2D::CleanBlockUse(void)
{
	m_pBreakBlock3D->CleanBlockUse();
}

//====================================================================
//���x���A�b�v�ɂ���Փx�ύX
//====================================================================
void CMap2D::SetLevelUP(void)
{
	//�u���b�N�̔j��͈͂�I������
	m_BreakSelect = 451 - m_MapLevel * 75;
	if (m_BreakSelect <= 101)
	{
		m_BreakSelect = 101;
	}

	//�o������G�̎�ނ�I������
	m_EnemySelect = m_MapLevel * 7;
	m_EnemySelect2 = m_MapLevel * 12;
	if (m_EnemySelect >= 50)
	{
		m_EnemySelect = 40;
	}
	if (m_EnemySelect2 >= 80)
	{
		m_EnemySelect2 = 80;
	}

	//���̐����ɏo���o����G�̍ő吔��ݒ肷��
	CreateEnemy = m_MapLevel * 2;

	//�v���C���[�̗����̍ō����x��ݒ肷��
	CGame::GetPlayer3D()->SetFallMax(10.0f + m_MapLevel * 1.0f);

	//�{�X�̐i�s���x��ݒ肷��
	CGame::GetBossLevel()->SetEatSpeed(2.0f + m_MapLevel * 1.0f);
}

//====================================================================
//�}�b�v�̌`�������������鏈��(�u���b�N�̔j��ƓG�̏o��)
//====================================================================
void CMap2D::BreakBlck(void)
{
	//�u���b�N�j��̊J�n�ʒu��1000.0f��؂�̎w��̈ʒu�ɐݒ肷��
	m_BreakPos = D3DXVECTOR3(m_BreakEnd.x, ((int)m_Depth / SPOWN_MAP) * 1000.0f - 2000.0f, 0.0f);

	//�u���b�N�j��̏I���ʒu��ݒ肷��
	float fBreakEnd = m_BreakPos.y - 1000.0f;

	while (1)
	{
		//��������
		bool bMovePoint = false;

		//�j��n�_�̈ړ��I��p�����_���֐�
		int MoveRoot = rand() % 8;

		//�G�̏o���m���p�����_���֐�
		int m_EnemySpown = rand() % 101;

		//�}�b�v�̃u���b�N�j��͈͂��o�������_���֐�
		float fRandWight = (float)(rand() % m_BreakSelect);
		float fRandHeight = (float)(rand() % m_BreakSelect);

		//�j��n�_�ړ�����
		switch (MoveRoot)
		{
		case 0:
		case 1:
		case 2:
			if (m_BreakPos.x >= 400.0f)
			{//�G���A�͈̔͊O�ɏo���珈������������x�����_���֐�����
				continue;
			}
			else
			{//�E�ɔj��ʒu���ړ�����
				m_BreakPos.x += fRandWight * 0.5f;
				bMovePoint = true;
				m_bSpownMove = false;
				break;
			}
		case 3:
		case 4:
		case 5:
			if (m_BreakPos.x <= -400.0f)
			{//�G���A�͈̔͊O�ɏo���珈������������x�����_���֐�����
				continue;
			}
			else
			{//���ɔj��ʒu���ړ�����
				m_BreakPos.x -= fRandWight * 0.5f;
				bMovePoint = true;
				m_bSpownMove = false;
				break;
			}
			break;
		case 6:
			if (m_BreakPos.x >= 400.0f)
			{//�G���A�͈̔͊O�ɏo���珈������������x�����_���֐�����
				continue;
			}
			else
			{//�E���ɔj��ʒu���ړ�����
				m_BreakPos.x += fRandWight * 0.5f;
				m_BreakPos.y -= fRandHeight * 0.5f;
				bMovePoint = true;
				m_bSpownMove = false;
				break;
			}
		case 7:
			if (m_BreakPos.x <= -400.0f)
			{//�G���A�͈̔͊O�ɏo���珈������������x�����_���֐�����
				continue;
			}
			else
			{//�����ɔj��ʒu���ړ�����
				m_BreakPos.x -= fRandWight * 0.5f;
				m_BreakPos.y -= fRandHeight * 0.5f;
				bMovePoint = true;
				m_bSpownMove = false;
				break;
			}
		}

		if (bMovePoint == true)
		{
			//�j�󏈗�
			for (int nCntPriority = 0; nCntPriority < PRIORITY_MAX; nCntPriority++)
			{
				//�I�u�W�F�N�g���擾
				CObject *pObj = CObject::GetTop(nCntPriority);


				while (pObj != NULL)
				{
					CObject *pObjNext = pObj->GetNext();

					CObject::TYPE type = pObj->GetType();				//��ނ��擾
					D3DXVECTOR3 CollsionPos = pObj->GetPos();			//�ʒu���擾
					float CollsionWight = pObj->GetWight() * 0.5f;		//�����擾
					float CollsionHeight = pObj->GetHeight() * 0.5f;	//�������擾
					float fmyWight = fRandWight * 0.5f;					//���S����̕�
					float fmyHeight = fRandHeight * 0.5f;				//���S����̍���

					if (type == CObject::TYPE_NORMALBLOCK || type == CObject::TYPE_BREAKBLOCK3D)
					{//��ނ��u���b�N�̎�
						if (m_BreakPos.x + fmyWight > CollsionPos.x - CollsionWight &&
							m_BreakPos.x - fmyWight < CollsionPos.x + CollsionWight &&
							m_BreakPos.y + fmyHeight > CollsionPos.y - CollsionHeight &&
							m_BreakPos.y - fmyHeight < CollsionPos.y + CollsionHeight)
						{
							pObj->Uninit();
							m_pBreakBlock3D = NULL;

							if (m_EnemySpown < 5 && CreateEnemyCount < CreateEnemy && fRandWight > 40.0f && fRandHeight > 40.0f)
							{//�G��5%�̊m���ŏo�� && �G�̏o����������ɒB���Ă��Ȃ��Ƃ� && �j��͈͂��G���傫���Ƃ�
								if (m_bSpownMove == false)
								{
									//�o��������G�̎�ޑI��
									int nRandEenemy = rand() % 101;

									if (nRandEenemy < m_EnemySelect)
									{
										m_pEnemy = CEnemy3D::Create(CEnemy3D::ENEMY_WALLD);
									}
									else if (nRandEenemy < m_EnemySelect2)
									{
										m_pEnemy = CEnemy3D::Create(CEnemy3D::ENEMY_GROUND);
									}
									else
									{
										m_pEnemy = CEnemy3D::Create(CEnemy3D::ENEMY_NORMAL);
									}
									CreateEnemyCount++;
									m_bSpownMove = true;
								}
								m_pEnemy->SetPos(m_BreakPos);
							}
						}
					}

					pObj = pObjNext;
				}
			}

			bMovePoint = false;

			if (m_BreakPos.y < fBreakEnd)
			{
				break;
			}
		}
	}

	m_BreakEnd = m_BreakPos;
}

//====================================================================
//�~�̓����蔻��(�O���̂�)
//====================================================================
bool CMap2D::CollisionCircleOut(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2, float nRadiusOut, float nRadiusIn)
{
	bool nHit = false;

	if ((sqrtf((pos1.x - pos2.x) * (pos1.x - pos2.x)
		+ (pos1.y - pos2.y) * (pos1.y - pos2.y)) <= nRadiusOut) &&
		(sqrtf((pos1.x - pos2.x) * (pos1.x - pos2.x)
			+ (pos1.y - pos2.y) * (pos1.y - pos2.y)) > nRadiusIn))
	{//�~�̔��肪��������
		nHit = true;
	}

	return nHit;
}

//====================================================================
//��`�͈͓̔��̓����蔻��
//====================================================================
void CMap2D::CollisionSquare(D3DXVECTOR3 pos)
{
	//�j�󏈗�
	for (int nCntPriority = 0; nCntPriority < PRIORITY_MAX; nCntPriority++)
	{
		//�I�u�W�F�N�g���擾
		CObject *pObj = CObject::GetTop(nCntPriority);


		while (pObj != NULL)
		{
			CObject *pObjNext = pObj->GetNext();

			CObject::TYPE type = pObj->GetType();				//��ނ��擾
			D3DXVECTOR3 CollsionPos = pObj->GetPos();			//�ʒu���擾
			float CollsionWight = pObj->GetWight() * 0.5f;		//�����擾
			float CollsionHeight = pObj->GetHeight() * 0.5f;	//�������擾
			float fmyWight = 300.0f;							//���S����̕�
			float fmyHeight = 80.0f;							//���S����̍���

			if (type == CObject::TYPE_BREAKBLOCK3D)
			{//��ނ��u���b�N�̎�
				if (pos.x + fmyWight > CollsionPos.x - CollsionWight &&
					pos.x - fmyWight < CollsionPos.x + CollsionWight &&
					pos.y + fmyHeight > CollsionPos.y - CollsionHeight &&
					pos.y - fmyHeight < CollsionPos.y + CollsionHeight)
				{
					CBreak_Block3D *pBlock = (CBreak_Block3D*)pObj;

					pBlock->BreakCountSet(10);
				}
			}

			pObj = pObjNext;
		}
	}
}
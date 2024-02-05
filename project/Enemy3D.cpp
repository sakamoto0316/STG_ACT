//============================================
//
//	�G�̏��� [Enemy3D.cpp]
//	Author:sakamoto kai
//
//============================================
#include "Enemy3D.h"
#include "input.h"
#include "renderer.h"
#include "manager.h"
#include "game.h"
#include "bullet3D.h"
#include "time.h"
#include "effect.h"
#include "debugproc.h"
#include "texture.h"
#include "Xmodel.h"
#include "player3D.h"
#include "particle.h"
#include "score.h"
#include "LifeGaugeBillboard.h"
#include "break_block3D.h"
#include "LevelPoint3D.h"
#include "EnemyBullet3D.h"
#include "sound.h"

//�}�N����`
#define ENEMY_WIGHT (40.0f)		//����
#define ENEMY_HEIGHT (40.0f)	//�c��
#define ENEMY_SPEED (20.0f)		//�G�̃X�s�[�h
#define ENEMY_SCORE (200)		//�G�����񂾂Ƃ��̉��Z�X�R�A
#define ENEMYNORMAL_LIFE (3)	//�ʏ�G�̗̑�
#define ENEMYWALL_LIFE (2)		//�ǓG�̗̑�
#define ENEMYGROUND_LIFE (5)	//�n��G�̗̑�
#define WAIT_TIME (2)			//�v���C���[�̖��G���Ԃ̒���
#define DAMAGE_TIME (3)			//�v���C���[�̃_���[�W���A�N�V�����̒���
#define BULLET_TIME (60)		//�e�����܂ł̃J�E���g
#define JUMP_TIME	(300)		//�W�����v�܂ł̃J�E���g

//�ÓI�����o�ϐ��錾
int CEnemy3D::m_nIdxXModel[ENEMY_MAX] = {};			//X���f���̎g�p�ԍ�
int CEnemy3D::m_nIdxTexture[ENEMY_MAX][64] = {};	//X���f���̃e�N�X�`���̎g�p�ԍ�

//====================================================================
//�R���X�g���N�^
//====================================================================
CEnemy3D::CEnemy3D(ENEMY_TYPE Type, int nPriority) : CObjectX(nPriority)
{
	m_pLifeGauge = NULL;
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Type = Type;
	pEnemy = NULL;
	m_BulletCount = 0;
	m_JumpCount = 0;
	m_bJump = false;
	m_bDeath = false;
	m_bDeathCountFlog = false;
	m_nDeathStopCount = 2;

	switch (m_Type)
	{
	case ENEMY_NORMAL:
		SetWight(ENEMY_WIGHT);
		SetHeight(ENEMY_HEIGHT);
		m_nLife = ENEMYNORMAL_LIFE;
		break;
	case ENEMY_WALLD:
		SetWight(ENEMY_WIGHT);
		SetHeight(ENEMY_HEIGHT);
		m_nLife = ENEMYWALL_LIFE;
		break;
	case ENEMY_WALLU:
		SetWight(0.0f);
		SetHeight(0.0f);
		m_nLife = 0;
		break;
	case ENEMY_GROUND:
		SetWight(ENEMY_WIGHT);
		SetHeight(ENEMY_HEIGHT);
		m_nLife = ENEMYGROUND_LIFE;
		break;
	}

	switch (m_Type)
	{
	case ENEMY_NORMAL:
		break;
	case ENEMY_WALLD:
		break;
	case ENEMY_WALLU:
		break;
	case ENEMY_GROUND:
		break;
	}
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CEnemy3D::~CEnemy3D()
{

}

//====================================================================
//��������
//====================================================================
CEnemy3D *CEnemy3D::Create(ENEMY_TYPE Type)
{
	CEnemy3D *pEnemy = NULL;

	if (pEnemy == NULL)
	{
		//�G�̐���
		pEnemy = new CEnemy3D(Type);
	}

	//�I�u�W�F�N�g�̏���������
	if (FAILED(pEnemy->Init()))
	{//���������������s�����ꍇ
		return NULL;
	}

	return pEnemy;
}

//====================================================================
//����������
//====================================================================
HRESULT CEnemy3D::Init(void)
{
	SetType(CObject::TYPE_ENEMY3D);

	CXModel *pXModel = CManager::GetInstance()->GetXModel();
	CTexture *pTexture = CManager::GetInstance()->GetTexture();

	switch (m_Type)
	{
	case ENEMY_NORMAL:
		//X�t�@�C���̊��蓖��
		m_nIdxXModel[ENEMY_NORMAL] = pXModel->Regist("data\\MODEL\\Enemy00.x");
		pTexture->XModelRegist(&m_nIdxTexture[ENEMY_NORMAL][0], m_nIdxXModel[ENEMY_NORMAL]);
		break;
	case ENEMY_WALLD:
		//X�t�@�C���̊��蓖��
		m_nIdxXModel[ENEMY_WALLD] = pXModel->Regist("data\\MODEL\\EnemyWallD.x");
		pTexture->XModelRegist(&m_nIdxTexture[ENEMY_WALLD][0], m_nIdxXModel[ENEMY_WALLD]);
		pEnemy = Create(ENEMY_WALLU);
		break;
	case ENEMY_WALLU:
		//X�t�@�C���̊��蓖��
		m_nIdxXModel[ENEMY_WALLU] = pXModel->Regist("data\\MODEL\\EnemyWallU.x");
		pTexture->XModelRegist(&m_nIdxTexture[ENEMY_WALLU][0], m_nIdxXModel[ENEMY_WALLU]);
		break;
	case ENEMY_GROUND:
		//X�t�@�C���̊��蓖��
		m_nIdxXModel[ENEMY_GROUND] = pXModel->Regist("data\\MODEL\\EnemyGround.x");
		pTexture->XModelRegist(&m_nIdxTexture[ENEMY_GROUND][0], m_nIdxXModel[ENEMY_GROUND]);
		break;
	}

	if (m_Type != ENEMY_WALLU)
	{
		D3DXVECTOR3 pos = GetPos();

		//���C�t�Q�[�W�̐����Ɛݒ�
		m_pLifeGauge = CLifeGaugeBillboard::Create();
		m_pLifeGauge->SetPos(D3DXVECTOR3(pos.x - ENEMY_WIGHT, pos.y - 20.0f, pos.z));
		m_pLifeGauge->SetGaugeMax(m_nLife);
		m_pLifeGauge->SetGauge(m_nLife);
	}

	CObjectX::Init();

	return S_OK;
}

//====================================================================
//�I������
//====================================================================
void CEnemy3D::Uninit(void)
{
	if (m_Type != ENEMY_WALLU)
	{
		if (m_pLifeGauge != NULL)
		{
			m_pLifeGauge->SetDeathFlag(true);
		}

		CObjectX::Uninit();
	}
}
//====================================================================
//NULL�ɂ��鏈��
//====================================================================
void CEnemy3D::SetNULL(void)
{
	m_pLifeGauge = NULL;

	if (pEnemy != NULL)
	{
		pEnemy->SetEnemyType(ENEMY_NORMAL);
		pEnemy->Uninit();
		pEnemy = NULL;
	}
}

//====================================================================
//�X�V����
//====================================================================
void CEnemy3D::Update(void)
{
	//�ʒu�̎擾
	D3DXVECTOR3 pos = GetPos();

	//�ߋ��̈ʒu�ݒ�
	SetPosOld(GetPos());

	//�G�̏�ԊǗ�
	StateManager();

	switch (m_Type)
	{
	case ENEMY_NORMAL:

		//�G�̓���
		pos = MoveNormal(pos);

		//���C�t�Q�[�W�̈ʒu�X�V
		m_pLifeGauge->SetPos(D3DXVECTOR3(pos.x - ENEMY_WIGHT, pos.y - 20.0f, pos.z));

		break;

	case ENEMY_WALLD:

		//�G�̓���
		pos = MoveWallD(pos);

		//���C�t�Q�[�W�̈ʒu�X�V
		m_pLifeGauge->SetPos(D3DXVECTOR3(pos.x - ENEMY_WIGHT, pos.y - 20.0f, pos.z));

		break;

	case ENEMY_WALLU:

		//�G�̓���
		MoveWallU(pos);

		break;

	case ENEMY_GROUND:

		//�G�̓���
		pos = MoveGround(pos);

		//���C�t�Q�[�W�̈ʒu�X�V
		m_pLifeGauge->SetPos(D3DXVECTOR3(pos.x - ENEMY_WIGHT, pos.y - 20.0f, pos.z));

		break;
	}
	//�ʒu�̐ݒ�
	SetPos(pos);

	//���̐ݒ�
	CObjectX::Update();

	CPlayer3D *pPlayer = CGame::GetPlayer3D();

	if (pPlayer->GetPos().y + 400.0f < pos.y &&
		CGame::GetEventStart() == false)
	{
		Uninit();
		return;
	}

	if (m_bDeathCountFlog == true)
	{
		if (m_nDeathStopCount > 0)
		{
			m_nDeathStopCount--;
		}
		else
		{
			Death(pos, 200.0f, 6);
		}
	}
}

//====================================================================
//�ʏ�G�̍X�V����
//====================================================================
D3DXVECTOR3 CEnemy3D::MoveNormal(D3DXVECTOR3 pos)
{
	//�v���C���[�̈ʒu���擾����
	CPlayer3D *pPlayer = CGame::GetPlayer3D();
	D3DXVECTOR3 PlayerPos = pPlayer->GetPos();
	PlayerPos.y += pPlayer->GetHeight() * 0.25f;

	//�G���v���C���[�ɒǔ�����
	m_move = PlayerPos - pos;
	D3DXVec3Normalize(&m_move, &m_move);
	m_move *= ENEMY_SPEED;

	//�����W��
	m_move = m_move * 0.1f;

	//X���̈ʒu�ݒ�
	pos.x += m_move.x;
	//X���̃u���b�N�Ƃ̓����蔻��
	CollisionBlock(&pos, true);

	//Y���̈ʒu�ݒ�
	pos.y += m_move.y;
	//Y���̃u���b�N�Ƃ̓����蔻��
	CollisionBlock(&pos, false);

	return pos;
}

//====================================================================
//�ǂɒ���t���G�̍X�V����
//====================================================================
D3DXVECTOR3 CEnemy3D::MoveWallD(D3DXVECTOR3 pos)
{
	if (pos.x >= 0.0f)
	{//�E�ɂ��鎞

		//�����̐ݒ�
		SetRot(D3DXVECTOR3(0.0f, 0.0f, 1.57f));

		//�d��
		pos.x += 10.0f;

		//���̔���
		if (pos.x > 400.0f)
		{
			pos.x = 400.0f;
		}
	}
	else
	{//���ɂ��鎞
		SetRot(D3DXVECTOR3(0.0f, 0.0f, -1.57f));

		//�d��
		pos.x -= 10.0f;

		//���̔���
		if (pos.x < -360.0f)
		{
			pos.x = -360.0f;
		}
	}

	////X���̈ʒu�ݒ�
	pos.x += m_move.x;
	//X���̃u���b�N�Ƃ̓����蔻��
	CollisionBlock(&pos, true);

	//Y���̈ʒu�ݒ�
	pos.y += m_move.y;
	//Y���̃u���b�N�Ƃ̓����蔻��
	CollisionBlock(&pos, false);

	//���p�[�c�̈ʒu�ݒ�
	pEnemy->SetPos(D3DXVECTOR3(
		pos.x + cosf(GetRot().z + 0.75f) * 25.0f,
		pos.y + sinf(GetRot().z + 0.75f) * 25.0f,
		pos.z
	));

	return pos;
}

//====================================================================
//�ǂɒ���t���G�̍X�V����
//====================================================================
void CEnemy3D::MoveWallU(D3DXVECTOR3 pos)
{
	//�v���C���[�̈ʒu���擾����
	CPlayer3D *pPlayer = CGame::GetPlayer3D();
	D3DXVECTOR3 PlayerPos = pPlayer->GetPos();
	PlayerPos.y += pPlayer->GetHeight() * 0.25f;

	if (sqrtf((pos.x - PlayerPos.x) * (pos.x - PlayerPos.x)
		+ (pos.y - PlayerPos.y) * (pos.y - PlayerPos.y)) <= 600.0f)
	{//�~�̔��肪��������

		//�v���C���[�̕����ތ���
		float fAngle = atan2f(pos.x - PlayerPos.x, PlayerPos.y - pos.y);
		SetRot(D3DXVECTOR3(0.0f, 0.0f, fAngle));

		if (m_BulletCount < BULLET_TIME)
		{
			m_BulletCount++;
		}
		else
		{
			m_BulletCount = 0;

			CEenmyBullet3D *pBullet = CEenmyBullet3D::Create();
			pBullet->SetPos(pos);
			pBullet->SetLife(60);
			pBullet->SetMove(D3DXVECTOR3
			(
				sinf(-fAngle) * 7.5f,
				cosf(fAngle) * 7.5f,
				0.0f
			));
		}
	}
}

//====================================================================
//�n��G�̍X�V����
//====================================================================
D3DXVECTOR3 CEnemy3D::MoveGround(D3DXVECTOR3 pos)
{
	//�v���C���[�̈ʒu���擾����
	CPlayer3D *pPlayer = CGame::GetPlayer3D();
	D3DXVECTOR3 PlayerPos = pPlayer->GetPos();
	PlayerPos.y += pPlayer->GetHeight() * 0.25f;

	//�d��
	m_move.y -= 0.98f;

	if (m_JumpCount > JUMP_TIME)
	{
		if (PlayerPos.x >= pos.x)
		{
			m_move.x = 10.0f;
			m_move.y = 20.0f;
		}
		else
		{
			m_move.x = -10.0f;
			m_move.y = 20.0f;
		}
		m_JumpCount = 0;
	}
	else
	{
		m_JumpCount++;
	}

	if (PlayerPos.x >= pos.x)
	{
		SetRot(D3DXVECTOR3(0.0f, 3.14f, 0.0f));
	}
	else
	{
		SetRot(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	}

	//�����W��
	m_move.x = m_move.x * 0.98f;

	//X���̈ʒu�ݒ�
	pos.x += m_move.x;
	//X���̃u���b�N�Ƃ̓����蔻��
	CollisionBlock(&pos, true);

	//Y���̈ʒu�ݒ�
	pos.y += m_move.y;
	//Y���̃u���b�N�Ƃ̓����蔻��
	if (CollisionBlock(&pos, false) == true)
	{
		m_move.x = 0.0f;
	}

	return pos;
}

//====================================================================
//�`�揈��
//====================================================================
void CEnemy3D::Draw(void)
{
	CObjectX::Draw();
}

//====================================================================
//��ԊǗ�
//====================================================================
void CEnemy3D::StateManager(void)
{
	switch (m_State)
	{
	case STATE_NORMAL:
		break;

	case STATE_DAMAGE:
		if (m_StateCount <= 0)
		{
			SetMatColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
			m_State = STATE_WAIT;
			m_StateCount = WAIT_TIME;
		}
		break;

	case STATE_WAIT:
		if (m_StateCount <= 0)
		{
			SetDefColor();
			m_State = STATE_NORMAL;
		}
		break;
	}

	if (m_StateCount > 0)
	{
		m_StateCount--;
	}
}

//====================================================================
//�q�b�g����
//====================================================================
void CEnemy3D::Hit(D3DXVECTOR3 pos, int Damage)
{
	if (m_nLife > 0)
	{
		CManager::GetInstance()->GetSound()->PlaySoundA(CSound::SOUND_LABEL_SE_ENEMY_DAMAGE);
		m_nLife -= Damage;
		if (m_nLife < 0)
		{
			m_nLife = 0;
		}
		m_pLifeGauge->SetGauge(m_nLife);
	}
	SetMatColor(D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f));
	m_State = STATE_DAMAGE;
	m_StateCount = DAMAGE_TIME;

	if (m_nLife <= 0 && m_bDeath == false && m_Type != ENEMY_WALLU)
	{
		Death(pos, 200.0f, 6);
	}
}

//====================================================================
//���S������
//====================================================================
void CEnemy3D::Death(D3DXVECTOR3 pos,float nRadius,int BreakCount)
{
	if (m_bDeathCountFlog == true && m_nDeathStopCount <= 0)
	{
		//�v���C���[�̎擾
		CPlayer3D *pPlayer = CGame::GetPlayer3D();

		//�R���{���Z����
		pPlayer->AddCombo();

		//�K�E�Q�[�W���Z����
		if (pPlayer->GetUseUlt() == false)
		{
			pPlayer->AddUlt();
		}

		//�R���{���ɂ��o���l�������ݒ�
		int nCnmbo = pPlayer->GetCombo();
		nCnmbo = (nCnmbo / 5) + 1;

		//���񂾎��p
		m_nLife = 0;

		//�p�[�e�B�N���̐���
		CParticle::Create
		(
			pos,
			D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f),
			10,
			50.0f,
			2
		);
		//�X�R�A�̉��Z
		CGame::GetScore()->AddScore(ENEMY_SCORE);

		//�~�̓����蔻��
		CollisionObjectCircle(pos, nRadius, BreakCount);

		//�ړ��ʂ̐ݒ�
		D3DXVECTOR3 Move;

		//�����̉~����̃����_���Ȉʒu�Ɍo���l���΂�
		for (int nCnt = 0; nCnt < nCnmbo; nCnt++)
		{
			Move.x = sinf((float)(rand() % 731 - (731 - 1) / 2) / 100.0f + D3DX_PI * -0.5f);
			Move.y = cosf((float)(rand() % 731 - (731 - 1) / 2) / 100.0f + D3DX_PI * -0.5f);
			Move.z = 0.0f;

			D3DXVec3Normalize(&Move, &Move);
			Move *= 15.0f;

			CLevelPoint *pLevelPoint = CLevelPoint::Create();
			pLevelPoint->SetPos(pos);
			pLevelPoint->SetMove(Move);
		}

		//�K�w�\���̓�����������
		if (pEnemy != NULL)
		{
			pEnemy->Uninit();
		}

		m_bDeath = true;
		Uninit();
	}
	else if(m_bDeathCountFlog == false)
	{
		if (CGame::GetEventStart() == true)
		{//�C�x���g�̃����X�^�[�n�E�X���̏ꍇ
			CGame::GetMap2D()->DeleteEventEnemy();
		}

		if (CGame::GetMap2D()->GetEventEnemy() == 0)
		{
			CGame::GetMap2D()->SetDirectionPos(pos);
		}

		m_bDeathCountFlog = true;
		SetMatColor(D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f));
	}
}

//====================================================================
//�u���b�N�Ƃ̓����蔻�菈��
//====================================================================
bool CEnemy3D::CollisionBlock(D3DXVECTOR3 *pos, bool bX)
{
	for (int nCntPriority = 0; nCntPriority < PRIORITY_MAX; nCntPriority++)
	{
		//�I�u�W�F�N�g���擾
		CObject *pObj = CObject::GetTop(nCntPriority);

		while (pObj != NULL)
		{
			CObject *pObjNext = pObj->GetNext();
			D3DXVECTOR3 ObjPos = pObj->GetPos();

			if (sqrtf((pos->x - ObjPos.x) * (pos->x - ObjPos.x)
				+ (pos->y - ObjPos.y) * (pos->y - ObjPos.y)) <= 100.0f)
			{//�~�̔��肪��������

				CObject::TYPE type = pObj->GetType();			//��ނ��擾

				if (type == TYPE_BREAKBLOCK3D)
				{//��ނ��u���b�N�̎�
					if (pObj->Collision(pos, GetPosOld(), &m_move, ENEMY_HEIGHT * 0.5f, ENEMY_WIGHT * 0.5f, bX) == true)
					{
						return true;
					}
				}
			}
			pObj = pObjNext;
		}
	}
	return false;
}

//====================================================================
//�I�u�W�F�N�g�̓����蔻�菈��(�~)
//====================================================================
void CEnemy3D::CollisionObjectCircle(D3DXVECTOR3 pos, float nRadiusOut, int BreakCount)
{
	for (int nCntPriority = 0; nCntPriority < PRIORITY_MAX; nCntPriority++)
	{
		//�I�u�W�F�N�g���擾
		CObject *pObj = CObject::GetTop(nCntPriority);

		while (pObj != NULL)
		{
			CObject *pObjNext = pObj->GetNext();
			CObject::TYPE type = pObj->GetType();				//��ނ��擾
			if (type == TYPE_BREAKBLOCK3D)
			{//��ނ��G�̎�
				CBreak_Block3D *pBreakBlock = (CBreak_Block3D*)pObj;

				D3DXVECTOR3 CollisionPos = pBreakBlock->GetPos();			//�ʒu���擾

				if (sqrtf((pos.x - CollisionPos.x) * (pos.x - CollisionPos.x)
					+ (pos.y - CollisionPos.y) * (pos.y - CollisionPos.y)) <= nRadiusOut)
				{//�~�̔��肪��������
					if (sqrtf((pos.x - CollisionPos.x) * (pos.x - CollisionPos.x)
						+ (pos.y - CollisionPos.y) * (pos.y - CollisionPos.y)) <= nRadiusOut * 0.5f)
					{//�~�̔��肪��������
						pBreakBlock->BreakCountSet((int)(BreakCount * 0.5f));
					}
					else
					{
						pBreakBlock->BreakCountSet(BreakCount);
					}
				}
			}
			else if (type == TYPE_ENEMY3D
				&& pObj != this
				&& pObj->GetLife() > 0)
			{//��ނ��G�̎�
				D3DXVECTOR3 CollisionPos = pObj->GetPos();			//�ʒu���擾

				if (sqrtf((pos.x - CollisionPos.x) * (pos.x - CollisionPos.x)
					+ (pos.y - CollisionPos.y) * (pos.y - CollisionPos.y)) <= nRadiusOut)
				{//�~�̔��肪��������
					pObj->Hit(CollisionPos, 2);
				}
			}
			pObj = pObjNext;
		}
	}
}
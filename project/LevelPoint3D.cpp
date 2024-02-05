//============================================
//
//	�o���l�̏��� [LevelPoint3D.cpp]
//	Author:sakamoto kai
//
//============================================
#include "LevelPoint3D.h"
#include "renderer.h"
#include "manager.h"
#include "game.h"
#include "texture.h"
#include "Xmodel.h"
#include "particle.h"
#include "player3D.h"
#include "effect.h"

//�}�N����`
#define LEVELPOINT_WIGHT (10.0f)	//����
#define LEVELPOINT_HEIGHT (10.0f)	//�c��
#define LEVELPOINT_SPEED (20.0f)	//�o���l�̃X�s�[�h

//�ÓI�����o�ϐ��錾
int CLevelPoint::m_nIdxXModel = NULL;					//X���f���̎g�p�ԍ�
int CLevelPoint::m_nIdxTexture[64] = {};				//X���f���̃e�N�X�`���̎g�p�ԍ�

//====================================================================
//�R���X�g���N�^
//====================================================================
CLevelPoint::CLevelPoint(int nPriority) : CObjectX(nPriority)
{
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	SetWight(LEVELPOINT_WIGHT);
	SetHeight(LEVELPOINT_HEIGHT);
	m_MoveState = MOVE_WAIT;
	m_MoveCount = 0;
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CLevelPoint::~CLevelPoint()
{

}

//====================================================================
//��������
//====================================================================
CLevelPoint *CLevelPoint::Create()
{
	CLevelPoint *pEnemy = NULL;

	if (pEnemy == NULL)
	{
		//�G�̐���
		pEnemy = new CLevelPoint();
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
HRESULT CLevelPoint::Init(void)
{
	SetType(CObject::TYPE_LEVELPOINT3D);

	//X�t�@�C���̊��蓖��
	CXModel *pXModel = CManager::GetInstance()->GetXModel();
	m_nIdxXModel = pXModel->Regist("data\\MODEL\\LevelPoint.x");
	CTexture *pTexture = CManager::GetInstance()->GetTexture();
	pTexture->XModelRegist(&m_nIdxTexture[0], m_nIdxXModel);

	D3DXVECTOR3 pos = GetPos();

	CObjectX::Init();

	return S_OK;
}

//====================================================================
//�I������
//====================================================================
void CLevelPoint::Uninit(void)
{
	CObjectX::Uninit();
}

//====================================================================
//�X�V����
//====================================================================
void CLevelPoint::Update(void)
{
	//�ʒu�̎擾
	D3DXVECTOR3 pos = GetPos();
	D3DXVECTOR3 rot = GetRot();

	//�ߋ��̈ʒu�ݒ�
	SetPosOld(GetPos());

	if (m_MoveState == MOVE_PLAYER)
	{
		//�v���C���[�̏����擾����
		CPlayer3D *pPlayer = CGame::GetPlayer3D();
		D3DXVECTOR3 PlayerPos = pPlayer->GetPos();
		PlayerPos.y += pPlayer->GetHeight() * 0.25f;

		//�G���v���C���[�ɒǔ�����
		m_move = PlayerPos - pos;
		D3DXVec3Normalize(&m_move, &m_move);
		m_move *= LEVELPOINT_SPEED;
	}
	else
	{
		m_MoveCount++;
		if (m_MoveCount > 30)
		{
			m_MoveState = MOVE_PLAYER;
		}
	}

	//�����W��
	m_move = m_move * 0.9f;

	//�ʒu�ݒ�
	pos += m_move;

	rot.x += 0.1f;
	rot.z += 0.3f;

	CEffect *pEffect = CEffect::Create();
	pEffect->SetPos(pos);
	pEffect->SetRadius(LEVELPOINT_HEIGHT);
	pEffect->SetLife(20);
	pEffect->SetDel(0.2f);

	//�ʒu�̐ݒ�
	SetPos(pos);
	SetRot(rot);

	//���̐ݒ�
	CObjectX::Update();
}

//====================================================================
//�`�揈��
//====================================================================
void CLevelPoint::Draw(void)
{
	CObjectX::Draw();
}
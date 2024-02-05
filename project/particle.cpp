//============================================
//
//	�p�[�e�B�N������ [particle.cpp]
//	Author:sakamoto kai
//
//============================================
#include "particle.h"
#include "effect.h"
#include "FallEffect.h"
#include "manager.h"
#include "camera.h"

//�}�N����`
#define STANDERD_SPEED1 (1.0f)	//�p�[�e�B�N���̊�̃X�s�[�h
#define STANDERD_SPEED2 (15.0f)	//�p�[�e�B�N���̊�̃X�s�[�h
#define STANDERD_SPEED3 (400.0f)	//�p�[�e�B�N���̊�̃X�s�[�h

#define RAND_PAI1 (731)			//�p�x�̃����_��
#define PUT_PARTICLE1 (15)		//�P�t���[���ɏo���p�[�e�B�N���̐�
#define RAND_PAI2 (731)			//�p�x�̃����_��
#define PUT_PARTICLE2 (45)		//�P�t���[���ɏo���p�[�e�B�N���̐�

#define RAND_PAI3 (731)			//�p�x�̃����_��
#define PUT_PARTICLE3 (1)		//�P�t���[���ɏo���p�[�e�B�N���̐�

//====================================================================
//�R���X�g���N�^
//====================================================================
CParticle::CParticle()
{
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_col = D3DXCOLOR(1.0f,1.0f,1.0f,1.0f);
	m_nLife = 0;
	m_nSize = 0.0f;
	m_nType = 0;
}

//====================================================================
//�R���X�g���N�^
//====================================================================
CParticle::CParticle(D3DXVECTOR3 pos, D3DXCOLOR col, int nLife, float nSize, int nType)
{
	m_pos = pos;
	m_col = col;
	m_nLife = nLife;
	m_nSize = nSize;
	m_nType = nType;
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CParticle::~CParticle()
{

}

//====================================================================
//��������
//====================================================================
CParticle *CParticle::Create(D3DXVECTOR3 pos, D3DXCOLOR col, int nLife, float nSize, int nType)
{
	CParticle *pParticle = NULL;

	if (pParticle == NULL)
	{
		//�I�u�W�F�N�g2D�̐���
		pParticle = new CParticle(pos, col, nLife, nSize, nType);
	}

	//�I�u�W�F�N�g�̏���������
	if (FAILED(pParticle->Init()))
	{//���������������s�����ꍇ
		return NULL;
	}

 	return pParticle;
}

//====================================================================
//������
//====================================================================
HRESULT CParticle::Init(void)
{
	CEffect *pEffect = NULL;
	CFallEffect *pFallEffect = NULL;
	SetType(CObject::TYPE_PARTICLE);

	if (m_nType == 1)
	{
		for (int nCntAppear = 0; nCntAppear < PUT_PARTICLE1; nCntAppear++)
		{
			//�ړ��ʂ̐ݒ�
			m_move.x = sinf((float)(rand() % RAND_PAI1 - (RAND_PAI1 - 1) / 2) / 100.0f + D3DX_PI * -0.5f)*(float)((rand() % 100) / 10.0f) + STANDERD_SPEED1;
			m_move.y = cosf((float)(rand() % RAND_PAI1 - (RAND_PAI1 - 1) / 2) / 100.0f + D3DX_PI * -0.5f)*(float)((rand() % 100) / 10.0f) + STANDERD_SPEED1;
			m_move.z = 0.0f;

			//�G�t�F�N�g�̐���
			pEffect = CEffect::Create();

			pEffect->SetPos(m_pos);
			pEffect->SetMove(m_move);
			pEffect->SetColor(m_col);
			pEffect->SetRadius(m_nSize);
			pEffect->SetLife(m_nLife);
		}
	}
	if (m_nType == 2)
	{
		for (int nCntAppear = 0; nCntAppear < PUT_PARTICLE2; nCntAppear++)
		{
			//�ړ��ʂ̐ݒ�
			m_move.x = sinf((float)(rand() % RAND_PAI2 - (RAND_PAI2 - 1) / 2) / 100.0f + D3DX_PI * -0.5f);
			m_move.y = cosf((float)(rand() % RAND_PAI2 - (RAND_PAI2 - 1) / 2) / 100.0f + D3DX_PI * -0.5f);
			m_move.z = 0.0f;

			D3DXVec3Normalize(&m_move, &m_move);
			m_move *= STANDERD_SPEED2;

			//�G�t�F�N�g�̐���
			pEffect = CEffect::Create();

			pEffect->SetPos(m_pos);
			pEffect->SetDel(4.0f);
			pEffect->SetMove(m_move);
			pEffect->SetColor(m_col);
			pEffect->SetRadius(m_nSize);
			pEffect->SetLife(m_nLife);
		}
	}
	if (m_nType == 3)
	{
		for (int nCntAppear = 0; nCntAppear < PUT_PARTICLE3; nCntAppear++)
		{
			//�ړ��ʂ̐ݒ�
			m_pos.x = sinf((float)(rand() % RAND_PAI2 - (RAND_PAI2 - 1) / 2) / 100.0f + D3DX_PI * -0.5f);
			m_pos.y = 0.0f;
			m_pos.z = cosf((float)(rand() % RAND_PAI2 - (RAND_PAI2 - 1) / 2) / 100.0f + D3DX_PI * -0.5f);

			D3DXVec3Normalize(&m_pos, &m_pos);
			m_pos *= STANDERD_SPEED3;
			m_pos.y = CManager::GetInstance()->GetCamera()->GetPosY() - 400.0f;

			//�G�t�F�N�g�̐���
			pFallEffect = CFallEffect::Create();

			pFallEffect->SetPos(m_pos);
			pFallEffect->SetColor(m_col);
			pFallEffect->SetLife(m_nLife);
		}
	}

	Uninit();

	return S_OK;
}

//====================================================================
//�p�[�e�B�N���̏I������
//====================================================================
void CParticle::Uninit(void)
{
	SetDeathFlag(true);
}

//====================================================================
//�p�[�e�B�N���̍X�V����
//====================================================================
void CParticle::Update(void)
{

}

//====================================================================
//�p�[�e�B�N���̕`�揈��
//====================================================================
void CParticle::Draw(void)
{

}
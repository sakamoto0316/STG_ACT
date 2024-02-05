//============================================
//
//	�p�[�e�B�N������ [DirectionParticle.cpp]
//	Author:sakamoto kai
//
//============================================
#include "DirectionParticle.h"
#include "effect.h"

//�}�N����`
#define STANDERD_SPEED1 (1.0f)	//�p�[�e�B�N���̊�̃X�s�[�h
#define RAND_PAI1 (731)			//�p�x�̃����_��
#define PUT_PARTICLE1 (1)		//�P�t���[���ɏo���p�[�e�B�N���̐�

//====================================================================
//�R���X�g���N�^
//====================================================================
CDirectionParticle::CDirectionParticle()
{
	m_Rand = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	m_nLife = 0;
	m_nSize = 0.0f;
	m_nType = 0;
}

//====================================================================
//�R���X�g���N�^
//====================================================================
CDirectionParticle::CDirectionParticle(D3DXVECTOR3 pos, D3DXCOLOR col, float Radius, int nLife, float nSize, int nType)
{
	m_pos = pos;
	m_col = col;
	m_nLife = nLife;
	m_nSize = nSize;
	m_nType = nType;
	m_nRadius = Radius;
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CDirectionParticle::~CDirectionParticle()
{

}

//====================================================================
//��������
//====================================================================
CDirectionParticle *CDirectionParticle::Create(D3DXVECTOR3 pos, D3DXCOLOR col, float Radius, int nLife, float nSize, int nType)
{
	CDirectionParticle *pParticle = NULL;

	if (pParticle == NULL)
	{
		//�I�u�W�F�N�g2D�̐���
		pParticle = new CDirectionParticle(pos, col, Radius, nLife, nSize, nType);
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
HRESULT CDirectionParticle::Init(void)
{
	CEffect *pEffect = NULL;
	SetType(CObject::TYPE_PARTICLE);

	if (m_nType == 1)
	{
		for (int nCntAppear = 0; nCntAppear < PUT_PARTICLE1; nCntAppear++)
		{
			D3DXVECTOR3 StartPos = m_pos;

			//�ړ��ʂ̐ݒ�
			m_Rand.x = sinf((float)(rand() % RAND_PAI1 - (RAND_PAI1 - 1) / 2) / 100.0f + D3DX_PI * -0.5f);
			m_Rand.y = cosf((float)(rand() % RAND_PAI1 - (RAND_PAI1 - 1) / 2) / 100.0f + D3DX_PI * -0.5f);
			m_Rand.z = 0.0f;

			D3DXVec3Normalize(&m_Rand, &m_Rand);
			m_Rand *= m_nRadius;

			//�ړ��ʂ̐ݒ�
			m_move = m_Rand * -0.05f;

			//�ʒu�̐ݒ�
			StartPos += m_Rand;

			//�G�t�F�N�g�̐���
			pEffect = CEffect::Create();

			pEffect->SetPos(StartPos);
			pEffect->SetDel(2.0f);
			pEffect->SetMove(m_move);
			pEffect->SetColor(m_col);
			pEffect->SetRadius(m_nSize);
			pEffect->SetLife(m_nLife);
		}
	}

	Uninit();

	return S_OK;
}

//====================================================================
//�p�[�e�B�N���̏I������
//====================================================================
void CDirectionParticle::Uninit(void)
{
	SetDeathFlag(true);
}

//====================================================================
//�p�[�e�B�N���̍X�V����
//====================================================================
void CDirectionParticle::Update(void)
{

}

//====================================================================
//�p�[�e�B�N���̕`�揈��
//====================================================================
void CDirectionParticle::Draw(void)
{

}
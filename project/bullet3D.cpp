//============================================
//
//	�e�̏��� [bullet3D.cpp]
//	Author:sakamoto kai
//
//============================================
#include "bullet3D.h"
#include "object.h"
#include "input.h"
#include "renderer.h"
#include "manager.h"
#include "texture.h"
#include "effect.h"
#include "particle.h"
#include "score.h"
#include "Enemy3D.h"
#include "Break.h"
#include "sound.h"

//�}�N����`
#define BULLET_WIGHT (10.0f)		//����
#define BULLET_HEIGHT (10.0f)		//�c��
#define BULLET_SPEED (10.0f)		//�v���C���[�̑���
#define BULLET_STOP (0.5f)			//�����W��
#define EFFECT_SIZE (35.0f)			//�G�t�F�N�g�̑傫��
#define EFFECT_LIFE (50)			//�G�t�F�N�g�̎���

//====================================================================
//�R���X�g���N�^
//====================================================================
CBullet3D::CBullet3D(BULLET_TYPE Type, int nPriority) : CObjectBillboard(nPriority)
{
	m_Type = Type;
	m_SpreadCount = 0;
	SetWight(BULLET_WIGHT);
	SetHeight(BULLET_HEIGHT);
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_stop = BULLET_STOP;
	m_nLife = 0;
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CBullet3D::~CBullet3D()
{

}

//====================================================================
//��������
//====================================================================
CBullet3D *CBullet3D::Create(BULLET_TYPE Type)
{
	CBullet3D *pBullet = NULL;

	if (pBullet == NULL)
	{
		//�I�u�W�F�N�g3D�̐���
		pBullet = new CBullet3D(Type);
	}

	//�I�u�W�F�N�g�̏���������
	if (FAILED(pBullet->Init()))
	{//���������������s�����ꍇ
		return NULL;
	}

	return pBullet;
}

//====================================================================
//����������
//====================================================================
HRESULT CBullet3D::Init(void)
{
	CTexture *pTexture = CManager::GetInstance()->GetTexture();;
	m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\Bullet00.png");

	SetType(CObject::TYPE_BULLET3D);

	CObjectBillboard::Init();

	return S_OK;
}

//====================================================================
//�I������
//====================================================================
void CBullet3D::Uninit(void)
{
	CObjectBillboard::Uninit();
}

//====================================================================
//�X�V����
//====================================================================
void CBullet3D::Update(void)
{
	bool bHit = false;

	D3DXVECTOR3 pos = GetPos();

	//�ʒu�X�V
	pos += m_move;

	//�G�Ƃ̓����蔻�菈��
	bHit = CollisionObject(pos);

	if (bHit == false)
	{
		//�e�̎���
		if (m_nLife <= 0)
		{
			Hit(pos);
			return;
		}
		else
		{
			CEffect *pEffect = NULL;

			//�G�t�F�N�g�̐���
			pEffect = CEffect::Create();

			pEffect->SetPos(pos);
			pEffect->SetRadius(EFFECT_SIZE);
			pEffect->SetLife(EFFECT_LIFE);

			m_nLife--;
		}

		SetPos(pos);

		//���_���̍X�V
		CObjectBillboard::Update();
	}
}

//====================================================================
//�`�揈��
//====================================================================
void CBullet3D::Draw(void)
{
	CObjectBillboard::Draw();
}

//====================================================================
//�e�̓����蔻�菈��
//====================================================================
bool CBullet3D::CollisionObject(D3DXVECTOR3 pos)
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
			float CollsionWight = pObj->GetWight() * 0.5f;		//�����擾
			float CollsionHeight = pObj->GetHeight() * 0.5f;	//�������擾
			float fmyWight = GetWight() * 0.5f;					//���S����̕�
			float fmyHeight = GetHeight() * 0.5f;				//���S����̍���

			if (type == TYPE_ENEMY3D)
			{//��ނ��G�̎�
				if (pos.x + fmyWight > CollsionPos.x - CollsionWight &&
					pos.x - fmyWight < CollsionPos.x + CollsionWight &&
					pos.y + fmyHeight > CollsionPos.y - CollsionHeight &&
					pos.y - fmyHeight < CollsionPos.y + CollsionHeight)
				{
					//�G�̏I������
					pObj->Hit(CollsionPos, 1);

					//�e���Ԃ������Ƃ��̏���
					Hit(pos);

					return true;
				}
			}
			else if (type == TYPE_NORMALBLOCK)
			{//��ނ��u���b�N�̎�
				if (pos.x + fmyWight > CollsionPos.x - CollsionWight &&
					pos.x - fmyWight < CollsionPos.x + CollsionWight &&
					pos.y + fmyHeight > CollsionPos.y - CollsionHeight &&
					pos.y - fmyHeight < CollsionPos.y + CollsionHeight)
				{
					//�p�[�e�B�N���̐���
					CParticle::Create
					(
						pos,
						D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f),
						20,
						50.0f,
						1
					);

					//�e���Ԃ������Ƃ��̏���
					Hit(pos);

					return true;
				}
			}
			else if (type == TYPE_BREAKBLOCK3D)
			{//��ނ��u���b�N�̎�
				if (pos.x + fmyWight > CollsionPos.x - CollsionWight &&
					pos.x - fmyWight < CollsionPos.x + CollsionWight &&
					pos.y + fmyHeight > CollsionPos.y - CollsionHeight &&
					pos.y - fmyHeight < CollsionPos.y + CollsionHeight)
				{
					CManager::GetInstance()->GetSound()->PlaySoundA(CSound::SOUND_LABEL_SE_BREAK_BLOCK);

					//�p�[�e�B�N���̐���
					CParticle::Create
					(
						pos,
						D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f),
						20,
						50.0f,
						1
					);

					CBreak *pPiece = CBreak::Create(pObj->GetPos());

					//�u���b�N�̏I������
					pObj->Uninit();

					//�e���Ԃ������Ƃ��̏���
					Hit(pos);

					return true;
				}
			}
			else if (type == TYPE_BLOCKUI)
			{//��ނ��u���b�N�̎�
				if (pos.x + fmyWight > CollsionPos.x - CollsionWight &&
					pos.x - fmyWight < CollsionPos.x + CollsionWight &&
					pos.y + fmyHeight > CollsionPos.y - CollsionHeight &&
					pos.y - fmyHeight < CollsionPos.y + CollsionHeight)
				{
					CManager::GetInstance()->GetSound()->PlaySoundA(CSound::SOUND_LABEL_SE_SELECT_PUSH);

					//�p�[�e�B�N���̐���
					CParticle::Create
					(
						pos,
						D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f),
						20,
						50.0f,
						1
					);

					//�G�̏I������
					pObj->Hit(CollsionPos, 1);

					//�e���Ԃ������Ƃ��̏���
					Hit(pos);

					return true;
				}
			}


			pObj = pObjNext;
		}
	}
	return false;
}

//====================================================================
//�e�������������̏���
//====================================================================
void CBullet3D::Hit(D3DXVECTOR3 pos)
{
	CBullet3D *pBullet = NULL;

	switch (m_Type)
	{
	case BULLET_NORMAL:
		//�p�[�e�B�N���̐���
		CParticle::Create
		(
			pos,
			D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f),
			20,
			50.0f,
			1
		);
		break;

	case BULLET_SPREAD_3WAY:

		for (int nCntBullet = 0; nCntBullet < 3; nCntBullet++)
		{
			pBullet = CBullet3D::Create(CBullet3D::BULLET_NORMAL);
			pBullet->SetPos(pos);
			D3DXVECTOR3 rot = GetRot();
			pBullet->SetMove(D3DXVECTOR3
			(
				sinf((D3DX_PI *  (-0.25f + 0.25f * nCntBullet)) + rot.z) * 10.0f,
				cosf((D3DX_PI *  (-0.25f + 0.25f * nCntBullet)) + rot.z) * 10.0f,
				0.0f
			));
			pBullet->SetRot(rot);
			pBullet->SetLife(20);
			pBullet->SetVerTex();
		}
		break;

	case BULLET_SPREAD_CONTINUE_3WAY:

		if (m_SpreadCount > 0)
		{
			for (int nCntBullet = 0; nCntBullet < 2; nCntBullet++)
			{
				pBullet = CBullet3D::Create(CBullet3D::BULLET_NORMAL);
				pBullet->SetPos(pos);
				D3DXVECTOR3 rot = GetRot();
				pBullet->SetMove(D3DXVECTOR3
				(
					sinf((D3DX_PI *  (-0.75f - 0.5f * nCntBullet)) + rot.z) * 10.0f,
					cosf((D3DX_PI *  (-0.75f - 0.5f * nCntBullet)) + rot.z) * 10.0f,
					0.0f
				));
				pBullet->SetRot(rot);
				pBullet->SetLife(20);
				pBullet->SetVerTex();
			}

			pBullet = CBullet3D::Create(CBullet3D::BULLET_SPREAD_CONTINUE_3WAY);
			pBullet->SetPos(pos);
			D3DXVECTOR3 rot = GetRot();
			pBullet->SetMove(D3DXVECTOR3
			(
				sinf((D3DX_PI * -1.0f) + rot.z) * 10.0f,
				cosf((D3DX_PI * -1.0f) + rot.z) * 10.0f,
				0.0f
			));
			pBullet->SetRot(rot);
			pBullet->SetLife(20);
			pBullet->SetVerTex();
			m_SpreadCount--;
			pBullet->SetSpreadCount(m_SpreadCount);
		}
		else
		{
			for (int nCntBullet = 0; nCntBullet < 3; nCntBullet++)
			{
				pBullet = CBullet3D::Create(CBullet3D::BULLET_NORMAL);
				pBullet->SetPos(pos);
				D3DXVECTOR3 rot = GetRot();
				pBullet->SetMove(D3DXVECTOR3
				(
					sinf((D3DX_PI *  (-0.75f - 0.25f * nCntBullet)) + rot.z) * 10.0f,
					cosf((D3DX_PI *  (-0.75f - 0.25f * nCntBullet)) + rot.z) * 10.0f,
					0.0f
				));
				pBullet->SetRot(rot);
				pBullet->SetLife(20);
				pBullet->SetVerTex();
			}
		}

		break;

	case BULLET_SPREAD_CROSS:

			for (int nCntBullet = 0; nCntBullet < 4; nCntBullet++)
			{
				pBullet = CBullet3D::Create(CBullet3D::BULLET_NORMAL);
				pBullet->SetPos(pos);
				D3DXVECTOR3 rot = GetRot();
				pBullet->SetMove(D3DXVECTOR3
				(
					sinf((D3DX_PI *  (-0.75f + 0.5f * nCntBullet)) + rot.z) * 10.0f,
					cosf((D3DX_PI *  (-0.75f + 0.5f * nCntBullet)) + rot.z) * 10.0f,
					0.0f
				));
				pBullet->SetRot(D3DXVECTOR3(0.0f, 0.0f, (D3DX_PI *  (-0.75f + 0.5f * nCntBullet)) + rot.z));
				pBullet->SetLife(20);
				pBullet->SetVerTex();
			}

		break;

	case BULLET_SPREAD_EXCROSS:

		for (int nCntBullet = 0; nCntBullet < 4; nCntBullet++)
		{
			pBullet = CBullet3D::Create(CBullet3D::BULLET_SPREAD_3WAY);
			pBullet->SetPos(pos);
			D3DXVECTOR3 rot = GetRot();
			pBullet->SetMove(D3DXVECTOR3
			(
				sinf((D3DX_PI *  (-0.75f + 0.5f * nCntBullet)) + rot.z) * 10.0f,
				cosf((D3DX_PI *  (-0.75f + 0.5f * nCntBullet)) + rot.z) * 10.0f,
				0.0f
			));
			pBullet->SetRot(D3DXVECTOR3(0.0f, 0.0f, (D3DX_PI *  (-0.75f + 0.5f * nCntBullet)) + rot.z));
			pBullet->SetLife(20);
			pBullet->SetVerTex();
		}
		m_SpreadCount--;
		SetSpreadCount(m_SpreadCount);

		break;
	}

	//�����̏I������
	Uninit();
}
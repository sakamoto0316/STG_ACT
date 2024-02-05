//============================================
//
//	�G�̒e�̏��� [EnemyBullet3D.cpp]
//	Author:sakamoto kai
//
//============================================
#include "EnemyBullet3D.h"
#include "object.h"
#include "input.h"
#include "renderer.h"
#include "manager.h"
#include "texture.h"
#include "effect.h"
#include "particle.h"
#include "score.h"
#include "Enemy3D.h"
#include "Game.h"

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
CEenmyBullet3D::CEenmyBullet3D(int nPriority) : CObjectBillboard(nPriority)
{
	SetWight(BULLET_WIGHT);
	SetHeight(BULLET_HEIGHT);
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_stop = BULLET_STOP;
	m_nLife = 0;
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CEenmyBullet3D::~CEenmyBullet3D()
{

}

//====================================================================
//��������
//====================================================================
CEenmyBullet3D *CEenmyBullet3D::Create()
{
	CEenmyBullet3D *pBullet = NULL;

	if (pBullet == NULL)
	{
		//�I�u�W�F�N�g3D�̐���
		pBullet = new CEenmyBullet3D();
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
HRESULT CEenmyBullet3D::Init(void)
{
	CTexture *pTexture = CManager::GetInstance()->GetTexture();;
	m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\Bullet00.png");

	SetType(CObject::TYPE_ENEMYBULLET3D);

	CObjectBillboard::Init();

	return S_OK;
}

//====================================================================
//�I������
//====================================================================
void CEenmyBullet3D::Uninit(void)
{
	CObjectBillboard::Uninit();
}

//====================================================================
//�X�V����
//====================================================================
void CEenmyBullet3D::Update(void)
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
			//�p�[�e�B�N���̐���
			CParticle::Create
			(
				pos,
				D3DXCOLOR(0.5f, 0.5f, 0.5f, 1.0f),
				20,
				50.0f,
				1
			);

			Uninit();
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
			pEffect->SetColor(D3DXCOLOR(0.5f, 0.0f, 0.5f, 1.0f));

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
void CEenmyBullet3D::Draw(void)
{
	CObjectBillboard::Draw();
}

//====================================================================
//�e�̓����蔻�菈��
//====================================================================
bool CEenmyBullet3D::CollisionObject(D3DXVECTOR3 pos)
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

			if (type == TYPE_PLAYER3D)
			{//��ނ��G�̎�
				if (pos.x + fmyWight > CollsionPos.x - CollsionWight &&
					pos.x - fmyWight < CollsionPos.x + CollsionWight &&
					pos.y + fmyHeight > CollsionPos.y - CollsionHeight &&
					pos.y - fmyHeight < CollsionPos.y + CollsionHeight)
				{
					//�G�̏I������
					pObj->HitDamage(1);

					//�����̏I������
					Uninit();

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
						D3DXCOLOR(0.5f, 0.5f, 1.0f, 1.0f),
						20,
						50.0f,
						1
					);

					//�����̏I������
					Uninit();

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
					//�p�[�e�B�N���̐���
					CParticle::Create
					(
						pos,
						D3DXCOLOR(0.5f, 0.5f, 1.0f, 1.0f),
						20,
						50.0f,
						1
					);

					//�u���b�N�̏I������
					pObj->Uninit();

					//�X�R�A�̉��Z
					CGame::GetScore()->AddScore(30);

					//�����̏I������
					Uninit();

					return true;
				}
			}
			pObj = pObjNext;
		}
	}
	return false;
}
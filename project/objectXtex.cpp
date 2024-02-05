//============================================
//
//	�I�u�W�F�N�gX�t�@�C�� [objectXtex.cpp]
//	Author:sakamoto kai
//
//============================================
#include "objectXtex.h"
#include "renderer.h"
#include "manager.h"
#include "game.h"
#include "texture.h"
#include "player3D.h"

#define POLYDON_SIZE (10.0f)

//====================================================================
//�R���X�g���N�^
//====================================================================
CObjectXtex::CObjectXtex(int nPriority) :CObject(nPriority)
{
	m_pBuffMat = NULL;
	m_pMesh = NULL;
	m_Wight = POLYDON_SIZE;
	m_Height = POLYDON_SIZE;
	m_dwNumMat = 0;
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_MatColor = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	m_bTexOne = false;
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CObjectXtex::~CObjectXtex()
{

}

//====================================================================
//��������
//====================================================================
CObjectXtex *CObjectXtex::Create(void)
{
	CObjectXtex *pObjectXtex = NULL;

	if (pObjectXtex == NULL)
	{
		//�I�u�W�F�N�g3D�̐���
		pObjectXtex = new CObjectXtex();
	}

	//�I�u�W�F�N�g�̏���������
	if (FAILED(pObjectXtex->Init()))
	{//���������������s�����ꍇ
		return NULL;
	}

	return pObjectXtex;
}

//====================================================================
//����������
//====================================================================
HRESULT CObjectXtex::Init(void)
{
	return S_OK;
}

//====================================================================
//�I������
//====================================================================
void CObjectXtex::Uninit(void)
{
	SetDeathFlag(true);
}

//====================================================================
//�X�V����
//====================================================================
void CObjectXtex::Update(void)
{
	CPlayer3D *pPlayer = CGame::GetPlayer3D();

	if (CScene::GetMode() == CScene::MODE_GAME)
	{
		if (pPlayer->GetPos().y + 400.0f < m_pos.y &&
			CGame::GetTutorial() == false &&
			CGame::GetEventStart() == false)
		{
			Uninit();
			return;
		}
	}
}

//====================================================================
//�`�揈��
//====================================================================
void CObjectXtex::Draw(void)
{
	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();
	D3DXMATRIX mtxRot, mtxTrans;	//�v�Z�p�}�g���b�N�X
	D3DMATERIAL9 matDef;			//���݂̃}�e���A���ۑ��p
	D3DXMATERIAL *pMat;				//�}�e���A���f�[�^�ւ̃|�C���^

									//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);

	//�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);

	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);

	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	//���݂̃}�e���A��������
	pDevice->GetMaterial(&matDef);

	//�}�e���A���f�[�^�ւ̃|�C���^����������
	pMat = (D3DXMATERIAL*)m_pBuffMat->GetBufferPointer();

	for (int nCntMat = 0; nCntMat < (int)m_dwNumMat; nCntMat++)
	{
		//�}�e���A���̐ݒ�
		pMat[nCntMat].MatD3D.Diffuse = m_MatColor;
		pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

		CTexture *pTexture = CManager::GetInstance()->GetTexture();

		assert(GetIdx() != -1);		//�e�N�X�`���̔ԍ������Y�ꂽ�ꍇ�G���[��f��

		if (m_bTexOne == false)
		{
			//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, pTexture->GetAddress(GetIdx()));
		}
		else
		{
			if (nCntMat == 0)
			{
				//�e�N�X�`���̐ݒ�
				pDevice->SetTexture(0, pTexture->GetAddress(GetIdx()));
			}
			else
			{
				//�e�N�X�`���̐ݒ�
				pDevice->SetTexture(0, NULL);
			}
		}

		//���f��(�p�[�c)�̕`��
		m_pMesh->DrawSubset(nCntMat);
	}
	//�ۑ����Ă����}�e���A����߂�
	pDevice->SetMaterial(&matDef);
}

//====================================================================
//���f�����̊��蓖��
//====================================================================
void CObjectXtex::BindFile(LPD3DXMESH pMesh, LPD3DXBUFFER pBuffMat, DWORD pdwNumMat)
{
	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	//���̊��蓖��
	m_pMesh = pMesh;
	m_pBuffMat = pBuffMat;
	m_dwNumMat = pdwNumMat;
}
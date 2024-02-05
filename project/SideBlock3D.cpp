//============================================
//
//	���E�̃u���b�N�̏��� [SideBlock3D.cpp]
//	Author:sakamoto kai
//
//============================================
#include "Sideblock3D.h"
#include "renderer.h"
#include "manager.h"
#include "game.h"
#include "map2D.h"
#include "texture.h"
#include "DebugNumber3D.h"
#include "XModel.h"
#include "score.h"

//�}�N����`
#define BLOCK_WIGHT (400.0f)	//����
#define BLOCK_HEIGHT (2000.0f)	//�c��

LPD3DXMESH CSide_Block3D::m_pMesh = NULL;				//���b�V��(���_���)�ւ̃|�C���^
LPD3DXBUFFER CSide_Block3D::m_pBuffMat = NULL;			//�}�e���A���ւ̃|�C���^
DWORD CSide_Block3D::m_dwNumMat = NULL;					//�}�e���A���̐�
int CSide_Block3D::m_nIdxXModel = NULL;					//�}�e���A���̐�
//====================================================================
//�R���X�g���N�^
//====================================================================
CSide_Block3D::CSide_Block3D(int nPriority) : CObjectXtex(nPriority)
{
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//�ړ���
	m_nIdxTexture = 0;						//�e�N�X�`���̔ԍ�
	SetWight(BLOCK_WIGHT);					//�c�̔ԍ�
	SetHeight(BLOCK_HEIGHT);				//�c�̔ԍ�

	if (CScene::GetMode() == CScene::MODE_GAME)
	{
		switch (CGame::GetMap2D()->GetMapLevel() % 3 + 1)
		{
		case 1:
			m_BlockColor = D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f);
			break;

		case 2:
			m_BlockColor = D3DXCOLOR(0.9f, 0.3f, 0.0f, 1.0f);
			break;

		case 3:
			m_BlockColor = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
			break;

		default:
			m_BlockColor = D3DXCOLOR(0.9f, 0.3f, 0.0f, 1.0f);
			break;
		}
	}
	else
	{
		m_BlockColor = D3DXCOLOR(0.9f, 0.3f, 0.0f, 1.0f);
	}
	//m_BlockColor = D3DXCOLOR(0.21f, 0.76f, 0.24f, 1.0f);
	m_bColorChange = false;
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CSide_Block3D::~CSide_Block3D()
{

}

//====================================================================
//��������
//====================================================================
CSide_Block3D *CSide_Block3D::Create()
{
	CSide_Block3D *pPlayer = NULL;

	if (pPlayer == NULL)
	{
		//�I�u�W�F�N�g2D�̐���
		pPlayer = new CSide_Block3D();
	}

	//X�t�@�C���̊��蓖��
	CXModel *pXModel = CManager::GetInstance()->GetXModel();
	m_nIdxXModel = pXModel->Regist("data\\MODEL\\SideBlock00.x");
	pXModel->GetXModelInfo(&m_pBuffMat, &m_dwNumMat, &m_pMesh, m_nIdxXModel);
	pPlayer->BindFile(m_pMesh, m_pBuffMat, m_dwNumMat);

	//�I�u�W�F�N�g�̏���������
	if (FAILED(pPlayer->Init()))
	{//���������������s�����ꍇ
		return NULL;
	}

	return pPlayer;
}

//====================================================================
//����������
//====================================================================
HRESULT CSide_Block3D::Init(void)
{
	CTexture *pTexture = CManager::GetInstance()->GetTexture();;
	m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\5.png");

	SetType(CObject::TYPE_SIDEBLOCK3D);

	CObjectXtex::Init();

	return S_OK;
}

//====================================================================
//�I������
//====================================================================
void CSide_Block3D::Uninit(void)
{
	CObjectXtex::Uninit();
}

//====================================================================
//�X�V����
//====================================================================
void CSide_Block3D::Update(void)
{
	//���_���̍X�V
	CObjectXtex::Update();
}

//====================================================================
//�`�揈��
//====================================================================
void CSide_Block3D::Draw(void)
{
	SetMatColor(m_BlockColor);

	CObjectXtex::Draw();
}

//====================================================================
//�u���b�N�̐F�ύX����
//====================================================================
void CSide_Block3D::ChangeColor(int Level)
{
	switch (Level % 3)
	{
	case 0:
		m_BlockColor = D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f);
		break;

	case 1:
		m_BlockColor = D3DXCOLOR(0.9f, 0.3f, 0.0f, 1.0f);
		break;

	case 2:
		m_BlockColor = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
		break;

	default:
		m_BlockColor = D3DXCOLOR(0.9f, 0.3f, 0.0f, 1.0f);
		break;
	}
}
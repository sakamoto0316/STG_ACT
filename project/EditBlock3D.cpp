//============================================
//
//	�G�f�B�b�g�p�u���b�N�̏��� [EditBlock3D.cpp]
//	Author:sakamoto kai
//
//============================================
#include "EditBlock3D.h"
#include "renderer.h"
#include "manager.h"
#include "texture.h"
#include "DebugNumber3D.h"
#include "XModel.h"
#include "score.h"

//�}�N����`
#define BLOCK_WIGHT (40.0f)		//����
#define BLOCK_HEIGHT (40.0f)	//�c��
#define BLOCK_WAVE (90)	//�U������

bool CEdit_Block3D::m_bUse[100][SET_BLOCK_WIGHT + 2][SET_BLOCK_HEIGHT] = {};
LPD3DXMESH CEdit_Block3D::m_pMesh = NULL;				//���b�V��(���_���)�ւ̃|�C���^
LPD3DXBUFFER CEdit_Block3D::m_pBuffMat = NULL;			//�}�e���A���ւ̃|�C���^
DWORD CEdit_Block3D::m_dwNumMat = NULL;					//�}�e���A���̐�
int CEdit_Block3D::m_nIdxXModel = NULL;					//�}�e���A���̐�
//====================================================================
//�R���X�g���N�^
//====================================================================
CEdit_Block3D::CEdit_Block3D(int nPriority) : CObjectXtex(nPriority)
{
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//�ړ���
	m_nIdxTexture = 0;					//�e�N�X�`���̔ԍ�
	m_CreateNumber = 0;					//�����̔ԍ�
	m_WightNumber = 0;					//���̔ԍ�
	m_HeightNumber = 0;					//�c�̔ԍ�
	SetWight(BLOCK_WIGHT);				//�c�̔ԍ�
	SetHeight(BLOCK_HEIGHT);			//�c�̔ԍ�
	m_nWaveCount = 0;
	m_bBreak = false;
	m_bWave = false;
	m_nBreakCount = 0;
	m_nWavePower = 0.0f;
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CEdit_Block3D::~CEdit_Block3D()
{

}

//====================================================================
//��������
//====================================================================
CEdit_Block3D *CEdit_Block3D::Create()
{
	CEdit_Block3D *pBlock = NULL;

	if (pBlock == NULL)
	{
		//�I�u�W�F�N�g2D�̐���
		pBlock = new CEdit_Block3D();
	}

	//X�t�@�C���̊��蓖��
	CXModel *pXModel = CManager::GetInstance()->GetXModel();
	m_nIdxXModel = pXModel->Regist("data\\MODEL\\block00.x");
	pXModel->GetXModelInfo(&m_pBuffMat, &m_dwNumMat, &m_pMesh, m_nIdxXModel);
	pBlock->BindFile(m_pMesh, m_pBuffMat, m_dwNumMat);

	//�I�u�W�F�N�g�̏���������
	if (FAILED(pBlock->Init()))
	{//���������������s�����ꍇ
		return NULL;
	}

	return pBlock;
}

//====================================================================
//����������
//====================================================================
HRESULT CEdit_Block3D::Init(void)
{
	CTexture *pTexture = CManager::GetInstance()->GetTexture();;
	m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\block001.png");

	SetType(CObject::TYPE_EDITBLOCK3D);

	CObjectXtex::Init();

	return S_OK;
}

//====================================================================
//�I������
//====================================================================
void CEdit_Block3D::Uninit(void)
{
	m_bUse[m_CreateNumber][m_WightNumber][m_HeightNumber] = false;

	CObjectXtex::Uninit();
}

//====================================================================
//�X�V����
//====================================================================
void CEdit_Block3D::Update(void)
{
	SetPos(D3DXVECTOR3(-400.0f + 40.0f * m_WightNumber,400.0f - 40.0f * m_HeightNumber, -5.0f));

	//���_���̍X�V
	CObjectXtex::Update();
}

//====================================================================
//�`�揈��
//====================================================================
void CEdit_Block3D::Draw(void)
{
	SetMatColor(D3DXCOLOR(0.5f, 0.5f, 0.5f, 0.5f));

	CObjectXtex::Draw();
}

//====================================================================
//�u���b�N�̎g�p�ԍ��ݒ�
//====================================================================
void CEdit_Block3D::bUseSet(void)
{
	for (int nCntCreate = 0; nCntCreate < 100; nCntCreate++)
	{
		for (int nCntObjHeight = 0; nCntObjHeight < SET_BLOCK_HEIGHT; nCntObjHeight++)
		{
			for (int nCntObjWight = 0; nCntObjWight < 2; nCntObjWight++)
			{
				m_bUse[nCntCreate][nCntObjWight * (SET_BLOCK_WIGHT + 1)][nCntObjHeight] = true;
			}
		}
	}
}
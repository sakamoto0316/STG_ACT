//============================================
//
//	�^�C�g����UI�̏��� [TitleUI.cpp]
//	Author:sakamoto kai
//
//============================================
#include "TitleUI.h"
#include "input.h"
#include "renderer.h"
#include "manager.h"
#include "texture.h"
#include "XModel.h"
#include "debugproc.h"
#include "title.h"

//�}�N����`
#define NUMBER_WIGHT (200.0f)		//����
#define NUMBER_HEIGHT (50.0f)		//�c��

LPD3DXMESH CTitleUI::m_pMesh = NULL;				//���b�V��(���_���)�ւ̃|�C���^
LPD3DXBUFFER CTitleUI::m_pBuffMat = NULL;			//�}�e���A���ւ̃|�C���^
DWORD CTitleUI::m_dwNumMat = NULL;					//�}�e���A���̐�
int CTitleUI::m_nIdxXModel = NULL;					//�}�e���A���̐�

//====================================================================
//�R���X�g���N�^
//====================================================================
CTitleUI::CTitleUI(int nPriority) : CObjectXtex(nPriority)
{
	SetPos(D3DXVECTOR3(640.0f, 360.0f, 0.0f));
	SetWight(NUMBER_WIGHT);
	SetHeight(NUMBER_HEIGHT);
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CTitleUI::~CTitleUI()
{

}

//====================================================================
//��������
//====================================================================
CTitleUI *CTitleUI::Create()
{
	CTitleUI *pNumber = NULL;

	if (pNumber == NULL)
	{
		//�I�u�W�F�N�g2D�̐���
		pNumber = new CTitleUI();
	}

	//X�t�@�C���̊��蓖��
	CXModel *pXModel = CManager::GetInstance()->GetXModel();
	m_nIdxXModel = pXModel->Regist("data\\MODEL\\SquareFall.x");
	pXModel->GetXModelInfo(&m_pBuffMat, &m_dwNumMat, &m_pMesh, m_nIdxXModel);
	pNumber->BindFile(m_pMesh, m_pBuffMat, m_dwNumMat);

	//�I�u�W�F�N�g�̏���������
	if (FAILED(pNumber->Init()))
	{//���������������s�����ꍇ
		return NULL;
	}

	return pNumber;
}

//====================================================================
//����������
//====================================================================
HRESULT CTitleUI::Init(void)
{
	CTexture *pTexture = CManager::GetInstance()->GetTexture();;
	m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\SquareFall.png");

	SetType(CObject::TYPE_BG);

	CObjectXtex::Init();

	return S_OK;
}

//====================================================================
//�I������
//====================================================================
void CTitleUI::Uninit(void)
{
	CObjectXtex::Uninit();
}

//====================================================================
//�X�V����
//====================================================================
void CTitleUI::Update(void)
{
	CObjectXtex::Update();
}

//====================================================================
//�`�揈��
//====================================================================
void CTitleUI::Draw(void)
{
	CObjectXtex::Draw();
}
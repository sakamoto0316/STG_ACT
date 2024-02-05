//============================================
//
//	���x���A�b�v����UI�̏��� [LevelUPUI.cpp]
//	Author:sakamoto kai
//
//============================================
#include "LevelUPUI.h"
#include "input.h"
#include "renderer.h"
#include "manager.h"
#include "texture.h"

//�}�N����`
#define NUMBER_WIGHT (100.0f)		//����
#define NUMBER_HEIGHT (100.0f)		//�c��

//====================================================================
//�R���X�g���N�^
//====================================================================
CLevelUPUI::CLevelUPUI(int nPriority) : CObject2D(nPriority)
{
	SetWight(NUMBER_WIGHT);
	SetHeight(NUMBER_HEIGHT);
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CLevelUPUI::~CLevelUPUI()
{

}

//====================================================================
//��������
//====================================================================
CLevelUPUI *CLevelUPUI::Create(void)
{
	CLevelUPUI *pNumber = NULL;

	if (pNumber == NULL)
	{
		//�I�u�W�F�N�g2D�̐���
		pNumber = new CLevelUPUI();
	}

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
HRESULT CLevelUPUI::Init(void)
{
	CTexture *pTexture = CManager::GetInstance()->GetTexture();;
	m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\Test.jpg");

	CObject2D::Init();

	SetType(CObject::TYPE_LEVELUI);

	return S_OK;
}

//====================================================================
//�I������
//====================================================================
void CLevelUPUI::Uninit(void)
{
	CObject2D::Uninit();
}

//====================================================================
//�X�V����
//====================================================================
void CLevelUPUI::Update(void)
{
	//���_���̍X�V
	CObject2D::Update();
}

//====================================================================
//�`�揈��
//====================================================================
void CLevelUPUI::Draw(void)
{
	CObject2D::Draw();
}
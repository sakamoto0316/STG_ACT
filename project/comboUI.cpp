//============================================
//
//	�R���{UI�̏��� [comboUI.cpp]
//	Author:sakamoto kai
//
//============================================
#include "comboUI.h"
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
CComboUI::CComboUI(int nPriority) : CObjectBillboard(nPriority)
{
	SetWight(NUMBER_WIGHT);
	SetHeight(NUMBER_HEIGHT);
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CComboUI::~CComboUI()
{

}

//====================================================================
//��������
//====================================================================
CComboUI *CComboUI::Create(void)
{
	CComboUI *pNumber = NULL;

	if (pNumber == NULL)
	{
		//�I�u�W�F�N�g2D�̐���
		pNumber = new CComboUI();
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
HRESULT CComboUI::Init(void)
{
	CTexture *pTexture = CManager::GetInstance()->GetTexture();;
	m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\COMBO_UI.png");

	SetType(CObject::TYPE_LEVELUI);

	CObjectBillboard::Init();

	return S_OK;
}

//====================================================================
//�I������
//====================================================================
void CComboUI::Uninit(void)
{
	CObjectBillboard::Uninit();
}

//====================================================================
//�X�V����
//====================================================================
void CComboUI::Update(void)
{
	//���_���̍X�V
	CObjectBillboard::Update();
}

//====================================================================
//�`�揈��
//====================================================================
void CComboUI::Draw(void)
{
	CObjectBillboard::Draw();
}
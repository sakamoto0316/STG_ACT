//============================================
//
//	�e�̎�ނ�UI�̏��� [BulletTypeUI.cpp]
//	Author:sakamoto kai
//
//============================================
#include "BulletTypeUI.h"
#include "input.h"
#include "renderer.h"
#include "manager.h"
#include "texture.h"

//�}�N����`
#define NUMBER_WIGHT (80.0f)		//����
#define NUMBER_HEIGHT (80.0f)		//�c��

//====================================================================
//�R���X�g���N�^
//====================================================================
CBulletTypeUI::CBulletTypeUI(int nPriority) : CObject2D(nPriority)
{
	SetWight(NUMBER_WIGHT);
	SetHeight(NUMBER_HEIGHT);
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CBulletTypeUI::~CBulletTypeUI()
{

}

//====================================================================
//��������
//====================================================================
CBulletTypeUI *CBulletTypeUI::Create(void)
{
	CBulletTypeUI *pNumber = NULL;

	if (pNumber == NULL)
	{
		//�I�u�W�F�N�g2D�̐���
		pNumber = new CBulletTypeUI();
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
HRESULT CBulletTypeUI::Init(void)
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
void CBulletTypeUI::Uninit(void)
{
	CObject2D::Uninit();
}

//====================================================================
//�X�V����
//====================================================================
void CBulletTypeUI::Update(void)
{
	//���_���̍X�V
	CObject2D::Update();
}

//====================================================================
//�`�揈��
//====================================================================
void CBulletTypeUI::Draw(void)
{
	CObject2D::Draw();
}
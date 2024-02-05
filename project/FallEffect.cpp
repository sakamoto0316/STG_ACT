//============================================
//
//	�ō����x�������̉��o�|���S���̏��� [FallEffect.cpp]
//	Author:sakamoto kai
//
//============================================
#include "FallEffect.h"
#include "input.h"
#include "renderer.h"
#include "manager.h"
#include "texture.h"

//�}�N����`
#define NUMBER_WIGHT (2.0f)		//����
#define NUMBER_HEIGHT (20.0f)	//�c��

//====================================================================
//�R���X�g���N�^
//====================================================================
CFallEffect::CFallEffect(int nPriority) : CObjectBillboard(nPriority)
{
	SetWight(NUMBER_WIGHT);
	SetHeight(NUMBER_HEIGHT);

	m_MoveUP = (float)((rand() % 5) + 16);
	m_nLife = 0;
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CFallEffect::~CFallEffect()
{

}

//====================================================================
//��������
//====================================================================
CFallEffect *CFallEffect::Create(void)
{
	CFallEffect *pNumber = NULL;

	if (pNumber == NULL)
	{
		//�I�u�W�F�N�g2D�̐���
		pNumber = new CFallEffect();
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
HRESULT CFallEffect::Init(void)
{
	CTexture *pTexture = CManager::GetInstance()->GetTexture();;
	m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\Test.jpg");

	SetType(CObject::TYPE_FALLEFFECT);

	CObjectBillboard::Init();

	return S_OK;
}

//====================================================================
//�I������
//====================================================================
void CFallEffect::Uninit(void)
{
	CObjectBillboard::Uninit();
}

//====================================================================
//�X�V����
//====================================================================
void CFallEffect::Update(void)
{
	D3DXVECTOR3 Pos = GetPos();

	Pos.y += m_MoveUP;

	SetPos(Pos);

	//���_���̍X�V
	CObjectBillboard::Update();

	if (m_nLife > 0)
	{
		m_nLife--;
	}
	else
	{
		Uninit();
	}
}

//====================================================================
//�`�揈��
//====================================================================
void CFallEffect::Draw(void)
{
	CObjectBillboard::Draw();
}
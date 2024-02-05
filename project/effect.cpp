//============================================
//
//	�G�t�F�N�g���� [effect.cpp]
//	Author:sakamoto kai
//
//============================================
#include "effect.h"
#include "renderer.h"
#include "manager.h"
#include "texture.h"

//�}�N����`
#define SMALLER (2.0f)

//�ÓI�����o�ϐ��錾
LPDIRECT3DTEXTURE9 CEffect::m_pTexture = NULL;

//====================================================================
//�R���X�g���N�^
//====================================================================
CEffect::CEffect(int nPriority) : CObjectBillboard(nPriority)
{
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	m_fRadius = 0.0f;
	m_nLife = 0;
	m_fDel = SMALLER;
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CEffect::~CEffect()
{

}

//====================================================================
//��������
//====================================================================
CEffect *CEffect::Create()
{
	CEffect *pPlayer = NULL;

	if (pPlayer == NULL)
	{
		//�I�u�W�F�N�g2D�̐���
		pPlayer = new CEffect();
	}

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
HRESULT CEffect::Init(void)
{
	CTexture *pTexture = CManager::GetInstance()->GetTexture();;
	m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\Effect000.jpg");

	SetType(CObject::TYPE_EFFECT);

	CObjectBillboard::Init();

	//���_�J���[�̐ݒ�
	SetColor(m_col);

	return S_OK;
}

//====================================================================
//�I������
//====================================================================
void CEffect::Uninit(void)
{
	CObjectBillboard::Uninit();
}

//====================================================================
//�X�V����
//====================================================================
void CEffect::Update(void)
{
	//�T�C�Y�̒���
	m_fRadius -= m_fDel;
	SetWight(m_fRadius);
	SetHeight(m_fRadius);

	m_nLife--;

	//�ʒu�X�V
	SetPos(GetPos() += m_move);

	if (m_nLife <= 0 || m_fRadius <= 0.0f)
	{
		Uninit();
		return;
	}

	//���_���̍X�V
	CObjectBillboard::Update();
}

//====================================================================
//�`�揈��
//====================================================================
void CEffect::Draw(void)
{
	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	//a�u�����f�B���O�����Z�����ɐݒ�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	CObjectBillboard::Draw();

	//a�u�����f�B���O��ʏ�ɐݒ�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
}
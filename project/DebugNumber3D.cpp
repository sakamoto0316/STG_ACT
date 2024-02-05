//============================================
//
//	�f�o�b�O�p�����̏��� [DebugNumber.cpp]
//	Author:sakamoto kai
//
//============================================
#include "DebugNumber3D.h"
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
CDebugNumber3D::CDebugNumber3D(int nPriority) : CObjectBillboard(nPriority)
{
	SetWight(NUMBER_WIGHT);
	SetHeight(NUMBER_HEIGHT);
	m_nNumber = 0;
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CDebugNumber3D::~CDebugNumber3D()
{

}

//====================================================================
//��������
//====================================================================
CDebugNumber3D *CDebugNumber3D::Create(void)
{
	CDebugNumber3D *pExplosion = NULL;

	if (pExplosion == NULL)
	{
		//�I�u�W�F�N�g2D�̐���
		pExplosion = new CDebugNumber3D();
	}

	//�I�u�W�F�N�g�̏���������
	if (FAILED(pExplosion->Init()))
	{//���������������s�����ꍇ
		return NULL;
	}

	return pExplosion;
}

//====================================================================
//����������
//====================================================================
HRESULT CDebugNumber3D::Init(void)
{
	CTexture *pTexture = CManager::GetInstance()->GetTexture();;
	m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\Number00.png");

	SetType(CObject::TYPE_NUMBER);

	CObjectBillboard::Init();

	SetAnim(D3DXVECTOR2(0.2f, 0.2f));

	return S_OK;
}

//====================================================================
//�I������
//====================================================================
void CDebugNumber3D::Uninit(void)
{
	CObjectBillboard::Uninit();
}

//====================================================================
//�X�V����
//====================================================================
void CDebugNumber3D::Update(void)
{
	VERTEX_3D*pVtx;	//���_�|�C���^������

	//���_�o�b�t�@�����b�N���A���X���ւ̃|�C���^������
	GetVtxBuff()->Lock(0, 0, (void**)&pVtx, 0);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f + (m_nNumber * 0.1f), 0.0f);
	pVtx[1].tex = D3DXVECTOR2(0.1f + (m_nNumber * 0.1f), 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f + (m_nNumber * 0.1f), 1.0f);
	pVtx[3].tex = D3DXVECTOR2(0.1f + (m_nNumber * 0.1f), 1.0f);

	//���_�o�b�t�@���A�����b�N����
	GetVtxBuff()->Unlock();

	//���_���̍X�V
	CObjectBillboard::Update();
}

//====================================================================
//�`�揈��
//====================================================================
void CDebugNumber3D::Draw(void)
{
	CObjectBillboard::Draw();
}
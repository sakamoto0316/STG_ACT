//============================================
//
//	���C�t�Q�[�W�̃r���{�[�h [LifeGaugeBillboard.cpp]
//	Author:sakamoto kai
//
//============================================
#include "LifeGaugeBillboard.h"
#include "input.h"
#include "renderer.h"
#include "manager.h"
#include "texture.h"

//�}�N����`
#define GAUGE_POS (D3DXVECTOR3(5.0f, 5.0f, 0.0f))		//�Q�[�W�̈ʒu
#define GAUGE_WIGHT (80.0f)	//�Q�[�W�̉���
#define GAUGE_HEIGHT (10.0f)	//�Q�[�W�̏c��
#define GAUGE_TILT (5.0f)		//�Q�[�W�̌X��

//====================================================================
//�R���X�g���N�^
//====================================================================
CLifeGaugeBillboard::CLifeGaugeBillboard(int nPriority) : CGaugeBillboard(nPriority)
{
	m_nIdxTexture = -1;
	//m_nLifeMax = 0;
	//m_nLife = 0;

	SetPos(GAUGE_POS);
	SetWight(GAUGE_WIGHT);
	SetHeight(GAUGE_HEIGHT);
	SetTilt(GAUGE_TILT);
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CLifeGaugeBillboard::~CLifeGaugeBillboard()
{

}

//====================================================================
//��������
//====================================================================
CLifeGaugeBillboard *CLifeGaugeBillboard::Create(void)
{
	CLifeGaugeBillboard *pGauge = NULL;

	if (pGauge == NULL)
	{
		//�I�u�W�F�N�g2D�̐���
		pGauge = new CLifeGaugeBillboard();
	}

	//�I�u�W�F�N�g�̏���������
	if (FAILED(pGauge->Init()))
	{//���������������s�����ꍇ
		return NULL;
	}

	return pGauge;
}

//====================================================================
//����������
//====================================================================
HRESULT CLifeGaugeBillboard::Init(void)
{
	CTexture *pTexture = CManager::GetInstance()->GetTexture();;
	m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\Test.jpg");

	CGaugeBillboard::Init();

	return S_OK;
}

//====================================================================
//�I������
//====================================================================
void CLifeGaugeBillboard::Uninit(void)
{
	CGaugeBillboard::Uninit();
}

//====================================================================
//�X�V����
//====================================================================
void CLifeGaugeBillboard::Update(void)
{
	//���_���̍X�V
	CGaugeBillboard::Update();
}

//====================================================================
//�`�揈��
//====================================================================
void CLifeGaugeBillboard::Draw(void)
{
	CGaugeBillboard::Draw();
}
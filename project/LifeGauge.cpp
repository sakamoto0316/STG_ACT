//============================================
//
//	���C�t�Q�[�W [LifeGauge.cpp]
//	Author:sakamoto kai
//
//============================================
#include "LifeGauge.h"
#include "input.h"
#include "renderer.h"
#include "manager.h"
#include "texture.h"

//�}�N����`
#define GAUGE_POS (D3DXVECTOR3(5.0f, 5.0f, 0.0f))		//�Q�[�W�̈ʒu
#define GAUGE_WIGHT (200.0f)	//�Q�[�W�̉���
#define GAUGE_HEIGHT (50.0f)	//�Q�[�W�̏c��
#define GAUGE_TILT (10.0f)		//�Q�[�W�̌X��

//====================================================================
//�R���X�g���N�^
//====================================================================
CLifeGauge::CLifeGauge(bool Vertical, bool NumberUI, int nPriority) : CGauge(nPriority)
{
	m_nIdxTexture = -1;
	//m_nLifeMax = 0;
	//m_nLife = 0;

	SetPos(GAUGE_POS);
	SetWight(GAUGE_WIGHT);
	SetHeight(GAUGE_HEIGHT);
	SetTilt(GAUGE_TILT);
	SetVertical(Vertical);
	SetNumberUI(NumberUI);
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CLifeGauge::~CLifeGauge()
{

}

//====================================================================
//��������
//====================================================================
CLifeGauge *CLifeGauge::Create(bool Vertical, bool NumberUI)
{
	CLifeGauge *pGauge = NULL;

	if (pGauge == NULL)
	{
		//�I�u�W�F�N�g2D�̐���
		pGauge = new CLifeGauge(Vertical, NumberUI);
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
HRESULT CLifeGauge::Init(void)
{
	CTexture *pTexture = CManager::GetInstance()->GetTexture();;
	m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\Test.jpg");

	CGauge::Init();

	SetAnim(D3DXVECTOR2(0.2f, 0.2f));

	return S_OK;
}

//====================================================================
//�I������
//====================================================================
void CLifeGauge::Uninit(void)
{
	CGauge::Uninit();
}

//====================================================================
//�X�V����
//====================================================================
void CLifeGauge::Update(void)
{
	//���_���̍X�V
	CGauge::Update();
}

//====================================================================
//�`�揈��
//====================================================================
void CLifeGauge::Draw(void)
{
	CGauge::Draw();
}
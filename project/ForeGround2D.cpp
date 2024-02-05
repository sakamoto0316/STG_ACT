//============================================
//
//	�O�i�̏��� [ForeGround2D.cpp]
//	Author:sakamoto kai
//
//============================================
#include "ForeGround2D.h"
#include "input.h"
#include "renderer.h"
#include "manager.h"
#include "texture.h"

//�}�N����`
#define NUMBER_WIGHT (1280.0f)		//����
#define NUMBER_HEIGHT (720.0f)		//�c��

//====================================================================
//�R���X�g���N�^
//====================================================================
CFG::CFG(int Cnt, int nType, int nPriority) : CObject2D(nPriority)
{
	SetPos(D3DXVECTOR3(640.0f, 360.0f, 0.0f));
	SetWight(NUMBER_WIGHT);
	SetHeight(NUMBER_HEIGHT);
	m_nLife = Cnt;
	m_nType = nType;
	m_bColorSet = false;
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CFG::~CFG()
{

}

//====================================================================
//��������
//====================================================================
CFG *CFG::Create(int nCnt, int nType)
{
	CFG *pNumber = NULL;

	if (pNumber == NULL)
	{
		//�I�u�W�F�N�g2D�̐���
		pNumber = new CFG(nCnt, nType);
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
HRESULT CFG::Init(void)
{
	CTexture *pTexture = CManager::GetInstance()->GetTexture();;
	m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\Test.jpg");

	CObject2D::Init();

	SetType(CObject::TYPE_FG);

	return S_OK;
}

//====================================================================
//�I������
//====================================================================
void CFG::Uninit(void)
{
	CObject2D::Uninit();
}

//====================================================================
//�X�V����
//====================================================================
void CFG::Update(void)
{
	if (m_ColorCount > 0)
	{
		m_ColorCount--;
	}
	else
	{
		m_bColorSet = m_bColorSet ? false : true;
		m_ColorCount = 5;
	}

	switch (m_nType)
	{
	case 1:
		if (m_bColorSet == true)
		{
			SetColor(D3DXCOLOR(1.0f, 0.0f, 0.0f, 0.3f));
		}
		else
		{
			SetColor(D3DXCOLOR(0.8f, 0.8f, 0.8f, 0.3f));
		}
		break;
	default:
		break;
	}

	CObject2D::Update();

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
void CFG::Draw(void)
{
	CObject2D::Draw();
}
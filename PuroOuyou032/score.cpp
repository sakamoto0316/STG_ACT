//============================================
//
//	�X�R�A�̏��� [score.cpp]
//	Author:sakamoto kai
//
//============================================
#include "score.h"
#include "number.h"

//�}�N����`
#define SPACE_SCORE (50.0f)		//�X�R�A���m�̌���
#define NUMBER_WIGHT (100.0f)	//�����̉���
#define NUMBER_HEIGHT (100.0f)	//�����̏c��

//�ÓI�����o�ϐ��錾

//====================================================================
//�R���X�g���N�^
//====================================================================
CScore::CScore()
{
	for (int nCnt = 0; nCnt < NUM_SCORE; nCnt++)
	{
		m_apObject[nCnt] = NULL;
		m_nNumber[nCnt] = 0;
	}

	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_nScore = 0;
	m_nWight = NUMBER_WIGHT;
	m_Height = NUMBER_HEIGHT;
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CScore::~CScore()
{

}

//====================================================================
//��������
//====================================================================
CScore *CScore::Create()
{
	CScore *pMultiBG = NULL;

	if (pMultiBG == NULL)
	{
		//�I�u�W�F�N�g2D�̐���
		pMultiBG = new CScore();
	}

	//�I�u�W�F�N�g�̏���������
	if (FAILED(pMultiBG->Init()))
	{//���������������s�����ꍇ
		return NULL;
	}

	return pMultiBG;
}

//====================================================================
//�X�R�A�̏�����
//====================================================================
HRESULT CScore::Init(void)
{
	SetType(CObject::TYPE_SCORE);

	for (int nCntObject = 0; nCntObject < NUM_SCORE; nCntObject++)
	{
		if (m_apObject[nCntObject] == NULL)
		{
			//�����̐���
			m_apObject[nCntObject] = CNumber::Create();
			m_apObject[nCntObject]->SetPos(D3DXVECTOR3(m_pos.x + (nCntObject * m_nWight * 0.6f), m_pos.y, m_pos.z));
			m_apObject[nCntObject]->SetWight(m_nWight);
			m_apObject[nCntObject]->SetHeight(m_Height);
			m_apObject[nCntObject]->SetNumber(0);
		}
	}
	return S_OK;
}

//====================================================================
//�X�R�A�̏I��
//====================================================================
void CScore::Uninit(void)
{
	SetDeathFlag(true);
}

//====================================================================
//�I������
//====================================================================
void CScore::SetNULL(void)
{
	for (int nCntObject = 0; nCntObject < NUM_SCORE; nCntObject++)
	{
		if (m_apObject[nCntObject] != NULL)
		{
			//�����̐���
			m_apObject[nCntObject] = NULL;
		}
	}
}

//====================================================================
//�X�R�A�̍X�V
//====================================================================
void CScore::Update(void)
{
	for (int nCntObject = 0; nCntObject < NUM_SCORE; nCntObject++)
	{
		if (m_apObject[nCntObject] != NULL)
		{
			m_apObject[nCntObject]->SetPos(D3DXVECTOR3(m_pos.x + (nCntObject * m_nWight * 0.6f), m_pos.y, m_pos.z));
			m_apObject[nCntObject]->SetWight(m_nWight);
			m_apObject[nCntObject]->SetHeight(m_Height);
		}
	}
}

//====================================================================
//�X�R�A�̕`��
//====================================================================
void CScore::Draw(void)
{

}

//====================================================================
//�X�R�A�̐ݒ菈��
//====================================================================
void CScore::SetScore(int Score)
{
	m_nScore = Score;

	m_nNumber[0] = m_nScore % 100000000 / 10000000;
	m_nNumber[1] = m_nScore % 10000000 / 1000000;
	m_nNumber[2] = m_nScore % 1000000 / 100000;
	m_nNumber[3] = m_nScore % 100000 / 10000;
	m_nNumber[4] = m_nScore % 10000 / 1000;
	m_nNumber[5] = m_nScore % 1000 / 100;
	m_nNumber[6] = m_nScore % 100 / 10;
	m_nNumber[7] = m_nScore % 10 / 1;

	for (int nCntObject = 0; nCntObject < NUM_SCORE; nCntObject++)
	{
		m_apObject[nCntObject]->SetNumber(m_nNumber[nCntObject]);
	}
}

//====================================================================
//�X�R�A�̐ݒ菈��
//====================================================================
void CScore::AddScore(int Add)
{
	m_nScore += Add;

	m_nNumber[0] = m_nScore % 100000000 / 10000000;
	m_nNumber[1] = m_nScore % 10000000 / 1000000;
	m_nNumber[2] = m_nScore % 1000000 / 100000;
	m_nNumber[3] = m_nScore % 100000 / 10000;
	m_nNumber[4] = m_nScore % 10000 / 1000;
	m_nNumber[5] = m_nScore % 1000 / 100;
	m_nNumber[6] = m_nScore % 100 / 10;
	m_nNumber[7] = m_nScore % 10 / 1;

	for (int nCntObject = 0; nCntObject < NUM_SCORE; nCntObject++)
	{
		m_apObject[nCntObject]->SetNumber(m_nNumber[nCntObject]);
	}
}
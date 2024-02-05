//============================================
//
//	�����L���O�̏��� [ranking.cpp]
//	Author:sakamoto kai
//
//============================================
#include "manager.h"
#include "ranking.h"
#include "number.h"

//�}�N����`
#define SPACE_TIME (50.0f)		//�^�C�����m�̌���
#define TIME_POS (D3DXVECTOR3(1000.0f, 200.0f, 0.0f))		//�^�C���̈ʒu

//�ÓI�����o�ϐ��錾
CNumber *CRanking::m_apObject[NUM_TIME][MAX_RANK] = {};
D3DXVECTOR3 CRanking::m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
int CRanking::m_nTime[MAX_RANK] = { 80000,40000,20000,10000,5000 };
int CRanking::m_nCount = 0;
int CRanking::m_StartTime = 0;
int CRanking::m_nNumber[NUM_TIME][MAX_RANK] = { 0 };
bool CRanking::m_StopTime = false;
bool CRanking::m_SetRanking = false;

//====================================================================
//�R���X�g���N�^
//====================================================================
CRanking::CRanking()
{

}

//====================================================================
//�f�X�g���N�^
//====================================================================
CRanking::~CRanking()
{

}

//====================================================================
//��������
//====================================================================
CRanking *CRanking::Create()
{
	CRanking *pMultiBG = NULL;

	if (pMultiBG == NULL)
	{
		//�I�u�W�F�N�g2D�̐���
		pMultiBG = new CRanking();
	}

	//�I�u�W�F�N�g�̏���������
	if (FAILED(pMultiBG->Init()))
	{//���������������s�����ꍇ
		return NULL;
	}

	return pMultiBG;
}

//====================================================================
//�����L���O�̏�����
//====================================================================
HRESULT CRanking::Init(void)
{
	SetType(CObject::TYPE_TIME);

	SetPos(TIME_POS);

	for (int nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
	{
		for (int nCntObject = 0; nCntObject < NUM_TIME; nCntObject++)
		{
			if (m_apObject[nCntObject][nCntRank] == NULL)
			{
				//�����̐���
				m_apObject[nCntObject][nCntRank] = CNumber::Create();
				m_apObject[nCntObject][nCntRank]->SetNumber(0);
				m_apObject[nCntObject][nCntRank]->SetPos(D3DXVECTOR3(m_pos.x + (nCntObject * 60.0f), m_pos.y + (nCntRank * 100.0f), m_pos.z));
				m_apObject[nCntObject][nCntRank]->SetWight(100.0f);
				m_apObject[nCntObject][nCntRank]->SetHeight(100.0f);
			}
		}
	}

	LoadRanking();

	return S_OK;
}

//====================================================================
//�^�C���̏I��
//====================================================================
void CRanking::Uninit(void)
{

}

//====================================================================
//�^�C���̏I��
//====================================================================
void CRanking::SetNULL(void)
{
	for (int nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
	{
		for (int nCntObject = 0; nCntObject < NUM_TIME; nCntObject++)
		{
			if (m_apObject[nCntObject][nCntRank] != NULL)
			{
				m_apObject[nCntObject][nCntRank]->Uninit();
				m_apObject[nCntObject][nCntRank] = NULL;
			}
		}
	}
}


//====================================================================
//�^�C���̍X�V
//====================================================================
void CRanking::Update(void)
{
	for (int nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
	{
		for (int nCntObject = 0; nCntObject < NUM_TIME; nCntObject++)
		{
			if (m_apObject[nCntObject] != NULL)
			{
				m_apObject[nCntObject][nCntRank]->SetPos(D3DXVECTOR3(m_pos.x + (nCntObject * 60.0f), m_pos.y + (nCntRank * 85.0f), m_pos.z));
			}
		}
	}

	for (int nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
	{
		m_nNumber[0][nCntRank] = m_nTime[nCntRank] % 100000000 / 10000000;
		m_nNumber[1][nCntRank] = m_nTime[nCntRank] % 10000000 / 1000000;
		m_nNumber[2][nCntRank] = m_nTime[nCntRank] % 1000000 / 100000;
		m_nNumber[3][nCntRank] = m_nTime[nCntRank] % 100000 / 10000;
		m_nNumber[4][nCntRank] = m_nTime[nCntRank] % 10000 / 1000;
		m_nNumber[5][nCntRank] = m_nTime[nCntRank] % 1000 / 100;
		m_nNumber[6][nCntRank] = m_nTime[nCntRank] % 100 / 10;
		m_nNumber[7][nCntRank] = m_nTime[nCntRank] % 10 / 1;

		for (int nCntObject = 0; nCntObject < NUM_TIME; nCntObject++)
		{
			m_apObject[nCntObject][nCntRank]->SetNumber(m_nNumber[nCntObject][nCntRank]);
			//m_apObject[nCntObject][nCntRank]->SetNumber(nCntObject * 2 + nCntRank * 2);
		}
	}
}

//====================================================================
//�^�C���̕`��
//====================================================================
void CRanking::Draw(void)
{

}

//====================================================================
//�^�C���̕`��
//====================================================================
void CRanking::FloatSetTime(int Time)
{
	if (m_StopTime == false)
	{
		m_nTime[0] = Time - m_StartTime;
	}
}

//====================================================================
//�����L���O�̐ݒ菈��
//====================================================================
void CRanking::SetRanking(int nRanKing)
{
	int nCount1;
	int nCount2;
	int nData;

	if (nRanKing > m_nTime[MAX_RANK - 1])
	{
		m_nTime[MAX_RANK - 1] = nRanKing;

		for (nCount1 = 0; nCount1 < MAX_RANK; nCount1++)
		{
			for (nCount2 = nCount1; nCount2 < MAX_RANK; nCount2++)
			{
				if (m_nTime[nCount1] < m_nTime[nCount2])
				{
					nData = m_nTime[nCount1];
					m_nTime[nCount1] = m_nTime[nCount2];
					m_nTime[nCount2] = nData;
				}
			}
		}
	}
}

//====================================================================
//�ۑ�����
//====================================================================
void CRanking::SaveRanking(void)
{
	FILE *pFile; //�t�@�C���|�C���^��錾

	//�t�@�C�����J��
	pFile = fopen("data\\TXT\\Ranking", "w");

	if (pFile != NULL)
	{//�t�@�C�����J�����ꍇ

		for (int nCnt = 0; nCnt < MAX_RANK; nCnt++)
		{
			fprintf(pFile, "%d\n", m_nTime[nCnt]);
		}

		fclose(pFile);
	}
	else
	{//�t�@�C�����J���Ȃ������ꍇ
		printf("***�t�@�C�����J���܂���ł���***\n");
	}
}

//====================================================================
//�}�b�v��S�Ė��߂Đ���
//====================================================================
void CRanking::LoadRanking(void)
{
	FILE *pFile; //�t�@�C���|�C���^��錾

	//�t�@�C�����J��
	pFile = fopen("data\\TXT\\Ranking", "r");

	if (pFile != NULL)
	{//�t�@�C�����J�����ꍇ

		for (int nCnt = 0; nCnt < MAX_RANK; nCnt++)
		{
			fscanf(pFile, "%d", &m_nTime[nCnt]);
		}
		fclose(pFile);
	}
	else
	{//�t�@�C�����J���Ȃ������ꍇ
		printf("***�t�@�C�����J���܂���ł���***\n");
	}
}
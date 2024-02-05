//============================================
//
//	�G�f�B�b�g [Edit.cpp]
//	Author:sakamoto kai
//
//============================================
#include "Edit.h"
#include "object.h"
#include "EditBlock3D.h"
#include "renderer.h"
#include "break_block3D.h"
#include "manager.h"
#include "game.h"
#include "input.h"
#include "debugproc.h"
#include "Map2D.h"

//�}�N����`
#define SPOWN_MAP (1000)
#define GAME_WIGHT (240.0f)			//��ʉ��̈ړ�����

//�ÓI�����o�ϐ��錾
CEdit_Block3D *CEdit::m_pEditBlock = NULL;			//�}�e���A���ւ̃|�C���^

//====================================================================
//�R���X�g���N�^
//====================================================================
CEdit::CEdit()
{
	m_WightNumber = 1;					//���̔ԍ�
	m_HeightNumber = 0;					//�c�̔ԍ�
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CEdit::~CEdit()
{

}

//====================================================================
//��������
//====================================================================
CEdit *CEdit::Create()
{
	CEdit *pMap = NULL;

	if (pMap == NULL)
	{
		//�I�u�W�F�N�g2D�̐���
		pMap = new CEdit();
	}

	m_pEditBlock = CEdit_Block3D::Create();

	return pMap;
}

//====================================================================
//�I������
//====================================================================
void CEdit::Uninit(void)
{

}


//====================================================================
//�X�V����
//====================================================================
void CEdit::Update(void)
{
	//�L�[�{�[�h�̎擾
	CInputKeyboard *pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	if (pInputKeyboard->GetTrigger(DIK_W) == true ||
		pInputKeyboard->GetTrigger(DIK_UP) == true)
	{
		m_HeightNumber--;

		if (m_HeightNumber < 0)
		{
			m_HeightNumber = SET_BLOCK_HEIGHT - 1;
		}
	}
	if (pInputKeyboard->GetTrigger(DIK_S) == true ||
		pInputKeyboard->GetTrigger(DIK_DOWN) == true)
	{
		m_HeightNumber++;

		if (m_HeightNumber > SET_BLOCK_HEIGHT - 1)
		{
			m_HeightNumber = 0;
		}
	}

	if (pInputKeyboard->GetTrigger(DIK_A) == true ||
		pInputKeyboard->GetTrigger(DIK_LEFT) == true)
	{
		m_WightNumber--;

		if (m_WightNumber < 1)
		{
			m_WightNumber = SET_BLOCK_WIGHT;
		}
	}
	if (pInputKeyboard->GetTrigger(DIK_D) == true ||
		pInputKeyboard->GetTrigger(DIK_RIGHT) == true)
	{
		m_WightNumber++;

		if (m_WightNumber > SET_BLOCK_WIGHT)
		{
			m_WightNumber = 1;
		}
	}

	m_pEditBlock->SetHNumber(m_HeightNumber);
	m_pEditBlock->SetWNumber(m_WightNumber);

	if (pInputKeyboard->GetTrigger(DIK_RETURN) == true)
	{
		if (CBreak_Block3D::GetCheckUse(0, m_WightNumber, m_HeightNumber) == false)
		{
			CBreak_Block3D *pBBlock = CBreak_Block3D::Create();
			pBBlock->SetPos(D3DXVECTOR3(-400.0f + 40.0f * m_WightNumber, 400.0f - 40.0f * m_HeightNumber, 0.0f));
			pBBlock->SetCNumber(0);
			pBBlock->SetWNumber(m_WightNumber);
			pBBlock->SetHNumber(m_HeightNumber);
			pBBlock->SetUse(0, m_WightNumber, m_HeightNumber, true);
		}
	}

	if (pInputKeyboard->GetTrigger(DIK_BACKSPACE) == true)
	{
		if (CBreak_Block3D::GetCheckUse(0, m_WightNumber, m_HeightNumber) == true)
		{
			CBreak_Block3D::UseBreak(0, m_WightNumber, m_HeightNumber);
		}
	}

	if (pInputKeyboard->GetTrigger(DIK_F9) == true)
	{
		SaveData();
	}
}

//====================================================================
//�ۑ�����
//====================================================================
void CEdit::SaveData(void)
{
	FILE *pFile; //�t�@�C���|�C���^��錾

	//�t�@�C�����J��
	pFile = fopen(DATA_NAME, "w");

	if (pFile != NULL)
	{//�t�@�C�����J�����ꍇ

	 //�X�e�[�W���Z�[�u����J�n�̍��}
		fprintf(pFile, "%s\n\n", "STARTSETSTAGE");

		for (int nCntPriority = 0; nCntPriority < PRIORITY_MAX; nCntPriority++)
		{
			//�I�u�W�F�N�g���擾
			CObject *pObj = CObject::GetTop(nCntPriority);

			while (pObj != NULL)
			{
				CObject *pObjNext = pObj->GetNext();

				CObject::TYPE type = pObj->GetType();				//��ނ��擾

				if (type == CObject::TYPE_BREAKBLOCK3D)
				{//��ނ��u���b�N�̎�
					CBreak_Block3D *m_pBBlock = (CBreak_Block3D*)pObj;

					if (m_pBBlock->GetUse() == true)
					{
						fprintf(pFile, "%s\n", "STARTSETBLOCK");

						//�X�e�[�W���Z�[�u�����I���̍��}
						fprintf(pFile, "%d\n", m_pBBlock->GetCNumber());
						fprintf(pFile, "%d\n", m_pBBlock->GetWNumber());
						fprintf(pFile, "%d\n", m_pBBlock->GetHNumber());

						fprintf(pFile, "%s\n\n", "ENDSETBLOCK");
					}
				}

				pObj = pObjNext;
			}
		}

		//�X�e�[�W���Z�[�u�����I���̍��}
		fprintf(pFile, "%s", "ENDSETSTAGE");

		fclose(pFile);
	}
	else
	{//�t�@�C�����J���Ȃ������ꍇ
		printf("***�t�@�C�����J���܂���ł���***\n");
	}
}
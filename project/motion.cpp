//============================================
//
//	���[�V���� [motion.cpp]
//	Author:sakamoto kai
//
//============================================
#include "motion.h"
#include "model.h"
#include <stdio.h>

//====================================================================
//�R���X�g���N�^
//====================================================================
CMotion::CMotion()
{
	m_ppModel = NULL;
	m_nType = 0;					//���[�V�����̎�ނ̐ݒ�
	m_bLoop = m_aInfo[m_nType].bLoop;	//���[�v���邩�ǂ����̐ݒ�
	m_nKey = 0;							//���݂̃L�[No��0�ɂ���
	m_nNextKey = m_nKey + 1;			//���̃L�[No��1�ɂ���
	m_Counter = 0;						//���[�V�����̃J�E���^�[��0�ɂ���
	m_bFinish = false;					//�I�����Ă��Ȃ���Ԃɂ���
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CMotion::~CMotion()
{

}

//====================================================================
//���[�V�����̐ݒ菈��
//====================================================================
void CMotion::Set(int nType)
{
	m_nType = nType;					//���[�V�����̎�ނ̐ݒ�
	m_bLoop = m_aInfo[m_nType].bLoop;	//���[�v���邩�ǂ����̐ݒ�
	m_nKey = 0;							//���݂̃L�[No��0�ɂ���
	m_nNextKey = m_nKey + 1;			//���̃L�[No��1�ɂ���
	m_Counter = 0;						//���[�V�����̃J�E���^�[��0�ɂ���
	m_bFinish = false;					//�I�����Ă��Ȃ���Ԃɂ���

	for (int nCntModel = 0; nCntModel < m_nNumModel; nCntModel++)
	{
		//�p�[�c�̈ʒu�E������ݒ�
		m_ppModel[nCntModel]->SetPos(D3DXVECTOR3
		(
			m_aInfo[m_nType].aKeyInfo[m_nKey].aKey[nCntModel].fPosX,
			m_aInfo[m_nType].aKeyInfo[m_nKey].aKey[nCntModel].fPosY,
			m_aInfo[m_nType].aKeyInfo[m_nKey].aKey[nCntModel].fPosZ
		));

		m_ppModel[nCntModel]->SetRot(D3DXVECTOR3
		(
			m_aInfo[m_nType].aKeyInfo[m_nKey].aKey[nCntModel].fRotX,
			m_aInfo[m_nType].aKeyInfo[m_nKey].aKey[nCntModel].fRotY,
			m_aInfo[m_nType].aKeyInfo[m_nKey].aKey[nCntModel].fRotZ
		));
	}
}

//====================================================================
//���[�V�����̍X�V����
//====================================================================
void CMotion::Update(void)
{
	m_nNumKey = m_aInfo[m_nType].NumKey;

	//�S���f��(�p�[�c)�̍X�V
	for (int nCntModel = 0; nCntModel < m_nNumModel; nCntModel++)
	{
		//�L�[�̏�񂩂�ʒu�E�������Z�o
		float POSX = m_aInfo[m_nType].aKeyInfo[m_nNextKey].aKey[nCntModel].fPosX - m_aInfo[m_nType].aKeyInfo[m_nKey].aKey[nCntModel].fPosX;
		float POSY = m_aInfo[m_nType].aKeyInfo[m_nNextKey].aKey[nCntModel].fPosY - m_aInfo[m_nType].aKeyInfo[m_nKey].aKey[nCntModel].fPosY;
		float POSZ = m_aInfo[m_nType].aKeyInfo[m_nNextKey].aKey[nCntModel].fPosZ - m_aInfo[m_nType].aKeyInfo[m_nKey].aKey[nCntModel].fPosZ;
		float ROTX = m_aInfo[m_nType].aKeyInfo[m_nNextKey].aKey[nCntModel].fRotX - m_aInfo[m_nType].aKeyInfo[m_nKey].aKey[nCntModel].fRotX;
		float ROTY = m_aInfo[m_nType].aKeyInfo[m_nNextKey].aKey[nCntModel].fRotY - m_aInfo[m_nType].aKeyInfo[m_nKey].aKey[nCntModel].fRotY;
		float ROTZ = m_aInfo[m_nType].aKeyInfo[m_nNextKey].aKey[nCntModel].fRotZ - m_aInfo[m_nType].aKeyInfo[m_nKey].aKey[nCntModel].fRotZ;

		//�p�[�c�̈ʒu�E������ݒ�
		m_ppModel[nCntModel]->SetPos(D3DXVECTOR3
		(
			m_ppModel[nCntModel]->GetStartPos().x + m_aInfo[m_nType].aKeyInfo[m_nKey].aKey[nCntModel].fPosX + POSX * ((float)m_Counter / (float)m_aInfo[m_nType].aKeyInfo[m_nKey].nFrame),
			m_ppModel[nCntModel]->GetStartPos().y + m_aInfo[m_nType].aKeyInfo[m_nKey].aKey[nCntModel].fPosY + POSY * ((float)m_Counter / (float)m_aInfo[m_nType].aKeyInfo[m_nKey].nFrame),
			m_ppModel[nCntModel]->GetStartPos().z + m_aInfo[m_nType].aKeyInfo[m_nKey].aKey[nCntModel].fPosZ + POSZ * ((float)m_Counter / (float)m_aInfo[m_nType].aKeyInfo[m_nKey].nFrame)
		));

		m_ppModel[nCntModel]->SetRot(D3DXVECTOR3
		(
			m_ppModel[nCntModel]->GetStartRot().x + m_aInfo[m_nType].aKeyInfo[m_nKey].aKey[nCntModel].fRotX + ROTX * ((float)m_Counter / (float)m_aInfo[m_nType].aKeyInfo[m_nKey].nFrame),
			m_ppModel[nCntModel]->GetStartRot().y + m_aInfo[m_nType].aKeyInfo[m_nKey].aKey[nCntModel].fRotY + ROTY * ((float)m_Counter / (float)m_aInfo[m_nType].aKeyInfo[m_nKey].nFrame),
			m_ppModel[nCntModel]->GetStartRot().z + m_aInfo[m_nType].aKeyInfo[m_nKey].aKey[nCntModel].fRotZ + ROTZ * ((float)m_Counter / (float)m_aInfo[m_nType].aKeyInfo[m_nKey].nFrame)
		));
	}
	m_Counter++;
	if (m_Counter >= m_aInfo[m_nType].aKeyInfo[m_nKey].nFrame)
	{
		m_Counter = 0;
		m_nKey++;
		m_nNextKey++;

		if (m_nNextKey >= m_nNumKey)
		{
			if (m_aInfo[m_nType].bLoop == true)
			{
				m_nNextKey = 0;
			}
			else
			{
				m_nNextKey = 0;
			}
		}
		if (m_nKey >= m_nNumKey)
		{
			if (m_aInfo[m_nType].bLoop == true)
			{
				m_nKey = 0;
			}
			else
			{
				m_nKey = 0;
			}
		}
	}
}

//====================================================================
//���f���̃Z�b�g����
//====================================================================
void CMotion::SetModel(CModel **ppModel, int nNumModel)
{
	m_ppModel = ppModel;
	m_nNumModel = nNumModel;
}

//====================================================================
//���[�V�����̃��[�h����
//====================================================================
void CMotion::LoadData(const char *pFilename)
{
	FILE *pFile; //�t�@�C���|�C���^��錾

	//�t�@�C�����J��
	pFile = fopen(pFilename, "r");

	if (pFile != NULL)
	{//�t�@�C�����J�����ꍇ

		int nCntModel = 0;
		int nCntParts = 0;
		int nCntMotion = 0;
		int nCntKeySet = 0;
		int nCntKey = 0;

		char aString[128] = {};				//�S�~��
		char aMessage[128] = {};		//�X�^�[�g���b�Z�[�W
		char aBool[128] = {};				//bool�ϊ��p���b�Z�[�W

		// �ǂݍ��݊J�n-----------------------------------------------------
		while (1)
		{//�uSCRIPT�v��T��
			fscanf(pFile, "%s", &aMessage[0]);
			if (strcmp(&aMessage[0], "SCRIPT") == 0)
			{
				// ���[�V�������ǂݍ���-----------------------------------------------------
				while (1)
				{//�uMOTIONSET�v��T��
					fscanf(pFile, "%s", &aMessage[0]);
					if (strcmp(&aMessage[0], "MOTIONSET") == 0)
					{
						while (1)
						{//�e��ϐ���T��
							fscanf(pFile, "%s", &aMessage[0]);
							if (strcmp(&aMessage[0], "LOOP") == 0)
							{
								fscanf(pFile, "%s", &aString[0]);
								fscanf(pFile, "%s", &aBool[0]);	//���[�v���邩�ǂ�����ݒ�
								m_aInfo[nCntMotion].bLoop = (strcmp(&aBool[0], "1") == 0 ? true : false);			//bool�^�̏�����
							}
							if (strcmp(&aMessage[0], "NUM_KEY") == 0)
							{
								fscanf(pFile, "%s", &aString[0]);
								fscanf(pFile, "%d", &m_aInfo[nCntMotion].NumKey);	//�L�[�̑�����ݒ�
								break;
							}
						}

						// �L�[���ǂݍ���-----------------------------------------------------
						while (1)
						{//�uKEYSET�v��T��
							fscanf(pFile, "%s", &aMessage[0]);
							if (strcmp(&aMessage[0], "KEYSET") == 0)
							{
								while (1)
								{//�uFRAME�v��T��
									fscanf(pFile, "%s", &aMessage[0]);
									if (strcmp(&aMessage[0], "FRAME") == 0)
									{
										fscanf(pFile, "%s", &aString[0]);
										fscanf(pFile, "%d", &m_aInfo[nCntMotion].aKeyInfo[nCntKeySet].nFrame);	//�L�[�t���[����ݒ�
										break;
									}
								}

								while (1)
								{//�uKEY�v��T��
									fscanf(pFile, "%s", &aMessage[0]);
									if (strcmp(&aMessage[0], "KEY") == 0)
									{
										while (1)
										{//�e��ϐ���T��
											fscanf(pFile, "%s", &aMessage[0]);
											if (strcmp(&aMessage[0], "POS") == 0)
											{
												fscanf(pFile, "%s", &aString[0]);
												fscanf(pFile, "%f", &m_aInfo[nCntMotion].aKeyInfo[nCntKeySet].aKey[nCntKey].fPosX);	//�ʒu��ݒ�
												fscanf(pFile, "%f", &m_aInfo[nCntMotion].aKeyInfo[nCntKeySet].aKey[nCntKey].fPosY);	//�ʒu��ݒ�
												fscanf(pFile, "%f", &m_aInfo[nCntMotion].aKeyInfo[nCntKeySet].aKey[nCntKey].fPosZ);	//�ʒu��ݒ�
											}
											if (strcmp(&aMessage[0], "ROT") == 0)
											{
												fscanf(pFile, "%s", &aString[0]);
												fscanf(pFile, "%f", &m_aInfo[nCntMotion].aKeyInfo[nCntKeySet].aKey[nCntKey].fRotX);	//�ʒu��ݒ�
												fscanf(pFile, "%f", &m_aInfo[nCntMotion].aKeyInfo[nCntKeySet].aKey[nCntKey].fRotY);	//�ʒu��ݒ�
												fscanf(pFile, "%f", &m_aInfo[nCntMotion].aKeyInfo[nCntKeySet].aKey[nCntKey].fRotZ);	//�ʒu��ݒ�
												break;
											}
										}
									}
									if (strcmp(&aMessage[0], "END_KEY") == 0)
									{
										nCntKey++;
										if (nCntKey >= m_nNumModel)
										{
											break;
										}
									}
								}
							}
							if (strcmp(&aMessage[0], "END_KEYSET") == 0)
							{
								nCntKey = 0;
								nCntKeySet++;
								if (nCntKeySet >= m_aInfo[nCntMotion].NumKey)
								{
									break;
								}
							}
						}
					}
					if (strcmp(&aMessage[0], "END_MOTIONSET") == 0)
					{
						nCntKeySet = 0;
						nCntMotion++;
					}
					else if (strcmp(&aMessage[0], "END_SCRIPT") == 0)
					{
						break;
					}
				}
			}
			if (strcmp(&aMessage[0], "END_SCRIPT") == 0)
			{
				break;
			}
		}
		fclose(pFile);
	}
	else
	{//�t�@�C�����J���Ȃ������ꍇ
		printf("***�t�@�C�����J���܂���ł���***\n");
	}
}
//============================================
//
//	���[�V���� [motion.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _MOTION_H_
#define _MOTION_H_

//�}�N����`
#define MAX_INFO (32)	//���̍ő吔
#define MAX_PARTS (32)	//�p�[�c�̑���
#define MAX_KEY (16)	//�L�[�̑���

//�O���錾
class CModel;

//�}�b�v�N���X
class CMotion
{
public:
	CMotion();
	~CMotion();

	//�L�[�̍\����
	typedef struct
	{
		float fPosX;		//�ʒuX
		float fPosY;		//�ʒuY
		float fPosZ;		//�ʒuZ
		float fRotX;		//����X
		float fRotY;		//����Y
		float fRotZ;		//����Z
	}KEY;

	//�L�[���̍\����
	typedef struct
	{
		int nFrame;					//�Đ��t���[��
		KEY aKey[MAX_PARTS];		//�e���f���̃L�[�v�f[�p�[�c�̑���]
	}KEY_INFO;

	//���[�V�������̍\����
	typedef struct
	{
		bool bLoop;						//���[�v���邩�ǂ���
		int NumKey;						//�e���f���̃L�[�v�f
		KEY_INFO aKeyInfo[MAX_KEY];		//�L�[���[�L�[�̑���]
	}INFO;

	void Set(int nType);
	void Update(void);
	int GetType(void);
	bool IsFinish(void);
	void SetInfo(INFO info);
	void SetModel(CModel **ppModel, int nNumModel);
	void LoadData(const char *pFilename);

private:
	INFO m_aInfo[MAX_INFO];		//���[�V�����̏��[���[�V�����̑���]
	int m_nNumAll;				//���f��(�p�[�c)�̑���
	int m_nType;				//���[�V�����̎��
	bool m_bLoop;				//���[�v���邩�ǂ���
	int m_nNumKey;				//�L�[�̑���
	int m_nKey;					//���݂̃L�[No.
	int m_nNextKey;				//���݂̎��̃L�[No.
	int m_Counter;				//���[�V�����̃J�E���^�[
	bool m_bFinish;				//�I���������ǂ���

	CModel **m_ppModel;			//���f���ւ̃|�C���^
	int m_nNumModel;			//���f���̑���
};
#endif
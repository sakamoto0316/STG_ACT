//============================================
//
//	���x���A�b�v���� [LevelUP.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _LEVELUP_H_
#define _LEVELUP_H_

#include "main.h"
#include "player3D.h"

//�O���錾
class CLevelUPUI;

//���x���A�b�v�N���X
class CLevelUP
{
public:
	CLevelUP(int nLevelUP, CPlayer3D::SHOT_TYPE type);
	~CLevelUP();

	static CLevelUP *Create(int nLevelUP, CPlayer3D::SHOT_TYPE type);

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetNULL(void);
	void SetLevelUP(bool Set) { m_bLevelUp = Set; }
	bool GetLevelUp(void) { return m_bLevelUp; }
private:
	void BulletChange(void);

	bool m_bLevelUp;
	static CLevelUPUI *m_pLevelUPText;			//���x���A�b�v���b�Z�[�W
	static CLevelUPUI *m_pLevelUPTutorial;		//���x���A�b�v�̐���
	static CLevelUPUI *m_pLevelUPBG;			//���x���A�b�v�̔w�i
	static CLevelUPUI *m_pLevelUPUI[3];			//���x���A�b�v�pUI
	static CLevelUPUI *m_pLevelUPCursor;		//���x���A�b�v�p�̃J�[�\��
	static int m_nCursorNumber;					//�J�[�\���̈ʒu�ԍ�
	static CPlayer3D::SHOT_TYPE m_BulletType;	//�v���C���[�̒e�̎��
	int LevelUpCount;							//���x���A�b�v�񐔂̃J�E���g
	int LevelUpMax;								//���x���A�b�v�I���̍ő吔
};
#endif
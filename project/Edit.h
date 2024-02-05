//============================================
//
//	�G�f�B�b�g [Edit.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _EDIT_H_
#define _EDIT_H_

#include "main.h"
#include "object.h"

#define SET_BLOCK_WIGHT (20)
#define SET_BLOCK_HEIGHT (25)

//�O���錾
class CEdit_Block3D;

//�}�b�v�N���X
class CEdit
{
public:
	CEdit();
	~CEdit();

	static CEdit *Create();
	void Uninit(void);
	void Update(void);

protected:

private:
	void SaveData(void);

	static CEdit_Block3D *m_pEditBlock;
	int m_WightNumber;		//���̔ԍ�
	int m_HeightNumber;		//�c�̔ԍ�
};
#endif
//============================================
//
//	�����̏��� [number.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _NUMBER_H_
#define _NUMBER_H_

#include "main.h"
#include "object2D.h"

//�I�u�W�F�N�g�v���C���[�N���X
class CNumber : public CObject2D
{
public:

	CNumber(int nPriority = 4);
	~CNumber();

	static CNumber *Create(void);

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	int GetNumber(void) { return m_nNumber; }
   	void SetNumber(int number) { m_nNumber = number; }
	int GetIdx(void) { return m_nIdxTexture; }

private:
	int m_nIdxTexture;						//�e�N�X�`���̔ԍ�
	int m_nNumber;							//�\�����鐔��
};
#endif
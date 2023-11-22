//============================================
//
//	�f�o�b�O�p�����̏��� [DebugNumber3D.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _DEBUGNUMBER3D_H_
#define _DEBUGNUMBER3D_H_

#include "main.h"
#include "objectBillboard.h"

//�I�u�W�F�N�g�v���C���[�N���X
class CDebugNumber3D : public CObjectBillboard
{
public:

	CDebugNumber3D(int nPriority = 5);
	~CDebugNumber3D();

	static CDebugNumber3D *Create(void);

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
//============================================
//
//	�O�i�̏��� [ForeGround2D.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _FOREGROUND_H_
#define _FOREGROUND_H_

#include "main.h"
#include "object2D.h"

//�I�u�W�F�N�g�v���C���[�N���X
class CFG : public CObject2D
{
public:

	CFG(int Cnt,int nType, int nPriority = 5);
	~CFG();

	static CFG *Create(int nCnt, int nType);

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	int GetIdx(void) { return m_nIdxTexture; }

private:
	int m_nIdxTexture;					//�e�N�X�`���̔ԍ�
	int m_nLife;						//���̑O�i�����݂��鎞��
	int m_nType;						//�O�i�̎��
	int m_ColorCount;					//�O�i�̐F�؂�ւ�����
	bool m_bColorSet;					//�O�i�̐F�؂�ւ��t���O
};
#endif
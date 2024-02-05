//============================================
//
//	���C�t�Q�[�W�̃r���{�[�h [LifeGaugeBillboard.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _LIFEGAUGEBILLBOARD_H_
#define _LIFEGAUGEBILLBOARD_H_

#include "main.h"
#include "GaugeBillboard.h"

//�I�u�W�F�N�g�v���C���[�N���X
class CLifeGaugeBillboard : public CGaugeBillboard
{
public:

	CLifeGaugeBillboard(int nPriority = 5);
	~CLifeGaugeBillboard();

	static CLifeGaugeBillboard *Create(void);

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	int GetIdx(void) { return m_nIdxTexture; }

private:
	int m_nIdxTexture;		//�e�N�X�`���̔ԍ�
};
#endif
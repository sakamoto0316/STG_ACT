//============================================
//
//	���x���A�b�v����UI�̏��� [LevelUPUI.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _LEVELUPUI_H_
#define _LEVELUPUI_H_

#include "main.h"
#include "object2D.h"

//���x���A�b�vUI�N���X
class CLevelUPUI : public CObject2D
{
public:

	CLevelUPUI(int nPriority = 5);
	~CLevelUPUI();

	static CLevelUPUI *Create(void);

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetIdx(int Idx) { m_nIdxTexture = Idx; }
	int GetIdx(void) { return m_nIdxTexture; }

private:
	int m_nIdxTexture;						//�e�N�X�`���̔ԍ�
};
#endif
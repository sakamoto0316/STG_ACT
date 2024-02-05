//============================================
//
//	�e�̎�ނ�UI�̏��� [BulletTypeUI.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _BULLETTYPEUI_H_
#define _BULLETTYPEUI_H_

#include "main.h"
#include "object2D.h"

//���x���A�b�vUI�N���X
class CBulletTypeUI : public CObject2D
{
public:

	CBulletTypeUI(int nPriority = 5);
	~CBulletTypeUI();

	static CBulletTypeUI *Create(void);

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
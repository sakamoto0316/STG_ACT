//============================================
//
//	���C�g�̏��� [light.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "main.h"

//�}�N����`
#define MAX_LIGHT (3)	//�g�p���郉�C�g�̐�

//�J�����N���X
class CLight
{
public:
	CLight();
	~CLight();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);

private:
	D3DLIGHT9 m_aLight[MAX_LIGHT];
};

#endif
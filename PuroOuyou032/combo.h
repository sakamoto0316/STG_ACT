//============================================
//
//	�R���{���� [combo.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _COMBO_H_
#define _COMBO_H_

#include "main.h"
#include "player3D.h"

//�O���錾
class CDebugNumber3D;
class CComboUI;

//���x���A�b�v�N���X
class CCombo
{
public:
	CCombo();
	~CCombo();

	static CCombo *Create(void);

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetCombo(int Combo) { m_nComboNumber = Combo; }
	void SetPos(D3DXVECTOR3 pos) { m_pos = pos; }
	D3DXVECTOR3 SetPos(void) { return m_pos; }
	void SetNULL(void);
private:
	D3DXVECTOR3 m_pos;				//�ʒu
	int m_nComboNumber;				//�R���{��
	CDebugNumber3D *m_pNumber1;		//�R���{��UI
	CDebugNumber3D *m_pNumber10;	//�R���{��UI
	CComboUI *m_pComboUI;			//�R���{�pUI
};
#endif
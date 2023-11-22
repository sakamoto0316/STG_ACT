//============================================
//
//	�ō����x�������̉��o�|���S���̏��� [FallEffect.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _FALLEFFECT_H_
#define _FALLEFFECT_H_

#include "main.h"
#include "objectBillboard.h"

//���x���A�b�vUI�N���X
class CFallEffect : public CObjectBillboard
{
public:

	CFallEffect(int nPriority = 5);
	~CFallEffect();

	static CFallEffect *Create(void);

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetIdx(int Idx) { m_nIdxTexture = Idx; }
	int GetIdx(void) { return m_nIdxTexture; }
	void SetLife(int Life) { m_nLife = Life; }
	int GetLife(void) { return m_nLife; }

private:
	int m_nIdxTexture;			//�e�N�X�`���̔ԍ�
	float m_MoveUP;				//������ɐi�ޗ�
	int m_nLife;				//����
};
#endif
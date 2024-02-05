//============================================
//
//	�p�[�e�B�N������ [DirectionParticle.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _DERECTIONPARTICLE_H_
#define _DERECTIONPARTICLE_H_

#include "main.h"
#include "object.h"

//�O���錾
class CObject2D;

//�p�[�e�B�N���N���X
class CDirectionParticle : public CObject
{
public:
	CDirectionParticle();
	CDirectionParticle(D3DXVECTOR3 pos, D3DXCOLOR col, float Radius, int nLife, float nSize, int nType);
	~CDirectionParticle();

	static CDirectionParticle *Create(D3DXVECTOR3 pos, D3DXCOLOR col, float Radius, int nLife, float nSize, int nType);

	virtual HRESULT Init(void);
	virtual void Uninit(void);
	virtual void Update(void);
	virtual void Draw(void);

	void SetPos(D3DXVECTOR3 pos) { m_pos = pos; }
	D3DXVECTOR3 GetPos(void) { return m_pos; }
	void SetMove(D3DXVECTOR3 move) { m_move = move; }
	D3DXVECTOR3 GetMove(void) { return m_move; }
	void SetRadius(float Size) { m_nSize = Size; }
	float GetRadius(void) { return m_nSize; }
	void SetColer(D3DXCOLOR Coler) { m_col = Coler; }
	D3DXCOLOR GetColer(void) { return m_col; }
	void SetLife(int Life) { m_nLife = Life; }
	int GetLife(void) { return m_nLife; }
	void SetParticleType(int Type) { m_nType = Type; }
	int GetParticleType(void) { return m_nType; }

protected:

private:
	D3DXVECTOR3 m_Rand;			//�����_���̒l
	D3DXVECTOR3 m_pos;			//�����ʒu
	D3DXVECTOR3 m_move;			//�ړ���
	D3DXCOLOR m_col;			//�F
	int m_nLife;				//����(��������)
	float m_nSize;				//�傫��
	float m_nRadius;			//���a
	int m_nType;				//���	

};

#endif
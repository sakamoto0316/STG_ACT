//============================================
//
//	�e�̏��� [bullet3D.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _BULLET3D_H_
#define _BULLET3D_H_

#include "main.h"
#include "objectBillboard.h"

//�e�N���X
class CBullet3D : public CObjectBillboard
{
public:
	typedef enum
	{
		BULLET_NORMAL = 0,
		BULLET_SPREAD_3WAY,
		BULLET_SPREAD_CONTINUE_3WAY,
		BULLET_SPREAD_CROSS,
		BULLET_SPREAD_EXCROSS,
	}BULLET_TYPE;

	CBullet3D(BULLET_TYPE Type, int nPriority = 2);
	~CBullet3D();

	static CBullet3D *Create(BULLET_TYPE Type);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetMove(D3DXVECTOR3 move) { m_move = move; }
	D3DXVECTOR3 GetMove(void) { return m_move; }
	void SetLife(int Life) { m_nLife = Life; }
	int GetLife(void) { return m_nLife; }
	void SetStop(float Stop) { m_stop = Stop; }
	float GetStop(void) { return m_stop; }
	int GetIdx(void) { return m_nIdxTexture; }
	void SetSpreadCount(int SpreadCount) { m_SpreadCount = SpreadCount; }


private:
	bool CollisionObject(D3DXVECTOR3 pos);	//�I�u�W�F�N�g�Ƃ̓����蔻��
	void Hit(D3DXVECTOR3 pos);							//�e�������������̏���

	BULLET_TYPE m_Type;						//�e�̎��
	int m_SpreadCount;						//�g�U�e�𔭐�������J�E���g
	int m_nIdxTexture;						//�e�N�X�`���̔ԍ�
	D3DXVECTOR3 m_move;						//�ړ���	
	int m_nLife;							//����	
	float m_stop;							//�����W��	
};
#endif
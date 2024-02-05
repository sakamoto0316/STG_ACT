//============================================
//
//	�G�̒e�̏��� [EnemyBullet3D.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _ENEMYBULLET3D_H_
#define _ENEMYBULLET3D_H_

#include "main.h"
#include "objectBillboard.h"

//�e�N���X
class CEenmyBullet3D : public CObjectBillboard
{
public:

	CEenmyBullet3D(int nPriority = 2);
	~CEenmyBullet3D();

	static CEenmyBullet3D *Create(void);
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

private:
	bool CollisionObject(D3DXVECTOR3 pos);	//�I�u�W�F�N�g�Ƃ̓����蔻��

	int m_nIdxTexture;						//�e�N�X�`���̔ԍ�
	D3DXVECTOR3 m_move;						//�ړ���	
	int m_nLife;								//����	
	float m_stop;							//�����W��	
};
#endif
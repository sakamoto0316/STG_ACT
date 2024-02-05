//============================================
//
//	�o���l�̏��� [LevelPoint3D.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _LEVELPOINT_H_
#define _LEVELPOINT_H_

#include "main.h"
#include "objectX.h"

//�O���錾
class CItem;
class CEnemy;
class CLifeGaugeBillboard;

//�I�u�W�F�N�g�v���C���[�N���X
class CLevelPoint : public CObjectX
{
public:
	typedef enum
	{
		MOVE_WAIT = 0,
		MOVE_PLAYER,
		MOVE_MAX,
	}MOVE_STATE;

	CLevelPoint(int nPriority = 3);
	~CLevelPoint();
	int GetIdxXModel(void) { return m_nIdxXModel; }
	int GetIdxTexture(int nCnt) { return m_nIdxTexture[nCnt]; }

	static CLevelPoint *Create();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	D3DXVECTOR3 GetMove(void) { return m_move; }
	void SetMove(D3DXVECTOR3 move) { m_move = move; }

private:
	static int m_nIdxXModel;				//X���f���̔ԍ�
	static int m_nIdxTexture[64];			//X���f���e�N�X�`���̔ԍ�
	D3DXVECTOR3 m_move;						//�ړ���
	float m_SpeedUp;						//�ړ���
	MOVE_STATE m_MoveState;					//�ړ����
	int m_MoveCount;						//�ړ���ԕύX�̂��߂̃J�E���g
};
#endif
//============================================
//
//	�G�̏��� [Enemy3D.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _ENEMY3D_H_
#define _ENEMY3D_H_

#include "main.h"
#include "objectX.h"

//�O���錾
class CItem;
class CEnemy;
class CLifeGaugeBillboard;
class CEenmyBullet3D;

//�I�u�W�F�N�g�v���C���[�N���X
class CEnemy3D : public CObjectX
{
public:
	typedef enum
	{
		ENEMY_NORMAL = 0,
		ENEMY_WALLD,
		ENEMY_WALLU,
		ENEMY_GROUND,
		ENEMY_MAX,
	}ENEMY_TYPE;

	typedef enum
	{
		STATE_NORMAL = 0,
		STATE_DAMAGE,
		STATE_WAIT,
		STATE_MAX,
	}STATE_TYPE;

	CEnemy3D(ENEMY_TYPE Type, int nPriority = 3);
	~CEnemy3D();
	int GetIdxXModel(void) { return m_nIdxXModel[m_Type]; }
	int GetIdxTexture(int nCnt) { return m_nIdxTexture[m_Type][nCnt]; }

	static CEnemy3D *Create(ENEMY_TYPE Type);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	D3DXVECTOR3 MoveNormal(D3DXVECTOR3 pos);
	D3DXVECTOR3 MoveWallD(D3DXVECTOR3 pos);
	void MoveWallU(D3DXVECTOR3 pos);
	D3DXVECTOR3 MoveGround(D3DXVECTOR3 pos);
	void Draw(void);
	void Hit(D3DXVECTOR3 pos, int Damage);											//�_���[�W�q�b�g����
	void Death(D3DXVECTOR3 pos, float nRadius, int BreakCount);						//���S����
	void StateManager(void);														//��ԊǗ�
	bool CollisionBlock(D3DXVECTOR3 *pos, bool bX);									//�u���b�N�Ƃ̓����蔻��
	void CollisionObjectCircle(D3DXVECTOR3 pos, float nRadiusOut, int BreakCount);	//�~�̓����蔻��
	void SetNULL(void);

	D3DXVECTOR3 GetMove(void) { return m_move; }
	void SetMove(D3DXVECTOR3 move) { m_move = move; }
	void SetEnemyType(ENEMY_TYPE Type) { m_Type = Type; }
	int GetLife(void) { return m_nLife; }

private:
	static int m_nIdxXModel[ENEMY_MAX];			//X���f���̔ԍ�
	static int m_nIdxTexture[ENEMY_MAX][64];	//X���f���e�N�X�`���̔ԍ�
	D3DXVECTOR3 m_move;							//�ړ���	
	int m_nLife;								//�̗�	
	CLifeGaugeBillboard *m_pLifeGauge;			//�̗͗p�̃Q�[�W�\��
	STATE_TYPE m_State;							//���
	ENEMY_TYPE m_Type;							//�G�̎��
	int m_StateCount;							//��Ԃ̒������Ǘ�����J�E���g
	int m_BulletCount;							//�G���e�������߂̃J�E���g
	int m_JumpCount;							//�G���W�����v���邽�߂̃J�E���g
	bool m_bJump;								//�G���W�����v�������ǂ���
	int m_nDeathStopCount;						//�G�����S����O�̃q�b�g�X�g�b�v
	bool m_bDeathCountFlog;						//�G�����S����Ƃ��̃t���O
	bool m_bDeath;								//�G�����S�������ǂ���
	CEnemy3D *pEnemy;							//�G�̃|�C���^
};
#endif
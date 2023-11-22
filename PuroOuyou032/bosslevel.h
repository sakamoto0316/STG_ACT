//============================================
//
//	�{�X�̏��� [bosslevel.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _BOSSLEVEL_H_
#define _BOSSLEVEL_H_

#include "object.h"

//�O���錾
class CModel;
class CMotion;

//�I�u�W�F�N�g�v���C���[�N���X
class CBossLevel : public CObject
{
public:
	CBossLevel();
	~CBossLevel();

	//�v���C���[�̃��[�V����
	typedef enum
	{
		ACTION_WAIT1 = 0,
		ACTION_WAIT2,
		ACTION_WAIT3,
		ACTION_WAIT4,
		ACTION_RUNPOZE,
		ACTION_MAX,

	}ACTION_TYPE;

	D3DMATRIX GetMtxWorld(void) { return m_mtxWorld; }
	static CBossLevel *Create();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void LoadLevelData(const char *pFilename);
	void SetPos(D3DXVECTOR3 pos) { m_pos = pos; }
	D3DXVECTOR3 GetEatPos(void) { return m_eatpos; }
	void SetEatSpeed(float Speed) { m_EatFallSpeed = Speed; }
	bool CollisionObject(void);
	void SetNULL(void);

private:
	void MotionTest(void);

	D3DXVECTOR3 m_pos;		//�ʒu
	D3DXVECTOR3 m_eatpos;	//�u���b�N��G��H�ׂ�ʒu
	float m_EatFallSpeed;		//�H�ׂ�X�s�[�h
	D3DXVECTOR3 m_rot;		//����
	D3DXMATRIX m_mtxWorld;	//���[���h�}�g���b�N�X

	CModel *m_apModel[64];
	CMotion *m_pMotion;
	char *m_aModelName[64];
	int m_nNumModel;
};

#endif
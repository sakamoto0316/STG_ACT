//============================================
//
//	�}�b�v�̎����������� [map2D.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _MAP2D_H_
#define _MAP2D_H_

#include "main.h"
#include "object.h"

#define SET_BLOCK_WIGHT (20)
#define SET_BLOCK_HEIGHT (25)
#define DATA_NAME ("data\\TXT\\Stage02")	//�X�^�[�g���b�Z�[�W�����邩�ǂ����̊m�F

//�O���錾
class CNormal_Block;
class CBreak_Block3D;
class CEnemy3D;
class CItem;

//�}�b�v�N���X
class CMap2D
{
public:
	CMap2D();
	~CMap2D();

	static CMap2D *Create();
	void Uninit(void);
	void Update(void);

	void SetDepth(float Depth) { m_DepthOld = m_Depth; m_Depth = Depth; }
	float GetDepth(void) { return m_Depth; }
	void SetDepthOld(float DepthOld) { m_DepthOld = DepthOld; }
	float GetDepthOld(void) { return m_DepthOld; }
	void SetBreakPos(D3DXVECTOR3 BreakPos) { m_BreakPos = BreakPos; }
	void SetDirectionPos(D3DXVECTOR3 DirectionPos) { m_DirectionPos = DirectionPos; }
	D3DXVECTOR3 GetBreakPos(void) { return m_BreakPos; }
	void AddCreateEnemy(void) { CreateEnemy++; }
	void DeleteEventEnemy(void) { m_EventEnemy--; }
	int GetEventEnemy(void) { return m_EventEnemy; }
	int GetMapLevel(void) { return m_MapLevel; }
	void CleanBlockUse(void);

protected:

private:
	void CreateMap(void);
	void CreateSideMap(void);
	void CreateEventMap(void);
	void EventStart(void);
	void EventUpdate(void);
	void EndDirection(void);
	void SetBlock(void);
	void LoadBlock(char *Name, D3DXVECTOR3 pos);
	void SetLevelUP(void);
	void BreakBlck(void);
	void ColorCircle(D3DXVECTOR3 pos);
	bool CollisionCircleOut(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2, float nRadiusOut, float nRadiusIn);
	void CMap2D::CollisionSquare(D3DXVECTOR3 pos);

	int m_MapLevel;					//�}�b�v�̓�Փx
	float m_DepthOld;				//�ߋ��̐[��
	float m_Depth;					//���݂̐[��
	bool m_bCreate;					//�}�b�v�������s�������ǂ���
	bool m_bSpownMove;				//�G�������ꏊ�ɏo�����Ȃ����߁A�o�����Ă���ړ��������𔻒f����t���O
	float m_fCreatePoint;			//�}�b�v�������s�����ʒu
	int m_BreakSelect;				//�u���b�N�̔j��͈�
	int m_EnemySelect;				//�o������G�̎��
	int m_EnemySelect2;				//�o������G�̎��
	int CreateEnemy;				//�}�b�v�����̍ۂɓG���o����
	int CreateEnemyCount;			//�}�b�v�����̍ۂɓG���o������
	int CreateNumber;				//�}�b�v�����̉�
	D3DXVECTOR3 m_BreakPos;			//�j����J�n����ʒu
	D3DXVECTOR3 m_BreakEnd;			//�j����J�n����ʒu
	int m_TestCount;				//�e�X�g�p�J�E���g
	int m_CreateNumber;				//�����ԍ�
	int m_WightNumber;				//���̔ԍ�
	int m_HeightNumber;				//�c�̔ԍ�
	int m_EventEnemy;				//�C�x���g���̓G�̐�
	float m_EventStartLine;			//�C�x���g�̕������ǂ����̊���C��
	D3DXVECTOR3 m_EventEndBreakPos;	//�C�x���g�I�����̃u���b�N�j��ʒu
	int m_EndDirectionTime;			//�C�x���g�I�����̉��o����
	bool m_bEndDirection;			//�C�x���g�I�����̉��o���o���Ă��邩�ǂ���
	D3DXVECTOR3 m_DirectionPos;		//���o�����ʒu
	int m_nCntCreateEventMap;		//�C�x���g�}�b�v�̔�����
	int m_nCreateEventMap;			//���������C�x���g�}�b�v�̔ԍ�

	float m_fCirclePos;				//�F�؂�ւ��̉~�̈ʒu
	bool m_bColorCircle;			//�F�؂�ւ��̉~���g�p���Ă��邩�ǂ���

	CNormal_Block *m_pNormalBlock;
	CBreak_Block3D *m_pBreakBlock3D;
	CEnemy3D *m_pEnemy;
	CItem *m_pItem;
};
#endif
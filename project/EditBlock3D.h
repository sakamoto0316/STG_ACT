//============================================
//
//	�G�f�B�b�g�p�u���b�N�̏��� [EditBlock3D.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _EDITBLOCK_H_
#define _EDITBLOCK_H_

#include "main.h"
#include "objectXtex.h"
#include "Map2D.h"

//�O���錾
class CDebugNumber3D;

//�I�u�W�F�N�g�v���C���[�N���X
class CEdit_Block3D : public CObjectXtex
{
public:

	CEdit_Block3D(int nPriority = 3);
	~CEdit_Block3D();

	static CEdit_Block3D *Create();
	void SetMove(D3DXVECTOR3 move) { m_move = move; }
	D3DXVECTOR3 GetMove(void) { return m_move; }
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetCNumber(int Number) { m_CreateNumber = Number; }
	void SetWNumber(int Number) { m_WightNumber = Number; }
	void SetHNumber(int Number) { m_HeightNumber = Number; }
	void SetUse(int Create, int Wight, int Height, bool Use) { m_bUse[Create][Wight][Height] = Use; }
	int GetIdx(void) { return m_nIdxTexture; }
	void bUseSet(void);
	int GetIdxXModel(void) { return -1; }

private:
	static LPD3DXMESH m_pMesh;				//���b�V��(���_���)�ւ̃|�C���^
	static LPD3DXBUFFER m_pBuffMat;			//�}�e���A���ւ̃|�C���^
	static DWORD m_dwNumMat;				//�}�e���A���̐�
	static int m_nIdxXModel;				//X���f���̔ԍ�
	int m_nIdxTexture;						//�e�N�X�`���̔ԍ�
	int m_CreateNumber;						//�����̔ԍ�
	int m_WightNumber;						//���̔ԍ�
	int m_HeightNumber;						//�c�̔ԍ�
	static bool m_bUse[100][SET_BLOCK_WIGHT + 2][SET_BLOCK_HEIGHT];
	bool m_bBreak;
	int m_nWaveCount;
	float m_nWavePower;
	bool m_bWave;
	int m_nBreakCount;
	D3DXVECTOR3 m_move;						//�ړ���	
};
#endif
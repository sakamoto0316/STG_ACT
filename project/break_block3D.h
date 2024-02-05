//============================================
//
//	�j��\�u���b�N�̏��� [break_block3D.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _BREAKBLOCK3D_H_
#define _BREAKBLOCK3D_H_

#include "main.h"
#include "objectXtex.h"
#include "Map2D.h"

#define NUM 0

//�O���錾
class CDebugNumber3D;

//�I�u�W�F�N�g�v���C���[�N���X
class CBreak_Block3D : public CObjectXtex
{
public:

	CBreak_Block3D(int nPriority = 3);
	~CBreak_Block3D();

	static CBreak_Block3D *Create();
	void SetMove(D3DXVECTOR3 move) { m_move = move; }
	D3DXVECTOR3 GetMove(void) { return m_move; }
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void Wave(void);											//�U������
	void Hit(D3DXVECTOR3 pos, int Damage);						//�_���[�W�q�b�g����
	bool Break(void);
	void BreakCountSet(int Count);
	static void CreateMapBlocks(int CreateNumber, D3DXVECTOR3 pos);
	bool Collision(D3DXVECTOR3 *pPos, D3DXVECTOR3 pPosOld, D3DXVECTOR3 *pMove, float fHeight, float fWidth, bool bX);
	void ChangeColor(int Level);
	void CleanBlockUse(void);

	int GetCNumber(void) { return m_CreateNumber; }
	void SetCNumber(int Number) { m_CreateNumber = Number; }
	int GetWNumber(void) { return m_WightNumber; }
	void SetWNumber(int Number) { m_WightNumber = Number; }
	int GetHNumber(void) { return m_HeightNumber; }
	void SetHNumber(int Number) { m_HeightNumber = Number; }
	void SetUse(int Create, int Wight, int Height, bool Use) { m_bUse[Create][Wight][Height] = Use; }
	static void TrueUse(int Create, int Wight, int Height) { m_bUse[Create][Wight][Height] = true; }
	static bool GetCheckUse(int Create, int Wight, int Height) { return m_bUse[Create][Wight][Height]; }
	bool GetUse(void) { return m_bUse[m_CreateNumber][m_WightNumber][m_HeightNumber]; }
	static void UseBreak(int Create, int Wight, int Height);
	void SetTexture(void);
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
	bool m_bColorChange;					//�F���ς�������ǂ���
	D3DXCOLOR m_BlockColor;
	D3DXVECTOR3 m_move;						//�ړ���	
	CDebugNumber3D *m_pCNumber;
	CDebugNumber3D *m_pWNumber;
	CDebugNumber3D *m_pHNumber;
	CDebugNumber3D *m_pBNumber;
};
#endif
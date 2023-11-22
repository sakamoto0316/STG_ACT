//============================================
//
//	���E�̃u���b�N�̏��� [SideBlock3D.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _SIDEBLOCK3D_H_
#define _SIDEBLOCK3D_H_

#include "main.h"
#include "objectXtex.h"
#include "Map2D.h"

//�O���錾
class CDebugNumber3D;

//�I�u�W�F�N�g�v���C���[�N���X
class CSide_Block3D : public CObjectXtex
{
public:

	CSide_Block3D(int nPriority = 3);
	~CSide_Block3D();

	static CSide_Block3D *Create();
	void SetMove(D3DXVECTOR3 move) { m_move = move; }
	D3DXVECTOR3 GetMove(void) { return m_move; }
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void ChangeColor(int Level);

	int GetIdx(void) { return m_nIdxTexture; }
	int GetIdxXModel(void) { return -1; }

private:
	static LPD3DXMESH m_pMesh;				//���b�V��(���_���)�ւ̃|�C���^
	static LPD3DXBUFFER m_pBuffMat;			//�}�e���A���ւ̃|�C���^
	static DWORD m_dwNumMat;				//�}�e���A���̐�
	static int m_nIdxXModel;				//X���f���̔ԍ�
	int m_nIdxTexture;						//�e�N�X�`���̔ԍ�
	bool m_bColorChange;					//�F���ς�������ǂ���
	D3DXCOLOR m_BlockColor;
	D3DXVECTOR3 m_move;						//�ړ���	
	CDebugNumber3D *m_pCNumber;
	CDebugNumber3D *m_pWNumber;
	CDebugNumber3D *m_pHNumber;
	CDebugNumber3D *m_pBNumber;
};
#endif
//============================================
//
//	�j�󂳂ꂽ�u���b�N�̏��� [breakPiece.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _BREAKPIECE_H_
#define _BREAKPIECE_H_

#include "main.h"
#include "objectXtex.h"

//�O���錾

//�I�u�W�F�N�g�v���C���[�N���X
class CBreak_Piece : public CObjectXtex
{
public:

	CBreak_Piece(int nPriority = 3);
	~CBreak_Piece();

	static CBreak_Piece *Create();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	int GetIdx(void) { return m_nIdxTexture; }
	int GetIdxXModel(void) { return -1; }

private:

	D3DXCOLOR m_BlockColor;
	float m_ColorA;
	static LPD3DXMESH m_pMesh;				//���b�V��(���_���)�ւ̃|�C���^
	static LPD3DXBUFFER m_pBuffMat;			//�}�e���A���ւ̃|�C���^
	static DWORD m_dwNumMat;				//�}�e���A���̐�
	static int m_nIdxXModel;				//X���f���̔ԍ�
	int m_nIdxTexture;						//�e�N�X�`���̔ԍ�

	D3DXVECTOR3 m_move;						//�ړ���	
	D3DXVECTOR3 m_rot;						//�ړ���	

};
#endif
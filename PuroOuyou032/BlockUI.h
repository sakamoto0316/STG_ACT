//============================================
//
//	�u���b�N��UI�̏��� [BlockUI.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _BLOCKUI_H_
#define _BLOCKUI_H_

#include "main.h"
#include "objectXtex.h"

//�I�u�W�F�N�g�v���C���[�N���X
class CBlockUI : public CObjectXtex
{
public:

	CBlockUI(int nPriority = 5);
	~CBlockUI();

	static CBlockUI *Create();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	int GetIdx(void) { return m_nIdxTexture; }
	bool Collision(D3DXVECTOR3 *pPos, D3DXVECTOR3 pPosOld, D3DXVECTOR3 *pMove, float fHeight, float fWidth, bool bX);
	void Hit(D3DXVECTOR3 pos, int Damage);
	void SetMyCount(int Count) { m_MyCount = Count; }

private:
	static LPD3DXMESH m_pMesh;				//���b�V��(���_���)�ւ̃|�C���^
	static LPD3DXBUFFER m_pBuffMat;			//�}�e���A���ւ̃|�C���^
	static DWORD m_dwNumMat;				//�}�e���A���̐�
	static int m_nIdxXModel;				//X���f���̔ԍ�
	int m_nIdxTexture;						//�e�N�X�`���̔ԍ�
	int m_MyCount;							//�����̔ԍ�
};
#endif
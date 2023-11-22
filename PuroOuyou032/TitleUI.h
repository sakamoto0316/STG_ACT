//============================================
//
//	�^�C�g����UI�̏��� [TitleUI.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _TITLEUI_H_
#define _TITLEUI_H_

#include "main.h"
#include "objectXtex.h"

//�I�u�W�F�N�g�v���C���[�N���X
class CTitleUI : public CObjectXtex
{
public:

	CTitleUI(int nPriority = 5);
	~CTitleUI();

	static CTitleUI *Create();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	int GetIdx(void) { return m_nIdxTexture; }

private:
	static LPD3DXMESH m_pMesh;				//���b�V��(���_���)�ւ̃|�C���^
	static LPD3DXBUFFER m_pBuffMat;			//�}�e���A���ւ̃|�C���^
	static DWORD m_dwNumMat;				//�}�e���A���̐�
	static int m_nIdxXModel;				//X���f���̔ԍ�
	int m_nIdxTexture;						//�e�N�X�`���̔ԍ�
	int m_MyCount;							//�����̔ԍ�
};
#endif
//============================================
//
//	�^�C�g����� [title.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _TITLE_H_
#define _TITLE_H_

#include "main.h"
#include "manager.h"

//�}�N����`
#define MAX_SELECT (3)
#define MAX_TITLEUI (3)

//�O���錾
class CObject2D;
class CPlayer3D;
class CBreak_Block3D;
class CBlockUI;
class CTitleUI;
class CFallEffect;

//�V�[���N���X
class CTitle : public CScene
{
public:
	CTitle();
	~CTitle();

	virtual HRESULT Init(void);
	virtual void Uninit(void);
	virtual void Update(void);
	virtual void Draw(void);
	static void SetSelectColor(int SelectCnt);

private:
	void Select(void);

	static int m_nSelect;
	static int m_CreateCount;
	static CPlayer3D *m_pPlayer3D;			//�v���C���[�̃|�C���^
	static CBreak_Block3D *m_pBlock3D;		//�u���b�N�̃|�C���^
	static CObject2D *m_pTitle;
	static CBlockUI *m_pSelect[MAX_SELECT];
	static CTitleUI *m_pTitleUI[MAX_TITLEUI];
};
#endif
//============================================
//
//	�Q�[����� [game.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _GAME_H_
#define _GAME_H_

#include "main.h"
#include "manager.h"

//�O���錾
class CPlayer3D;
class CMap2D;
class CPlayerLevel;
class CBossLevel;
class CBreak_Block3D;
class CEdit;
class CTutorialUI;
class CObject2D;
class CPause;
class CScore;

//�V�[���N���X
class CGame : public CScene
{
public:
	CGame();
	~CGame();

	virtual HRESULT Init(void);
	virtual void Uninit(void);
	virtual void Update(void);
	virtual void Draw(void);

	void ReSetGame(void);
	void UpdateTutorial(void);
	void SkipTutorial(void);
	void GameStartEvent(void);
	static CPlayer3D *GetPlayer3D(void) { return m_pPlayer3D; }
	static CMap2D *GetMap2D(void) { return m_pMap2D; }
	static CBossLevel *GetBossLevel(void) { return m_pBossLevel; }
	static CPause *GetPause(void) { return m_pPause; }
	static CScore *GetScore(void) { return m_pScore; }
	static void SetGameEnd(int Time) { m_bGameEnd = true; m_bGameEndTime = Time; }
	static bool GetTutorial(void) { return m_bTutorial; }
	static void SetGSEvent(bool Set) { m_bGSEvent = Set; }
	static bool GetGSEvent(void) { return m_bGSEvent; }
	static void SetGSEventCamera(bool Set) { m_bGSEventCamera = Set; }
	static bool GetGSEventCamera(void) { return m_bGSEventCamera; }
	static void SetEvent(bool Set) { m_bEvent = Set; }
	static bool GetEvent(void) { return m_bEvent; }
	static void SetEventStart(bool Set) { m_bEventStart = Set; }
	static bool GetEventStart(void) { return m_bEventStart; }
	static void DeleteTutorial(void);
	static void SetTutorial(void);
	static void SetTutorialUnderText(char *cName);
	static void SetTutorialStart(bool Set) { m_bTutorial = Set; }

private:
	int m_GSEventCount;						//�Q�[���X�^�[�g�C�x���g�̒���
	static bool m_bGSEvent;					//�Q�[���X�^�[�g�C�x���g�����ǂ���
	static bool m_bGSEventCamera;			//�Q�[���X�^�[�g�C�x���g�������������ǂ���
	bool m_bGSEventEnd;						//�Q�[���X�^�[�g�C�x���g�������������ǂ���
	static bool m_bEvent;					//�C�x���g�����ǂ���
	static bool m_bEventStart;				//�C�x���g�̕������ǂ���
	static bool m_bGameEnd;					//�Q�[���I����Ԃ��ǂ���
	static bool m_bTutorial;				//�`���[�g���A����Ԃ��ǂ���
	static int m_nTutorialCount;			//���ڂ̃`���[�g���A�����̃J�E���g
	static bool m_bUseTutorialUI;			//�`���[�g���A��UI���g���Ă��邩
	static int m_bGameEndTime;				//�Q�[���I������t�F�[�h�J�n�܂ł̎���
	static CPlayer3D *m_pPlayer3D;			//�v���C���[�̃|�C���^
	static CMap2D *m_pMap2D;				//�}�b�v�����̃|�C���^
	static CPlayerLevel *m_pPlayerLevel;	//�v���C���[�̃��x���̃|�C���^
	static CBossLevel *m_pBossLevel;		//�K�w�\���̃{�X�̃|�C���^
	static CBreak_Block3D *m_pBlock3D;		//�u���b�N�̃|�C���^
	static CEdit *m_pEdit;					//�G�f�B�b�g���[�h�̃|�C���^
	static CTutorialUI *m_pTutorialUI;		//�`���[�g���A����ʉ���UI�̃|�C���^
	static CObject2D *m_pTutorialBG;		//�`���[�g���A����ʉ��̔w�i�̃|�C���^
	static CObject2D *m_pTutorialText;		//�`���[�g���A����ʉ��̃e�L�X�g�̃|�C���^
	static CPause *m_pPause;				//�|�[�Y�̃|�C���^
	static CObject2D* m_pScoreText;			//�X�R�A�p�̃e�L�X�g
	static CObject2D* m_pEventText;			//�C�x���g�p�̃e�L�X�g
	static CObject2D *m_pEventTextBG;		//�C�x���g�p�̃e�L�X�g�̔w�i
	static CScore *m_pScore;				//�X�R�A�̃|�C���^
	static bool m_bTextColor;				//�e�L�X�g���Z���Ȃ��Ă��邩�����Ȃ��Ă��邩
	static float m_fTextColor;				//�e�L�X�g�̕s�����x
	static float m_fEventTextColor;			//�C�x���g�e�L�X�g�̕s�����x
};
#endif
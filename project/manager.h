//============================================
//
//	�}�l�[�W�� [manager.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _MANAGER_H_
#define _MANAGER_H_

#include "main.h"
#include "object.h"

//�O���錾
class CRenderer;
class CDebugProc;
class CInputKeyboard;
class CInputJoypad;
class CCamera;
class CLight;
class CTexture;
class CXModel;
class CLevelUP;
class CFade;
class CSound;

//�V�[���N���X
class CScene
{
public:
	CScene();
	~CScene();

	typedef enum
	{
		MODE_TITLE = 0,
		MODE_GAME,
		MODE_RESULT
	}MODE;

	static CScene *Create(MODE mode);
	virtual HRESULT Init(void);
	virtual void Uninit(void);
	virtual void Update(void);
	virtual void Draw(void);

	static void SetMode(MODE mode);
	static MODE GetMode(void) { return m_mode; }

private:
	static MODE m_mode;
};

//�}�l�[�W���N���X
class CManager
{
public:
	CManager();
	~CManager();
	static CManager* GetInstance();

	HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow); 	//�Ԃ�l��HRESULT�Ȃ̂͒��_�o�b�t�@�̐����ȂǂɎ��s�����Ƃ��m�F�̂���
	void Uninit(void);
	void Update(void);
	void Draw(void);

	CRenderer *GetRenderer(void) { return m_pRenderer; }
	CDebugProc *GetDebugProc(void) { return m_pDebugProc; }
	CInputKeyboard *GetInputKeyboard(void) { return m_pInputKeyboard; }
	CInputJoypad *GetInputJoyPad(void) { return m_pInputJoyPad; }
	CCamera *GetCamera(void) { return m_pCamera; }
	CTexture *GetTexture(void) { return m_pTexture; }
	CXModel *GetXModel(void) { return m_pXModel; }
	CScene *GetScene(void) { return m_pScene; }
	CFade *GetFade(void) { return m_Fade; }
	CSound *GetSound(void) { return m_pSound; }
	void SetScene(CScene *Scene) { m_pScene = Scene; }
	void SetLevelUP(CLevelUP *LevelUP) { m_LevelUP = LevelUP; }
	void SetEdit(bool bEdit) { m_bEdit = bEdit; }
	bool GetEdit(void) { return m_bEdit; }
	void SetStop(bool Set) { m_bStop = Set; }
	bool GetStop(void) { return m_bStop; }
	void SetPause(bool Set) { m_Pause = Set; }
	bool GetPause(void) { return m_Pause; }
	void SetEndScore(int Set) { m_EndScore = Set; }
	int GetEndScore(void) { return m_EndScore; }
	void SetEndCombo(int Set) { m_EndCombo = Set; }
	int GetEndCombo(void) { return m_EndCombo; }
	void SetEndFall(int Set) { m_EndFall = Set; }
	int GetEndFall(void) { return m_EndFall; }
	void SetEndDepth(int Set) { m_EndDepth = Set; }
	int GetEndDepth(void) { return m_EndDepth; }
	void SetTutorialStart(bool Set) { m_SetTutorial = Set; }
	bool GetTutorialStart(void) { return m_SetTutorial; }
	void SetSetScoreResult(bool Set) { m_SetScoreResult = Set; }
	bool GetSetScoreResult(void) { return m_SetScoreResult; }
	void SetSetTutorialPad(bool Set) { m_SetJoyPad = Set; }
	bool GetSetTutorialPad(void) { return m_SetJoyPad; }
	void SetPauseOK(bool Set) { m_PauseOK = Set; }
	bool GetPauseOK(void) { return m_PauseOK; }

private:
	static CManager* pManager;

	int m_EndScore;						//�ŏI�I�ȃX�R�A
	int m_EndCombo;						//�ŏI�I�ȃR���{
	int m_EndFall;						//�ŏI�I�ȍō�����������
	int m_EndDepth;						//�ŏI�I�Ȑ[��
	bool m_SetTutorial;					//�G�f�B�b�g���[�h���ǂ���
	bool m_bEdit;						//�G�f�B�b�g���[�h���ǂ���
	bool m_bStop;						//��ʒ�~��Ԃ��ǂ���
	bool m_Pause;						//�|�[�Y��Ԃ��ǂ���
	bool m_SetScoreResult;				//���U���g�ɃX�R�A�������邩�ǂ���
	bool m_SetJoyPad;					//�W���C�p�b�h�ő��삵�Ă��邩�ǂ���
	bool m_PauseOK;						//�|�[�Y�������Ă����v��
	CRenderer *m_pRenderer;				//�����_���[�̃|�C���^
	CDebugProc *m_pDebugProc;			//�f�o�b�O�v���b�N�̃|�C���^
	CInputKeyboard *m_pInputKeyboard;	//�L�[�{�[�h�̃|�C���^
	CInputJoypad *m_pInputJoyPad;		//�W���C�p�b�h�̃|�C���^
	CCamera *m_pCamera;					//�J�����̃|�C���^
	CLight *m_pLight;					//���C�g�̃|�C���^
	CTexture *m_pTexture;				//�e�N�X�`���̃|�C���^
	CXModel *m_pXModel;					//X���f���̃|�C���^
	CScene *m_pScene;					//�V�[���̃|�C���^
	CLevelUP *m_LevelUP;					//���x���A�b�v�̃|�C���^
	CFade *m_Fade;						//�t�F�[�h�̃|�C���^
	CSound *m_pSound;					//�T�E���h�̃|�C���^
};												

#endif
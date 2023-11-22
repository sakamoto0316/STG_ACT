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

	static HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow); 	//�Ԃ�l��HRESULT�Ȃ̂͒��_�o�b�t�@�̐����ȂǂɎ��s�����Ƃ��m�F�̂���
	static void Uninit(void);
	static void Update(void);
	static void Draw(void);

	static CRenderer *GetRenderer(void) { return m_pRenderer; }
	static CDebugProc *GetDebugProc(void) { return m_pDebugProc; }
	static CInputKeyboard *GetInputKeyboard(void) { return m_pInputKeyboard; }
	static CInputJoypad *GetInputJoyPad(void) { return m_pInputJoyPad; }
	static CCamera *GetCamera(void) { return m_pCamera; }
	static CTexture *GetTexture(void) { return m_pTexture; }
	static CXModel *GetXModel(void) { return m_pXModel; }
	static CScene *GetScene(void) { return m_pScene; }
	static CFade *GetFade(void) { return m_Fade; }
	static CSound *GetSound(void) { return m_pSound; }
	static void SetScene(CScene *Scene) { m_pScene = Scene; }
	static void SetLevelUP(CLevelUP *LevelUP) { m_LevelUP = LevelUP; }
	static void SetEdit(bool bEdit) { m_bEdit = bEdit; }
	static bool GetEdit(void) { return m_bEdit; }
	static void SetStop(bool Set) { m_bStop = Set; }
	static bool GetStop(void) { return m_bStop; }
	static void SetPause(bool Set) { m_Pause = Set; }
	static bool GetPause(void) { return m_Pause; }
	static void SetEndScore(int Set) { m_EndScore = Set; }
	static int GetEndScore(void) { return m_EndScore; }
	static void SetEndCombo(int Set) { m_EndCombo = Set; }
	static int GetEndCombo(void) { return m_EndCombo; }
	static void SetEndFall(int Set) { m_EndFall = Set; }
	static int GetEndFall(void) { return m_EndFall; }
	static void SetEndDepth(int Set) { m_EndDepth = Set; }
	static int GetEndDepth(void) { return m_EndDepth; }
	static void SetTutorialStart(bool Set) { m_SetTutorial = Set; }
	static bool GetTutorialStart(void) { return m_SetTutorial; }
	static void SetSetScoreResult(bool Set) { m_SetScoreResult = Set; }
	static bool GetSetScoreResult(void) { return m_SetScoreResult; }
	static void SetSetTutorialPad(bool Set) { m_SetJoyPad = Set; }
	static bool GetSetTutorialPad(void) { return m_SetJoyPad; }
	static void SetPauseOK(bool Set) { m_PauseOK = Set; }
	static bool GetPauseOK(void) { return m_PauseOK; }

private:
	static int m_EndScore;						//�ŏI�I�ȃX�R�A
	static int m_EndCombo;						//�ŏI�I�ȃR���{
	static int m_EndFall;						//�ŏI�I�ȍō�����������
	static int m_EndDepth;						//�ŏI�I�Ȑ[��
	static bool m_SetTutorial;					//�G�f�B�b�g���[�h���ǂ���
	static bool m_bEdit;						//�G�f�B�b�g���[�h���ǂ���
	static bool m_bStop;						//��ʒ�~��Ԃ��ǂ���
	static bool m_Pause;						//�|�[�Y��Ԃ��ǂ���
	static bool m_SetScoreResult;				//���U���g�ɃX�R�A�������邩�ǂ���
	static bool m_SetJoyPad;					//�W���C�p�b�h�ő��삵�Ă��邩�ǂ���
	static bool m_PauseOK;						//�|�[�Y�������Ă����v��
	static CRenderer *m_pRenderer;				//�����_���[�̃|�C���^
	static CDebugProc *m_pDebugProc;			//�f�o�b�O�v���b�N�̃|�C���^
	static CInputKeyboard *m_pInputKeyboard;	//�L�[�{�[�h�̃|�C���^
	static CInputJoypad *m_pInputJoyPad;		//�W���C�p�b�h�̃|�C���^
	static CCamera *m_pCamera;					//�J�����̃|�C���^
	static CLight *m_pLight;					//���C�g�̃|�C���^
	static CTexture *m_pTexture;				//�e�N�X�`���̃|�C���^
	static CXModel *m_pXModel;					//X���f���̃|�C���^
	static CScene *m_pScene;					//�V�[���̃|�C���^
	static CLevelUP *m_LevelUP;					//���x���A�b�v�̃|�C���^
	static CFade *m_Fade;						//�t�F�[�h�̃|�C���^
	static CSound *m_pSound;					//�T�E���h�̃|�C���^
};												

#endif
//============================================
//
//	マネージャ [manager.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _MANAGER_H_
#define _MANAGER_H_

#include "main.h"
#include "object.h"

//前方宣言
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

//シーンクラス
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

//マネージャクラス
class CManager
{
public:
	CManager();
	~CManager();

	static HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow); 	//返り値がHRESULTなのは頂点バッファの生成などに失敗したとき確認のため
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
	static int m_EndScore;						//最終的なスコア
	static int m_EndCombo;						//最終的なコンボ
	static int m_EndFall;						//最終的な最高速落下時間
	static int m_EndDepth;						//最終的な深さ
	static bool m_SetTutorial;					//エディットモードかどうか
	static bool m_bEdit;						//エディットモードかどうか
	static bool m_bStop;						//画面停止状態かどうか
	static bool m_Pause;						//ポーズ状態かどうか
	static bool m_SetScoreResult;				//リザルトにスコア情報を入れるかどうか
	static bool m_SetJoyPad;					//ジョイパッドで操作しているかどうか
	static bool m_PauseOK;						//ポーズを押しても大丈夫か
	static CRenderer *m_pRenderer;				//レンダラーのポインタ
	static CDebugProc *m_pDebugProc;			//デバッグプロックのポインタ
	static CInputKeyboard *m_pInputKeyboard;	//キーボードのポインタ
	static CInputJoypad *m_pInputJoyPad;		//ジョイパッドのポインタ
	static CCamera *m_pCamera;					//カメラのポインタ
	static CLight *m_pLight;					//ライトのポインタ
	static CTexture *m_pTexture;				//テクスチャのポインタ
	static CXModel *m_pXModel;					//Xモデルのポインタ
	static CScene *m_pScene;					//シーンのポインタ
	static CLevelUP *m_LevelUP;					//レベルアップのポインタ
	static CFade *m_Fade;						//フェードのポインタ
	static CSound *m_pSound;					//サウンドのポインタ
};												

#endif
//============================================
//
//	�\�����[�V����[main.cpp]
//	Author:sakamoto kai
//
//============================================
#include "main.h"
#include "manager.h"

//�}�N����`
#define CLASS_NAME "TEST"			//�E�C���h�E�N���X�̖��O
#define WINDOW_NAME "�@�`Square Fall�`�@"	//�E�C���h�E�̖��O(�L���v�V�����ɕ\��)

//�v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//�O���[�o���ϐ�
int g_nCountFPS = 0;						//FPS�J�E���^
bool g_bDispDebug = false;					//�f�o�b�O�\����ON/OFF

//============================================
//���C���֐�
//============================================
int	WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hinstancePrev, LPSTR lpCmdLine, int nCmdShow)
{
	//�I�����Ƀ��������[�N���o��
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CManager *pManager = NULL;	//�}�l�[�W���̃C���X�^���X

	DWORD dwCurrentTime;	//���ݎ���
	DWORD dwExecLastTime;	//�Ō�ɏ�����������
	DWORD dwFrameCount;		//�t���[���J�E���g
	DWORD dwFPSLastTime;	//�Ō��FPS���v����������

	WNDCLASSEX wcex =
	{
		sizeof(WNDCLASSEX),					//WNDCLASSEX�̃������T�C�Y
		CS_CLASSDC,							//�E�C���h�E�̃X�^�C��
		WindowProc,							//�E�C���h�E�v���V�[�W��
		0,									//0�ɂ���(�ʏ�͎g�p���Ȃ�)
		0,									//0�ɂ���(�ʏ�͎g�p���Ȃ�)
		hInstance,							//�C���X�^���X�n���h��
		LoadIcon(NULL,IDI_APPLICATION),		//�^�X�N�o�[�̃A�C�R��
		LoadCursor(NULL,IDC_ARROW),			//�}�E�X�J�[�\��
		(HBRUSH)(COLOR_WINDOW + 1),			//�N���C�A���g�̈�̔w�i�F
		NULL,								//���j���[�o�[
		CLASS_NAME,							//�E�C���h�E�N���X�̖��O
		LoadIcon(NULL,IDI_APPLICATION),		//�t�@�C���̃A�C�R��
	};
	HWND hWnd;
	MSG msg;
	RECT rect = { 0,0,SCREEN_WIDTH ,SCREEN_HEIGHT };

	//�E�C���h�E�N���X�̓o�^
	RegisterClassEx(&wcex);

	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

	//�E�C���h�E�𐶐�
	hWnd = CreateWindowEx(0,	//�g���E�C���h�E�X�^�C��
		CLASS_NAME,				//�E�C���h�E�N���X�̖��O
		WINDOW_NAME,			//�E�C���h�E�̖��O
		WS_OVERLAPPEDWINDOW,	//�E�C���h�E�X�^�C��
		CW_USEDEFAULT,			//�E�C���h�E�̍���X���W
		CW_USEDEFAULT,			//�E�C���h�E�̍���Y���W
		SCREEN_WIDTH,			//�E�C���h�E�̕�
		SCREEN_HEIGHT,			//�E�C���h�E�̍���
		NULL,					//�e�E�C���h�E�̃n���h��
		NULL,					//���j���[�n���h���܂��͎q�E�C���h�EID
		hInstance,				//�C���X�^���X�n���h��
		NULL);					//�E�C���h�E�쐬�f�[�^
								//�E�C���h�E�̕\��
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	dwFrameCount = 0;
	dwFPSLastTime = timeGetTime();

	//����\��ݒ�
	timeBeginPeriod(1);

	dwCurrentTime = 0;				//����������
	dwExecLastTime = timeGetTime();	//���ݎ���������(�ۑ�)

	srand(dwExecLastTime);

	//�}�l�[�W���̐���
	if (pManager == NULL)
	{
		pManager = CManager::GetInstance();
	}

	//������
	if (pManager != NULL)
	{
		if (FAILED(pManager->Init(hInstance, hWnd, TRUE)))
		{//���������������s�����ꍇ
			return -1;
		}
	}

	//���b�Z�[�W���[�v
	while (1)
	{//Windows�̏���
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0)
		{
			if (msg.message == WM_QUIT)
			{//WM_QUIT���b�Z�[�W���󂯎�����烋�[�v�𔲂���
				break;
			}
			else
			{
				//���b�Z�[�W�̐ݒ�
				TranslateMessage(&msg);	//�E�C���h�E�̕\����Ԃ�ݒ�
				DispatchMessage(&msg);	//�N���C�A���g�̈���X�V
			}
		}
		else
		{//DirectX�̏���
			dwCurrentTime = timeGetTime();		//���ݎ���������

			if ((dwCurrentTime - dwFPSLastTime) >= 500)
			{//0.5�b�o��
			 //FPS���v��
				g_nCountFPS = (dwFrameCount * 1000) / (dwCurrentTime - dwFPSLastTime);
				dwFPSLastTime = dwCurrentTime;	//FPS���v������������ۑ�
				dwFrameCount = 0;				//�t���[���J�E���g���N���A
			}

			if (dwCurrentTime - dwExecLastTime >= (1000 / 60))
			{//�U�O���̂P�b�o��
				dwExecLastTime = dwCurrentTime;	//�����J�n�̎���[���ݎ���]��ۑ�

				if (pManager != NULL)
				{
					//�X�V����
					pManager->Update();

					//�`�揈��
					pManager->Draw();
				}

				dwFrameCount++;					//�t���[���J�E���g�����Z
			}
		}
	}

	if (pManager != NULL)
	{
		//�I������
		pManager->Uninit();

		//���������
		delete pManager;
		pManager = NULL;
	}

	//����\��߂�
	timeEndPeriod(1);

	//�E�C���h�E�N���X�̓o�^������
	UnregisterClass(CLASS_NAME, wcex.hInstance);

	return (int)msg.wParam;
}

//====================================================================
//�E�C���h�E�v���V�[�W��
//====================================================================
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	char aString[256] = "test";		//�`�悷��e�L�X�g���i�[
	const RECT rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };	//�E�C���h�E�̗̈�i��`�j

	int nID;						//�Ԃ�l���i�[
	HWND hWndButtonFinish = 0;			//�I���{�^���̃E�C���h�E�n���h��(���ʎq)

	switch (uMsg)
	{
	case WM_DESTROY:	//�E�C���h�E�j���̃��b�Z�[�W
						//WM_QUIT���b�Z�[�W�𑗂�B
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:	//�L�[�����̃��b�Z�[�W
		switch (wParam)
		{
		case VK_ESCAPE: //[ESC]�L�[�������ꂽ
			nID = MessageBox(NULL, "�I�����܂����H", "�I�����b�Z�[�W", MB_YESNO);

			if (nID == IDYES)
			{
				//�E�C���h�E��j������(WM_DESTROY���b�Z�[�W�𑗂�)
				DestroyWindow(hWnd);
				break;
			}
			break;
		}

		//�I���{�^���ɕ\�����镶�����ݒ�
		SetWindowText(hWndButtonFinish, "�I��");

		break;

	case WM_CLOSE:	//���鉟���̃��b�Z�[�W
		nID = MessageBox(NULL, "�I�����܂����H", "�I�����b�Z�[�W", MB_YESNO);

		if (nID == IDYES)
		{
			//�E�C���h�E��j������(WM_DESTROY���b�Z�[�W�𑗂�)
			DestroyWindow(hWnd);
		}
		else
		{
			return 0;	//�O��Ԃ��Ȃ��ƏI�����Ă��܂�
		}

		break;

	case WM_LBUTTONDOWN: //�}�E�X���N���b�N�̃��b�Z�[�W
						 //�ΏۃE�C���h�E�Ƀt�H�[�J�X�����킹��
		SetFocus(hWnd);
		break;

	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);	//����̏�����Ԃ�
}

int GetFps(void)
{
	return g_nCountFPS;
}
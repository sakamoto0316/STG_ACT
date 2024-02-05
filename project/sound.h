#ifndef _SOUND_H_
#define _SOUND_H_

#include "main.h"

class CSound
{
public:
	CSound();
	~CSound();

	//*****************************************************************************
	// �T�E���h�ꗗ
	//*****************************************************************************
	typedef enum
	{
		SOUND_LABEL_BGM_TITLE = 0,			// BGM0						
		SOUND_LABEL_BGM_TUTORIAL,			// BGM1
		SOUND_LABEL_BGM_GAME,				// BGM2
		SOUND_LABEL_BGM_RESULT,				// BGM3
		SOUND_LABEL_SE_ATTACK_NORMAL,		// �U��
		SOUND_LABEL_SE_ATTACK_NOBULLET,		// �e�؂�̎��̉�
		SOUND_LABEL_SE_BREAK_BLOCK,			// �u���b�N�j��
		SOUND_LABEL_SE_PLAYER_DAMAGE,		// �v���C���[�_���[�W
		SOUND_LABEL_SE_ENEMY_DAMAGE,		// �G�_���[�W
		SOUND_LABEL_SE_ULT,					// �K�E�Z
		SOUND_LABEL_SE_CAMERA_WAVE,			// �n����
		SOUND_LABEL_SE_SELECT_PUSH,			// �I����
		SOUND_LABEL_SE_ENTER_PUSH,			// ���艹
		SOUND_LABEL_SE_PLAYER_TEXT,			// �v���C���[�̐����o����
		SOUND_LABEL_SE_PLAYER_JUMP,			// �v���C���[�̃W�����v��
		SOUND_LABEL_SE_WARNING,				// �x����
		SOUND_LABEL_SE_LEVELUP,				// ���x���A�b�v��
		SOUND_LABEL_MAX,
	} SOUND_LABEL;

	//*****************************************************************************
	// �����o�֐��錾
	//*****************************************************************************
	HRESULT InitSound(HWND hWnd);
	void UninitSound(void);
	HRESULT PlaySound(SOUND_LABEL label);
	void StopSound(SOUND_LABEL label);
	void StopSound(void);

private:

	//*****************************************************************************
	// �T�E���h���̍\���̒�`
	//*****************************************************************************
	typedef struct
	{
		char *pFilename;	// �t�@�C����
		int nCntLoop;		// ���[�v�J�E���g
	} SOUNDINFO;

	//*****************************************************************************
	// �����o�֐��錾
	//*****************************************************************************
	HRESULT CheckChunk(HANDLE hFile, DWORD format, DWORD *pChunkSize, DWORD *pChunkDataPosition);
	HRESULT ReadChunkData(HANDLE hFile, void *pBuffer, DWORD dwBuffersize, DWORD dwBufferoffset);

	//*****************************************************************************
	// �����o�ϐ��錾
	//*****************************************************************************
	IXAudio2 *m_pXAudio2;									// XAudio2�I�u�W�F�N�g�ւ̃C���^�[�t�F�C�X
	IXAudio2MasteringVoice *m_pMasteringVoice;				// �}�X�^�[�{�C�X
	IXAudio2SourceVoice *m_apSourceVoice[SOUND_LABEL_MAX];	// �\�[�X�{�C�X
	BYTE *m_apDataAudio[SOUND_LABEL_MAX];					// �I�[�f�B�I�f�[�^
	DWORD m_aSizeAudio[SOUND_LABEL_MAX];					// �I�[�f�B�I�f�[�^�T�C�Y

	// �T�E���h�̏��
	static SOUNDINFO m_aSoundInfo[SOUND_LABEL_MAX];
};
#endif

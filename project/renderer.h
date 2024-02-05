//============================================
//
//	�����_���[[renderer.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _RENSERER_H_
#define _RENSERER_H_

#include "main.h"

//�����_���[�N���X
class CRenderer
{
public:
	CRenderer();	//�R���X�g���N�^
	~CRenderer();	//�f�X�g���N�^

	//�����_���[�̏���
	HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow); 	//�Ԃ�l��HRESULT�Ȃ̂͒��_�o�b�t�@�̐����ȂǂɎ��s�����Ƃ��m�F�̂���
	void Uninit(void);
	void Update(void);
	void Draw(void);
	LPDIRECT3DDEVICE9 GetDevice(void);

private:

	LPDIRECT3D9 m_pD3D;					//Direct3D�I�u�W�F�N�g�ւ̃|�C���^
	LPDIRECT3DDEVICE9 m_pD3DDevice;		//Direct3D�f�o�C�X�ւ̃|�C���^
};

#endif
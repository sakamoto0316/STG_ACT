//============================================
//
//	�J�����̏��� [camera.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "main.h"

//�J�����N���X
class CCamera
{
public:
	CCamera();
	~CCamera();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void SetCamera(void);
	void SetCameraPosY(float PosY) { m_EventPosY = PosY; }
	void ResetCamera(void);
	void SetBib(bool Set) { m_bBib = Set; }
	float GetPosY(void) { return m_posR.y; }

private:
	D3DXMATRIX m_mtxView;		//�r���[�}�g���b�N�X
	D3DXMATRIX m_mtxProjection;	//�v���W�F�N�V�����}�g���b�N�X
	D3DXVECTOR3 m_posV;			//���_
	D3DXVECTOR3 m_posR;			//�����_
	D3DXVECTOR3 m_vecU;			//������x�N�g��
	D3DXVECTOR3 m_rot;			//���݂̌���
	D3DXVECTOR3 m_rotOld;		//�ߋ��̌���
	D3DXVECTOR3 m_posVDest;		//�ړI�̎��_
	D3DXVECTOR3 m_posRDest;		//�ړI�̒����_
	float m_CameraDistance;		//�����_�ƃJ�����̋���
	float m_EventPosY;			//�C�x���g���̃J�����̍���
	bool m_bBib;				//�J�������U�����邩�ǂ���
	float m_fBibPowor;			//�J�����U���̋���
};

#endif
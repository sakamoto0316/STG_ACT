//============================================
//
//	���C�g�̏��� [light.cpp]
//	Author:sakamoto kai
//
//============================================
#include "light.h"
#include "manager.h"
#include "renderer.h"

//====================================================================
//�R���X�g���N�^
//====================================================================
CLight::CLight()
{

}

//====================================================================
//�f�X�g���N�^
//====================================================================
CLight::~CLight()
{

}

//====================================================================
//�J�����̏���������
//====================================================================
HRESULT CLight::Init(void)
{
	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();
	D3DXVECTOR3 vecDir[MAX_LIGHT];	//�ݒ�p�����x�N�g��

	//���C�g�̏����N���A����
	ZeroMemory(&m_aLight, sizeof(D3DLIGHT9));

	for (int nCntlight = 0; nCntlight < MAX_LIGHT; nCntlight++)
	{
		//���C�g�̎�ނ�ݒ�
		m_aLight[nCntlight].Type = D3DLIGHT_DIRECTIONAL;

		//���C�g�̊g�U����ݒ�
		m_aLight[nCntlight].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		//���C�g�̕�����ݒ�
		switch (nCntlight)
		{
		case 0:
			vecDir[nCntlight] = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
			break;
		case 1:
			vecDir[nCntlight] = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);
			break;
		case 2:
			vecDir[nCntlight] = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
			break;
		}

		D3DXVec3Normalize(&vecDir[nCntlight], &vecDir[nCntlight]);	//�x�N�g���𐳋K������
		m_aLight[nCntlight].Direction = vecDir[nCntlight];

		//���C�g��ݒ肷��
		pDevice->SetLight(nCntlight, &m_aLight[nCntlight]);

		//���C�g��L���ɂ���
		pDevice->LightEnable(nCntlight, TRUE);
	}

	return S_OK;
}

//====================================================================
//�J�����̏I������
//====================================================================
void CLight::Uninit(void)
{

}

//====================================================================
//�J�����̍X�V����
//====================================================================
void CLight::Update(void)
{

}
//============================================
//
//	�e�N�X�`���̊Ǘ� [texture.cpp]
//	Author:sakamoto kai
//
//============================================
#include "texture.h"
#include "renderer.h"
#include "manager.h"
#include "Xmodel.h"

//�ÓI�����o�ϐ��錾
int CTexture::m_NumAll = 0;
//const char *CTexture::c_apTexturename[] =
//{
//	"data\\TEXTURE\\Player00.png",		//�v���C���[
//	"data\\TEXTURE\\ENEMY00.png",		//�G
//	"data\\TEXTURE\\block000.jpg",		//���ʂ̃u���b�N
//	"data\\TEXTURE\\block001.png",		//����u���b�N
//	"data\\TEXTURE\\Life.png",			//���C�t
//	"data\\TEXTURE\\rain.png",			//������
//	"data\\TEXTURE\\watch.png",			//���v
//	"data\\TEXTURE\\Bullet00.png",		//�e
//	"data\\TEXTURE\\Effect000.jpg",		//�G�t�F�N�g
//	"data\\TEXTURE\\magic001.png",		//����
//	"data\\TEXTURE\\Number00.png",		//����
//	"data\\TEXTURE\\Test.jpg",			//�e�X�g�p
//	"data\\TEXTURE\\0.png",				//�e�X�g�u���b�N1
//	"data\\TEXTURE\\1.png",				//�e�X�g�u���b�N2
//	"data\\TEXTURE\\3.png",				//�e�X�g�u���b�N3
//	"data\\TEXTURE\\5.png",				//�e�X�g�u���b�N4
//	"data\\TEXTURE\\7.png",				//�e�X�g�u���b�N5
//	"data\\TEXTURE\\9.png",				//�e�X�g�u���b�N6
//	"data\\TEXTURE\\19.png",			//�e�X�g�u���b�N7
//	"data\\TEXTURE\\37.png",			//�e�X�g�u���b�N8
//	"data\\TEXTURE\\123.png",			//�e�X�g�u���b�N9
//	"data\\TEXTURE\\147.png",			//�e�X�g�u���b�N10
//	"data\\TEXTURE\\369.png",			//�e�X�g�u���b�N11
//	"data\\TEXTURE\\789.png",			//�e�X�g�u���b�N12
//	"data\\TEXTURE\\12347.png",			//�e�X�g�u���b�N13
//	"data\\TEXTURE\\12369.png",			//�e�X�g�u���b�N14
//	"data\\TEXTURE\\14789.png",			//�e�X�g�u���b�N15
//	"data\\TEXTURE\\36789.png",			//�e�X�g�u���b�N16
//};

const char *CTexture::c_apTexturename[] = {};

//====================================================================
//�R���X�g���N�^
//====================================================================
CTexture::CTexture()
{
	for (int nCntTex = 0; nCntTex < MAX_TEXTURE; nCntTex++)
	{
		m_apTexture[nCntTex] = NULL;
	}
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CTexture::~CTexture()
{

}

//====================================================================
//�ǂݍ���
//====================================================================
HRESULT CTexture::Load(void)
{
	////�f�o�C�X�̎擾
	//LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	//for (int nCntTex = 0; nCntTex < MAX_TEXTURE; nCntTex++)
	//{
	//	//�e�N�X�`���̓ǂݍ���
	//	if (FAILED(D3DXCreateTextureFromFile(pDevice,
	//		c_apTexturename[nCntTex],
	//		&m_apTexture[nCntTex])))
	//	{
	//		if (c_apTexturename[nCntTex] == NULL)
	//		{
	//			m_NumAll = nCntTex;
	//			return S_OK;
	//		}
	//		else
	//		{
	//			return E_FAIL;
	//		}
	//	}
	//	else
	//	{
	//		int a = 0;
	//	}
	//}

	return S_OK;
}

//====================================================================
//�j��
//====================================================================
void CTexture::Unload(void)
{
	for (int nCntTex = 0; nCntTex < m_NumAll; nCntTex++)
	{
		//�e�N�X�`���̔j��
		if (m_apTexture[nCntTex] != NULL)
		{
			m_apTexture[nCntTex]->Release();
			m_apTexture[nCntTex] = NULL;
		}
	}
}

//====================================================================
//�e�N�X�`���̔ԍ��w��
//====================================================================
int CTexture::Regist(const char *pFilename)
{
	for (int nCntTex = 0; nCntTex < m_NumAll; nCntTex++)
	{
		if (strcmp(c_apTexturename[nCntTex], pFilename) == 0)
		{
			return nCntTex;
		}
	}

	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

		//�e�N�X�`���̓ǂݍ���
	if (SUCCEEDED(D3DXCreateTextureFromFile(pDevice,
		pFilename,
		&m_apTexture[m_NumAll])))
	{
		if (c_apTexturename[m_NumAll] == NULL)
		{
			c_apTexturename[m_NumAll] = pFilename;
			m_NumAll++;
			return m_NumAll - 1;
		}
		else
		{
			return -1;
		}
	}

	return -1;
}

//====================================================================
//�e�N�X�`���̔ԍ��w��
//====================================================================
void CTexture::XModelRegist(int *nTexIdx, int nXModelIdx)
{
	int nCheck = -1;

	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();
	D3DXMATERIAL *pMat;	//�}�e���A���ւ̃|�C���^

	//X���f���̎擾
	CXModel::XModel *pXmodel = CManager::GetInstance()->GetXModel()->GetXModel(nXModelIdx);

	//�}�e���A�����ɑ΂���|�C���^������
	pMat = (D3DXMATERIAL*)pXmodel->m_pBuffMat->GetBufferPointer();

	for (int nCntMat = 0; nCntMat < (int)pXmodel->m_dwNumMat; nCntMat++)
	{
		nCheck = -1;
		if (pMat[nCntMat].pTextureFilename != NULL)
		{
			for (int nCntTex = 0; nCntTex < m_NumAll; nCntTex++)
			{
				if (strcmp(c_apTexturename[nCntTex], pMat[nCntMat].pTextureFilename) == 0)
				{
					nTexIdx[nCntMat] = nCntTex;
					nCheck = nCntTex;
				}
			}

			if (nTexIdx[nCntMat] != nCheck)
			{
				//�e�N�X�`���̓ǂݍ���
				if (SUCCEEDED(D3DXCreateTextureFromFile(pDevice,
					pMat[nCntMat].pTextureFilename,
					&m_apTexture[m_NumAll])))
				{
					c_apTexturename[m_NumAll] = pMat[nCntMat].pTextureFilename;
					m_NumAll++;
					nTexIdx[nCntMat] = m_NumAll - 1;
				}
			}
		}
		else
		{
			m_apTexture[m_NumAll] = NULL;
			nTexIdx[nCntMat] = -1;
		}
	}
}

//====================================================================
//�w��̃e�N�X�`����Ԃ�
//====================================================================
LPDIRECT3DTEXTURE9 CTexture::GetAddress(int nIdx)
{
	return m_apTexture[nIdx];
}
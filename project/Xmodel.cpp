//============================================
//
//	X���f���̊Ǘ� [Xmodel.cpp]
//	Author:sakamoto kai
//
//============================================
#include "XModel.h"
#include "renderer.h"
#include "manager.h"

//�ÓI�����o�ϐ��錾
int CXModel::m_NumAll = 0;
//const char *CXModel::c_apModelname[] =
//{
//	"data\\MODEL\\Player00.x",
//	"data\\MODEL\\block00.x",
//};

const char *CXModel::c_apModelname[] = {};

//====================================================================
//�R���X�g���N�^
//====================================================================
CXModel::CXModel()
{
	for (int nCntModel = 0; nCntModel < MAX_MODEL; nCntModel++)
	{
		m_apXModel[nCntModel].m_pBuffMat = NULL;
		m_apXModel[nCntModel].m_dwNumMat = NULL;
		m_apXModel[nCntModel].m_pMesh = NULL;
	}
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CXModel::~CXModel()
{

}

//====================================================================
//�ǂݍ���
//====================================================================
HRESULT CXModel::Load(void)
{
	////�f�o�C�X�̎擾
	//LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	//for (int nCntModel = 0; nCntModel < MAX_MODEL; nCntModel++)
	//{

	//	//X�t�@�C���̓ǂݍ���
	//	if (FAILED(D3DXLoadMeshFromX(c_apModelname[nCntModel],
	//		D3DXMESH_SYSTEMMEM,
	//		pDevice,
	//		NULL,
	//		&m_apXModel[nCntModel].m_pBuffMat,
	//		NULL,
	//		&m_apXModel[nCntModel].m_dwNumMat,
	//		&m_apXModel[nCntModel].m_pMesh)))
	//	{
	//		if (c_apModelname[nCntModel] == NULL)
	//		{
	//			m_NumAll = nCntModel;
	//			return S_OK;
	//		}
	//		else
	//		{
	//			return E_FAIL;
	//		}
	//	}
	//}

	return S_OK;
}

//====================================================================
//�j��
//====================================================================
void CXModel::Unload(void)
{
	for (int nCntModel = 0; nCntModel < m_NumAll; nCntModel++)
	{
		//�o�b�t�@�̔j��
		if (m_apXModel[nCntModel].m_pBuffMat != NULL)
		{
			m_apXModel[nCntModel].m_pBuffMat->Release();
			m_apXModel[nCntModel].m_pBuffMat = NULL;
		}

		//���b�V���̔j��
		if (m_apXModel[nCntModel].m_pMesh != NULL)
		{
			m_apXModel[nCntModel].m_pMesh->Release();
			m_apXModel[nCntModel].m_pMesh = NULL;
		}
	}
}

//====================================================================
//X���f���̔ԍ��w��
//====================================================================
int CXModel::Regist(const char *pFilename)
{
	for (int nCntModel = 0; nCntModel < m_NumAll; nCntModel++)
	{
		if (strcmp(c_apModelname[nCntModel], pFilename) == 0)
		{
			return nCntModel;
		}
	}

	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	//X�t�@�C���̓ǂݍ���
	if (SUCCEEDED(D3DXLoadMeshFromX(pFilename,
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&m_apXModel[m_NumAll].m_pBuffMat,
		NULL,
		&m_apXModel[m_NumAll].m_dwNumMat,
		&m_apXModel[m_NumAll].m_pMesh)))
	{
		if (c_apModelname[m_NumAll] == NULL)
		{
			c_apModelname[m_NumAll] = pFilename;
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
//�w��̃e�N�X�`����Ԃ�
//====================================================================
void CXModel::GetXModelInfo(LPD3DXBUFFER *pBuffMat, DWORD *dwNumMat, LPD3DXMESH *pMesh, int nIdx)
{
	*pBuffMat = m_apXModel[nIdx].m_pBuffMat;
	*dwNumMat = m_apXModel[nIdx].m_dwNumMat;
	*pMesh = m_apXModel[nIdx].m_pMesh;
}
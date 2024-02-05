//============================================
//
//	�u���b�N��UI�̏��� [BlockUI.cpp]
//	Author:sakamoto kai
//
//============================================
#include "BlockUI.h"
#include "input.h"
#include "renderer.h"
#include "manager.h"
#include "texture.h"
#include "XModel.h"
#include "debugproc.h"
#include "title.h"

//�}�N����`
#define NUMBER_WIGHT (200.0f)		//����
#define NUMBER_HEIGHT (50.0f)		//�c��

LPD3DXMESH CBlockUI::m_pMesh = NULL;				//���b�V��(���_���)�ւ̃|�C���^
LPD3DXBUFFER CBlockUI::m_pBuffMat = NULL;			//�}�e���A���ւ̃|�C���^
DWORD CBlockUI::m_dwNumMat = NULL;					//�}�e���A���̐�
int CBlockUI::m_nIdxXModel = NULL;					//�}�e���A���̐�

//====================================================================
//�R���X�g���N�^
//====================================================================
CBlockUI::CBlockUI(int nPriority) : CObjectXtex(nPriority)
{
	SetPos(D3DXVECTOR3(640.0f, 360.0f, 0.0f));
	SetWight(NUMBER_WIGHT);
	SetHeight(NUMBER_HEIGHT);
	SetTexOne(true);
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CBlockUI::~CBlockUI()
{

}

//====================================================================
//��������
//====================================================================
CBlockUI *CBlockUI::Create()
{
	CBlockUI *pNumber = NULL;

	if (pNumber == NULL)
	{
		//�I�u�W�F�N�g2D�̐���
		pNumber = new CBlockUI();
	}

	//X�t�@�C���̊��蓖��
	CXModel *pXModel = CManager::GetInstance()->GetXModel();
	m_nIdxXModel = pXModel->Regist("data\\MODEL\\BlockUI01.x");
	pXModel->GetXModelInfo(&m_pBuffMat, &m_dwNumMat, &m_pMesh, m_nIdxXModel);
	pNumber->BindFile(m_pMesh, m_pBuffMat, m_dwNumMat);

	//�I�u�W�F�N�g�̏���������
	if (FAILED(pNumber->Init()))
	{//���������������s�����ꍇ
		return NULL;
	}

	return pNumber;
}

//====================================================================
//����������
//====================================================================
HRESULT CBlockUI::Init(void)
{
	CTexture *pTexture = CManager::GetInstance()->GetTexture();;
	m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\Test.jpg");

	SetType(CObject::TYPE_BLOCKUI);

	CObjectXtex::Init();

	return S_OK;
}

//====================================================================
//�I������
//====================================================================
void CBlockUI::Uninit(void)
{
	CObjectXtex::Uninit();
}

//====================================================================
//�X�V����
//====================================================================
void CBlockUI::Update(void)
{
	//�e�N�X�`���̎擾
	CTexture *pTexture = CManager::GetInstance()->GetTexture();

	switch (m_MyCount)
	{
	case 0:
		m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\GameStart.png");
		break;

	case 1:
		m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\TUTORIAL.png");
		break;

	case 2:
		m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\RANKING.png");
		break;

	default:
		break;
	}

	CObjectXtex::Update();

	//�f�o�b�O�\��
	CManager::GetInstance()->GetDebugProc()->Print("�u���b�N��X:[%f]\n", GetPos().x);
	CManager::GetInstance()->GetDebugProc()->Print("�u���b�N��Y:[%f]\n", GetPos().y);
}

//====================================================================
//�`�揈��
//====================================================================
void CBlockUI::Draw(void)
{
	CObjectXtex::Draw();
}

//====================================================================
//�����蔻�菈��
//====================================================================
bool CBlockUI::Collision(D3DXVECTOR3 *pPos, D3DXVECTOR3 pPosOld, D3DXVECTOR3 *pMove, float fHeight, float fWidth, bool bX)
{
	bool bOn = false;

	float myWight = GetWight() * 0.5f;
	float myHeight = GetHeight() * 0.5f;
	D3DXVECTOR3 myPos = GetPos();


	if (bX == false)
	{
		if (
			(pPos->y - fHeight < myPos.y + myHeight &&
				pPosOld.y - fHeight >= myPos.y + myHeight) &&
			pPos->x + fWidth > myPos.x - myWight &&
			pPos->x - fWidth < myPos.x + myWight
			)
		{//�ォ��߂荞�񂾎�
			bOn = true;
			pPos->y = myPos.y + myHeight + fHeight;		//�u���b�N�̂����ɂ�������
			pMove->y = 0.0f;					//�ړ��ʂ��O�ɂ���
		}

		if (
			(pPos->y + fHeight > myPos.y - myHeight &&
				pPosOld.y + fHeight <= myPos.y - myHeight) &&
			pPos->x + fWidth > myPos.x - myWight &&
			pPos->x - fWidth < myPos.x + myWight
			)
		{//������߂荞�񂾎�
			pPos->y = myPos.y - myHeight - fHeight;		//�u���b�N�̉��Ŏ~�߂�
			pMove->y = 0.0f;					//�ړ��ʂ��O�ɂ���
		}
	}
	else
	{
		if (
			(pPos->x + fWidth > myPos.x - myWight &&
				pPosOld.x + fWidth <= myPos.x - myWight) &&
			pPos->y + fHeight > myPos.y - myHeight &&
			pPos->y - fHeight < myPos.y + myHeight
			)
		{//������߂荞�񂾎�
			pPos->x = myPos.x - myWight - fWidth;		//�u���b�N�̍��Ŏ~�߂�
			pMove->x = 0.0f;					//�ړ��ʂ��O�ɂ���
		}

		if (
			(pPos->x - fWidth < myPos.x + myWight &&
				pPosOld.x - fWidth >= myPos.x + myWight) &&
			pPos->y + fHeight > myPos.y - myHeight &&
			pPos->y - fHeight< myPos.y + myHeight
			)
		{//�E����߂荞�񂾎�
			pPos->x = myPos.x + myWight + fWidth;		//�u���b�N�̉E�Ŏ~�߂�
			pMove->x = 0.0f;					//�ړ��ʂ��O�ɂ���
		}
	}

	return bOn;
}

//====================================================================
//�����蔻�菈��
//====================================================================
void CBlockUI::Hit(D3DXVECTOR3 pos, int Damage)
{
	CTitle::SetSelectColor(m_MyCount);
}
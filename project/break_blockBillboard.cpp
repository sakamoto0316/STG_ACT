//============================================
//
//	�j��\�u���b�N�̏��� [break_blockBillboard.cpp]
//	Author:sakamoto kai
//
//============================================
#include "break_blockBillboard.h"
#include "renderer.h"
#include "manager.h"
//#include "map2D.h"
#include "texture.h"
#include "DebugNumber3D.h"

//�}�N����`
#define BLOCK_WIGHT (40.0f)		//����
#define BLOCK_HEIGHT (40.0f)	//�c��

bool CBreak_BlockBillboard::m_bUse[100][SET_BLOCK_WIGHT][SET_BLOCK_HEIGHT] = {};
//====================================================================
//�R���X�g���N�^
//====================================================================
CBreak_BlockBillboard::CBreak_BlockBillboard(int nPriority) : CObjectBillboard(nPriority)
{
	SetWight(BLOCK_WIGHT);
	SetHeight(BLOCK_HEIGHT);
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CBreak_BlockBillboard::~CBreak_BlockBillboard()
{

}

//====================================================================
//��������
//====================================================================
CBreak_BlockBillboard *CBreak_BlockBillboard::Create()
{
	CBreak_BlockBillboard *pPlayer = NULL;

	if (pPlayer == NULL)
	{
		//�I�u�W�F�N�g2D�̐���
		pPlayer = new CBreak_BlockBillboard();
	}

	//�I�u�W�F�N�g�̏���������
	if (FAILED(pPlayer->Init()))
	{//���������������s�����ꍇ
		return NULL;
	}

	return pPlayer;
}

//====================================================================
//����������
//====================================================================
HRESULT CBreak_BlockBillboard::Init(void)
{
#if NUM == 1
	m_pWNumber = CDebugNumber3D::Create();
	m_pWNumber->SetWight(20.0f);
	m_pWNumber->SetHeight(20.0f);
	m_pWNumber->SetColor(D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f));

	m_pHNumber = CDebugNumber3D::Create();
	m_pHNumber->SetWight(20.0f);
	m_pHNumber->SetHeight(20.0f);
	m_pHNumber->SetColor(D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f));

	m_pCNumber = CDebugNumber3D::Create();
	m_pCNumber->SetWight(20.0f);
	m_pCNumber->SetHeight(20.0f);
	m_pCNumber->SetColor(D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f));

	m_pBNumber = CDebugNumber3D::Create();
	m_pBNumber->SetWight(20.0f);
	m_pBNumber->SetHeight(20.0f);
	m_pBNumber->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
#endif // NUM

	CTexture *pTexture = CManager::GetInstance()->GetTexture();;
	m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\block001.png");

	SetType(CObject::TYPE_BREAKBLOCK3D);

	CObjectBillboard::Init();

	return S_OK;
}

//====================================================================
//�I������
//====================================================================
void CBreak_BlockBillboard::Uninit(void)
{
	m_bUse[m_CreateNumber][m_WightNumber][m_HeightNumber] = false;

	CObjectBillboard::Uninit();
}

//====================================================================
//�X�V����
//====================================================================
void CBreak_BlockBillboard::Update(void)
{
#if NUM == 1
	if (m_pWNumber != NULL)
	{
		D3DXVECTOR3 pos = GetPos();
		m_pWNumber->SetNumber(m_WightNumber);
		m_pWNumber->SetPos(D3DXVECTOR3(pos.x - 10.0f, pos.y - 10.0f, pos.z));
	}

	if (m_pHNumber != NULL)
	{
		D3DXVECTOR3 pos = GetPos();
		m_pHNumber->SetNumber(m_HeightNumber);
		m_pHNumber->SetPos(D3DXVECTOR3(pos.x + 10.0f, pos.y + 10.0f, pos.z));
	}

	if (m_pCNumber != NULL)
	{
		D3DXVECTOR3 pos = GetPos();
		m_pCNumber->SetNumber(m_CreateNumber);
		m_pCNumber->SetPos(D3DXVECTOR3(pos.x + 10.0f, pos.y - 10.0f, pos.z));
	}

	if (m_pBNumber != NULL)
	{
		D3DXVECTOR3 pos = GetPos();
		if (m_bUse[m_CreateNumber][m_WightNumber][m_HeightNumber] == true)
		{
			m_pBNumber->SetNumber(1);
		}
		else
		{
			m_pBNumber->SetNumber(0);
		}
		m_pBNumber->SetPos(D3DXVECTOR3(pos.x - 10.0f, pos.y + 10.0f, pos.z));
	}
#endif // NUM

	SetTexture();

	//���_���̍X�V
	CObjectBillboard::Update();

	//m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\1.png");
}

//====================================================================
//�`�揈��
//====================================================================
void CBreak_BlockBillboard::Draw(void)
{
	CObjectBillboard::Draw();
}

//====================================================================
//�����蔻�菈��
//====================================================================
bool CBreak_BlockBillboard::Collision(D3DXVECTOR3 *pPos, D3DXVECTOR3 pPosOld, D3DXVECTOR3 *pMove, float fHeight, float fWidth, bool bX)
{
	bool bOn = false;

	float myWight = GetWight() * 0.5f;
	float myHeight = GetHeight() * 0.5f;
	D3DXVECTOR3 mtPos = GetPos();


	if (bX == false)
	{
		if (
			(pPos->y < mtPos.y + myHeight &&
				pPosOld.y >= mtPos.y + myHeight) &&
			pPos->x + fWidth > mtPos.x - myWight &&
			pPos->x - fWidth < mtPos.x + myWight
			)
		{//�ォ��߂荞�񂾎�
			bOn = true;
			pPos->y = mtPos.y + myHeight;		//�u���b�N�̂����ɂ�������
			pMove->y = 0.0f;					//�ړ��ʂ��O�ɂ���
		}

		if (
			(pPos->y + fHeight > mtPos.y - myHeight &&
				pPosOld.y + fHeight <= mtPos.y - myHeight) &&
			pPos->x + fWidth > mtPos.x - myWight &&
			pPos->x - fWidth < mtPos.x + myWight
			)
		{//������߂荞�񂾎�
			pPos->y = mtPos.y - myHeight - fHeight;		//�u���b�N�̉��Ŏ~�߂�
			pMove->y = 0.0f;					//�ړ��ʂ��O�ɂ���
		}
	}
	else
	{
		if (
			(pPos->x + fWidth > mtPos.x - myWight &&
				pPosOld.x + fWidth <= mtPos.x - myWight) &&
			pPos->y + fHeight > mtPos.y - myHeight &&
			pPos->y < mtPos.y + myHeight
			)
		{//������߂荞�񂾎�
			pPos->x = mtPos.x - myHeight - fWidth;		//�u���b�N�̍��Ŏ~�߂�
			pMove->x = 0.0f;					//�ړ��ʂ��O�ɂ���
		}

		if (
			(pPos->x - fWidth < mtPos.x + myWight &&
				pPosOld.x - fWidth >= mtPos.x + myWight) &&
			pPos->y + fHeight > mtPos.y - myHeight &&
			pPos->y < mtPos.y + myHeight
			)
		{//�E����߂荞�񂾎�
			pPos->x = mtPos.x + myHeight + fWidth;		//�u���b�N�̉E�Ŏ~�߂�
			pMove->x = 0.0f;					//�ړ��ʂ��O�ɂ���
		}
	}

	return bOn;
}

//====================================================================
//�e�N�X�`���̐ݒ菈��
//====================================================================
void CBreak_BlockBillboard::SetTexture(void)
{
	//�e�N�X�`���̎擾
	CTexture *pTexture = CManager::GetInstance()->GetTexture();;

	if (m_bUse[m_CreateNumber][(m_WightNumber + 1) % SET_BLOCK_WIGHT][(m_HeightNumber) % SET_BLOCK_HEIGHT] == true)
	{
		m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\3.png");
	}
	else
	{
		m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\block001.png");
	}
}
//============================================
//
//	�j�󂳂ꂽ�u���b�N�̏��� [breakPiece.cpp]
//	Author:sakamoto kai
//
//============================================
#include "BreakPiece.h"
#include "renderer.h"
#include "manager.h"
#include "game.h"
#include "texture.h"
#include "DebugNumber3D.h"
#include "XModel.h"
#include "player3D.h"
#include "Map2D.h"

//�}�N����`
#define BLOCK_WIGHT (40.0f)		//����
#define BLOCK_HEIGHT (40.0f)	//�c��
#define BLOCK_WAVE (90)	//�U������

LPD3DXMESH CBreak_Piece::m_pMesh = NULL;				//���b�V��(���_���)�ւ̃|�C���^
LPD3DXBUFFER CBreak_Piece::m_pBuffMat = NULL;			//�}�e���A���ւ̃|�C���^
DWORD CBreak_Piece::m_dwNumMat = NULL;					//�}�e���A���̐�
int CBreak_Piece::m_nIdxXModel = NULL;					//�}�e���A���̐�

//====================================================================
//�R���X�g���N�^
//====================================================================
CBreak_Piece::CBreak_Piece(int nPriority) : CObjectXtex(nPriority)
{
	m_ColorA = 1.0f;

	if (CScene::GetMode() == CScene::MODE_GAME)
	{
		switch (CGame::GetMap2D()->GetMapLevel() % 3 + 1)
		{
		case 1:
			m_BlockColor = D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f);
			break;

		case 2:
			m_BlockColor = D3DXCOLOR(0.9f, 0.3f, 0.0f, 1.0f);
			break;

		case 3:
			m_BlockColor = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
			break;

		default:
			m_BlockColor = D3DXCOLOR(0.9f, 0.3f, 0.0f, 1.0f);
			break;
		}
	}
	else
	{
		m_BlockColor = D3DXCOLOR(0.9f, 0.3f, 0.0f, 1.0f);
	}

	m_move.x = sinf((float)(rand() % 731 - (731 - 1) / 2) / 100.0f + D3DX_PI * -0.5f)*(float)((rand() % 100) / 10.0f) + 2.0f;
	m_move.y = 7.5f;
	m_move.z = -0.75f;

	m_rot.x = (float)(rand() % 9 - 4) * 0.1f;
	m_rot.y = (float)(rand() % 9 - 4) * 0.1f;
	m_rot.z = (float)(rand() % 9 - 4) * 0.1f;
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CBreak_Piece::~CBreak_Piece()
{

}

//====================================================================
//��������
//====================================================================
CBreak_Piece *CBreak_Piece::Create()
{
	CBreak_Piece *pPlayer = NULL;

	if (pPlayer == NULL)
	{
		//�I�u�W�F�N�g2D�̐���
		pPlayer = new CBreak_Piece();
	}

	//X�t�@�C���̊��蓖��
	CXModel *pXModel = CManager::GetInstance()->GetXModel();

	int nRandModel = rand() % 3;

	switch (nRandModel)
	{
	case 0:
		m_nIdxXModel = pXModel->Regist("data\\MODEL\\break00.x");
		break;
	case 1:
		m_nIdxXModel = pXModel->Regist("data\\MODEL\\break01.x");
		break;
	case 2:
		m_nIdxXModel = pXModel->Regist("data\\MODEL\\break02.x");
		break;
	}

	pXModel->GetXModelInfo(&m_pBuffMat, &m_dwNumMat, &m_pMesh, m_nIdxXModel);
	pPlayer->BindFile(m_pMesh, m_pBuffMat, m_dwNumMat);

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
HRESULT CBreak_Piece::Init(void)
{
	CTexture *pTexture = CManager::GetInstance()->GetTexture();;
	m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\0.png");

	SetType(CObject::TYPE_EFFECT);

	CObjectXtex::Init();

	return S_OK;
}

//====================================================================
//�I������
//====================================================================
void CBreak_Piece::Uninit(void)
{
	CObjectXtex::Uninit();
}

//====================================================================
//�X�V����
//====================================================================
void CBreak_Piece::Update(void)
{
	D3DXVECTOR3 pos = GetPos();
	D3DXVECTOR3 rot = GetRot();

	//�v���C���[�̈ʒu���擾����
	CPlayer3D *pPlayer = CGame::GetPlayer3D();
	D3DXVECTOR3 PlayerPos = pPlayer->GetPos();

	if (m_ColorA > 0.0f)
	{
		m_ColorA -= 0.02f;
	}
	m_BlockColor.a = m_ColorA;

	//�d��
	m_move.y -= 0.98f;

	//�����W��
	m_move.x = m_move.x * 0.98f;

	//�ʒu�ݒ�
	pos += m_move;

	rot += m_rot;

	SetPos(pos);
	SetRot(rot);

	//���_���̍X�V
	CObjectXtex::Update();

	if (pos.y < PlayerPos.y - 400.0f)
	{
		Uninit();
	}
}

//====================================================================
//�`�揈��
//====================================================================
void CBreak_Piece::Draw(void)
{
	SetMatColor(m_BlockColor);

	CObjectXtex::Draw();
}
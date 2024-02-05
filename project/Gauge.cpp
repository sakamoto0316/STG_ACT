//============================================
//
//	�Q�[�W�̏��� [Gauge.cpp]
//	Author:sakamoto kai
//
//============================================
#include "Gauge.h"
#include "renderer.h"
#include "manager.h"
#include "texture.h"
#include "number.h"

//====================================================================
//�R���X�g���N�^
//====================================================================
CGauge::CGauge(int nPriority) :CObject(nPriority)
{
	m_pTexture = NULL;
	m_pVtxBuff = NULL;
	m_bVertical = false;
	m_bNumberUI = false;
	m_bNumber10UI = false;

	m_Tilt = 0.0f;
	m_Height = 0.0f;
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	m_pNumberMax10 = NULL;
	m_pNumberMax1 = NULL;
	m_pNumber10 = NULL;
	m_pNumber1 = NULL;
}

//====================================================================
//�f�X�g���N�^
//====================================================================
CGauge::~CGauge()
{

}

//====================================================================
//��������
//====================================================================
CGauge *CGauge::Create(void)
{
	CGauge *pObject2D = NULL;

	if (pObject2D == NULL)
	{
		//�I�u�W�F�N�g2D�̐���
		pObject2D = new CGauge();
	}

	//�I�u�W�F�N�g�̏���������
	if (FAILED(pObject2D->Init()))
	{//���������������s�����ꍇ
		return NULL;
	}

	return pObject2D;
}

//====================================================================
//����������
//====================================================================
HRESULT CGauge::Init(void)
{
	CTexture *pTexture = CManager::GetInstance()->GetTexture();;
	m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\Test.jpg");

	if (m_bNumberUI == true)
	{
		//���C�t�Q�[�W�̐����Ɛݒ�
		m_pNumberMax1 = CNumber::Create();
		m_pNumberMax1->SetNumber(m_GaugeMax);
		m_pNumberMax1->SetPos(D3DXVECTOR3(m_pos.x + (m_Wight * 0.4f), m_pos.y + (m_Height * 0.5f), m_pos.z));
		m_pNumberMax1->SetWight(30.0f);
		m_pNumberMax1->SetHeight(30.0f);

		m_pNumber1 = CNumber::Create();
		m_pNumber1->SetNumber(m_Gauge);
		m_pNumber1->SetPos(D3DXVECTOR3(m_pos.x + (m_Wight * 0.6f), m_pos.y + (m_Height * 0.5f), m_pos.z));
		m_pNumber1->SetWight(30.0f);
		m_pNumber1->SetHeight(30.0f);
	}

	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	//���_�o�b�t�@�̐���
	if (FAILED(pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL)))
	{
		return E_FAIL;
	}

	//�Q�[�W�̊������o��
	float fRatio = 0.0f;

	if (m_Gauge != 0)
	{
		fRatio = ((float)m_Gauge / (float)m_GaugeMax);
	}

	VERTEX_2D*pVtx;	//���_�|�C���^������

	//���_�o�b�t�@�����b�N���A���X���ւ̃|�C���^������
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	if (m_bVertical == true)
	{
		//���_���W�̐ݒ� 
		pVtx[0].pos = D3DXVECTOR3(m_pos.x, m_pos.y - (m_Height * fRatio), m_pos.z);
		pVtx[1].pos = D3DXVECTOR3(m_pos.x + m_Wight, m_pos.y - (m_Height * fRatio), m_pos.z);
		pVtx[2].pos = D3DXVECTOR3(m_pos.x, m_pos.y, m_pos.z);
		pVtx[3].pos = D3DXVECTOR3(m_pos.x + m_Wight, m_pos.y, m_pos.z);
	}
	else
	{
		//���_���W�̐ݒ� 
		pVtx[0].pos = D3DXVECTOR3(m_pos.x, m_pos.y, m_pos.z);
		pVtx[1].pos = D3DXVECTOR3(m_pos.x + (m_Wight * fRatio), m_pos.y, m_pos.z);
		pVtx[2].pos = D3DXVECTOR3(m_pos.x + m_Tilt, m_pos.y + m_Height, m_pos.z);
		pVtx[3].pos = D3DXVECTOR3(m_pos.x + m_Tilt + (m_Wight * fRatio), m_pos.y + m_Height, m_pos.z);
	}

	//rhw�̐ݒ�
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//���_�J���[�̐ݒ�
	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();

	return S_OK;
}

//====================================================================
//�I������
//====================================================================
void CGauge::Uninit(void)
{
	if (m_pNumberMax10 != NULL)
	{
		m_pNumberMax10->Uninit();
		m_pNumberMax10->SetDeathFlag(true);
	}
	if (m_pNumberMax1 != NULL)
	{
		m_pNumberMax1->Uninit();
		m_pNumberMax1->SetDeathFlag(true);
	}
	if (m_pNumber10 != NULL)
	{
		m_pNumber10->Uninit();
		m_pNumber10->SetDeathFlag(true);
	}
	if (m_pNumber1 != NULL)
	{
		m_pNumber1->Uninit();
		m_pNumber1->SetDeathFlag(true);
	}

	SetDeathFlag(true);
}

//====================================================================
//�I������
//====================================================================
void CGauge::SetNULL(void)
{
	if (m_pNumberMax10 != NULL)
	{
		m_pNumberMax10 = NULL;
	}
	if (m_pNumberMax1 != NULL)
	{
		m_pNumberMax1 = NULL;
	}
	if (m_pNumber10 != NULL)
	{
		m_pNumber10 = NULL;
	}
	if (m_pNumber1 != NULL)
	{
		m_pNumber1 = NULL;
	}

	//���_�o�b�t�@�̔j��
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}
}

//====================================================================
//�X�V����
//====================================================================
void CGauge::Update(void)
{
	if (m_bNumberUI == true)
	{
		if (m_bNumber10UI == true)
		{
			m_pNumberMax1->SetNumber(m_GaugeMax / 10);
			m_pNumberMax1->SetPos(D3DXVECTOR3(m_pos.x + (m_Wight * 0.2f), m_pos.y + (m_Height * 0.5f), m_pos.z));

			m_pNumberMax10->SetNumber(m_GaugeMax);
			m_pNumberMax10->SetPos(D3DXVECTOR3(m_pos.x + (m_Wight * 0.3f), m_pos.y + (m_Height * 0.5f), m_pos.z));

			m_pNumber1->SetNumber(m_Gauge / 10);
			m_pNumber1->SetPos(D3DXVECTOR3(m_pos.x + (m_Wight * 0.6f), m_pos.y + (m_Height * 0.5f), m_pos.z));

			m_pNumber10->SetNumber(m_Gauge);
			m_pNumber10->SetPos(D3DXVECTOR3(m_pos.x + (m_Wight * 0.7f), m_pos.y + (m_Height * 0.5f), m_pos.z));
		}
		else if (m_GaugeMax >= 10)
		{
			SetNumber10();
			SetNumberMax10();
			m_bNumber10UI = true;
		}
		else
		{
			//���C�t�Q�[�W�̐ݒ�
			m_pNumberMax1->SetNumber(m_GaugeMax);
			m_pNumberMax1->SetPos(D3DXVECTOR3(m_pos.x + (m_Wight * 0.3f), m_pos.y + (m_Height * 0.5f), m_pos.z));

			m_pNumber1->SetNumber(m_Gauge);
			m_pNumber1->SetPos(D3DXVECTOR3(m_pos.x + (m_Wight * 0.7f), m_pos.y + (m_Height * 0.5f), m_pos.z));
		}
	}

	SetVerTex(m_bVertical);
}

//====================================================================
//�`�揈��
//====================================================================
void CGauge::Draw(void)
{
	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	////�e�N�X�`���̐ݒ�
	//pDevice->SetTexture(0, m_pTexture);

	CTexture *pTexture = CManager::GetInstance()->GetTexture();

	assert(GetIdx() != -1);		//�e�N�X�`���̔ԍ������Y�ꂽ�ꍇ�G���[��f��

								//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, pTexture->GetAddress(GetIdx()));

	//�|���S���̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,	//�v���~�e�B�u�̎��
		0,						//�`��̊J�n�ʒu
		2);						//�v���~�e�B�u(�|���S��)��
}

//====================================================================
//�e�N�X�`���̊��蓖��
//====================================================================
void CGauge::BindTexture(LPDIRECT3DTEXTURE9 pTexture)
{
	m_pTexture = pTexture;
}

//====================================================================
//���_���W�̐ݒ�
//====================================================================
void CGauge::SetVerTex(bool Vertical)
{
	//�Q�[�W�̊������o��
	float fRatio = 0.0f;

	if (m_Gauge != 0)
	{
		fRatio = ((float)m_Gauge / (float)m_GaugeMax);
	}

	VERTEX_2D*pVtx;	//���_�|�C���^������

	//���_�o�b�t�@�����b�N���A���X���ւ̃|�C���^������
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	if (Vertical == true)
	{
		//���_���W�̐ݒ� 
		pVtx[0].pos = D3DXVECTOR3(m_pos.x, m_pos.y - (m_Height * fRatio), m_pos.z);
		pVtx[1].pos = D3DXVECTOR3(m_pos.x + m_Wight, m_pos.y - (m_Height * fRatio), m_pos.z);
		pVtx[2].pos = D3DXVECTOR3(m_pos.x, m_pos.y, m_pos.z);
		pVtx[3].pos = D3DXVECTOR3(m_pos.x + m_Wight, m_pos.y, m_pos.z);
	}
	else
	{
		//���_���W�̐ݒ� 
		pVtx[0].pos = D3DXVECTOR3(m_pos.x, m_pos.y, m_pos.z);
		pVtx[1].pos = D3DXVECTOR3(m_pos.x + (m_Wight * fRatio), m_pos.y, m_pos.z);
		pVtx[2].pos = D3DXVECTOR3(m_pos.x + m_Tilt, m_pos.y + m_Height, m_pos.z);
		pVtx[3].pos = D3DXVECTOR3(m_pos.x + m_Tilt + (m_Wight * fRatio), m_pos.y + m_Height, m_pos.z);
	}

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//====================================================================
//�e�N�X�`�����W�̐ݒ�
//====================================================================
void CGauge::SetAnim(D3DXVECTOR2 Tex)
{
	VERTEX_2D*pVtx;	//���_�|�C���^������

	//���_�o�b�t�@�����b�N���A���X���ւ̃|�C���^������
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(Tex.x, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, Tex.y);
	pVtx[3].tex = D3DXVECTOR2(Tex.x, Tex.y);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//====================================================================
//���_�J���[�̐ݒ�
//====================================================================
void CGauge::SetColor(D3DXCOLOR col)
{
	VERTEX_2D*pVtx;	//���_�|�C���^������

	//���_�o�b�t�@�����b�N���A���X���ւ̃|�C���^������
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//���_�J���[�̐ݒ�
	pVtx[0].col =
		pVtx[1].col =
		pVtx[2].col =
		pVtx[3].col = col;

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//====================================================================
//�����̍ő吔��10�̈ʂ̐���
//====================================================================
void CGauge::SetNumberMax10(void)
{
	//���C�t�Q�[�W�̐����Ɛݒ�
	m_pNumberMax10 = CNumber::Create();
	m_pNumberMax10->SetNumber(m_GaugeMax % 10);
	m_pNumberMax10->SetPos(D3DXVECTOR3(m_pos.x + (m_Wight * 0.3f), m_pos.y + (m_Height * 0.5f), m_pos.z));
	m_pNumberMax10->SetWight(30.0f);
	m_pNumberMax10->SetHeight(30.0f);
}

//====================================================================
//������10�̈ʂ̐���
//====================================================================
void CGauge::SetNumber10(void)
{
	//���C�t�Q�[�W�̐����Ɛݒ�
	m_pNumber10 = CNumber::Create();
	m_pNumber10->SetNumber(m_Gauge % 10);
	m_pNumber10->SetPos(D3DXVECTOR3(m_pos.x + (m_Wight * 0.7f), m_pos.y + (m_Height * 0.5f), m_pos.z));
	m_pNumber10->SetWight(30.0f);
	m_pNumber10->SetHeight(30.0f);
}
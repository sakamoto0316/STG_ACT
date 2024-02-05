//========================================================================================
//
// �t�F�[�h����[fade.cpp]
// Author: ��{�@�ėB
//
//========================================================================================
#include "fade.h"
#include "renderer.h"

//�ÓI�����o�ϐ��錾
CFade::FADE CFade::m_fade = FADE_NONE;
CScene::MODE CFade::m_modeNext = CScene::MODE_TITLE;
D3DXCOLOR CFade::m_colorFade = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

//====================================================================
//�R���X�g���N�^
//====================================================================
CFade::CFade()
{

}

//====================================================================
//�f�X�g���N�^
//====================================================================
CFade::~CFade()
{

}

//====================================================================
//�t�F�[�h��ʂ̏���������
//====================================================================
void CFade::Init(CScene::MODE modeNext)
{
	m_fade = FADE_IN;

	m_modeNext = modeNext;

	m_colorFade = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);

	m_Fade_OK = true;

	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuffFade,
		NULL);

	VERTEX_2D*pVtx;	//���_�|�C���^������

	//���_�o�b�t�@�����b�N���A���X���ւ̃|�C���^������
	m_pVtxBuffFade->Lock(0, 0, (void**)&pVtx, 0);

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(SCREEN_WIDTH, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, SCREEN_HEIGHT, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f);

	//rhw�̐ݒ�
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//���_�J���[�̐ݒ�
	pVtx[0].col = m_colorFade;
	pVtx[1].col = m_colorFade;
	pVtx[2].col = m_colorFade;
	pVtx[3].col = m_colorFade;

	//pVtx += 4;	//���_�f�[�^�̃|�C���^���S���i�߂�

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuffFade->Unlock();

	//���[�h�̐ݒ�
	CScene::SetMode(m_modeNext);
}

//====================================================================
//�t�F�[�h�̏I������
//====================================================================
void CFade::Uninit(void)
{
	//���_�o�b�t�@�̔j��
	if (m_pVtxBuffFade != NULL)
	{
		m_pVtxBuffFade->Release();
		m_pVtxBuffFade = NULL;
	}
}

//====================================================================
//�t�F�[�h��ʂ̍X�V����
//====================================================================
void CFade::Update(void)
{
	if (m_fade != FADE_NONE)
	{
		if (m_fade == FADE_IN)
		{
			m_colorFade.a -= 0.02f;	//�|���S���𓧖��ɂ���
			if (m_colorFade.a <= 0.0f)
			{
				m_colorFade.a = 0.0f;
				m_fade = FADE_NONE;	//�������Ă��Ȃ����	
			}
		}
		else if (m_fade == FADE_OUT)
		{
			m_colorFade.a += 0.02f;
			if (m_colorFade.a >= 1.0f)
			{
				m_colorFade.a = 1.0f;
				m_fade = FADE_IN;

				m_Fade_OK = true;
				//���[�h�̐ݒ�(���̉�ʂɈڍs)
				CScene::SetMode(m_modeNext);
			}
		}
		VERTEX_2D*pVtx;	//���_�|�C���^������

						//���_�o�b�t�@�����b�N���A���X���ւ̃|�C���^������
		m_pVtxBuffFade->Lock(0, 0, (void**)&pVtx, 0);

		//���_�J���[�̐ݒ�
		pVtx[0].col = m_colorFade;
		pVtx[1].col = m_colorFade;
		pVtx[2].col = m_colorFade;
		pVtx[3].col = m_colorFade;

		//���_�o�b�t�@���A�����b�N����
		m_pVtxBuffFade->Unlock();
	}
}

//====================================================================
//�t�F�[�h��ʂ̕`�揈��
//====================================================================
void CFade::Draw(void)
{
	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetInstance()->GetRenderer()->GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, m_pVtxBuffFade, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, NULL);

	//�|���S���̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,	//�v���~�e�B�u�̎��
		0,						//�v���~�e�B�u(�|���S��)��
		2);
}

//====================================================================
//�t�F�[�h��ʂ̐ݒ菈��
//====================================================================
void CFade::SetFade(CScene::MODE modeNext)
{
	if (m_fade == FADE_NONE)
	{
		m_fade = FADE_OUT;

		m_modeNext = modeNext;

		m_colorFade = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);
	}
}

//====================================================================
//�t�F�[�h��ʂ̏�������
//====================================================================
void CFade::Fade_false(void)
{
	m_Fade_OK = false;
}

//====================================================================
//�t�F�[�h��ʂ̏�������
//====================================================================
bool CFade::Fade_OK(void)
{
	return m_Fade_OK;
}
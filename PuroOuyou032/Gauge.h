//============================================
//
//	�Q�[�W�̏��� [Gauge.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _GAUGE_H_
#define _GAUGE_H_

#include "main.h"
#include "object.h"

//�O���錾
class CNumber;

//�I�u�W�F�N�g2D�N���X
class CGauge : public CObject
{
public:
	CGauge(int nPriority = 3);
	~CGauge();

	static CGauge *Create(void);

	virtual HRESULT Init(void);
	virtual void Uninit(void);
	virtual void Update(void);
	virtual void Draw(void);
	void BindTexture(LPDIRECT3DTEXTURE9 pTexture);

	void SetVerTex(bool Vertical);					//���_���W�̐ݒ�
	void SetAnim(D3DXVECTOR2 Tex);					//�e�N�X�`�����W�̐ݒ�
	void SetColor(D3DXCOLOR col);					//���_�J���[�̐ݒ�

	void SetPos(D3DXVECTOR3 pos) { m_pos = pos; }
	D3DXVECTOR3 GetPos(void) { return m_pos; }
	void SetGaugeMax(int Max) { m_GaugeMax = Max; }
	int GetGaugeMax(void) { return m_GaugeMax; }
	void SetGauge(int Gauge) { m_Gauge = Gauge; }
	int GetGauge(void) { return m_Gauge; }
	void SetTilt(float Tilt) { m_Tilt = Tilt; }
	float GetTilt(void) { return m_Tilt; }
	void SetWight(float Wight) { m_Wight = Wight; }
	float GetWight(void) { return m_Wight; }
	void SetHeight(float Height) { m_Height = Height; }
	float GetHeight(void) { return m_Height; }
	int GetIdx(void) { return m_nIdxTexture; }
	void SetVertical(bool Vertical) { m_bVertical = Vertical; }
	void SetNumberUI(bool NumberUI) { m_bNumberUI = NumberUI; }
	void SetNULL(void);

protected:
	void SetVtxBuff(LPDIRECT3DVERTEXBUFFER9 Height) { m_pVtxBuff = Height; }
	LPDIRECT3DVERTEXBUFFER9 GetVtxBuff(void) { return m_pVtxBuff; }

private:
	void SetNumberMax10(void);
	void SetNumber10(void);

	int m_nIdxTexture;						//�e�N�X�`���̔ԍ�
	int m_GaugeMax ;						//�ő�̃Q�[�W
	int m_Gauge;							//���݂̃Q�[�W
	float m_Tilt;							//�Q�[�W�̌X��
	float m_Wight;							//��
	float m_Height;							//����
	bool m_bVertical;						//�Q�[�W���c���ǂ���
	bool m_bNumberUI;						//UI��\�����邩�ǂ���
	bool m_bNumber10UI;						//UI��\�����邩�ǂ���
	D3DXVECTOR3 m_pos;						//���_�̈ʒu
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;		//���_�o�b�t�@�ւ̃|�C���^
	LPDIRECT3DTEXTURE9 m_pTexture;			//�e�N�X�`���ւ̃|�C���^

	CNumber *m_pNumberMax10;				//10�̈ʂ̍ő�l
	CNumber *m_pNumberMax1;					//1�̈ʂ̍ő�l
	CNumber *m_pNumber10;					//10�̈ʂ̒l
	CNumber *m_pNumber1;					//1�̈ʂ̒l
};											
#endif
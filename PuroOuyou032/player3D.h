//============================================
//
//	�v���C���[�̏��� [player3D.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _PLAYER3D_H_
#define _PLAYER3D_H_

#include "main.h"
#include "objectX.h"

#define NUM_PLAYER 0

//�O���錾
class CMap2D;
class CGuide;
class CItem;
class CEnemy;
class CLifeGauge;
class CObject2D;
class CNumber;
class CCombo;
class CBulletTypeUI;

//�I�u�W�F�N�g�v���C���[�N���X
class CPlayer3D : public CObjectX
{
public:
	typedef enum
	{
		STATE_NORMAL = 0,
		STATE_DAMAGE,
		STATE_WAIT,
	}STATE_TYPE;

	typedef enum
	{
		SHOT_NORMAL = 0,
		SHOT_3WAY,
		SHOT_TRIPLE_3WAY,
		SHOT_8WAY,
		SHOT_BURST,
		SHOT_LESER,
		SHOT_MACHINEGUN,
		SHOT_EXPLOSION,
		SHOT_SPREAD_EXPLOSION,
		SHOT_CONTINUE_EXPLOSION,
	}SHOT_TYPE;

	CPlayer3D(int nPriority = 3);
	~CPlayer3D();

	static CPlayer3D *Create();
	HRESULT Init(void);
	void UICreate(void);
	void Uninit(void);
	void Update(void);
	void TitleUpdate(void);
	void GameUpdate(void);
	void Draw(void);

	void PlayPad(void);
	D3DXVECTOR3 GetMove(void) { return m_move; }
	void SetMove(D3DXVECTOR3 move) { m_move = move; }
	void SetFallMax(float Max) { m_FallMax = Max; }
	int GetIdxXModel(void) { return m_nIdxXModel; }
	int GetIdxTexture(int nCnt) { return m_nIdxTexture[nCnt]; }
	void SetNULL(void);
	void SetBullet(SHOT_TYPE type);												//�i�����̒e�̎��
	void AddUlt(void);															//�K�E�Q�[�W�̉��Z
	bool GetUseUlt(void) { return m_bUseUlt; }									//�K�E�Z���g���Ă��邩�ǂ���
	void AddCombo(void) { m_nCombo++; }											//�R���{���̉��Z
	int GetCombo(void) { return m_nCombo; }										//�R���{���̎擾
	void SetComboScore(int Score) { m_MaxConboScore = Score; }					//�R���{�X�R�A�̐ݒ�
	int GetComboScore(void) { return m_MaxConboScore; }							//�R���{�X�R�A�̎擾
	void SetFallScore(int Score) { m_MaxFallScore = Score; }					//�ō����x�����X�R�A�̐ݒ�
	int GetFallScore(void) { return m_MaxFallScore; }							//�ō����x�����X�R�A�̎擾
	void SetComboDepth(int Score) { m_DepthScore = (float)Score; }				//�[���X�R�A�̐ݒ�
	int GetComboDepth(void) { return (int)m_DepthScore; }						//�[���X�R�A�̎擾
	void SetBulletTypeUI(const char *Texture, SHOT_TYPE Type);					//�e�̎�ނ�UI�̃Z�b�g
	CCombo *GetDebugCombo(void) { return m_pCombo; }							//�f�o�b�O�p
	void LifeBlinking(void);

private:
	void SizeVtx(void);															//���f���̑傫���w��
	void StateManager(void);													//��ԊǗ�
	void Move(void);															//�ړ�����
	void LandingEffect(D3DXVECTOR3 pos);										//���n�����A�N�V����
	void UltimateTrigger(D3DXVECTOR3 pos);										//�K�E�Z��������
	void Ultimate(D3DXVECTOR3 pos);												//�K�E�Z����
	void Shoot(D3DXVECTOR3 pos, D3DXVECTOR3 rot);								//�e���ˏ���
	void BurstShoot(D3DXVECTOR3 pos);											//�o�[�X�g�e���ˏ���
	void Machinegun(D3DXVECTOR3 pos);											//�}�V���K�����ˏ���
	void SetWarning(D3DXVECTOR3 pos);													//�_���[�W�q�b�g����
	void HitDamage(int Damage);													//�_���[�W�q�b�g����
	void LevelUp(void);															//���x���A�b�v����
	void Evolution(void);														//�i���̏���
	bool CollisionBlock(D3DXVECTOR3 *pos, bool bX);								//�u���b�N�Ƃ̓����蔻��
	bool CollisionUI(D3DXVECTOR3 *pos, bool bX);								//�u���b�N�Ƃ̓����蔻��
	bool CollisionObjectSquareSpace(void);										//�I�u�W�F�N�g�Ƃ̓����蔻��(��`�͈̔�)
	bool CollisionObjectSquareLine(D3DXVECTOR3 pos);							//�I�u�W�F�N�g�Ƃ̓����蔻��(��`��4��)
	bool CollisionEnemyCircle(D3DXVECTOR3 pos, float nRadiusOut);				//�~�̓����蔻��
	bool CollisionPointCircle(D3DXVECTOR3 pos, float nRadiusOut);				//�o���l�̓����蔻��
	bool CollisionCircle(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2, float nRadiusOut);	//�~�̓����蔻��
	bool CollisionCircleOut(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2, float nRadiusOut, float nRadiusIn);	//�~�̓����蔻��(�O���̂�)
	void ResetBullet(void);														//�c�e���̃��Z�b�g
	void SetLevelNumber10(void);												//���x���̐��l��10�̈ʂ𐶐�����

	static LPD3DXMESH m_pMesh;				//���b�V��(���_���)�ւ̃|�C���^
	static LPD3DXBUFFER m_pBuffMat;			//�}�e���A���ւ̃|�C���^
	static DWORD m_dwNumMat;				//�}�e���A���̐�
	static int m_nIdxXModel;				//X���f���̔ԍ�
	static int m_nIdxTexture[64];			//X���f���e�N�X�`���̔ԍ�
	D3DXVECTOR3 m_vtxMin;					//���f���̍ŏ�
	D3DXVECTOR3 m_vtxMax;					//���f���̍ő�
	D3DXVECTOR3 m_posOld;					//�ߋ��̈ʒu	
	D3DXVECTOR3 m_move;						//�ړ���	
	bool m_bFallMax; 						//�v���C���[���ő呬�x�ŗ������Ă��邩�ǂ���
	float m_FallMax; 						//�v���C���[����������ő呬�x
	int m_FallCount; 						//�ő呬�x�ŗ������Ă��鎞�ɂ����p�[�e�B�N���̂��߂̃J�E���g
	float m_stop;							//�����W��	
	D3DXVECTOR3 m_GuideRot;					//�K�C�h�̌���	
	bool m_bJump;							//�W�����v�������ǂ����̔��f
	int m_nLife;							//���C�t
	int m_Ultimate;							//�K�E
	float m_UltimateSpin;					//���݂̕K�E�Z�̃G�t�F�N�g��]
	float m_UltimateLine;					//���݂̕K�E�Z�̌��ʔ͈�
	D3DXVECTOR3 m_UltimatePos;				//�K�E�Z�̔����ʒu
	bool m_bUseUlt;							//�K�E�̔��������ǂ���
	int m_nBulletMax;						//�e�̑��e��
	int m_nBullet;							//���݂̒e�̐�
	int m_nBurstCount;						//�o�[�X�g�e�̃J�E���g
	int m_nBurstCoolTime;					//�o�[�X�g�e�̎��̒e���o��܂ł̃N�[���^�C��
	int m_BulletCoolTime;					//���̒e�����Ă�悤�ɂȂ�܂ł̃N�[���^�C��
	bool m_bMachingun;						//�}�V���K���̔��ˏ�Ԃ��I�����I�t��
	float m_fMachingunJump;					//�}�V���K���̔����ɂ��W�����v�̒l
	int m_nLevelUp;							//���x���A�b�v�܂łɕK�v�Ȍo���l
	int m_nLevelPoint;						//���݂̌o���l
	int m_nLevel;							//���݂̃��x��
	int m_EvolutionCount;					//�i���̉�
	STATE_TYPE m_State;						//���
	SHOT_TYPE m_BulletType;					//�e�̎��
	SHOT_TYPE m_MyBulletType[3];			//���ݎg����e�̎��
	int m_SelectBulletType;					//���ݎg���Ă���e�̎��
	int m_SelectBulletTypeMax;				//���ݎg���Ă���e�̎�ނ̍ő吔
	int m_StateCount;						//��Ԃ̒������Ǘ�����J�E���g
	bool m_bLevelNumber10;					//10�̈ʂ�\�����Ă��邩�ǂ���
	int m_nCombo;							//�n�ʂɒ��n�����ɓG��|������
	int UltOKParticleCount;					//�K�E�Z���g�����Ԃ̂Ƃ��ɂ����p�[�e�B�N���̃J�E���g
	int m_LifeRedCount;						//���C�t���Ⴂ���̓_�ŗp�J�E���g
	int m_LifeNormalCount;					//���C�t���Ⴂ���̓_�ŗp�J�E���g
	bool m_bLifeRed;						//���C�t���Ⴂ���̓_�ŗpbool
	int m_MaxConboScore;					//�R���{�̍ő吔�ɂ���Ċl���ł���X�R�A
	int m_MaxFallScore;						//�ō����x�ŗ������Ă��鎞�Ԃɂ���Ċl���ł���X�R�A
	float m_DepthScore;						//�Q�[���I�����ɂ���[���ɂ���Ċl���ł���X�R�A
	bool m_bWarning;						//�{�X�̋����ɂ��x��

	static CGuide *m_pGuide;				//�K�C�h�p�G�t�F�N�g
	static CObject2D *m_pUIPlayer;			//�v���C���[��UI
	static CObject2D *m_pUIPlayerBG;		//�v���C���[��UI
	static CObject2D *m_pUIPlayerFG;		//�v���C���[��UI�̑O�ʃ|���S��
	static CObject2D *m_pUIBullet;			//�o���b�g��UI
	static CObject2D *m_pUIBulletBG;		//�o���b�g��UI
	static CObject2D *m_pUIBulletFG;		//�o���b�g��UI�̑O�ʃ|���S��
	static CObject2D *m_pLifeUI;			//�̗�UI
	static CLifeGauge *m_pLifeGauge;		//�̗̓Q�[�W
	static CLifeGauge *m_pLifeFG;			//�̗̓Q�[�W�̑O�ʃ|���S��
	static CObject2D *m_pUltimateUI;		//�K�EUI
	static CLifeGauge *m_pUltimateGauge;	//�K�E�Q�[�W
	static CLifeGauge *m_pUltimateFG;		//�K�E�Q�[�W�̑O�ʃ|���S��
	static CObject2D *m_pBulletUI;			//�e��UI
	static CLifeGauge *m_pBulletGauge;		//�e���Q�[�W
	static CLifeGauge *m_pBulletFG;			//�e���Q�[�W�̑O�ʃ|���S��
	static CLifeGauge *m_LevelGauge;		//���x���Q�[�W
	static CLifeGauge *m_LevelFG;			//���x���Q�[�W�̑O�ʃ|���S��
	static CNumber *m_LevelNumber1;			//���x���𐔎��ŕ\������UI
	static CNumber *m_LevelNumber10;		//���x���𐔎��ŕ\������UI
	static CObject2D *m_pLvPolygon;			//���x����Lv.�̕����̃|���S��
	static CCombo *m_pCombo;				//�R���{���\�L
	static CBulletTypeUI *m_pBulletTypeUI[3];//���ݎg����e��UI
	static CBulletTypeUI *m_pSelectBulletTypeUI;//�R���{�pUI
	static CObject2D *m_pWarning;			//�x���}�[�N
	static CObject2D *m_pWarningTex[2];		//�x���|���S��
};
#endif
//============================================
//
//	�e�N�X�`���̊Ǘ� [texture.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include "main.h"

//�}�N����`
#define MAX_TEXTURE (256)

//�e�N�X�`���N���X
class CTexture
{
public:
	CTexture();
	~CTexture();

	HRESULT Load(void);
	void Unload(void);

	int Regist(const char *pFilename);
	void XModelRegist(int *nTexIdx, int nXModelIdx);
	LPDIRECT3DTEXTURE9 GetAddress(int nIdx);
	const char *GetTextureName(int Idx) { return c_apTexturename[Idx]; }

private:
	LPDIRECT3DTEXTURE9 m_apTexture[MAX_TEXTURE];
	static int m_NumAll;
	static const char *c_apTexturename[MAX_TEXTURE];
};
#endif
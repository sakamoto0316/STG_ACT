//============================================
//
//	�v���R���p�C���w�b�_ [precompile.h]
//	Author:sakamoto kai
//
//============================================
#ifndef _PRECOMPILE_H_
#define _PRECOMPILE_H_

#include <windows.h>
#include "d3dx9.h"						//�`�揈���ɕK�v
#define DIRECTINPUT_VERSION (0x0800)	//�r���h���̌x���Ώ��p�}�N��
#include "dinput.h"						//���͏����ɕK�v
#include "xaudio2.h"					//�T�E���h����
#include <cassert>
#include <math.h>
#include <stdio.h>

//���������[�N�o�͗p�}�N��
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#ifdef _DEBUG
#define CHECK_MEM_LEAK
#endif // _DEBUG
#ifdef CHECK_MEM_LEAK
#ifdef new
#undef new
#endif
#endif // CHECK_MEM_LEAK
//
////���i�g�p�֎~
//#ifdef CHECK_MEM_LEAK
//#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
//#endif // CHECK_MEM_LEAK

#endif	//_PRECOMPILE_H_
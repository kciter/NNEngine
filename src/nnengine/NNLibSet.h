
/*
 * NNLibSet.h
 * �ۼ���: �̼���
 * �ۼ���: 2014. 02. 18
 * ���������� ������ ���:
 * ������:
 * Static Library�� �����ϴ� ��ũ�θ� ��Ƶ� �������
 */

#ifndef __NNLIBSET_H__
#define __NNLIBSET_H__

#if defined(_WIN32) || defined(_WIN64) /* Windows */

/* timeGetTime */
#pragma comment(lib, "winmm.lib")
/* // */

/* D3D */
#pragma comment(lib, "d3d9.lib")
#ifdef _DEBUG
#pragma comment(lib, "d3dx9d.lib")
#else
#pragma comment(lib, "d3dx9.lib")
#endif
/* // */

#endif

#endif
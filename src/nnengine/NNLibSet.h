
/*
 * NNLibSet.h
 * 작성자: 이선협
 * 작성일: 2014. 02. 18
 * 마지막으로 수정한 사람:
 * 수정일:
 * Static Library를 포함하는 매크로를 모아둔 헤더파일
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

/*
 * NNWindowsApplication.h
 * 작성자: 이선협
 * 작성일: 2014. 02. 18
 * 마지막으로 수정한 사람:
 * 수정일:
 * 윈도우에서 Application Frame을 생성하기 위한 클래스
 */

#ifndef __NNWINDOWSAPPLICATION_H__
#define __NNWINDOWSAPPLICATION_H__

#include <windows.h>
#include "NNBaseApplication.h"

namespace NNEngine
{
	class NNWindowsApplication : public NNBaseApplication
	{
	public:
		static NNWindowsApplication* GetInstance();
		static void ReleaseInstance();

	public:
		virtual bool Init( wchar_t* title, int width, int height, RendererStatus rendererStatus );
		virtual bool Release();
		virtual bool Run();

	private:
		/* _CreateWindow
		 * title: 어플리케이션의 타이틀명
		 * width: 어플리케이션 프레임의 가로길이
		 * height: 어플리케이션 프레임의 세로길이
		 * 어플리케이션 프레임을 생성하는 함수.
		 */
		bool _CreateWindow( wchar_t* title, int width, int height );

		/* _WndProc
		 * 윈도우 메세지 큐 처리 콜백 함수
		 */
		static LRESULT CALLBACK _WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );

	private:
		/* 생성자와 소멸자 */
		NNWindowsApplication();
		virtual ~NNWindowsApplication();

	private:
		static NNWindowsApplication* mInstance;

		HWND mHwnd;
		HINSTANCE mhInstance;
	};
}

#endif

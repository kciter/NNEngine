
/*
 * NNWindowsApplication.h
 * 작성자: 이선협
 * 작성일: 2014. 02. 18
 * 마지막으로 수정한 사람:
 * 수정일:
 * 윈도우에서 Application Frame을 생성하기 위한 클래스
 * 엔진에서 기본적으로 제공해주는 Application 클래스
 * 이 클래스를 사용하지 않고 BaseApplication을 상속받아
 * 직접 만들어서 사용하여도 상관없다.
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
		/* GetInstance
		 * Return Type: NNWindowsApplication
		 * 싱글톤 인스턴스를 반환하는 함수
		 */
		static NNWindowsApplication* GetInstance();

		/* ReleaseInstance
		 * Return Type: void
		 * 싱글톤 인스턴스 삭제하는 함수
		 */
		static void ReleaseInstance();

	public:
		/* Init
		 * Return Type: bool
		 * title: 어플리케이션의 타이틀명
		 * width: 어플리케이션 프레임의 가로길이
		 * height: 어플리케이션 프레임의 세로길이
		 * isFullscreen: 풀스크린 여부
		 * rendererStatus: 렌더러 종류 (D3D, OpenGL, ...)
		 * NNBaseApplication에서 상속받은 함수를 오버라이딩함
		 */
		bool Init( wchar_t* title, int width, int height, bool isFullscreen, RendererStatus rendererStatus );

		/* Release
		 * Return Type: bool
		 * NNBaseApplication에서 상속받은 함수를 오버라이딩함
		 */
		bool Release();

		/* Run
		 * Return Type: bool
		 * NNBaseApplication에서 상속받은 함수를 오버라이딩함
		 */
		bool Run();

	public:
		/* GetHWND
		 * Return Type: HWND
		 * HWND를 반환하는 함수
		 */
		inline HWND GetHWND() const { return mHwnd; }

		/* GetHandleInstance
		 * Return Type: HINSTANCE
		 * 인스턴스 핸들을 반환하는 함수
		 */
		inline HINSTANCE GetHandleInstance() const { return mhInstance; }

	private:
		/* _CreateWindow
		 * Return Type: bool
		 * title: 어플리케이션의 타이틀명
		 * width: 어플리케이션 프레임의 가로길이
		 * height: 어플리케이션 프레임의 세로길이
		 * 어플리케이션 프레임을 생성하는 함수.
		 */
		bool _CreateWindow( wchar_t* title, int width, int height );

		/* _CreateRenderer
		 * Return Type: bool
		 * rendererStatus: 렌더러 종류 (D3D, OpenGL, ...)
		 * NNBaseApplication에서 상속받은 함수를 오버라이딩함
		 */
		bool _CreateRenderer( bool isFullscreen, RendererStatus rendererStatus );

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

		friend class NND3DRenderer;
	};
}

#endif

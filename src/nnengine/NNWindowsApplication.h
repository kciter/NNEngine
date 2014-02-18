
/*
 * NNWindowsApplication.h
 * �ۼ���: �̼���
 * �ۼ���: 2014. 02. 18
 * ���������� ������ ���:
 * ������:
 * �����쿡�� Application Frame�� �����ϱ� ���� Ŭ����
 * �������� �⺻������ �������ִ� Application Ŭ����
 * �� Ŭ������ ������� �ʰ� BaseApplication�� ��ӹ޾�
 * ���� ���� ����Ͽ��� �������.
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
		 * �̱��� �ν��Ͻ��� ��ȯ�ϴ� �Լ�
		 */
		static NNWindowsApplication* GetInstance();

		/* ReleaseInstance
		 * Return Type: void
		 * �̱��� �ν��Ͻ� �����ϴ� �Լ�
		 */
		static void ReleaseInstance();

	public:
		/* Init
		 * Return Type: bool
		 * title: ���ø����̼��� Ÿ��Ʋ��
		 * width: ���ø����̼� �������� ���α���
		 * height: ���ø����̼� �������� ���α���
		 * isFullscreen: Ǯ��ũ�� ����
		 * rendererStatus: ������ ���� (D3D, OpenGL, ...)
		 * NNBaseApplication���� ��ӹ��� �Լ��� �������̵���
		 */
		bool Init( wchar_t* title, int width, int height, bool isFullscreen, RendererStatus rendererStatus );

		/* Release
		 * Return Type: bool
		 * NNBaseApplication���� ��ӹ��� �Լ��� �������̵���
		 */
		bool Release();

		/* Run
		 * Return Type: bool
		 * NNBaseApplication���� ��ӹ��� �Լ��� �������̵���
		 */
		bool Run();

	public:
		/* GetHWND
		 * Return Type: HWND
		 * HWND�� ��ȯ�ϴ� �Լ�
		 */
		inline HWND GetHWND() const { return mHwnd; }

		/* GetHandleInstance
		 * Return Type: HINSTANCE
		 * �ν��Ͻ� �ڵ��� ��ȯ�ϴ� �Լ�
		 */
		inline HINSTANCE GetHandleInstance() const { return mhInstance; }

	private:
		/* _CreateWindow
		 * Return Type: bool
		 * title: ���ø����̼��� Ÿ��Ʋ��
		 * width: ���ø����̼� �������� ���α���
		 * height: ���ø����̼� �������� ���α���
		 * ���ø����̼� �������� �����ϴ� �Լ�.
		 */
		bool _CreateWindow( wchar_t* title, int width, int height );

		/* _CreateRenderer
		 * Return Type: bool
		 * rendererStatus: ������ ���� (D3D, OpenGL, ...)
		 * NNBaseApplication���� ��ӹ��� �Լ��� �������̵���
		 */
		bool _CreateRenderer( bool isFullscreen, RendererStatus rendererStatus );

		/* _WndProc
		 * ������ �޼��� ť ó�� �ݹ� �Լ�
		 */
		static LRESULT CALLBACK _WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );

	private:
		/* �����ڿ� �Ҹ��� */
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

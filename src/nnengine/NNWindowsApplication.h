
/*
 * NNWindowsApplication.h
 * �ۼ���: �̼���
 * �ۼ���: 2014. 02. 18
 * ���������� ������ ���:
 * ������:
 * �����쿡�� Application Frame�� �����ϱ� ���� Ŭ����
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
		 * title: ���ø����̼��� Ÿ��Ʋ��
		 * width: ���ø����̼� �������� ���α���
		 * height: ���ø����̼� �������� ���α���
		 * ���ø����̼� �������� �����ϴ� �Լ�.
		 */
		bool _CreateWindow( wchar_t* title, int width, int height );

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
	};
}

#endif

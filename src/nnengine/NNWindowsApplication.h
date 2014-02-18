
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
		 * NNBaseApplication���� ��ӹ��� �Լ��� �������̵���
		 */
		virtual bool Init( wchar_t* title, int width, int height, RendererStatus rendererStatus );

		/* Release
		 * Return Type: bool
		 * NNBaseApplication���� ��ӹ��� �Լ��� �������̵���
		 */
		virtual bool Release();

		/* Run
		 * Return Type: bool
		 * NNBaseApplication���� ��ӹ��� �Լ��� �������̵���
		 */
		virtual bool Run();

	private:
		/* _CreateWindow
		 * Return Type: bool
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

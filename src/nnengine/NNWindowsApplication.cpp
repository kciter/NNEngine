
/*
 * NNWindowsApplication.cpp
 * �ۼ���: �̼���
 * �ۼ���: 2014. 02. 18
 * ���������� ������ ���:
 * ������:
 * �����쿡�� Application Frame�� �����ϱ� ���� Ŭ����
 */

#include "NNWindowsApplication.h"

#include "NND3DRenderer.h"

namespace NNEngine
{
	NNWindowsApplication* NNWindowsApplication::mInstance = nullptr;

	NNWindowsApplication* NNWindowsApplication::GetInstance()
	{
		if ( mInstance == nullptr )
		{
			mInstance = new NNWindowsApplication();
		}

		return mInstance;
	}
	void NNWindowsApplication::ReleaseInstance()
	{
		if ( mInstance != nullptr )
		{
			delete mInstance;
			mInstance = nullptr;
		}
	}

	NNWindowsApplication::NNWindowsApplication()
	{
	}
	NNWindowsApplication::~NNWindowsApplication()
	{
	}

	bool NNWindowsApplication::Init( wchar_t* title, int width, int height, bool isFullscreen, RendererStatus rendererStatus )
	{
		mTitle = title;
		mScreenWidth = width;
		mScreenHeight = height;
		mIsFullscreen = isFullscreen;
		mRendererStatus = rendererStatus;

		if ( _CreateWindow( title, width, height ) == false )
		{
			return false;
		}

		if ( _CreateRenderer( isFullscreen, rendererStatus ) == false )
		{
			return false;
		}

		return true;
	}
	bool NNWindowsApplication::Release()
	{
		return true;
	}
	bool NNWindowsApplication::Run()
	{
		float mFpsTimer = 0.f; /* �� ������ ���� �ֱ�� �������� �����Ѵ� */
		int mPrevTime = 0; /* �����Ӱ� DeltaTime�� ���ϱ� ���� ���� */
		int mNowTime = 0; /* �����Ӱ� DeltaTime�� ���ϱ� ���� ���� */
		int mFrameCount = 0; /* ������ ī��Ʈ */

		MSG msg;
		ZeroMemory( &msg, sizeof(msg) );

		while (true)
		{
			if ( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) )
			{
				if ( msg.message == WM_QUIT )
				{
					return true;
				}
				TranslateMessage( &msg );
				DispatchMessage( &msg );
			}
			else{
				mFrameCount++;
				mNowTime = timeGetTime(); // Linux, Mac������ �ȵ��ư�
				if ( mPrevTime == 0.f )
				{
					mPrevTime = mNowTime;
				}
				mDeltaTime = (static_cast<float>(mNowTime - mPrevTime)) / 1000.f;
				mElapsedTime += mDeltaTime;
				mFpsTimer += mDeltaTime;
				if( mFpsTimer > 0.1f ) /* 0.1�� �ֱ� */
				{
					mFps = ((float)mFrameCount) / mFpsTimer;
					mFrameCount = 0;
					mFpsTimer = 0.f;
				}
				mPrevTime = mNowTime;

				if ( GetKeyState(VK_RETURN) & 0x8000 ) {
					mRenderer->ToggleFullscreen();
				}

				/* Render */
				mRenderer->Clear();
				mRenderer->DrawBegin();
				/* Scene */
				mRenderer->DrawEnd();
			}
		}

		return true;
	}

	bool NNWindowsApplication::_CreateWindow( wchar_t* title, int width, int height )
	{
		WNDCLASSEX wcex;
		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = _WndProc;
		wcex.cbClsExtra = NULL;
		wcex.cbWndExtra = NULL;
		wcex.hInstance = mhInstance;
		wcex.hIcon = NULL;
		wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
		wcex.lpszMenuName = NULL;
		wcex.lpszClassName = L"NNApplication";
		wcex.hIconSm = NULL;
		wcex.hIcon = NULL;

		RegisterClassEx( &wcex );

		DWORD style = WS_OVERLAPPEDWINDOW; // Fullscreen�϶��� WS_POPUP���� �ϴ��� �� ������?

		RECT wr = {0, 0, width, height};
		AdjustWindowRect( &wr, style, FALSE );

		mHwnd = CreateWindow( L"NNApplication", title, style, CW_USEDEFAULT, CW_USEDEFAULT,
			wr.right-wr.left, wr.bottom-wr.top, NULL, NULL, mhInstance, NULL);

		ShowWindow( mHwnd, SW_SHOWNORMAL );

		return true;
	}

	bool NNWindowsApplication::_CreateRenderer( bool isFullscreen, RendererStatus rendererStatus )
	{
		switch( rendererStatus )
		{
		case D3D:
			{
				mRenderer = new NND3DRenderer();
				break;
			}
		default:
			return false;
		}

		if ( mRenderer->Init() == false )
			return false;

		return true;
	}

	LRESULT CALLBACK NNWindowsApplication::_WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
	{
		switch( message )
		{
		case WM_CREATE:
			{
				return 0;
			}
		case WM_DESTROY:
			{
				PostQuitMessage(0);
				return 0;
			}
		case WM_PAINT:
			{
				PAINTSTRUCT ps;
				HDC hdc = BeginPaint( hWnd, &ps );
				EndPaint( hWnd, &ps );
				return 0;
			}
		}

		return(DefWindowProc(hWnd,message,wParam,lParam));
	}
}
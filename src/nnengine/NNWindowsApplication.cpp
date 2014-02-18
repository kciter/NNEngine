
/*
 * NNWindowsApplication.cpp
 * 작성자: 이선협
 * 작성일: 2014. 02. 18
 * 마지막으로 수정한 사람:
 * 수정일:
 * 윈도우에서 Application Frame을 생성하기 위한 클래스
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
		float mFpsTimer = 0.f; /* 이 변수의 값을 주기로 프레임을 측정한다 */
		int mPrevTime = 0; /* 프레임과 DeltaTime을 구하기 위한 변수 */
		int mNowTime = 0; /* 프레임과 DeltaTime을 구하기 위한 변수 */
		int mFrameCount = 0; /* 프레임 카운트 */

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
				mNowTime = timeGetTime(); // Linux, Mac에서는 안돌아감
				if ( mPrevTime == 0.f )
				{
					mPrevTime = mNowTime;
				}
				mDeltaTime = (static_cast<float>(mNowTime - mPrevTime)) / 1000.f;
				mElapsedTime += mDeltaTime;
				mFpsTimer += mDeltaTime;
				if( mFpsTimer > 0.1f ) /* 0.1초 주기 */
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

		DWORD style = WS_OVERLAPPEDWINDOW; // Fullscreen일때는 WS_POPUP으로 하던데 그 이유는?

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
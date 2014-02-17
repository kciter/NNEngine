
#include "NNWindowsApplication.h"

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

	bool NNWindowsApplication::Init( wchar_t* title, int width, int height, RendererStatus rendererStatus )
	{
		if ( __super::Init( title, width, height, rendererStatus ) == false )
		{
			return false;
		}

		if ( _CreateWindow( title, width, height ) == false )
		{
			return false;
		}

		return true;
	}
	bool NNWindowsApplication::Release()
	{

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
				mNowTime = timeGetTime();
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

				/* Render */
			}
		}

		return true;
	}

	bool NNWindowsApplication::_CreateWindow( wchar_t* title, int width, int height )
	{

	}
	LRESULT CALLBACK NNWindowsApplication::_WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
	{

	}
}
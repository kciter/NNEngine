
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
				mNowTime = timeGetTime();
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
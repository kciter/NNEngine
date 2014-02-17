
/*
 * NNBaseApplication.cpp
 * 작성자: 이선협
 * 작성일: 2014. 02. 18
 * 마지막으로 수정한 사람:
 * 수정일:
 * Application Frame을 생성하기 위한 기본 클래스
 */

#include "NNBaseApplication.h"

#include "NNRenderer.h"

namespace NNEngine
{
	NNBaseApplication::NNBaseApplication()
		: mTitle(nullptr), mScreenWidth(0), mScreenHeight(0),
		  mFps(0.f), mElapsedTime(0.f), mDeltaTime(0),
		  mRendererStatus(RendererStatus::NONE), mRenderer(nullptr)
	{
	}

	NNBaseApplication::~NNBaseApplication()
	{

	}

	bool NNBaseApplication::Init( wchar_t* title, int width, int height, RendererStatus rendererStatus )
	{
		mTitle = title;
		mScreenWidth = width;
		mScreenHeight = height;
		mRendererStatus = rendererStatus;

		if ( _CreateRenderer( rendererStatus ) == false )
		{
			return false;
		}

		return true;
	}
	bool NNBaseApplication::Release()
	{
		return true;
	}
	bool NNBaseApplication::Run()
	{
		return true;
	}

	bool NNBaseApplication::_CreateRenderer( RendererStatus rendererStatus )
	{
		return true;
	}
}
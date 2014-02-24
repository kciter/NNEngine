
/*
 * NNOpenGLRenderer.cpp
 * 작성자: 이선협
 * 작성일: 2014. 02. 19
 * 마지막으로 수정한 사람:
 * 수정일:
 * OpenGL을 사용하여 만들어진 렌더러 클래스
 */

#include "NNOpenGLRenderer.h"

namespace NNEngine
{
	NNOpenGLRenderer::NNOpenGLRenderer()
	{
	}
	NNOpenGLRenderer::~NNOpenGLRenderer()
	{
	}

	bool NNOpenGLRenderer::Init()
	{
		return true;
	}
	bool NNOpenGLRenderer::Release()
	{
		return true;
	}
	bool NNOpenGLRenderer::DrawBegin()
	{
		glBegin( GL_POINTS );
		return true;
	}
	bool NNOpenGLRenderer::DrawEnd()
	{
		glEnd();
		glFlush();
		return true;
	}
	bool NNOpenGLRenderer::Clear()
	{
		glClearColor( 0.f, 0.f, 0.f, 1.f );
		glClear( GL_COLOR_BUFFER_BIT );
		return true;
	}
	bool NNOpenGLRenderer::ToggleFullscreen()
	{
		return true;
	}
}
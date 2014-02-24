
/*
 * NNOpenGLRenderer.cpp
 * �ۼ���: �̼���
 * �ۼ���: 2014. 02. 19
 * ���������� ������ ���:
 * ������:
 * OpenGL�� ����Ͽ� ������� ������ Ŭ����
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
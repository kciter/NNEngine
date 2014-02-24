
/*
 * NNOpenGLRenderer.h
 * �ۼ���: �̼���
 * �ۼ���: 2014. 02. 19
 * ���������� ������ ���:
 * ������:
 * OpenGL�� ����Ͽ� ������� ������ Ŭ����
 */

#ifndef __NNOPENGLRENDERER_H__
#define __NNOPENGLRENDERER_H__

#include "NNBaseRenderer.h"

#if defined(_WIN32) || defined(_WIN64)
#include <Windows.h>
#endif

#include <GL/GL.h>
#include <GL/GLU.h>

namespace NNEngine
{
	class NNOpenGLRenderer : public NNBaseRenderer
	{
	public:
		NNOpenGLRenderer();
		virtual ~NNOpenGLRenderer();

	public:
		/* Init
		 * Return Type: bool
		 * NNRenderer���� ��ӹ޾� �������̵�
		 */
		bool Init();

		/* Release
		 * Return Type: bool
		 * NNRenderer���� ��ӹ޾� �������̵�
		 */
		bool Release();

		/* DrawBegin
		 * Return Type: bool
		 * NNRenderer���� ��ӹ޾� �������̵�
		 */
		bool DrawBegin();

		/* DrawEnd
		 * Return Type: bool
		 * NNRenderer���� ��ӹ޾� �������̵�
		 */
		bool DrawEnd();

		/* Clear
		 * Return Type: bool
		 * NNRenderer���� ��ӹ޾� �������̵�
		 */
		bool Clear();

		/* ToggleFullscreen
		 * Return Type: bool
		 * NNRenderer���� ��ӹ޾� �������̵�
		 */
		bool ToggleFullscreen();
	};
}

#endif
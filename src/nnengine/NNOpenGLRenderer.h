
/*
 * NNOpenGLRenderer.h
 * 작성자: 이선협
 * 작성일: 2014. 02. 19
 * 마지막으로 수정한 사람:
 * 수정일:
 * OpenGL을 사용하여 만들어진 렌더러 클래스
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
		 * NNRenderer에서 상속받아 오버라이딩
		 */
		bool Init();

		/* Release
		 * Return Type: bool
		 * NNRenderer에서 상속받아 오버라이딩
		 */
		bool Release();

		/* DrawBegin
		 * Return Type: bool
		 * NNRenderer에서 상속받아 오버라이딩
		 */
		bool DrawBegin();

		/* DrawEnd
		 * Return Type: bool
		 * NNRenderer에서 상속받아 오버라이딩
		 */
		bool DrawEnd();

		/* Clear
		 * Return Type: bool
		 * NNRenderer에서 상속받아 오버라이딩
		 */
		bool Clear();

		/* ToggleFullscreen
		 * Return Type: bool
		 * NNRenderer에서 상속받아 오버라이딩
		 */
		bool ToggleFullscreen();
	};
}

#endif
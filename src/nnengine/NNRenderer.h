
/*
 * NNRenderer.h
 * 작성자: 이선협
 * 작성일: 2014. 02. 18
 * 마지막으로 수정한 사람:
 * 수정일:
 * 렌더러 인터페이스 클래스
 */

#ifndef __NNRENDERER_H__
#define __NNRENDERER_H__

namespace NNEngine
{
	enum RendererStatus
	{
		NONE,
		D3D,
		OPENGL,
	};

	class NNRenderer
	{
	public:
		NNRenderer();
		virtual ~NNRenderer();

	public:
		virtual bool Init() = 0;
		virtual bool Release() = 0;

		virtual bool DrawBegin() = 0;
		virtual bool DrawEnd() = 0;
		virtual bool Clear() = 0;
	};
}

#endif
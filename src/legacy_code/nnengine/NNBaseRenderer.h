
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

	class NNBaseRenderer
	{
	public:
		NNBaseRenderer() : mIsFullscreen(false) {}
		virtual ~NNBaseRenderer(){}

	public:
		/* Init
		 * Return Type: bool
		 * isFullscreen: 풀스크린 여부
		 * 렌더러를 초기화하는 함수
		 */
		virtual bool Init() = 0;

		/* Release
		 * Return Type: bool
		 * 렌더러를 삭제하는 함수
		 */
		virtual bool Release() = 0;

		/* DrawBegin
		 * Return Type: bool
		 * 렌더러에서 그리기 시작을 나타냄
		 */
		virtual bool DrawBegin() = 0;

		/* DrawEnd
		 * Return Type: bool
		 * 렌더러에서 그리기 끝을 나타냄
		 */
		virtual bool DrawEnd() = 0;

		/* Clear
		 * Return Type: bool
		 * 렌더러에서 그린 화면을 지워줌
		 */
		virtual bool Clear() = 0;

		/* ToggleFullscreen
		 * Return Type: bool
		 * 풀스크린, 윈도우모드 전환
		 */
		virtual bool ToggleFullscreen() = 0;

	protected:
		bool mIsFullscreen;
	};
}

#endif
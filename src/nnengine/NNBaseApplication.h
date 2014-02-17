
/*
 * NNBaseApplication.h
 * 작성자: 이선협
 * 작성일: 2014. 02. 18
 * 마지막으로 수정한 사람:
 * 수정일:
 * Application Frame을 생성하기 위한 기본 클래스
 */

#ifndef __NNBASEAPPLICATION_H__
#define __NNBASEAPPLICATION_H__

namespace NNEngine
{
	enum RendererStatus;
	class NNRenderer;

	class NNBaseApplication
	{
	public:
		/* 생성자와 소멸자 */
		NNBaseApplication();
		virtual ~NNBaseApplication();

	public:
		/* Init 
		 * Return Type: bool
		 * title: 어플리케이션의 타이틀명
		 * width: 어플리케이션 프레임의 가로길이
		 * height: 어플리케이션 프레임의 세로길이
		 * rendererStatus: 렌더러 종류 (D3D, OpenGL, ...)
		 * 어플리케이션을 초기화하는 함수. 프레임창을 생성함
		 * 성공하면 true를 반환한다.
		 */
		virtual bool Init( wchar_t* title, int width, int height, RendererStatus rendererStatus );

		/* Release
		 * Return Type: bool
		 * 어플리케이션 프레임을 삭제함과 동시에 할당한
		 * 메모리를 전부 delete함
		 * 성공하면 true를 반환한다.
		 */
		virtual bool Release();

		/* Release
		 * Return Type: bool
		 * 메세지 루프를 실행한다.
		 * 성공하면 true를 반환한다.
		 */
		virtual bool Run();

	public:
		/* GetTitle
		 * Return Type: wchar_t*
		 * 어플리케이션의 타이틀명을 반환한다.
		 */
		inline wchar_t* GetTitle() const { return mTitle; }

		/* GetScreenWidth
		 * Return Type: int
		 * 어플리케이션 프레임의 가로길이를 반환한다.
		 */
		inline int GetScreenWidth() const { return mScreenWidth; }

		/* GetScreenHeight
		 * Return Type: int
		 * 어플리케이션 프레임의 세로길이를 반환한다.
		 */
		inline int GetScreenHeight() const { return mScreenHeight; }

		/* GetFPS
		 * Return Type: float
		 * 렌더러의 FPS(Frames Per Second)를 반환한다.
		 */
		inline float GetFPS() const { return mFps; }

		/* GetElapsedTime
		 * Return Type: float
		 * 어플리케이션이 Run 된 후 지금까지 실행된 시간을 반환한다.
		 */
		inline float GetElapsedTime() const { return mElapsedTime; }

		/* GetDeltaTime
		 * Return Type: int
		 * 지난 프레임과 현재프레임의 시간 차를 반환한다.
		 */
		inline float GetDeltaTime() const { return mDeltaTime; }

		/* GetRendererStatus
		 * Return Type: RendererStatus
		 * 현재 사용되는 렌더러 타입을 반환한다.
		 */
		inline RendererStatus GetRendererStatus() const { return mRendererStatus; }

		/* GetRenderer
		 * Return Type: NNRenderer
		 * 현재 사용하는 렌더러를 반환한다.
		 */
		inline NNRenderer* GetRenderer() const { return mRenderer; }

	private:
		/* _CreateRenderer
		* rendererStatus: 렌더러 종류 (D3D, OpenGL, ...)
		* 렌더러를 생성하는 함수.
		*/
		bool _CreateRenderer( RendererStatus rendererStatus );

	protected:
		wchar_t* mTitle;
		int mScreenWidth;
		int mScreenHeight;

		float mFps;
		float mElapsedTime;
		float mDeltaTime;

		RendererStatus mRendererStatus;
		NNRenderer* mRenderer;
	};
}
#endif
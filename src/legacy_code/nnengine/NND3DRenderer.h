
/*
 * NND3DRenderer.h
 * 작성자: 이선협
 * 작성일: 2014. 02. 18
 * 마지막으로 수정한 사람:
 * 수정일:
 * Direct3D 9.0 SDK를 사용하여 만들어진 렌더러 클래스
 */

#ifndef __NND3DRENDERER_H__
#define __NND3DRENDERER_H__

#if defined(_WIN32) || defined(_WIN64)

#include "NNBaseRenderer.h"
#include <d3dx9.h>

namespace NNEngine
{
	class NND3DRenderer : public NNBaseRenderer
	{
	public:
		/* 생성자와 소멸자 */
		NND3DRenderer();
		virtual ~NND3DRenderer();

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

	public:
		/* GetD3D
		 * Return Type: LPDIRECT3DP
		 * D3D 객체를 반환한다
		 */
		LPDIRECT3D9 GetD3D() const { return mD3D; }

		/* GetDevice
		 * Return Type: LPDIRECT3DDEVICE9
		 * D3D Device 객체를 반환
		 */
		LPDIRECT3DDEVICE9 GetDevice() const { return mD3DDevice; }

		/* GetSpriect
		 * Return Type: LPD3DXSPRITE
		 * D3D Sprite 객체를 반환한다
		 */
		LPD3DXSPRITE GetSprite() const { return mSprite; }

	private:
		LPDIRECT3D9 mD3D;
		LPDIRECT3DDEVICE9 mD3DDevice;
		LPD3DXSPRITE mSprite;
	};
}

#endif

#endif
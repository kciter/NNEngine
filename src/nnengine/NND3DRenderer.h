
/*
 * NND3DRenderer.h
 * �ۼ���: �̼���
 * �ۼ���: 2014. 02. 18
 * ���������� ������ ���:
 * ������:
 * Direct3D 9.0 SDK�� ����Ͽ� ������� ������ Ŭ����
 */

#ifndef __NND3DRENDERER_H__
#define __NND3DRENDERER_H__

#if defined(_WIN32) || defined(_WIN64)

#include "NNRenderer.h"
#include <d3dx9.h>

namespace NNEngine
{
	class NND3DRenderer : public NNRenderer
	{
	public:
		NND3DRenderer();
		virtual ~NND3DRenderer();

	public:
		bool Init();
		bool Release();

		bool DrawBegin();
		bool DrawEnd();
		bool Clear();

	public:
		LPDIRECT3D9 GetD3D() const { return mD3D; }
		LPDIRECT3DDEVICE9 GetDevice() const { return mD3DDevice; }
		LPD3DXSPRITE GetSprite() const { return mSprite; }

	private:
		LPDIRECT3D9 mD3D;
		LPDIRECT3DDEVICE9 mD3DDevice;
		LPD3DXSPRITE mSprite;
	};
}

#endif

#endif

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

#include "NNBaseRenderer.h"
#include <d3dx9.h>

namespace NNEngine
{
	class NND3DRenderer : public NNBaseRenderer
	{
	public:
		/* �����ڿ� �Ҹ��� */
		NND3DRenderer();
		virtual ~NND3DRenderer();

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

	public:
		/* GetD3D
		 * Return Type: LPDIRECT3DP
		 * D3D ��ü�� ��ȯ�Ѵ�
		 */
		LPDIRECT3D9 GetD3D() const { return mD3D; }

		/* GetDevice
		 * Return Type: LPDIRECT3DDEVICE9
		 * D3D Device ��ü�� ��ȯ
		 */
		LPDIRECT3DDEVICE9 GetDevice() const { return mD3DDevice; }

		/* GetSpriect
		 * Return Type: LPD3DXSPRITE
		 * D3D Sprite ��ü�� ��ȯ�Ѵ�
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
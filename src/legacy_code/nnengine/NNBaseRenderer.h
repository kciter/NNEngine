
/*
 * NNRenderer.h
 * �ۼ���: �̼���
 * �ۼ���: 2014. 02. 18
 * ���������� ������ ���:
 * ������:
 * ������ �������̽� Ŭ����
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
		 * isFullscreen: Ǯ��ũ�� ����
		 * �������� �ʱ�ȭ�ϴ� �Լ�
		 */
		virtual bool Init() = 0;

		/* Release
		 * Return Type: bool
		 * �������� �����ϴ� �Լ�
		 */
		virtual bool Release() = 0;

		/* DrawBegin
		 * Return Type: bool
		 * ���������� �׸��� ������ ��Ÿ��
		 */
		virtual bool DrawBegin() = 0;

		/* DrawEnd
		 * Return Type: bool
		 * ���������� �׸��� ���� ��Ÿ��
		 */
		virtual bool DrawEnd() = 0;

		/* Clear
		 * Return Type: bool
		 * ���������� �׸� ȭ���� ������
		 */
		virtual bool Clear() = 0;

		/* ToggleFullscreen
		 * Return Type: bool
		 * Ǯ��ũ��, �������� ��ȯ
		 */
		virtual bool ToggleFullscreen() = 0;

	protected:
		bool mIsFullscreen;
	};
}

#endif
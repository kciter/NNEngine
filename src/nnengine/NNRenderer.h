
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
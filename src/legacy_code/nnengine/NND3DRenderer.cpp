
/*
 * NND3DRenderer.cpp
 * 작성자: 이선협
 * 작성일: 2014. 02. 18
 * 마지막으로 수정한 사람:
 * 수정일:
 * Direct3D 9.0 SDK를 사용하여 만들어진 렌더러 클래스
 */

#if defined(_WIN32) || defined(_WIN64)

#include "NND3DRenderer.h"

#include "NNWindowsApplication.h"

namespace NNEngine
{
	NND3DRenderer::NND3DRenderer()
		: mD3D(nullptr), mD3DDevice(nullptr), mSprite(nullptr)
	{
	}
	NND3DRenderer::~NND3DRenderer()
	{
	}

	bool NND3DRenderer::Init()
	{
		HRESULT hr = 0;
		D3DPRESENT_PARAMETERS d3dPresentParameters;

		mD3D = nullptr;
		mD3DDevice = nullptr;

		mD3D = Direct3DCreate9( D3D_SDK_VERSION );

		ZeroMemory( &d3dPresentParameters, sizeof(d3dPresentParameters) );

		D3DMULTISAMPLE_TYPE mst = D3DMULTISAMPLE_NONE;
		/* 샘플링
		switch(4)
		{
		case 1: mst = D3DMULTISAMPLE_NONMASKABLE;break;
		case 2: mst = D3DMULTISAMPLE_2_SAMPLES;break;
		case 3: mst = D3DMULTISAMPLE_3_SAMPLES;break;
		case 4: mst = D3DMULTISAMPLE_4_SAMPLES;break;
		case 5: mst = D3DMULTISAMPLE_5_SAMPLES;break;
		case 6: mst = D3DMULTISAMPLE_6_SAMPLES;break;
		case 7: mst = D3DMULTISAMPLE_7_SAMPLES;break;
		case 8: mst = D3DMULTISAMPLE_8_SAMPLES;break;
		case 9: mst = D3DMULTISAMPLE_9_SAMPLES;break;
		case 10: mst = D3DMULTISAMPLE_10_SAMPLES;break;
		case 11: mst = D3DMULTISAMPLE_11_SAMPLES;break;
		case 12: mst = D3DMULTISAMPLE_12_SAMPLES;break;
		case 13: mst = D3DMULTISAMPLE_13_SAMPLES;break;
		case 14: mst = D3DMULTISAMPLE_14_SAMPLES;break;
		case 15: mst = D3DMULTISAMPLE_15_SAMPLES;break;
		case 16: mst = D3DMULTISAMPLE_16_SAMPLES;break;
		default: mst = D3DMULTISAMPLE_NONE;break;
		}
		*/
		d3dPresentParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
		d3dPresentParameters.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
		d3dPresentParameters.BackBufferWidth = NNWindowsApplication::GetInstance()->GetScreenWidth();
		d3dPresentParameters.BackBufferHeight = NNWindowsApplication::GetInstance()->GetScreenHeight();
		d3dPresentParameters.BackBufferFormat = D3DFMT_A8R8G8B8;
		d3dPresentParameters.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;// D3DPRESENT_INTERVAL_IMMEDIATE;
		d3dPresentParameters.hDeviceWindow = NNWindowsApplication::GetInstance()->GetHWND();
		d3dPresentParameters.Windowed = !NNWindowsApplication::GetInstance()->IsFullscreen();

		hr = mD3D->CheckDeviceMultiSampleType( D3DADAPTER_DEFAULT,
			D3DDEVTYPE_HAL, d3dPresentParameters.BackBufferFormat, !NNWindowsApplication::GetInstance()->IsFullscreen(), mst, NULL );

		if( SUCCEEDED(hr) ) { d3dPresentParameters.MultiSampleType = mst; }
		else { return false; }

		hr = mD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, NNWindowsApplication::GetInstance()->GetHWND(),
			D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dPresentParameters, &mD3DDevice ); //D3DCREATE_SOFTWARE_VERTEXPROCESSING

		if( FAILED(hr) ) { return false; }

		hr = D3DXCreateSprite( mD3DDevice, &mSprite );

		if( FAILED(hr) ) { return false; }

		return true;
	}
	bool NND3DRenderer::Release()
	{
		mD3D->Release();
		mD3DDevice->Release();
		return true;
	}

	bool NND3DRenderer::DrawBegin()
	{
		if ( mD3DDevice == nullptr )
			return false;

		if( FAILED(mD3DDevice->BeginScene()) )
			return false;

		return true;
	}
	bool NND3DRenderer::DrawEnd()
	{
		if ( mD3DDevice == nullptr )
			return false;

		if( FAILED(mD3DDevice->EndScene()) )
			return false;

		if( FAILED(mD3DDevice->Present( NULL, NULL, NULL, NULL )) )
			return false;

		return true;
	}
	bool NND3DRenderer::Clear()
	{
		if ( mD3DDevice == nullptr )
			return false;

		if( FAILED(mD3DDevice->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(255,0,0,0), 1.0f, 0 )) )
			return false;

		return true;
	}
	bool NND3DRenderer::ToggleFullscreen()
	{
		D3DPRESENT_PARAMETERS d3dPresentParameters;

		ZeroMemory( &d3dPresentParameters, sizeof(d3dPresentParameters) );

		d3dPresentParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
		d3dPresentParameters.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
		d3dPresentParameters.BackBufferWidth = NNWindowsApplication::GetInstance()->GetScreenWidth();
		d3dPresentParameters.BackBufferHeight = NNWindowsApplication::GetInstance()->GetScreenHeight();
		d3dPresentParameters.BackBufferFormat = D3DFMT_A8R8G8B8;
		d3dPresentParameters.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;// D3DPRESENT_INTERVAL_IMMEDIATE;
		d3dPresentParameters.hDeviceWindow = NNWindowsApplication::GetInstance()->GetHWND();

		if ( mD3DDevice == nullptr )
			return false;

		if ( NNWindowsApplication::GetInstance()->IsFullscreen() == false )
		{
			d3dPresentParameters.Windowed = false;

			SetWindowLong( NNWindowsApplication::GetInstance()->GetHWND(), GWL_STYLE, WS_POPUPWINDOW );
			SetWindowPos( NNWindowsApplication::GetInstance()->GetHWND(), HWND_TOP, 0, 0, 0, 0,
				SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW );

			if ( FAILED(mD3DDevice->Reset(&d3dPresentParameters)) )
				return false;

			NNWindowsApplication::GetInstance()->mIsFullscreen = true;
		}
		else
		{
			d3dPresentParameters.Windowed = true;

			SetWindowLong( NNWindowsApplication::GetInstance()->GetHWND(), GWL_STYLE, WS_OVERLAPPEDWINDOW );
			SetWindowPos( NNWindowsApplication::GetInstance()->GetHWND(), HWND_TOP, 0, 0, 
				NNWindowsApplication::GetInstance()->GetScreenWidth(), NNWindowsApplication::GetInstance()->GetScreenHeight(), 
				SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW );

			if ( FAILED(mD3DDevice->Reset(&d3dPresentParameters)) )
				return false;

			NNWindowsApplication::GetInstance()->mIsFullscreen = false;
		}

		return true;
	}
}

#endif
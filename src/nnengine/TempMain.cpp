
#include <stdio.h>
#include "NNEngine.h"

using namespace NNEngine;

int main() {
	if ( NNWindowsApplication::GetInstance()->Init( L"Test", 1024, 768, RendererStatus::D3D ) == true )
	{
		NNWindowsApplication::GetInstance()->Run();
		NNWindowsApplication::GetInstance()->Release();
	}
	return 0;
}
#include "iostream"

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>

#include <shellapi.h> // For CommandLineToArgvW
#if defined(min)

#undef min

#endif



#if defined(max)

#undef max


#endif

#if defined(CreateWindow)

#undef CreateWindow

#endif

#include <wrl.h>


using namespace Microsoft::WRL;
using namespace std;
#include <d3d12.h>

#include <dxgi1_6.h>

#include <d3dcompiler.h>

#include <DirectXMath.h>
#include "vector"



// D3D12 extension library.

#include <d3dx12.h>
#include <immintrin.h>


// STL Headers

#include <algorithm>
#include "numeric"

#include <cassert>

#include <chrono>

#include "RENDER.h"
#include "CORE.h"
#include "DATATYPES.h"
#include "ECS.h"
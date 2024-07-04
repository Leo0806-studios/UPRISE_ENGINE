
//#include "glad.h"
//#include "glad.h"
#ifndef _PCH_



#define _PCH_
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

#include "vector"

// D3D12 extension library.
#include <immintrin.h>
// STL Headers
#include <algorithm>
#include "numeric"
#include <cassert>
#include <chrono>
#include "string"
#include "vector"
#include "memory"
#include "filesystem"
#include <iostream>


//#include "RENDER.h"
//#include "CORE.h"
//#include "DATATYPES.h"
//#include "ECS.h"
//
//#include "MESSAGES.h"
#endif // _PCH_
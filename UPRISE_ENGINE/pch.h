
//#include "glad.h"
//#include "glad.h"
#ifndef _PCH_
//C : \Users\leo08\source\repos\Neuer Ordner(2)\NativeLibrary\bin\release\net8.0\win - x64\publish


#define _PCH_
#include "tracy/Tracy.hpp"
#include "tracy/TracyC.h"
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#define symLoad GetProcAddress 


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
#include "memory"
#include "filesystem"
#include <iostream>
#include <array>
#include <bitset>
#include <intrin.h>
#include "sysinfoapi.h"
#include "stb_image.h"
#include <fstream>
#include <sstream>
#include "functional"
#include "mutex"
#include <xmmintrin.h>
#include <emmintrin.h>
#include <cmath>
#include "nlohmann/json.hpp"

#ifndef _assimp_
#define _assimp_

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>


#endif // !_assimp_
//#include "RENDER.h"
//#include "CORE.h"
//#include "DATATYPES.h"
//#include "ECS.h"
//
//#include "MESSAGES.h"

inline void ThrowIfFailed(HRESULT hr)

{


    if (FAILED(hr))


    {


        throw std::exception();


    }

}

using TypeInfoRef = std::reference_wrapper<const std::type_info>;

struct Hasher
{
    std::size_t operator()(TypeInfoRef code) const
    {
        return code.get().hash_code();
    }
};

struct EqualTo
{
    bool operator()(TypeInfoRef lhs, TypeInfoRef rhs) const
    {
        return lhs.get() == rhs.get();
    }
};
template<class _Ty,class _Arg>
_Ty CallCSharpFunction(const WCHAR* patrh,char* functionName,_Arg argument) {
    const WCHAR* addrs = L"C:\\Users\\leo08\\source\\repos\\Neuer Ordner(2)\\NativeLibrary\\bin\\release\\net8.0\\win - x64\\publish";
    HINSTANCE handle = LoadLibrary(patrh);
    typedef _Ty((*externFuction)(_Arg));
    externFuction Function = (externFuction)symLoad(handle, functionName);
    _Ty result = Function(argument);
    return result;
}
#define GameObject_ std::shared_ptr<GameObject>
#endif // _PCH_
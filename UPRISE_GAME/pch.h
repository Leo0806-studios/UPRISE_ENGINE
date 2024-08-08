
//#include "glad.h"
//#include "glad.h"
#ifndef _PCH_
//C : \Users\leo08\source\repos\Neuer Ordner(2)\NativeLibrary\bin\release\net8.0\win - x64\publish


#define _PCH_
#define DEBUG_Engine

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
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "imgui_stdlib.h"
//#include "imgui_impl_opengl3_loader.h"
//#include "RENDER.h"
//#include "Header/CORE/CORE.h"
//#include "Header/DATATYPES/D_DATATYPES.h"
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
template<class _Ty, class _Arg>
_Ty CallCSharpFunction(const WCHAR* patrh, char* functionName, _Arg argument) {
    const WCHAR* addrs = L"C:\\Users\\leo08\\source\\repos\\Neuer Ordner(2)\\NativeLibrary\\bin\\release\\net8.0\\win - x64\\publish";
    HINSTANCE handle = LoadLibrary(patrh);
    typedef _Ty((*externFuction)(_Arg));
    externFuction Function = (externFuction)symLoad(handle, functionName);
    _Ty result = Function(argument);
    return result;
}
#define GameObject_ std::shared_ptr<GameObject>
#define Component_ std::shared_ptr<CORE::Behaviour>
#define VEC(X) std::vector<X>
#ifdef DEBUG_Engine
#define TrPr(V,N)   TracyCZoneN(V, N, true); 
#define TrPrE(V) TracyCZoneEnd(V);


//#define ScPr(name) scopedProfiler profiler(   name );  
#else
#define ScPr;
#define TrPr(V,N)    ;
#define TrPrE(V) ;
#endif //DEBUG_Engine
#ifndef globlist
#define globlist
namespace CORE {
    class Behaviour;
}
class fact {
public:
    static VEC(std::shared_ptr<CORE::Behaviour>) inst;
    static VEC(std::any) anys;
    //static std::function<std::unique_ptr<Behaviour>()> CreatorFunc;
    using  CreatorFunc = std::function<std::shared_ptr<CORE::Behaviour>()>;


    static std::map<std::string, CreatorFunc> creators;
};

#endif // !globlist


//class BaseFactory {
//public:
//    using CreatorFunc = std::function<std::unique_ptr<Behaviour>()>;
//
//    // Singleton instance accessor
//    static BaseFactory& getInstance() {
//        static BaseFactory instance;
//        return instance;
//    }
//
//    // Registers a class creation function with a class name
//    void registerClass(const std::string& className, CreatorFunc creator) {
//        creators[className] = creator;
//    }
//
//    // Creates an instance of a registered class by its name
//    std::unique_ptr<Behaviour> create(const std::string& className) {
//        auto it = creators.find(className);
//        if (it != creators.end()) {
//            return it->second();
//        }
//        return nullptr;
//    }
//
//    // Creates instances of all registered classes
//    std::vector<std::unique_ptr<Behaviour>> createAll() {
//        std::vector<std::unique_ptr<Behaviour>> instances;
//        for (const auto& pair : creators) {
//            instances.push_back(pair.second());
//        }
//        return instances;
//    }
//
//private:
//    std::map<std::string, CreatorFunc> creators;  // Map from class name to creation function
//};
//
//template <typename T>
//class Registrar {
//public:
//    explicit Registrar(const std::string& className) {
//        BaseFactory::getInstance().registerClass(className, []() -> std::unique_ptr<Behaviour> {
//            return std::make_unique<T>();
//            });
//    }
//};
#endif // _PCH_
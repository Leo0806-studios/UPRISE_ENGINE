
//#include "glad.h"
//#include "glad.h"
#ifndef _PCH_
//C : \Users\leo08\source\repos\Neuer Ordner(2)\NativeLibrary\bin\release\net8.0\win - x64\publish


#define _PCH_
#define DEBUG_Engine
//import <string>

#include "tracy/Tracy.hpp"
#include "tracy/TracyC.h"
//#include "tracy/TracyOpenGL.hpp"
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
//import Windows;

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
;
using namespace Microsoft::WRL;
//using namespace std;

#include "vector"
//
//// D3D12 extension library.

//// STL Headers
#include <algorithm>
#include "numeric"
#include <cassert>
#include <chrono>
#include "string"




#include "memory"
//
//
//
//
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

#include <cmath>
#ifndef JSON__
#define JSON__
#include "nlohmann/json.hpp"
#endif

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


//#include "boost/compute.hpp"
//#include <boost/compute/algorithm/transform.hpp>
//#include <boost/compute/container/vector.hpp>
//#include <boost/compute/functional/math.hpp>
//#include <boost/compute/types/complex.hpp>
//import BOOST_COMPUTE;
//#include "imgui_impl_opengl3_loader.h"
//#include "RENDER.h"
//#include "HeaderE/CORE/CORE.h"
//#include "HeaderE/DATATYPES/D_DATATYPES.h"
//#include "ECS.h"
//
//#include "MESSAGES.h"

//import std;


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
    static std::vector<std::shared_ptr<CORE::Behaviour>> inst;
    //static VEC(std::any) anys;
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


#ifdef Force_inline
#define _inline_func __forceinline
#else
#define _inline_func __inline
#endif
_inline_func VEC(float) Tofloat(const __m128& a) {
    return std::vector<float>(4, (*(const float*)&a));
}
//class DATALINK;
//enum GameMode {
//    GameMode_Paused,
//    GameMode_Play,
//    GameMode_Stoped
//};
#define TD(t,r,p) typedef r(*t)(p);
#define FUNCI(x,y,z)(IMPORTANT::x)GetProcAddress(IMPORTANT::y,z);
#define FUNCE(x,y,z)(EDITOR_IMPORTANT::x)GetProcAddress(EDITOR_IMPORTANT::y,z);
//namespace compute = boost::compute;
//class EDITOR_IMPORTANT {
//public:
//    static  const WCHAR* addrs;
//
//    static HINSTANCE EDITORHANDLE;
//    TD(INIT, void, ImGuiContext* ctx)
//        TD(DRAW, void, void)
//        TD(SHUTDOWN, void, void)
//        ;
//    static SHUTDOWN Shutdown_Editor;
//    static INIT init_EDITOR;
//    static DRAW Draw_EDITOR;
//};
//class IMPORTANT {
//public:
//
//   static DATALINK* LINK;
//   static  const WCHAR* addrs;
//   static HINSTANCE handle; 
//   typedef void (*create)();
//   typedef void(*print)();
//   typedef void(*externFuction)(DATALINK* DATA);
//   typedef DATALINK* (*GetDatabase)();
//   typedef void(*SetDatabase)(DATALINK*);
//   typedef void(*BEHAVIOUR_UPDATE)();
//   typedef void(*BEHAVIOUR_UPDATE_AWAKE)();
//   typedef void(*BEHAVIOUR_UPDATE_START)();
//   typedef void(*PHYSICS_UPDATE)();
//   typedef void(*DRAW_EDITOR)();
//   typedef void(*STOP)();
//
//   //static test* inst = NULL;
//
//  static create CREATE;
//  static print PRINT;
//  static externFuction Function;
//  static SetDatabase Set;
//  static GetDatabase Get;
//  static BEHAVIOUR_UPDATE B_Up;
//  static BEHAVIOUR_UPDATE_AWAKE B_Up_A;
//  static BEHAVIOUR_UPDATE_START B_Up_S;
//  static PHYSICS_UPDATE P_Up;
//  static DRAW_EDITOR D_E;
//  static STOP Stop;
//  static GameMode mode;
//  //static boost::compute::device device;
// // static boost::compute::context context;
//  //static boost::compute::command_queue cq;
//  
//};
#ifndef _OVERLOADLOCK_
#define _OVERLOADLOCK_

#define MEM_PROFILE 1;
#if MEM_PROFILE ==1
void* operator new(std::size_t count);

void operator delete(void* ptr);

#endif
#endif // !1

#endif // _PCH_
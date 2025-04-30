// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com



#pragma once
#ifndef UE_GLOBAL_
#define UE_GLOBAL_
#pragma warning (push)
#pragma warning(disable:4005)
#pragma region EXPORTIMPORT_DEFINES


#ifdef UPRISEENGINECORE_EXPORTS

#define UPRISE_CORE_API __declspec(dllexport)
#define UPRISE_CORE_API_EXPORTS
#else
#define UPRISE_CORE_API __declspec(dllimport)
#define UPRISE_CORE_API_EXPORTS
#endif
#ifdef UPRISEENGINEECS_EXPORTS
#define UPRISE_ECS_API __declspec(dllexport)
#define UPRISE_ECS_API_EXPORTS export
#else
#define UPRISE_ECS_API __declspec(dllimport)
#define UPRISE_ECS_API_EXPORTS
#endif // UPRISEENGINEECS_EXPORTS




#ifdef UPRISEENGINERENDER_EXPORTS
#define UPRISE_RENDER_API __declspec(dllexport)
#define UPRISE_RENDER_API_EXPORTS export
#else
#define UPRISE_RENDER_API __declspec(dllimport)
#define UPRISE_RENDER_API_EXPORTS
#endif // UPRISEENGINERENDER_EXPORTS

#ifdef UPRISEENGINECOMMONRENDERCOMPS_EXPORTS
#define UPRISE_COMMON_RENDER_COMPS_API __declspec(dllexport)
#define UPRISE_COMMON_RENDER_COMPS_API_EXPORTS export
#else
#define UPRISE_COMMON_RENDER_COMPS_API __declspec(dllimport)
#define UPRISE_COMMON_RENDER_COMPS_API_EXPORTS
#endif // UPRISEENGINECOMMONRENDERCOMPS_EXPORTS


#ifdef UPRISEENGINEDX11RENDER_EXPORTS
#define UPRISE_DX11_RENDER_API __declspec(dllexport)
#define UPRISE_DX11_RENDER_API_EXPORTS export
#else
#define UPRISE_DX11_RENDER_API __declspec(dllimport)
#define UPRISE_DX11_RENDER_API_EXPORTS
#endif // UPRISEENGINEDX11RENDER_EXPORTS

#ifdef UPRISEENGINEDX12RENDER_EXPORTS
#define UPRISE_DX12_RENDER_API __declspec(dllexport)
#define UPRISE_DX12_RENDER_API_EXPORTS export
#else
#define UPRISE_DX12_RENDER_API __declspec(dllimport)
#define UPRISE_DX12_RENDER_API_EXPORTS
#endif // UPRISEENGINEDX12RENDER_EXPORTS

#ifdef UPRISEENGINEOPENGLRENDER_EXPORTS
#define UPRISE_OPENGL_RENDER_API __declspec(dllexport)
#define UPRISE_OPENGL_RENDER_API_EXPORTS export
#else
#define UPRISE_OPENGL_RENDER_API __declspec(dllimport)
#define UPRISE_OPENGL_RENDER_API_EXPORTS
#endif // UPRISEENGINEOPENGLRENDER_EXPORTS

#ifdef UPRISEENGINEVULKANRENDER_EXPORTS
#define UPRISE_VULKAN_RENDER_API __declspec(dllexport)
#define UPRISE_VULKAN_RENDER_API_EXPORTS export
#else
#define UPRISE_VULKAN_RENDER_API __declspec(dllimport)
#define UPRISE_VULKAN_RENDER_API_EXPORTS
#endif // UPRISEENGINEVULKANRENDER_EXPORTS



#ifdef UPRISEENGINEDEBUG_EXPORTS
#define UPRISE_DEBUG_API __declspec(dllexport)
#define UPRISE_DEBUG_API_EXPORTS 
#else
#define UPRISE_DEBUG_API __declspec(dllimport)
#define UPRISE_DEBUG_API_EXPORTS 

#endif // UPRISEENGINEDEBUG_EXPORTS

#ifdef UPRISEENGINEPHYSICS_EXPORTS
#define UPRISE_PHYSICS_API __declspec(dllexport)
#define UPRISE_PHYSICS_API_EXPORTS
#else
#define UPRISE_PHYSICS_API __declspec(dllimport)
#define UPRISE_PHYSICS_API_EXPORTS
#endif // UPRISEENGINEPHYSICS_EXPORTS

#ifdef UPRISEENGINEPROFILER_EXPORTS
#define UPRISE_PROFILER_API __declspec(dllexport)
#define UPRISE_PROFILER_API_EXPORTS export
#else
#define UPRISE_PROFILER_API __declspec(dllimport)
#define UPRISE_PROFILER_API_EXPORTS
#endif // UPRISEENGINEPROFILER_EXPORTS
#ifdef UPRISEENGINEEE_EXPORTS
#define UPRISE_ENGINE_EE_API __declspec(dllexport)
#define UPRISE_ENGINE_EE_API_EXPORTS export
#else
#define UPRISE_ENGINE_EE_API __declspec(dllimport)
#define UPRISE_ENGINE_EE_API_EXPORTS
#endif // UPRISEENGINEEE_EXPORTS


#pragma endregion



#pragma region TestInfrastructure

#define TypeMAcroCombiner(...) __VA_ARGS__
#ifdef UPRISE_TESTS
#define MockableGlobalVar(Type,x) __inline Type& x(){\
static Type InternalMockReplacement{};\
return InternalMockReplacement;\
}
#define MockableStaticVar(x,...) static __inline __VA_ARGS__& x(){\
static Type InternalMockReplacement{};\
return InternalMockReplacement;\
}
#define AccsesGlobalVar(FullName) FullName ()
#define AccsesStaticVar(FullName) FullName ()
#define CallMockableMethod(FullName)  FullName
#else
#define MockableGlobalVar(Type,x)  Type x ;

#define MockableStaticVar(x,Type) static Type x ; 
#define AccsesGlobalVar(x)  x
#define AccsesStaticVar(x)  x
#define CallMockableMethod(FullName) FullName
#endif


#pragma warning(push)

#pragma warning(disable :4005)
#ifdef UPRISE_TESTS
#define UPRISE_PROFILER_API
#define UPRISE_PHYSICS_API
#define UPRISE_DEBUG_API
#define UPRISE_VULKAN_RENDER_API
#define UPRISE_OPENGL_RENDER_API
#define UPRISE_DX12_RENDER_API
#define UPRISE_DX11_RENDER_API
#define UPRISE_COMMON_RENDER_COMPS_API
#define UPRISE_ECS_API
#define UPRISE_CORE_API
#define UPRISE_RENDER_API

#endif
#pragma warning(pop)
#pragma endregion


#pragma region RuntimeWarnings
#ifdef RT_WARNINGS_5
constexpr inline bool RuntimeWarnings = true; //-V3549
constexpr inline unsigned char RuntimeWarningsLevel = 5; //-V3549
#elif RT_WARNINGS_4
constexpr inline bool RuntimeWarnings = true;
constexpr inline unsigned char RuntimeWarningsLevel = 4;
#elif RT_WARNINGS_3
constexpr inline bool RuntimeWarnings = true;
constexpr inline unsigned char RuntimeWarningsLevel = 3;
#elif RT_WARNINGS_2
constexpr inline bool RuntimeWarnings = true;
constexpr inline unsigned char RuntimeWarningsLevel = 2;
#elif RT_WARNINGS_1
constexpr inline bool RuntimeWarnings = true;
constexpr inline unsigned char RuntimeWarningsLevel = 1;
#elif RT_WARNINGS_0
constexpr inline bool RuntimeWarnings = false;
constexpr inline unsigned char RuntimeWarningsLevel = 0;
#else
#error "RT_WARNINGS_0-5 not defined. tis is an error. set to 0 to disable runtime warnings"
#endif // RT_WARNINGS_5

#pragma endregion


#pragma region GetWarningLevel
#ifdef EnableAllWarnings
constexpr inline int WarningLevel = 5; //-V3549
#else //notEnableAllWarnings
#ifdef Level4
constexpr int WarningLevel = 4
#else//notLevel4
#ifdef Level3
constexpr int WarningLevel = 3;
#else//notLevel3
#ifdef Level2
constexpr int WarningLevel = 2;
#else //notLevel2
#ifdef Level1
constexpr int WarningLevel = 1;
#endif //Level1
#endif // Level2
#endif // Level3
#endif // Level4
#endif // EnableAllWarnings

#pragma endregion


//#include "tracy/Tracy.hpp"
//#include "tracy/TracyC.h"


#define symLoad GetProcAddress 

#pragma region PRofiler_Specxific
namespace UPRISE_ENGINE {
    namespace  PROFILER {

        constexpr inline size_t maxFrames = 64;

    }
}
#pragma endregion


#pragma warning(disable : 4514)

#pragma region UE_DEFINES



#define UE_NODISCARD [[nodiscard]]
#define UE_FINLINE __forceinline
#define UE_INLINE __inline
#define UE_DEFAUL(TypeName) TypeName() noexept = default;
#define UE_VEC_CALL __vectorcall
#define UE_FINLINE_VEC_CALL __forceinline __vectorcall
#define UE_INLINE_VEC_CALL __inline __vectorcall
#define UE_CONST_NOEXCEPT const noexcept
#define UE_SIMD_ALIGN__M128 alignas(16) //-V3547
#define UE_SIMD_ALIGN__M256 alignas(32) //-V3547
#define UE_SIMD_ALIGN__M512 alignas(64) //-V3547
#define UE_ALIGN_PTR alignas(alignof(void*))
#define UE_ALIGN_SHORT alignas(alignof(short))
#define UE_CONST_PTR(Name,...)  __VA_ARGS__* const Name
#define UE_PTR_TO_CONST(Name,...)  const __VA_ARGS__* Name
#define UE_IMPORT(Name) import Name;
#define UE_UNLIKELY [[unlikely]]
#define UE_LIKELY [[likely]]
#define UE_FALLTHROUGH [[fallthrough]]

void __cdecl __debugbreak(void); //-V3549
#define UE_THROW_NOT_IMPLEMENTED __debugbreak();

#define UE_THROW_NOT_FULLY_IMPLEMENTED __debugbreak();
#define UE_InClassBoilerplate(API) API MockableStaticVar(uid,UUID);
#define UE_OutClassBoilerplate(Type)  ::UPRISE_ENGINE::UUID Type::uid = UUID::Create();

#define UE_NOEXCEPT_IF(condition) noexcept(condition)
#define UE_UNSAFE_MODE false
#define UE_SAFE_MODE true
#pragma endregion
#ifndef UE_UNSAFE_REFS
#define UE_REF_SAFETY_MODE UE_UNSAFE_MODE

#else
#define UE_REF_SAFETY_MODE UE_SAFE_MODE

#endif

#pragma region Typedefs


typedef  long long huge;; //-V2575 //-V3549
typedef unsigned long long uhuge; //-V2575 //-V3549

typedef size_t  Index; // alias for size_t/unsigned long long, used for indexing //-V2575 //-V3549
#pragma endregion

#pragma region Global_ConstevalFuncs


namespace UPRISE_ENGINE {
    consteval size_t constevalstrlen(const char* str) {
        Index len = 0;
        while (str[len] != '\0') { //-V2563 //-V3539
            len++;
        }

        return len;
    }
}
#pragma endregion



#pragma region DEBUG_NO_DEBUG
#ifdef _DEBUG
#define DEBUG_PAD_BITS_ZEROED 0
#define TrPr(V,N)   ;
#define TrPrE(V) ;
#define UE_DEBUG_FIND_INFINITE_LOOP(MaxLoop, InitialValue) \
 static thread_local int __loopCounter = 0; \
if(__loopCounter == InitialValue) {__loopCounter = 0;}\
if(__loopCounter++ > MaxLoop) { \
__debugbreak(); \
} 

constexpr inline bool DebugMode = true; //-V3549
#define UE_DEBUG_FIND_INFINITE_LOOP_MAX 1000000
#define UE_ABORT_IF_REACHED_IN_DEBUG_MODE __debugbreak();

#else
#define DEBUG_PAD_BITS_ZEROED 
#define TrPr(V,N)    ;
#define TrPrE(V) ;
#define UE_DEBUG_FIND_INFINITE_LOOP(MaxLoop) ;
#define UE_DEBUG_FIND_INFINITE_LOOP_MAX 1000000
constexpr inline bool DebugMode = false;
#define UE_ABORT_IF_REACHED_IN_DEBUG_MODE ;
#endif // DEBUG
#pragma endregion

#pragma region FORCE_INCLUDES
//#include <intrin.h>
#pragma endregion





#pragma region UE_ANOTATIONS


#define UE_IN_PARAMETER(X) X
#define UE_OUT_PARAMETER(X) X
#define UE_IN_OUT_PARAMETER(X) X
#define UE_TAKES_OWNERSHIP_OF_POINTER(X) X
#define UE_IO_REF_TO_PTR_PTR_WILL_BE_REALLOCATED(X) X


#define UE_USE_CONSTEXPR_VAR(X) X


#pragma endregion
//import UPRISE_ENGINE_PROFILER requiret to use this macro
#define SCOPED_TIME_  UPRISE_ENGINE::PROFILER::TIMERS::SCOPED_TIME scoped_time(__FUNCSIG__,__FILE__,__FUNCTION__,__LINE__);


template<typename T>
consteval T* IntegerTypeToPointer(unsigned long long input) { //-V3549
    return reinterpret_cast<T*>(input); //-V3546 //-V2571
}
#pragma warning(pop)
#endif // !UE_GLOBAL_

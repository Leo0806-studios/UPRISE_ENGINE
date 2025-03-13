// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_GLOBAL_
#define UE_GLOBAL_
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





#ifdef UPRISE_TESTS
#define MockableGlobalVar(Type,Name) __inline Type& Name(){\
static Type InternalMockReplacement{};\
return InternalMockReplacement;\
}
#define MockableStaticVar(Name,...) static __inline __VA_ARGS__& Name(){\
static Type InternalMockReplacement{};\
return InternalMockReplacement;\
}
#define AccsesGlobalVar(FullName) FullName ()
#define AccsesStaticVar(FullName) FullName ()
#define CallMockableMethod(FullName)  FullName
#else
#define MockableGlobalVar(Type,Name)  Type Name ;

#define MockableStaticVar(Name,...) static __VA_ARGS__ Name ; 
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
//#include "tracy/Tracy.hpp"
//#include "tracy/TracyC.h"


#define symLoad GetProcAddress 
namespace UPRISE_ENGINE {
    namespace  PROFILER {

        constexpr size_t maxFrames = 64;

    }
}
#pragma warning(disable : 4514)


#define UE_NODISCARD [[nodiscard]]
#define UE_FINLINE __forceinline
#define UE_INLINE __inline
#define UE_DEFAUL(TypeName) TypeName() noexept = default;
#define UE_VEC_CALL __vectorcall
#define UE_FINLINE_VEC_CALL __forceinline __vectorcall
#define UE_INLINE_VEC_CALL __inline __vectorcall
#define UE_CONST_NOEXCEPT const noexcept
#define UE_SIMD_ALIGN__M128 alignas(16)
#define UE_SIMD_ALIGN__M256 alignas(32)
#define UE_SIMD_ALIGN__M512 alignas(64)
#define UE_CONST_PTR(Name,...)  __VA_ARGS__* const Name
#define UE_PTR_TO_CONST(Name,...)  const __VA_ARGS__* Name
typedef  long long huge;; //-V2575 //-V3549
typedef unsigned long long uhuge; //-V2575 //-V3549

typedef size_t  Index; // alias for size_t/unsigned long long, used for indexing //-V2575 //-V3549

namespace UPRISE_ENGINE {
    consteval size_t constevalstrlen(const char* str) {
        Index len = 0;
        while (str[len] != '\0') { //-V2563 //-V3539
            len++;
        }

        return len;
    }
}
#ifdef _DEBUG
#define DEBUG_PAD_BITS_ZEROED 0
#define TrPr(V,N)   ;
#define TrPrE(V) ;
#else
#define DEBUG_PAD_BITS_ZEROED 
#define TrPr(V,N)    ;
#define TrPrE(V) ;
#endif // DEBUG

#endif // !UE_GLOBAL_

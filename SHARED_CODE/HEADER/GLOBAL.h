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




#ifdef UPRISEENGINERENDER_EXPORTS ||  || UPRISEENGINEDX11RENDER_EXPORTS || UPRISEENGINEDX12RENDER_EXPORTS || UPRISEENGINEOPENGLRENDER_EXPORTS || UPRISEENGINEVULKANRENDER_EXPORTS
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

#include "tracy/Tracy.hpp"
#include "tracy/TracyC.h"



#define symLoad GetProcAddress 
namespace UPRISE_ENGINE {
    namespace  PROFILER {
        constexpr size_t maxFrames = 64;

    }
}


#define UE_NODISCARD [[nodiscard]]
typedef  long long huge;; //-V2575 //-V3549
typedef unsigned long long uhuge; //-V2575 //-V3549
typedef size_t  Index; //-V2575 //-V3549

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
#define TrPr(V,N)   TracyCZoneN(V, N, true); 
#define TrPrE(V) TracyCZoneEnd(V);
#else
#define TrPr(V,N)    ;
#define TrPrE(V) ;
#endif // DEBUG

#endif // !UE_GLOBAL_

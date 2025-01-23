// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef ___GLOBAL___
#define ___GLOBAL___
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

#include "tracy/Tracy.hpp"
#include "tracy/TracyC.h"




#define symLoad GetProcAddress 

#ifdef _DEBUG
#define TrPr(V,N)   TracyCZoneN(V, N, true); 
#define TrPrE(V) TracyCZoneEnd(V);
#else
#define TrPr(V,N)    ;
#define TrPrE(V) ;
#endif // DEBUG

#endif // !___GLOBAL___

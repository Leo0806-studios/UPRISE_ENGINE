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

#ifdef UPRISEENGINERENDER_EXPORTS
#define UPRISE_RENDER_API __declspec(dllexport)
#define UPRISE_RENDER_API_EXPORTS export
#else
#define UPRISE_RENDER_API __declspec(dllimport)
#define UPRISE_RENDER_API_EXPORTS
#endif // UPRISEENGINERENDER_EXPORTS

#ifdef UPRISEENGINEDEBUG_EXPORTS
#define UPRISE_DEBUG_API __declspec(dllexport)
#define UPRISE_DEBUG_API_EXPORTS 
#else
#define UPRISE_DEBUG_API __declspec(dllimport)
#define UPRISE_DEBUG_API_EXPORTS 

#endif // UPRISEENGINEDEBUG_EXPORTS


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

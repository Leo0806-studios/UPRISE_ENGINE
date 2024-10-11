#pragma once
#ifndef ___GLOBAL___
#define ___GLOBAL___
#ifdef _EXPORT_CORE

#define UPRISE_CORE_API __declspec(dllexport)
#else
#define UPRISE_CORE_API __declspec(dllimport)
#endif
#ifdef UPRISEENGINEECS_EXPORTS
#define UPRISE_ECS_API __declspec(dllexport)
#else
#define UPRISE_ECS_API __declspec(dllimport)
#endif // UPRISEENGINEECS_EXPORTS

#ifdef UPRISEENGINERENDER_EXPORTS
#define UPRISE_RENDER_API __declspec(dllexport)
#else
#define UPRISE_RENDER_API __declspec(dllimport)
#endif // UPRISEENGINERENDER_EXPORTS



#include "tracy/Tracy.hpp"
#include "tracy/TracyC.h"





#ifdef _DEBUG
#define TrPr(V,N)   TracyCZoneN(V, N, true); 
#define TrPrE(V) TracyCZoneEnd(V);
#else
#define TrPr(V,N)    ;
#define TrPrE(V) ;
#endif // DEBUG

#endif // !___GLOBAL___

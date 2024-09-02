// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H
#define EXPORT_API 1
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
#include "string"
#include "vector"
#include "memory"

#include "sysinfoapi.h"

// add headers that you want to pre-compile here
#include "framework.h"
#ifdef EXPORT_API
#define UPRISE_API __declspec(dllexport)
#else
#define UPRISE_API
#endif


#endif //PCH_H

// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>
import std; //-V2575 //-V3549
#pragma warning(disable: 4100)

BOOL APIENTRY DllMain( HMODULE hModule, //-V2575 //-V2537 //-V3523 //-V3549
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        std::cout << "attatching dx11 render module to process\n";
        break;
    case DLL_THREAD_ATTACH:
        std::cout << "attatching dx11 render module to thread\n";
        break;
    case DLL_THREAD_DETACH:
        std::cout << "detatching dx11 render module from thread\n";
        break;
    case DLL_PROCESS_DETACH:
        std::cout << "detatching dx11 render module\n";

        break;
    }
    return TRUE;
}
#pragma warning(default: 4100)
UPRISE_DX11_RENDER_API void e() {} //-V2575 //-V3549


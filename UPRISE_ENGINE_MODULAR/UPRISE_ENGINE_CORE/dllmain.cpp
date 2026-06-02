// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
// dllmain.cpp : Defines the entry point for the DLL application.

#include <Windows.h>
#include <MACROS.h>

#pragma warning(push)
#pragma warning(disable:4100)
#pragma warning(suppress:26461)
BOOL APIENTRY DllMain( HMODULE hModule, //-V2537 //-V2575 //-V3549 //-V3523
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
)noexcept
{
    UE_UNUSED_PARAMETER(hModule);
    UE_UNUSED_PARAMETER(lpReserved);
    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH: {
            UE_FALLTROUGH;
        }
        case DLL_THREAD_ATTACH: {
            UE_FALLTROUGH; 
        }
        case DLL_THREAD_DETACH: {
            UE_FALLTROUGH; 
        }
        case DLL_PROCESS_DETACH: {
            UE_FALLTROUGH; 
        }
        default: {
            break;
        }

    }
    return TRUE;
}
#pragma warning(pop)

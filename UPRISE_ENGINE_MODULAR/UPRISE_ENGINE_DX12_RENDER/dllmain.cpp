// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
// dllmain.cpp : Defines the entry point for the DLL application.
import <Windows.h>;
#pragma warning(push)
#pragma warning(disable: 4100)
#pragma warning (disable:4005)
#ifdef UPRISEENGINEDX12RENDER_EXPORTS
#define UPRISE_DX12_RENDER_API __declspec(dllexport)
#endif // UPRISEENGINEDX12RENDER_EXPORTS

BOOL APIENTRY DllMain( HMODULE hModule, //-V2575 //-V2537 //-V3523 //-V3549
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

#pragma warning(pop)
UPRISE_DX12_RENDER_API void eee() {} //-V2575 //-V3549
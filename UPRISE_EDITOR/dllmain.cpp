// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "HEADER/DLL_LINK.h"

BOOL APIENTRY DllMain( HMODULE hModule,
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
void(*DRAWp)();
#define EX __declspec(dllexport)
extern "C" {

    EX void INIT() {

    }
    EX void DRAW() {
        {
            
            DRAWp();

        }
    }
    EX void SHUTDOWN() {

    }
    EX void UPDATE_FUNC_PTR(void(*drawptr)() ) {
        DRAWp = drawptr;
    }


}


// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
//#include "GLOBAL/GLINCLUDES.h"
#include "HEADER/DATATYPES/VECTOR/VECTOR3/FAST/VECTOR3_F.h"
#include "HEADER/DATATYPES/QUTERION/QUATERION.h"
#include "HEADER/CORE/OBJECT/OBJECT.h"
import std; //-V2575 //-V3549

#pragma warning(disable:4100)
BOOL APIENTRY DllMain( HMODULE hModule, //-V2537 //-V2575 //-V3549
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
#pragma warning(default:4100)
int main() {
   


}
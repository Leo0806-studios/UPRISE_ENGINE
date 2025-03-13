// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

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

#define ADRS void*
#define ADRS_ARRAY ADRS*
#define FILE_ATTRIBUTES void*
#define BOOL bool
#define FILE_DATA void*

/// <summary>
/// Node in the file system. can be a file or a directory ( for a directory ChildStructure is null)
/// </summary>
struct NODE {
    ADRS DATA_PTR; // adress of a HEADER struct object
    ADRS ChildStructure; // adress of a ChildStructure struct object
};
/// <summary>
/// structure that contains the number of childs of a NODE Object and an array of adresses of NODE struct objects
/// </summary>
struct ChildStructure {
    size_t NumChilds; // number of childs
    ADRS_ARRAY Childs; // array of adresses of NODE struct objects
};
/// <summary>
/// Header OF  a file.The DATA_PTR of the NODE points to this. Contains the size of the header, the attributes of the file, a boolean that indicates if the file has a footer, the adress of the footer, a boolean that indicates if the file is fragmented and the adress of the next fragment
/// </summary>
struct HEADER {
    size_t HeaderSize;
    FILE_ATTRIBUTES Attributes;
    BOOL hasFooter;
    ADRS Footer;
    BOOL IS_FRAGMENTED;

};
/// <summary>
/// Contains the data of a file. it is located directly after the HEADER struct object
/// </summary>
struct DATA {
    FILE_DATA Data; // the data of the file
};
/// <summary>
/// A optional footer of a file. Contains the size of the footer and the adress of the next fragment
/// is located at the end of the file
/// </summary>
struct FOOTER {
    size_t FooterSize; // size of the footer
    ADRS NextFragment; // adress of the next fragment. is null if there is no next fragment
};

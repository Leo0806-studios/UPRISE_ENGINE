// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com


module;

//#include <GLOBAL/GLINCLUDES.h>
export module UPRISE_ENGINE_CORE;



#define CORE_MODULE_BUILD
#pragma warning (push)
#pragma warning(disable:4005)
#define UE_IMPORT(Name)
#pragma warning(pop)




export import :BEHAVIOUR; //-V3549
export import :CONTROL_BASE;
export import :GC_CONTROLBLOCK;
export import :OWNED_REF;
export import :CONCEPT_ALIGN;
export import :CONCEPT_SIZE;
export import :CONTROL_BASE;
export import :OBJECT;
export import :OWNED_REF;
export import :SHARED_REF;
export import :WEAK_REF;
export import :WRAPPER_BASE;
export import :__M128_UTILLS;
export import :WRAPPER_BASE;
export import :OWNED_CONTROLBLOCK;
export import :CONTROL_BASE;
export import :UUID;
export import:CPUID; //-V3549

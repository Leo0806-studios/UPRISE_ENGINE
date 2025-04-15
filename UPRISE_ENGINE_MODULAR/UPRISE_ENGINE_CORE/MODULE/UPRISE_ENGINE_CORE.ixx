module;

//#include <GLOBAL/GLINCLUDES.h>
export module UPRISE_ENGINE_CORE;



#define CORE_MODULE_BUILD
#pragma warning (push)
#pragma warning(disable:4005)
#define UE_IMPORT(Name)
#pragma warning(pop)




export import :BEHAVIOUR;
export import :CONTROL_BASE;
export import :GC_CONTROLBLOCK;
export import :OWNED_REF;
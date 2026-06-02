#pragma once
#include "ABI.h"
#include "ANOTATIONS.h"
#include "IMPORT_DEFS.h"
void __cdecl __debugbreak(void); //-V3549 //forecully predefines debugbreak to avoid having to breing in intrin.h
#define UE_THROW_NOT_IMPLEMENTED __debugbreak(); __pragma(message("function " __FUNCSIG__ " in file "  __FILE__  " is not implemented. will call debugbreak if called"));

#define constevalstrlen(str) []() consteval { \
    size_t len = 0; \
    const char* str_ = str; \
    while (str_[len] != '\0') { \
        ++len; \
    } \
    return len; \
}()
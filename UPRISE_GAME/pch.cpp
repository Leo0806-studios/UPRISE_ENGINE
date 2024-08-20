
#include "pch.h"
#include "DLL-ENGINE-LINK.h"



DATALINK* IMPORTANT::DATA;
int IMPORTANT::GameObj_count = 0;
void* operator new(std::size_t count)
{
    auto ptr = malloc(count);
    TracyAlloc(ptr, count);
    return ptr;
}

void operator delete(void* ptr) noexcept
{
    TracyFree(ptr);
    free(ptr);
}

void PLTADD(const char* name, int val)
{
    IMPORTANT::DATA->PLOTADD(name, val);
}

void PLTREM(const char* name, int val)
{
    IMPORTANT::DATA->PLOTREMOVE(name, val);
}

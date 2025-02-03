// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "OPERATOR_NEW.h"
#include <corecrt_malloc.h>
#include "PROFILER/PROFILER_OBJECTS/ALLOC/ALLOC_OBJECT.h"
#include "PROFILER/PROFILER_INIT/PROFILER_INIT.h"
#include "PROFILER/PROFILER_OBJECTS/DEALLOC/DEALLOC_OBJECT.h"
void* operator new(size_t count) //-V3549 //-V2575
{
    std::cout << "new\n";
  
        void* ptr = malloc(count); //-V2511
        if (UPRISE_ENGINE::PROFILER::Profiler_started()) {
            UPRISE_ENGINE::PROFILER::ALLOC_OBJECT(count, ptr, "new", __FILE__, __LINE__, "new"); //-V3551 //-V3527 //-V2578 //-V2547

        }
        return ptr;
    
}
void operator delete(void* ptr) //-V3549 //-V2575
{
    std::cout << "delete\n";
    if (UPRISE_ENGINE::PROFILER::Profiler_started()) {
        ;
        UPRISE_ENGINE::PROFILER::DEALLOC_OBJECT(_msize(ptr), ptr, "delete", __FILE__, __LINE__, "delete"); //-V3551 //-V3527 //-V2578 //-V2547
    }
    free(ptr); //-V2511
}
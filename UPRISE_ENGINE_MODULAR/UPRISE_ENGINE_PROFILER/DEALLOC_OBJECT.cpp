// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include <memory>
#include "DEALLOC_OBJECT.h"
#include "DEALLOC.h"
#include "EVENT_QEUE.h"
#include <MACROS.h>


UPRISE_ENGINE::PROFILER::DEALLOC_OBJECT::DEALLOC_OBJECT(size_t size, void* ptr, const char* Type, const char* File, int Line, const char* message)
{
    std::unique_ptr<EVENT_BASE> a = std::make_unique<DEALLOC>(DEALLOC(size, ptr, Type, File, Line, message));
    UPRISE_ENGINE::PROFILER::EVENT_QEUE::Add_to_Qeue(std::move(a));
}

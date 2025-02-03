#pragma once
#ifndef UE_ALLOC_
#define UE_ALLOC_
import std;
#include "PROFILER/PROFILE_EVENTS/PROF_EVENT/PROF_EVENT.h"
namespace UPRISE_ENGINE {
    namespace PROFILER {
        class ALLOC:public PROFILER::EVENT_BASE {
        private:
            size_t size;
            void* ptr;
            const char* Type;
            const char* File;
            int Line;
            const char* message;
        public:
            std::string What() {
                std::string a = "alloc at ";
                a += std::to_string(reinterpret_cast<uintptr_t> (ptr));
                a += " size: ";
                a += std::to_string(size);
                a += " with message: ";
                a += message;
                return a.c_str();
            }
            ALLOC() = default;
            ALLOC(size_t size, void* ptr, const char* Type, const char* File, int Line, const char* message) {
                this->size = size;
                this->ptr = ptr;
                this->Type = Type;
                this->File = File;
                this->Line = Line;
                this->message = message;
            }
            ~ALLOC() {}
        };
    }
}

#endif // !_ALLOC_

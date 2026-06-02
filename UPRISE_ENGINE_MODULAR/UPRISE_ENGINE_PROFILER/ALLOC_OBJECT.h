#pragma once
#include <MACROS.h>
 namespace UPRISE_ENGINE {
    namespace PROFILER {
        class ALLOC_OBJECT {
        private:
        public:
            ALLOC_OBJECT() = default;
            UPRISE_PROFILER_API  ALLOC_OBJECT(size_t size, void* ptr, const char* Type, const char* File, int Line, const char* message);

            ~ALLOC_OBJECT() = default;
        };
    }
}
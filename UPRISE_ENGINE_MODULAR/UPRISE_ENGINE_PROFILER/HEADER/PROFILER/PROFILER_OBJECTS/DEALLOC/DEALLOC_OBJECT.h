#pragma once
#ifndef UE_DEALLOC_OBJECT_
#define UE_DEALLOC_OBJECT_
namespace UPRISE_ENGINE {
    namespace PROFILER {
        class DEALLOC_OBJECT {
        private:
        public:
            DEALLOC_OBJECT() = default;
            UPRISE_PROFILER_API  DEALLOC_OBJECT(size_t size, void* ptr, const char* Type, const char* File, int Line, const char* message);
            ~DEALLOC_OBJECT() {}
        };
    }
}

#endif // !_DEALLOC_

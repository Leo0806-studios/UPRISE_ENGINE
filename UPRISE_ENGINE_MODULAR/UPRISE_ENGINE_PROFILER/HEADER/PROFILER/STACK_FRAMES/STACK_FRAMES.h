#pragma once
#ifndef UE_STACK_FRAMES_
#define UE_STACK_FRAMES_
import std; //-V2575
namespace  UPRISE_ENGINE {
    namespace PROFILER {
        class stack_frames {
        private:
            void* frames{nullptr};
        public:
            void** get_frames() {
                return &frames;
            }
            const size_t get_size() const {
                return size;
            }

            size_t size=0;
           UPRISE_PROFILER_API stack_frames();
            stack_frames(const stack_frames& other) = delete;

            UPRISE_PROFILER_API  stack_frames(stack_frames&& other) noexcept;

            stack_frames& operator=(const stack_frames& other) = delete;

            UPRISE_PROFILER_API stack_frames& operator=(stack_frames&& other) noexcept;
            UPRISE_PROFILER_API ~stack_frames();
        };
        
    }
}
#endif // !UE_STACK_FRAMES_
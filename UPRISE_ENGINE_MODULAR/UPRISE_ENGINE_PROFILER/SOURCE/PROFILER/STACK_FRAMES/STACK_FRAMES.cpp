#include "PROFILER/STACK_FRAMES/STACK_FRAMES.h"
#include "corecrt_malloc.h"

inline UPRISE_ENGINE::PROFILER::stack_frames::stack_frames() {
    frames = malloc(sizeof(void*) * maxFrames);
    if (frames) {
        size = maxFrames;
    }
    else {
        size = 0;
    }
}

inline UPRISE_ENGINE::PROFILER::stack_frames::stack_frames(stack_frames&& other) noexcept {
    if (this != &other) {
        if (frames) {
            free(frames);
        }
        frames = other.frames;
        size = other.size;
        other.frames = nullptr;
        other.size = 0;
    }
}

inline UPRISE_ENGINE::PROFILER::stack_frames& UPRISE_ENGINE::PROFILER::stack_frames::operator=(stack_frames&& other) noexcept {
    if (this != &other) {
        if (frames) {
            free(frames);
        }
        frames = other.frames;
        size = other.size;
        other.frames = nullptr;
        other.size = 0;
    }
    return *this;
}

inline UPRISE_ENGINE::PROFILER::stack_frames::~stack_frames() {
    if (frames) {
        free(frames);
    }
}

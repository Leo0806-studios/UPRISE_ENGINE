#pragma once
#include <cassert>
#include <string>
#include <format>
namespace UPRISE_ENGINE {
    size_t HashCombine(size_t seed, size_t hash) noexcept {
        return seed ^ (hash + 0x9e3779b9 + (seed << 6) + (seed >> 2));
    }
#ifdef NDEBUG
#define ASSERT_MSG(expr, msg) ((void)0)
#else
#define ASSERT_MSG(expr, msg) assert((expr) && (msg))
#endif


}


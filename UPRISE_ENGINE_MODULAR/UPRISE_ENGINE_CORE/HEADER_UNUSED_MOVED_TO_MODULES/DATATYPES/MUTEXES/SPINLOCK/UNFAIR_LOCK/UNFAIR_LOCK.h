//
#pragma once
#ifndef _UNFAIR_LOCK_
#define _UNFAIR_LOCK_
import std; //-V2575 //-V3549
namespace UPRISE_ENGINE {
    class UnfairLock {
        std::atomic_flag locked{};
    public:
        __inline void Lock() {
            while (locked.test_and_set(std::memory_order_acquire)) {

            }
        }
        __inline void Unlock() {
            locked.clear(std::memory_order_release);
        }
    };
}

#endif // !_UNFAIR_LOCK_

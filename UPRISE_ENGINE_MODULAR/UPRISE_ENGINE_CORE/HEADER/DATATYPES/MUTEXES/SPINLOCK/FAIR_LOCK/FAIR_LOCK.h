#pragma once
#ifndef _FAIR_LOCK_
#define _FAIR_LOCK_
import std; 
namespace UPRISE_ENGINE {
    class FairLock {
        std::atomic<unsigned int> next_ticket{ 0 };
        std::atomic<unsigned int> now_serving{ 0 };
    public:
        void lock() {
            unsigned int my_ticket = next_ticket.fetch_add(1, std::memory_order_relaxed);
            while (now_serving.load(std::memory_order_acquire) != my_ticket) {
            }
        }
        void unlock() {
            now_serving.fetch_add(1, std::memory_order_release);
        }
    };
}

#endif // !_FAIR_LOCK_

#pragma once
#ifndef _THREAD_
#define _THREAD_
import std;
namespace UPRISE_ENGINE {
    namespace THREADING {
        class Thread {
        private:
            long unsigned long thread_id = 0;

        public:
           UE_NODISCARD Thread() = default;

            ~Thread() {}
        };
    }
}

#endif // !_THREAD_

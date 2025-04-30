#pragma once
#ifndef _ASYNC_RETURN_
#define _ASYNC_RETURN_
namespace UPRISE_ENGINE {
    namespace THREADING {
        template <class T>
        class Async_Return {
        private:
            T __VAL;
        public:
            Async_Return() = default;
            ~Async_Return() {
            
            }
        };
    }
}

#endif // !_ASYNC_RETURN_

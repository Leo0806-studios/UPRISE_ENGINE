#pragma once
#ifndef _CONTEXT_
#define _CONTEXT_
import REF_WRAPPER;
import std;
namespace UPRISE_ENGINE {
    namespace RENDER_COMMON {
        class CONTEXT_BASE;
    }
    namespace RENDER {
        class Context {
        private:
            SharedRef<RENDER_COMMON::CONTEXT_BASE, true> context;
        public:
            void SetContext(SharedRef<RENDER_COMMON::CONTEXT_BASE, true> cont) {
                context = cont;
            }
        };
    }
}

#endif // !_CONTEXT_

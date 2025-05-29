#pragma once
#ifndef UE_CONTEXT_INTERNAL_
#define UE_CONTEXT_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_RENDER_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#ifdef __INTELLISENSE__
#include "UE_CORE_INTELLISENSE_FIX.h"
#endif // __INTELLISENSE__

namespace UPRISE_ENGINE::RENDER {
    namespace RENDER_COMMON {
        class CONTEXT_BASE;
    }
    
        class Context {
        private:
            SharedRef<RENDER_COMMON::CONTEXT_BASE, true> context;
        public:
            void SetContext(SharedRef<RENDER_COMMON::CONTEXT_BASE, true> cont) {
                context = cont;
            }
        };
    
}


#endif

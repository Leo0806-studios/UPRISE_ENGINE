#pragma once
#pragma once
#ifndef UE_GC_CONTROLBLOCK_INTERNAL_
#define UE_GC_CONTROLBLOCK_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_CORE_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif

#ifdef __INTELLISENSE__
#include "REF_WRAPPERS/CONTROLL_BLOCKS/CONTROL_BASE/CONTROL_BASE_INTERNAL.h"
#endif
 namespace UPRISE_ENGINE {

    namespace CORE {
        class GC_CONTROL_BLOCK :public ControlBlock_Base {
        private:
        public:
            GC_CONTROL_BLOCK()noexcept = default;
            ~GC_CONTROL_BLOCK()noexcept = default;
            GC_CONTROL_BLOCK(const GC_CONTROL_BLOCK& other) = delete;
            GC_CONTROL_BLOCK(GC_CONTROL_BLOCK&& other) = delete;
            GC_CONTROL_BLOCK& operator=(const GC_CONTROL_BLOCK& other) = delete;
            GC_CONTROL_BLOCK& operator=(GC_CONTROL_BLOCK&& other) = delete;
        };
    }
}
#endif
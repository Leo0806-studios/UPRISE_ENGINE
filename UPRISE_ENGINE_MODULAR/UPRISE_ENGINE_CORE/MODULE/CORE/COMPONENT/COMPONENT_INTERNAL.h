#pragma once
#ifndef UE_COMPONENT_INTERNAL_
#define UE_COMPONENT_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_CORE_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#ifdef __INTELLISENSE__
#include "OBJECT/OBJECT_INTERNAL.h"
#include "REF_WRAPPERS/WEAK_REF/WEAK_REF_INTERNAL.h"
#endif // __INTELLISENSE__

namespace UPRISE_ENGINE {
    namespace CORE {
        /// <summary>
    /// base Class for components on GameObjects that are just for storing Data
    /// very low runntime cost
    /// </summary>
        class  Component :public CORE::Object {
        private:
        public:
            UPRISE_CORE_API   Component() = default;
            UPRISE_CORE_API    Component(const Component& other) = delete;
            UPRISE_CORE_API  Component operator=(const Component& other) = delete;
            UPRISE_CORE_API  ~Component() {}
            UPRISE_CORE_API  void OnDestroyInt(WeakRef<CORE::Object, true> obj)override {}
        };
    }
}


#endif
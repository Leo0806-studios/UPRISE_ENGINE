#pragma once
#ifndef UE_COMPONENT_INTERNAL_
#define UE_COMPONENT_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_ECS_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#ifdef __INTELLISENSE__
#include "UE_CORE_INTELLISENSE_FIX.h"
#include "OBJECT/OBJECT_INTERNAL.h"
#endif // __INTELLISENSE__

namespace UPRISE_ENGINE {
        /// <summary>
    /// base Class for components on GameObjects that are just for storing Data
    /// very low runntime cost
    /// </summary>
        class  Component :public Object {
        private:
        public:
            UPRISE_ECS_API   Component() = default;
            UPRISE_ECS_API    Component(const Component& other) = delete;
            UPRISE_ECS_API  Component operator=(const Component& other) = delete;
            UPRISE_ECS_API  ~Component() {}
            UPRISE_ECS_API  void OnDestroyInt(WeakRef<Object, true> obj)override {}
        };
}


#endif
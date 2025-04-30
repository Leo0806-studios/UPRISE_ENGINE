// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_Component_
#define UE_Component_
#include "OBJECT/OBJECT.h"


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

#endif // !_Component_

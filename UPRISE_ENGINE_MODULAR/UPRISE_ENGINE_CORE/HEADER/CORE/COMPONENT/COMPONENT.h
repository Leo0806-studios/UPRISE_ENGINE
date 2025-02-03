// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_Component_
#define UE_Component_
#include "OBJECT/OBJECT.h";



namespace UPRISE_ENGINE {
    namespace CORE {
        /// <summary>
    /// base Class for components on GameObjects that are just for storing Data
    /// very low runntime cost
    /// </summary>
        class UPRISE_CORE_API Component :public CORE::Object {
        private:
        public:
            Component() = default;
            ~Component() {}
            void OnDestroyInt(RefWrapper<CORE::Object, true> obj)override {}
        };
    }
}

#endif // !_Component_

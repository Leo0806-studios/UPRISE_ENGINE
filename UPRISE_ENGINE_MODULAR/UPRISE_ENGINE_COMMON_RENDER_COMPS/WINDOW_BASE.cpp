// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#ifdef __INTELLISENSE__
#include "UE_COMMON_COMPS_INTELLISENSE_FIX.h"
#else
import UPRISE_ENGINE_COMMON_RENDER_COMPONETS;
#endif // __INTELLISENSE__

namespace UPRISE_ENGINE::RENDER::RENDER_COMMON {
        WINDOW_BASE::WINDOW_BASE(const WINDOW_BASE& other)
        {
            this->Callbacks = other.Callbacks;
            
        }
        WINDOW_BASE& WINDOW_BASE::operator=(const WINDOW_BASE& other) {
            this->Callbacks = other.Callbacks;
            return *this;
         }

    }

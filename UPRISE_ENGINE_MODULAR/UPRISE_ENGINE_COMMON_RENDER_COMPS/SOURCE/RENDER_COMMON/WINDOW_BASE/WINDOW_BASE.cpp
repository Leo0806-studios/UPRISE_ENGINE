// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "RENDER_COMMON/WINDOW_BASE/WINDOW_BASE.h"
namespace UPRISE_ENGINE {
    namespace RENDER_COMMON {
        WINDOW_BASE::WINDOW_BASE(const WINDOW_BASE& other)
        {
            this->Callbacks = other.Callbacks;
            
        }
        WINDOW_BASE& WINDOW_BASE::operator=(const WINDOW_BASE& other) {
            this->Callbacks = other.Callbacks;
            return *this;
         }

    }
}
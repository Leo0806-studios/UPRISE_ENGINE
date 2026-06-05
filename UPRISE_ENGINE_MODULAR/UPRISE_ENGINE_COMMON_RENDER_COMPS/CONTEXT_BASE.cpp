#include "CONTEXT_BASE.h"
namespace UPRISE_ENGINE::RENDER::RENDER_COMMON {

    std::unique_ptr<CONTEXT_BASE> CONTEXT_BASE::CreateContext(std::weak_ptr<RENDER_COMMON::WINDOW_BASE> Window)
    {
        return std::unique_ptr<CONTEXT_BASE>();
    }

}
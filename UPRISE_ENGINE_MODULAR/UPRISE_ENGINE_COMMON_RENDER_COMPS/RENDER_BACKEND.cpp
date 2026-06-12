// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "RENDER_BACKEND.h"
#include "RENDER_BACKEND.h"
#include <memory>
namespace UPRISE_ENGINE::RENDER::RENDER_COMMON {


    std::shared_ptr<RenderBackend> RenderBackend::_internal_backend;
    Backend RenderBackend::_internal_backend_type;

}



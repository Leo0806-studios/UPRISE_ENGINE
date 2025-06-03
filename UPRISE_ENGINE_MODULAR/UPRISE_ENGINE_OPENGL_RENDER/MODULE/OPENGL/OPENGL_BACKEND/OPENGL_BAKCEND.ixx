// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
export module UPRISE_ENGINE_OPEN_GL_RENDER:OPENGL_BAKCEND;


import UPRISE_ENGINE_CORE;
import UPRISE_ENGINE_COMMON_RENDER_COMPONETS;
export {
#define UE_OPENGL_BUILD_
#include "OPENGL_BACKEND_INTERNAL.h"
}
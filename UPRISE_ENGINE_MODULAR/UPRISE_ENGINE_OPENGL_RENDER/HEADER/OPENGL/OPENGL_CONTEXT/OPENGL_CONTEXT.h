// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef _OPENGL_CONTEXT_
#define _OPENGL_CONTEXT_
#include "RENDER_COMMON/CONTEXT_BASE/CONTEXT_BASE.h"
struct GLFWwindow;
namespace UPRISE_ENGINE {
    /// <summary>
/// "placeholder" to keep consitency with the other context classes
/// GLFWwindow* window is the actual context
/// </summary>
    class OPENGL_CONTEXT : public CONTEXT_BASE {
    private:
        GLFWwindow* window;
    public:
        OPENGL_CONTEXT() = default;
        ~OPENGL_CONTEXT() {}
    };
}

#endif // !_OPENGL_CONTEXT_

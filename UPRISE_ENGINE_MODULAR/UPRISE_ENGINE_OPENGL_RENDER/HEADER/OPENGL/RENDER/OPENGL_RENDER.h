// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef _OPENGL_RENDER_
#define _OPENGL_RENDER_
namespace UPRISE_ENGINE {
    void CreateOpenGLWindow(int w, int h, const char* Title);
    class OPENGL_RENDER {
    private:
    public:
        OPENGL_RENDER() = default;
        ~OPENGL_RENDER() {}
    };
}

#endif // !_OPENGL_RENDER_

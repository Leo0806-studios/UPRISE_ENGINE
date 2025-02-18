#pragma once
#ifndef _OPENGL_SHADER_
#define _OPENGL_SHADER_
#include "RENDER_COMMON/SHADER_BASE/SHADER_BASE.h"
import std;
namespace UPRISE_ENGINE {
    namespace OPENGL_RENDER {
        class OPENGL_SHADER: public RENDER_COMMON::SHADER_BASE{
        private:
            long long ID{ -1 };
        public:
            OPENGL_SHADER() = default;
            UPRISE_OPENGL_RENDER_API OPENGL_SHADER(std::string code);
            UPRISE_OPENGL_RENDER_API OPENGL_SHADER(std::filesystem::path path);
            UPRISE_OPENGL_RENDER_API void Compile() override;
            ~OPENGL_SHADER() {}

            UPRISE_COMMON_RENDER_COMPS_API void Delete() override;
            UPRISE_COMMON_RENDER_COMPS_API void Load() override;
        };
    }
}

#endif // !_OPENGL_SHADER_

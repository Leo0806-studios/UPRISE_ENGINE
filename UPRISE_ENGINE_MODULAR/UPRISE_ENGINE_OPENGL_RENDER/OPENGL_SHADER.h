#pragma once
#include <string>
#include <filesystem>
#include <MACROS.h>
#include <SHADER_BASE.h>


namespace UPRISE_ENGINE {
   namespace RENDER {
        namespace OPENGL_RENDER {
            /// <summary>
            /// 
            /// </summary>
            class OPENGL_SHADER : public RENDER_COMMON::SHADER_BASE {
            private:
                long long ID{ -1 };
            public:
                OPENGL_SHADER() = default;
                UPRISE_OPENGL_RENDER_API OPENGL_SHADER(std::string code);
                UPRISE_OPENGL_RENDER_API OPENGL_SHADER(std::filesystem::path path);
                ~OPENGL_SHADER() = default;
                UPRISE_OPENGL_RENDER_API OPENGL_SHADER(const OPENGL_SHADER& other);

                OPENGL_SHADER& operator=(const OPENGL_SHADER& other);

                UPRISE_OPENGL_RENDER_API void Compile() override;
                UPRISE_OPENGL_RENDER_API void Delete() override;
                UPRISE_OPENGL_RENDER_API void Load() override;
            };
        }
    }
}





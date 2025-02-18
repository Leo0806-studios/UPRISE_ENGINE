// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef _SHADER_BASE_
#define _SHADER_BASE_
import std;
import REF_WRAPPER;
namespace UPRISE_ENGINE {
    namespace OPENGL_RENDER {
        class OPENGL_SHADER;
    }
    class VULKAN_SHADER;
    class DIRECTX11_SHADER;
    class DIRECTX12_SHADER;
    namespace RENDER_COMMON {
        enum class ShaderType {
            S_null,
            S_Vertex,
            S_Fragment,
            S_Geometry,
            S_Compute
        };
        class SHADER_BASE {
        protected:
            friend OPENGL_RENDER::OPENGL_SHADER;
            friend VULKAN_SHADER;
            friend DIRECTX11_SHADER;
            friend DIRECTX12_SHADER;
            std::string Code;
            std::string Path;
            ShaderType shadertype = ShaderType::S_null;
            char PAD[4]; //TODO find a better way to align this or put data here

        public:
            UPRISE_COMMON_RENDER_COMPS_API  virtual void Compile() = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual void Delete() = 0;
            UPRISE_COMMON_RENDER_COMPS_API  virtual void Load() = 0;
            UPRISE_COMMON_RENDER_COMPS_API SHADER_BASE(const SHADER_BASE& other);
            UPRISE_COMMON_RENDER_COMPS_API SHADER_BASE(const std::string& code);
            UPRISE_COMMON_RENDER_COMPS_API SHADER_BASE(const std::filesystem::path& path);
            UPRISE_COMMON_RENDER_COMPS_API SHADER_BASE() = default;
            virtual ~SHADER_BASE() {};
            UPRISE_COMMON_RENDER_COMPS_API SHADER_BASE& operator=(const SHADER_BASE& other);


        };
    }
}


#endif // !_SHADER_BASE_

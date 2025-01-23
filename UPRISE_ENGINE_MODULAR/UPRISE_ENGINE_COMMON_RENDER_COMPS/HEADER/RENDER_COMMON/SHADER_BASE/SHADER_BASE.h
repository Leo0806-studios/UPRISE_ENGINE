// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef _SHADER_BASE_
#define _SHADER_BASE_
import std;
import REF_WRAPPER;
class OPENGL_SHADER;
class VULKAN_SHADER;
class DIRECTX11_SHADER;
class DIRECTX12_SHADER;
namespace RENDER_COMMON {
    enum ShaderType {
        S_null,
        S_Vertex,
        S_Fragment,
        S_Geometry,
        S_Compute
    };
    class SHADER_BASE {
    private:
        friend OPENGL_SHADER;
        friend VULKAN_SHADER;
        friend DIRECTX11_SHADER;
        friend DIRECTX12_SHADER;
        std::string Code;
        std::string Path;
        ShaderType shadertype = ShaderType::S_null;

    public:
        UPRISE_COMMON_RENDER_COMPS_API  virtual void* Compile() = 0;
        UPRISE_COMMON_RENDER_COMPS_API  virtual void Delete() = 0;
        UPRISE_COMMON_RENDER_COMPS_API  virtual void Load()=0;



    };
}

#endif // !_SHADER_BASE_

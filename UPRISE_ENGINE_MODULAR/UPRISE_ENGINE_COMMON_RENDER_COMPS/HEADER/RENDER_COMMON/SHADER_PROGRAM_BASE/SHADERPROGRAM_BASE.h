// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef _SHADERPROGRAM_BASE_
#define _SHADERPROGRAM_BASE_
import REF_WRAPPER;
import std;
class OPENGL_SHADERPROGRAM;
class VULKAN_SHADERPROGRAM;
class DIRECTX11_SHADERPROGRAM;
class DIRECTX12_SHADERPROGRAM;
class SHADER_BASE;
namespace RENDER_COMMON {
    class SHADERPROGRAM_BASE {
    private:
        std::string name = "";
    public:

        UPRISE_COMMON_RENDER_COMPS_API  virtual  void* Create(const std::vector<RefWrapper<SHADER_BASE, true>>& Shaders) = 0;
        UPRISE_COMMON_RENDER_COMPS_API  virtual void Use() = 0;
        UPRISE_COMMON_RENDER_COMPS_API  virtual void Delete() = 0;

    };
}

#endif // !_SHADERPROGRAM_BASE_


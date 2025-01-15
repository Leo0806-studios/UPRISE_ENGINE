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

        virtual  void* Create(const std::vector<RefWrapper<SHADER_BASE, true>>& Shaders) = 0;
        virtual void Use() = 0;
        virtual void Delete() = 0;

    };
}

#endif // !_SHADERPROGRAM_BASE_


// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "RENDER_COMMON/RENDER_BACKEND/RENDER_BACKEND.h"
#include "PROFILER/PROFILER_OBJECTS/TIMERS/SCOPED/SCOPED_TIME.h"
namespace UPRISE_ENGINE {
    namespace RENDER_COMMON {


        SharedRef<RENDER_BACKEND, true> RENDER_BACKEND::_internal_backend;
        RENDER_BACKEND::_Create_Backend_FUNC RENDER_BACKEND::_Create_Backend = nullptr; //-V2573 //-V3547
        void RENDER_BACKEND::DestroyBackend()
        {
            RENDER_BACKEND::_internal_backend->_internal_DestroyBackend();
        }

        SharedRef<WINDOW_BASE, true> RENDER_BACKEND::_CreateWindow(int w, int h, const char* Title)
        {
            PROFILER::TIMERS::SCOPED_TIME time("CreateWindow", __FILE__, __FUNCTION__, __LINE__);
            return RENDER_BACKEND::_internal_backend->_internal_CreateWindow(w, h, Title);
        }
        class DIRECTX12_BACKEND;
        SharedRef<RENDER_BACKEND, true> RENDER_BACKEND::CreateBackend()
        {
            PROFILER::TIMERS::SCOPED_TIME time("CreateBackend", __FILE__, __FUNCTION__, __LINE__);
            return _Create_Backend();

        }

        const SharedRef<RENDER_BACKEND, true>& RENDER_BACKEND::GetBackend()
        {
            return _internal_backend;
        }

        SharedRef<CONTEXT_BASE, true> RENDER_BACKEND::CreateContext()
        {
            return _internal_backend->_internal_Create_Context();
        }

        SharedRef<SHADER_BASE, true> RENDER_BACKEND::CreateShader(const std::string& ShaderCode)
        {
            return _internal_backend->_internal_Create_Shader(ShaderCode);
        }

        SharedRef<SHADER_BASE, true> RENDER_BACKEND::CreateShader(const std::filesystem::path& ShaderCode_Path)
        {
            return _internal_backend->_internal_Create_Shader(ShaderCode_Path);
        }

        SharedRef<SHADER_PROGRAM_BASE, true> RENDER_BACKEND::CreateShaderProgram(SharedRef<SHADER_BASE, true> Shader0)
        {
            return _internal_backend->_internal_CreateShaderProgram(Shader0);
        }

        SharedRef<SHADER_PROGRAM_BASE, true> RENDER_BACKEND::CreateShaderProgram(SharedRef<SHADER_BASE, true> Shader0, SharedRef<SHADER_BASE, true> Shader1)
        {
            return _internal_backend->_internal_CreateShaderProgram(Shader0, Shader1);
        }

        SharedRef<SHADER_PROGRAM_BASE, true> RENDER_BACKEND::CreateShaderProgram(SharedRef<SHADER_BASE, true> Shader0, SharedRef<SHADER_BASE, true> Shader1, SharedRef<SHADER_BASE, true> Shader2)
        {
            return _internal_backend->_internal_CreateShaderProgram(Shader0, Shader1, Shader2);
        }

        void RENDER_BACKEND::CreateMaterial()
        {
            _internal_backend->_internal_CreateMaterial();
        }
         int RENDER_BACKEND::CreateBuffer()
        {
             ///TODO implement CreateBuffer
             return 0;
        }
        void RENDER_BACKEND::DestroyWindow(SharedRef<RENDER_COMMON::WINDOW_BASE, true> Window)
        {
            PROFILER::TIMERS::SCOPED_TIME time("SetWindow", __FILE__, __FUNCTION__, __LINE__);

            _internal_backend->_internal_Destroy_Window(Window);
        }
         void RENDER_BACKEND::DestroyBuffer(unsigned int Buffer)
        {
             _internal_backend->_internal_DestroyBuffer(Buffer);
        }
         void RENDER_BACKEND::BindBuffer(int Buffer, void* _Data, size_t length, size_t Type_size, unsigned long bufferType)
        {
             _internal_backend->_internal_BindBuffer(Buffer, _Data, length, Type_size,bufferType);
        }
    }
}



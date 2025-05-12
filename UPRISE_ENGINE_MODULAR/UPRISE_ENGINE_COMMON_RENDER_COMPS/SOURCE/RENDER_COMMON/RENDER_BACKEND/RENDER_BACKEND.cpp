// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#ifdef __INTELLISENSE__
#include "UE_COMMON_COMPS_INTELLISENSE_FIX.h"
#include "UE_CORE_INTELLISENSE_FIX.h"
#else
import UPRISE_ENGINE_COMMON_RENDER_COMPONETS;
import UPRISE_ENGINE_CORE;
#endif // __INTELLISENSE__
import UPRISE_ENGINE_PROFILER;
namespace UPRISE_ENGINE {
    namespace RENDER_COMMON {


        OwnedRef<RENDER_BACKEND> RENDER_BACKEND::_internal_backend;
        RENDER_BACKEND::_Create_Backend_FUNC RENDER_BACKEND::_Create_Backend = nullptr; //-V2573 //-V3547
        void RENDER_BACKEND::DestroyBackend()
        {
            RENDER_BACKEND::_internal_backend->_internal_DestroyBackend();
        }

        OwnedRef<WINDOW_BASE> RENDER_BACKEND::_CreateWindow(int w, int h, const char* Title)
        {
            PROFILER::TIMERS::SCOPED_TIME time("CreateWindow", __FILE__, __FUNCTION__, __LINE__);
            return RENDER_BACKEND::_internal_backend->_internal_CreateWindow(w, h, Title);
        }
        class DIRECTX12_BACKEND;
        OwnedRef<RENDER_BACKEND> RENDER_BACKEND::CreateBackend()
        {
            PROFILER::TIMERS::SCOPED_TIME time("CreateBackend", __FILE__, __FUNCTION__, __LINE__);
            return _Create_Backend();

        }

        const WeakRef<RENDER_BACKEND,true> RENDER_BACKEND::GetBackend()
        {
            return _internal_backend.GetWeakRef();
        }

        WeakRef<RENDER_COMMON::CONTEXT_BASE,true> UPRISE_ENGINE::RENDER_COMMON::RENDER_BACKEND::CreateContext(WeakRef<RENDER_COMMON::WINDOW_BASE,true> window)
        {
            return _internal_backend->_internal_Create_Context(window);
        }

        OwnedRef<SHADER_BASE> RENDER_BACKEND::CreateShader(const std::string& ShaderCode)
        {
            return _internal_backend->_internal_Create_Shader(ShaderCode);
        }

        OwnedRef<SHADER_BASE> RENDER_BACKEND::CreateShader(const std::filesystem::path& ShaderCode_Path)
        {
            return _internal_backend->_internal_Create_Shader(ShaderCode_Path);
        }

        OwnedRef<SHADER_PROGRAM_BASE> RENDER_BACKEND::CreateShaderProgram(OwnedRef<SHADER_BASE> Shader0)
        {
            return _internal_backend->_internal_CreateShaderProgram(std::move(Shader0));
        }

        OwnedRef<SHADER_PROGRAM_BASE> RENDER_BACKEND::CreateShaderProgram(OwnedRef<SHADER_BASE> Shader0, OwnedRef<SHADER_BASE> Shader1)
        {
            return _internal_backend->_internal_CreateShaderProgram(std::move(Shader0), std::move(Shader1));
        }

        OwnedRef<SHADER_PROGRAM_BASE> RENDER_BACKEND::CreateShaderProgram(OwnedRef<SHADER_BASE> Shader0, OwnedRef<SHADER_BASE> Shader1, OwnedRef<SHADER_BASE> Shader2)
        {
            return _internal_backend->_internal_CreateShaderProgram(std::move(Shader0), std::move(Shader1), std::move(Shader2));
        }

        void RENDER_BACKEND::CreateMaterial()
        {
            _internal_backend->_internal_CreateMaterial();
        }
        unsigned int RENDER_BACKEND::CreateBuffer()
        {
            return _internal_backend->_internal_Create_Buffer();
        }
        void RENDER_BACKEND::DestroyWindow(WeakRef<RENDER_COMMON::WINDOW_BASE, true> Window)
        {
            PROFILER::TIMERS::SCOPED_TIME time("SetWindow", __FILE__, __FUNCTION__, __LINE__);

            _internal_backend->_internal_Destroy_Window(Window);
        }
         void RENDER_BACKEND::DestroyBuffer(unsigned int Buffer)
        {
             _internal_backend->_internal_DestroyBuffer(Buffer);
        }
         void RENDER_BACKEND::BindBuffer(unsigned int Buffer, void* _Data, size_t length, size_t Type_size, unsigned long long bufferType)
        {
             _internal_backend->_internal_BindBuffer(Buffer, _Data, length, Type_size,bufferType);
        }
         RENDER_BACKEND::RENDER_BACKEND( RENDER_BACKEND&& other)
         {
             this->_Create_Backend = std::move(other._Create_Backend);
             this->_internal_backend = std::move(other._internal_backend);
         }
         UPRISE_COMMON_RENDER_COMPS_API RENDER_BACKEND& RENDER_BACKEND::operator=( RENDER_BACKEND&& other)
         {
             this->_Create_Backend = std::move(other._Create_Backend);
             this->_internal_backend = std::move(other._internal_backend);

             return *this;
             // TODO: insert return statement here
         }
         UPRISE_COMMON_RENDER_COMPS_API void RENDER_BACKEND::PostFrameWork()
         {
            // SCOPED_TIME_

             _internal_backend->_internal_PostFrameWork();
         }
         UPRISE_COMMON_RENDER_COMPS_API void RENDER_BACKEND::PreFrameWork()
         {
            // SCOPED_TIME_
             _internal_backend->_internal_PreFrameWork();
         }

    }
}



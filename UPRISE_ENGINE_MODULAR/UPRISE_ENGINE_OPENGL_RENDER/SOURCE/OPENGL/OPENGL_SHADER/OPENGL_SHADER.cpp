// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#ifdef __INTELLISENSE__
#include "UE_CORE_INTELLISENSE_FIX.h"
#include "UE_COMMON_COMPS_INTELLISENSE_FIX.h"
#include "UE_OPENGL_INTELLISENSE_FIX.h"
#include "fstream"
#else
import UPRISE_ENGINE_OPEN_GL_RENDER;
import UPRISE_ENGINE_CORE;
import UPRISE_ENGINE_COMMON_RENDER_COMPONETS;
import <filesystem>;
import <iostream>;
import <fstream>;
#endif // __INTELLISENSE__

namespace UPRISE_ENGINE::RENDER::OPENGL_RENDER {
        OPENGL_SHADER::OPENGL_SHADER(std::string code) :SHADER_BASE(code) //-V2537 //explanation at PVS Disabled Warning explanation §1
        {
        }

        OPENGL_SHADER::OPENGL_SHADER(std::filesystem::path path) :SHADER_BASE(path) //-V2537 //explanation at PVS Disabled Warning explanation §1
        {
        }

        void OPENGL_SHADER::Compile()
        {
        }

        OPENGL_SHADER::OPENGL_SHADER(const OPENGL_SHADER& other) :SHADER_BASE(other) //-V2537 //explanation at PVS Disabled Warning explanation §1
        {
        }

        OPENGL_SHADER& OPENGL_SHADER::operator=(const OPENGL_SHADER& other)
        {
            SHADER_BASE::operator=(other);
            return *this;
        }
        
        

         void OPENGL_SHADER::Delete()
        {
        }

         void OPENGL_SHADER::Load()
        {
             std::ifstream shaderFile(Path);
             if (shaderFile) {
                 std::stringstream buffer;
                 buffer << shaderFile.rdbuf();
                 Code = buffer.str();
             }
             else {
                 std::cerr << "Failed to load shader file: " << Path << std::endl;
             }
         
        }
        
    
}



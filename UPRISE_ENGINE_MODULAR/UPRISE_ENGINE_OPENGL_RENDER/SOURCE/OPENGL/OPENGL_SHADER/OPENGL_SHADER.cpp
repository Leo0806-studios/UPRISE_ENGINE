// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "OPENGL/OPENGL_SHADER/OPENGL_SHADER.h"
import GLAD;
namespace UPRISE_ENGINE {
    namespace OPENGL_RENDER {
        OPENGL_SHADER::OPENGL_SHADER(std::string code) :SHADER_BASE(code)
        {
        }

        OPENGL_SHADER::OPENGL_SHADER(std::filesystem::path path) :SHADER_BASE(path)
        {
        }

        void OPENGL_SHADER::Compile()
        {
        }

        OPENGL_SHADER::OPENGL_SHADER(const OPENGL_SHADER& other) :SHADER_BASE(other)
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
}



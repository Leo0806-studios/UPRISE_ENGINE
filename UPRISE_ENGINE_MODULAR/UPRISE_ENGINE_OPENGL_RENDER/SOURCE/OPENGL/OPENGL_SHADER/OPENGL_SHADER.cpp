#include "OPENGL/OPENGL_SHADER/OPENGL_SHADER.h"
import GLAD;
namespace UPRISE_ENGINE {
    namespace OPENGL_RENDER {
        OPENGL_SHADER::OPENGL_SHADER(std::string code)
        {
            Code = code;
        }

        OPENGL_SHADER::OPENGL_SHADER(std::filesystem::path path)
        {
            Path = path.string();
        }

        void OPENGL_SHADER::Compile()
        {
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
}



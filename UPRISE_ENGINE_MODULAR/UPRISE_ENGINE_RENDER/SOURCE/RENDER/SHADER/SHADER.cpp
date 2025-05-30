// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#ifdef __INTELLISENSE__
#define DONT_INCLUDE_GLAD
#include "UE_RENDER_INTELLISENSE_FIX.h"
#include "fstream"
#include "UE_OPENGL_INTELLISENSE_FIX.h"
#include "map"
#else
import UPRISE_ENGINE_RENDER;
import UPRISE_ENGINE_OPEN_GL_RENDER;
import std;
#endif // __INTELLISENSE__

namespace UPRISE_ENGINE {
    namespace RENDER {
        Shader::Shader(const char* vertexPath, const char* fragmentPath)
        {
            UE_UNUSED_PARAMETER(vertexPath)
                UE_UNUSED_PARAMETER(fragmentPath)
            UE_THROW_NOT_IMPLEMENTED


        }



        // activate the shader
        // ------------------------------------------------------------------------

        void Shader::use() const
        {
            UE_THROW_NOT_IMPLEMENTED

        }

        // utility uniform functions
        // ------------------------------------------------------------------------

        void Shader::setBool(const std::string& name, bool value) const
        {
            UE_UNUSED_PARAMETER(name);
            UE_UNUSED_PARAMETER(value);

            UE_THROW_NOT_IMPLEMENTED

        }

        // ------------------------------------------------------------------------

        void Shader::setInt(const std::string& name, int value) const
        {
            UE_UNUSED_PARAMETER(name);
            UE_UNUSED_PARAMETER(value);
            UE_THROW_NOT_IMPLEMENTED

        }

        // ------------------------------------------------------------------------

        void Shader::setFloat(const std::string& name, float value) const
        {
            UE_UNUSED_PARAMETER(name);
            UE_UNUSED_PARAMETER(value);
            UE_THROW_NOT_IMPLEMENTED

        }

        // ------------------------------------------------------------------------

        void Shader::setVec2(const std::string& name, const Vector2& value) const
        {
            UE_UNUSED_PARAMETER(name);
            UE_UNUSED_PARAMETER(value);
            UE_THROW_NOT_IMPLEMENTED

        }

        void Shader::setVec2(const std::string& name, float x, float y) const
        {
            UE_UNUSED_PARAMETER(name);
            UE_UNUSED_PARAMETER(x);
            UE_UNUSED_PARAMETER(y);
            UE_THROW_NOT_IMPLEMENTED

        }

        // ------------------------------------------------------------------------

        void Shader::setVec3(const std::string& name, const Vector3& value) const
        {
            UE_UNUSED_PARAMETER(name);
            UE_UNUSED_PARAMETER(value);
            UE_THROW_NOT_IMPLEMENTED

        }

        void Shader::setVec3(const std::string& name, float x, float y, float z) const
        {
            UE_UNUSED_PARAMETER(name);
            UE_UNUSED_PARAMETER(x);
            UE_UNUSED_PARAMETER(y);
            UE_UNUSED_PARAMETER(z);
            UE_THROW_NOT_IMPLEMENTED

        }

        // ------------------------------------------------------------------------

        void Shader::setVec4(const std::string& name, const Vector4& value) const
        {
            UE_UNUSED_PARAMETER(name);
            UE_UNUSED_PARAMETER(value);
            UE_THROW_NOT_IMPLEMENTED

        }

        void Shader::setVec4(const std::string& name, float x, float y, float z, float w) const
        {
            UE_UNUSED_PARAMETER(name);
            UE_UNUSED_PARAMETER(x);
            UE_UNUSED_PARAMETER(y);
            UE_UNUSED_PARAMETER(z);
            UE_UNUSED_PARAMETER(w);
            UE_THROW_NOT_IMPLEMENTED

        }

        // ------------------------------------------------------------------------


        // ------------------------------------------------------------------------

        void Shader::setMat4(const std::string& name, const Mat4& mat) const
        {
            UE_UNUSED_PARAMETER(name);
            UE_UNUSED_PARAMETER(mat);
            UE_THROW_NOT_IMPLEMENTED

        }

        // utility function for checking shader compilation/linking errors.
        // ------------------------------------------------------------------------

        void Shader::checkCompileErrors(GLAD::GLuint shader, std::string type)
        {
            UE_UNUSED_PARAMETER(shader);
            UE_UNUSED_PARAMETER(type);
           
            UE_THROW_NOT_IMPLEMENTED
        }
    }
}

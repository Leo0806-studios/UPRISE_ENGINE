#pragma once
#ifndef UE_SHADER_INTERNAL_
#define UE_SHADER_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_RENDER_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#ifdef __INTELLISENSE__
#include <string>
#include <unordered_map>
#define DONT_INCLUDE_GLAD
#include "UE_OPENGL_INTELLISENSE_FIX.h"
#endif // __INTELLISENSE__

namespace UPRISE_ENGINE {
    class VertexShader;
    class FragmentShader;
    class GeometryShader;
    namespace RENDER {
        class Shader {
        private:
        public:
        public:
            unsigned int ID = INT_MAX;
            char PAD[4]{};//TODO find a way to aling this better or put data here //-V112 //NOSONAR

            std::unordered_map< std::string, GLAD::GLint> VarLocationsU;
            std::unordered_map< std::string, GLAD::GLint> VarLocationsL;
            // constructor generates the shader on the fly
            // ------------------------------------------------------------------------
            Shader(const char* vertexPath, const char* fragmentPath);

            Shader() = default;
            // activate the shader
            // ------------------------------------------------------------------------
            void use() const;
            // utility uniform functions
            // ------------------------------------------------------------------------
            void setBool(const std::string& name, bool value) const;
            // ------------------------------------------------------------------------
            void setInt(const std::string& name, int value) const;
            // ------------------------------------------------------------------------
            void setFloat(const std::string& name, float value) const;
            // ------------------------------------------------------------------------
            void setVec2(const std::string& name, const Vector2& value) const;
            void setVec2(const std::string& name, float x, float y) const;
            // ------------------------------------------------------------------------
            void setVec3(const std::string& name, const Vector3& value) const;
            void setVec3(const std::string& name, float x, float y, float z) const;
            // ------------------------------------------------------------------------
            void setVec4(const std::string& name, const Vector4& value) const;
            void setVec4(const std::string& name, float x, float y, float z, float w) const;
            // ------------------------------------------------------------------------
      // TODO FIX      void setMat2(const std::string& name, const glm::mat2& mat) const; //NOSONAR
            // ------------------------------------------------------------------------
        // TODO FIX    void setMat3(const std::string& name, const glm::mat3& mat) const; //NOSONAR
            // ------------------------------------------------------------------------
            void setMat4(const std::string& name, const Mat4& mat)const;

        private:
            // utility function for checking shader compilation/linking errors.
            // ------------------------------------------------------------------------
            void checkCompileErrors(GLAD::GLuint shader, std::string type);
        };
    };
}


#endif





// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once
#ifndef UE_Shader_
#define UE_Shader_
#include <GLOBAL/GLINCLUDES.h>

import std; //-V3549 //-V2575
import REF_WRAPPER; //-V3549 //-V2575
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
            char PAD[4]{};//TODO find a way to aling this better or put data here //-V112

            std::unordered_map< std::string, GLint> VarLocationsU;
            std::unordered_map< std::string, GLint> VarLocationsL;
            // constructor generates the shader on the fly
            // ------------------------------------------------------------------------
            Shader(const char* vertexPath, const char* fragmentPath);
            //Shader(SharedRef<VertexShader, true> vertexshader, SharedRef<FragmentShader, true> frgmentshader);
            //Shader(VertexShader vertexshader, FragmentShader frgmentshader, GeometryShader geometryshader);
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
            void setVec2(const std::string& name, const glm::vec2& value) const;
            void setVec2(const std::string& name, float x, float y) const;
            // ------------------------------------------------------------------------
            void setVec3(const std::string& name, const glm::vec3& value) const;
            void setVec3(const std::string& name, float x, float y, float z) const;
            // ------------------------------------------------------------------------
            void setVec4(const std::string& name, const glm::vec4& value) const;
            void setVec4(const std::string& name, float x, float y, float z, float w) const;
            // ------------------------------------------------------------------------
            void setMat2(const std::string& name, const glm::mat2& mat) const;
            // ------------------------------------------------------------------------
            void setMat3(const std::string& name, const glm::mat3& mat) const;
            // ------------------------------------------------------------------------
            void setMat4(const std::string& name, const glm::mat4& mat)const;

        private:
            // utility function for checking shader compilation/linking errors.
            // ------------------------------------------------------------------------
            void checkCompileErrors(GLuint shader, std::string type);
        };
    };
}

#endif // !_Shader_

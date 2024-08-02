#pragma once
#ifndef _RENDER_SHADER_UTILLS_
#include "GLINCLUDES.h"

#include "pch.h"
#include "CONFIGFILE.h"

#define _RENDER_SHADER_UTILLS_
namespace PAIN {
	class Shader;
}

namespace PAIN {
	class ShaderU {
	private:
		// utility function for checking shader compilation/linking errors.
		// ------------------------------------------------------------------------
		void checkCompileErrors(GLuint shader, std::string type);

	public:

		unsigned int ID;
		unsigned short textcount;
		ShaderU(char* vertexPath, char* fragmentPath);


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
		void setMat4(const std::string& name, const glm::mat4& mat) const;
	};

	class ShaderUtills {




	};
	class Shader
	{
	public:
		unsigned int ID;
		// constructor generates the shader on the fly
		// ------------------------------------------------------------------------
		Shader(const char* vertexPath, const char* fragmentPath);
		Shader(std::shared_ptr<VertexShader> vertexshader, std::shared_ptr<FragmentShader> frgmentshader);
		Shader(VertexShader vertexshader,FragmentShader frgmentshader,GeometryShader geometryshader);
		Shader();
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
		void setMat4(const std::string& name, const glm::mat4& mat) const;

	private:
		// utility function for checking shader compilation/linking errors.
		// ------------------------------------------------------------------------
		void checkCompileErrors(GLuint shader, std::string type);
	};
}

#endif // !_RENDER_SHADER_UTILLS_

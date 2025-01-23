// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
export module GLMODULE;

#define GLM_FORCE_SSE2 1
#define GLM_FORCE_AVX 1 
export import "glad.h";
export import "glfw3.h";
export import <glm/glm.hpp>;
export import <glm/gtc/matrix_transform.hpp>;
export import <glm/gtc/type_ptr.hpp>;
export import "glm/detail/type_vec2.hpp";
export import "glm/simd/matrix.h";
export import "glm/simd/common.h";
export import "glm/simd/vector_relational.h";
export import <assimp/vector3.h>;
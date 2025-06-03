// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
module;

export module GLAD:GLAD_GLOBALS;
import <glad/glad.h>;

export {
#define UE_OPENGL_BUILD_
#include "GLAD_GLOBALS_INTERNAL.h"
}
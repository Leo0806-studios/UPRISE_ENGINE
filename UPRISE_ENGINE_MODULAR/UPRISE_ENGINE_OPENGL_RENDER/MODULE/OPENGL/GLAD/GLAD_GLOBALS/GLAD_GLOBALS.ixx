module;

export module GLAD:GLAD_GLOBALS;
import <glad/glad.h>;

export {
#define UE_OPENGL_BUILD_
#include "GLAD_GLOBALS_INTERNAL.h"
}
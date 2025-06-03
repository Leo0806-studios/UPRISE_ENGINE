// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
export module GLAD:OPENGL_VERSION_ALL;
import :GLAD_GLOBALS;
export {
#define UE_OPENGL_BUILD_
#include "OPENGL_VERSION_ALL_INTERNAL.h"
}
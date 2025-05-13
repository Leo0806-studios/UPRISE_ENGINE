#pragma once
#ifndef UE_CONSTANTS_PART1_INTERNAL_
#define UE_CONSTANTS_PART1_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_OPENGL_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#include "GLAD/STUPIDMACROS/GLAD_MACROS.h"
#ifdef __INTELLISENSE__
#include <glad.h>
#endif // __INTELLISENSE__
namespace UPRISE_ENGINE {
    namespace RENDER {
        namespace GLAD {
            namespace CONSTANTS {
                constexpr int _GL_DEPTH_BUFFER_BIT = 0x00000100;
                constexpr int _GL_STENCIL_BUFFER_BIT = 0x00000400;
                constexpr int _GL_COLOR_BUFFER_BIT = 0x00004000;
                constexpr int UE_GL_FALSE = 0;
                constexpr int _GL_TRUE = 1;
                constexpr int _GL_POINTS = 0x0000;
                constexpr int _GL_LINES = 0x0001;
                constexpr int _GL_LINE_LOOP = 0x0002;
                constexpr int _GL_LINE_STRIP = 0x0003;
                constexpr int _GL_TRIANGLES = 0x0004;
                constexpr int _GL_TRIANGLE_STRIP = 0x0005;
                constexpr int _GL_TRIANGLE_FAN = 0x0006;
                constexpr int _GL_NEVER = 0x0200;
                constexpr int _GL_LESS = 0x0201;
                constexpr int _GL_EQUAL = 0x0202;
                constexpr int _GL_LEQUAL = 0x0203;
                constexpr int _GL_GREATER = 0x0204;
                constexpr int _GL_NOTEQUAL = 0x0205;
                constexpr int _GL_GEQUAL = 0x0206;
                constexpr int _GL_ALWAYS = 0x0207;
                constexpr int _GL_ZERO = 0;
                constexpr int _GL_ONE = 1;
                constexpr int _GL_SRC_COLOR = 0x0300;
                constexpr int _GL_ONE_MINUS_SRC_COLOR = 0x0301;
                constexpr int _GL_SRC_ALPHA = 0x0302;
                constexpr int _GL_ONE_MINUS_SRC_ALPHA = 0x0303;
                constexpr int _GL_DST_ALPHA = 0x0304;
                constexpr int _GL_ONE_MINUS_DST_ALPHA = 0x0305;
                constexpr int _GL_DST_COLOR = 0x0306;
                constexpr int _GL_ONE_MINUS_DST_COLOR = 0x0307;
                constexpr int _GL_SRC_ALPHA_SATURATE = 0x0308;
                constexpr int _GL_NONE = 0;
                constexpr int _GL_FRONT_LEFT = 0x0400;
                constexpr int _GL_FRONT_RIGHT = 0x0401;
                constexpr int _GL_BACK_LEFT = 0x0402;
                constexpr int _GL_BACK_RIGHT = 0x0403;
                constexpr int _GL_FRONT = 0x0404;
                constexpr int _GL_BACK = 0x0405;
                constexpr int _GL_LEFT = 0x0406;
                constexpr int _GL_RIGHT = 0x0407;
                constexpr int _GL_FRONT_AND_BACK = 0x0408;
                constexpr int _GL_NO_ERROR = 0;
                constexpr int _GL_INVALID_ENUM = 0x0500;
                constexpr int _GL_INVALID_VALUE = 0x0501;
                constexpr int _GL_INVALID_OPERATION = 0x0502;
                constexpr int _GL_OUT_OF_MEMORY = 0x0505;
                constexpr int _GL_CW = 0x0900;
                constexpr int _GL_CCW = 0x0901;
                constexpr int _GL_POINT_SIZE = 0x0B11;
                constexpr int _GL_POINT_SIZE_RANGE = 0x0B12;
                constexpr int _GL_POINT_SIZE_GRANULARITY = 0x0B13;
                consteval void CheckConstantsPart1() {
                    static_assert(_GL_DEPTH_BUFFER_BIT == GL_DEPTH_BUFFER_BIT, "GL_DEPTH_BUFFER_BIT is not equal to _GL_DEPTH_BUFFER_BIT");
                    static_assert(_GL_STENCIL_BUFFER_BIT == GL_STENCIL_BUFFER_BIT, "GL_STENCIL_BUFFER_BIT is not equal to _GL_STENCIL_BUFFER_BIT");
                    static_assert(_GL_COLOR_BUFFER_BIT == GL_COLOR_BUFFER_BIT, "GL_COLOR_BUFFER_BIT is not equal to _GL_COLOR_BUFFER_BIT");
                    static_assert(UE_GL_FALSE == GL_FALSE, "GL_FALSE is not equal to UE_GL_FALSE");
                    static_assert(_GL_TRUE == GL_TRUE, "GL_TRUE is not equal to _GL_TRUE");
                    static_assert(_GL_POINTS == GL_POINTS, "GL_POINTS is not equal to _GL_POINTS");
                    static_assert(_GL_LINES == GL_LINES, "GL_LINES is not equal to _GL_LINES");
                    static_assert(_GL_LINE_LOOP == GL_LINE_LOOP, "GL_LINE_LOOP is not equal to _GL_LINE_LOOP");
                    static_assert(_GL_LINE_STRIP == GL_LINE_STRIP, "GL_LINE_STRIP is not equal to _GL_LINE_STRIP");
                    static_assert(_GL_TRIANGLES == GL_TRIANGLES, "GL_TRIANGLES is not equal to _GL_TRIANGLES");
                    static_assert(_GL_TRIANGLE_STRIP == GL_TRIANGLE_STRIP, "GL_TRIANGLE_STRIP is not equal to _GL_TRIANGLE_STRIP");
                    static_assert(_GL_TRIANGLE_FAN == GL_TRIANGLE_FAN, "GL_TRIANGLE_FAN is not equal to _GL_TRIANGLE_FAN");
                    static_assert(_GL_NEVER == GL_NEVER, "GL_NEVER is not equal to _GL_NEVER");
                    static_assert(_GL_LESS == GL_LESS, "GL_LESS is not equal to _GL_LESS");
                    static_assert(_GL_EQUAL == GL_EQUAL, "GL_EQUAL is not equal to _GL_EQUAL");
                    static_assert(_GL_LEQUAL == GL_LEQUAL, "GL_LEQUAL is not equal to _GL_LEQUAL");
                    static_assert(_GL_GREATER == GL_GREATER, "GL_GREATER is not equal to _GL_GREATER");
                    static_assert(_GL_NOTEQUAL == GL_NOTEQUAL, "GL_NOTEQUAL is not equal to _GL_NOTEQUAL");
                    static_assert(_GL_GEQUAL == GL_GEQUAL, "GL_GEQUAL is not equal to _GL_GEQUAL");
                    static_assert(_GL_ALWAYS == GL_ALWAYS, "GL_ALWAYS is not equal to _GL_ALWAYS");
                    static_assert(_GL_ZERO == GL_ZERO, "GL_ZERO is not equal to _GL_ZERO");
                    static_assert(_GL_ONE == GL_ONE, "GL_ONE is not equal to _GL_ONE");
                    static_assert(_GL_SRC_COLOR == GL_SRC_COLOR, "GL_SRC_COLOR is not equal to _GL_SRC_COLOR");
                    static_assert(_GL_ONE_MINUS_SRC_COLOR == GL_ONE_MINUS_SRC_COLOR, "GL_ONE_MINUS_SRC_COLOR is not equal to _GL_ONE_MINUS_SRC_COLOR");
                    static_assert(_GL_SRC_ALPHA == GL_SRC_ALPHA, "GL_SRC_ALPHA is not equal to _GL_SRC_ALPHA");
                    static_assert(_GL_ONE_MINUS_SRC_ALPHA == GL_ONE_MINUS_SRC_ALPHA, "GL_ONE_MINUS_SRC_ALPHA is not equal to _GL_ONE_MINUS_SRC_ALPHA");
                    static_assert(_GL_DST_ALPHA == GL_DST_ALPHA, "GL_DST_ALPHA is not equal to _GL_DST_ALPHA");
                    static_assert(_GL_ONE_MINUS_DST_ALPHA == GL_ONE_MINUS_DST_ALPHA, "GL_ONE_MINUS_DST_ALPHA is not equal to _GL_ONE_MINUS_DST_ALPHA");
                    static_assert(_GL_DST_COLOR == GL_DST_COLOR, "GL_DST_COLOR is not equal to _GL_DST_COLOR");
                    static_assert(_GL_ONE_MINUS_DST_COLOR == GL_ONE_MINUS_DST_COLOR, "GL_ONE_MINUS_DST_COLOR is not equal to _GL_ONE_MINUS_DST_COLOR");
                    static_assert(_GL_SRC_ALPHA_SATURATE == GL_SRC_ALPHA_SATURATE, "GL_SRC_ALPHA_SATURATE is not equal to _GL_SRC_ALPHA_SATURATE");
                    static_assert(_GL_NONE == GL_NONE, "GL_NONE is not equal to _GL_NONE");
                    static_assert(_GL_FRONT_LEFT == GL_FRONT_LEFT, "GL_FRONT_LEFT is not equal to _GL_FRONT_LEFT");
                    static_assert(_GL_FRONT_RIGHT == GL_FRONT_RIGHT, "GL_FRONT_RIGHT is not equal to _GL_FRONT_RIGHT");
                    static_assert(_GL_BACK_LEFT == GL_BACK_LEFT, "GL_BACK_LEFT is not equal to _GL_BACK_LEFT");
                    static_assert(_GL_BACK_RIGHT == GL_BACK_RIGHT, "GL_BACK_RIGHT is not equal to _GL_BACK_RIGHT");
                    static_assert(_GL_FRONT == GL_FRONT, "GL_FRONT is not equal to _GL_FRONT");
                    static_assert(_GL_BACK == GL_BACK, "GL_BACK is not equal to _GL_BACK");
                    static_assert(_GL_LEFT == GL_LEFT, "GL_LEFT is not equal to _GL_LEFT");
                    static_assert(_GL_RIGHT == GL_RIGHT, "GL_RIGHT is not equal to _GL_RIGHT");
                    static_assert(_GL_FRONT_AND_BACK == GL_FRONT_AND_BACK, "GL_FRONT_AND_BACK is not equal to _GL_FRONT_AND_BACK");
                    static_assert(_GL_NO_ERROR == GL_NO_ERROR, "GL_NO_ERROR is not equal to _GL_NO_ERROR");
                    static_assert(_GL_INVALID_ENUM == GL_INVALID_ENUM, "GL_INVALID_ENUM is not equal to _GL_INVALID_ENUM");
                    static_assert(_GL_INVALID_VALUE == GL_INVALID_VALUE, "GL_INVALID_VALUE is not equal to _GL_INVALID_VALUE");
                    static_assert(_GL_INVALID_OPERATION == GL_INVALID_OPERATION, "GL_INVALID_OPERATION is not equal to _GL_INVALID_OPERATION");
                    static_assert(_GL_OUT_OF_MEMORY == GL_OUT_OF_MEMORY, "GL_OUT_OF_MEMORY is not equal to _GL_OUT_OF_MEMORY");
                    static_assert(_GL_CW == GL_CW, "GL_CW is not equal to _GL_CW");
                    static_assert(_GL_CCW == GL_CCW, "GL_CCW is not equal to _GL_CCW");
                    static_assert(_GL_POINT_SIZE == GL_POINT_SIZE, "GL_POINT_SIZE is not equal to _GL_POINT_SIZE");
                    static_assert(_GL_POINT_SIZE_RANGE == GL_POINT_SIZE_RANGE, "GL_POINT_SIZE_RANGE is not equal to _GL_POINT_SIZE_RANGE");
                    static_assert(_GL_POINT_SIZE_GRANULARITY == GL_POINT_SIZE_GRANULARITY, "GL_POINT_SIZE_GRANULARITY is not equal to _GL_POINT_SIZE_GRANULARITY");

                }
            }
        }
    }
}
#endif

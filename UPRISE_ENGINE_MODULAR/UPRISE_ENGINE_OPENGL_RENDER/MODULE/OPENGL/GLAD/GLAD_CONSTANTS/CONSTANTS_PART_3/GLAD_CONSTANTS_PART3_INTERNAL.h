#pragma once
#ifndef UE_GLAD_CONSTANTS_INTERNAL_PART3_INTERNAL_
#define UE_GLAD_CONSTANTS_INTERNAL_PART3_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_OPENGL_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#include "OPENGL/GLAD/STUPIDMACROS/GLAD_MACROS.h"
#ifdef __INTELLISENSE__
#ifndef DONT_INCLUDE_GLAD
#include "glad.h"
#endif
#endif // __INTELLISENSE__
namespace UPRISE_ENGINE {
    namespace RENDER {
        namespace GLAD {
            namespace CONSTANTS {
                constexpr int _GL_STENCIL = 0x1802;
                constexpr int _GL_STENCIL_INDEX = 0x1901;
                constexpr int _GL_DEPTH_COMPONENT = 0x1902;
                constexpr int _GL_RED = 0x1903;
                constexpr int _GL_GREEN = 0x1904;
                constexpr int _GL_BLUE = 0x1905;
                constexpr int _GL_ALPHA = 0x1906;
                constexpr int _GL_RGB = 0x1907;
                constexpr int _GL_RGBA = 0x1908;
                constexpr int _GL_POINT = 0x1B00;
                constexpr int _GL_LINE = 0x1B01;
                constexpr int _GL_FILL = 0x1B02;
                constexpr int _GL_KEEP = 0x1E00;
                constexpr int _GL_REPLACE = 0x1E01;
                constexpr int _GL_INCR = 0x1E02;
                constexpr int _GL_DECR = 0x1E03;
                constexpr int _GL_VENDOR = 0x1F00;
                constexpr int _GL_RENDERER = 0x1F01;
                constexpr int _GL_VERSION = 0x1F02;
                constexpr int _GL_EXTENSIONS = 0x1F03;
                constexpr int _GL_NEAREST = 0x2600;
                constexpr int _GL_LINEAR = 0x2601;
                constexpr int _GL_NEAREST_MIPMAP_NEAREST = 0x2700;
                constexpr int _GL_LINEAR_MIPMAP_NEAREST = 0x2701;
                constexpr int _GL_NEAREST_MIPMAP_LINEAR = 0x2702;
                constexpr int _GL_LINEAR_MIPMAP_LINEAR = 0x2703;
                constexpr int _GL_TEXTURE_MAG_FILTER = 0x2800;
                constexpr int _GL_TEXTURE_MIN_FILTER = 0x2801;
                constexpr int _GL_TEXTURE_WRAP_S = 0x2802;
                constexpr int _GL_TEXTURE_WRAP_T = 0x2803;
                constexpr int _GL_REPEAT = 0x2901;
                constexpr int _GL_COLOR_LOGIC_OP = 0x0BF2;
                constexpr int _GL_POLYGON_OFFSET_UNITS = 0x2A00;
                constexpr int _GL_POLYGON_OFFSET_POINT = 0x2A01;
                constexpr int _GL_POLYGON_OFFSET_LINE = 0x2A02;
                constexpr int _GL_POLYGON_OFFSET_FILL = 0x8037;
                constexpr int _GL_POLYGON_OFFSET_FACTOR = 0x8038;
                constexpr int _GL_TEXTURE_BINDING_1D = 0x8068;
                constexpr int _GL_TEXTURE_BINDING_2D = 0x8069;
                constexpr int _GL_TEXTURE_INTERNAL_FORMAT = 0x1003;
                constexpr int _GL_TEXTURE_RED_SIZE = 0x805C;
                constexpr int _GL_TEXTURE_GREEN_SIZE = 0x805D;
                constexpr int _GL_TEXTURE_BLUE_SIZE = 0x805E;
                constexpr int _GL_TEXTURE_ALPHA_SIZE = 0x805F;
                constexpr int _GL_DOUBLE = 0x140A;
                constexpr int _GL_PROXY_TEXTURE_1D = 0x8063;
                constexpr int _GL_PROXY_TEXTURE_2D = 0x8064;
                constexpr int _GL_R3_G3_B2 = 0x2A10;
                constexpr int _GL_RGB4 = 0x804F;
                constexpr int _GL_RGB5 = 0x8050;
                constexpr int _GL_RGB8 = 0x8051;
                constexpr int _GL_RGB10 = 0x8052;
                constexpr int _GL_RGB12 = 0x8053;
                constexpr int _GL_RGB16 = 0x8054;
                constexpr int _GL_RGBA2 = 0x8055;
                constexpr int _GL_RGBA4 = 0x8056;
                constexpr int _GL_RGB5_A1 = 0x8057;
                constexpr int _GL_RGBA8 = 0x8058;
                constexpr int _GL_RGB10_A2 = 0x8059;
                constexpr int _GL_RGBA12 = 0x805A;
                constexpr int _GL_RGBA16 = 0x805B;
                constexpr int _GL_UNSIGNED_BYTE_3_3_2 = 0x8032;
                constexpr int _GL_UNSIGNED_SHORT_4_4_4_4 = 0x8033;
                constexpr int _GL_UNSIGNED_SHORT_5_5_5_1 = 0x8034;
                constexpr int _GL_UNSIGNED_INT_8_8_8_8 = 0x8035;
                constexpr int _GL_UNSIGNED_INT_10_10_10_2 = 0x8036;
                constexpr int _GL_TEXTURE_BINDING_3D = 0x806A;
                constexpr int _GL_PACK_SKIP_IMAGES = 0x806B;
                constexpr int _GL_PACK_IMAGE_HEIGHT = 0x806C;
                constexpr int _GL_UNPACK_SKIP_IMAGES = 0x806D;
                constexpr int _GL_UNPACK_IMAGE_HEIGHT = 0x806E;
                constexpr int _GL_TEXTURE_3D = 0x806F;
                constexpr int _GL_PROXY_TEXTURE_3D = 0x8070;
                constexpr int _GL_TEXTURE_DEPTH = 0x8071;
                constexpr int _GL_TEXTURE_WRAP_R = 0x8072;
                constexpr int _GL_MAX_3D_TEXTURE_SIZE = 0x8073;
                constexpr int _GL_UNSIGNED_BYTE_2_3_3_REV = 0x8362;
                constexpr int _GL_UNSIGNED_SHORT_5_6_5 = 0x8363;
                constexpr int _GL_UNSIGNED_SHORT_5_6_5_REV = 0x8364;
                constexpr int _GL_UNSIGNED_SHORT_4_4_4_4_REV = 0x8365;
                constexpr int _GL_UNSIGNED_SHORT_1_5_5_5_REV = 0x8366;
                constexpr int _GL_UNSIGNED_INT_8_8_8_8_REV = 0x8367;
                constexpr int _GL_UNSIGNED_INT_2_10_10_10_REV = 0x8368;
                constexpr int _GL_BGR = 0x80E0;
                constexpr int _GL_BGRA = 0x80E1;
                constexpr int _GL_MAX_ELEMENTS_VERTICES = 0x80E8;
                constexpr int _GL_MAX_ELEMENTS_INDICES = 0x80E9;
                constexpr int _GL_CLAMP_TO_EDGE = 0x812F;
                constexpr int _GL_TEXTURE_MIN_LOD = 0x813A;
                constexpr int _GL_TEXTURE_MAX_LOD = 0x813B;
                constexpr int _GL_TEXTURE_BASE_LEVEL = 0x813C;
                constexpr int _GL_TEXTURE_MAX_LEVEL = 0x813D;
                constexpr int _GL_SMOOTH_POINT_SIZE_RANGE = 0x0B12;
                constexpr int _GL_SMOOTH_POINT_SIZE_GRANULARITY = 0x0B13;
                constexpr int _GL_SMOOTH_LINE_WIDTH_RANGE = 0x0B22;
                constexpr int _GL_SMOOTH_LINE_WIDTH_GRANULARITY = 0x0B23;
                constexpr int _GL_ALIASED_LINE_WIDTH_RANGE = 0x846E;
#ifndef DONT_INCLUDE_GLAD
                consteval void CheckConstantsPart3() {
                    static_assert(_GL_STENCIL==GL_STENCIL,"_GL_STENCIL is not equal to GL_STENCIL");
                    static_assert(_GL_STENCIL_INDEX == GL_STENCIL_INDEX, "_GL_STENCIL_INDEX is not equal to GL_STENCIL_INDEX");
                    static_assert(_GL_DEPTH_COMPONENT == GL_DEPTH_COMPONENT, "_GL_DEPTH_COMPONENT is not equal to GL_DEPTH_COMPONENT");
                    static_assert(_GL_RED == GL_RED, "_GL_RED is not equal to GL_RED");
                    static_assert(_GL_GREEN == GL_GREEN, "_GL_GREEN is not equal to GL_GREEN");
                    static_assert(_GL_BLUE == GL_BLUE, "_GL_BLUE is not equal to GL_BLUE");
                    static_assert(_GL_ALPHA == GL_ALPHA, "_GL_ALPHA is not equal to GL_ALPHA");
                    static_assert(_GL_RGB == GL_RGB, "_GL_RGB is not equal to GL_RGB");
                    static_assert(_GL_RGBA == GL_RGBA, "_GL_RGBA is not equal to GL_RGBA");
                    static_assert(_GL_POINT == GL_POINT, "_GL_POINT is not equal to GL_POINT");
                    static_assert(_GL_LINE == GL_LINE, "_GL_LINE is not equal to GL_LINE");
                    static_assert(_GL_FILL == GL_FILL, "_GL_FILL is not equal to GL_FILL");
                    static_assert(_GL_KEEP == GL_KEEP, "_GL_KEEP is not equal to GL_KEEP");
                    static_assert(_GL_REPLACE == GL_REPLACE, "_GL_REPLACE is not equal to GL_REPLACE");
                    static_assert(_GL_INCR == GL_INCR, "_GL_INCR is not equal to GL_INCR");
                    static_assert(_GL_DECR == GL_DECR, "_GL_DECR is not equal to GL_DECR");
                    static_assert(_GL_VENDOR == GL_VENDOR, "_GL_VENDOR is not equal to GL_VENDOR");
                    static_assert(_GL_RENDERER == GL_RENDERER, "_GL_RENDERER is not equal to GL_RENDERER");
                    static_assert(_GL_VERSION == GL_VERSION, "_GL_VERSION  is not equal to GL_VERSION");
                    static_assert(_GL_EXTENSIONS == GL_EXTENSIONS, "_GL_EXTENSIONS  is not equal to GL_EXTENSIONS");
                    static_assert(_GL_NEAREST == GL_NEAREST, "_GL_NEAREST  is not equal to GL_NEAREST");
                    static_assert(_GL_LINEAR == GL_LINEAR, "_GL_LINEAR  is not equal to GL_LINEAR");
                    static_assert(_GL_NEAREST_MIPMAP_NEAREST == GL_NEAREST_MIPMAP_NEAREST, "_GL_NEAREST_MIPMAP_NEAREST  is not equal to GL_NEAREST_MIPMAP_NEAREST");
                    static_assert(_GL_LINEAR_MIPMAP_NEAREST == GL_LINEAR_MIPMAP_NEAREST, "_GL_LINEAR_MIPMAP_NEAREST  is not equal to GL_LINEAR_MIPMAP_NEAREST");
                    static_assert(_GL_NEAREST_MIPMAP_LINEAR == GL_NEAREST_MIPMAP_LINEAR, "_GL_NEAREST_MIPMAP_LINEAR  is not equal to GL_NEAREST_MIPMAP_LINEAR");
                    static_assert(_GL_LINEAR_MIPMAP_LINEAR == GL_LINEAR_MIPMAP_LINEAR, "_GL_LINEAR_MIPMAP_LINEAR  is not equal to GL_LINEAR_MIPMAP_LINEAR");
                    static_assert(_GL_TEXTURE_MAG_FILTER == GL_TEXTURE_MAG_FILTER, "_GL_TEXTURE_MAG_FILTER  is not equal to GL_TEXTURE_MAG_FILTER");
                    static_assert(_GL_TEXTURE_MIN_FILTER == GL_TEXTURE_MIN_FILTER, "_GL_TEXTURE_MIN_FILTER  is not equal to GL_TEXTURE_MIN_FILTER");
                    static_assert(_GL_TEXTURE_WRAP_S == GL_TEXTURE_WRAP_S, "_GL_TEXTURE_WRAP_S  is not equal to GL_TEXTURE_WRAP_S");
                    static_assert(_GL_TEXTURE_WRAP_T == GL_TEXTURE_WRAP_T, "_GL_TEXTURE_WRAP_T  is not equal to GL_TEXTURE_WRAP_T");
                    static_assert(_GL_REPEAT == GL_REPEAT, "_GL_REPEAT  is not equal to GL_REPEAT");
                    static_assert(_GL_COLOR_LOGIC_OP == GL_COLOR_LOGIC_OP, "_GL_COLOR_LOGIC_OP  is not equal to GL_COLOR_LOGIC_OP");
                    static_assert(_GL_POLYGON_OFFSET_UNITS == GL_POLYGON_OFFSET_UNITS, "_GL_POLYGON_OFFSET_UNITS  is not equal to GL_POLYGON_OFFSET_UNITS");
                    static_assert(_GL_POLYGON_OFFSET_POINT == GL_POLYGON_OFFSET_POINT, "_GL_POLYGON_OFFSET_POINT  is not equal to GL_POLYGON_OFFSET_POINT");
                    static_assert(_GL_POLYGON_OFFSET_LINE == GL_POLYGON_OFFSET_LINE, "_GL_POLYGON_OFFSET_LINE  is not equal to GL_POLYGON_OFFSET_LINE");
                    static_assert(_GL_POLYGON_OFFSET_FILL == GL_POLYGON_OFFSET_FILL, "_GL_POLYGON_OFFSET_FILL  is not equal to GL_POLYGON_OFFSET_FILL");
                    static_assert(_GL_POLYGON_OFFSET_FACTOR == GL_POLYGON_OFFSET_FACTOR, "_GL_POLYGON_OFFSET_FACTOR  is not equal to GL_POLYGON_OFFSET_FACTOR");
                    static_assert(_GL_TEXTURE_BINDING_1D == GL_TEXTURE_BINDING_1D, "_GL_TEXTURE_BINDING_1D  is not equal to GL_TEXTURE_BINDING_1D");
                    static_assert(_GL_TEXTURE_BINDING_2D == GL_TEXTURE_BINDING_2D, "_GL_TEXTURE_BINDING_2D  is not equal to GL_TEXTURE_BINDING_2D");
                    static_assert(_GL_TEXTURE_INTERNAL_FORMAT == GL_TEXTURE_INTERNAL_FORMAT, "_GL_TEXTURE_INTERNAL_FORMAT  is not equal to GL_TEXTURE_INTERNAL_FORMAT");
                    static_assert(_GL_TEXTURE_RED_SIZE == GL_TEXTURE_RED_SIZE, "_GL_TEXTURE_RED_SIZE  is not equal to GL_TEXTURE_RED_SIZE");
                    static_assert(_GL_TEXTURE_GREEN_SIZE == GL_TEXTURE_GREEN_SIZE, "_GL_TEXTURE_GREEN_SIZE  is not equal to GL_TEXTURE_GREEN_SIZE");
                    static_assert(_GL_TEXTURE_BLUE_SIZE == GL_TEXTURE_BLUE_SIZE, "_GL_TEXTURE_BLUE_SIZE  is not equal to GL_TEXTURE_BLUE_SIZE");
                    static_assert(_GL_TEXTURE_ALPHA_SIZE == GL_TEXTURE_ALPHA_SIZE, "_GL_TEXTURE_ALPHA_SIZE  is not equal to GL_TEXTURE_ALPHA_SIZE");
                    static_assert(_GL_DOUBLE == GL_DOUBLE, "_GL_DOUBLE  is not equal to GL_DOUBLE");
                    static_assert(_GL_PROXY_TEXTURE_1D == GL_PROXY_TEXTURE_1D, "_GL_PROXY_TEXTURE_1D  is not equal to GL_PROXY_TEXTURE_1D");
                    static_assert(_GL_PROXY_TEXTURE_2D == GL_PROXY_TEXTURE_2D, "_GL_PROXY_TEXTURE_2D  is not equal to GL_PROXY_TEXTURE_2D");
                    static_assert(_GL_R3_G3_B2 == GL_R3_G3_B2, "_GL_R3_G3_B2  is not equal to GL_R3_G3_B2");
                    static_assert(_GL_RGB4 == GL_RGB4, "_GL_RGB4  is not equal to GL_RGB4");
                    static_assert(_GL_RGB5 == GL_RGB5, "_GL_RGB5  is not equal to GL_RGB5");
                    static_assert(_GL_RGB8 == GL_RGB8, "_GL_RGB8  is not equal to GL_RGB8");
                    static_assert(_GL_RGB10 == GL_RGB10, "_GL_RGB10  is not equal to GL_RGB10");
                    static_assert(_GL_RGB12 == GL_RGB12, "_GL_RGB12  is not equal to GL_RGB12");
                    static_assert(_GL_RGB16 == GL_RGB16, "_GL_RGB16  is not equal to GL_RGB16");
                    static_assert(_GL_RGBA2 == GL_RGBA2, "_GL_RGBA2  is not equal to GL_RGBA2");
                    static_assert(_GL_RGBA4 == GL_RGBA4, "_GL_RGBA4  is not equal to GL_RGBA4");
                    static_assert(_GL_RGB5_A1 == GL_RGB5_A1, "_GL_RGB5_A1  is not equal to GL_RGB5_A1");
                    static_assert(_GL_RGBA8 == GL_RGBA8, "_GL_RGBA8  is not equal to GL_RGBA8");
                    static_assert(_GL_RGB10_A2 == GL_RGB10_A2, "_GL_RGB10_A2  is not equal to GL_RGB10_A2");
                    static_assert(_GL_RGBA12 == GL_RGBA12, "_GL_RGBA12  is not equal to GL_RGBA12");
                    static_assert(_GL_RGBA16 == GL_RGBA16, "_GL_RGBA16  is not equal to GL_RGBA16");
                    static_assert(_GL_UNSIGNED_BYTE_3_3_2 == GL_UNSIGNED_BYTE_3_3_2, "_GL_UNSIGNED_BYTE_3_3_2  is not equal to GL_UNSIGNED_BYTE_3_3_2");
                    static_assert(_GL_UNSIGNED_SHORT_4_4_4_4 == GL_UNSIGNED_SHORT_4_4_4_4, "_GL_UNSIGNED_SHORT_4_4_4_4  is not equal to GL_UNSIGNED_SHORT_4_4_4_4");
                    static_assert(_GL_UNSIGNED_SHORT_5_5_5_1 == GL_UNSIGNED_SHORT_5_5_5_1, "_GL_UNSIGNED_SHORT_5_5_5_1  is not equal to GL_UNSIGNED_SHORT_5_5_5_1");
                    static_assert(_GL_UNSIGNED_INT_8_8_8_8 == GL_UNSIGNED_INT_8_8_8_8, "_GL_UNSIGNED_INT_8_8_8_8 is not equal to GL_UNSIGNED_INT_8_8_8_8");
                    static_assert(_GL_UNSIGNED_INT_10_10_10_2 == GL_UNSIGNED_INT_10_10_10_2, "_GL_UNSIGNED_INT_10_10_10_2  is not equal to GL_UNSIGNED_INT_10_10_10_2");
                    static_assert(_GL_TEXTURE_BINDING_3D == GL_TEXTURE_BINDING_3D, "_GL_TEXTURE_BINDING_3D  is not equal to GL_TEXTURE_BINDING_3D");
                    static_assert(_GL_PACK_SKIP_IMAGES == GL_PACK_SKIP_IMAGES, "_GL_PACK_SKIP_IMAGES  is not equal to GL_PACK_SKIP_IMAGES");
                    static_assert(_GL_PACK_IMAGE_HEIGHT == GL_PACK_IMAGE_HEIGHT, "_GL_PACK_IMAGE_HEIGHT  is not equal to GL_PACK_IMAGE_HEIGHT");
                    static_assert(_GL_UNPACK_SKIP_IMAGES == GL_UNPACK_SKIP_IMAGES, "_GL_UNPACK_SKIP_IMAGES  is not equal to GL_UNPACK_SKIP_IMAGES");
                    static_assert(_GL_UNPACK_IMAGE_HEIGHT == GL_UNPACK_IMAGE_HEIGHT, "_GL_UNPACK_IMAGE_HEIGHT  is not equal to GL_UNPACK_IMAGE_HEIGHT");
                    static_assert(_GL_TEXTURE_3D == GL_TEXTURE_3D, "_GL_TEXTURE_3D  is not equal to GL_TEXTURE_3D");
                    static_assert(_GL_PROXY_TEXTURE_3D == GL_PROXY_TEXTURE_3D, "_GL_PROXY_TEXTURE_3D  is not equal to GL_PROXY_TEXTURE_3D");
                    static_assert(_GL_TEXTURE_DEPTH == GL_TEXTURE_DEPTH, "_GL_TEXTURE_DEPTH  is not equal to GL_TEXTURE_DEPTH");
                    static_assert(_GL_TEXTURE_WRAP_R == GL_TEXTURE_WRAP_R, "_GL_TEXTURE_WRAP_R  is not equal to GL_TEXTURE_WRAP_R");
                    static_assert(_GL_MAX_3D_TEXTURE_SIZE == GL_MAX_3D_TEXTURE_SIZE, "_GL_MAX_3D_TEXTURE_SIZE  is not equal to GL_MAX_3D_TEXTURE_SIZE");
                    static_assert(_GL_UNSIGNED_BYTE_2_3_3_REV == GL_UNSIGNED_BYTE_2_3_3_REV, "_GL_UNSIGNED_BYTE_2_3_3_REV  is not equal to GL_UNSIGNED_BYTE_2_3_3_REV");
                    static_assert(_GL_UNSIGNED_SHORT_5_6_5 == GL_UNSIGNED_SHORT_5_6_5, "_GL_UNSIGNED_SHORT_5_6_5  is not equal to GL_UNSIGNED_SHORT_5_6_5");
                    static_assert(_GL_UNSIGNED_SHORT_5_6_5_REV == GL_UNSIGNED_SHORT_5_6_5_REV, "_GL_UNSIGNED_SHORT_5_6_5_REV  is not equal to GL_UNSIGNED_SHORT_5_6_5_REV");
                    static_assert(_GL_UNSIGNED_SHORT_4_4_4_4_REV == GL_UNSIGNED_SHORT_4_4_4_4_REV, "_GL_UNSIGNED_SHORT_4_4_4_4_REV  is not equal to GL_UNSIGNED_SHORT_4_4_4_4_REV");
                    static_assert(_GL_UNSIGNED_SHORT_1_5_5_5_REV == GL_UNSIGNED_SHORT_1_5_5_5_REV, "_GL_UNSIGNED_SHORT_1_5_5_5_REV  is not equal to GL_UNSIGNED_SHORT_1_5_5_5_REV");
                    static_assert(_GL_UNSIGNED_INT_8_8_8_8_REV == GL_UNSIGNED_INT_8_8_8_8_REV, "_GL_UNSIGNED_INT_8_8_8_8_REV  is not equal to GL_UNSIGNED_INT_8_8_8_8_REV");
                    static_assert(_GL_UNSIGNED_INT_2_10_10_10_REV == GL_UNSIGNED_INT_2_10_10_10_REV, "_GL_UNSIGNED_INT_2_10_10_10_REV  is not equal to GL_UNSIGNED_INT_2_10_10_10_REV");
                    static_assert(_GL_BGR == GL_BGR, "_GL_BGR  is not equal to GL_BGR");
                    static_assert(_GL_BGRA == GL_BGRA, "_GL_BGRA  is not equal to GL_BGRA");
                    static_assert(_GL_MAX_ELEMENTS_VERTICES == GL_MAX_ELEMENTS_VERTICES, "_GL_MAX_ELEMENTS_VERTICES  is not equal to GL_MAX_ELEMENTS_VERTICES");
                    static_assert(_GL_MAX_ELEMENTS_INDICES == GL_MAX_ELEMENTS_INDICES, "_GL_MAX_ELEMENTS_INDICES  is not equal to GL_MAX_ELEMENTS_INDICES");
                    static_assert(_GL_CLAMP_TO_EDGE == GL_CLAMP_TO_EDGE, "_GL_CLAMP_TO_EDGE  is not equal to GL_CLAMP_TO_EDGE");
                    static_assert(_GL_TEXTURE_MIN_LOD == GL_TEXTURE_MIN_LOD, "_GL_TEXTURE_MIN_LOD  is not equal to GL_TEXTURE_MIN_LOD");
                    static_assert(_GL_TEXTURE_MAX_LOD == GL_TEXTURE_MAX_LOD, "_GL_TEXTURE_MAX_LOD  is not equal to GL_TEXTURE_MAX_LOD");
                    static_assert(_GL_TEXTURE_BASE_LEVEL == GL_TEXTURE_BASE_LEVEL, "_GL_TEXTURE_BASE_LEVEL  is not equal to GL_TEXTURE_BASE_LEVEL");
                    static_assert(_GL_TEXTURE_MAX_LEVEL == GL_TEXTURE_MAX_LEVEL, "_GL_TEXTURE_MAX_LEVEL  is not equal to GL_TEXTURE_MAX_LEVEL");
                    static_assert(_GL_SMOOTH_POINT_SIZE_RANGE == GL_SMOOTH_POINT_SIZE_RANGE, "_GL_SMOOTH_POINT_SIZE_RANGE  is not equal to GL_SMOOTH_POINT_SIZE_RANGE");
                    static_assert(_GL_SMOOTH_POINT_SIZE_GRANULARITY == GL_SMOOTH_POINT_SIZE_GRANULARITY, "_GL_SMOOTH_POINT_SIZE_GRANULARITY  is not equal to GL_SMOOTH_POINT_SIZE_GRANULARITY");
                    static_assert(_GL_SMOOTH_LINE_WIDTH_RANGE == GL_SMOOTH_LINE_WIDTH_RANGE, "_GL_SMOOTH_LINE_WIDTH_RANGE  is not equal to GL_SMOOTH_LINE_WIDTH_RANGE");
                    static_assert(_GL_SMOOTH_LINE_WIDTH_GRANULARITY == GL_SMOOTH_LINE_WIDTH_GRANULARITY, "_GL_SMOOTH_LINE_WIDTH_GRANULARITY  is not equal to GL_SMOOTH_LINE_WIDTH_GRANULARITY");
                    static_assert(_GL_ALIASED_LINE_WIDTH_RANGE == GL_ALIASED_LINE_WIDTH_RANGE, "_GL_ALIASED_LINE_WIDTH_RANGE  is not equal to GL_ALIASED_LINE_WIDTH_RANGE");
                }
#endif
            }
        }
    }
}
#endif

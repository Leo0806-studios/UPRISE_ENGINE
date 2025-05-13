#pragma once
#ifndef UE_CONSTANTS_PART2_INTERNAL_
#define UE_CONSTANTS_PART2_INTERNAL_
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
                constexpr int _GL_LINE_SMOOTH = 0x0B20;
                constexpr int _GL_LINE_WIDTH = 0x0B21;
                constexpr int _GL_LINE_WIDTH_RANGE = 0x0B22;
                constexpr int _GL_LINE_WIDTH_GRANULARITY = 0x0B23;
                constexpr int _GL_POLYGON_MODE = 0x0B40;
                constexpr int _GL_POLYGON_SMOOTH = 0x0B41;
                constexpr int _GL_CULL_FACE = 0x0B44;
                constexpr int _GL_CULL_FACE_MODE = 0x0B45;
                constexpr int _GL_FRONT_FACE = 0x0B46;
                constexpr int _GL_DEPTH_RANGE = 0x0B70;
                constexpr int _GL_DEPTH_TEST = 0x0B71;
                constexpr int _GL_DEPTH_WRITEMASK = 0x0B72;
                constexpr int _GL_DEPTH_CLEAR_VALUE = 0x0B73;
                constexpr int _GL_DEPTH_FUNC = 0x0B74;
                constexpr int _GL_STENCIL_TEST = 0x0B90;
                constexpr int _GL_STENCIL_CLEAR_VALUE = 0x0B91;
                constexpr int _GL_STENCIL_FUNC = 0x0B92;
                constexpr int _GL_STENCIL_VALUE_MASK = 0x0B93;
                constexpr int _GL_STENCIL_FAIL = 0x0B94;
                constexpr int _GL_STENCIL_PASS_DEPTH_FAIL = 0x0B95;
                constexpr int _GL_STENCIL_PASS_DEPTH_PASS = 0x0B96;
                constexpr int _GL_STENCIL_REF = 0x0B97;
                constexpr int _GL_STENCIL_WRITEMASK = 0x0B98;
                constexpr int _GL_VIEWPORT = 0x0BA2;
                constexpr int _GL_DITHER = 0x0BD0;
                constexpr int _GL_BLEND_DST = 0x0BE0;
                constexpr int _GL_BLEND_SRC = 0x0BE1;
                constexpr int _GL_BLEND = 0x0BE2;
                constexpr int _GL_LOGIC_OP_MODE = 0x0BF0;
                constexpr int _GL_DRAW_BUFFER = 0x0C01;
                constexpr int _GL_READ_BUFFER = 0x0C02;
                constexpr int _GL_SCISSOR_BOX = 0x0C10;
                constexpr int _GL_SCISSOR_TEST = 0x0C11;
                constexpr int _GL_COLOR_CLEAR_VALUE = 0x0C22;
                constexpr int _GL_COLOR_WRITEMASK = 0x0C23;
                constexpr int _GL_DOUBLEBUFFER = 0x0C32;
                constexpr int _GL_STEREO = 0x0C33;
                constexpr int _GL_LINE_SMOOTH_HINT = 0x0C52;
                constexpr int _GL_POLYGON_SMOOTH_HINT = 0x0C53;
                constexpr int _GL_UNPACK_SWAP_BYTES = 0x0CF0;
                constexpr int _GL_UNPACK_LSB_FIRST = 0x0CF1;
                constexpr int _GL_UNPACK_ROW_LENGTH = 0x0CF2;
                constexpr int _GL_UNPACK_SKIP_ROWS = 0x0CF3;
                constexpr int _GL_UNPACK_SKIP_PIXELS = 0x0CF4;
                constexpr int _GL_UNPACK_ALIGNMENT = 0x0CF5;
                constexpr int _GL_PACK_SWAP_BYTES = 0x0D00;
                constexpr int _GL_PACK_LSB_FIRST = 0x0D01;
                constexpr int _GL_PACK_ROW_LENGTH = 0x0D02;
                constexpr int _GL_PACK_SKIP_ROWS = 0x0D03;
                constexpr int _GL_PACK_SKIP_PIXELS = 0x0D04;
                constexpr int _GL_PACK_ALIGNMENT = 0x0D05;
                constexpr int _GL_MAX_TEXTURE_SIZE = 0x0D33;
                constexpr int _GL_MAX_VIEWPORT_DIMS = 0x0D3A;
                constexpr int _GL_SUBPIXEL_BITS = 0x0D50;
                constexpr int _GL_TEXTURE_1D = 0x0DE0;
                constexpr int _GL_TEXTURE_2D = 0x0DE1;
                constexpr int _GL_TEXTURE_WIDTH = 0x1000;
                constexpr int _GL_TEXTURE_HEIGHT = 0x1001;
                constexpr int _GL_TEXTURE_BORDER_COLOR = 0x1004;
                constexpr int _GL_DONT_CARE = 0x1100;
                constexpr int _GL_FASTEST = 0x1101;
                constexpr int _GL_NICEST = 0x1102;
                constexpr int _GL_BYTE = 0x1400;
                constexpr int _GL_UNSIGNED_BYTE = 0x1401;
                constexpr int _GL_SHORT = 0x1402;
                constexpr int _GL_UNSIGNED_SHORT = 0x1403;
                constexpr int _GL_INT = 0x1404;
                constexpr int _GL_UNSIGNED_INT = 0x1405;
                constexpr int _GL_FLOAT = 0x1406;
                constexpr int _GL_CLEAR = 0x1500;
                constexpr int _GL_AND = 0x1501;
                constexpr int _GL_AND_REVERSE = 0x1502;
                constexpr int _GL_COPY = 0x1503;
                constexpr int _GL_AND_INVERTED = 0x1504;
                constexpr int _GL_NOOP = 0x1505;
                constexpr int _GL_XOR = 0x1506;
                constexpr int _GL_OR = 0x1507;
                constexpr int _GL_NOR = 0x1508;
                constexpr int _GL_EQUIV = 0x1509;
                constexpr int _GL_INVERT = 0x150A;
                constexpr int _GL_OR_REVERSE = 0x150B;
                constexpr int _GL_COPY_INVERTED = 0x150C;
                constexpr int _GL_OR_INVERTED = 0x150D;
                constexpr int _GL_NAND = 0x150E;
                constexpr int _GL_SET = 0x150F;
                constexpr int _GL_TEXTURE = 0x1702;
                constexpr int _GL_COLOR = 0x1800;
                constexpr int _GL_DEPTH = 0x1801;
                consteval void CheckConstantsPart2() {
                    static_assert(_GL_LINE_SMOOTH == GL_LINE_SMOOTH, "GL_LINE_SMOOTH is not equal to _GL_LINE_SMOOTH");
                    static_assert(_GL_LINE_WIDTH == GL_LINE_WIDTH, "GL_LINE_WIDTH is not equal to _GL_LINE_WIDTH");
                    static_assert(_GL_LINE_WIDTH_RANGE == GL_LINE_WIDTH_RANGE, "GL_LINE_WIDTH_RANGE is not equal to _GL_LINE_WIDTH_RANGE");
                    static_assert(_GL_LINE_WIDTH_GRANULARITY == GL_LINE_WIDTH_GRANULARITY, "GL_LINE_WIDTH_GRANULARITY is not equal to _GL_LINE_WIDTH_GRANULARITY");
                    static_assert(_GL_POLYGON_MODE == GL_POLYGON_MODE, "GL_POLYGON_MODE is not equal to _GL_POLYGON_MODE");
                    static_assert(_GL_POLYGON_SMOOTH == GL_POLYGON_SMOOTH, "GL_POLYGON_SMOOTH is not equal to _GL_POLYGON_SMOOTH");
                    static_assert(_GL_CULL_FACE == GL_CULL_FACE, "GL_CULL_FACE is not equal to _GL_CULL_FACE");
                    static_assert(_GL_CULL_FACE_MODE == GL_CULL_FACE_MODE, "GL_CULL_FACE_MODE is not equal to _GL_CULL_FACE_MODE");
                    static_assert(_GL_FRONT_FACE == GL_FRONT_FACE, "GL_FRONT_FACE is not equal to _GL_FRONT_FACE");
                    static_assert(_GL_DEPTH_RANGE == GL_DEPTH_RANGE, "GL_DEPTH_RANGE is not equal to _GL_DEPTH_RANGE");
                    static_assert(_GL_DEPTH_TEST == GL_DEPTH_TEST, "GL_DEPTH_TEST is not equal to _GL_DEPTH_TEST");
                    static_assert(_GL_DEPTH_WRITEMASK == GL_DEPTH_WRITEMASK, "GL_DEPTH_WRITEMASK is not equal to _GL_DEPTH_WRITEMASK");
                    static_assert(_GL_DEPTH_CLEAR_VALUE == GL_DEPTH_CLEAR_VALUE, "GL_DEPTH_CLEAR_VALUE is not equal to _GL_DEPTH_CLEAR_VALUE");
                    static_assert(_GL_DEPTH_FUNC == GL_DEPTH_FUNC, "GL_DEPTH_FUNC is not equal to _GL_DEPTH_FUNC");
                    static_assert(_GL_STENCIL_TEST == GL_STENCIL_TEST, "GL_STENCIL_TEST is not equal to _GL_STENCIL_TEST");
                    static_assert(_GL_STENCIL_CLEAR_VALUE == GL_STENCIL_CLEAR_VALUE, "GL_STENCIL_CLEAR_VALUE is not equal to _GL_STENCIL_CLEAR_VALUE");
                    static_assert(_GL_STENCIL_FUNC == GL_STENCIL_FUNC, "GL_STENCIL_FUNC is not equal to _GL_STENCIL_FUNC");
                    static_assert(_GL_STENCIL_VALUE_MASK == GL_STENCIL_VALUE_MASK, "GL_STENCIL_VALUE_MASK is not equal to _GL_STENCIL_VALUE_MASK");
                    static_assert(_GL_STENCIL_FAIL == GL_STENCIL_FAIL, "GL_STENCIL_FAIL is not equal to _GL_STENCIL_FAIL");
                    static_assert(_GL_STENCIL_PASS_DEPTH_FAIL == GL_STENCIL_PASS_DEPTH_FAIL, "GL_STENCIL_PASS_DEPTH_FAIL is not equal to _GL_STENCIL_PASS_DEPTH_FAIL");
                    static_assert(_GL_STENCIL_PASS_DEPTH_PASS == GL_STENCIL_PASS_DEPTH_PASS, "GL_STENCIL_PASS_DEPTH_PASS is not equal to _GL_STENCIL_PASS_DEPTH_PASS");
                    static_assert(_GL_STENCIL_REF == GL_STENCIL_REF, "GL_STENCIL_REF is not equal to _GL_STENCIL_REF");
                    static_assert(_GL_STENCIL_WRITEMASK == GL_STENCIL_WRITEMASK, "GL_STENCIL_WRITEMASK is not equal to _GL_STENCIL_WRITEMASK");
                    static_assert(_GL_VIEWPORT == GL_VIEWPORT, "GL_VIEWPORT is not equal to _GL_VIEWPORT");
                    static_assert(_GL_DITHER == GL_DITHER, "GL_DITHER is not equal to _GL_DITHER");
                    static_assert(_GL_BLEND_DST == GL_BLEND_DST, "GL_BLEND_DST is not equal to _GL_BLEND_DST");
                    static_assert(_GL_BLEND_SRC == GL_BLEND_SRC, "GL_BLEND_SRC is not equal to _GL_BLEND_SRC");
                    static_assert(_GL_BLEND == GL_BLEND, "GL_BLEND is not equal to _GL_BLEND");
                    static_assert(_GL_LOGIC_OP_MODE == GL_LOGIC_OP_MODE, "GL_LOGIC_OP_MODE is not equal to _GL_LOGIC_OP_MODE");
                    static_assert(_GL_DRAW_BUFFER == GL_DRAW_BUFFER, "GL_DRAW_BUFFER is not equal to _GL_DRAW_BUFFER");
                    static_assert(_GL_READ_BUFFER == GL_READ_BUFFER, "GL_READ_BUFFER is not equal to _GL_READ_BUFFER");
                    static_assert(_GL_SCISSOR_BOX == GL_SCISSOR_BOX, "GL_SCISSOR_BOX is not equal to _GL_SCISSOR_BOX");
                    static_assert(_GL_SCISSOR_TEST == GL_SCISSOR_TEST, "GL_SCISSOR_TEST is not equal to _GL_SCISSOR_TEST");
                    static_assert(_GL_COLOR_CLEAR_VALUE == GL_COLOR_CLEAR_VALUE, "GL_COLOR_CLEAR_VALUE is not equal to _GL_COLOR_CLEAR_VALUE");
                    static_assert(_GL_COLOR_WRITEMASK == GL_COLOR_WRITEMASK, "GL_COLOR_WRITEMASK is not equal to _GL_COLOR_WRITEMASK");
                    static_assert(_GL_DOUBLEBUFFER == GL_DOUBLEBUFFER, "GL_DOUBLEBUFFER is not equal to _GL_DOUBLEBUFFER");
                    static_assert(_GL_STEREO == GL_STEREO, "GL_STEREO is not equal to _GL_STEREO");
                    static_assert(_GL_LINE_SMOOTH_HINT == GL_LINE_SMOOTH_HINT, "GL_LINE_SMOOTH_HINT is not equal to _GL_LINE_SMOOTH_HINT");
                    static_assert(_GL_POLYGON_SMOOTH_HINT == GL_POLYGON_SMOOTH_HINT, "GL_POLYGON_SMOOTH_HINT is not equal to _GL_POLYGON_SMOOTH_HINT");
                    static_assert(_GL_UNPACK_SWAP_BYTES == GL_UNPACK_SWAP_BYTES, "GL_UNPACK_SWAP_BYTES is not equal to _GL_UNPACK_SWAP_BYTES");
                    static_assert(_GL_UNPACK_LSB_FIRST == GL_UNPACK_LSB_FIRST, "GL_UNPACK_LSB_FIRST is not equal to _GL_UNPACK_LSB_FIRST");
                    static_assert(_GL_UNPACK_ROW_LENGTH == GL_UNPACK_ROW_LENGTH, "GL_UNPACK_ROW_LENGTH is not equal to _GL_UNPACK_ROW_LENGTH");
                    static_assert(_GL_UNPACK_SKIP_ROWS == GL_UNPACK_SKIP_ROWS, "GL_UNPACK_SKIP_ROWS is not equal to _GL_UNPACK_SKIP_ROWS");
                    static_assert(_GL_UNPACK_SKIP_PIXELS == GL_UNPACK_SKIP_PIXELS, "GL_UNPACK_SKIP_PIXELS is not equal to _GL_UNPACK_SKIP_PIXELS");
                    static_assert(_GL_UNPACK_ALIGNMENT == GL_UNPACK_ALIGNMENT, "GL_UNPACK_ALIGNMENT is not equal to _GL_UNPACK_ALIGNMENT");
                    static_assert(_GL_PACK_SWAP_BYTES == GL_PACK_SWAP_BYTES, "GL_PACK_SWAP_BYTES is not equal to _GL_PACK_SWAP_BYTES");
                    static_assert(_GL_PACK_LSB_FIRST == GL_PACK_LSB_FIRST, "GL_PACK_LSB_FIRST is not equal to _GL_PACK_LSB_FIRST");
                    static_assert(_GL_PACK_ROW_LENGTH == GL_PACK_ROW_LENGTH, "GL_PACK_ROW_LENGTH is not equal to _GL_PACK_ROW_LENGTH");
                    static_assert(_GL_PACK_SKIP_ROWS == GL_PACK_SKIP_ROWS, "GL_PACK_SKIP_ROWS is not equal to _GL_PACK_SKIP_ROWS");
                    static_assert(_GL_PACK_SKIP_PIXELS == GL_PACK_SKIP_PIXELS, "GL_PACK_SKIP_PIXELS is not equal to _GL_PACK_SKIP_PIXELS");
                    static_assert(_GL_PACK_ALIGNMENT == GL_PACK_ALIGNMENT, "GL_PACK_ALIGNMENT is not equal to _GL_PACK_ALIGNMENT");
                    static_assert(_GL_MAX_TEXTURE_SIZE == GL_MAX_TEXTURE_SIZE, "GL_MAX_TEXTURE_SIZE is not equal to _GL_MAX_TEXTURE_SIZE");
                    static_assert(_GL_MAX_VIEWPORT_DIMS == GL_MAX_VIEWPORT_DIMS, "GL_MAX_VIEWPORT_DIMS is not equal to _GL_MAX_VIEWPORT_DIMS");
                    static_assert(_GL_SUBPIXEL_BITS == GL_SUBPIXEL_BITS, "GL_SUBPIXEL_BITS is not equal to _GL_SUBPIXEL_BITS");
                    static_assert(_GL_TEXTURE_1D == GL_TEXTURE_1D, "GL_TEXTURE_1D is not equal to _GL_TEXTURE_1D");
                    static_assert(_GL_TEXTURE_2D == GL_TEXTURE_2D, "GL_TEXTURE_2D is not equal to _GL_TEXTURE_2D");
                    static_assert(_GL_TEXTURE_WIDTH == GL_TEXTURE_WIDTH, "GL_TEXTURE_WIDTH is not equal to _GL_TEXTURE_WIDTH");
                    static_assert(_GL_TEXTURE_HEIGHT == GL_TEXTURE_HEIGHT, "GL_TEXTURE_HEIGHT is not equal to _GL_TEXTURE_HEIGHT");
                    static_assert(_GL_TEXTURE_BORDER_COLOR == GL_TEXTURE_BORDER_COLOR, "GL_TEXTURE_BORDER_COLOR is not equal to _GL_TEXTURE_BORDER_COLOR");
                    static_assert(_GL_DONT_CARE == GL_DONT_CARE, "GL_DONT_CARE is not equal to _GL_DONT_CARE");
                    static_assert(_GL_FASTEST == GL_FASTEST, "GL_FASTEST is not equal to _GL_FASTEST");
                    static_assert(_GL_NICEST == GL_NICEST, "GL_NICEST is not equal to _GL_NICEST");
                    static_assert(_GL_BYTE == GL_BYTE, "GL_BYTE is not equal to _GL_BYTE");
                    static_assert(_GL_UNSIGNED_BYTE == GL_UNSIGNED_BYTE, "GL_UNSIGNED_BYTE is not equal to _GL_UNSIGNED_BYTE");
                    static_assert(_GL_SHORT == GL_SHORT, "GL_SHORT is not equal to _GL_SHORT");
                    static_assert(_GL_UNSIGNED_SHORT == GL_UNSIGNED_SHORT, "GL_UNSIGNED_SHORT is not equal to _GL_UNSIGNED_SHORT");
                    static_assert(_GL_INT == GL_INT, "GL_INT is not equal to _GL_INT");
                    static_assert(_GL_UNSIGNED_INT == GL_UNSIGNED_INT, "GL_UNSIGNED_INT is not equal to _GL_UNSIGNED_INT");
                    static_assert(_GL_FLOAT == GL_FLOAT, "GL_FLOAT is not equal to _GL_FLOAT");
                    static_assert(_GL_CLEAR == GL_CLEAR, "GL_CLEAR is not equal to _GL_CLEAR");
                    static_assert(_GL_AND == GL_AND, "GL_AND is not equal to _GL_AND");
                    static_assert(_GL_AND_REVERSE == GL_AND_REVERSE, "GL_AND_REVERSE is not equal to _GL_AND_REVERSE");
                    static_assert(_GL_COPY == GL_COPY, "GL_COPY is not equal to _GL_COPY");
                    static_assert(_GL_AND_INVERTED == GL_AND_INVERTED, "GL_AND_INVERTED is not equal to _GL_AND_INVERTED");
                    static_assert(_GL_NOOP == GL_NOOP, "GL_NOOP is not equal to _GL_NOOP");
                    static_assert(_GL_XOR == GL_XOR, "GL_XOR is not equal to _GL_XOR");
                    static_assert(_GL_OR == GL_OR, "GL_OR is not equal to _GL_OR");
                    static_assert(_GL_NOR == GL_NOR, "GL_NOR is not equal to _GL_NOR");
                    static_assert(_GL_EQUIV == GL_EQUIV, "GL_EQUIV is not equal to _GL_EQUIV");
                    static_assert(_GL_INVERT == GL_INVERT, "GL_INVERT is not equal to _GL_INVERT");
                    static_assert(_GL_OR_REVERSE == GL_OR_REVERSE, "GL_OR_REVERSE is not equal to _GL_OR_REVERSE");
                    static_assert(_GL_COPY_INVERTED == GL_COPY_INVERTED, "GL_COPY_INVERTED is not equal to _GL_COPY_INVERTED");
                    static_assert(_GL_OR_INVERTED == GL_OR_INVERTED, "GL_OR_INVERTED is not equal to _GL_OR_INVERTED");
                    static_assert(_GL_NAND == GL_NAND, "GL_NAND is not equal to _GL_NAND");
                    static_assert(_GL_SET == GL_SET, "GL_SET is not equal to _GL_SET");
                    static_assert(_GL_TEXTURE == GL_TEXTURE, "GL_TEXTURE is not equal to _GL_TEXTURE");
                    static_assert(_GL_COLOR == GL_COLOR, "GL_COLOR is not equal to _GL_COLOR");
                    static_assert(_GL_DEPTH == GL_DEPTH, "GL_DEPTH is not equal to _GL_DEPTH");

                }
            }
        }
    }
}
#endif
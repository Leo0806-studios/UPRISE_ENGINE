// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
export module GLAD;
#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
#define APIENTRY __stdcall
#endif

#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif

#ifndef GLAPIENTRY
#define GLAPIENTRY APIENTRY
#endif

export struct gladGLversionStruct {
    int major;
    int minor;
};
export typedef void* (*GLADloadproc)(const char* name);
#ifndef GLAPI
# if defined(GLAD_GLAPI_EXPORT)
#  if defined(_WIN32) || defined(__CYGWIN__)
#   if defined(GLAD_GLAPI_EXPORT_BUILD)
#    if defined(__GNUC__)
#     define GLAPI __attribute__ ((dllexport)) extern
#    else
#     define GLAPI __declspec(dllexport) extern
#    endif
#   else
#    if defined(__GNUC__)
#     define GLAPI __attribute__ ((dllimport)) extern
#    else
#     define GLAPI __declspec(dllimport) extern
#    endif
#   endif
#  elif defined(__GNUC__) && defined(GLAD_GLAPI_EXPORT_BUILD)
#   define GLAPI __attribute__ ((visibility ("default"))) extern
#  else
#   define GLAPI extern
#  endif
# else
#  define GLAPI extern
# endif
#endif

/// <summary>
/// global instance that holds the version of the loaded OpenGL
/// </summary>
export GLAPI struct gladGLversionStruct GLVersion;
/// <summary>
/// loads the OpenGL library
/// </summary>
/// <param name="void"></param>
/// <returns></returns>
export GLAPI int gladLoadGL(void);
/// <summary>
/// 
/// </summary>
/// <param name=""></param>
/// /// <returns></returns>
export GLAPI int gladLoadGLLoader(GLADloadproc);
#pragma region Khrplatform
#pragma region intro_Comment
/*
** Copyright (c) 2008-2018 The Khronos Group Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and/or associated documentation files (the
** "Materials"), to deal in the Materials without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Materials, and to
** permit persons to whom the Materials are furnished to do so, subject to
** the following conditions:
**
** The above copyright notice and this permission notice shall be included
** in all copies or substantial portions of the Materials.
**
** THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
** CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
** TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
** MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
*/

/* Khronos platform-specific types and definitions.
 *
 * The master copy of khrplatform.h is maintained in the Khronos EGL
 * Registry repository at https://github.com/KhronosGroup/EGL-Registry
 * The last semantic modification to khrplatform.h was at commit ID:
 *      67a3e0864c2d75ea5287b9f3d2eb74a745936692
 *
 * Adopters may modify this file to suit their platform. Adopters are
 * encouraged to submit platform specific modifications to the Khronos
 * group so that they can be included in future versions of this file.
 * Please submit changes by filing pull requests or issues on
 * the EGL Registry repository linked above.
 *
 *
 * See the Implementer's Guidelines for information about where this file
 * should be located on your system and for more details of its use:
 *    http://www.khronos.org/registry/implementers_guide.pdf
 *
 * This file should be included as
 *        #include <KHR/khrplatform.h>
 * by Khronos client API header files that use its types and defines.
 *
 * The types in khrplatform.h should only be used to define API-specific types.
 *
 * Types defined in khrplatform.h:
 *    khronos_int8_t              signed   8  bit
 *    khronos_uint8_t             unsigned 8  bit
 *    khronos_int16_t             signed   16 bit
 *    khronos_uint16_t            unsigned 16 bit
 *    khronos_int32_t             signed   32 bit
 *    khronos_uint32_t            unsigned 32 bit
 *    khronos_int64_t             signed   64 bit
 *    khronos_uint64_t            unsigned 64 bit
 *    khronos_intptr_t            signed   same number of bits as a pointer
 *    khronos_uintptr_t           unsigned same number of bits as a pointer
 *    khronos_ssize_t             signed   size
 *    khronos_usize_t             unsigned size
 *    khronos_float_t             signed   32 bit floating point
 *    khronos_time_ns_t           unsigned 64 bit time in nanoseconds
 *    khronos_utime_nanoseconds_t unsigned time interval or absolute time in
 *                                         nanoseconds
 *    khronos_stime_nanoseconds_t signed time interval in nanoseconds
 *    khronos_boolean_enum_t      enumerated boolean type. This should
 *      only be used as a base type when a client API's boolean type is
 *      an enum. Client APIs which use an integer or other type for
 *      booleans cannot use this as the base type for their boolean.
 *
 * Tokens defined in khrplatform.h:
 *
 *    KHRONOS_FALSE, KHRONOS_TRUE Enumerated boolean false/true values.
 *
 *    KHRONOS_SUPPORT_INT64 is 1 if 64 bit integers are supported; otherwise 0.
 *    KHRONOS_SUPPORT_FLOAT is 1 if floats are supported; otherwise 0.
 *
 * Calling convention macros defined in this file:
 *    KHRONOS_APICALL
 *    KHRONOS_APIENTRY
 *    KHRONOS_APIATTRIBUTES
 *
 * These may be used in function prototypes as:
 *
 *      KHRONOS_APICALL void KHRONOS_APIENTRY funcname(
 *                                  int arg1,
 *                                  int arg2) KHRONOS_APIATTRIBUTES;
 */
#pragma endregion

#if defined(__SCITECH_SNAP__) && !defined(KHRONOS_STATIC)
#   define KHRONOS_STATIC 1
#endif
 /*-------------------------------------------------------------------------
  * Definition of KHRONOS_APICALL
  *-------------------------------------------------------------------------
  * This precedes the return type of the function in the function prototype.
  */
#if defined(KHRONOS_STATIC)
  /* If the preprocessor constant KHRONOS_STATIC is defined, make the
   * header compatible with static linking. */
#   define KHRONOS_APICALL
#elif defined(_WIN32)
#   define KHRONOS_APICALL __declspec(dllimport)
#elif defined (__SYMBIAN32__)
#   define KHRONOS_APICALL IMPORT_C
#elif defined(__ANDROID__)
#   define KHRONOS_APICALL __attribute__((visibility("default")))
#else
#   define KHRONOS_APICALL
#endif


  /*-------------------------------------------------------------------------
   * Definition of KHRONOS_APIENTRY
   *-------------------------------------------------------------------------
   * This follows the return type of the function  and precedes the function
   * name in the function prototype.
   */
#if defined(_WIN32) && !defined(_WIN32_WCE) && !defined(__SCITECH_SNAP__)
   /* Win32 but not WinCE */
#   define KHRONOS_APIENTRY __stdcall
#else
#   define KHRONOS_APIENTRY
#endif




   /*-------------------------------------------------------------------------
    * Definition of KHRONOS_APIATTRIBUTES
    *-------------------------------------------------------------------------
    * This follows the closing parenthesis of the function prototype arguments.
    */
#if defined (__ARMCC_2__)
#define KHRONOS_APIATTRIBUTES __softfp
#else
#define KHRONOS_APIATTRIBUTES
#endif


#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || defined(__GNUC__) || defined(__SCO__) || defined(__USLC__)


    /*
     * Using <stdint.h>
     */
#include <stdint.h>
export typedef int32_t                 khronos_int32_t;
export typedef uint32_t                khronos_uint32_t;
export typedef int64_t                 khronos_int64_t;
export typedef uint64_t                khronos_uint64_t;
constexpr int _KHRONOS_SUPPORT_INT64 = 1;
constexpr int _KHRONOS_SUPPORT_FLOAT = 1;
#define KHRONOS_SUPPORT_INT64   1

#define KHRONOS_SUPPORT_FLOAT   1

/*
 * To support platform where unsigned long cannot be used interchangeably with
 * inptr_t (e.g. CHERI-extended ISAs), we can use the stdint.h intptr_t.
 * Ideally, we could just use (u)intptr_t everywhere, but this could result in
 * ABI breakage if khronos_uintptr_t is changed from unsigned long to
 * unsigned long long or similar (this results in different C++ name mangling).
 * To avoid changes for existing platforms, we restrict usage of intptr_t to
 * platforms where the size of a pointer is larger than the size of long.
 */
#if defined(__SIZEOF_LONG__) && defined(__SIZEOF_POINTER__)
#if __SIZEOF_POINTER__ > __SIZEOF_LONG__
#define KHRONOS_USE_INTPTR_T
#endif
#endif

#elif defined(__VMS ) || defined(__sgi)

    /*
     * Using <inttypes.h>
     */
#include <inttypes.h>
export typedef int32_t                 khronos_int32_t;
export typedef uint32_t                khronos_uint32_t;
export typedef int64_t                 khronos_int64_t;
export typedef uint64_t                khronos_uint64_t;
export constexpr int _KHRONOS_SUPPORT_INT64 = 1;
export constexpr int _KHRONOS_SUPPORT_FLOAT = 1;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1




#elif defined(_WIN32) && !defined(__SCITECH_SNAP__)

    /*
     * Win32
     */
export typedef __int32                 khronos_int32_t;
export typedef unsigned __int32        khronos_uint32_t;
export typedef __int64                 khronos_int64_t;
export typedef unsigned __int64        khronos_uint64_t;
export constexpr int _KHRONOS_SUPPORT_INT64 = 1;
export constexpr int _KHRONOS_SUPPORT_FLOAT = 1;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#elif defined(__sun__) || defined(__digital__)

    /*
     * Sun or Digital
     */
export typedef int                     khronos_int32_t;
export typedef unsigned int            khronos_uint32_t;
#if defined(__arch64__) || defined(_LP64)
export typedef long int                khronos_int64_t;
export typedef unsigned long int       khronos_uint64_t;
#else
export typedef long long int           khronos_int64_t;
export typedef unsigned long long int  khronos_uint64_t;
export constexpr int _KHRONOS_SUPPORT_INT64 = 1;
export constexpr int _KHRONOS_SUPPORT_FLOAT = 1;
#endif /* __arch64__ */
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#elif 0

    /*
     * Hypothetical platform with no float or int64 support
     */
export typedef int                     khronos_int32_t;
export typedef unsigned int            khronos_uint32_t;
export constexpr int _KHRONOS_SUPPORT_INT64 = 0;
export constexpr int _KHRONOS_SUPPORT_FLOAT = 0;
#define KHRONOS_SUPPORT_INT64   0
#define KHRONOS_SUPPORT_FLOAT   0

#else

    /*
     * Generic fallback
     */
#include <stdint.h>
export typedef int32_t                 khronos_int32_t;
export typedef uint32_t                khronos_uint32_t;
export typedef int64_t                 khronos_int64_t;
export typedef uint64_t                khronos_uint64_t;
export constexpr int _KHRONOS_SUPPORT_INT64 = 1;
export constexpr int _KHRONOS_SUPPORT_FLOAT = 1;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#endif







/*
 * Types that are (so far) the same on all platforms
 */
export typedef signed   char          khronos_int8_t;
export typedef unsigned char          khronos_uint8_t;
export typedef signed   short int     khronos_int16_t;
export typedef unsigned short int     khronos_uint16_t;


/*
 * Types that differ between LLP64 and LP64 architectures - in LLP64,
 * pointers are 64 bits, but 'long' is still 32 bits. Win64 appears
 * to be the only LLP64 architecture in current use.
 */
#ifdef KHRONOS_USE_INTPTR_T
export typedef intptr_t               khronos_intptr_t;
export typedef uintptr_t              khronos_uintptr_t;
#elif defined(_WIN64)
export typedef signed   long long int khronos_intptr_t;
export typedef unsigned long long int khronos_uintptr_t;
#else
export typedef signed   long  int     khronos_intptr_t;
export typedef unsigned long  int     khronos_uintptr_t;
#endif

#if defined(_WIN64)
export typedef signed   long long int khronos_ssize_t;
export typedef unsigned long long int khronos_usize_t;
#else
export typedef signed   long  int     khronos_ssize_t;
export typedef unsigned long  int     khronos_usize_t;
#endif


#if KHRONOS_SUPPORT_FLOAT
/*
 * Float type
 */
export typedef          float         khronos_float_t;
#endif





#if KHRONOS_SUPPORT_INT64
/* Time types
 *
 * These types can be used to represent a time interval in nanoseconds or
 * an absolute Unadjusted System Time.  Unadjusted System Time is the number
 * of nanoseconds since some arbitrary system event (e.g. since the last
 * time the system booted).  The Unadjusted System Time is an unsigned
 * 64 bit value that wraps back to 0 every 584 years.  Time intervals
 * may be either signed or unsigned.
 */
export typedef khronos_uint64_t       khronos_utime_nanoseconds_t;
export typedef khronos_int64_t        khronos_stime_nanoseconds_t;
#endif
/*
 * Dummy value used to pad enum types to 32 bits.
 */
#ifdef KHRONOS_MAX_ENUM
export constexpr int _KHRONOS_MAX_ENUM = KHRONOS_MAX_ENUM;
#else
#define KHRONOS_MAX_ENUM 0x7FFFFFFF
export constexpr int _KHRONOS_MAX_ENUM = KHRONOS_MAX_ENUM;

#endif


/*
 * Enumerated boolean type
 *
 * Values other than zero should be considered to be true.  Therefore
 * comparisons should not be made against KHRONOS_TRUE.
 */
export typedef enum {
    KHRONOS_FALSE = 0,
    KHRONOS_TRUE = 1,
    KHRONOS_BOOLEAN_ENUM_FORCE_SIZE = KHRONOS_MAX_ENUM
} khronos_boolean_enum_t;
#pragma endregion // Khrplatform



export {
    typedef unsigned int GLenum;
    typedef unsigned char GLboolean;
    typedef unsigned int GLbitfield;
    typedef void GLvoid;
    typedef khronos_int8_t GLbyte;
    typedef khronos_uint8_t GLubyte;
    typedef khronos_int16_t GLshort;
    typedef khronos_uint16_t GLushort;
    typedef int GLint;
    typedef unsigned int GLuint;
    typedef khronos_int32_t GLclampx;
    typedef int GLsizei;
    typedef khronos_float_t GLfloat;
    typedef khronos_float_t GLclampf;
    typedef double GLdouble;
    typedef double GLclampd;
    typedef void* GLeglClientBufferEXT;
    typedef void* GLeglImageOES;
    typedef char GLchar;
    typedef char GLcharARB;
}

#ifdef __APPLE__
export typedef void* GLhandleARB;
#else
export typedef unsigned int GLhandleARB;
#endif

export{
    typedef khronos_uint16_t GLhalf;
    typedef khronos_uint16_t GLhalfARB;
    typedef khronos_int32_t GLfixed;
    typedef khronos_intptr_t GLintptr;
    typedef khronos_intptr_t GLintptrARB;
    typedef khronos_ssize_t GLsizeiptr;
    typedef khronos_ssize_t GLsizeiptrARB;
    typedef khronos_int64_t GLint64;
    typedef khronos_int64_t GLint64EXT;
    typedef khronos_uint64_t GLuint64;
    typedef khronos_uint64_t GLuint64EXT;
    typedef struct __GLsync* GLsync;
    struct _cl_context;
    struct _cl_event;

}

export{
    /// <summary>
    /// GLDEBUGPROC is a typedef for a pointer to a function that is called by OpenGL to report debugging information, including the source, type, ID, severity, length, message, and user-defined parameters.
    /// </summary>
    typedef void (APIENTRY* GLDEBUGPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
    /// <summary>
    /// GLDEBUGPROCARB is a typedef for a pointer to a function that is called by OpenGL to report debugging information, including the source, type, ID, severity, length, message, and user-defined parameters.
    /// </summary>
    typedef void (APIENTRY* GLDEBUGPROCARB)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
    /// <summary>
    /// GLDEBUGPROCKHR is a typedef for a pointer to a function that is called by OpenGL to report debugging information, including the source, type, ID, severity, length, message, and user-defined parameters.
    /// </summary>
    typedef void (APIENTRY* GLDEBUGPROCKHR)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
    /// <summary>
    /// GLDEBUGPROCAMD is a typedef for a pointer to a function that is called by OpenGL to report debugging information, including the source, type, ID, severity, length, message, and user-defined parameters.
    /// </summary>
    typedef void (APIENTRY* GLDEBUGPROCAMD)(GLuint id, GLenum category, GLenum severity, GLsizei length, const GLchar* message, void* userParam);
}


export{
    typedef unsigned short GLhalfNV;
    typedef GLintptr GLvdpauSurfaceNV;
    /// <summary>
    /// GL
    /// </summary>
    typedef void (APIENTRY* GLVULKANPROCNV)(void);
}



#pragma region CONSTEXPR
#pragma region BUFFER_BIT
#define GL_DEPTH_BUFFER_BIT 0x00000100
#define GL_STENCIL_BUFFER_BIT 0x00000400
#define GL_COLOR_BUFFER_BIT 0x00004000
export{
    constexpr int _GL_DEPTH_BUFFER_BIT = 0x00000100;
    constexpr int _GL_STENCIL_BUFFER_BIT = 0x00000400;
    constexpr int _GL_COLOR_BUFFER_BIT = 0x00004000;
}
consteval void Check_Buffer_Bit() {
    static_assert(GL_DEPTH_BUFFER_BIT == _GL_DEPTH_BUFFER_BIT, "GL_DEPTH_BUFFER_BIT is not equal to _GL_DEPTH_BUFFER_BIT");
    static_assert(GL_STENCIL_BUFFER_BIT == _GL_STENCIL_BUFFER_BIT, "GL_STENCIL_BUFFER_BIT is not equal to _GL_STENCIL_BUFFER_BIT");
    static_assert(GL_COLOR_BUFFER_BIT == _GL_COLOR_BUFFER_BIT, "GL_COLOR_BUFFER_BIT is not equal to _GL_COLOR_BUFFER_BIT");
}
#pragma endregion


#pragma region BOOLEAN
#define GL_FALSE 0
#define GL_TRUE 1
export{
    constexpr int _GL_FALSE = 0;
    constexpr int _GL_TRUE = 1;
}
consteval void Check_Boolean() {
    static_assert(GL_FALSE == _GL_FALSE, "GL_FALSE is not equal to _GL_FALSE");
    static_assert(GL_TRUE == _GL_TRUE, "GL_TRUE is not equal to _GL_TRUE");
}
#pragma endregion


#pragma region point
#define GL_POINTS 0x0000

export{
    constexpr int _GL_POINTS = 0x0000;
}
consteval void Check_Point() {
    static_assert(GL_POINTS == _GL_POINTS, "GL_POINTS is not equal to _GL_POINTS");
}
#pragma endregion

#pragma region LINE
#define GL_LINES 0x0001
#define GL_LINE_LOOP 0x0002
#define GL_LINE_STRIP 0x0003
export{
    constexpr int _GL_LINES = 0x0001;
    constexpr int _GL_LINE_LOOP = 0x0002;
    constexpr int _GL_LINE_STRIP = 0x0003;
}
consteval void Check_Line() {
    static_assert(GL_LINES == _GL_LINES, "GL_LINES is not equal to _GL_LINES");
    static_assert(GL_LINE_LOOP == _GL_LINE_LOOP, "GL_LINE_LOOP is not equal to _GL_LINE_LOOP");
    static_assert(GL_LINE_STRIP == _GL_LINE_STRIP, "GL_LINE_STRIP is not equal to _GL_LINE_STRIP");
}
#pragma endregion

#pragma region TRIANGLES
#define GL_TRIANGLES 0x0004
#define GL_TRIANGLE_STRIP 0x0005
#define GL_TRIANGLE_FAN 0x0006
export{
    constexpr int _GL_TRIANGLES = 0x0004;
    constexpr int _GL_TRIANGLE_STRIP = 0x0005;
    constexpr int _GL_TRIANGLE_FAN = 0x0006;
}
consteval void Check_Triangles() {
    static_assert(GL_TRIANGLES == _GL_TRIANGLES, "GL_TRIANGLES is not equal to _GL_TRIANGLES");
    static_assert(GL_TRIANGLE_STRIP == _GL_TRIANGLE_STRIP, "GL_TRIANGLE_STRIP is not equal to _GL_TRIANGLE_STRIP");
    static_assert(GL_TRIANGLE_FAN == _GL_TRIANGLE_FAN, "GL_TRIANGLE_FAN is not equal to _GL_TRIANGLE_FAN");
}
#pragma endregion


#pragma region NEVER
#define GL_NEVER 0x0200

export{
    constexpr int _GL_NEVER = 0x0200;
}
consteval void Check_Never() {
    static_assert(GL_NEVER == _GL_NEVER, "GL_NEVER is not equal to _GL_NEVER");
}
#pragma endregion

#pragma region BOOLOPERATORS
#define GL_LESS 0x0201
#define GL_EQUAL 0x0202
#define GL_LEQUAL 0x0203
#define GL_GREATER 0x0204
#define GL_NOTEQUAL 0x0205
#define GL_GEQUAL 0x0206
#define GL_ALWAYS 0x0207

export{
    constexpr int _GL_LESS = 0x0201;
    constexpr int _GL_EQUAL = 0x0202;
    constexpr int _GL_LEQUAL = 0x0203;
    constexpr int _GL_GREATER = 0x0204;
    constexpr int _GL_NOTEQUAL = 0x0205;
    constexpr int _GL_GEQUAL = 0x0206;
    constexpr int _GL_ALWAYS = 0x0207;
}
consteval void Check_BoolOperators() {
    static_assert(GL_LESS == _GL_LESS, "GL_LESS is not equal to _GL_LESS");
    static_assert(GL_EQUAL == _GL_EQUAL, "GL_EQUAL is not equal to _GL_EQUAL");
    static_assert(GL_LEQUAL == _GL_LEQUAL, "GL_LEQUAL is not equal to _GL_LEQUAL");
    static_assert(GL_GREATER == _GL_GREATER, "GL_GREATER is not equal to _GL_GREATER");
    static_assert(GL_NOTEQUAL == _GL_NOTEQUAL, "GL_NOTEQUAL is not equal to _GL_NOTEQUAL");
    static_assert(GL_GEQUAL == _GL_GEQUAL, "GL_GEQUAL is not equal to _GL_GEQUAL");
    static_assert(GL_ALWAYS == _GL_ALWAYS, "GL_ALWAYS is not equal to _GL_ALWAYS");
}
#pragma endregion


#pragma region ZERO_ONE
#define GL_ZERO 0
#define GL_ONE 1
export{
    constexpr int _GL_ZERO = 0;
    constexpr int _GL_ONE = 1;
}
consteval void Check_Zero_One() {
    static_assert(GL_ZERO == _GL_ZERO, "GL_ZERO is not equal to _GL_ZERO");
    static_assert(GL_ONE == _GL_ONE, "GL_ONE is not equal to _GL_ONE");
}

#pragma endregion

#pragma region SRC_COLOR
#define GL_SRC_COLOR 0x0300
#define GL_ONE_MINUS_SRC_COLOR 0x0301
#define GL_SRC_ALPHA 0x0302
#define GL_ONE_MINUS_SRC_ALPHA 0x0303
#define GL_DST_ALPHA 0x0304
#define GL_ONE_MINUS_DST_ALPHA 0x0305
#define GL_DST_COLOR 0x0306
#define GL_ONE_MINUS_DST_COLOR 0x0307
#define GL_SRC_ALPHA_SATURATE 0x0308
export{
    constexpr int _GL_SRC_COLOR = 0x0300;
    constexpr int _GL_ONE_MINUS_SRC_COLOR = 0x0301;
    constexpr int _GL_SRC_ALPHA = 0x0302;
    constexpr int _GL_ONE_MINUS_SRC_ALPHA = 0x0303;
    constexpr int _GL_DST_ALPHA = 0x0304;
    constexpr int _GL_ONE_MINUS_DST_ALPHA = 0x0305;
    constexpr int _GL_DST_COLOR = 0x0306;
    constexpr int _GL_ONE_MINUS_DST_COLOR = 0x0307;
    constexpr int _GL_SRC_ALPHA_SATURATE = 0x0308;
}
consteval void Check_Src_Color() {
    static_assert(GL_SRC_COLOR == _GL_SRC_COLOR, "GL_SRC_COLOR is not equal to _GL_SRC_COLOR");
    static_assert(GL_ONE_MINUS_SRC_COLOR == _GL_ONE_MINUS_SRC_COLOR, "GL_ONE_MINUS_SRC_COLOR is not equal to _GL_ONE_MINUS_SRC_COLOR");
    static_assert(GL_SRC_ALPHA == _GL_SRC_ALPHA, "GL_SRC_ALPHA is not equal to _GL_SRC_ALPHA");
    static_assert(GL_ONE_MINUS_SRC_ALPHA == _GL_ONE_MINUS_SRC_ALPHA, "GL_ONE_MINUS_SRC_ALPHA is not equal to _GL_ONE_MINUS_SRC_ALPHA");
    static_assert(GL_DST_ALPHA == _GL_DST_ALPHA, "GL_DST_ALPHA is not equal to _GL_DST_ALPHA");
    static_assert(GL_ONE_MINUS_DST_ALPHA == _GL_ONE_MINUS_DST_ALPHA, "GL_ONE_MINUS_DST_ALPHA is not equal to _GL_ONE_MINUS_DST_ALPHA");
    static_assert(GL_DST_COLOR == _GL_DST_COLOR, "GL_DST_COLOR is not equal to _GL_DST_COLOR");
    static_assert(GL_ONE_MINUS_DST_COLOR == _GL_ONE_MINUS_DST_COLOR, "GL_ONE_MINUS_DST_COLOR is not equal to _GL_ONE_MINUS_DST_COLOR");
    static_assert(GL_SRC_ALPHA_SATURATE == _GL_SRC_ALPHA_SATURATE, "GL_SRC_ALPHA_SATURATE is not equal to _GL_SRC_ALPHA_SATURATE");
}
#pragma endregion


#pragma region NONE
#define GL_NONE 0

export{
    constexpr int _GL_NONE = 0;
}
consteval void Check_None() {
    static_assert(GL_NONE == _GL_NONE, "GL_NONE is not equal to _GL_NONE");
}
#pragma endregion

#pragma region DIRECTIONS
#define GL_FRONT_LEFT 0x0400
#define GL_FRONT_RIGHT 0x0401
#define GL_BACK_LEFT 0x0402
#define GL_BACK_RIGHT 0x0403
#define GL_FRONT 0x0404
#define GL_BACK 0x0405
#define GL_LEFT 0x0406
#define GL_RIGHT 0x0407
#define GL_FRONT_AND_BACK 0x0408
    export constexpr int _GL_FRONT_LEFT = 0x0400;
    export constexpr int _GL_FRONT_RIGHT = 0x0401;
    export constexpr int _GL_BACK_LEFT = 0x0402;
    export constexpr int _GL_BACK_RIGHT = 0x0403;
    export constexpr int _GL_FRONT = 0x0404;
    export constexpr int _GL_BACK = 0x0405;
    export constexpr int _GL_LEFT = 0x0406;
    export constexpr int _GL_RIGHT = 0x0407;
    export constexpr int _GL_FRONT_AND_BACK = 0x0408;
consteval void Check_Directions() {
    static_assert(GL_FRONT_LEFT == _GL_FRONT_LEFT, "GL_FRONT_LEFT is not equal to _GL_FRONT_LEFT");
    static_assert(GL_FRONT_RIGHT == _GL_FRONT_RIGHT, "GL_FRONT_RIGHT is not equal to _GL_FRONT_RIGHT");
    static_assert(GL_BACK_LEFT == _GL_BACK_LEFT, "GL_BACK_LEFT is not equal to _GL_BACK_LEFT");
    static_assert(GL_BACK_RIGHT == _GL_BACK_RIGHT, "GL_BACK_RIGHT is not equal to _GL_BACK_RIGHT");
    static_assert(GL_FRONT == _GL_FRONT, "GL_FRONT is not equal to _GL_FRONT");
    static_assert(GL_BACK == _GL_BACK, "GL_BACK is not equal to _GL_BACK");
    static_assert(GL_LEFT == _GL_LEFT, "GL_LEFT is not equal to _GL_LEFT");
    static_assert(GL_RIGHT == _GL_RIGHT, "GL_RIGHT is not equal to _GL_RIGHT");
    static_assert(GL_FRONT_AND_BACK == _GL_FRONT_AND_BACK, "GL_FRONT_AND_BACK is not equal to _GL_FRONT_AND_BACK");
}
#pragma endregion


#pragma region NO_ERROR
#define GL_NO_ERROR 0

   export  constexpr int _GL_NO_ERROR = 0;
consteval void Check_No_Error() {
    static_assert(GL_NO_ERROR == _GL_NO_ERROR, "GL_NO_ERROR is not equal to _GL_NO_ERROR");
}
#pragma endregion

#pragma region SOME_ERRORS
#define GL_INVALID_ENUM 0x0500
#define GL_INVALID_VALUE 0x0501
#define GL_INVALID_OPERATION 0x0502
#define GL_OUT_OF_MEMORY 0x0505
export{
    constexpr int _GL_INVALID_ENUM = 0x0500;
    constexpr int _GL_INVALID_VALUE = 0x0501;
    constexpr int _GL_INVALID_OPERATION = 0x0502;
    constexpr int _GL_OUT_OF_MEMORY = 0x0505;
}
consteval void Check_Some_Errors() {
    static_assert(GL_INVALID_ENUM == _GL_INVALID_ENUM, "GL_INVALID_ENUM is not equal to _GL_INVALID_ENUM");
    static_assert(GL_INVALID_VALUE == _GL_INVALID_VALUE, "GL_INVALID_VALUE is not equal to _GL_INVALID_VALUE");
    static_assert(GL_INVALID_OPERATION == _GL_INVALID_OPERATION, "GL_INVALID_OPERATION is not equal to _GL_INVALID_OPERATION");
    static_assert(GL_OUT_OF_MEMORY == _GL_OUT_OF_MEMORY, "GL_OUT_OF_MEMORY is not equal to _GL_OUT_OF_MEMORY");
}
#pragma endregion

#pragma region CW_CCW
#define GL_CW 0x0900
#define GL_CCW 0x0901
export{
    constexpr int _GL_CW = 0x0900;
    constexpr int _GL_CCW = 0x0901;
}
consteval void Check_CW_CCW() {
    static_assert(GL_CW == _GL_CW, "GL_CW is not equal to _GL_CW");
    static_assert(GL_CCW == _GL_CCW, "GL_CCW is not equal to _GL_CCW");
}
#pragma endregion


#pragma region POINT_SIZE
#define GL_POINT_SIZE 0x0B11
#define GL_POINT_SIZE_RANGE 0x0B12
#define GL_POINT_SIZE_GRANULARITY 0x0B13
export{
    constexpr int _GL_POINT_SIZE = 0x0B11;
    constexpr int _GL_POINT_SIZE_RANGE = 0x0B12;
    constexpr int _GL_POINT_SIZE_GRANULARITY = 0x0B13;
}
consteval void Check_Point_Size() {
    static_assert(GL_POINT_SIZE == _GL_POINT_SIZE, "GL_POINT_SIZE is not equal to _GL_POINT_SIZE");
    static_assert(GL_POINT_SIZE_RANGE == _GL_POINT_SIZE_RANGE, "GL_POINT_SIZE_RANGE is not equal to _GL_POINT_SIZE_RANGE");
    static_assert(GL_POINT_SIZE_GRANULARITY == _GL_POINT_SIZE_GRANULARITY, "GL_POINT_SIZE_GRANULARITY is not equal to _GL_POINT_SIZE_GRANULARITY");
}

#pragma endregion



#pragma region LINE
#define GL_LINE_SMOOTH 0x0B20
#define GL_LINE_WIDTH 0x0B21
#define GL_LINE_WIDTH_RANGE 0x0B22
#define GL_LINE_WIDTH_GRANULARITY 0x0B23

export{
    constexpr int _GL_LINE_SMOOTH = 0x0B20;
    constexpr int _GL_LINE_WIDTH = 0x0B21;
    constexpr int _GL_LINE_WIDTH_RANGE = 0x0B22;
    constexpr int _GL_LINE_WIDTH_GRANULARITY = 0x0B23;
}
consteval void Check_LINE_() {
    static_assert(GL_LINE_SMOOTH == _GL_LINE_SMOOTH, "GL_LINE_SMOOTH is not equal to _GL_LINE_SMOOTH");
    static_assert(GL_LINE_WIDTH == _GL_LINE_WIDTH, "GL_LINE_WIDTH is not equal to _GL_LINE_WIDTH");
    static_assert(GL_LINE_WIDTH_RANGE == _GL_LINE_WIDTH_RANGE, "GL_LINE_WIDTH_RANGE is not equal to _GL_LINE_WIDTH_RANGE");
    static_assert(GL_LINE_WIDTH_GRANULARITY == _GL_LINE_WIDTH_GRANULARITY, "GL_LINE_WIDTH_GRANULARITY is not equal to _GL_LINE_WIDTH_GRANULARITY");
}
#pragma endregion


#pragma region POLYGONE_THINGS
#define GL_POLYGON_MODE 0x0B40
#define GL_POLYGON_SMOOTH 0x0B41
export{
    constexpr int _GL_POLYGON_MODE = 0x0B40;
    constexpr int _GL_POLYGON_SMOOTH = 0x0B41;
}
consteval void Check_Polygon_Things() {
    static_assert(GL_POLYGON_MODE == _GL_POLYGON_MODE, "GL_POLYGON_MODE is not equal to _GL_POLYGON_MODE");
    static_assert(GL_POLYGON_SMOOTH == _GL_POLYGON_SMOOTH, "GL_POLYGON_SMOOTH is not equal to _GL_POLYGON_SMOOTH");
}
#pragma endregion


#pragma region CULL_FACE
#define GL_CULL_FACE 0x0B44
#define GL_CULL_FACE_MODE 0x0B45
export{
    constexpr int _GL_CULL_FACE = 0x0B44;
    constexpr int _GL_CULL_FACE_MODE = 0x0B45;
}
consteval void Check_Cull_Face() {
    static_assert(GL_CULL_FACE == _GL_CULL_FACE, "GL_CULL_FACE is not equal to _GL_CULL_FACE");
    static_assert(GL_CULL_FACE_MODE == _GL_CULL_FACE_MODE, "GL_CULL_FACE_MODE is not equal to _GL_CULL_FACE_MODE");
}
#pragma endregion

#pragma region FRONT_FACE
#define GL_FRONT_FACE 0x0B46

export{
    constexpr int _GL_FRONT_FACE = 0x0B46;
}
consteval void Check_Front_Face() {
    static_assert(GL_FRONT_FACE == _GL_FRONT_FACE, "GL_FRONT_FACE is not equal to _GL_FRONT_FACE");
}
#pragma endregion

#pragma region DEPTH

#define GL_DEPTH_RANGE 0x0B70
#define GL_DEPTH_TEST 0x0B71
#define GL_DEPTH_WRITEMASK 0x0B72
#define GL_DEPTH_CLEAR_VALUE 0x0B73
#define GL_DEPTH_FUNC 0x0B74
export{
    constexpr int _GL_DEPTH_RANGE = 0x0B70;
    constexpr int _GL_DEPTH_TEST = 0x0B71;
    constexpr int _GL_DEPTH_WRITEMASK = 0x0B72;
    constexpr int _GL_DEPTH_CLEAR_VALUE = 0x0B73;
    constexpr int _GL_DEPTH_FUNC = 0x0B74;
}
consteval void Check_Depth() {
    static_assert(GL_DEPTH_RANGE == _GL_DEPTH_RANGE, "GL_DEPTH_RANGE is not equal to _GL_DEPTH_RANGE");
    static_assert(GL_DEPTH_TEST == _GL_DEPTH_TEST, "GL_DEPTH_TEST is not equal to _GL_DEPTH_TEST");
    static_assert(GL_DEPTH_WRITEMASK == _GL_DEPTH_WRITEMASK, "GL_DEPTH_WRITEMASK is not equal to _GL_DEPTH_WRITEMASK");
    static_assert(GL_DEPTH_CLEAR_VALUE == _GL_DEPTH_CLEAR_VALUE, "GL_DEPTH_CLEAR_VALUE is not equal to _GL_DEPTH_CLEAR_VALUE");
    static_assert(GL_DEPTH_FUNC == _GL_DEPTH_FUNC, "GL_DEPTH_FUNC is not equal to _GL_DEPTH_FUNC");
}
#pragma endregion



#pragma region STENCIL
#define GL_STENCIL_TEST 0x0B90
#define GL_STENCIL_CLEAR_VALUE 0x0B91
#define GL_STENCIL_FUNC 0x0B92
#define GL_STENCIL_VALUE_MASK 0x0B93
#define GL_STENCIL_FAIL 0x0B94
#define GL_STENCIL_PASS_DEPTH_FAIL 0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS 0x0B96
#define GL_STENCIL_REF 0x0B97
#define GL_STENCIL_WRITEMASK 0x0B98
export{
    constexpr int _GL_STENCIL_TEST = 0x0B90;
    constexpr int _GL_STENCIL_CLEAR_VALUE = 0x0B91;
    constexpr int _GL_STENCIL_FUNC = 0x0B92;
    constexpr int _GL_STENCIL_VALUE_MASK = 0x0B93;
    constexpr int _GL_STENCIL_FAIL = 0x0B94;
    constexpr int _GL_STENCIL_PASS_DEPTH_FAIL = 0x0B95;
    constexpr int _GL_STENCIL_PASS_DEPTH_PASS = 0x0B96;
    constexpr int _GL_STENCIL_REF = 0x0B97;
    constexpr int _GL_STENCIL_WRITEMASK = 0x0B98;
}
consteval void Check_Stencil() {
    static_assert(GL_STENCIL_TEST == _GL_STENCIL_TEST, "GL_STENCIL_TEST is not equal to _GL_STENCIL_TEST");
    static_assert(GL_STENCIL_CLEAR_VALUE == _GL_STENCIL_CLEAR_VALUE, "GL_STENCIL_CLEAR_VALUE is not equal to _GL_STENCIL_CLEAR_VALUE");
    static_assert(GL_STENCIL_FUNC == _GL_STENCIL_FUNC, "GL_STENCIL_FUNC is not equal to _GL_STENCIL_FUNC");
    static_assert(GL_STENCIL_VALUE_MASK == _GL_STENCIL_VALUE_MASK, "GL_STENCIL_VALUE_MASK is not equal to _GL_STENCIL_VALUE_MASK");
    static_assert(GL_STENCIL_FAIL == _GL_STENCIL_FAIL, "GL_STENCIL_FAIL is not equal to _GL_STENCIL_FAIL");
    static_assert(GL_STENCIL_PASS_DEPTH_FAIL == _GL_STENCIL_PASS_DEPTH_FAIL, "GL_STENCIL_PASS_DEPTH_FAIL is not equal to _GL_STENCIL_PASS_DEPTH_FAIL");
    static_assert(GL_STENCIL_PASS_DEPTH_PASS == _GL_STENCIL_PASS_DEPTH_PASS, "GL_STENCIL_PASS_DEPTH_PASS is not equal to _GL_STENCIL_PASS_DEPTH_PASS");
    static_assert(GL_STENCIL_REF == _GL_STENCIL_REF, "GL_STENCIL_REF is not equal to _GL_STENCIL_REF");
    static_assert(GL_STENCIL_WRITEMASK == _GL_STENCIL_WRITEMASK, "GL_STENCIL_WRITEMASK is not equal to _GL_STENCIL_WRITEMASK");
}
#pragma endregion


#pragma region VIEWPORT
#define GL_VIEWPORT 0x0BA2

export{
    constexpr int _GL_VIEWPORT = 0x0BA2;
}
consteval void Check_Viewport() {
    static_assert(GL_VIEWPORT == _GL_VIEWPORT, "GL_VIEWPORT is not equal to _GL_VIEWPORT");
}
#pragma endregion

#pragma region DITHER
#define GL_DITHER 0x0BD0
export{
    constexpr int _GL_DITHER = 0x0BD0;
}
consteval void Check_Dither() {
    static_assert(GL_DITHER == _GL_DITHER, "GL_DITHER is not equal to _GL_DITHER");
}
#pragma endregion

#pragma region BLEND
#define GL_BLEND_DST 0x0BE0
#define GL_BLEND_SRC 0x0BE1
#define GL_BLEND 0x0BE2
export{
    constexpr int _GL_BLEND_DST = 0x0BE0;
    constexpr int _GL_BLEND_SRC = 0x0BE1;
    constexpr int _GL_BLEND = 0x0BE2;
}

consteval void Check_Blend() {
    static_assert(GL_BLEND_DST == _GL_BLEND_DST, "GL_BLEND_DST is not equal to _GL_BLEND_DST");
    static_assert(GL_BLEND_SRC == _GL_BLEND_SRC, "GL_BLEND_SRC is not equal to _GL_BLEND_SRC");
    static_assert(GL_BLEND == _GL_BLEND, "GL_BLEND is not equal to _GL_BLEND");
}
#pragma endregion

#pragma region LOGIC_OP
#define GL_LOGIC_OP_MODE 0x0BF0

export{
    constexpr int _GL_LOGIC_OP_MODE = 0x0BF0;
}
consteval void Check_Logic_Op() {
    static_assert(GL_LOGIC_OP_MODE == _GL_LOGIC_OP_MODE, "GL_LOGIC_OP_MODE is not equal to _GL_LOGIC_OP_MODE");
}
#pragma endregion

#pragma region DRAW_BUFFER
#define GL_DRAW_BUFFER 0x0C01

export{
    constexpr int _GL_DRAW_BUFFER = 0x0C01;
}
consteval void Check_Draw_Buffer() {
    static_assert(GL_DRAW_BUFFER == _GL_DRAW_BUFFER, "GL_DRAW_BUFFER is not equal to _GL_DRAW_BUFFER");
}
#pragma endregion   


#pragma region READ_BUFFER
#define GL_READ_BUFFER 0x0C02

export{
    constexpr int _GL_READ_BUFFER = 0x0C02;
}
consteval void Check_Read_Buffer() {
    static_assert(GL_READ_BUFFER == _GL_READ_BUFFER, "GL_READ_BUFFER is not equal to _GL_READ_BUFFER");
}
#pragma endregion

#pragma region SCISSOR
#define GL_SCISSOR_BOX 0x0C10
#define GL_SCISSOR_TEST 0x0C11

export{
    constexpr int _GL_SCISSOR_BOX = 0x0C10;
    constexpr int _GL_SCISSOR_TEST = 0x0C11;
}
consteval void Check_Scissor() {
    static_assert(GL_SCISSOR_BOX == _GL_SCISSOR_BOX, "GL_SCISSOR_BOX is not equal to _GL_SCISSOR_BOX");
    static_assert(GL_SCISSOR_TEST == _GL_SCISSOR_TEST, "GL_SCISSOR_TEST is not equal to _GL_SCISSOR_TEST");
}
#pragma endregion

#pragma region COLOUT_STUFF_
#define GL_COLOR_CLEAR_VALUE 0x0C22
#define GL_COLOR_WRITEMASK 0x0C23
export{
    constexpr int _GL_COLOR_CLEAR_VALUE = 0x0C22;
    constexpr int _GL_COLOR_WRITEMASK = 0x0C23;
}
consteval void Check_Color_Stuff() {
    static_assert(GL_COLOR_CLEAR_VALUE == _GL_COLOR_CLEAR_VALUE, "GL_COLOR_CLEAR_VALUE is not equal to _GL_COLOR_CLEAR_VALUE");
    static_assert(GL_COLOR_WRITEMASK == _GL_COLOR_WRITEMASK, "GL_COLOR_WRITEMASK is not equal to _GL_COLOR_WRITEMASK");
}
#pragma endregion

#pragma region RANDOMSTUFF1
#define GL_DOUBLEBUFFER 0x0C32
#define GL_STEREO 0x0C33
#define GL_LINE_SMOOTH_HINT 0x0C52
#define GL_POLYGON_SMOOTH_HINT 0x0C53
export{
    constexpr int _GL_DOUBLEBUFFER = 0x0C32;
    constexpr int _GL_STEREO = 0x0C33;
    constexpr int _GL_LINE_SMOOTH_HINT = 0x0C52;
    constexpr int _GL_POLYGON_SMOOTH_HINT = 0x0C53;
}
consteval void Check_RandomStuff1() {
    static_assert(GL_DOUBLEBUFFER == _GL_DOUBLEBUFFER, "GL_DOUBLEBUFFER is not equal to _GL_DOUBLEBUFFER");
    static_assert(GL_STEREO == _GL_STEREO, "GL_STEREO is not equal to _GL_STEREO");
    static_assert(GL_LINE_SMOOTH_HINT == _GL_LINE_SMOOTH_HINT, "GL_LINE_SMOOTH_HINT is not equal to _GL_LINE_SMOOTH_HINT");
    static_assert(GL_POLYGON_SMOOTH_HINT == _GL_POLYGON_SMOOTH_HINT, "GL_POLYGON_SMOOTH_HINT is not equal to _GL_POLYGON_SMOOTH_HINT");
}
#pragma endregion



#pragma region UNPACK1
#define GL_UNPACK_SWAP_BYTES 0x0CF0
#define GL_UNPACK_LSB_FIRST 0x0CF1
#define GL_UNPACK_ROW_LENGTH 0x0CF2
#define GL_UNPACK_SKIP_ROWS 0x0CF3
#define GL_UNPACK_SKIP_PIXELS 0x0CF4
#define GL_UNPACK_ALIGNMENT 0x0CF5
export{
    constexpr int _GL_UNPACK_SWAP_BYTES = 0x0CF0;
    constexpr int _GL_UNPACK_LSB_FIRST = 0x0CF1;
    constexpr int _GL_UNPACK_ROW_LENGTH = 0x0CF2;
    constexpr int _GL_UNPACK_SKIP_ROWS = 0x0CF3;
    constexpr int _GL_UNPACK_SKIP_PIXELS = 0x0CF4;
    constexpr int _GL_UNPACK_ALIGNMENT = 0x0CF5;
}
consteval void Check_Unpack1() {
    static_assert(GL_UNPACK_SWAP_BYTES == _GL_UNPACK_SWAP_BYTES, "GL_UNPACK_SWAP_BYTES is not equal to _GL_UNPACK_SWAP_BYTES");
    static_assert(GL_UNPACK_LSB_FIRST == _GL_UNPACK_LSB_FIRST, "GL_UNPACK_LSB_FIRST is not equal to _GL_UNPACK_LSB_FIRST");
    static_assert(GL_UNPACK_ROW_LENGTH == _GL_UNPACK_ROW_LENGTH, "GL_UNPACK_ROW_LENGTH is not equal to _GL_UNPACK_ROW_LENGTH");
    static_assert(GL_UNPACK_SKIP_ROWS == _GL_UNPACK_SKIP_ROWS, "GL_UNPACK_SKIP_ROWS is not equal to _GL_UNPACK_SKIP_ROWS");
    static_assert(GL_UNPACK_SKIP_PIXELS == _GL_UNPACK_SKIP_PIXELS, "GL_UNPACK_SKIP_PIXELS is not equal to _GL_UNPACK_SKIP_PIXELS");
    static_assert(GL_UNPACK_ALIGNMENT == _GL_UNPACK_ALIGNMENT, "GL_UNPACK_ALIGNMENT is not equal to _GL_UNPACK_ALIGNMENT");
}
#pragma endregion


#pragma region PACK1

#define GL_PACK_SWAP_BYTES 0x0D00
#define GL_PACK_LSB_FIRST 0x0D01
#define GL_PACK_ROW_LENGTH 0x0D02
#define GL_PACK_SKIP_ROWS 0x0D03
#define GL_PACK_SKIP_PIXELS 0x0D04
#define GL_PACK_ALIGNMENT 0x0D05

export{
    constexpr int _GL_PACK_SWAP_BYTES = 0x0D00;
    constexpr int _GL_PACK_LSB_FIRST = 0x0D01;
    constexpr int _GL_PACK_ROW_LENGTH = 0x0D02;
    constexpr int _GL_PACK_SKIP_ROWS = 0x0D03;
    constexpr int _GL_PACK_SKIP_PIXELS = 0x0D04;
    constexpr int _GL_PACK_ALIGNMENT = 0x0D05;
}
consteval void Check_Pack1() {
    static_assert(GL_PACK_SWAP_BYTES == _GL_PACK_SWAP_BYTES, "GL_PACK_SWAP_BYTES is not equal to _GL_PACK_SWAP_BYTES");
    static_assert(GL_PACK_LSB_FIRST == _GL_PACK_LSB_FIRST, "GL_PACK_LSB_FIRST is not equal to _GL_PACK_LSB_FIRST");
    static_assert(GL_PACK_ROW_LENGTH == _GL_PACK_ROW_LENGTH, "GL_PACK_ROW_LENGTH is not equal to _GL_PACK_ROW_LENGTH");
    static_assert(GL_PACK_SKIP_ROWS == _GL_PACK_SKIP_ROWS, "GL_PACK_SKIP_ROWS is not equal to _GL_PACK_SKIP_ROWS");
    static_assert(GL_PACK_SKIP_PIXELS == _GL_PACK_SKIP_PIXELS, "GL_PACK_SKIP_PIXELS is not equal to _GL_PACK_SKIP_PIXELS");
    static_assert(GL_PACK_ALIGNMENT == _GL_PACK_ALIGNMENT, "GL_PACK_ALIGNMENT is not equal to _GL_PACK_ALIGNMENT");
}
#pragma endregion


#pragma region MAX_STUFF1
#define GL_MAX_TEXTURE_SIZE 0x0D33
#define GL_MAX_VIEWPORT_DIMS 0x0D3A
export{
    constexpr int _GL_MAX_TEXTURE_SIZE = 0x0D33;
    constexpr int _GL_MAX_VIEWPORT_DIMS = 0x0D3A;
}
consteval void Check_Max_Stuff1() {
    static_assert(GL_MAX_TEXTURE_SIZE == _GL_MAX_TEXTURE_SIZE, "GL_MAX_TEXTURE_SIZE is not equal to _GL_MAX_TEXTURE_SIZE");
    static_assert(GL_MAX_VIEWPORT_DIMS == _GL_MAX_VIEWPORT_DIMS, "GL_MAX_VIEWPORT_DIMS is not equal to _GL_MAX_VIEWPORT_DIMS");
}
#pragma endregion


#pragma region SUBPIXEL_BITS
#define GL_SUBPIXEL_BITS 0x0D50

export{
    constexpr int _GL_SUBPIXEL_BITS = 0x0D50;
}
consteval void Check_Subpixel_Bits() {
    static_assert(GL_SUBPIXEL_BITS == _GL_SUBPIXEL_BITS, "GL_SUBPIXEL_BITS is not equal to _GL_SUBPIXEL_BITS");
}
#pragma endregion


#pragma region TEXTURE1
#define GL_TEXTURE_1D 0x0DE0
#define GL_TEXTURE_2D 0x0DE1
#define GL_TEXTURE_WIDTH 0x1000
#define GL_TEXTURE_HEIGHT 0x1001
#define GL_TEXTURE_BORDER_COLOR 0x1004

export{
    constexpr int _GL_TEXTURE_1D = 0x0DE0;
    constexpr int _GL_TEXTURE_2D = 0x0DE1;
    constexpr int _GL_TEXTURE_WIDTH = 0x1000;
    constexpr int _GL_TEXTURE_HEIGHT = 0x1001;
    constexpr int _GL_TEXTURE_BORDER_COLOR = 0x1004;
}
consteval void Check_Texture1() {
    static_assert(GL_TEXTURE_1D == _GL_TEXTURE_1D, "GL_TEXTURE_1D is not equal to _GL_TEXTURE_1D");
    static_assert(GL_TEXTURE_2D == _GL_TEXTURE_2D, "GL_TEXTURE_2D is not equal to _GL_TEXTURE_2D");
    static_assert(GL_TEXTURE_WIDTH == _GL_TEXTURE_WIDTH, "GL_TEXTURE_WIDTH is not equal to _GL_TEXTURE_WIDTH");
    static_assert(GL_TEXTURE_HEIGHT == _GL_TEXTURE_HEIGHT, "GL_TEXTURE_HEIGHT is not equal to _GL_TEXTURE_HEIGHT");
    static_assert(GL_TEXTURE_BORDER_COLOR == _GL_TEXTURE_BORDER_COLOR, "GL_TEXTURE_BORDER_COLOR is not equal to _GL_TEXTURE_BORDER_COLOR");
}
#pragma endregion


#pragma region DONT_CARE
#define GL_DONT_CARE 0x1100

export{
    constexpr int _GL_DONT_CARE = 0x1100;
}
consteval void Check_Dont_Care() {
    static_assert(GL_DONT_CARE == _GL_DONT_CARE, "GL_DONT_CARE is not equal to _GL_DONT_CARE");
}
#pragma endregion

#pragma region FASTEST
#define GL_FASTEST 0x1101

export{
    constexpr int _GL_FASTEST = 0x1101;
}
consteval void Check_Fastest() {
    static_assert(GL_FASTEST == _GL_FASTEST, "GL_FASTEST is not equal to _GL_FASTEST");
}
#pragma endregion

#pragma region NICEST
#define GL_NICEST 0x1102

export{
    constexpr int _GL_NICEST = 0x1102;
}
consteval void Check_Nicest() {
    static_assert(GL_NICEST == _GL_NICEST, "GL_NICEST is not equal to _GL_NICEST");
}
#pragma endregion

#pragma region DATATYPES1
#define GL_BYTE 0x1400
#define GL_UNSIGNED_BYTE 0x1401
#define GL_SHORT 0x1402
#define GL_UNSIGNED_SHORT 0x1403
#define GL_INT 0x1404
#define GL_UNSIGNED_INT 0x1405
#define GL_FLOAT 0x1406

export{

    constexpr int _GL_BYTE = 0x1400;
    constexpr int _GL_UNSIGNED_BYTE = 0x1401;
    constexpr int _GL_SHORT = 0x1402;
    constexpr int _GL_UNSIGNED_SHORT = 0x1403;
    constexpr int _GL_INT = 0x1404;
    constexpr int _GL_UNSIGNED_INT = 0x1405;
    constexpr int _GL_FLOAT = 0x1406;
}
consteval void Check_DataTypes1() {
    static_assert(GL_BYTE == _GL_BYTE, "GL_BYTE is not equal to _GL_BYTE");
    static_assert(GL_UNSIGNED_BYTE == _GL_UNSIGNED_BYTE, "GL_UNSIGNED_BYTE is not equal to _GL_UNSIGNED_BYTE");
    static_assert(GL_SHORT == _GL_SHORT, "GL_SHORT is not equal to _GL_SHORT");
    static_assert(GL_UNSIGNED_SHORT == _GL_UNSIGNED_SHORT, "GL_UNSIGNED_SHORT is not equal to _GL_UNSIGNED_SHORT");
    static_assert(GL_INT == _GL_INT, "GL_INT is not equal to _GL_INT");
    static_assert(GL_UNSIGNED_INT == _GL_UNSIGNED_INT, "GL_UNSIGNED_INT is not equal to _GL_UNSIGNED_INT");
    static_assert(GL_FLOAT == _GL_FLOAT, "GL_FLOAT is not equal to _GL_FLOAT");
}
#pragma endregion


#pragma region CLEAR1
#define GL_CLEAR 0x1500

export{
    constexpr int _GL_CLEAR = 0x1500;
}
consteval void Check_Clear1() {
    static_assert(GL_CLEAR == _GL_CLEAR, "GL_CLEAR is not equal to _GL_CLEAR");
}
#pragma endregion

#pragma region LOGIC_OP1
#define GL_AND 0x1501
#define GL_AND_REVERSE 0x1502
#define GL_COPY 0x1503
#define GL_AND_INVERTED 0x1504
#define GL_NOOP 0x1505
#define GL_XOR 0x1506
#define GL_OR 0x1507
#define GL_NOR 0x1508
#define GL_EQUIV 0x1509
#define GL_INVERT 0x150A
#define GL_OR_REVERSE 0x150B
#define GL_COPY_INVERTED 0x150C
#define GL_OR_INVERTED 0x150D
#define GL_NAND 0x150E
export{
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
}
consteval void Check_Logic_Op1() {
    static_assert(GL_AND == _GL_AND, "GL_AND is not equal to _GL_AND");
    static_assert(GL_AND_REVERSE == _GL_AND_REVERSE, "GL_AND_REVERSE is not equal to _GL_AND_REVERSE");
    static_assert(GL_COPY == _GL_COPY, "GL_COPY is not equal to _GL_COPY");
    static_assert(GL_AND_INVERTED == _GL_AND_INVERTED, "GL_AND_INVERTED is not equal to _GL_AND_INVERTED");
    static_assert(GL_NOOP == _GL_NOOP, "GL_NOOP is not equal to _GL_NOOP");
    static_assert(GL_XOR == _GL_XOR, "GL_XOR is not equal to _GL_XOR");
    static_assert(GL_OR == _GL_OR, "GL_OR is not equal to _GL_OR");
    static_assert(GL_NOR == _GL_NOR, "GL_NOR is not equal to _GL_NOR");
    static_assert(GL_EQUIV == _GL_EQUIV, "GL_EQUIV is not equal to _GL_EQUIV");
    static_assert(GL_INVERT == _GL_INVERT, "GL_INVERT is not equal to _GL_INVERT");
    static_assert(GL_OR_REVERSE == _GL_OR_REVERSE, "GL_OR_REVERSE is not equal to _GL_OR_REVERSE");
    static_assert(GL_COPY_INVERTED == _GL_COPY_INVERTED, "GL_COPY_INVERTED is not equal to _GL_COPY_INVERTED");
    static_assert(GL_OR_INVERTED == _GL_OR_INVERTED, "GL_OR_INVERTED is not equal to _GL_OR_INVERTED");
    static_assert(GL_NAND == _GL_NAND, "GL_NAND is not equal to _GL_NAND");
}
#pragma endregion

#pragma region RANOM_STUFF2
#define GL_SET 0x150F
#define GL_TEXTURE 0x1702
#define GL_COLOR 0x1800
#define GL_DEPTH 0x1801

export{
    constexpr int _GL_SET = 0x150F;
    constexpr int _GL_TEXTURE = 0x1702;
    constexpr int _GL_COLOR = 0x1800;
    constexpr int _GL_DEPTH = 0x1801;
}
consteval void Check_Random_Stuff2() {
    static_assert(GL_SET == _GL_SET, "GL_SET is not equal to _GL_SET");
    static_assert(GL_TEXTURE == _GL_TEXTURE, "GL_TEXTURE is not equal to _GL_TEXTURE");
    static_assert(GL_COLOR == _GL_COLOR, "GL_COLOR is not equal to _GL_COLOR");
    static_assert(GL_DEPTH == _GL_DEPTH, "GL_DEPTH is not equal to _GL_DEPTH");
}
#pragma endregion


#pragma region STENCIL1
#define GL_STENCIL 0x1802
#define GL_STENCIL_INDEX 0x1901
export{
    constexpr int _GL_STENCIL = 0x1802;
    constexpr int _GL_STENCIL_INDEX = 0x1901;
}
consteval void Check_Stencil1() {
    static_assert(GL_STENCIL == _GL_STENCIL, "GL_STENCIL is not equal to _GL_STENCIL");
    static_assert(GL_STENCIL_INDEX == _GL_STENCIL_INDEX, "GL_STENCIL_INDEX is not equal to _GL_STENCIL_INDEX");
}
#pragma endregion

#pragma region DEPTH_COMPONENT
#define GL_DEPTH_COMPONENT 0x1902

export{
    constexpr int _GL_DEPTH_COMPONENT = 0x1902;
}
consteval void Check_Depth_Component() {
    static_assert(GL_DEPTH_COMPONENT == _GL_DEPTH_COMPONENT, "GL_DEPTH_COMPONENT is not equal to _GL_DEPTH_COMPONENT");
}
#pragma endregion

#pragma region COLOR1
#define GL_RED 0x1903
#define GL_GREEN 0x1904
#define GL_BLUE 0x1905
#define GL_ALPHA 0x1906
#define GL_RGB 0x1907
#define GL_RGBA 0x1908
export{
    constexpr int _GL_RED = 0x1903;
    constexpr int _GL_GREEN = 0x1904;
    constexpr int _GL_BLUE = 0x1905;
    constexpr int _GL_ALPHA = 0x1906;
    constexpr int _GL_RGB = 0x1907;
    constexpr int _GL_RGBA = 0x1908;
}
consteval void Check_Color1() {
    static_assert(GL_RED == _GL_RED, "GL_RED is not equal to _GL_RED");
    static_assert(GL_GREEN == _GL_GREEN, "GL_GREEN is not equal to _GL_GREEN");
    static_assert(GL_BLUE == _GL_BLUE, "GL_BLUE is not equal to _GL_BLUE");
    static_assert(GL_ALPHA == _GL_ALPHA, "GL_ALPHA is not equal to _GL_ALPHA");
    static_assert(GL_RGB == _GL_RGB, "GL_RGB is not equal to _GL_RGB");
    static_assert(GL_RGBA == _GL_RGBA, "GL_RGBA is not equal to _GL_RGBA");
}
#pragma endregion

#pragma region RANDOM_STUFF3
#define GL_POINT 0x1B00
#define GL_LINE 0x1B01
export{
    constexpr int _GL_POINT = 0x1B00;
    constexpr int _GL_LINE = 0x1B01;
}
consteval void Check_Random_Stuff3() {
    static_assert(GL_POINT == _GL_POINT, "GL_POINT is not equal to _GL_POINT");
    static_assert(GL_LINE == _GL_LINE, "GL_LINE is not equal to _GL_LINE");
}
#pragma endregion

#pragma region RANDOM_STUFF4
#define GL_FILL 0x1B02
#define GL_KEEP 0x1E00
#define GL_REPLACE 0x1E01
#define GL_INCR 0x1E02
#define GL_DECR 0x1E03
export{
    constexpr int _GL_FILL = 0x1B02;
    constexpr int _GL_KEEP = 0x1E00;
    constexpr int _GL_REPLACE = 0x1E01;
    constexpr int _GL_INCR = 0x1E02;
    constexpr int _GL_DECR = 0x1E03;
}
consteval void Check_Random_Stuff4() {
    static_assert(GL_FILL == _GL_FILL, "GL_FILL is not equal to _GL_FILL");
    static_assert(GL_KEEP == _GL_KEEP, "GL_KEEP is not equal to _GL_KEEP");
    static_assert(GL_REPLACE == _GL_REPLACE, "GL_REPLACE is not equal to _GL_REPLACE");
    static_assert(GL_INCR == _GL_INCR, "GL_INCR is not equal to _GL_INCR");
    static_assert(GL_DECR == _GL_DECR, "GL_DECR is not equal to _GL_DECR");
}
#pragma endregion

#pragma region RANDOM_STUFF5
#define GL_VENDOR 0x1F00
#define GL_RENDERER 0x1F01
#define GL_VERSION 0x1F02
#define GL_EXTENSIONS 0x1F03
export{
    constexpr int _GL_VENDOR = 0x1F00;
    constexpr int _GL_RENDERER = 0x1F01;
    constexpr int _GL_VERSION = 0x1F02;
    constexpr int _GL_EXTENSIONS = 0x1F03;
}
consteval void Check_Random_Stuff5() {
    static_assert(GL_VENDOR == _GL_VENDOR, "GL_VENDOR is not equal to _GL_VENDOR");
    static_assert(GL_RENDERER == _GL_RENDERER, "GL_RENDERER is not equal to _GL_RENDERER");
    static_assert(GL_VERSION == _GL_VERSION, "GL_VERSION is not equal to _GL_VERSION");
    static_assert(GL_EXTENSIONS == _GL_EXTENSIONS, "GL_EXTENSIONS is not equal to _GL_EXTENSIONS");
}
#pragma endregion

#pragma region RANDOM_STUFF6
#define GL_NEAREST 0x2600
#define GL_LINEAR 0x2601
export{
    constexpr int _GL_NEAREST = 0x2600;
    constexpr int _GL_LINEAR = 0x2601;
}
consteval void Check_Random_Stuff6() {
    static_assert(GL_NEAREST == _GL_NEAREST, "GL_NEAREST is not equal to _GL_NEAREST");
    static_assert(GL_LINEAR == _GL_LINEAR, "GL_LINEAR is not equal to _GL_LINEAR");
}
#pragma endregion

#pragma region MIPMAP
#define GL_NEAREST_MIPMAP_NEAREST 0x2700
#define GL_LINEAR_MIPMAP_NEAREST 0x2701
#define GL_NEAREST_MIPMAP_LINEAR 0x2702
#define GL_LINEAR_MIPMAP_LINEAR 0x2703
export{
    constexpr int _GL_NEAREST_MIPMAP_NEAREST = 0x2700;
    constexpr int _GL_LINEAR_MIPMAP_NEAREST = 0x2701;
    constexpr int _GL_NEAREST_MIPMAP_LINEAR = 0x2702;
    constexpr int _GL_LINEAR_MIPMAP_LINEAR = 0x2703;
}
consteval void Check_Mipmap() {
    static_assert(GL_NEAREST_MIPMAP_NEAREST == _GL_NEAREST_MIPMAP_NEAREST, "GL_NEAREST_MIPMAP_NEAREST is not equal to _GL_NEAREST_MIPMAP_NEAREST");
    static_assert(GL_LINEAR_MIPMAP_NEAREST == _GL_LINEAR_MIPMAP_NEAREST, "GL_LINEAR_MIPMAP_NEAREST is not equal to _GL_LINEAR_MIPMAP_NEAREST");
    static_assert(GL_NEAREST_MIPMAP_LINEAR == _GL_NEAREST_MIPMAP_LINEAR, "GL_NEAREST_MIPMAP_LINEAR is not equal to _GL_NEAREST_MIPMAP_LINEAR");
    static_assert(GL_LINEAR_MIPMAP_LINEAR == _GL_LINEAR_MIPMAP_LINEAR, "GL_LINEAR_MIPMAP_LINEAR is not equal to _GL_LINEAR_MIPMAP_LINEAR");
}
#pragma endregion


#pragma region TEXTURE_STUFF3
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_TEXTURE_MIN_FILTER 0x2801
#define GL_TEXTURE_WRAP_S 0x2802
#define GL_TEXTURE_WRAP_T 0x2803
export{
    constexpr int _GL_TEXTURE_MAG_FILTER = 0x2800;
    constexpr int _GL_TEXTURE_MIN_FILTER = 0x2801;
    constexpr int _GL_TEXTURE_WRAP_S = 0x2802;
    constexpr int _GL_TEXTURE_WRAP_T = 0x2803;
}
consteval void Check_Texture_Stuff3() {
    static_assert(GL_TEXTURE_MAG_FILTER == _GL_TEXTURE_MAG_FILTER, "GL_TEXTURE_MAG_FILTER is not equal to _GL_TEXTURE_MAG_FILTER");
    static_assert(GL_TEXTURE_MIN_FILTER == _GL_TEXTURE_MIN_FILTER, "GL_TEXTURE_MIN_FILTER is not equal to _GL_TEXTURE_MIN_FILTER");
    static_assert(GL_TEXTURE_WRAP_S == _GL_TEXTURE_WRAP_S, "GL_TEXTURE_WRAP_S is not equal to _GL_TEXTURE_WRAP_S");
    static_assert(GL_TEXTURE_WRAP_T == _GL_TEXTURE_WRAP_T, "GL_TEXTURE_WRAP_T is not equal to _GL_TEXTURE_WRAP_T");
}
#pragma endregion

#pragma region RANDOM_STUFF7
#define GL_REPEAT 0x2901
#define GL_COLOR_LOGIC_OP 0x0BF2
export{
    constexpr int _GL_REPEAT = 0x2901;
    constexpr int _GL_COLOR_LOGIC_OP = 0x0BF2;
}
consteval void Check_Random_Stuff7() {
    static_assert(GL_REPEAT == _GL_REPEAT, "GL_REPEAT is not equal to _GL_REPEAT");
    static_assert(GL_COLOR_LOGIC_OP == _GL_COLOR_LOGIC_OP, "GL_COLOR_LOGIC_OP is not equal to _GL_COLOR_LOGIC_OP");
}
#pragma endregion


#pragma region POLYGON_STUFF2
#define GL_POLYGON_OFFSET_UNITS 0x2A00
#define GL_POLYGON_OFFSET_POINT 0x2A01
#define GL_POLYGON_OFFSET_LINE 0x2A02
#define GL_POLYGON_OFFSET_FILL 0x8037
#define GL_POLYGON_OFFSET_FACTOR 0x8038

export{
    constexpr int _GL_POLYGON_OFFSET_UNITS = 0x2A00;
    constexpr int _GL_POLYGON_OFFSET_POINT = 0x2A01;
    constexpr int _GL_POLYGON_OFFSET_LINE = 0x2A02;
    constexpr int _GL_POLYGON_OFFSET_FILL = 0x8037;
    constexpr int _GL_POLYGON_OFFSET_FACTOR = 0x8038;
}
    
consteval void Check_Polygon_Stuff2() {
    static_assert(GL_POLYGON_OFFSET_UNITS == _GL_POLYGON_OFFSET_UNITS, "GL_POLYGON_OFFSET_UNITS is not equal to _GL_POLYGON_OFFSET_UNITS");
    static_assert(GL_POLYGON_OFFSET_POINT == _GL_POLYGON_OFFSET_POINT, "GL_POLYGON_OFFSET_POINT is not equal to _GL_POLYGON_OFFSET_POINT");
    static_assert(GL_POLYGON_OFFSET_LINE == _GL_POLYGON_OFFSET_LINE, "GL_POLYGON_OFFSET_LINE is not equal to _GL_POLYGON_OFFSET_LINE");
    static_assert(GL_POLYGON_OFFSET_FILL == _GL_POLYGON_OFFSET_FILL, "GL_POLYGON_OFFSET_FILL is not equal to _GL_POLYGON_OFFSET_FILL");
    static_assert(GL_POLYGON_OFFSET_FACTOR == _GL_POLYGON_OFFSET_FACTOR, "GL_POLYGON_OFFSET_FACTOR is not equal to _GL_POLYGON_OFFSET_FACTOR");
}
#pragma endregion

#pragma region TEXTURE_STUFF7
#define GL_TEXTURE_BINDING_1D 0x8068
#define GL_TEXTURE_BINDING_2D 0x8069
#define GL_TEXTURE_INTERNAL_FORMAT 0x1003
#define GL_TEXTURE_RED_SIZE 0x805C
#define GL_TEXTURE_GREEN_SIZE 0x805D
#define GL_TEXTURE_BLUE_SIZE 0x805E
#define GL_TEXTURE_ALPHA_SIZE 0x805F
export{
    constexpr int _GL_TEXTURE_BINDING_1D = 0x8068;
    constexpr int _GL_TEXTURE_BINDING_2D = 0x8069;
    constexpr int _GL_TEXTURE_INTERNAL_FORMAT = 0x1003;
    constexpr int _GL_TEXTURE_RED_SIZE = 0x805C;
    constexpr int _GL_TEXTURE_GREEN_SIZE = 0x805D;
    constexpr int _GL_TEXTURE_BLUE_SIZE = 0x805E;
    constexpr int _GL_TEXTURE_ALPHA_SIZE = 0x805F;
}
consteval void Check_Texture_Stuff7() {
    static_assert(GL_TEXTURE_BINDING_1D == _GL_TEXTURE_BINDING_1D, "GL_TEXTURE_BINDING_1D is not equal to _GL_TEXTURE_BINDING_1D");
    static_assert(GL_TEXTURE_BINDING_2D == _GL_TEXTURE_BINDING_2D, "GL_TEXTURE_BINDING_2D is not equal to _GL_TEXTURE_BINDING_2D");
    static_assert(GL_TEXTURE_INTERNAL_FORMAT == _GL_TEXTURE_INTERNAL_FORMAT, "GL_TEXTURE_INTERNAL_FORMAT is not equal to _GL_TEXTURE_INTERNAL_FORMAT");
    static_assert(GL_TEXTURE_RED_SIZE == _GL_TEXTURE_RED_SIZE, "GL_TEXTURE_RED_SIZE is not equal to _GL_TEXTURE_RED_SIZE");
    static_assert(GL_TEXTURE_GREEN_SIZE == _GL_TEXTURE_GREEN_SIZE, "GL_TEXTURE_GREEN_SIZE is not equal to _GL_TEXTURE_GREEN_SIZE");
    static_assert(GL_TEXTURE_BLUE_SIZE == _GL_TEXTURE_BLUE_SIZE, "GL_TEXTURE_BLUE_SIZE is not equal to _GL_TEXTURE_BLUE_SIZE");
    static_assert(GL_TEXTURE_ALPHA_SIZE == _GL_TEXTURE_ALPHA_SIZE, "GL_TEXTURE_ALPHA_SIZE is not equal to _GL_TEXTURE_ALPHA_SIZE");
}
#pragma endregion


#pragma region DOUBLE
#define GL_DOUBLE 0x140A

export{
    constexpr int _GL_DOUBLE = 0x140A;
}
consteval void Check_Double() {
    static_assert(GL_DOUBLE == _GL_DOUBLE, "GL_DOUBLE is not equal to _GL_DOUBLE");
}
#pragma endregion

#pragma region PROXY_TEXTURE
#define GL_PROXY_TEXTURE_1D 0x8063
#define GL_PROXY_TEXTURE_2D 0x8064
export{
    constexpr int _GL_PROXY_TEXTURE_1D = 0x8063;
    constexpr int _GL_PROXY_TEXTURE_2D = 0x8064;
}
consteval void Check_Proxy_Texture() {
    static_assert(GL_PROXY_TEXTURE_1D == _GL_PROXY_TEXTURE_1D, "GL_PROXY_TEXTURE_1D is not equal to _GL_PROXY_TEXTURE_1D");
    static_assert(GL_PROXY_TEXTURE_2D == _GL_PROXY_TEXTURE_2D, "GL_PROXY_TEXTURE_2D is not equal to _GL_PROXY_TEXTURE_2D");
}
#pragma endregion



#pragma region RGB_STUFF1
#define GL_R3_G3_B2 0x2A10
#define GL_RGB4 0x804F
#define GL_RGB5 0x8050
#define GL_RGB8 0x8051
#define GL_RGB10 0x8052
#define GL_RGB12 0x8053
#define GL_RGB16 0x8054
#define GL_RGBA2 0x8055
#define GL_RGBA4 0x8056
#define GL_RGB5_A1 0x8057
#define GL_RGBA8 0x8058
#define GL_RGB10_A2 0x8059
#define GL_RGBA12 0x805A
#define GL_RGBA16 0x805B
export{
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
}
consteval void Check_RGB_Stuff1() {
    static_assert(GL_R3_G3_B2 == _GL_R3_G3_B2, "GL_R3_G3_B2 is not equal to _GL_R3_G3_B2");
    static_assert(GL_RGB4 == _GL_RGB4, "GL_RGB4 is not equal to _GL_RGB4");
    static_assert(GL_RGB5 == _GL_RGB5, "GL_RGB5 is not equal to _GL_RGB5");
    static_assert(GL_RGB8 == _GL_RGB8, "GL_RGB8 is not equal to _GL_RGB8");
    static_assert(GL_RGB10 == _GL_RGB10, "GL_RGB10 is not equal to _GL_RGB10");
    static_assert(GL_RGB12 == _GL_RGB12, "GL_RGB12 is not equal to _GL_RGB12");
    static_assert(GL_RGB16 == _GL_RGB16, "GL_RGB16 is not equal to _GL_RGB16");
    static_assert(GL_RGBA2 == _GL_RGBA2, "GL_RGBA2 is not equal to _GL_RGBA2");
    static_assert(GL_RGBA4 == _GL_RGBA4, "GL_RGBA4 is not equal to _GL_RGBA4");
    static_assert(GL_RGB5_A1 == _GL_RGB5_A1, "GL_RGB5_A1 is not equal to _GL_RGB5_A1");
    static_assert(GL_RGBA8 == _GL_RGBA8, "GL_RGBA8 is not equal to _GL_RGBA8");
    static_assert(GL_RGB10_A2 == _GL_RGB10_A2, "GL_RGB10_A2 is not equal to _GL_RGB10_A2");
    static_assert(GL_RGBA12 == _GL_RGBA12, "GL_RGBA12 is not equal to _GL_RGBA12");
    static_assert(GL_RGBA16 == _GL_RGBA16, "GL_RGBA16 is not equal to _GL_RGBA16");
}
#pragma endregion



#pragma region UNSIGNED_DATATYPES1
#define GL_UNSIGNED_BYTE_3_3_2 0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4 0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1 0x8034
#define GL_UNSIGNED_INT_8_8_8_8 0x8035
#define GL_UNSIGNED_INT_10_10_10_2 0x8036
export{
    constexpr int _GL_UNSIGNED_BYTE_3_3_2 = 0x8032;
    constexpr int _GL_UNSIGNED_SHORT_4_4_4_4 = 0x8033;
    constexpr int _GL_UNSIGNED_SHORT_5_5_5_1 = 0x8034;
    constexpr int _GL_UNSIGNED_INT_8_8_8_8 = 0x8035;
    constexpr int _GL_UNSIGNED_INT_10_10_10_2 = 0x8036;
}
consteval void Check_Unsigned_DataTypes1() {
    static_assert(GL_UNSIGNED_BYTE_3_3_2 == _GL_UNSIGNED_BYTE_3_3_2, "GL_UNSIGNED_BYTE_3_3_2 is not equal to _GL_UNSIGNED_BYTE_3_3_2");
    static_assert(GL_UNSIGNED_SHORT_4_4_4_4 == _GL_UNSIGNED_SHORT_4_4_4_4, "GL_UNSIGNED_SHORT_4_4_4_4 is not equal to _GL_UNSIGNED_SHORT_4_4_4_4");
    static_assert(GL_UNSIGNED_SHORT_5_5_5_1 == _GL_UNSIGNED_SHORT_5_5_5_1, "GL_UNSIGNED_SHORT_5_5_5_1 is not equal to _GL_UNSIGNED_SHORT_5_5_5_1");
    static_assert(GL_UNSIGNED_INT_8_8_8_8 == _GL_UNSIGNED_INT_8_8_8_8, "GL_UNSIGNED_INT_8_8_8_8 is not equal to _GL_UNSIGNED_INT_8_8_8_8");
    static_assert(GL_UNSIGNED_INT_10_10_10_2 == _GL_UNSIGNED_INT_10_10_10_2, "GL_UNSIGNED_INT_10_10_10_2 is not equal to _GL_UNSIGNED_INT_10_10_10_2");
}
#pragma endregion


#pragma region TEXTURE_BINDING_3D
#define GL_TEXTURE_BINDING_3D 0x806A

export{
    constexpr int _GL_TEXTURE_BINDING_3D = 0x806A;
}
consteval void Check_Texture_Binding_3D() {
    static_assert(GL_TEXTURE_BINDING_3D == _GL_TEXTURE_BINDING_3D, "GL_TEXTURE_BINDING_3D is not equal to _GL_TEXTURE_BINDING_3D");
}
#pragma endregion

#pragma region PACK_STUFF2
#define GL_PACK_SKIP_IMAGES 0x806B
#define GL_PACK_IMAGE_HEIGHT 0x806C
export{
    constexpr int _GL_PACK_SKIP_IMAGES = 0x806B;
    constexpr int _GL_PACK_IMAGE_HEIGHT = 0x806C;
}
consteval void Check_Pack_Stuff2() {
    static_assert(GL_PACK_SKIP_IMAGES == _GL_PACK_SKIP_IMAGES, "GL_PACK_SKIP_IMAGES is not equal to _GL_PACK_SKIP_IMAGES");
    static_assert(GL_PACK_IMAGE_HEIGHT == _GL_PACK_IMAGE_HEIGHT, "GL_PACK_IMAGE_HEIGHT is not equal to _GL_PACK_IMAGE_HEIGHT");
}
#pragma endregion


#pragma region UNPACK_STUFF2
#define GL_UNPACK_SKIP_IMAGES 0x806D
#define GL_UNPACK_IMAGE_HEIGHT 0x806E
export{
    constexpr int _GL_UNPACK_SKIP_IMAGES = 0x806D;
    constexpr int _GL_UNPACK_IMAGE_HEIGHT = 0x806E;
}
consteval void Check_Unpack_Stuff2() {
    static_assert(GL_UNPACK_SKIP_IMAGES == _GL_UNPACK_SKIP_IMAGES, "GL_UNPACK_SKIP_IMAGES is not equal to _GL_UNPACK_SKIP_IMAGES");
    static_assert(GL_UNPACK_IMAGE_HEIGHT == _GL_UNPACK_IMAGE_HEIGHT, "GL_UNPACK_IMAGE_HEIGHT is not equal to _GL_UNPACK_IMAGE_HEIGHT");
}
#pragma endregion

#pragma region TEXTURE_STUFF8
#define GL_TEXTURE_3D 0x806F
#define GL_PROXY_TEXTURE_3D 0x8070
#define GL_TEXTURE_DEPTH 0x8071
#define GL_TEXTURE_WRAP_R 0x8072
#define GL_MAX_3D_TEXTURE_SIZE 0x8073

    export constexpr int _GL_TEXTURE_3D = 0x806F;
    export constexpr int _GL_PROXY_TEXTURE_3D = 0x8070;
    export constexpr int _GL_TEXTURE_DEPTH = 0x8071;
    export constexpr int _GL_TEXTURE_WRAP_R = 0x8072;
    export constexpr int _GL_MAX_3D_TEXTURE_SIZE = 0x8073;

consteval void Check_Texture_Stuff8() {
    static_assert(GL_TEXTURE_3D == _GL_TEXTURE_3D, "GL_TEXTURE_3D is not equal to _GL_TEXTURE_3D");
    static_assert(GL_PROXY_TEXTURE_3D == _GL_PROXY_TEXTURE_3D, "GL_PROXY_TEXTURE_3D is not equal to _GL_PROXY_TEXTURE_3D");
    static_assert(GL_TEXTURE_DEPTH == _GL_TEXTURE_DEPTH, "GL_TEXTURE_DEPTH is not equal to _GL_TEXTURE_DEPTH");
    static_assert(GL_TEXTURE_WRAP_R == _GL_TEXTURE_WRAP_R, "GL_TEXTURE_WRAP_R is not equal to _GL_TEXTURE_WRAP_R");
    static_assert(GL_MAX_3D_TEXTURE_SIZE == _GL_MAX_3D_TEXTURE_SIZE, "GL_MAX_3D_TEXTURE_SIZE is not equal to _GL_MAX_3D_TEXTURE_SIZE");
}
#pragma endregion


#pragma region UNSIGNED_DATATYPES4
#define GL_UNSIGNED_BYTE_2_3_3_REV 0x8362
#define GL_UNSIGNED_SHORT_5_6_5 0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV 0x8364
#define GL_UNSIGNED_SHORT_4_4_4_4_REV 0x8365
#define GL_UNSIGNED_SHORT_1_5_5_5_REV 0x8366
#define GL_UNSIGNED_INT_8_8_8_8_REV 0x8367
#define GL_UNSIGNED_INT_2_10_10_10_REV 0x8368

    export constexpr int _GL_UNSIGNED_BYTE_2_3_3_REV = 0x8362;
    export constexpr int _GL_UNSIGNED_SHORT_5_6_5 = 0x8363;
    export constexpr int _GL_UNSIGNED_SHORT_5_6_5_REV = 0x8364;
    export constexpr int _GL_UNSIGNED_SHORT_4_4_4_4_REV = 0x8365;
    export constexpr int _GL_UNSIGNED_SHORT_1_5_5_5_REV = 0x8366;
    export constexpr int _GL_UNSIGNED_INT_8_8_8_8_REV = 0x8367;
    export constexpr int _GL_UNSIGNED_INT_2_10_10_10_REV = 0x8368;

consteval void Check_Unsigned_DataTypes4() {
    static_assert(GL_UNSIGNED_BYTE_2_3_3_REV == _GL_UNSIGNED_BYTE_2_3_3_REV, "GL_UNSIGNED_BYTE_2_3_3_REV is not equal to _GL_UNSIGNED_BYTE_2_3_3_REV");
    static_assert(GL_UNSIGNED_SHORT_5_6_5 == _GL_UNSIGNED_SHORT_5_6_5, "GL_UNSIGNED_SHORT_5_6_5 is not equal to _GL_UNSIGNED_SHORT_5_6_5");
    static_assert(GL_UNSIGNED_SHORT_5_6_5_REV == _GL_UNSIGNED_SHORT_5_6_5_REV, "GL_UNSIGNED_SHORT_5_6_5_REV is not equal to _GL_UNSIGNED_SHORT_5_6_5_REV");
    static_assert(GL_UNSIGNED_SHORT_4_4_4_4_REV == _GL_UNSIGNED_SHORT_4_4_4_4_REV, "GL_UNSIGNED_SHORT_4_4_4_4_REV is not equal to _GL_UNSIGNED_SHORT_4_4_4_4_REV");
    static_assert(GL_UNSIGNED_SHORT_1_5_5_5_REV == _GL_UNSIGNED_SHORT_1_5_5_5_REV, "GL_UNSIGNED_SHORT_1_5_5_5_REV is not equal to _GL_UNSIGNED_SHORT_1_5_5_5_REV");
    static_assert(GL_UNSIGNED_INT_8_8_8_8_REV == _GL_UNSIGNED_INT_8_8_8_8_REV, "GL_UNSIGNED_INT_8_8_8_8_REV is not equal to _GL_UNSIGNED_INT_8_8_8_8_REV");
    static_assert(GL_UNSIGNED_INT_2_10_10_10_REV == _GL_UNSIGNED_INT_2_10_10_10_REV, "GL_UNSIGNED_INT_2_10_10_10_REV is not equal to _GL_UNSIGNED_INT_2_10_10_10_REV");
}
#pragma endregion


#pragma region BGR
#define GL_BGR 0x80E0
#define GL_BGRA 0x80E1
 export   constexpr int _GL_BGR = 0x80E0;
   export constexpr int _GL_BGRA = 0x80E1;
consteval void Check_BGR() {
    static_assert(GL_BGR == _GL_BGR, "GL_BGR is not equal to _GL_BGR");
    static_assert(GL_BGRA == _GL_BGRA, "GL_BGRA is not equal to _GL_BGRA");
}
#pragma endregion


#pragma region MAX_ELEMENTS
#define GL_MAX_ELEMENTS_VERTICES 0x80E8
#define GL_MAX_ELEMENTS_INDICES 0x80E9
export{
    constexpr int _GL_MAX_ELEMENTS_VERTICES = 0x80E8;
    constexpr int _GL_MAX_ELEMENTS_INDICES = 0x80E9;
}
consteval void Check_Max_Elements() {
    static_assert(GL_MAX_ELEMENTS_VERTICES == _GL_MAX_ELEMENTS_VERTICES, "GL_MAX_ELEMENTS_VERTICES is not equal to _GL_MAX_ELEMENTS_VERTICES");
    static_assert(GL_MAX_ELEMENTS_INDICES == _GL_MAX_ELEMENTS_INDICES, "GL_MAX_ELEMENTS_INDICES is not equal to _GL_MAX_ELEMENTS_INDICES");
}
#pragma endregion


#pragma region CLAMP_TO_EDGE
#define GL_CLAMP_TO_EDGE 0x812F

export{
    constexpr int _GL_CLAMP_TO_EDGE = 0x812F;
}
consteval void Check_Clamp_To_Edge() {
    static_assert(GL_CLAMP_TO_EDGE == _GL_CLAMP_TO_EDGE, "GL_CLAMP_TO_EDGE is not equal to _GL_CLAMP_TO_EDGE");
}
#pragma endregion

#pragma region TEXTURE_STUFF9
#define GL_TEXTURE_MIN_LOD 0x813A
#define GL_TEXTURE_MAX_LOD 0x813B
#define GL_TEXTURE_BASE_LEVEL 0x813C
#define GL_TEXTURE_MAX_LEVEL 0x813D
export{
    constexpr int _GL_TEXTURE_MIN_LOD = 0x813A;
    constexpr int _GL_TEXTURE_MAX_LOD = 0x813B;
    constexpr int _GL_TEXTURE_BASE_LEVEL = 0x813C;
    constexpr int _GL_TEXTURE_MAX_LEVEL = 0x813D;
}
consteval void Check_Texture_Stuff9() {
    static_assert(GL_TEXTURE_MIN_LOD == _GL_TEXTURE_MIN_LOD, "GL_TEXTURE_MIN_LOD is not equal to _GL_TEXTURE_MIN_LOD");
    static_assert(GL_TEXTURE_MAX_LOD == _GL_TEXTURE_MAX_LOD, "GL_TEXTURE_MAX_LOD is not equal to _GL_TEXTURE_MAX_LOD");
    static_assert(GL_TEXTURE_BASE_LEVEL == _GL_TEXTURE_BASE_LEVEL, "GL_TEXTURE_BASE_LEVEL is not equal to _GL_TEXTURE_BASE_LEVEL");
    static_assert(GL_TEXTURE_MAX_LEVEL == _GL_TEXTURE_MAX_LEVEL, "GL_TEXTURE_MAX_LEVEL is not equal to _GL_TEXTURE_MAX_LEVEL");
}
#pragma endregion

#pragma region SMOOTH_STUFF1
#define GL_SMOOTH_POINT_SIZE_RANGE 0x0B12
#define GL_SMOOTH_POINT_SIZE_GRANULARITY 0x0B13
#define GL_SMOOTH_LINE_WIDTH_RANGE 0x0B22
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY 0x0B23

export{
    constexpr int _GL_SMOOTH_POINT_SIZE_RANGE = 0x0B12;
    constexpr int _GL_SMOOTH_POINT_SIZE_GRANULARITY = 0x0B13;
    constexpr int _GL_SMOOTH_LINE_WIDTH_RANGE = 0x0B22;
    constexpr int _GL_SMOOTH_LINE_WIDTH_GRANULARITY = 0x0B23;
}
consteval void Check_Smooth_Stuff1() {
    static_assert(GL_SMOOTH_POINT_SIZE_RANGE == _GL_SMOOTH_POINT_SIZE_RANGE, "GL_SMOOTH_POINT_SIZE_RANGE is not equal to _GL_SMOOTH_POINT_SIZE_RANGE");
    static_assert(GL_SMOOTH_POINT_SIZE_GRANULARITY == _GL_SMOOTH_POINT_SIZE_GRANULARITY, "GL_SMOOTH_POINT_SIZE_GRANULARITY is not equal to _GL_SMOOTH_POINT_SIZE_GRANULARITY");
    static_assert(GL_SMOOTH_LINE_WIDTH_RANGE == _GL_SMOOTH_LINE_WIDTH_RANGE, "GL_SMOOTH_LINE_WIDTH_RANGE is not equal to _GL_SMOOTH_LINE_WIDTH_RANGE");
    static_assert(GL_SMOOTH_LINE_WIDTH_GRANULARITY == _GL_SMOOTH_LINE_WIDTH_GRANULARITY, "GL_SMOOTH_LINE_WIDTH_GRANULARITY is not equal to _GL_SMOOTH_LINE_WIDTH_GRANULARITY");
}
#pragma endregion


#pragma region ALIASED_LINE_WIDTH_RANGE
#define GL_ALIASED_LINE_WIDTH_RANGE 0x846E

export{
    constexpr int _GL_ALIASED_LINE_WIDTH_RANGE = 0x846E;
}
consteval void Check_Aliased_Line_Width_Range() {
    static_assert(GL_ALIASED_LINE_WIDTH_RANGE == _GL_ALIASED_LINE_WIDTH_RANGE, "GL_ALIASED_LINE_WIDTH_RANGE is not equal to _GL_ALIASED_LINE_WIDTH_RANGE");
}
#pragma endregion

#pragma region TEXTURE_STUFF10
#define GL_TEXTURE0 0x84C0
#define GL_TEXTURE1 0x84C1
#define GL_TEXTURE2 0x84C2
#define GL_TEXTURE3 0x84C3
#define GL_TEXTURE4 0x84C4
#define GL_TEXTURE5 0x84C5
#define GL_TEXTURE6 0x84C6
#define GL_TEXTURE7 0x84C7
#define GL_TEXTURE8 0x84C8
#define GL_TEXTURE9 0x84C9
#define GL_TEXTURE10 0x84CA
#define GL_TEXTURE11 0x84CB
#define GL_TEXTURE12 0x84CC
#define GL_TEXTURE13 0x84CD
#define GL_TEXTURE14 0x84CE
#define GL_TEXTURE15 0x84CF
#define GL_TEXTURE16 0x84D0
#define GL_TEXTURE17 0x84D1
#define GL_TEXTURE18 0x84D2
#define GL_TEXTURE19 0x84D3
#define GL_TEXTURE20 0x84D4
#define GL_TEXTURE21 0x84D5
#define GL_TEXTURE22 0x84D6
#define GL_TEXTURE23 0x84D7
#define GL_TEXTURE24 0x84D8
#define GL_TEXTURE25 0x84D9
#define GL_TEXTURE26 0x84DA
#define GL_TEXTURE27 0x84DB
#define GL_TEXTURE28 0x84DC
#define GL_TEXTURE29 0x84DD
#define GL_TEXTURE30 0x84DE
#define GL_TEXTURE31 0x84DF
export{
    constexpr int _GL_TEXTURE0 = 0x84C0;
    constexpr int _GL_TEXTURE1 = 0x84C1;
    constexpr int _GL_TEXTURE2 = 0x84C2;
    constexpr int _GL_TEXTURE3 = 0x84C3;
    constexpr int _GL_TEXTURE4 = 0x84C4;
    constexpr int _GL_TEXTURE5 = 0x84C5;
    constexpr int _GL_TEXTURE6 = 0x84C6;
    constexpr int _GL_TEXTURE7 = 0x84C7;
    constexpr int _GL_TEXTURE8 = 0x84C8;
    constexpr int _GL_TEXTURE9 = 0x84C9;
    constexpr int _GL_TEXTURE10 = 0x84CA;
    constexpr int _GL_TEXTURE11 = 0x84CB;
    constexpr int _GL_TEXTURE12 = 0x84CC;
    constexpr int _GL_TEXTURE13 = 0x84CD;
    constexpr int _GL_TEXTURE14 = 0x84CE;
    constexpr int _GL_TEXTURE15 = 0x84CF;
    constexpr int _GL_TEXTURE16 = 0x84D0;
    constexpr int _GL_TEXTURE17 = 0x84D1;
    constexpr int _GL_TEXTURE18 = 0x84D2;
    constexpr int _GL_TEXTURE19 = 0x84D3;
    constexpr int _GL_TEXTURE20 = 0x84D4;
    constexpr int _GL_TEXTURE21 = 0x84D5;
    constexpr int _GL_TEXTURE22 = 0x84D6;
    constexpr int _GL_TEXTURE23 = 0x84D7;
    constexpr int _GL_TEXTURE24 = 0x84D8;
    constexpr int _GL_TEXTURE25 = 0x84D9;
    constexpr int _GL_TEXTURE26 = 0x84DA;
    constexpr int _GL_TEXTURE27 = 0x84DB;
    constexpr int _GL_TEXTURE28 = 0x84DC;
    constexpr int _GL_TEXTURE29 = 0x84DD;
    constexpr int _GL_TEXTURE30 = 0x84DE;
    constexpr int _GL_TEXTURE31 = 0x84DF;
}
consteval void Check_Texture_Stuff10() {
    static_assert(GL_TEXTURE0 == _GL_TEXTURE0, "GL_TEXTURE0 is not equal to _GL_TEXTURE0");
    static_assert(GL_TEXTURE1 == _GL_TEXTURE1, "GL_TEXTURE1 is not equal to _GL_TEXTURE1");
    static_assert(GL_TEXTURE2 == _GL_TEXTURE2, "GL_TEXTURE2 is not equal to _GL_TEXTURE2");
    static_assert(GL_TEXTURE3 == _GL_TEXTURE3, "GL_TEXTURE3 is not equal to _GL_TEXTURE3");
    static_assert(GL_TEXTURE4 == _GL_TEXTURE4, "GL_TEXTURE4 is not equal to _GL_TEXTURE4");
    static_assert(GL_TEXTURE5 == _GL_TEXTURE5, "GL_TEXTURE5 is not equal to _GL_TEXTURE5");
    static_assert(GL_TEXTURE6 == _GL_TEXTURE6, "GL_TEXTURE6 is not equal to _GL_TEXTURE6");
    static_assert(GL_TEXTURE7 == _GL_TEXTURE7, "GL_TEXTURE7 is not equal to _GL_TEXTURE7");
    static_assert(GL_TEXTURE8 == _GL_TEXTURE8, "GL_TEXTURE8 is not equal to _GL_TEXTURE8");
    static_assert(GL_TEXTURE9 == _GL_TEXTURE9, "GL_TEXTURE9 is not equal to _GL_TEXTURE9");
    static_assert(GL_TEXTURE10 == _GL_TEXTURE10, "GL_TEXTURE10 is not equal to _GL_TEXTURE10");
    static_assert(GL_TEXTURE11 == _GL_TEXTURE11, "GL_TEXTURE11 is not equal to _GL_TEXTURE11");
    static_assert(GL_TEXTURE12 == _GL_TEXTURE12, "GL_TEXTURE12 is not equal to _GL_TEXTURE12");
    static_assert(GL_TEXTURE13 == _GL_TEXTURE13, "GL_TEXTURE13 is not equal to _GL_TEXTURE13");
    static_assert(GL_TEXTURE14 == _GL_TEXTURE14, "GL_TEXTURE14 is not equal to _GL_TEXTURE14");
    static_assert(GL_TEXTURE15 == _GL_TEXTURE15, "GL_TEXTURE15 is not equal to _GL_TEXTURE15");
    static_assert(GL_TEXTURE16 == _GL_TEXTURE16, "GL_TEXTURE16 is not equal to _GL_TEXTURE16");
    static_assert(GL_TEXTURE17 == _GL_TEXTURE17, "GL_TEXTURE17 is not equal to _GL_TEXTURE17");
    static_assert(GL_TEXTURE18 == _GL_TEXTURE18, "GL_TEXTURE18 is not equal to _GL_TEXTURE18");
    static_assert(GL_TEXTURE19 == _GL_TEXTURE19, "GL _GL_TEXTURE19 is not equal to _GL_TEXTURE19");
    static_assert(GL_TEXTURE20 == _GL_TEXTURE20, "GL_TEXTURE20 is not equal to _GL_TEXTURE20");
    static_assert(GL_TEXTURE21 == _GL_TEXTURE21, "GL_TEXTURE21 is not equal to _GL_TEXTURE21");
    static_assert(GL_TEXTURE22 == _GL_TEXTURE22, "GL_TEXTURE22 is not equal to _GL_TEXTURE22");
    static_assert(GL_TEXTURE23 == _GL_TEXTURE23, "GL_TEXTURE23 is not equal to _GL_TEXTURE23");
    static_assert(GL_TEXTURE24 == _GL_TEXTURE24, "GL_TEXTURE24 is not equal to _GL_TEXTURE24");
    static_assert(GL_TEXTURE25 == _GL_TEXTURE25, "GL_TEXTURE25 is not equal to _GL_TEXTURE25");
    static_assert(GL_TEXTURE26 == _GL_TEXTURE26, "GL_TEXTURE26 is not equal to _GL_TEXTURE26");
    static_assert(GL_TEXTURE27 == _GL_TEXTURE27, "GL_TEXTURE27 is not equal to _GL_TEXTURE27");
    static_assert(GL_TEXTURE28 == _GL_TEXTURE28, "GL_TEXTURE28 is not equal to _GL_TEXTURE28");
    static_assert(GL_TEXTURE29 == _GL_TEXTURE29, "GL_TEXTURE29 is not equal to _GL_TEXTURE29");
    static_assert(GL_TEXTURE30 == _GL_TEXTURE30, "GL_TEXTURE30 is not equal to _GL_TEXTURE30");
    static_assert(GL_TEXTURE31 == _GL_TEXTURE31, "GL_TEXTURE31 is not equal to _GL_TEXTURE31");
}
#pragma endregion

#pragma region ACTIVE_TEXTURE
#define GL_ACTIVE_TEXTURE 0x84E0

export{
    constexpr int _GL_ACTIVE_TEXTURE = 0x84E0;
}
consteval void Check_Active_Texture() {
    static_assert(GL_ACTIVE_TEXTURE == _GL_ACTIVE_TEXTURE, "GL_ACTIVE_TEXTURE is not equal to _GL_ACTIVE_TEXTURE");
}
#pragma endregion

#pragma region MULTISAMPLE
#define GL_MULTISAMPLE 0x809D

export{
    constexpr int _GL_MULTISAMPLE = 0x809D;
}
consteval void Check_Multisample() {
    static_assert(GL_MULTISAMPLE == _GL_MULTISAMPLE, "GL_MULTISAMPLE is not equal to _GL_MULTISAMPLE");
}
#pragma endregion


#pragma region SAMPLE_STUFF
#define GL_SAMPLE_ALPHA_TO_COVERAGE 0x809E
#define GL_SAMPLE_ALPHA_TO_ONE 0x809F
#define GL_SAMPLE_COVERAGE 0x80A0
#define GL_SAMPLE_BUFFERS 0x80A8
#define GL_SAMPLES 0x80A9
#define GL_SAMPLE_COVERAGE_VALUE 0x80AA
#define GL_SAMPLE_COVERAGE_INVERT 0x80AB
export{
    constexpr int _GL_SAMPLE_ALPHA_TO_COVERAGE = 0x809E;
    constexpr int _GL_SAMPLE_ALPHA_TO_ONE = 0x809F;
    constexpr int _GL_SAMPLE_COVERAGE = 0x80A0;
    constexpr int _GL_SAMPLE_BUFFERS = 0x80A8;
    constexpr int _GL_SAMPLES = 0x80A9;
    constexpr int _GL_SAMPLE_COVERAGE_VALUE = 0x80AA;
    constexpr int _GL_SAMPLE_COVERAGE_INVERT = 0x80AB;
}
consteval void Check_Sample_Stuff() {
    static_assert(GL_SAMPLE_ALPHA_TO_COVERAGE == _GL_SAMPLE_ALPHA_TO_COVERAGE, "GL_SAMPLE_ALPHA_TO_COVERAGE is not equal to _GL_SAMPLE_ALPHA_TO_COVERAGE");
    static_assert(GL_SAMPLE_ALPHA_TO_ONE == _GL_SAMPLE_ALPHA_TO_ONE, "GL_SAMPLE_ALPHA_TO_ONE is not equal to _GL_SAMPLE_ALPHA_TO_ONE");
    static_assert(GL_SAMPLE_COVERAGE == _GL_SAMPLE_COVERAGE, "GL_SAMPLE_COVERAGE is not equal to _GL_SAMPLE_COVERAGE");
    static_assert(GL_SAMPLE_BUFFERS == _GL_SAMPLE_BUFFERS, "GL_SAMPLE_BUFFERS is not equal to _GL_SAMPLE_BUFFERS");
    static_assert(GL_SAMPLES == _GL_SAMPLES, "GL_SAMPLES is not equal to _GL_SAMPLES");
    static_assert(GL_SAMPLE_COVERAGE_VALUE == _GL_SAMPLE_COVERAGE_VALUE, "GL_SAMPLE_COVERAGE_VALUE is not equal to _GL_SAMPLE_COVERAGE_VALUE");
    static_assert(GL_SAMPLE_COVERAGE_INVERT == _GL_SAMPLE_COVERAGE_INVERT, "GL_SAMPLE_COVERAGE_INVERT is not equal to _GL_SAMPLE_COVERAGE_INVERT");
}
#pragma endregion


#pragma region TEXTURE_STUFF11
#define GL_TEXTURE_CUBE_MAP 0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP 0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X 0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X 0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y 0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y 0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z 0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z 0x851A
export{
    constexpr int _GL_TEXTURE_CUBE_MAP = 0x8513;
    constexpr int _GL_TEXTURE_BINDING_CUBE_MAP = 0x8514;
    constexpr int _GL_TEXTURE_CUBE_MAP_POSITIVE_X = 0x8515;
    constexpr int _GL_TEXTURE_CUBE_MAP_NEGATIVE_X = 0x8516;
    constexpr int _GL_TEXTURE_CUBE_MAP_POSITIVE_Y = 0x8517;
    constexpr int _GL_TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x8518;
    constexpr int _GL_TEXTURE_CUBE_MAP_POSITIVE_Z = 0x8519;
    constexpr int _GL_TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x851A;
}
consteval void Check_Texture_Stuff11() {
    static_assert(GL_TEXTURE_CUBE_MAP == _GL_TEXTURE_CUBE_MAP, "GL_TEXTURE_CUBE_MAP is not equal to _GL_TEXTURE_CUBE_MAP");
    static_assert(GL_TEXTURE_BINDING_CUBE_MAP == _GL_TEXTURE_BINDING_CUBE_MAP, "GL_TEXTURE_BINDING_CUBE_MAP is not equal to _GL_TEXTURE_BINDING_CUBE_MAP");
    static_assert(GL_TEXTURE_CUBE_MAP_POSITIVE_X == _GL_TEXTURE_CUBE_MAP_POSITIVE_X, "GL_TEXTURE_CUBE_MAP_POSITIVE_X is not equal to _GL_TEXTURE_CUBE_MAP_POSITIVE_X");
    static_assert(GL_TEXTURE_CUBE_MAP_NEGATIVE_X == _GL_TEXTURE_CUBE_MAP_NEGATIVE_X, "GL_TEXTURE_CUBE_MAP_NEGATIVE_X is not equal to _GL_TEXTURE_CUBE_MAP_NEGATIVE_X");
    static_assert(GL_TEXTURE_CUBE_MAP_POSITIVE_Y == _GL_TEXTURE_CUBE_MAP_POSITIVE_Y, "GL_TEXTURE_CUBE_MAP_POSITIVE_Y is not equal to _GL_TEXTURE_CUBE_MAP_POSITIVE_Y");
    static_assert(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y == _GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, "GL_TEXTURE_CUBE_MAP_NEGATIVE_Y is not equal to _GL_TEXTURE_CUBE_MAP_NEGATIVE_Y");
    static_assert(GL_TEXTURE_CUBE_MAP_POSITIVE_Z == _GL_TEXTURE_CUBE_MAP_POSITIVE_Z, "GL_TEXTURE_CUBE_MAP_POSITIVE_Z is not equal to _GL_TEXTURE_CUBE_MAP_POSITIVE_Z");
    static_assert(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z == _GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, "GL_TEXTURE_CUBE_MAP_NEGATIVE_Z is not equal to _GL_TEXTURE_CUBE_MAP_NEGATIVE_Z");
}
#pragma endregion

#pragma region RANDOM_STUFF10
#define GL_PROXY_TEXTURE_CUBE_MAP 0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE 0x851C
#define GL_COMPRESSED_RGB 0x84ED
#define GL_COMPRESSED_RGBA 0x84EE
#define GL_TEXTURE_COMPRESSION_HINT 0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE 0x86A0
#define GL_TEXTURE_COMPRESSED 0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS 0x86A3
#define GL_CLAMP_TO_BORDER 0x812D
#define GL_BLEND_DST_RGB 0x80C8
#define GL_BLEND_SRC_RGB 0x80C9
#define GL_BLEND_DST_ALPHA 0x80CA
#define GL_BLEND_SRC_ALPHA 0x80CB
#define GL_POINT_FADE_THRESHOLD_SIZE 0x8128
#define GL_DEPTH_COMPONENT16 0x81A5
#define GL_DEPTH_COMPONENT24 0x81A6
#define GL_DEPTH_COMPONENT32 0x81A7
#define GL_MIRRORED_REPEAT 0x8370
#define GL_MAX_TEXTURE_LOD_BIAS 0x84FD
#define GL_TEXTURE_LOD_BIAS 0x8501
#define GL_INCR_WRAP 0x8507
#define GL_DECR_WRAP 0x8508
#define GL_TEXTURE_DEPTH_SIZE 0x884A
#define GL_TEXTURE_COMPARE_MODE 0x884C
#define GL_TEXTURE_COMPARE_FUNC 0x884D

    export constexpr int _GL_PROXY_TEXTURE_CUBE_MAP = 0x851B;
    export constexpr int _GL_MAX_CUBE_MAP_TEXTURE_SIZE = 0x851C;
    export constexpr int _GL_COMPRESSED_RGB = 0x84ED;
    export constexpr int _GL_COMPRESSED_RGBA = 0x84EE;
    export constexpr int _GL_TEXTURE_COMPRESSION_HINT = 0x84EF;
    export constexpr int _GL_TEXTURE_COMPRESSED_IMAGE_SIZE = 0x86A0;
    export constexpr int _GL_TEXTURE_COMPRESSED = 0x86A1;
    export constexpr int _GL_NUM_COMPRESSED_TEXTURE_FORMATS = 0x86A2;
    export constexpr int _GL_COMPRESSED_TEXTURE_FORMATS = 0x86A3;
    export constexpr int _GL_CLAMP_TO_BORDER = 0x812D;
    export constexpr int _GL_BLEND_DST_RGB = 0x80C8;
    export constexpr int _GL_BLEND_SRC_RGB = 0x80C9;
    export constexpr int _GL_BLEND_DST_ALPHA = 0x80CA;
    export constexpr int _GL_BLEND_SRC_ALPHA = 0x80CB;
    export constexpr int _GL_POINT_FADE_THRESHOLD_SIZE = 0x8128;
    export constexpr int _GL_DEPTH_COMPONENT16 = 0x81A5;
    export constexpr int _GL_DEPTH_COMPONENT24 = 0x81A6;
    export constexpr int _GL_DEPTH_COMPONENT32 = 0x81A7;
    export constexpr int _GL_MIRRORED_REPEAT = 0x8370;
    export constexpr int _GL_MAX_TEXTURE_LOD_BIAS = 0x84FD;
    export constexpr int _GL_TEXTURE_LOD_BIAS = 0x8501;
    export constexpr int _GL_INCR_WRAP = 0x8507;
    export constexpr int _GL_DECR_WRAP = 0x8508;
    export constexpr int _GL_TEXTURE_DEPTH_SIZE = 0x884A;
    export constexpr int _GL_TEXTURE_COMPARE_MODE = 0x884C;
    export constexpr int _GL_TEXTURE_COMPARE_FUNC = 0x884D;


consteval void Check_Random_Stuff10() {
    static_assert(GL_PROXY_TEXTURE_CUBE_MAP == _GL_PROXY_TEXTURE_CUBE_MAP, "GL_PROXY_TEXTURE_CUBE_MAP is not equal to _GL_PROXY_TEXTURE_CUBE_MAP");
    static_assert(GL_MAX_CUBE_MAP_TEXTURE_SIZE == _GL_MAX_CUBE_MAP_TEXTURE_SIZE, "GL_MAX_CUBE_MAP_TEXTURE_SIZE is not equal to _GL_MAX_CUBE_MAP_TEXTURE_SIZE");
    static_assert(GL_COMPRESSED_RGB == _GL_COMPRESSED_RGB, "GL_COMPRESSED_RGB is not equal to _GL_COMPRESSED_RGB");
    static_assert(GL_COMPRESSED_RGBA == _GL_COMPRESSED_RGBA, "GL_COMPRESSED_RGBA is not equal to _GL_COMPRESSED_RGBA");
    static_assert(GL_TEXTURE_COMPRESSION_HINT == _GL_TEXTURE_COMPRESSION_HINT, "GL_TEXTURE_COMPRESSION_HINT is not equal to _GL_TEXTURE_COMPRESSION_HINT");
    static_assert(GL_TEXTURE_COMPRESSED_IMAGE_SIZE == _GL_TEXTURE_COMPRESSED_IMAGE_SIZE, "GL_TEXTURE_COMPRESSED_IMAGE_SIZE is not equal to _GL_TEXTURE_COMPRESSED_IMAGE_SIZE");
    static_assert(GL_TEXTURE_COMPRESSED == _GL_TEXTURE_COMPRESSED, "GL_TEXTURE_COMPRESSED is not equal to _GL_TEXTURE_COMPRESSED");
    static_assert(GL_NUM_COMPRESSED_TEXTURE_FORMATS == _GL_NUM_COMPRESSED_TEXTURE_FORMATS, "GL_NUM_COMPRESSED_TEXTURE_FORMATS is not equal to _GL_NUM_COMPRESSED_TEXTURE_FORMATS");
    static_assert(GL_COMPRESSED_TEXTURE_FORMATS == _GL_COMPRESSED_TEXTURE_FORMATS, "GL_COMPRESSED_TEXTURE_FORMATS is not equal to _GL_COMPRESSED_TEXTURE_FORMATS");
    static_assert(GL_CLAMP_TO_BORDER == _GL_CLAMP_TO_BORDER, "GL_CLAMP_TO_BORDER is not equal to _GL_CLAMP_TO_BORDER");
    static_assert(GL_BLEND_DST_RGB == _GL_BLEND_DST_RGB, "GL_BLEND_DST_RGB is not equal to _GL_BLEND_DST_RGB");
    static_assert(GL_BLEND_SRC_RGB == _GL_BLEND_SRC_RGB, "GL_BLEND_SRC_RGB is not equal to _GL_BLEND_SRC_RGB");
    static_assert(GL_BLEND_DST_ALPHA == _GL_BLEND_DST_ALPHA, "GL_BLEND_DST_ALPHA is not equal to _GL_BLEND_DST_ALPHA");
    static_assert(GL_BLEND_SRC_ALPHA == _GL_BLEND_SRC_ALPHA, "GL_BLEND_SRC_ALPHA is not equal to _GL_BLEND_SRC_ALPHA");
    static_assert(GL_POINT_FADE_THRESHOLD_SIZE == _GL_POINT_FADE_THRESHOLD_SIZE, "GL_POINT_FADE_THRESHOLD_SIZE is not equal to _GL_POINT_FADE_THRESHOLD_SIZE");

    static_assert(GL_DEPTH_COMPONENT16 == _GL_DEPTH_COMPONENT16, "GL_DEPTH_COMPONENT16 is not equal to _GL_DEPTH_COMPONENT16");
    static_assert(GL_DEPTH_COMPONENT24 == _GL_DEPTH_COMPONENT24, "GL_DEPTH_COMPONENT24 is not equal to _GL_DEPTH_COMPONENT24");
    static_assert(GL_DEPTH_COMPONENT32 == _GL_DEPTH_COMPONENT32, "GL_DEPTH_COMPONENT32 is not equal to _GL_DEPTH_COMPONENT32");
    static_assert(GL_MIRRORED_REPEAT == _GL_MIRRORED_REPEAT, "GL_MIRRORED_REPEAT is not equal to _GL_MIRRORED_REPEAT");
    static_assert(GL_MAX_TEXTURE_LOD_BIAS == _GL_MAX_TEXTURE_LOD_BIAS, "GL_MAX_TEXTURE_LOD_BIAS is not equal to _GL_MAX_TEXTURE_LOD_BIAS");
    static_assert(GL_TEXTURE_LOD_BIAS == _GL_TEXTURE_LOD_BIAS, "GL_TEXTURE_LOD_BIAS is not equal to _GL_TEXTURE_LOD_BIAS");
    static_assert(GL_INCR_WRAP == _GL_INCR_WRAP, "GL_INCR_WRAP is not equal to _GL_INCR_WRAP");
    static_assert(GL_DECR_WRAP == _GL_DECR_WRAP, "GL_DECR_WRAP is not equal to _GL_DECR_WRAP");
    static_assert(GL_TEXTURE_DEPTH_SIZE == _GL_TEXTURE_DEPTH_SIZE, "GL_TEXTURE_DEPTH_SIZE is not equal to _GL_TEXTURE_DEPTH_SIZE");
    static_assert(GL_TEXTURE_COMPARE_MODE == _GL_TEXTURE_COMPARE_MODE, "GL_TEXTURE_COMPARE_MODE is not equal to _GL_TEXTURE_COMPARE_MODE");
    static_assert(GL_TEXTURE_COMPARE_FUNC == _GL_TEXTURE_COMPARE_FUNC, "GL_TEXTURE_COMPARE_FUNC is not equal to _GL_TEXTURE_COMPARE_FUNC");
}

#pragma endregion


#pragma region RANDOM_STUFF11

#define GL_BLEND_COLOR 0x8005
#define GL_BLEND_EQUATION 0x8009
#define GL_CONSTANT_COLOR 0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR 0x8002
#define GL_CONSTANT_ALPHA 0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA 0x8004
#define GL_FUNC_ADD 0x8006
#define GL_FUNC_REVERSE_SUBTRACT 0x800B
#define GL_FUNC_SUBTRACT 0x800A
#define GL_MIN 0x8007
#define GL_MAX 0x8008
#define GL_BUFFER_SIZE 0x8764
#define GL_BUFFER_USAGE 0x8765
#define GL_QUERY_COUNTER_BITS 0x8864
#define GL_CURRENT_QUERY 0x8865
#define GL_QUERY_RESULT 0x8866
#define GL_QUERY_RESULT_AVAILABLE 0x8867
#define GL_ARRAY_BUFFER 0x8892
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_ARRAY_BUFFER_BINDING 0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING 0x8895
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_READ_ONLY 0x88B8
#define GL_WRITE_ONLY 0x88B9
#define GL_READ_WRITE 0x88BA
#define GL_BUFFER_ACCESS 0x88BB
#define GL_BUFFER_MAPPED 0x88BC
#define GL_BUFFER_MAP_POINTER 0x88BD
#define GL_STREAM_DRAW 0x88E0
#define GL_STREAM_READ 0x88E1
#define GL_STREAM_COPY 0x88E2

    export constexpr int _GL_BLEND_COLOR = 0x8005;
    export constexpr int _GL_BLEND_EQUATION = 0x8009;
    export constexpr int _GL_CONSTANT_COLOR = 0x8001;
    export constexpr int _GL_ONE_MINUS_CONSTANT_COLOR = 0x8002;
    export constexpr int _GL_CONSTANT_ALPHA = 0x8003;
    export constexpr int _GL_ONE_MINUS_CONSTANT_ALPHA = 0x8004;
    export constexpr int _GL_FUNC_ADD = 0x8006;
    export constexpr int _GL_FUNC_REVERSE_SUBTRACT = 0x800B;
    export constexpr int _GL_FUNC_SUBTRACT = 0x800A;
    export constexpr int _GL_MIN = 0x8007;
    export constexpr int _GL_MAX = 0x8008;
    export constexpr int _GL_BUFFER_SIZE = 0x8764;
    export constexpr int _GL_BUFFER_USAGE = 0x8765;
    export constexpr int _GL_QUERY_COUNTER_BITS = 0x8864;
    export constexpr int _GL_CURRENT_QUERY = 0x8865;
    export constexpr int _GL_QUERY_RESULT = 0x8866;
    export constexpr int _GL_QUERY_RESULT_AVAILABLE = 0x8867;
    export constexpr int _GL_ARRAY_BUFFER = 0x8892;
    export constexpr int _GL_ELEMENT_ARRAY_BUFFER = 0x8893;
    export constexpr int _GL_ARRAY_BUFFER_BINDING = 0x8894;
    export constexpr int _GL_ELEMENT_ARRAY_BUFFER_BINDING = 0x8895;
    export constexpr int _GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 0x889F;
    export constexpr int _GL_READ_ONLY = 0x88B8;
    export constexpr int _GL_WRITE_ONLY = 0x88B9;
    export constexpr int _GL_READ_WRITE = 0x88BA;
    export constexpr int _GL_BUFFER_ACCESS = 0x88BB;
    export constexpr int _GL_BUFFER_MAPPED = 0x88BC;
    export constexpr int _GL_BUFFER_MAP_POINTER = 0x88BD;
    export constexpr int _GL_STREAM_DRAW = 0x88E0;
    export constexpr int _GL_STREAM_READ = 0x88E1;
    export constexpr int _GL_STREAM_COPY = 0x88E2;

consteval void Check_Random_Stuff11() {
    static_assert(GL_BLEND_COLOR == _GL_BLEND_COLOR, "GL_BLEND_COLOR is not equal to _GL_BLEND_COLOR");
    static_assert(GL_BLEND_EQUATION == _GL_BLEND_EQUATION, "GL_BLEND_EQUATION is not equal to _GL_BLEND_EQUATION");
    static_assert(GL_CONSTANT_COLOR == _GL_CONSTANT_COLOR, "GL_CONSTANT_COLOR is not equal to _GL_CONSTANT_COLOR");
    static_assert(GL_ONE_MINUS_CONSTANT_COLOR == _GL_ONE_MINUS_CONSTANT_COLOR, "GL_ONE_MINUS_CONSTANT_COLOR is not equal to _GL_ONE_MINUS_CONSTANT_COLOR");
    static_assert(GL_CONSTANT_ALPHA == _GL_CONSTANT_ALPHA, "GL_CONSTANT_ALPHA is not equal to _GL_CONSTANT_ALPHA");
    static_assert(GL_ONE_MINUS_CONSTANT_ALPHA == _GL_ONE_MINUS_CONSTANT_ALPHA, "GL_ONE_MINUS_CONSTANT_ALPHA is not equal to _GL_ONE_MINUS_CONSTANT_ALPHA");
    static_assert(GL_FUNC_ADD == _GL_FUNC_ADD, "GL_FUNC_ADD is not equal to _GL_FUNC_ADD");
    static_assert(GL_FUNC_REVERSE_SUBTRACT == _GL_FUNC_REVERSE_SUBTRACT, "GL_FUNC_REVERSE_SUBTRACT is not equal to _GL_FUNC_REVERSE_SUBTRACT");
    static_assert(GL_FUNC_SUBTRACT == _GL_FUNC_SUBTRACT, "GL_FUNC_SUBTRACT is not equal to _GL_FUNC_SUBTRACT");
    static_assert(GL_MIN == _GL_MIN, "GL_MIN is not equal to _GL_MIN");
    static_assert(GL_MAX == _GL_MAX, "GL_MAX is not equal to _GL_MAX");
    static_assert(GL_BUFFER_SIZE == _GL_BUFFER_SIZE, "GL_BUFFER_SIZE is not equal to _GL_BUFFER_SIZE");
    static_assert(GL_BUFFER_USAGE == _GL_BUFFER_USAGE, "GL_BUFFER_USAGE is not equal to _GL_BUFFER_USAGE");
    static_assert(GL_QUERY_COUNTER_BITS == _GL_QUERY_COUNTER_BITS, "GL_QUERY_COUNTER_BITS is not equal to _GL_QUERY_COUNTER_BITS");
    static_assert(GL_CURRENT_QUERY == _GL_CURRENT_QUERY, "GL_CURRENT_QUERY is not equal to _GL_CURRENT_QUERY");
    static_assert(GL_QUERY_RESULT == _GL_QUERY_RESULT, "GL_QUERY_RESULT is not equal to _GL_QUERY_RESULT");
    static_assert(GL_QUERY_RESULT_AVAILABLE == _GL_QUERY_RESULT_AVAILABLE, "GL_QUERY_RESULT_AVAILABLE is not equal to _GL_QUERY_RESULT_AVAILABLE");
    static_assert(GL_ARRAY_BUFFER == _GL_ARRAY_BUFFER, "GL_ARRAY_BUFFER is not equal to _GL_ARRAY BUFFER");
    static_assert(GL_ELEMENT_ARRAY_BUFFER == _GL_ELEMENT_ARRAY_BUFFER, "GL_ELEMENT_ARRAY_BUFFER is not equal to _GL_ELEMENT_ARRAY_BUFFER");
    static_assert(GL_ARRAY_BUFFER_BINDING == _GL_ARRAY_BUFFER_BINDING, "GL_ARRAY_BUFFER_BINDING is not equal to _GL_ARRAY_BUFFER_BINDING");
    static_assert(GL_ELEMENT_ARRAY_BUFFER_BINDING == _GL_ELEMENT_ARRAY_BUFFER_BINDING, "GL_ELEMENT_ARRAY_BUFFER_BINDING is not equal to _GL_ELEMENT_ARRAY_BUFFER_BINDING");
    static_assert(GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING == _GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING, "GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING is not equal to _GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING");
    static_assert(GL_READ_ONLY == _GL_READ_ONLY, "GL_READ_ONLY is not equal to _GL_READ_ONLY");
    static_assert(GL_WRITE_ONLY == _GL_WRITE_ONLY, "GL_WRITE_ONLY is not equal to _GL_WRITE_ONLY");
    static_assert(GL_READ_WRITE == _GL_READ_WRITE, "GL_READ_WRITE is not equal to _GL_READ_WRITE");
    static_assert(GL_BUFFER_ACCESS == _GL_BUFFER_ACCESS, "GL_BUFFER_ACCESS is not equal to _GL_BUFFER_ACCESS");
    static_assert(GL_BUFFER_MAPPED == _GL_BUFFER_MAPPED, "GL_BUFFER_MAPPED is not equal to _GL_BUFFER_MAPPED");
    static_assert(GL_BUFFER_MAP_POINTER == _GL_BUFFER_MAP_POINTER, "GL_BUFFER_MAP_POINTER is not equal to _GL_BUFFER_MAP_POINTER");
    static_assert(GL_STREAM_DRAW == _GL_STREAM_DRAW, "GL_STREAM_DRAW is not equal to _GL_STREAM_DRAW");
    static_assert(GL_STREAM_READ == _GL_STREAM_READ, "GL_STREAM_READ is not equal to _GL_STREAM_READ");
    static_assert(GL_STREAM_COPY == _GL_STREAM_COPY, "GL_STREAM_COPY is not equal to _GL_STREAM_COPY");
}
#pragma endregion

#pragma region RANDOM_STUFF12
#define GL_STATIC_DRAW 0x88E4
#define GL_STATIC_READ 0x88E5
#define GL_STATIC_COPY 0x88E6
#define GL_DYNAMIC_DRAW 0x88E8
#define GL_DYNAMIC_READ 0x88E9
#define GL_DYNAMIC_COPY 0x88EA
#define GL_SAMPLES_PASSED 0x8914
#define GL_SRC1_ALPHA 0x8589
#define GL_BLEND_EQUATION_RGB 0x8009
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED 0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE 0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE 0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE 0x8625
#define GL_CURRENT_VERTEX_ATTRIB 0x8626
#define GL_VERTEX_PROGRAM_POINT_SIZE 0x8642
#define GL_VERTEX_ATTRIB_ARRAY_POINTER 0x8645
#define GL_STENCIL_BACK_FUNC 0x8800
#define GL_STENCIL_BACK_FAIL 0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL 0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS 0x8803
#define GL_MAX_DRAW_BUFFERS 0x8824

    export constexpr int _GL_STATIC_DRAW = 0x88E4;
    export constexpr int _GL_STATIC_READ = 0x88E5;
    export constexpr int _GL_STATIC_COPY = 0x88E6;
    export constexpr int _GL_DYNAMIC_DRAW = 0x88E8;
    export constexpr int _GL_DYNAMIC_READ = 0x88E9;
    export constexpr int _GL_DYNAMIC_COPY = 0x88EA;
    export constexpr int _GL_SAMPLES_PASSED = 0x8914;
    export constexpr int _GL_SRC1_ALPHA = 0x8589;
    export constexpr int _GL_BLEND_EQUATION_RGB = 0x8009;
    export constexpr int _GL_VERTEX_ATTRIB_ARRAY_ENABLED = 0x8622;
    export constexpr int _GL_VERTEX_ATTRIB_ARRAY_SIZE = 0x8623;
    export constexpr int _GL_VERTEX_ATTRIB_ARRAY_STRIDE = 0x8624;
    export constexpr int _GL_VERTEX_ATTRIB_ARRAY_TYPE = 0x8625;
    export constexpr int _GL_CURRENT_VERTEX_ATTRIB = 0x8626;
    export constexpr int _GL_VERTEX_PROGRAM_POINT_SIZE = 0x8642;
    export constexpr int _GL_VERTEX_ATTRIB_ARRAY_POINTER = 0x8645;
    export constexpr int _GL_STENCIL_BACK_FUNC = 0x8800;
    export constexpr int _GL_STENCIL_BACK_FAIL = 0x8801;
    export constexpr int _GL_STENCIL_BACK_PASS_DEPTH_FAIL = 0x8802;
    export constexpr int _GL_STENCIL_BACK_PASS_DEPTH_PASS = 0x8803;
    export constexpr int _GL_MAX_DRAW_BUFFERS = 0x8824;

consteval void Check_Random_Stuff12() {
    static_assert(GL_STATIC_DRAW == _GL_STATIC_DRAW, "GL_STATIC_DRAW is not equal to _GL_STATIC_DRAW");
    static_assert(GL_STATIC_READ == _GL_STATIC_READ, "GL_STATIC_READ is not equal to _GL_STATIC_READ");
    static_assert(GL_STATIC_COPY == _GL_STATIC_COPY, "GL_STATIC_COPY is not equal to _GL_STATIC_COPY");
    static_assert(GL_DYNAMIC_DRAW == _GL_DYNAMIC_DRAW, "GL_DYNAMIC_DRAW is not equal to _GL_DYNAMIC_DRAW");
    static_assert(GL_DYNAMIC_READ == _GL_DYNAMIC_READ, "GL_DYNAMIC_READ is not equal to _GL_DYNAMIC_READ");
    static_assert(GL_DYNAMIC_COPY == _GL_DYNAMIC_COPY, "GL_DYNAMIC_COPY is not equal to _GL_DYNAMIC_COPY");
    static_assert(GL_SAMPLES_PASSED == _GL_SAMPLES_PASSED, "GL_SAMPLES_PASSED is not equal to _GL_SAMPLES_PASSED");
    static_assert(GL_SRC1_ALPHA == _GL_SRC1_ALPHA, "GL_SRC1_ALPHA is not equal to _GL_SRC1_ALPHA");
    static_assert(GL_BLEND_EQUATION_RGB == _GL_BLEND_EQUATION_RGB, "GL_BLEND_EQUATION_RGB is not equal to _GL_BLEND_EQUATION_RGB");
    static_assert(GL_VERTEX_ATTRIB_ARRAY_ENABLED == _GL_VERTEX_ATTRIB_ARRAY_ENABLED, "GL_VERTEX_ATTRIB_ARRAY_ENABLED is not equal to _GL_VERTEX_ATTRIB_ARRAY_ENABLED");
    static_assert(GL_VERTEX_ATTRIB_ARRAY_SIZE == _GL_VERTEX_ATTRIB_ARRAY_SIZE, "GL_VERTEX_ATTRIB_ARRAY_SIZE is not equal to _GL_VERTEX_ATTRIB_ARRAY_SIZE");
    static_assert(GL_VERTEX_ATTRIB_ARRAY_STRIDE == _GL_VERTEX_ATTRIB_ARRAY_STRIDE, "GL_VERTEX_ATTRIB_ARRAY_STRIDE is not equal to _GL_VERTEX_ATTRIB_ARRAY_STRIDE");
    static_assert(GL_VERTEX_ATTRIB_ARRAY_TYPE == _GL_VERTEX_ATTRIB_ARRAY_TYPE, "GL_VERTEX_ATTRIB_ARRAY_TYPE is not equal to _GL_VERTEX_ATTRIB_ARRAY_TYPE");
    static_assert(GL_CURRENT_VERTEX_ATTRIB == _GL_CURRENT_VERTEX_ATTRIB, "GL_CURRENT_VERTEX_ATTRIB is not equal to _GL_CURRENT_VERTEX_ATTRIB");
    static_assert(GL_VERTEX_PROGRAM_POINT_SIZE == _GL_VERTEX_PROGRAM_POINT_SIZE, "GL_VERTEX_PROGRAM_POINT_SIZE is not equal to _GL_VERTEX_PROGRAM_POINT_SIZE");
    static_assert(GL_VERTEX_ATTRIB_ARRAY_POINTER == _GL_VERTEX_ATTRIB_ARRAY_POINTER, "GL_VERTEX_ATTRIB_ARRAY_POINTER is not equal to _GL_VERTEX_ATTRIB_ARRAY_POINTER");
    static_assert(GL_STENCIL_BACK_FUNC == _GL_STENCIL_BACK_FUNC, "GL_STENCIL_BACK_FUNC is not equal to _GL_STENCIL_BACK_FUNC");
    static_assert(GL_STENCIL_BACK_FAIL == _GL_STENCIL_BACK_FAIL, "GL_STENCIL_BACK_FAIL is not equal to _GL_STENCIL_BACK_FAIL");
    static_assert(GL_STENCIL_BACK_PASS_DEPTH_FAIL == _GL_STENCIL_BACK_PASS_DEPTH_FAIL, "GL_STENCIL_BACK_PASS_DEPTH_FAIL is not equal to _GL_STENCIL_BACK_PASS_DEPTH_FAIL");
    static_assert(GL_STENCIL_BACK_PASS_DEPTH_PASS == _GL_STENCIL_BACK_PASS_DEPTH_PASS, "GL_STENCIL_BACK_PASS_DEPTH_PASS is not equal to _GL_STENCIL_BACK_PASS_DEPTH_PASS");
    static_assert(GL_MAX_DRAW_BUFFERS == _GL_MAX_DRAW_BUFFERS, "GL_MAX_DRAW_BUFFERS is not equal to _GL_MAX_DRAW_BUFFERS");
}
#pragma endregion

#pragma region RANDOM_STUFF13
#define GL_DRAW_BUFFER0 0x8825
#define GL_DRAW_BUFFER1 0x8826
#define GL_DRAW_BUFFER2 0x8827
#define GL_DRAW_BUFFER3 0x8828
#define GL_DRAW_BUFFER4 0x8829
#define GL_DRAW_BUFFER5 0x882A
#define GL_DRAW_BUFFER6 0x882B
#define GL_DRAW_BUFFER7 0x882C
#define GL_DRAW_BUFFER8 0x882D
#define GL_DRAW_BUFFER9 0x882E
#define GL_DRAW_BUFFER10 0x882F
#define GL_DRAW_BUFFER11 0x8830
#define GL_DRAW_BUFFER12 0x8831
#define GL_DRAW_BUFFER13 0x8832
#define GL_DRAW_BUFFER14 0x8833
#define GL_DRAW_BUFFER15 0x8834
#define GL_BLEND_EQUATION_ALPHA 0x883D
#define GL_MAX_VERTEX_ATTRIBS 0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_MAX_TEXTURE_IMAGE_UNITS 0x8872
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_VERTEX_SHADER 0x8B31
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS 0x8B4A
#define GL_MAX_VARYING_FLOATS 0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_SHADER_TYPE 0x8B4F

    export constexpr int _GL_DRAW_BUFFER0 = 0x8825;
    export constexpr int _GL_DRAW_BUFFER1 = 0x8826;
    export constexpr int _GL_DRAW_BUFFER2 = 0x8827;
    export constexpr int _GL_DRAW_BUFFER3 = 0x8828;
    export constexpr int _GL_DRAW_BUFFER4 = 0x8829;
    export constexpr int _GL_DRAW_BUFFER5 = 0x882A;
    export constexpr int _GL_DRAW_BUFFER6 = 0x882B;
    export constexpr int _GL_DRAW_BUFFER7 = 0x882C;
    export constexpr int _GL_DRAW_BUFFER8 = 0x882D;
    export constexpr int _GL_DRAW_BUFFER9 = 0x882E;
    export constexpr int _GL_DRAW_BUFFER10 = 0x882F;
    export constexpr int _GL_DRAW_BUFFER11 = 0x8830;
    export constexpr int _GL_DRAW_BUFFER12 = 0x8831;
    export constexpr int _GL_DRAW_BUFFER13 = 0x8832;
    export constexpr int _GL_DRAW_BUFFER14 = 0x8833;
    export constexpr int _GL_DRAW_BUFFER15 = 0x8834;
    export constexpr int _GL_BLEND_EQUATION_ALPHA = 0x883D;
    export constexpr int _GL_MAX_VERTEX_ATTRIBS = 0x8869;
    export constexpr int _GL_VERTEX_ATTRIB_ARRAY_NORMALIZED = 0x886A;
    export constexpr int _GL_MAX_TEXTURE_IMAGE_UNITS = 0x8872;
    export constexpr int _GL_FRAGMENT_SHADER = 0x8B30;
    export constexpr int _GL_VERTEX_SHADER = 0x8B31;
    export constexpr int _GL_MAX_FRAGMENT_UNIFORM_COMPONENTS = 0x8B49;
    export constexpr int _GL_MAX_VERTEX_UNIFORM_COMPONENTS = 0x8B4A;
    export constexpr int _GL_MAX_VARYING_FLOATS = 0x8B4B;
    export constexpr int _GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS = 0x8B4C;
    export constexpr int _GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS = 0x8B4D;
    export constexpr int _GL_SHADER_TYPE = 0x8B4F;

consteval void Check_Random_Stuff13() {
    static_assert(GL_DRAW_BUFFER0 == _GL_DRAW_BUFFER0, "GL_DRAW_BUFFER0 is not equal to _GL_DRAW_BUFFER0");
    static_assert(GL_DRAW_BUFFER1 == _GL_DRAW_BUFFER1, "GL_DRAW_BUFFER1 is not equal to _GL_DRAW_BUFFER1");
    static_assert(GL_DRAW_BUFFER2 == _GL_DRAW_BUFFER2, "GL_DRAW_BUFFER2 is not equal to _GL_DRAW_BUFFER2");
    static_assert(GL_DRAW_BUFFER3 == _GL_DRAW_BUFFER3, "GL_DRAW_BUFFER3 is not equal to _GL_DRAW_BUFFER3");
    static_assert(GL_DRAW_BUFFER4 == _GL_DRAW_BUFFER4, "GL_DRAW_BUFFER4 is not equal to _GL_DRAW_BUFFER4");
    static_assert(GL_DRAW_BUFFER5 == _GL_DRAW_BUFFER5, "GL_DRAW_BUFFER5 is not equal to _GL_DRAW_BUFFER5");
    static_assert(GL_DRAW_BUFFER6 == _GL_DRAW_BUFFER6, "GL_DRAW_BUFFER6 is not equal to _GL_DRAW_BUFFER6");
    static_assert(GL_DRAW_BUFFER7 == _GL_DRAW_BUFFER7, "GL_DRAW_BUFFER7 is not equal to _GL_DRAW_BUFFER7");
    static_assert(GL_DRAW_BUFFER8 == _GL_DRAW_BUFFER8, "GL_DRAW_BUFFER8 is not equal to _GL_DRAW_BUFFER8");
    static_assert(GL_DRAW_BUFFER9 == _GL_DRAW_BUFFER9, "GL_DRAW_BUFFER9 is not equal to _GL_DRAW_BUFFER9");
    static_assert(GL_DRAW_BUFFER10 == _GL_DRAW_BUFFER10, "GL_DRAW_BUFFER10 is not equal to _GL_DRAW_BUFFER10");
    static_assert(GL_DRAW_BUFFER11 == _GL_DRAW_BUFFER11, "GL_DRAW_BUFFER11 is not equal to _GL_DRAW_BUFFER11");
    static_assert(GL_DRAW_BUFFER12 == _GL_DRAW_BUFFER12, "GL_DRAW_BUFFER12 is not equal to _GL_DRAW_BUFFER12");
    static_assert(GL_DRAW_BUFFER13 == _GL_DRAW_BUFFER13, "GL_DRAW_BUFFER13 is not equal to _GL_DRAW_BUFFER13");
    static_assert(GL_DRAW_BUFFER14 == _GL_DRAW_BUFFER14, "GL_DRAW_BUFFER14 is not equal to _GL_DRAW_BUFFER14");
    static_assert(GL_DRAW_BUFFER15 == _GL_DRAW_BUFFER15, "GL_DRAW_BUFFER15 is not equal to _GL_DRAW_BUFFER15");
    static_assert(GL_BLEND_EQUATION_ALPHA == _GL_BLEND_EQUATION_ALPHA, "GL_BLEND_EQUATION ALPHA is not equal to _GL_BLEND_EQUATION_ALPHA");
    static_assert(GL_MAX_VERTEX_ATTRIBS == _GL_MAX_VERTEX_ATTRIBS, "GL_MAX_VERTEX_ATTRIBS is not equal to _GL_MAX_VERTEX_ATTRIBS");
    static_assert(GL_VERTEX_ATTRIB_ARRAY_NORMALIZED == _GL_VERTEX_ATTRIB_ARRAY_NORMALIZED, "GL_VERTEX_ATTRIB_ARRAY_NORMALIZED is not equal to _GL_VERTEX_ATTRIB_ARRAY_NORMALIZED");
    static_assert(GL_MAX_TEXTURE_IMAGE_UNITS == _GL_MAX_TEXTURE_IMAGE_UNITS, "GL_MAX_TEXTURE_IMAGE_UNITS is not equal to _GL_MAX_TEXTURE_IMAGE_UNITS");
    static_assert(GL_FRAGMENT_SHADER == _GL_FRAGMENT_SHADER, "GL_FRAGMENT_SHADER is not equal to _GL_FRAGMENT_SHADER");
    static_assert(GL_VERTEX_SHADER == _GL_VERTEX_SHADER, "GL_VERTEX_SHADER is not equal to _GL_VERTEX_SHADER");
    static_assert(GL_MAX_FRAGMENT_UNIFORM_COMPONENTS == _GL_MAX_FRAGMENT_UNIFORM_COMPONENTS, "GL_MAX_FRAGMENT_UNIFORM_COMPONENTS is not equal to _GL_MAX_FRAGMENT_UNIFORM_COMPONENTS");
    static_assert(GL_MAX_VERTEX_UNIFORM_COMPONENTS == _GL_MAX_VERTEX_UNIFORM_COMPONENTS, "GL_MAX_VERTEX_UNIFORM_COMPONENTS is not equal to _GL_MAX_VERTEX_UNIFORM_COMPONENTS");
    static_assert(GL_MAX_VARYING_FLOATS == _GL_MAX_VARYING_FLOATS, "GL_MAX_VARYING_FLOATS is not equal to _GL_MAX_VARYING_FLOATS");
    static_assert(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS == _GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS, "GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS is not equal to _GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS");
    static_assert(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS == _GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, "GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS is not equal to _GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS");
    static_assert(GL_SHADER_TYPE == _GL_SHADER_TYPE, "GL_SHADER_TYPE is not equal to _GL_SHADER_TYPE");
}

#pragma endregion

#pragma region RANDOM_STUFF14
#define GL_FLOAT_VEC2 0x8B50
#define GL_FLOAT_VEC3 0x8B51
#define GL_FLOAT_VEC4 0x8B52
#define GL_INT_VEC2 0x8B53
#define GL_INT_VEC3 0x8B54
#define GL_INT_VEC4 0x8B55
#define GL_BOOL 0x8B56
#define GL_BOOL_VEC2 0x8B57
#define GL_BOOL_VEC3 0x8B58
#define GL_BOOL_VEC4 0x8B59
#define GL_FLOAT_MAT2 0x8B5A
#define GL_FLOAT_MAT3 0x8B5B
#define GL_FLOAT_MAT4 0x8B5C
#define GL_SAMPLER_1D 0x8B5D
#define GL_SAMPLER_2D 0x8B5E
#define GL_SAMPLER_3D 0x8B5F
#define GL_SAMPLER_CUBE 0x8B60
#define GL_SAMPLER_1D_SHADOW 0x8B61
#define GL_SAMPLER_2D_SHADOW 0x8B62

    export constexpr int _GL_FLOAT_VEC2 = 0x8B50;
    export constexpr int _GL_FLOAT_VEC3 = 0x8B51;
    export constexpr int _GL_FLOAT_VEC4 = 0x8B52;
    export constexpr int _GL_INT_VEC2 = 0x8B53;
    export constexpr int _GL_INT_VEC3 = 0x8B54;
    export constexpr int _GL_INT_VEC4 = 0x8B55;
    export constexpr int _GL_BOOL = 0x8B56;
    export constexpr int _GL_BOOL_VEC2 = 0x8B57;
    export constexpr int _GL_BOOL_VEC3 = 0x8B58;
    export constexpr int _GL_BOOL_VEC4 = 0x8B59;
    export constexpr int _GL_FLOAT_MAT2 = 0x8B5A;
    export constexpr int _GL_FLOAT_MAT3 = 0x8B5B;
    export constexpr int _GL_FLOAT_MAT4 = 0x8B5C;
    export constexpr int _GL_SAMPLER_1D = 0x8B5D;
    export constexpr int _GL_SAMPLER_2D = 0x8B5E;
    export constexpr int _GL_SAMPLER_3D = 0x8B5F;
    export constexpr int _GL_SAMPLER_CUBE = 0x8B60;
    export constexpr int _GL_SAMPLER_1D_SHADOW = 0x8B61;
    export constexpr int _GL_SAMPLER_2D_SHADOW = 0x8B62;

consteval void Check_Random_Stuff14() {
    static_assert(GL_FLOAT_VEC2 == _GL_FLOAT_VEC2, "GL_FLOAT_VEC2 is not equal to _GL_FLOAT_VEC2");
    static_assert(GL_FLOAT_VEC3 == _GL_FLOAT_VEC3, "GL_FLOAT_VEC3 is not equal to _GL_FLOAT_VEC3");
    static_assert(GL_FLOAT_VEC4 == _GL_FLOAT_VEC4, "GL_FLOAT_VEC4 is not equal to _GL_FLOAT_VEC4");
    static_assert(GL_INT_VEC2 == _GL_INT_VEC2, "GL_INT_VEC2 is not equal to _GL_INT_VEC2");
    static_assert(GL_INT_VEC3 == _GL_INT_VEC3, "GL_INT_VEC3 is not equal to _GL_INT_VEC3");
    static_assert(GL_INT_VEC4 == _GL_INT_VEC4, "GL_INT_VEC4 is not equal to _GL_INT_VEC4");
    static_assert(GL_BOOL == _GL_BOOL, "GL_BOOL is not equal to _GL_BOOL");
    static_assert(GL_BOOL_VEC2 == _GL_BOOL_VEC2, "GL_BOOL_VEC2 is not equal to _GL_BOOL_VEC2");
    static_assert(GL_BOOL_VEC3 == _GL_BOOL_VEC3, "GL_BOOL_VEC3 is not equal to _GL_BOOL_VEC3");
    static_assert(GL_BOOL_VEC4 == _GL_BOOL_VEC4, "GL_BOOL_VEC4 is not equal to _GL_BOOL_VEC4");
    static_assert(GL_FLOAT_MAT2 == _GL_FLOAT_MAT2, "GL_FLOAT_MAT2 is not equal to _GL_FLOAT_MAT2");
    static_assert(GL_FLOAT_MAT3 == _GL_FLOAT_MAT3, "GL_FLOAT_MAT3 is not equal to _GL_FLOAT_MAT3");
    static_assert(GL_FLOAT_MAT4 == _GL_FLOAT_MAT4, "GL_FLOAT_MAT4 is not equal to _GL_FLOAT_MAT4");
    static_assert(GL_SAMPLER_1D == _GL_SAMPLER_1D, "GL_SAMPLER_1D is not equal to _GL_SAMPLER_1D");
    static_assert(GL_SAMPLER_2D == _GL_SAMPLER_2D, "GL_SAMPLER_2D is not equal to _GL_SAMPLER_2D");
    static_assert(GL_SAMPLER_3D == _GL_SAMPLER_3D, "GL_SAMPLER_3D is not equal to _GL_SAMPLER_3D");
    static_assert(GL_SAMPLER_CUBE == _GL_SAMPLER_CUBE, "GL_SAMPLER_CUBE is not equal to _GL_SAMPLER_CUBE");
    static_assert(GL_SAMPLER_1D_SHADOW == _GL_SAMPLER_1D_SHADOW, "GL_SAMPLER_1D_SHADOW is not equal to _GL_SAMPLER_1D_SHADOW");
    static_assert(GL_SAMPLER_2D_SHADOW == _GL_SAMPLER_2D_SHADOW, "GL_SAMPLER_2D_SHADOW is not equal to _GL_SAMPLER_2D_SHADOW");
}
#pragma endregion

#pragma region RANDOM_STUFF15
#define GL_DELETE_STATUS 0x8B80
#define GL_COMPILE_STATUS 0x8B81
#define GL_LINK_STATUS 0x8B82
#define GL_VALIDATE_STATUS 0x8B83
#define GL_INFO_LOG_LENGTH 0x8B84
#define GL_ATTACHED_SHADERS 0x8B85
#define GL_ACTIVE_UNIFORMS 0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH 0x8B87
#define GL_SHADER_SOURCE_LENGTH 0x8B88
#define GL_ACTIVE_ATTRIBUTES 0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH 0x8B8A
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#define GL_SHADING_LANGUAGE_VERSION 0x8B8C
#define GL_CURRENT_PROGRAM 0x8B8D
#define GL_POINT_SPRITE_COORD_ORIGIN 0x8CA0
#define GL_LOWER_LEFT 0x8CA1
#define GL_UPPER_LEFT 0x8CA2
#define GL_STENCIL_BACK_REF 0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK 0x8CA4
#define GL_STENCIL_BACK_WRITEMASK 0x8CA5
#define GL_PIXEL_PACK_BUFFER 0x88EB
#define GL_PIXEL_UNPACK_BUFFER 0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING 0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING 0x88EF

    export constexpr int _GL_DELETE_STATUS = 0x8B80;
    export constexpr int _GL_COMPILE_STATUS = 0x8B81;
    export constexpr int _GL_LINK_STATUS = 0x8B82;
    export constexpr int _GL_VALIDATE_STATUS = 0x8B83;
    export constexpr int _GL_INFO_LOG_LENGTH = 0x8B84;
    export constexpr int _GL_ATTACHED_SHADERS = 0x8B85;
    export constexpr int _GL_ACTIVE_UNIFORMS = 0x8B86;
    export constexpr int _GL_ACTIVE_UNIFORM_MAX_LENGTH = 0x8B87;
    export constexpr int _GL_SHADER_SOURCE_LENGTH = 0x8B88;
    export constexpr int _GL_ACTIVE_ATTRIBUTES = 0x8B89;
    export constexpr int _GL_ACTIVE_ATTRIBUTE_MAX_LENGTH = 0x8B8A;
    export constexpr int _GL_FRAGMENT_SHADER_DERIVATIVE_HINT = 0x8B8B;
    export constexpr int _GL_SHADING_LANGUAGE_VERSION = 0x8B8C;
    export constexpr int _GL_CURRENT_PROGRAM = 0x8B8D;
    export constexpr int _GL_POINT_SPRITE_COORD_ORIGIN = 0x8CA0;
    export constexpr int _GL_LOWER_LEFT = 0x8CA1;
    export constexpr int _GL_UPPER_LEFT = 0x8CA2;
    export constexpr int _GL_STENCIL_BACK_REF = 0x8CA3;
    export constexpr int _GL_STENCIL_BACK_VALUE_MASK = 0x8CA4;
    export constexpr int _GL_STENCIL_BACK_WRITEMASK = 0x8CA5;
    export constexpr int _GL_PIXEL_PACK_BUFFER = 0x88EB;
    export constexpr int _GL_PIXEL_UNPACK_BUFFER = 0x88EC;
    export constexpr int _GL_PIXEL_PACK_BUFFER_BINDING = 0x88ED;
    export constexpr int _GL_PIXEL_UNPACK_BUFFER_BINDING = 0x88EF;

consteval void Check_Random_Stuff15() {
    static_assert(GL_DELETE_STATUS == _GL_DELETE_STATUS, "GL_DELETE_STATUS is not equal to _GL_DELETE_STATUS");
    static_assert(GL_COMPILE_STATUS == _GL_COMPILE_STATUS, "GL_COMPILE_STATUS is not equal to _GL_COMPILE_STATUS");
    static_assert(GL_LINK_STATUS == _GL_LINK_STATUS, "GL_LINK_STATUS is not equal to _GL_LINK_STATUS");
    static_assert(GL_VALIDATE_STATUS == _GL_VALIDATE_STATUS, "GL_VALIDATE_STATUS is not equal to _GL_VALIDATE_STATUS");
    static_assert(GL_INFO_LOG_LENGTH == _GL_INFO_LOG_LENGTH, "GL_INFO_LOG_LENGTH is not equal to _GL_INFO_LOG_LENGTH");
    static_assert(GL_ATTACHED_SHADERS == _GL_ATTACHED_SHADERS, "GL_ATTACHED_SHADERS is not equal to _GL_ATTACHED_SHADERS");
    static_assert(GL_ACTIVE_UNIFORMS == _GL_ACTIVE_UNIFORMS, "GL_ACTIVE_UNIFORMS is not equal to _GL_ACTIVE_UNIFORMS");
    static_assert(GL_ACTIVE_UNIFORM_MAX_LENGTH == _GL_ACTIVE_UNIFORM_MAX_LENGTH, "GL_ACTIVE_UNIFORM_MAX_LENGTH is not equal to _GL_ACTIVE_UNIFORM_MAX_LENGTH");
    static_assert(GL_SHADER_SOURCE_LENGTH == _GL_SHADER_SOURCE_LENGTH, "GL_SHADER_SOURCE_LENGTH is not equal to _GL_SHADER_SOURCE_LENGTH");
    static_assert(GL_ACTIVE_ATTRIBUTES == _GL_ACTIVE_ATTRIBUTES, "GL_ACTIVE_ATTRIBUTES is not equal to _GL_ACTIVE_ATTRIBUTES");
    static_assert(GL_ACTIVE_ATTRIBUTE_MAX_LENGTH == _GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, "GL_ACTIVE_ATTRIBUTE_MAX_LENGTH is not equal to _GL_ACTIVE_ATTRIBUTE_MAX_LENGTH");
    static_assert(GL_FRAGMENT_SHADER_DERIVATIVE_HINT == _GL_FRAGMENT_SHADER_DERIVATIVE_HINT, "GL_FRAGMENT_SHADER_DERIVATIVE_HINT is not equal to _GL_FRAGMENT_SHADER_DERIVATIVE_HINT");
    static_assert(GL_SHADING_LANGUAGE_VERSION == _GL_SHADING_LANGUAGE_VERSION, "GL_SHADING_LANGUAGE_VERSION is not equal to _GL_SHADING_LANGUAGE_VERSION");
    static_assert(GL_CURRENT_PROGRAM == _GL_CURRENT_PROGRAM, "GL_CURRENT_PROGRAM is not equal to _GL_CURRENT_PROGRAM");
    static_assert(GL_POINT_SPRITE_COORD_ORIGIN == _GL_POINT_SPRITE_COORD_ORIGIN, "GL_POINT_SPRITE_COORD_ORIGIN is not equal to _GL_POINT_SPRITE_COORD_ORIGIN");
    static_assert(GL_LOWER_LEFT == _GL_LOWER_LEFT, "GL_LOWER_LEFT is not equal to _GL_LOWER_LEFT");
    static_assert(GL_UPPER_LEFT == _GL_UPPER_LEFT, "GL_UPPER_LEFT is not equal to _GL_UPPER_LEFT");
    static_assert(GL_STENCIL_BACK_REF == _GL_STENCIL_BACK_REF, "GL_STENCIL_BACK_REF is not equal to _GL_STENCIL_BACK_REF");
    static_assert(GL_STENCIL_BACK_VALUE_MASK == _GL_STENCIL_BACK_VALUE_MASK, "GL_STENCIL_BACK_VALUE_MASK is not equal to _GL_STENCIL_BACK_VALUE_MASK");
    static_assert(GL_STENCIL_BACK_WRITEMASK == _GL_STENCIL_BACK_WRITEMASK, "GL_STENCIL_BACK_WRITEMASK is not equal to _GL_STENCIL_BACK_WRITEMASK");
    static_assert(GL_PIXEL_PACK_BUFFER == _GL_PIXEL_PACK_BUFFER, "GL_PIXEL_PACK_BUFFER is not equal to _GL_PIXEL_PACK_BUFFER");
    static_assert(GL_PIXEL_UNPACK_BUFFER == _GL_PIXEL_UNPACK_BUFFER, "GL_PIXEL_UNPACK_BUFFER is not equal to _GL_PIXEL_UNPACK_BUFFER");
    static_assert(GL_PIXEL_PACK_BUFFER_BINDING == _GL_PIXEL_PACK_BUFFER_BINDING, "GL_PIXEL_PACK_BUFFER_BINDING is not equal to _GL_PIXEL_PACK_BUFFER_BINDING");
    static_assert(GL_PIXEL_UNPACK_BUFFER_BINDING == _GL_PIXEL_UNPACK_BUFFER_BINDING, "GL_PIXEL_UNPACK_BUFFER_BINDING is not equal to _GL_PIXEL_UNPACK_BUFFER_BINDING");
}
#pragma endregion

#pragma region RANDOM_STUFF16
#define GL_FLOAT_MAT2x3 0x8B65
#define GL_FLOAT_MAT2x4 0x8B66
#define GL_FLOAT_MAT3x2 0x8B67
#define GL_FLOAT_MAT3x4 0x8B68
#define GL_FLOAT_MAT4x2 0x8B69
#define GL_FLOAT_MAT4x3 0x8B6A
#define GL_SRGB 0x8C40
#define GL_SRGB8 0x8C41
#define GL_SRGB_ALPHA 0x8C42
#define GL_SRGB8_ALPHA8 0x8C43
#define GL_COMPRESSED_SRGB 0x8C48
#define GL_COMPRESSED_SRGB_ALPHA 0x8C49
#define GL_COMPARE_REF_TO_TEXTURE 0x884E
#define GL_CLIP_DISTANCE0 0x3000
#define GL_CLIP_DISTANCE1 0x3001
#define GL_CLIP_DISTANCE2 0x3002
#define GL_CLIP_DISTANCE3 0x3003
#define GL_CLIP_DISTANCE4 0x3004
#define GL_CLIP_DISTANCE5 0x3005
#define GL_CLIP_DISTANCE6 0x3006
#define GL_CLIP_DISTANCE7 0x3007
#define GL_MAX_CLIP_DISTANCES 0x0D32
#define GL_MAJOR_VERSION 0x821B
#define GL_MINOR_VERSION 0x821C
#define GL_NUM_EXTENSIONS 0x821D
#define GL_CONTEXT_FLAGS 0x821E
#define GL_COMPRESSED_RED 0x8225
#define GL_COMPRESSED_RG 0x8226
#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT 0x00000001

    export constexpr int _GL_FLOAT_MAT2x3 = 0x8B65;
    export constexpr int _GL_FLOAT_MAT2x4 = 0x8B66;
    export constexpr int _GL_FLOAT_MAT3x2 = 0x8B67;
    export constexpr int _GL_FLOAT_MAT3x4 = 0x8B68;
    export constexpr int _GL_FLOAT_MAT4x2 = 0x8B69;
    export constexpr int _GL_FLOAT_MAT4x3 = 0x8B6A;
    export constexpr int _GL_SRGB = 0x8C40;
    export constexpr int _GL_SRGB8 = 0x8C41;
    export constexpr int _GL_SRGB_ALPHA = 0x8C42;
    export constexpr int _GL_SRGB8_ALPHA8 = 0x8C43;
    export constexpr int _GL_COMPRESSED_SRGB = 0x8C48;
    export constexpr int _GL_COMPRESSED_SRGB_ALPHA = 0x8C49;
    export constexpr int _GL_COMPARE_REF_TO_TEXTURE = 0x884E;
    export constexpr int _GL_CLIP_DISTANCE0 = 0x3000;
    export constexpr int _GL_CLIP_DISTANCE1 = 0x3001;
    export constexpr int _GL_CLIP_DISTANCE2 = 0x3002;
    export constexpr int _GL_CLIP_DISTANCE3 = 0x3003;
    export constexpr int _GL_CLIP_DISTANCE4 = 0x3004;
    export constexpr int _GL_CLIP_DISTANCE5 = 0x3005;
    export constexpr int _GL_CLIP_DISTANCE6 = 0x3006;
    export constexpr int _GL_CLIP_DISTANCE7 = 0x3007;
    export constexpr int _GL_MAX_CLIP_DISTANCES = 0x0D32;
    export constexpr int _GL_MAJOR_VERSION = 0x821B;
    export constexpr int _GL_MINOR_VERSION = 0x821C;
    export constexpr int _GL_NUM_EXTENSIONS = 0x821D;
    export constexpr int _GL_CONTEXT_FLAGS = 0x821E;
    export constexpr int _GL_COMPRESSED_RED = 0x8225;
    export constexpr int _GL_COMPRESSED_RG = 0x8226;
    export constexpr int _GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT = 0x00000001;

consteval void Check_Random_Stuff16() {
    static_assert(GL_FLOAT_MAT2x3 == _GL_FLOAT_MAT2x3, "GL_FLOAT_MAT2x3 is not equal to _GL_FLOAT_MAT2x3");
    static_assert(GL_FLOAT_MAT2x4 == _GL_FLOAT_MAT2x4, "GL_FLOAT_MAT2x4 is not equal to _GL_FLOAT_MAT2x4");
    static_assert(GL_FLOAT_MAT3x2 == _GL_FLOAT_MAT3x2, "GL_FLOAT_MAT3x2 is not equal to _GL_FLOAT_MAT3x2");
    static_assert(GL_FLOAT_MAT3x4 == _GL_FLOAT_MAT3x4, "GL_FLOAT_MAT3x4 is not equal to _GL_FLOAT_MAT3x4");
    static_assert(GL_FLOAT_MAT4x2 == _GL_FLOAT_MAT4x2, "GL_FLOAT_MAT4x2 is not equal to _GL_FLOAT_MAT4x2");
    static_assert(GL_FLOAT_MAT4x3 == _GL_FLOAT_MAT4x3, "GL_FLOAT_MAT4x3 is not equal to _GL_FLOAT_MAT4x3");
    static_assert(GL_SRGB == _GL_SRGB, "GL_SRGB is not equal to _GL_SRGB");
    static_assert(GL_SRGB8 == _GL_SRGB8, "GL_SRGB8 is not equal to _GL_SRGB8");
    static_assert(GL_SRGB_ALPHA == _GL_SRGB_ALPHA, "GL_SRGB_ALPHA is not equal to _GL_SRGB_ALPHA");
    static_assert(GL_SRGB8_ALPHA8 == _GL_SRGB8_ALPHA8, "GL_SRGB8_ALPHA8 is not equal to _GL_SRGB8_ALPHA8");
    static_assert(GL_COMPRESSED_SRGB == _GL_COMPRESSED_SRGB, "GL_COMPRESSED_SRGB is not equal to _GL_COMPRESSED_SRGB");
    static_assert(GL_COMPRESSED_SRGB_ALPHA == _GL_COMPRESSED_SRGB_ALPHA, "GL_COMPRESSED_SRGB_ALPHA is not equal to _GL_COMPRESSED_SRGB_ALPHA");
    static_assert(GL_COMPARE_REF_TO_TEXTURE == _GL_COMPARE_REF_TO_TEXTURE, "GL_COMPARE_REF_TO_TEXTURE is not equal to _GL_COMPARE_REF_TO_TEXTURE");
    static_assert(GL_CLIP_DISTANCE0 == _GL_CLIP_DISTANCE0, "GL_CLIP_DISTANCE0 is not equal to _GL_CLIP_DISTANCE0");
    static_assert(GL_CLIP_DISTANCE1 == _GL_CLIP_DISTANCE1, "GL_CLIP_DISTANCE1 is not equal to _GL_CLIP_DISTANCE1");
    static_assert(GL_CLIP_DISTANCE2 == _GL_CLIP_DISTANCE2, "GL_CLIP_DISTANCE2 is not equal to _GL_CLIP_DISTANCE2");
    static_assert(GL_CLIP_DISTANCE3 == _GL_CLIP_DISTANCE3, "GL_CLIP_DISTANCE3 is not equal to _GL_CLIP_DISTANCE3");
    static_assert(GL_CLIP_DISTANCE4 == _GL_CLIP_DISTANCE4, "GL_CLIP_DISTANCE4 is not equal to _GL_CLIP_DISTANCE4");
    static_assert(GL_CLIP_DISTANCE5 == _GL_CLIP_DISTANCE5, "GL_CLIP_DISTANCE5 is not equal to _GL_CLIP_DISTANCE5");
    static_assert(GL_CLIP_DISTANCE6 == _GL_CLIP_DISTANCE6, "GL_CLIP_DISTANCE6 is not equal to _GL_CLIP_DISTANCE6");
    static_assert(GL_CLIP_DISTANCE7 == _GL_CLIP_DISTANCE7, "GL_CLIP_DISTANCE7 is not equal to _GL_CLIP_DISTANCE7");
    static_assert(GL_MAX_CLIP_DISTANCES == _GL_MAX_CLIP_DISTANCES, "GL_MAX_CLIP_DISTANCES is not equal to _GL_MAX_CLIP_DISTANCES");
    static_assert(GL_MAJOR_VERSION == _GL_MAJOR_VERSION, "GL_MAJOR_VERSION is not equal to _GL_MAJOR_VERSION");
    static_assert(GL_MINOR_VERSION == _GL_MINOR_VERSION, "GL_MINOR_VERSION is not equal to _GL_MINOR_VERSION");
    static_assert(GL_NUM_EXTENSIONS == _GL_NUM_EXTENSIONS, "GL_NUM_EXTENSIONS is not equal to _GL_NUM_EXTENSIONS");
    static_assert(GL_CONTEXT_FLAGS == _GL_CONTEXT_FLAGS, "GL_CONTEXT_FLAGS is not equal to _GL_CONTEXT_FLAGS");
    static_assert(GL_COMPRESSED_RED == _GL_COMPRESSED_RED, "GL_COMPRESSED_RED is not equal to _GL_COMPRESSED_RED");
    static_assert(GL_COMPRESSED_RG == _GL_COMPRESSED_RG, "GL_COMPRESSED_RG is not equal to _GL_COMPRESSED_RG");
    static_assert(GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT == _GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT, "GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT is not equal to _GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT");
}
#pragma endregion

#pragma region RANDOM_STUFF17
#define GL_RGBA32F 0x8814
#define GL_RGB32F 0x8815
#define GL_RGBA16F 0x881A
#define GL_RGB16F 0x881B
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER 0x88FD
#define GL_MAX_ARRAY_TEXTURE_LAYERS 0x88FF
#define GL_MIN_PROGRAM_TEXEL_OFFSET 0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET 0x8905
#define GL_CLAMP_READ_COLOR 0x891C
#define GL_FIXED_ONLY 0x891D
#define GL_MAX_VARYING_COMPONENTS 0x8B4B
#define GL_TEXTURE_1D_ARRAY 0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY 0x8C19
#define GL_TEXTURE_2D_ARRAY 0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY 0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY 0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY 0x8C1D
#define GL_R11F_G11F_B10F 0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV 0x8C3B
#define GL_RGB9_E5 0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV 0x8C3E
#define GL_TEXTURE_SHARED_SIZE 0x8C3F
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH 0x8C76
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE 0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS 0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START 0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE 0x8C85
#define GL_PRIMITIVES_GENERATED 0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN 0x8C88
#define GL_RASTERIZER_DISCARD 0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
#define GL_INTERLEAVED_ATTRIBS 0x8C8C
#define GL_SEPARATE_ATTRIBS 0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER 0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING 0x8C8F

    export constexpr int _GL_RGBA32F = 0x8814;
    export constexpr int _GL_RGB32F = 0x8815;
    export constexpr int _GL_RGBA16F = 0x881A;
    export constexpr int _GL_RGB16F = 0x881B;
    export constexpr int _GL_VERTEX_ATTRIB_ARRAY_INTEGER = 0x88FD;
    export constexpr int _GL_MAX_ARRAY_TEXTURE_LAYERS = 0x88FF;
    export constexpr int _GL_MIN_PROGRAM_TEXEL_OFFSET = 0x8904;
    export constexpr int _GL_MAX_PROGRAM_TEXEL_OFFSET = 0x8905;
    export constexpr int _GL_CLAMP_READ_COLOR = 0x891C;
    export constexpr int _GL_FIXED_ONLY = 0x891D;
    export constexpr int _GL_MAX_VARYING_COMPONENTS = 0x8B4B;
    export constexpr int _GL_TEXTURE_1D_ARRAY = 0x8C18;
    export constexpr int _GL_PROXY_TEXTURE_1D_ARRAY = 0x8C19;
    export constexpr int _GL_TEXTURE_2D_ARRAY = 0x8C1A;
    export constexpr int _GL_PROXY_TEXTURE_2D_ARRAY = 0x8C1B;
    export constexpr int _GL_TEXTURE_BINDING_1D_ARRAY = 0x8C1C;
    export constexpr int _GL_TEXTURE_BINDING_2D_ARRAY = 0x8C1D;
    export constexpr int _GL_R11F_G11F_B10F = 0x8C3A;
    export constexpr int _GL_UNSIGNED_INT_10F_11F_11F_REV = 0x8C3B;
    export constexpr int _GL_RGB9_E5 = 0x8C3D;
    export constexpr int _GL_UNSIGNED_INT_5_9_9_9_REV = 0x8C3E;
    export constexpr int _GL_TEXTURE_SHARED_SIZE = 0x8C3F;
    export constexpr int _GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH = 0x8C76;
    export constexpr int _GL_TRANSFORM_FEEDBACK_BUFFER_MODE = 0x8C7F;
    export constexpr int _GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS = 0x8C80;
    export constexpr int _GL_TRANSFORM_FEEDBACK_VARYINGS = 0x8C83;
    export constexpr int _GL_TRANSFORM_FEEDBACK_BUFFER_START = 0x8C84;
    export constexpr int _GL_TRANSFORM_FEEDBACK_BUFFER_SIZE = 0x8C85;
    export constexpr int _GL_PRIMITIVES_GENERATED = 0x8C87;
    export constexpr int _GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN = 0x8C88;
    export constexpr int _GL_RASTERIZER_DISCARD = 0x8C89;
    export constexpr int _GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS = 0x8C8A;
    export constexpr int _GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS = 0x8C8B;
    export constexpr int _GL_INTERLEAVED_ATTRIBS = 0x8C8C;
    export constexpr int _GL_SEPARATE_ATTRIBS = 0x8C8D;
    export constexpr int _GL_TRANSFORM_FEEDBACK_BUFFER = 0x8C8E;
    export constexpr int _GL_TRANSFORM_FEEDBACK_BUFFER_BINDING = 0x8C8F;

consteval void Check_Random_Stuff17() {
    static_assert(GL_RGBA32F == _GL_RGBA32F, "GL_RGBA32F is not equal to _GL_RGBA32F");
    static_assert(GL_RGB32F == _GL_RGB32F, "GL_RGB32F is not equal to _GL_RGB32F");
    static_assert(GL_RGBA16F == _GL_RGBA16F, "GL_RGBA16F is not equal to _GL_RGBA16F");
    static_assert(GL_RGB16F == _GL_RGB16F, "GL_RGB16F is not equal to _GL_RGB16F");
    static_assert(GL_VERTEX_ATTRIB_ARRAY_INTEGER == _GL_VERTEX_ATTRIB_ARRAY_INTEGER, "GL_VERTEX_ATTRIB_ARRAY_INTEGER is not equal to _GL_VERTEX_ATTRIB_ARRAY_INTEGER");
    static_assert(GL_MAX_ARRAY_TEXTURE_LAYERS == _GL_MAX_ARRAY_TEXTURE_LAYERS, "GL_MAX_ARRAY_TEXTURE_LAYERS is not equal to _GL_MAX_ARRAY_TEXTURE_LAYERS");
    static_assert(GL_MIN_PROGRAM_TEXEL_OFFSET == _GL_MIN_PROGRAM_TEXEL_OFFSET, "GL_MIN_PROGRAM_TEXEL_OFFSET is not equal to _GL_MIN_PROGRAM_TEXEL_OFFSET");
    static_assert(GL_MAX_PROGRAM_TEXEL_OFFSET == _GL_MAX_PROGRAM_TEXEL_OFFSET, "GL_MAX_PROGRAM_TEXEL_OFFSET is not equal to _GL_MAX_PROGRAM_TEXEL_OFFSET");
    static_assert(GL_CLAMP_READ_COLOR == _GL_CLAMP_READ_COLOR, "GL_CLAMP_READ_COLOR is not equal to _GL_CLAMP_READ_COLOR");
    static_assert(GL_FIXED_ONLY == _GL_FIXED_ONLY, "GL_FIXED_ONLY is not equal to _GL_FIXED_ONLY");
    static_assert(GL_MAX_VARYING_COMPONENTS == _GL_MAX_VARYING_COMPONENTS, "GL_MAX_VARYING_COMPONENTS is not equal to _GL_MAX_VARYING_COMPONENTS");
    static_assert(GL_TEXTURE_1D_ARRAY == _GL_TEXTURE_1D_ARRAY, "GL_TEXTURE_1D_ARRAY is not equal to _GL_TEXTURE_1D_ARRAY");
    static_assert(GL_PROXY_TEXTURE_1D_ARRAY == _GL_PROXY_TEXTURE_1D_ARRAY, "GL_PROXY_TEXTURE_1D_ARRAY is not equal to _GL_PROXY_TEXTURE_1D_ARRAY");
    static_assert(GL_TEXTURE_2D_ARRAY == _GL_TEXTURE_2D_ARRAY, "GL_TEXTURE_2D_ARRAY is not equal to _GL_TEXTURE_2D_ARRAY");
    static_assert(GL_PROXY_TEXTURE_2D_ARRAY == _GL_PROXY_TEXTURE_2D_ARRAY, "GL_PROXY_TEXTURE_2D_ARRAY is not equal to _GL_PROXY texture_2D_ARRAY");
    static_assert(GL_TEXTURE_BINDING_1D_ARRAY == _GL_TEXTURE_BINDING_1D_ARRAY, "GL_TEXTURE_BINDING_1D_ARRAY is not equal to _GL_TEXTURE_BINDING_1D_ARRAY");
    static_assert(GL_TEXTURE_BINDING_2D_ARRAY == _GL_TEXTURE_BINDING_2D_ARRAY, "GL_TEXTURE_BINDING_2D_ARRAY is not equal to _GL_TEXTURE_BINDING_2D_ARRAY");
    static_assert(GL_R11F_G11F_B10F == _GL_R11F_G11F_B10F, "GL_R11F_G11F_B10F is not equal to _GL_R11F_G11F_B10F");
    static_assert(GL_UNSIGNED_INT_10F_11F_11F_REV == _GL_UNSIGNED_INT_10F_11F_11F_REV, "GL_UNSIGNED_INT_10F_11F_11F_REV is not equal to _GL_UNSIGNED_INT_10F_11F_11F_REV");
    static_assert(GL_RGB9_E5 == _GL_RGB9_E5, "GL_RGB9_E5 is not equal to _GL_RGB9_E5");
    static_assert(GL_UNSIGNED_INT_5_9_9_9_REV == _GL_UNSIGNED_INT_5_9_9_9_REV, "GL_UNSIGNED_INT_5_9_9_9_REV is not equal to _GL_UNSIGNED_INT_5_9_9_9_REV");
    static_assert(GL_TEXTURE_SHARED_SIZE == _GL_TEXTURE_SHARED_SIZE, "GL_TEXTURE_SHARED_SIZE is not equal to _GL_TEXTURE_SHARED_SIZE");
    static_assert(GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH == _GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH, "GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH is not equal to _GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH");
    static_assert(GL_TRANSFORM_FEEDBACK_BUFFER_MODE == _GL_TRANSFORM_FEEDBACK_BUFFER_MODE, "GL_TRANSFORM_FEEDBACK_BUFFER_MODE is not equal to _GL_TRANSFORM_FEEDBACK_BUFFER_MODE");
    static_assert(GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS == _GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS, "GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS is not equal to _GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS");
    static_assert(GL_TRANSFORM_FEEDBACK_VARYINGS == _GL_TRANSFORM_FEEDBACK_VARYINGS, "GL_TRANSFORM_FEEDBACK_VARYINGS is not equal to _GL_TRANSFORM_FEEDBACK_VARYINGS");
    static_assert(GL_TRANSFORM_FEEDBACK_BUFFER_START == _GL_TRANSFORM_FEEDBACK_BUFFER_START, "GL_TRANSFORM_FEEDBACK_BUFFER_START is not equal to _GL_TRANSFORM_FEEDBACK_BUFFER_START");
    static_assert(GL_TRANSFORM_FEEDBACK_BUFFER_SIZE == _GL_TRANSFORM_FEEDBACK_BUFFER_SIZE, "GL_TRANSFORM_FEEDBACK_BUFFER_SIZE is not equal to _GL_TRANSFORM_FEEDBACK_BUFFER_SIZE");
    static_assert(GL_PRIMITIVES_GENERATED == _GL_PRIMITIVES_GENERATED, "GL_PRIMITIVES_GENERATED is not equal to _GL_PRIMITIVES_GENERATED");
    static_assert(GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN == _GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN, "GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN is not equal to _GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN");
    static_assert(GL_RASTERIZER_DISCARD == _GL_RASTERIZER_DISCARD, "GL_RASTERIZER_DISCARD is not equal to _GL_RASTERIZER_DISCARD");
    static_assert(GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS == _GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS, "GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS is not equal to _GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS");
    static_assert(GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS == _GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS, "GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS is not equal to _GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS");
    static_assert(GL_INTERLEAVED_ATTRIBS == _GL_INTERLEAVED_ATTRIBS, "GL_INTERLEAVED_ATTRIBS is not equal to _GL_INTERLEAVED_ATTRIBS");
    static_assert(GL_SEPARATE_ATTRIBS == _GL_SEPARATE_ATTRIBS, "GL_SEPARATE_ATTRIBS is not equal to _GL_SEPARATE_ATTRIBS");
    static_assert(GL_TRANSFORM_FEEDBACK_BUFFER == _GL_TRANSFORM_FEEDBACK_BUFFER, "GL_TRANSFORM_FEEDBACK_BUFFER is not equal to _GL_TRANSFORM_FEEDBACK_BUFFER");
    static_assert(GL_TRANSFORM_FEEDBACK_BUFFER_BINDING == _GL_TRANSFORM_FEEDBACK_BUFFER_BINDING, "GL_TRANSFORM_FEEDBACK_BUFFER_BINDING is not equal to _GL_TRANSFORM_FEEDBACK_BUFFER_BINDING");
}
#pragma endregion

#pragma region RANDOM_STUFF18
#define GL_RGBA32UI 0x8D70
#define GL_RGB32UI 0x8D71
#define GL_RGBA16UI 0x8D76
#define GL_RGB16UI 0x8D77
#define GL_RGBA8UI 0x8D7C
#define GL_RGB8UI 0x8D7D
#define GL_RGBA32I 0x8D82
#define GL_RGB32I 0x8D83
#define GL_RGBA16I 0x8D88
#define GL_RGB16I 0x8D89
#define GL_RGBA8I 0x8D8E
#define GL_RGB8I 0x8D8F
#define GL_RED_INTEGER 0x8D94
#define GL_GREEN_INTEGER 0x8D95
#define GL_BLUE_INTEGER 0x8D96
#define GL_RGB_INTEGER 0x8D98
#define GL_RGBA_INTEGER 0x8D99
#define GL_BGR_INTEGER 0x8D9A
#define GL_BGRA_INTEGER 0x8D9B
#define GL_SAMPLER_1D_ARRAY 0x8DC0
#define GL_SAMPLER_2D_ARRAY 0x8DC1
#define GL_SAMPLER_1D_ARRAY_SHADOW 0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW 0x8DC4
#define GL_SAMPLER_CUBE_SHADOW 0x8DC5

    export constexpr int _GL_RGBA32UI = 0x8D70;
    export constexpr int _GL_RGB32UI = 0x8D71;
    export constexpr int _GL_RGBA16UI = 0x8D76;
    export constexpr int _GL_RGB16UI = 0x8D77;
    export constexpr int _GL_RGBA8UI = 0x8D7C;
    export constexpr int _GL_RGB8UI = 0x8D7D;
    export constexpr int _GL_RGBA32I = 0x8D82;
    export constexpr int _GL_RGB32I = 0x8D83;
    export constexpr int _GL_RGBA16I = 0x8D88;
    export constexpr int _GL_RGB16I = 0x8D89;
    export constexpr int _GL_RGBA8I = 0x8D8E;
    export constexpr int _GL_RGB8I = 0x8D8F;
    export constexpr int _GL_RED_INTEGER = 0x8D94;
    export constexpr int _GL_GREEN_INTEGER = 0x8D95;
    export constexpr int _GL_BLUE_INTEGER = 0x8D96;
    export constexpr int _GL_RGB_INTEGER = 0x8D98;
    export constexpr int _GL_RGBA_INTEGER = 0x8D99;
    export constexpr int _GL_BGR_INTEGER = 0x8D9A;
    export constexpr int _GL_BGRA_INTEGER = 0x8D9B;
    export constexpr int _GL_SAMPLER_1D_ARRAY = 0x8DC0;
    export constexpr int _GL_SAMPLER_2D_ARRAY = 0x8DC1;
    export constexpr int _GL_SAMPLER_1D_ARRAY_SHADOW = 0x8DC3;
    export constexpr int _GL_SAMPLER_2D_ARRAY_SHADOW = 0x8DC4;
    export constexpr int _GL_SAMPLER_CUBE_SHADOW = 0x8DC5;

consteval void Check_Random_Stuff18() {
    static_assert(GL_RGBA32UI == _GL_RGBA32UI, "GL_RGBA32UI is not equal to _GL_RGBA32UI");
    static_assert(GL_RGB32UI == _GL_RGB32UI, "GL_RGB32UI is not equal to _GL_RGB32UI");
    static_assert(GL_RGBA16UI == _GL_RGBA16UI, "GL_RGBA16UI is not equal to _GL_RGBA16UI");
    static_assert(GL_RGB16UI == _GL_RGB16UI, "GL_RGB16UI is not equal to _GL_RGB16UI");
    static_assert(GL_RGBA8UI == _GL_RGBA8UI, "GL_RGBA8UI is not equal to _GL_RGBA8UI");
    static_assert(GL_RGB8UI == _GL_RGB8UI, "GL_RGB8UI is not equal to _GL_RGB8UI");
    static_assert(GL_RGBA32I == _GL_RGBA32I, "GL_RGBA32I is not equal to _GL_RGBA32I");
    static_assert(GL_RGB32I == _GL_RGB32I, "GL_RGB32I is not equal to _GL_RGB32I");
    static_assert(GL_RGBA16I == _GL_RGBA16I, "GL_RGBA16I is not equal to _GL_RGBA16I");
    static_assert(GL_RGB16I == _GL_RGB16I, "GL_RGB16I is not equal to _GL_RGB16I");
    static_assert(GL_RGBA8I == _GL_RGBA8I, "GL_RGBA8I is not equal to _GL_RGBA8I");
    static_assert(GL_RGB8I == _GL_RGB8I, "GL_RGB8I is not equal to _GL_RGB8I");
    static_assert(GL_RED_INTEGER == _GL_RED_INTEGER, "GL_RED_INTEGER is not equal to _GL_RED_INTEGER");
    static_assert(GL_GREEN_INTEGER == _GL_GREEN_INTEGER, "GL_GREEN_INTEGER is not equal to _GL_GREEN_INTEGER");
    static_assert(GL_BLUE_INTEGER == _GL_BLUE_INTEGER, "GL_BLUE_INTEGER is not equal to _GL_BLUE_INTEGER");
    static_assert(GL_RGB_INTEGER == _GL_RGB_INTEGER, "GL_RGB_INTEGER is not equal to _GL_RGB_INTEGER");
    static_assert(GL_RGBA_INTEGER == _GL_RGBA_INTEGER, "GL_RGBA_INTEGER is not equal to _GL_RGBA_INTEGER");
    static_assert(GL_BGR_INTEGER == _GL_BGR_INTEGER, "GL_BGR INTEGER is not equal to _GL_BGR_INTEGER");
    static_assert(GL_BGRA_INTEGER == _GL_BGRA_INTEGER, "GL_BGRA_INTEGER is not equal to _GL_BGRA_INTEGER");
    static_assert(GL_SAMPLER_1D_ARRAY == _GL_SAMPLER_1D_ARRAY, "GL_SAMPLER_1D_ARRAY is not equal to _GL_SAMPLER_1D_ARRAY");
    static_assert(GL_SAMPLER_2D_ARRAY == _GL_SAMPLER_2D_ARRAY, "GL_SAMPLER_2D_ARRAY is not equal to _GL_SAMPLER_2D_ARRAY");
    static_assert(GL_SAMPLER_1D_ARRAY_SHADOW == _GL_SAMPLER_1D_ARRAY_SHADOW, "GL_SAMPLER_1D_ARRAY_SHADOW is not equal to _GL_SAMPLER_1D_ARRAY_SHADOW");
    static_assert(GL_SAMPLER_2D_ARRAY_SHADOW == _GL_SAMPLER_2D_ARRAY_SHADOW, "GL_SAMPLER_2D_ARRAY_SHADOW is not equal to _GL_SAMPLER_2D_ARRAY_SHADOW");
    static_assert(GL_SAMPLER_CUBE_SHADOW == _GL_SAMPLER_CUBE_SHADOW, "GL_SAMPLER_CUBE_SHADOW is not equal to _GL_SAMPLER_CUBE_SHADOW");
}
#pragma endregion

#pragma region RANDOM_STUFF19
#define GL_UNSIGNED_INT_VEC2 0x8DC6
#define GL_UNSIGNED_INT_VEC3 0x8DC7
#define GL_UNSIGNED_INT_VEC4 0x8DC8
#define GL_INT_SAMPLER_1D 0x8DC9
#define GL_INT_SAMPLER_2D 0x8DCA
#define GL_INT_SAMPLER_3D 0x8DCB
#define GL_INT_SAMPLER_CUBE 0x8DCC
#define GL_INT_SAMPLER_1D_ARRAY 0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY 0x8DCF
#define GL_UNSIGNED_INT_SAMPLER_1D 0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D 0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D 0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE 0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY 0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY 0x8DD7
#define GL_QUERY_WAIT 0x8E13
#define GL_QUERY_NO_WAIT 0x8E14
#define GL_QUERY_BY_REGION_WAIT 0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT 0x8E16
#define GL_BUFFER_ACCESS_FLAGS 0x911F
#define GL_BUFFER_MAP_LENGTH 0x9120
#define GL_BUFFER_MAP_OFFSET 0x9121
#define GL_DEPTH_COMPONENT32F 0x8CAC
#define GL_DEPTH32F_STENCIL8 0x8CAD
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV 0x8DAD
#define GL_INVALID_FRAMEBUFFER_OPERATION 0x0506

    export constexpr int _GL_UNSIGNED_INT_VEC2 = 0x8DC6;
    export constexpr int _GL_UNSIGNED_INT_VEC3 = 0x8DC7;
    export constexpr int _GL_UNSIGNED_INT_VEC4 = 0x8DC8;
    export constexpr int _GL_INT_SAMPLER_1D = 0x8DC9;
    export constexpr int _GL_INT_SAMPLER_2D = 0x8DCA;
    export constexpr int _GL_INT_SAMPLER_3D = 0x8DCB;
    export constexpr int _GL_INT_SAMPLER_CUBE = 0x8DCC;
    export constexpr int _GL_INT_SAMPLER_1D_ARRAY = 0x8DCE;
    export constexpr int _GL_INT_SAMPLER_2D_ARRAY = 0x8DCF;
    export constexpr int _GL_UNSIGNED_INT_SAMPLER_1D = 0x8DD1;
    export constexpr int _GL_UNSIGNED_INT_SAMPLER_2D = 0x8DD2;
    export constexpr int _GL_UNSIGNED_INT_SAMPLER_3D = 0x8DD3;
    export constexpr int _GL_UNSIGNED_INT_SAMPLER_CUBE = 0x8DD4;
    export constexpr int _GL_UNSIGNED_INT_SAMPLER_1D_ARRAY = 0x8DD6;
    export constexpr int _GL_UNSIGNED_INT_SAMPLER_2D_ARRAY = 0x8DD7;
    export constexpr int _GL_QUERY_WAIT = 0x8E13;
    export constexpr int _GL_QUERY_NO_WAIT = 0x8E14;
    export constexpr int _GL_QUERY_BY_REGION_WAIT = 0x8E15;
    export constexpr int _GL_QUERY_BY_REGION_NO_WAIT = 0x8E16;
    export constexpr int _GL_BUFFER_ACCESS_FLAGS = 0x911F;
    export constexpr int _GL_BUFFER_MAP_LENGTH = 0x9120;
    export constexpr int _GL_BUFFER_MAP_OFFSET = 0x9121;
    export constexpr int _GL_DEPTH_COMPONENT32F = 0x8CAC;
    export constexpr int _GL_DEPTH32F_STENCIL8 = 0x8CAD;
    export constexpr int _GL_FLOAT_32_UNSIGNED_INT_24_8_REV = 0x8DAD;
    export constexpr int _GL_INVALID_FRAMEBUFFER_OPERATION = 0x0506;

consteval void Check_Random_Stuff19() {
    static_assert(GL_UNSIGNED_INT_VEC2 == _GL_UNSIGNED_INT_VEC2, "GL_UNSIGNED_INT_VEC2 is not equal to _GL_UNSIGNED_INT_VEC2");
    static_assert(GL_UNSIGNED_INT_VEC3 == _GL_UNSIGNED_INT_VEC3, "GL_UNSIGNED_INT_VEC3 is not equal to _GL_UNSIGNED_INT_VEC3");
    static_assert(GL_UNSIGNED_INT_VEC4 == _GL_UNSIGNED_INT_VEC4, "GL_UNSIGNED_INT_VEC4 is not equal to _GL_UNSIGNED_INT_VEC4");
    static_assert(GL_INT_SAMPLER_1D == _GL_INT_SAMPLER_1D, "GL_INT_SAMPLER_1D is not equal to _GL_INT_SAMPLER_1D");
    static_assert(GL_INT_SAMPLER_2D == _GL_INT_SAMPLER_2D, "GL_INT_SAMPLER_2D is not equal to _GL_INT_SAMPLER_2D");
    static_assert(GL_INT_SAMPLER_3D == _GL_INT_SAMPLER_3D, "GL_INT_SAMPLER_3D is not equal to _GL_INT_SAMPLER_3D");
    static_assert(GL_INT_SAMPLER_CUBE == _GL_INT_SAMPLER_CUBE, "GL_INT_SAMPLER_CUBE is not equal to _GL_INT_SAMPLER_CUBE");
    static_assert(GL_INT_SAMPLER_1D_ARRAY == _GL_INT_SAMPLER_1D_ARRAY, "GL_INT_SAMPLER_1D_ARRAY is not equal to _GL_INT_SAMPLER_1D_ARRAY");
    static_assert(GL_INT_SAMPLER_2D_ARRAY == _GL_INT_SAMPLER_2D_ARRAY, "GL_INT_SAMPLER_2D_ARRAY is not equal to _GL_INT_SAMPLER_2D_ARRAY");
    static_assert(GL_UNSIGNED_INT_SAMPLER_1D == _GL_UNSIGNED_INT_SAMPLER_1D, "GL_UNSIGNED_INT_SAMPLER_1D is not equal to _GL_UNSIGNED_INT_SAMPLER_1D");
    static_assert(GL_UNSIGNED_INT_SAMPLER_2D == _GL_UNSIGNED_INT_SAMPLER_2D, "GL_UNSIGNED_INT_SAMPLER_2D is not equal to _GL_UNSIGNED_INT_SAMPLER_2D");
    static_assert(GL_UNSIGNED_INT_SAMPLER_3D == _GL_UNSIGNED_INT_SAMPLER_3D, "GL_UNSIGNED_INT_SAMPLER_3D is not equal to _GL_UNSIGNED_INT_SAMPLER_3D");
    static_assert(GL_UNSIGNED_INT_SAMPLER_CUBE == _GL_UNSIGNED_INT_SAMPLER_CUBE, "GL_UNSIGNED_INT_SAMPLER is not equal to _GL_UNSIGNED_INT_SAMPLER");
    static_assert(GL_UNSIGNED_INT_SAMPLER_1D_ARRAY == _GL_UNSIGNED_INT_SAMPLER_1D_ARRAY, "GL_UNSIGNED_INT_SAMPLER_1D_ARRAY is not equal to _GL_UNSIGNED_INT_SAMPLER_1D_ARRAY");
    static_assert(GL_UNSIGNED_INT_SAMPLER_2D_ARRAY == _GL_UNSIGNED_INT_SAMPLER_2D_ARRAY, "GL_UNSIGNED_INT_SAMPLER_2D_ARRAY is not equal to _GL_UNSIGNED_INT_SAMPLER_2D_ARRAY");
    static_assert(GL_QUERY_WAIT == _GL_QUERY_WAIT, "GL_QUERY_WAIT is not equal to _GL_QUERY_WAIT");
    static_assert(GL_QUERY_NO_WAIT == _GL_QUERY_NO_WAIT, "GL_QUERY_NO_WAIT is not equal to _GL_QUERY_NO_WAIT");
    static_assert(GL_QUERY_BY_REGION_WAIT == _GL_QUERY_BY_REGION_WAIT, "GL_QUERY_BY_REGION_WAIT is not equal to _GL_QUERY_BY_REGION_WAIT");
    static_assert(GL_QUERY_BY_REGION_NO_WAIT == _GL_QUERY_BY_REGION_NO_WAIT, "GL_QUERY_BY_REGION_NO_WAIT is not equal to _GL_QUERY_BY_REGION_NO_WAIT");
    static_assert(GL_BUFFER_ACCESS_FLAGS == _GL_BUFFER_ACCESS_FLAGS, "GL_BUFFER_ACCESS_FLAGS is not equal to _GL_BUFFER_ACCESS_FLAGS");
    static_assert(GL_BUFFER_MAP_LENGTH == _GL_BUFFER_MAP_LENGTH, "GL_BUFFER_MAP_LENGTH is not equal to _GL_BUFFER_MAP_LENGTH");
    static_assert(GL_BUFFER_MAP_OFFSET == _GL_BUFFER_MAP_OFFSET, "GL_BUFFER_MAP_OFFSET is not equal to _GL_BUFFER_MAP_OFFSET");
    static_assert(GL_DEPTH_COMPONENT32F == _GL_DEPTH_COMPONENT32F, "GL_DEPTH_COMPONENT32F is not equal to _GL_DEPTH_COMPONENT32F");
    static_assert(GL_DEPTH32F_STENCIL8 == _GL_DEPTH32F_STENCIL8, "GL_DEPTH32F_STENCIL8 is not equal to _GL_DEPTH32F_STENCIL8");
    static_assert(GL_FLOAT_32_UNSIGNED_INT_24_8_REV == _GL_FLOAT_32_UNSIGNED_INT_24_8_REV, "GL_FLOAT_32_UNSIGNED_INT_24_8_REV is not equal to _GL_FLOAT_32_UNSIGNED_INT_24_8_REV");
    static_assert(GL_INVALID_FRAMEBUFFER_OPERATION == _GL_INVALID_FRAMEBUFFER_OPERATION, "GL_INVALID_FRAMEBUFFER_OPERATION is not equal to _GL_INVALID_FRAMEBUFFER_OPERATION");
}
#pragma endregion

#pragma region RANDOM_STUFF20

#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING 0x8210
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE 0x8211
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE 0x8212
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE 0x8213
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE 0x8214
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE 0x8215
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE 0x8216
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE 0x8217
#define GL_FRAMEBUFFER_DEFAULT 0x8218
#define GL_FRAMEBUFFER_UNDEFINED 0x8219
#define GL_DEPTH_STENCIL_ATTACHMENT 0x821A
#define GL_MAX_RENDERBUFFER_SIZE 0x84E8
#define GL_DEPTH_STENCIL 0x84F9
#define GL_UNSIGNED_INT_24_8 0x84FA
#define GL_DEPTH24_STENCIL8 0x88F0
#define GL_TEXTURE_STENCIL_SIZE 0x88F1
#define GL_TEXTURE_RED_TYPE 0x8C10
#define GL_TEXTURE_GREEN_TYPE 0x8C11
#define GL_TEXTURE_BLUE_TYPE 0x8C12
#define GL_TEXTURE_ALPHA_TYPE 0x8C13
#define GL_TEXTURE_DEPTH_TYPE 0x8C16

    export constexpr int _GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING = 0x8210;
    export constexpr int _GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE = 0x8211;
    export constexpr int _GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE = 0x8212;
    export constexpr int _GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE = 0x8213;
    export constexpr int _GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE = 0x8214;
    export constexpr int _GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE = 0x8215;
    export constexpr int _GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE = 0x8216;
    export constexpr int _GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE = 0x8217;
    export constexpr int _GL_FRAMEBUFFER_DEFAULT = 0x8218;
    export constexpr int _GL_FRAMEBUFFER_UNDEFINED = 0x8219;
    export constexpr int _GL_DEPTH_STENCIL_ATTACHMENT = 0x821A;
    export constexpr int _GL_MAX_RENDERBUFFER_SIZE = 0x84E8;
    export constexpr int _GL_DEPTH_STENCIL = 0x84F9;
    export constexpr int _GL_UNSIGNED_INT_24_8 = 0x84FA;
    export constexpr int _GL_DEPTH24_STENCIL8 = 0x88F0;
    export constexpr int _GL_TEXTURE_STENCIL_SIZE = 0x88F1;
    export constexpr int _GL_TEXTURE_RED_TYPE = 0x8C10;
    export constexpr int _GL_TEXTURE_GREEN_TYPE = 0x8C11;
    export constexpr int _GL_TEXTURE_BLUE_TYPE = 0x8C12;
    export constexpr int _GL_TEXTURE_ALPHA_TYPE = 0x8C13;
    export constexpr int _GL_TEXTURE_DEPTH_TYPE = 0x8C16;

consteval void Check_Random_stuff20() {
    static_assert(GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING == _GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING, "GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING is not equal to _GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING");
    static_assert(GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE == _GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE, "GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE is not equal to _GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE");
    static_assert(GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE == _GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE, "GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE is not equal to _GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE");
    static_assert(GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE == _GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE, "GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE is not equal to _GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE");
    static_assert(GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE == _GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE, "GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE is not equal to _GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE");
    static_assert(GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE == _GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE, "GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE is not equal to _GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE");
    static_assert(GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE == _GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE, "GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE is not equal to _GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE");
    static_assert(GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE == _GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE, "GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE is not equal to _GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE");
    static_assert(GL_FRAMEBUFFER_DEFAULT == _GL_FRAMEBUFFER_DEFAULT, "GL_FRAMEBUFFER_DEFAULT is not equal to _GL_FRAMEBUFFER_DEFAULT");
    static_assert(GL_FRAMEBUFFER_UNDEFINED == _GL_FRAMEBUFFER_UNDEFINED, "GL_FRAMEBUFFER_UNDEFINED is not equal to _GL_FRAMEBUFFER_UNDEFINED");
    static_assert(GL_DEPTH_STENCIL_ATTACHMENT == _GL_DEPTH_STENCIL_ATTACHMENT, "GL_DEPTH_STENCIL_ATTACHMENT is not equal to _GL_DEPTH_STENCIL_ATTACHMENT");
    static_assert(GL_MAX_RENDERBUFFER_SIZE == _GL_MAX_RENDERBUFFER_SIZE, "GL_MAX_RENDERBUFFER_SIZE is not equal to _GL_MAX_RENDERBUFFER_SIZE");
    static_assert(GL_DEPTH_STENCIL == _GL_DEPTH_STENCIL, "GL_DEPTH_STENCIL is not equal to _GL_DEPTH_STENCIL");
    static_assert(GL_UNSIGNED_INT_24_8 == _GL_UNSIGNED_INT_24_8, "GL_UNSIGNED_INT_24_8 is not equal to _GL_UNSIGNED_INT_24_8");
    static_assert(GL_DEPTH24_STENCIL8 == _GL_DEPTH24_STENCIL8, "GL_DEPTH24_STENCIL8 is not equal to _GL_DEPTH24_STENCIL8");
    static_assert(GL_TEXTURE_STENCIL_SIZE == _GL_TEXTURE_STENCIL_SIZE, "GL_TEXTURE_STENCIL_SIZE is not equal to _GL_TEXTURE_STENCIL_SIZE");
    static_assert(GL_TEXTURE_RED_TYPE == _GL_TEXTURE_RED_TYPE, "GL_TEXTURE_RED_TYPE is not equal to _GL_TEXTURE_RED_TYPE");
    static_assert(GL_TEXTURE_GREEN_TYPE == _GL_TEXTURE_GREEN_TYPE, "GL_TEXTURE_GREEN_TYPE is not equal to _GL_TEXTURE_GREEN_TYPE");
    static_assert(GL_TEXTURE_BLUE_TYPE == _GL_TEXTURE_BLUE_TYPE, "GL_TEXTURE_BLUE_TYPE is not equal to _GL_TEXTURE_BLUE_TYPE");
    static_assert(GL_TEXTURE_ALPHA_TYPE == _GL_TEXTURE_ALPHA_TYPE, "GL_TEXTURE_ALPHA_TYPE is not equal to _GL_TEXTURE_ALPHA_TYPE");
    static_assert(GL_TEXTURE_DEPTH_TYPE == _GL_TEXTURE_DEPTH_TYPE, "GL_TEXTURE_DEPTH_TYPE is not equal to _GL_TEXTURE_DEPTH_TYPE");
}
#pragma endregion

#pragma region RANDOM_STUFF21
#define GL_UNSIGNED_NORMALIZED 0x8C17
#define GL_FRAMEBUFFER_BINDING 0x8CA6
#define GL_DRAW_FRAMEBUFFER_BINDING 0x8CA6
#define GL_RENDERBUFFER_BINDING 0x8CA7
#define GL_READ_FRAMEBUFFER 0x8CA8
#define GL_DRAW_FRAMEBUFFER 0x8CA9
#define GL_READ_FRAMEBUFFER_BINDING 0x8CAA
#define GL_RENDERBUFFER_SAMPLES 0x8CAB
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4
#define GL_FRAMEBUFFER_COMPLETE 0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER 0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER 0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED 0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS 0x8CDF

    export constexpr int _GL_UNSIGNED_NORMALIZED = 0x8C17;
    export constexpr int _GL_FRAMEBUFFER_BINDING = 0x8CA6;
    export constexpr int _GL_DRAW_FRAMEBUFFER_BINDING = 0x8CA6;
    export constexpr int _GL_RENDERBUFFER_BINDING = 0x8CA7;
    export constexpr int _GL_READ_FRAMEBUFFER = 0x8CA8;
    export constexpr int _GL_DRAW_FRAMEBUFFER = 0x8CA9;
    export constexpr int _GL_READ_FRAMEBUFFER_BINDING = 0x8CAA;
    export constexpr int _GL_RENDERBUFFER_SAMPLES = 0x8CAB;
    export constexpr int _GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE = 0x8CD0;
    export constexpr int _GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME = 0x8CD1;
    export constexpr int _GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL = 0x8CD2;
    export constexpr int _GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE = 0x8CD3;
    export constexpr int _GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER = 0x8CD4;
    export constexpr int _GL_FRAMEBUFFER_COMPLETE = 0x8CD5;
    export constexpr int _GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT = 0x8CD6;
    export constexpr int _GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT = 0x8CD7;
    export constexpr int _GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER = 0x8CDB;
    export constexpr int _GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER = 0x8CDC;
    export constexpr int _GL_FRAMEBUFFER_UNSUPPORTED = 0x8CDD;
    export constexpr int _GL_MAX_COLOR_ATTACHMENTS = 0x8CDF;

consteval void Check_Random_Stuff21() {
    static_assert(GL_UNSIGNED_NORMALIZED == _GL_UNSIGNED_NORMALIZED, "GL_UNSIGNED_NORMALIZED is not equal to _GL_UNSIGNED_NORMALIZED");
    static_assert(GL_FRAMEBUFFER_BINDING == _GL_FRAMEBUFFER_BINDING, "GL_FRAMEBUFFER_BINDING is not equal to _GL_FRAMEBUFFER_BINDING");
    static_assert(GL_DRAW_FRAMEBUFFER_BINDING == _GL_DRAW_FRAMEBUFFER_BINDING, "GL_DRAW_FRAMEBUFFER_BINDING is not equal to _GL_DRAW_FRAMEBUFFER_BINDING");
    static_assert(GL_RENDERBUFFER_BINDING == _GL_RENDERBUFFER_BINDING, "GL_RENDERBUFFER_BINDING is not equal to _GL_RENDERBUFFER_BINDING");
    static_assert(GL_READ_FRAMEBUFFER == _GL_READ_FRAMEBUFFER, "GL_READ_FRAMEBUFFER is not equal to _GL_READ_FRAMEBUFFER");
    static_assert(GL_DRAW_FRAMEBUFFER == _GL_DRAW_FRAMEBUFFER, "GL_DRAW_FRAMEBUFFER is not equal to _GL_DRAW_FRAMEBUFFER");
    static_assert(GL_READ_FRAMEBUFFER_BINDING == _GL_READ_FRAMEBUFFER_BINDING, "GL_READ_FRAMEBUFFER_BINDING is not equal to _GL_READ_FRAMEBUFFER_BINDING");
    static_assert(GL_RENDERBUFFER_SAMPLES == _GL_RENDERBUFFER_SAMPLES, "GL_RENDERBUFFER_SAMPLES is not equal to _GL_RENDERBUFFER_SAMPLES");
    static_assert(GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE == _GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE, "GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE is not equal to _GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE");
    static_assert(GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME == _GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME, "GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME is not equal to _GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME");
    static_assert(GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL == _GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL, "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL is not equal to _GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL");
    static_assert(GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE == _GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE, "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE is not equal to _GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE");
    static_assert(GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER == _GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER, "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER is not equal to _GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER");
    static_assert(GL_FRAMEBUFFER_COMPLETE == _GL_FRAMEBUFFER_COMPLETE, "GL_FRAMEBUFFER_COMPLETE is not equal to _GL_FRAMEBUFFER_COMPLETE");
    static_assert(GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT == _GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT, "GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT is not equal to _GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT");
    static_assert(GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT == _GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT, "GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT is not equal to _GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT");
    static_assert(GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER == _GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER, "GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER is not equal to _GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER");
    static_assert(GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER == _GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER, "GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER is not equal to _GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER");
    static_assert(GL_FRAMEBUFFER_UNSUPPORTED == _GL_FRAMEBUFFER_UNSUPPORTED, "GL_FRAMEBUFFER_UNSUPPORTED is not equal to _GL_FRAMEBUFFER_UNSUPPORTED");
    static_assert(GL_MAX_COLOR_ATTACHMENTS == _GL_MAX_COLOR_ATTACHMENTS, "GL_MAX_COLOR_ATTACHMENTS is not equal to _GL_MAX_COLOR_ATTACHMENTS");
}
#pragma endregion

#pragma region RANDOM_STUFF22
#define GL_COLOR_ATTACHMENT0 0x8CE0
#define GL_COLOR_ATTACHMENT1 0x8CE1
#define GL_COLOR_ATTACHMENT2 0x8CE2
#define GL_COLOR_ATTACHMENT3 0x8CE3
#define GL_COLOR_ATTACHMENT4 0x8CE4
#define GL_COLOR_ATTACHMENT5 0x8CE5
#define GL_COLOR_ATTACHMENT6 0x8CE6
#define GL_COLOR_ATTACHMENT7 0x8CE7
#define GL_COLOR_ATTACHMENT8 0x8CE8
#define GL_COLOR_ATTACHMENT9 0x8CE9
#define GL_COLOR_ATTACHMENT10 0x8CEA
#define GL_COLOR_ATTACHMENT11 0x8CEB
#define GL_COLOR_ATTACHMENT12 0x8CEC
#define GL_COLOR_ATTACHMENT13 0x8CED
#define GL_COLOR_ATTACHMENT14 0x8CEE
#define GL_COLOR_ATTACHMENT15 0x8CEF
#define GL_COLOR_ATTACHMENT16 0x8CF0
#define GL_COLOR_ATTACHMENT17 0x8CF1
#define GL_COLOR_ATTACHMENT18 0x8CF2
#define GL_COLOR_ATTACHMENT19 0x8CF3
#define GL_COLOR_ATTACHMENT20 0x8CF4
#define GL_COLOR_ATTACHMENT21 0x8CF5
#define GL_COLOR_ATTACHMENT22 0x8CF6
#define GL_COLOR_ATTACHMENT23 0x8CF7
#define GL_COLOR_ATTACHMENT24 0x8CF8
#define GL_COLOR_ATTACHMENT25 0x8CF9
#define GL_COLOR_ATTACHMENT26 0x8CFA
#define GL_COLOR_ATTACHMENT27 0x8CFB
#define GL_COLOR_ATTACHMENT28 0x8CFC
#define GL_COLOR_ATTACHMENT29 0x8CFD
#define GL_COLOR_ATTACHMENT30 0x8CFE
#define GL_COLOR_ATTACHMENT31 0x8CFF
#define GL_DEPTH_ATTACHMENT 0x8D00
#define GL_STENCIL_ATTACHMENT 0x8D20
#define GL_FRAMEBUFFER 0x8D40

    export constexpr int _GL_COLOR_ATTACHMENT0 = 0x8CE0;
    export constexpr int _GL_COLOR_ATTACHMENT1 = 0x8CE1;
    export constexpr int _GL_COLOR_ATTACHMENT2 = 0x8CE2;
    export constexpr int _GL_COLOR_ATTACHMENT3 = 0x8CE3;
    export constexpr int _GL_COLOR_ATTACHMENT4 = 0x8CE4;
    export constexpr int _GL_COLOR_ATTACHMENT5 = 0x8CE5;
    export constexpr int _GL_COLOR_ATTACHMENT6 = 0x8CE6;
    export constexpr int _GL_COLOR_ATTACHMENT7 = 0x8CE7;
    export constexpr int _GL_COLOR_ATTACHMENT8 = 0x8CE8;
    export constexpr int _GL_COLOR_ATTACHMENT9 = 0x8CE9;
    export constexpr int _GL_COLOR_ATTACHMENT10 = 0x8CEA;
    export constexpr int _GL_COLOR_ATTACHMENT11 = 0x8CEB;
    export constexpr int _GL_COLOR_ATTACHMENT12 = 0x8CEC;
    export constexpr int _GL_COLOR_ATTACHMENT13 = 0x8CED;
    export constexpr int _GL_COLOR_ATTACHMENT14 = 0x8CEE;
    export constexpr int _GL_COLOR_ATTACHMENT15 = 0x8CEF;
    export constexpr int _GL_COLOR_ATTACHMENT16 = 0x8CF0;
    export constexpr int _GL_COLOR_ATTACHMENT17 = 0x8CF1;
    export constexpr int _GL_COLOR_ATTACHMENT18 = 0x8CF2;
    export constexpr int _GL_COLOR_ATTACHMENT19 = 0x8CF3;
    export constexpr int _GL_COLOR_ATTACHMENT20 = 0x8CF4;
    export constexpr int _GL_COLOR_ATTACHMENT21 = 0x8CF5;
    export constexpr int _GL_COLOR_ATTACHMENT22 = 0x8CF6;
    export constexpr int _GL_COLOR_ATTACHMENT23 = 0x8CF7;
    export constexpr int _GL_COLOR_ATTACHMENT24 = 0x8CF8;
    export constexpr int _GL_COLOR_ATTACHMENT25 = 0x8CF9;
    export constexpr int _GL_COLOR_ATTACHMENT26 = 0x8CFA;
    export constexpr int _GL_COLOR_ATTACHMENT27 = 0x8CFB;
    export constexpr int _GL_COLOR_ATTACHMENT28 = 0x8CFC;
    export constexpr int _GL_COLOR_ATTACHMENT29 = 0x8CFD;
    export constexpr int _GL_COLOR_ATTACHMENT30 = 0x8CFE;
    export constexpr int _GL_COLOR_ATTACHMENT31 = 0x8CFF;
    export constexpr int _GL_DEPTH_ATTACHMENT = 0x8D00;
    export constexpr int _GL_STENCIL_ATTACHMENT = 0x8D20;
    export constexpr int _GL_FRAMEBUFFER = 0x8D40;

consteval void Check_Random_Stuff22() {
    static_assert(GL_COLOR_ATTACHMENT0 == _GL_COLOR_ATTACHMENT0, "GL_COLOR_ATTACHMENT0 is not equal to _GL_COLOR_ATTACHMENT0");
    static_assert(GL_COLOR_ATTACHMENT1 == _GL_COLOR_ATTACHMENT1, "GL_COLOR_ATTACHMENT1 is not equal to _GL_COLOR_ATTACHMENT1");
    static_assert(GL_COLOR_ATTACHMENT2 == _GL_COLOR_ATTACHMENT2, "GL_COLOR_ATTACHMENT2 is not equal to _GL_COLOR_ATTACHMENT2");
    static_assert(GL_COLOR_ATTACHMENT3 == _GL_COLOR_ATTACHMENT3, "GL_COLOR_ATTACHMENT3 is not equal to _GL_COLOR_ATTACHMENT3");
    static_assert(GL_COLOR_ATTACHMENT4 == _GL_COLOR_ATTACHMENT4, "GL_COLOR_ATTACHMENT4 is not equal to _GL_COLOR_ATTACHMENT4");
    static_assert(GL_COLOR_ATTACHMENT5 == _GL_COLOR_ATTACHMENT5, "GL_COLOR_ATTACHMENT5 is not equal to _GL_COLOR_ATTACHMENT5");
    static_assert(GL_COLOR_ATTACHMENT6 == _GL_COLOR_ATTACHMENT6, "GL_COLOR_ATTACHMENT6 is not equal to _GL_COLOR_ATTACHMENT6");
    static_assert(GL_COLOR_ATTACHMENT7 == _GL_COLOR_ATTACHMENT7, "GL_COLOR_ATTACHMENT7 is not equal to _GL_COLOR_ATTACHMENT7");
    static_assert(GL_COLOR_ATTACHMENT8 == _GL_COLOR_ATTACHMENT8, "GL_COLOR_ATTACHMENT8 is not equal to _GL_COLOR_ATTACHMENT8");
    static_assert(GL_COLOR_ATTACHMENT9 == _GL_COLOR_ATTACHMENT9, "GL_COLOR_ATTACHMENT9 is not equal to _GL_COLOR_ATTACHMENT9");
    static_assert(GL_COLOR_ATTACHMENT10 == _GL_COLOR_ATTACHMENT10, "GL_COLOR_ATTACHMENT10 is not equal to _GL_COLOR_ATTACHMENT10");
    static_assert(GL_COLOR_ATTACHMENT11 == _GL_COLOR_ATTACHMENT11, "GL_COLOR_ATTACHMENT11 is not equal to _GL_COLOR_ATTACHMENT11");
    static_assert(GL_COLOR_ATTACHMENT12 == _GL_COLOR_ATTACHMENT12, "GL_COLOR_ATTACHMENT12 is not equal to _GL_COLOR_ATTACHMENT12");
    static_assert(GL_COLOR_ATTACHMENT13 == _GL_COLOR_ATTACHMENT13, "GL_COLOR_ATTACHMENT13 is not equal to _GL_COLOR_ATTACHMENT13");
    static_assert(GL_COLOR_ATTACHMENT14 == _GL_COLOR_ATTACHMENT14, "GL_COLOR_ATTACHMENT14 is not equal to _GL_COLOR_ATTACHMENT14");
    static_assert(GL_COLOR_ATTACHMENT15 == _GL_COLOR_ATTACHMENT15, "GL_COLOR_ATTACHMENT15 is not equal to _GL_COLOR_ATTACHMENT15");
    static_assert(GL_COLOR_ATTACHMENT16 == _GL_COLOR_ATTACHMENT16, "GL_COLOR_ATTACHMENT16 is not equal to _ GL_COLOR_ATTACHMENT16");
    static_assert(GL_COLOR_ATTACHMENT17 == _GL_COLOR_ATTACHMENT17, "GL_COLOR_ATTACHMENT17 is not equal to _GL_COLOR_ATTACHMENT17");
    static_assert(GL_COLOR_ATTACHMENT18 == _GL_COLOR_ATTACHMENT18, "GL_COLOR_ATTACHMENT18 is not equal to _GL_COLOR_ATTACHMENT18");
    static_assert(GL_COLOR_ATTACHMENT19 == _GL_COLOR_ATTACHMENT19, "GL_COLOR_ATTACHMENT19 is not equal to _GL_COLOR_ATTACHMENT19");
    static_assert(GL_COLOR_ATTACHMENT20 == _GL_COLOR_ATTACHMENT20, "GL_COLOR_ATTACHMENT20 is not equal to _GL_COLOR_ATTACHMENT20");
    static_assert(GL_COLOR_ATTACHMENT21 == _GL_COLOR_ATTACHMENT21, "GL_COLOR_ATTACHMENT21 is not equal to _GL_COLOR_ATTACHMENT21");
    static_assert(GL_COLOR_ATTACHMENT22 == _GL_COLOR_ATTACHMENT22, "GL_COLOR_ATTACHMENT22 is not equal to _GL_COLOR_ATTACHMENT22");
    static_assert(GL_COLOR_ATTACHMENT23 == _GL_COLOR_ATTACHMENT23, "GL_COLOR_ATTACHMENT23 is not equal to _GL_COLOR_ATTACHMENT23");
    static_assert(GL_COLOR_ATTACHMENT24 == _GL_COLOR_ATTACHMENT24, "GL_COLOR_ATTACHMENT24 is not equal to _GL_COLOR_ATTACHMENT24");
    static_assert(GL_COLOR_ATTACHMENT25 == _GL_COLOR_ATTACHMENT25, "GL_COLOR_ATTACHMENT25 is not equal to _GL_COLOR_ATTACHMENT25");
    static_assert(GL_COLOR_ATTACHMENT26 == _GL_COLOR_ATTACHMENT26, "GL_COLOR_ATTACHMENT26 is not equal to _GL_COLOR_ATTACHMENT26");
    static_assert(GL_COLOR_ATTACHMENT27 == _GL_COLOR_ATTACHMENT27, "GL_COLOR_ATTACHMENT27 is not equal to _GL_COLOR_ATTACHMENT27");
    static_assert(GL_COLOR_ATTACHMENT28 == _GL_COLOR_ATTACHMENT28, "GL_COLOR_ATTACHMENT28 is not equal to _GL_COLOR_ATTACHMENT28");
    static_assert(GL_COLOR_ATTACHMENT29 == _GL_COLOR_ATTACHMENT29, "GL_COLOR_ATTACHMENT29 is not equal to _GL_COLOR_ATTACHMENT29");
    static_assert(GL_COLOR_ATTACHMENT30 == _GL_COLOR_ATTACHMENT30, "GL_COLOR_ATTACHMENT30 is not equal to _GL_COLOR_ATTACHMENT30");
    static_assert(GL_COLOR_ATTACHMENT31 == _GL_COLOR_ATTACHMENT31, "GL_COLOR_ATTACHMENT31 is not equal to _GL_COLOR_ATTACHMENT31");
    static_assert(GL_DEPTH_ATTACHMENT == _GL_DEPTH_ATTACHMENT, "GL_DEPTH_ATTACHMENT is not equal to _GL_DEPTH_ATTACHMENT");
    static_assert(GL_STENCIL_ATTACHMENT == _GL_STENCIL_ATTACHMENT, "GL_STENCIL_ATTACHMENT is not equal to _GL_STENCIL_ATTACHMENT");
    static_assert(GL_FRAMEBUFFER == _GL_FRAMEBUFFER, "GL_FRAMEBUFFER is not equal to _GL_FRAMEBUFFER");
}
#pragma endregion

#pragma region RANDOM_STUFF23
#define GL_RENDERBUFFER 0x8D41
#define GL_RENDERBUFFER_WIDTH 0x8D42
#define GL_RENDERBUFFER_HEIGHT 0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT 0x8D44
#define GL_STENCIL_INDEX1 0x8D46
#define GL_STENCIL_INDEX4 0x8D47
#define GL_STENCIL_INDEX8 0x8D48
#define GL_STENCIL_INDEX16 0x8D49
#define GL_RENDERBUFFER_RED_SIZE 0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE 0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE 0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE 0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE 0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE 0x8D55
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE 0x8D56
#define GL_MAX_SAMPLES 0x8D57
#define GL_FRAMEBUFFER_SRGB 0x8DB9
#define GL_HALF_FLOAT 0x140B
    export constexpr int _GL_RENDERBUFFER = 0x8D41;
    export constexpr int _GL_RENDERBUFFER_WIDTH = 0x8D42;
    export constexpr int _GL_RENDERBUFFER_HEIGHT = 0x8D43;
    export constexpr int _GL_RENDERBUFFER_INTERNAL_FORMAT = 0x8D44;
    export constexpr int _GL_STENCIL_INDEX1 = 0x8D46;
    export constexpr int _GL_STENCIL_INDEX4 = 0x8D47;
    export constexpr int _GL_STENCIL_INDEX8 = 0x8D48;
    export constexpr int _GL_STENCIL_INDEX16 = 0x8D49;
    export constexpr int _GL_RENDERBUFFER_RED_SIZE = 0x8D50;
    export constexpr int _GL_RENDERBUFFER_GREEN_SIZE = 0x8D51;
    export constexpr int _GL_RENDERBUFFER_BLUE_SIZE = 0x8D52;
    export constexpr int _GL_RENDERBUFFER_ALPHA_SIZE = 0x8D53;
    export constexpr int _GL_RENDERBUFFER_DEPTH_SIZE = 0x8D54;
    export constexpr int _GL_RENDERBUFFER_STENCIL_SIZE = 0x8D55;
    export constexpr int _GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE = 0x8D56;
    export constexpr int _GL_MAX_SAMPLES = 0x8D57;
    export constexpr int _GL_FRAMEBUFFER_SRGB = 0x8DB9;
    export constexpr int _GL_HALF_FLOAT = 0x140B;
consteval void Check_Random_Stuff23() {
    static_assert(GL_RENDERBUFFER == _GL_RENDERBUFFER, "GL_RENDERBUFFER is not equal to _GL_RENDERBUFFER");
    static_assert(GL_RENDERBUFFER_WIDTH == _GL_RENDERBUFFER_WIDTH, "GL_RENDERBUFFER_WIDTH is not equal to _GL_RENDERBUFFER_WIDTH");
    static_assert(GL_RENDERBUFFER_HEIGHT == _GL_RENDERBUFFER_HEIGHT, "GL_RENDERBUFFER_HEIGHT is not equal to _GL_RENDERBUFFER_HEIGHT");
    static_assert(GL_RENDERBUFFER_INTERNAL_FORMAT == _GL_RENDERBUFFER_INTERNAL_FORMAT, "GL_RENDERBUFFER_INTERNAL_FORMAT is not equal to _GL_RENDERBUFFER_INTERNAL_FORMAT");
    static_assert(GL_STENCIL_INDEX1 == _GL_STENCIL_INDEX1, "GL_STENCIL_INDEX1 is not equal to _GL_STENCIL_INDEX1");
    static_assert(GL_STENCIL_INDEX4 == _GL_STENCIL_INDEX4, "GL_STENCIL_INDEX4 is not equal to _GL_STENCIL_INDEX4");
    static_assert(GL_STENCIL_INDEX8 == _GL_STENCIL_INDEX8, "GL_STENCIL_INDEX8 is not equal to _GL_STENCIL_INDEX8");
    static_assert(GL_STENCIL_INDEX16 == _GL_STENCIL_INDEX16, "GL_STENCIL_INDEX16 is not equal to _GL_STENCIL_INDEX16");
    static_assert(GL_RENDERBUFFER_RED_SIZE == _GL_RENDERBUFFER_RED_SIZE, "GL_RENDERBUFFER_RED_SIZE is not equal to _GL_RENDERBUFFER_RED_SIZE");
    static_assert(GL_RENDERBUFFER_GREEN_SIZE == _GL_RENDERBUFFER_GREEN_SIZE, "GL_RENDERBUFFER_GREEN_SIZE is not equal to _GL_RENDERBUFFER_GREEN_SIZE");
    static_assert(GL_RENDERBUFFER_BLUE_SIZE == _GL_RENDERBUFFER_BLUE_SIZE, "GL_RENDERBUFFER_BLUE_SIZE is not equal to _GL_RENDERBUFFER_BLUE_SIZE");
    static_assert(GL_RENDERBUFFER_ALPHA_SIZE == _GL_RENDERBUFFER_ALPHA_SIZE, "GL_RENDERBUFFER_ALPHA_SIZE is not equal to _GL_RENDERBUFFER_ALPHA_SIZE");
    static_assert(GL_RENDERBUFFER_DEPTH_SIZE == _GL_RENDERBUFFER_DEPTH_SIZE, "GL_RENDERBUFFER_DEPTH_SIZE is not equal to _GL_RENDERBUFFER_DEPTH_SIZE");
    static_assert(GL_RENDERBUFFER_STENCIL_SIZE == _GL_RENDERBUFFER_STENCIL_SIZE, "GL_RENDERBUFFER_STENCIL_SIZE is not equal to _GL_RENDERBUFFER_STENCIL_SIZE");
    static_assert(GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE == _GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE, "GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE is not equal to _GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE");
    static_assert(GL_MAX_SAMPLES == _GL_MAX_SAMPLES, "GL_MAX_SAMPLES is not equal to _GL_MAX_SAMPLES");
    static_assert(GL_FRAMEBUFFER_SRGB == _GL_FRAMEBUFFER_SRGB, "GL_FRAMEBUFFER_SRGB is not equal to _GL_FRAMEBUFFER_SRGB");
    static_assert(GL_HALF_FLOAT == _GL_HALF_FLOAT, "GL_HALF_FLOAT is not equal to _GL_HALF_FLOAT");
}
#pragma endregion

#pragma region RANDOM_STUFF24
#define GL_MAP_READ_BIT 0x0001
#define GL_MAP_WRITE_BIT 0x0002
#define GL_MAP_INVALIDATE_RANGE_BIT 0x0004
#define GL_MAP_INVALIDATE_BUFFER_BIT 0x0008
#define GL_MAP_FLUSH_EXPLICIT_BIT 0x0010
#define GL_MAP_UNSYNCHRONIZED_BIT 0x0020
#define GL_COMPRESSED_RED_RGTC1 0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1 0x8DBC
#define GL_COMPRESSED_RG_RGTC2 0x8DBD
#define GL_COMPRESSED_SIGNED_RG_RGTC2 0x8DBE
#define GL_RG 0x8227
#define GL_RG_INTEGER 0x8228
#define GL_R8 0x8229
#define GL_R16 0x822A
#define GL_RG8 0x822B
#define GL_RG16 0x822C
#define GL_R16F 0x822D
#define GL_R32F 0x822E
#define GL_RG16F 0x822F
#define GL_RG32F 0x8230
#define GL_R8I 0x8231
#define GL_R8UI 0x8232
#define GL_R16I 0x8233
#define GL_R16UI 0x8234
#define GL_R32I 0x8235
#define GL_R32UI 0x8236
#define GL_RG8I 0x8237
#define GL_RG8UI 0x8238
#define GL_RG16I 0x8239
#define GL_RG16UI 0x823A
#define GL_RG32I 0x823B
#define GL_RG32UI 0x823C
    export constexpr int _GL_MAP_READ_BIT = 0x0001;
    export constexpr int _GL_MAP_WRITE_BIT = 0x0002;
    export constexpr int _GL_MAP_INVALIDATE_RANGE_BIT = 0x0004;
    export constexpr int _GL_MAP_INVALIDATE_BUFFER_BIT = 0x0008;
    export constexpr int _GL_MAP_FLUSH_EXPLICIT_BIT = 0x0010;
    export constexpr int _GL_MAP_UNSYNCHRONIZED_BIT = 0x0020;
    export constexpr int _GL_COMPRESSED_RED_RGTC1 = 0x8DBB;
    export constexpr int _GL_COMPRESSED_SIGNED_RED_RGTC1 = 0x8DBC;
    export constexpr int _GL_COMPRESSED_RG_RGTC2 = 0x8DBD;
    export constexpr int _GL_COMPRESSED_SIGNED_RG_RGTC2 = 0x8DBE;
    export constexpr int _GL_RG = 0x8227;
    export constexpr int _GL_RG_INTEGER = 0x8228;
    export constexpr int _GL_R8 = 0x8229;
    export constexpr int _GL_R16 = 0x822A;
    export constexpr int _GL_RG8 = 0x822B;
    export constexpr int _GL_RG16 = 0x822C;
    export constexpr int _GL_R16F = 0x822D;
    export constexpr int _GL_R32F = 0x822E;
    export constexpr int _GL_RG16F = 0x822F;
    export constexpr int _GL_RG32F = 0x8230;
    export constexpr int _GL_R8I = 0x8231;
    export constexpr int _GL_R8UI = 0x8232;
    export constexpr int _GL_R16I = 0x8233;
    export constexpr int _GL_R16UI = 0x8234;
    export constexpr int _GL_R32I = 0x8235;
    export constexpr int _GL_R32UI = 0x8236;
    export constexpr int _GL_RG8I = 0x8237;
    export constexpr int _GL_RG8UI = 0x8238;
    export constexpr int _GL_RG16I = 0x8239;
    export constexpr int _GL_RG16UI = 0x823A;
    export constexpr int _GL_RG32I = 0x823B;
    export constexpr int _GL_RG32UI = 0x823C;
consteval void Check_Random_Stuff24() {
    static_assert(GL_MAP_READ_BIT == _GL_MAP_READ_BIT, "GL_MAP_READ_BIT is not equal to _GL_MAP_READ_BIT");
    static_assert(GL_MAP_WRITE_BIT == _GL_MAP_WRITE_BIT, "GL_MAP_WRITE_BIT is not equal to _GL_MAP_WRITE_BIT");
    static_assert(GL_MAP_INVALIDATE_RANGE_BIT == _GL_MAP_INVALIDATE_RANGE_BIT, "GL_MAP_INVALIDATE_RANGE_BIT is not equal to _GL_MAP_INVALIDATE_RANGE_BIT");
    static_assert(GL_MAP_INVALIDATE_BUFFER_BIT == _GL_MAP_INVALIDATE_BUFFER_BIT, "GL_MAP_INVALIDATE_BUFFER_BIT is not equal to _GL_MAP_INVALIDATE_BUFFER_BIT");
    static_assert(GL_MAP_FLUSH_EXPLICIT_BIT == _GL_MAP_FLUSH_EXPLICIT_BIT, "GL_MAP_FLUSH_EXPLICIT_BIT is not equal to _GL_MAP_FLUSH_EXPLICIT_BIT");
    static_assert(GL_MAP_UNSYNCHRONIZED_BIT == _GL_MAP_UNSYNCHRONIZED_BIT, "GL_MAP_UNSYNCHRONIZED_BIT is not equal to _GL_MAP_UNSYNCHRONIZED_BIT");
    static_assert(GL_COMPRESSED_RED_RGTC1 == _GL_COMPRESSED_RED_RGTC1, "GL_COMPRESSED_RED_RGTC1 is not equal to _GL_COMPRESSED_RED_RGTC1");
    static_assert(GL_COMPRESSED_SIGNED_RED_RGTC1 == _GL_COMPRESSED_SIGNED_RED_RGTC1, "GL_COMPRESSED_SIGNED_RED_RGTC1 is not equal to _GL_COMPRESSED_SIGNED_RED_RGTC1");
    static_assert(GL_COMPRESSED_RG_RGTC2 == _GL_COMPRESSED_RG_RGTC2, "GL_COMPRESSED_RG_RGTC2 is not equal to _GL_COMPRESSED_RG_RGTC2");
    static_assert(GL_COMPRESSED_SIGNED_RG_RGTC2 == _GL_COMPRESSED_SIGNED_RG_RGTC2, "GL_COMPRESSED_SIGNED_RG_RGTC2 is not equal to _GL_COMPRESSED_SIGNED_RG_RGTC2");
    static_assert(GL_RG == _GL_RG, "GL_RG is not equal to _GL_RG");
    static_assert(GL_RG_INTEGER == _GL_RG_INTEGER, "GL_RG_INTEGER is not equal to _GL_RG_INTEGER");
    static_assert(GL_R8 == _GL_R8, "GL_R8 is not equal to _GL_R8");
    static_assert(GL_R16 == _GL_R16, "GL_R16 is not equal to _GL_R16");
    static_assert(GL_RG8 == _GL_RG8, "GL_RG8 is not equal to _GL_RG8");
    static_assert(GL_RG16 == _GL_RG16, "GL_RG16 is not equal to _GL_RG16");
    static_assert(GL_R16F == _GL_R16F, "GL_R16F is not equal to _GL_R16F");
    static_assert(GL_R32F == _GL_R32F, "GL_R32F is not equal to _GL_R32F");
    static_assert(GL_RG16F == _GL_RG16F, "GL_RG16F is not equal to _GL_RG16F");
    static_assert(GL_RG32F == _GL_RG32F, "GL_RG32F is not equal to _GL_RG32F");
    static_assert(GL_R8I == _GL_R8I, "GL_R8I is not equal to _GL_R8I");
    static_assert(GL_R8UI == _GL_R8UI, "GL_R8UI is not equal to _GL_R8UI");
    static_assert(GL_R16I == _GL_R16I, "GL_R16I is not equal to _GL_R16I");
    static_assert(GL_R16UI == _GL_R16UI, "GL_R16UI is not equal to _GL_R16UI");
    static_assert(GL_R32I == _GL_R32I, "GL_R32I is not equal to _GL_R32I");
    static_assert(GL_R32UI == _GL_R32UI, "GL_R32UI is not equal to _GL_R32UI");
    static_assert(GL_RG8I == _GL_RG8I, "GL_RG8I is not equal to _GL_RG8I");
    static_assert(GL_RG8UI == _GL_RG8UI, "GL_RG8UI is not equal to _GL_RG8UI");
    static_assert(GL_RG16I == _GL_RG16I, "GL_RG16I is not equal to _GL_RG16I");
    static_assert(GL_RG16UI == _GL_RG16UI, "GL_RG16UI is not equal to _GL_RG16UI");
    static_assert(GL_RG32I == _GL_RG32I, "GL_RG32I is not equal to _GL_RG32I");
    static_assert(GL_RG32UI == _GL_RG32UI, "GL_RG32UI is not equal to _GL_RG32UI");
}
#pragma endregion

#pragma region RANDOM_STUFF25
#define GL_VERTEX_ARRAY_BINDING 0x85B5
#define GL_SAMPLER_2D_RECT 0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW 0x8B64
#define GL_SAMPLER_BUFFER 0x8DC2
#define GL_INT_SAMPLER_2D_RECT 0x8DCD
#define GL_INT_SAMPLER_BUFFER 0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT 0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_BUFFER 0x8DD8
#define GL_TEXTURE_BUFFER 0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE 0x8C2B
#define GL_TEXTURE_BINDING_BUFFER 0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
#define GL_TEXTURE_RECTANGLE 0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE 0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE 0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE 0x84F8
#define GL_R8_SNORM 0x8F94
#define GL_RG8_SNORM 0x8F95
#define GL_RGB8_SNORM 0x8F96
#define GL_RGBA8_SNORM 0x8F97
#define GL_R16_SNORM 0x8F98
#define GL_RG16_SNORM 0x8F99
#define GL_RGB16_SNORM 0x8F9A
#define GL_RGBA16_SNORM 0x8F9B
    export constexpr int _GL_VERTEX_ARRAY_BINDING = 0x85B5;
    export constexpr int _GL_SAMPLER_2D_RECT = 0x8B63;
    export constexpr int _GL_SAMPLER_2D_RECT_SHADOW = 0x8B64;
    export constexpr int _GL_SAMPLER_BUFFER = 0x8DC2;
    export constexpr int _GL_INT_SAMPLER_2D_RECT = 0x8DCD;
    export constexpr int _GL_INT_SAMPLER_BUFFER = 0x8DD0;
    export constexpr int _GL_UNSIGNED_INT_SAMPLER_2D_RECT = 0x8DD5;
    export constexpr int _GL_UNSIGNED_INT_SAMPLER_BUFFER = 0x8DD8;
    export constexpr int _GL_TEXTURE_BUFFER = 0x8C2A;
    export constexpr int _GL_MAX_TEXTURE_BUFFER_SIZE = 0x8C2B;
    export constexpr int _GL_TEXTURE_BINDING_BUFFER = 0x8C2C;
    export constexpr int _GL_TEXTURE_BUFFER_DATA_STORE_BINDING = 0x8C2D;
    export constexpr int _GL_TEXTURE_RECTANGLE = 0x84F5;
    export constexpr int _GL_TEXTURE_BINDING_RECTANGLE = 0x84F6;
    export constexpr int _GL_PROXY_TEXTURE_RECTANGLE = 0x84F7;
    export constexpr int _GL_MAX_RECTANGLE_TEXTURE_SIZE = 0x84F8;
    export constexpr int _GL_R8_SNORM = 0x8F94;
    export constexpr int _GL_RG8_SNORM = 0x8F95;
    export constexpr int _GL_RGB8_SNORM = 0x8F96;
    export constexpr int _GL_RGBA8_SNORM = 0x8F97;
    export constexpr int _GL_R16_SNORM = 0x8F98;
    export constexpr int _GL_RG16_SNORM = 0x8F99;
    export constexpr int _GL_RGB16_SNORM = 0x8F9A;
    export constexpr int _GL_RGBA16_SNORM = 0x8F9B;
consteval void Check_Random_Stuff25() {
    static_assert(GL_VERTEX_ARRAY_BINDING == _GL_VERTEX_ARRAY_BINDING, "GL_VERTEX_ARRAY_BINDING is not equal to _GL_VERTEX_ARRAY_BINDING");
    static_assert(GL_SAMPLER_2D_RECT == _GL_SAMPLER_2D_RECT, "GL_SAMPLER_2D_RECT is not equal to _GL_SAMPLER_2D_RECT");
    static_assert(GL_SAMPLER_2D_RECT_SHADOW == _GL_SAMPLER_2D_RECT_SHADOW, "GL_SAMPLER_2D_RECT_SHADOW is not equal to _GL_SAMPLER_2D_RECT_SHADOW");
    static_assert(GL_SAMPLER_BUFFER == _GL_SAMPLER_BUFFER, "GL_SAMPLER_BUFFER is not equal to _GL_SAMPLER_BUFFER");
    static_assert(GL_INT_SAMPLER_2D_RECT == _GL_INT_SAMPLER_2D_RECT, "GL_INT_SAMPLER_2D_RECT is not equal to _GL_INT_SAMPLER_2D_RECT");
    static_assert(GL_INT_SAMPLER_BUFFER == _GL_INT_SAMPLER_BUFFER, "GL_INT_SAMPLER_BUFFER is not equal to _GL_INT_SAMPLER_BUFFER");
    static_assert(GL_UNSIGNED_INT_SAMPLER_2D_RECT == _GL_UNSIGNED_INT_SAMPLER_2D_RECT, "GL_UNSIGNED_INT_SAMPLER_2D_RECT is not equal to _GL_UNSIGNED_INT_SAMPLER_2D_RECT");
    static_assert(GL_UNSIGNED_INT_SAMPLER_BUFFER == _GL_UNSIGNED_INT_SAMPLER_BUFFER, "GL_UNSIGNED_INT_SAMPLER_BUFFER is not equal to _GL_UNSIGNED_INT_SAMPLER_BUFFER");
    static_assert(GL_TEXTURE_BUFFER == _GL_TEXTURE_BUFFER, "GL_TEXTURE_BUFFER is not equal to _GL_TEXTURE_BUFFER");
    static_assert(GL_MAX_TEXTURE_BUFFER_SIZE == _GL_MAX_TEXTURE_BUFFER_SIZE, "GL_MAX_TEXTURE_BUFFER_SIZE is not equal to _GL_MAX_TEXTURE_BUFFER_SIZE");
    static_assert(GL_TEXTURE_BINDING_BUFFER == _GL_TEXTURE_BINDING_BUFFER, "GL_TEXTURE_BINDING_BUFFER is not equal to _GL_TEXTURE_BINDING_BUFFER");
    static_assert(GL_TEXTURE_BUFFER_DATA_STORE_BINDING == _GL_TEXTURE_BUFFER_DATA_STORE_BINDING, "GL_TEXTURE_BUFFER_DATA_STORE_BINDING is not equal to _GL_TEXTURE_BUFFER_DATA_STORE_BINDING");
    static_assert(GL_TEXTURE_RECTANGLE == _GL_TEXTURE_RECTANGLE, "GL_TEXTURE_RECTANGLE is not equal to _GL_TEXTURE_RECTANGLE");
    static_assert(GL_TEXTURE_BINDING_RECTANGLE == _GL_TEXTURE_BINDING_RECTANGLE, "GL_TEXTURE_BINDING_RECTANGLE is not equal to _ GL_TEXTURE_BINDING_RECTANGLE");
    static_assert(GL_PROXY_TEXTURE_RECTANGLE == _GL_PROXY_TEXTURE_RECTANGLE, "GL_PROXY_TEXTURE_RECTANGLE is not equal to _GL_PROXY_TEXTURE_RECTANGLE");
    static_assert(GL_MAX_RECTANGLE_TEXTURE_SIZE == _GL_MAX_RECTANGLE_TEXTURE_SIZE, "GL_MAX_RECTANGLE_TEXTURE_SIZE is not equal to _GL_MAX_RECTANGLE_TEXTURE_SIZE");
    static_assert(GL_R8_SNORM == _GL_R8_SNORM, "GL_R8_SNORM is not equal to _GL_R8_SNORM");
    static_assert(GL_RG8_SNORM == _GL_RG8_SNORM, "GL_RG8_SNORM is not equal to _GL_RG8_SNORM");
    static_assert(GL_RGB8_SNORM == _GL_RGB8_SNORM, "GL_RGB8_SNORM is not equal to _GL_RGB8_SNORM");
    static_assert(GL_RGBA8_SNORM == _GL_RGBA8_SNORM, "GL_RGBA8_SNORM is not equal to _GL_RGBA8_SNORM");
    static_assert(GL_R16_SNORM == _GL_R16_SNORM, "GL_R16_SNORM is not equal to _GL_R16_SNORM");
    static_assert(GL_RG16_SNORM == _GL_RG16_SNORM, "GL_RG16_SNORM is not equal to _GL_RG16_SNORM");
    static_assert(GL_RGB16_SNORM == _GL_RGB16_SNORM, "GL_RGB16_SNORM is not equal to _GL_RGB16_SNORM");
    static_assert(GL_RGBA16_SNORM == _GL_RGBA16_SNORM, "GL_RGBA16_SNORM is not equal to _GL_RGBA16_SNORM");
}
#pragma endregion

#pragma region RANDOM_STUFF26
#define GL_SIGNED_NORMALIZED 0x8F9C
#define GL_PRIMITIVE_RESTART 0x8F9D
#define GL_PRIMITIVE_RESTART_INDEX 0x8F9E
#define GL_COPY_READ_BUFFER 0x8F36
#define GL_COPY_WRITE_BUFFER 0x8F37
#define GL_UNIFORM_BUFFER 0x8A11
#define GL_UNIFORM_BUFFER_BINDING 0x8A28
#define GL_UNIFORM_BUFFER_START 0x8A29
#define GL_UNIFORM_BUFFER_SIZE 0x8A2A
#define GL_MAX_VERTEX_UNIFORM_BLOCKS 0x8A2B
#define GL_MAX_GEOMETRY_UNIFORM_BLOCKS 0x8A2C
#define GL_MAX_FRAGMENT_UNIFORM_BLOCKS 0x8A2D
#define GL_MAX_COMBINED_UNIFORM_BLOCKS 0x8A2E
#define GL_MAX_UNIFORM_BUFFER_BINDINGS 0x8A2F
#define GL_MAX_UNIFORM_BLOCK_SIZE 0x8A30
#define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS 0x8A31
#define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS 0x8A32
#define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS 0x8A33
#define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT 0x8A34
#define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH 0x8A35
#define GL_ACTIVE_UNIFORM_BLOCKS 0x8A36
#define GL_UNIFORM_TYPE 0x8A37
#define GL_UNIFORM_SIZE 0x8A38
#define GL_UNIFORM_NAME_LENGTH 0x8A39
#define GL_UNIFORM_BLOCK_INDEX 0x8A3A
#define GL_UNIFORM_OFFSET 0x8A3B
#define GL_UNIFORM_ARRAY_STRIDE 0x8A3C
#define GL_UNIFORM_MATRIX_STRIDE 0x8A3D
#define GL_UNIFORM_IS_ROW_MAJOR 0x8A3E
#define GL_UNIFORM_BLOCK_BINDING 0x8A3F
#define GL_UNIFORM_BLOCK_DATA_SIZE 0x8A40
#define GL_UNIFORM_BLOCK_NAME_LENGTH 0x8A41
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS 0x8A42
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES 0x8A43
#define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER 0x8A44
#define GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER 0x8A45
#define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER 0x8A46
    export constexpr int _GL_SIGNED_NORMALIZED = 0x8F9C;
    export constexpr int _GL_PRIMITIVE_RESTART = 0x8F9D;
    export constexpr int _GL_PRIMITIVE_RESTART_INDEX = 0x8F9E;
    export constexpr int _GL_COPY_READ_BUFFER = 0x8F36;
    export constexpr int _GL_COPY_WRITE_BUFFER = 0x8F37;
    export constexpr int _GL_UNIFORM_BUFFER = 0x8A11;
    export constexpr int _GL_UNIFORM_BUFFER_BINDING = 0x8A28;
    export constexpr int _GL_UNIFORM_BUFFER_START = 0x8A29;
    export constexpr int _GL_UNIFORM_BUFFER_SIZE = 0x8A2A;
    export constexpr int _GL_MAX_VERTEX_UNIFORM_BLOCKS = 0x8A2B;
    export constexpr int _GL_MAX_GEOMETRY_UNIFORM_BLOCKS = 0x8A2C;
    export constexpr int _GL_MAX_FRAGMENT_UNIFORM_BLOCKS = 0x8A2D;
    export constexpr int _GL_MAX_COMBINED_UNIFORM_BLOCKS = 0x8A2E;
    export constexpr int _GL_MAX_UNIFORM_BUFFER_BINDINGS = 0x8A2F;
    export constexpr int _GL_MAX_UNIFORM_BLOCK_SIZE = 0x8A30;
    export constexpr int _GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS = 0x8A31;
    export constexpr int _GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS = 0x8A32;
    export constexpr int _GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS = 0x8A33;
    export constexpr int _GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT = 0x8A34;
    export constexpr int _GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH = 0x8A35;
    export constexpr int _GL_ACTIVE_UNIFORM_BLOCKS = 0x8A36;
    export constexpr int _GL_UNIFORM_TYPE = 0x8A37;
    export constexpr int _GL_UNIFORM_SIZE = 0x8A38;
    export constexpr int _GL_UNIFORM_NAME_LENGTH = 0x8A39;
    export constexpr int _GL_UNIFORM_BLOCK_INDEX = 0x8A3A;
    export constexpr int _GL_UNIFORM_OFFSET = 0x8A3B;
    export constexpr int _GL_UNIFORM_ARRAY_STRIDE = 0x8A3C;
    export constexpr int _GL_UNIFORM_MATRIX_STRIDE = 0x8A3D;
    export constexpr int _GL_UNIFORM_IS_ROW_MAJOR = 0x8A3E;
    export constexpr int _GL_UNIFORM_BLOCK_BINDING = 0x8A3F;
    export constexpr int _GL_UNIFORM_BLOCK_DATA_SIZE = 0x8A40;
    export constexpr int _GL_UNIFORM_BLOCK_NAME_LENGTH = 0x8A41;
    export constexpr int _GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS = 0x8A42;
    export constexpr int _GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES = 0x8A43;
    export constexpr int _GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER = 0x8A44;
    export constexpr int _GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER = 0x8A45;
    export constexpr int _GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER = 0x8A46;

consteval void Check_Random_Stuff26() {
    static_assert(GL_SIGNED_NORMALIZED == _GL_SIGNED_NORMALIZED, "GL_SIGNED_NORMALIZED is not equal to _GL_SIGNED_NORMALIZED");
    static_assert(GL_PRIMITIVE_RESTART == _GL_PRIMITIVE_RESTART, "GL_PRIMITIVE_RESTART is not equal to _GL_PRIMITIVE_RESTART");
    static_assert(GL_PRIMITIVE_RESTART_INDEX == _GL_PRIMITIVE_RESTART_INDEX, "GL_PRIMITIVE_RESTART_INDEX is not equal to _GL_PRIMITIVE_RESTART_INDEX");
    static_assert(GL_COPY_READ_BUFFER == _GL_COPY_READ_BUFFER, "GL_COPY_READ_BUFFER is not equal to _GL_COPY_READ_BUFFER");
    static_assert(GL_COPY_WRITE_BUFFER == _GL_COPY_WRITE_BUFFER, "GL_COPY_WRITE_BUFFER is not equal to _GL_COPY_WRITE_BUFFER");
    static_assert(GL_UNIFORM_BUFFER == _GL_UNIFORM_BUFFER, "GL_UNIFORM_BUFFER is not equal to _GL_UNIFORM_BUFFER");
    static_assert(GL_UNIFORM_BUFFER_BINDING == _GL_UNIFORM_BUFFER_BINDING, "GL_UNIFORM_BUFFER_BINDING is not equal to _GL_UNIFORM_BUFFER_BINDING");
    static_assert(GL_UNIFORM_BUFFER_START == _GL_UNIFORM_BUFFER_START, "GL_UNIFORM_BUFFER_START is not equal to _GL_UNIFORM_BUFFER_START");
    static_assert(GL_UNIFORM_BUFFER_SIZE == _GL_UNIFORM_BUFFER_SIZE, "GL_UNIFORM_BUFFER_SIZE is not equal to _GL_UNIFORM_BUFFER_SIZE");
    static_assert(GL_MAX_VERTEX_UNIFORM_BLOCKS == _GL_MAX_VERTEX_UNIFORM_BLOCKS, "GL_MAX_VERTEX_UNIFORM_BLOCKS is not equal to _GL_MAX_VERTEX_UNIFORM_BLOCKS");
    static_assert(GL_MAX_GEOMETRY_UNIFORM_BLOCKS == _GL_MAX_GEOMETRY_UNIFORM_BLOCKS, "GL_MAX_GEOMETRY_UNIFORM_BLOCKS is not equal to _GL_MAX_GEOMETRY_UNIFORM_BLOCKS");
    static_assert(GL_MAX_FRAGMENT_UNIFORM_BLOCKS == _GL_MAX_FRAGMENT_UNIFORM_BLOCKS, "GL_MAX_FRAGMENT_UNIFORM_BLOCKS is not equal to _GL_MAX_FRAGMENT_UNIFORM_BLOCKS");
    static_assert(GL_MAX_COMBINED_UNIFORM_BLOCKS == _GL_MAX_COMBINED_UNIFORM_BLOCKS, "GL_MAX_COMBINED_UNIFORM_BLOCKS is not equal to _GL_MAX_COMBINED_UNIFORM_BLOCKS");
    static_assert(GL_MAX_UNIFORM_BUFFER_BINDINGS == _GL_MAX_UNIFORM_BUFFER_BINDINGS, "GL_MAX_UNIFORM_BUFFER_BINDINGS is not equal to _GL_MAX_UNIFORM_BUFFER_BINDINGS");
    static_assert(GL_MAX_UNIFORM_BLOCK_SIZE == _GL_MAX_UNIFORM_BLOCK_SIZE, "GL_MAX_UNIFORM_BLOCK_SIZE is not equal to _GL_MAX_UNIFORM_BLOCK_SIZE");
    static_assert(GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS == _GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS, "GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS is not equal to _GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS");
    static_assert(GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS == _GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS, "GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS is not equal to _GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS");
    static_assert(GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS == _GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS, "GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS is not equal to _GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS");
    static_assert(GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT == _GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT, "GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT is not equal to _GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT");
    static_assert(GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH == _GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH, "GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH is not equal to _GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH");
    static_assert(GL_ACTIVE_UNIFORM_BLOCKS == _GL_ACTIVE_UNIFORM_BLOCKS, "GL_ACTIVE_UNIFORM_BLOCKS is not equal to _GL_ACTIVE_UNIFORM_BLOCKS");
    static_assert(GL_UNIFORM_TYPE == _GL_UNIFORM_TYPE, "GL_UNIFORM_TYPE is not equal to _GL_UNIFORM_TYPE");
    static_assert(GL_UNIFORM_SIZE == _GL_UNIFORM_SIZE, "GL_UNIFORM_SIZE is not equal to _GL_UNIFORM_SIZE");
    static_assert(GL_UNIFORM_NAME_LENGTH == _GL_UNIFORM_NAME_LENGTH, "GL_UNIFORM_NAME_LENGTH is not equal to _GL_UNIFORM_NAME_LENGTH");
    static_assert(GL_UNIFORM_BLOCK_INDEX == _GL_UNIFORM_BLOCK_INDEX, "GL_UNIFORM_BLOCK_INDEX is not equal to _GL_UNIFORM_BLOCK_INDEX");
    static_assert(GL_UNIFORM_OFFSET == _GL_UNIFORM_OFFSET, "GL_UNIFORM_OFFSET is not equal to _GL_UNIFORM_OFFSET");
    static_assert(GL_UNIFORM_ARRAY_STRIDE == _GL_UNIFORM_ARRAY_STRIDE, "GL_UNIFORM_ARRAY_STRIDE is not equal to _GL_UNIFORM_ARRAY_STRIDE");
    static_assert(GL_UNIFORM_MATRIX_STRIDE == _GL_UNIFORM_MATRIX_STRIDE, "GL_UNIFORM_MATRIX_STRIDE is not equal to _GL_UNIFORM_MATRIX_STRIDE");
    static_assert(GL_UNIFORM_IS_ROW_MAJOR == _GL_UNIFORM_IS_ROW_MAJOR, "GL_UNIFORM_IS_ROW_MAJOR is not equal to _GL_UNIFORM_IS_ROW_MAJOR");
    static_assert(GL_UNIFORM_BLOCK_BINDING == _GL_UNIFORM_BLOCK_BINDING, "GL_UNIFORM_BLOCK_BINDING is not equal to _GL_UNIFORM_BLOCK_BINDING");
    static_assert(GL_UNIFORM_BLOCK_DATA_SIZE == _GL_UNIFORM_BLOCK_DATA_SIZE, "GL_UNIFORM_BLOCK_DATA_SIZE is not equal to _GL_UNIFORM_BLOCK_DATA_SIZE");
    static_assert(GL_UNIFORM_BLOCK_NAME_LENGTH == _GL_UNIFORM_BLOCK_NAME_LENGTH, "GL_UNIFORM_BLOCK_NAME_LENGTH is not equal to _GL_UNIFORM_BLOCK_NAME_LENGTH");
    static_assert(GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS == _GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS, "GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS is not equal to _GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS");
    static_assert(GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES == _GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES, "GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES is not equal to _GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES");
    static_assert(GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER == _GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER, "GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER is not equal to _GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER");
    static_assert(GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER == _GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER, "GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER is not equal to _GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER");
    static_assert(GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER == _GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER, "GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER is not equal to _GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER");
}
#pragma endregion

#pragma region RANDOM_STUFF27
#define GL_INVALID_INDEX 0xFFFFFFFF
#define GL_CONTEXT_CORE_PROFILE_BIT 0x00000001
#define GL_CONTEXT_COMPATIBILITY_PROFILE_BIT 0x00000002
#define GL_LINES_ADJACENCY 0x000A
#define GL_LINE_STRIP_ADJACENCY 0x000B
#define GL_TRIANGLES_ADJACENCY 0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY 0x000D
#define GL_PROGRAM_POINT_SIZE 0x8642
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS 0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS 0x8DA8
#define GL_GEOMETRY_SHADER 0x8DD9
#define GL_GEOMETRY_VERTICES_OUT 0x8916
#define GL_GEOMETRY_INPUT_TYPE 0x8917
#define GL_GEOMETRY_OUTPUT_TYPE 0x8918
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES 0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS 0x8DE1
#define GL_MAX_VERTEX_OUTPUT_COMPONENTS 0x9122
#define GL_MAX_GEOMETRY_INPUT_COMPONENTS 0x9123
#define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS 0x9124
#define GL_MAX_FRAGMENT_INPUT_COMPONENTS 0x9125
#define GL_CONTEXT_PROFILE_MASK 0x9126
#define GL_DEPTH_CLAMP 0x864F
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION 0x8E4C
#define GL_FIRST_VERTEX_CONVENTION 0x8E4D
#define GL_LAST_VERTEX_CONVENTION 0x8E4E
#define GL_PROVOKING_VERTEX 0x8E4F
#define GL_TEXTURE_CUBE_MAP_SEAMLESS 0x884F
#define GL_MAX_SERVER_WAIT_TIMEOUT 0x9111
#define GL_OBJECT_TYPE 0x9112
#define GL_SYNC_CONDITION 0x9113
#define GL_SYNC_STATUS 0x9114
    export constexpr int _GL_INVALID_INDEX = 0xFFFFFFFF;
    export constexpr int _GL_CONTEXT_CORE_PROFILE_BIT = 0x00000001;
    export constexpr int _GL_CONTEXT_COMPATIBILITY_PROFILE_BIT = 0x00000002;
    export constexpr int _GL_LINES_ADJACENCY = 0x000A;
    export constexpr int _GL_LINE_STRIP_ADJACENCY = 0x000B;
    export constexpr int _GL_TRIANGLES_ADJACENCY = 0x000C;
    export constexpr int _GL_TRIANGLE_STRIP_ADJACENCY = 0x000D;
    export constexpr int _GL_PROGRAM_POINT_SIZE = 0x8642;
    export constexpr int _GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS = 0x8C29;
    export constexpr int _GL_FRAMEBUFFER_ATTACHMENT_LAYERED = 0x8DA7;
    export constexpr int _GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS = 0x8DA8;
    export constexpr int _GL_GEOMETRY_SHADER = 0x8DD9;
    export constexpr int _GL_GEOMETRY_VERTICES_OUT = 0x8916;
    export constexpr int _GL_GEOMETRY_INPUT_TYPE = 0x8917;
    export constexpr int _GL_GEOMETRY_OUTPUT_TYPE = 0x8918;
    export constexpr int _GL_MAX_GEOMETRY_UNIFORM_COMPONENTS = 0x8DDF;
    export constexpr int _GL_MAX_GEOMETRY_OUTPUT_VERTICES = 0x8DE0;
    export constexpr int _GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS = 0x8DE1;
    export constexpr int _GL_MAX_VERTEX_OUTPUT_COMPONENTS = 0x9122;
    export constexpr int _GL_MAX_GEOMETRY_INPUT_COMPONENTS = 0x9123;
    export constexpr int _GL_MAX_GEOMETRY_OUTPUT_COMPONENTS = 0x9124;
    export constexpr int _GL_MAX_FRAGMENT_INPUT_COMPONENTS = 0x9125;
    export constexpr int _GL_CONTEXT_PROFILE_MASK = 0x9126;
    export constexpr int _GL_DEPTH_CLAMP = 0x864F;
    export constexpr int _GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION = 0x8E4C;
    export constexpr int _GL_FIRST_VERTEX_CONVENTION = 0x8E4D;
    export constexpr int _GL_LAST_VERTEX_CONVENTION = 0x8E4E;
    export constexpr int _GL_PROVOKING_VERTEX = 0x8E4F;
    export constexpr int _GL_TEXTURE_CUBE_MAP_SEAMLESS = 0x884F;
    export constexpr int _GL_MAX_SERVER_WAIT_TIMEOUT = 0x9111;
    export constexpr int _GL_OBJECT_TYPE = 0x9112;
    export constexpr int _GL_SYNC_CONDITION = 0x9113;
    export constexpr int _GL_SYNC_STATUS = 0x9114;
consteval void Check_Random_Stuff27() {
    static_assert(GL_INVALID_INDEX == _GL_INVALID_INDEX, "GL_INVALID_INDEX is not equal to _GL_INVALID_INDEX"); //-V2523
    static_assert(GL_CONTEXT_CORE_PROFILE_BIT == _GL_CONTEXT_CORE_PROFILE_BIT, "GL_CONTEXT_CORE_PROFILE_BIT is not equal to _GL_CONTEXT_CORE_PROFILE_BIT");
    static_assert(GL_CONTEXT_COMPATIBILITY_PROFILE_BIT == _GL_CONTEXT_COMPATIBILITY_PROFILE_BIT, "GL_CONTEXT_COMPATIBILITY_PROFILE_BIT is not equal to _GL_CONTEXT_COMPATIBILITY_PROFILE_BIT");
    static_assert(GL_LINES_ADJACENCY == _GL_LINES_ADJACENCY, "GL_LINES_ADJACENCY is not equal to _GL_LINES_ADJACENCY");
    static_assert(GL_LINE_STRIP_ADJACENCY == _GL_LINE_STRIP_ADJACENCY, "GL_LINE_STRIP_ADJACENCY is not equal to _GL_LINE_STRIP_ADJACENCY");
    static_assert(GL_TRIANGLES_ADJACENCY == _GL_TRIANGLES_ADJACENCY, "GL_TRIANGLES_ADJACENCY is not equal to _GL_TRIANGLES_ADJACENCY");
    static_assert(GL_TRIANGLE_STRIP_ADJACENCY == _GL_TRIANGLE_STRIP_ADJACENCY, "GL_TRIANGLE_STRIP_ADJACENCY is not equal to _GL_TRIANGLE_STRIP_ADJACENCY");
    static_assert(GL_PROGRAM_POINT_SIZE == _GL_PROGRAM_POINT_SIZE, "GL_PROGRAM_POINT_SIZE is not equal to _GL_PROGRAM_POINT_SIZE");
    static_assert(GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS == _GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS, "GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS is not equal to _GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS");
    static_assert(GL_FRAMEBUFFER_ATTACHMENT_LAYERED == _GL_FRAMEBUFFER_ATTACHMENT_LAYERED, "GL_FRAMEBUFFER_ATTACHMENT_LAYERED is not equal to _GL_FRAMEBUFFER_ATTACHMENT_LAYERED");
    static_assert(GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS == _GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS, "GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS is not equal to _GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS");
    static_assert(GL_GEOMETRY_SHADER == _GL_GEOMETRY_SHADER, "GL_GEOMETRY_SHADER is not equal to _GL_GEOMETRY_SHADER");
    static_assert(GL_GEOMETRY_VERTICES_OUT == _GL_GEOMETRY_VERTICES_OUT, "GL_GEOMETRY_VERTICES_OUT is not equal to _GL_GEOMETRY_VERTICES_OUT");
    static_assert(GL_GEOMETRY_INPUT_TYPE == _GL_GEOMETRY_INPUT_TYPE, "GL_GEOMETRY_INPUT_TYPE is not equal to _GL_GEOMETRY_INPUT_TYPE");
    static_assert(GL_GEOMETRY_OUTPUT_TYPE == _GL_GEOMETRY_OUTPUT_TYPE, "GL_GEOMETRY_OUTPUT_TYPE is not equal to _GL_GEOMETRY_OUTPUT_TYPE");
    static_assert(GL_MAX_GEOMETRY_UNIFORM_COMPONENTS == _GL_MAX_GEOMETRY_UNIFORM_COMPONENTS, "GL_MAX_GEOMETRY_UNIFORM_COMPONENTS is not equal to _GL_MAX_GEOMETRY_UNIFORM_COMPONENTS");
    static_assert(GL_MAX_GEOMETRY_OUTPUT_VERTICES == _GL_MAX_GEOMETRY_OUTPUT_VERTICES, "GL_MAX_GEOMETRY_OUTPUT_VERTICES is not equal to _GL_MAX_GEOMETRY_OUTPUT_VERTICES");
    static_assert(GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS == _GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS, "GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS is not equal to _GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS");
    static_assert(GL_MAX_VERTEX_OUTPUT_COMPONENTS == _GL_MAX_VERTEX_OUTPUT_COMPONENTS, "GL_MAX_VERTEX_OUTPUT_COMPONENTS is not equal to _GL_MAX_VERTEX_OUTPUT_COMPONENTS");
    static_assert(GL_MAX_GEOMETRY_INPUT_COMPONENTS == _GL_MAX_GEOMETRY_INPUT_COMPONENTS, "GL_MAX_GEOMETRY_INPUT_COMPONENTS is not equal to _GL_MAX_GEOMETRY_INPUT_COMPONENTS");
    static_assert(GL_MAX_GEOMETRY_OUTPUT_COMPONENTS == _GL_MAX_GEOMETRY_OUTPUT_COMPONENTS, "GL_MAX_GEOMETRY_OUTPUT_COMPONENTS is not equal to _GL_MAX_GEOMETRY_OUTPUT_COMPONENTS");
    static_assert(GL_MAX_FRAGMENT_INPUT_COMPONENTS == _GL_MAX_FRAGMENT_INPUT_COMPONENTS, "GL_MAX_FRAGMENT_INPUT_COMPONENTS is not equal to _GL_MAX_FRAGMENT_INPUT_COMPONENTS");
    static_assert(GL_CONTEXT_PROFILE_MASK == _GL_CONTEXT_PROFILE_MASK, "GL_CONTEXT_PROFILE_MASK is not equal to _GL_CONTEXT_PROFILE_MASK");
    static_assert(GL_DEPTH_CLAMP == _GL_DEPTH_CLAMP, "GL_DEPTH_CLAMP is not equal to _GL_DEPTH_CLAMP");
    static_assert(GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION == _GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION, "GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION is not equal to _GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION");
    static_assert(GL_FIRST_VERTEX_CONVENTION == _GL_FIRST_VERTEX_CONVENTION, "GL_FIRST_VERTEX_CONVENTION is not equal to _GL_FIRST_VERTEX_CONVENTION");
    static_assert(GL_LAST_VERTEX_CONVENTION == _GL_LAST_VERTEX_CONVENTION, "GL_LAST_VERTEX_CONVENTION is not equal to _GL_LAST_VERTEX_CONVENTION");
    static_assert(GL_PROVOKING_VERTEX == _GL_PROVOKING_VERTEX, "GL_PROVOKING_VERTEX is not equal to _GL_PROVOKING_VERTEX");
    static_assert(GL_TEXTURE_CUBE_MAP_SEAMLESS == _GL_TEXTURE_CUBE_MAP_SEAMLESS, "GL_TEXTURE_CUBE_MAP_SEAMLESS is not equal to _GL_TEXTURE_CUBE_MAP_SEAMLESS");
    static_assert(GL_MAX_SERVER_WAIT_TIMEOUT == _GL_MAX_SERVER_WAIT_TIMEOUT, "GL_MAX_SERVER_WAIT_TIMEOUT is not equal to _GL_MAX_SERVER_WAIT_TIMEOUT");
    static_assert(GL_OBJECT_TYPE == _GL_OBJECT_TYPE, "GL_OBJECT_TYPE is not equal to _GL_OBJECT_TYPE");
    static_assert(GL_SYNC_CONDITION == _GL_SYNC_CONDITION, "GL_SYNC_CONDITION is not equal to _GL_SYNC_CONDITION");
    static_assert(GL_SYNC_STATUS == _GL_SYNC_STATUS, "GL_SYNC_STATUS is not equal to _GL_SYNC_STATUS");
}
#pragma endregion

#pragma region RANDOM_STUFF28
#define GL_SYNC_FLAGS 0x9115
#define GL_SYNC_FENCE 0x9116
#define GL_SYNC_GPU_COMMANDS_COMPLETE 0x9117
#define GL_UNSIGNALED 0x9118
#define GL_SIGNALED 0x9119
#define GL_ALREADY_SIGNALED 0x911A
#define GL_TIMEOUT_EXPIRED 0x911B
#define GL_CONDITION_SATISFIED 0x911C
#define GL_WAIT_FAILED 0x911D
#define GL_TIMEOUT_IGNORED 0xFFFFFFFFFFFFFFFF
#define GL_SYNC_FLUSH_COMMANDS_BIT 0x00000001
#define GL_SAMPLE_POSITION 0x8E50
#define GL_SAMPLE_MASK 0x8E51
#define GL_SAMPLE_MASK_VALUE 0x8E52
#define GL_MAX_SAMPLE_MASK_WORDS 0x8E59
#define GL_TEXTURE_2D_MULTISAMPLE 0x9100
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE 0x9101
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9102
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9103
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE 0x9104
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY 0x9105
#define GL_TEXTURE_SAMPLES 0x9106
#define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS 0x9107
#define GL_SAMPLER_2D_MULTISAMPLE 0x9108
#define GL_INT_SAMPLER_2D_MULTISAMPLE 0x9109
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE 0x910A
#define GL_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910B
#define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910C
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910D
    export constexpr int _GL_SYNC_FLAGS = 0x9115;
    export constexpr int _GL_SYNC_FENCE = 0x9116;
    export constexpr int _GL_SYNC_GPU_COMMANDS_COMPLETE = 0x9117;
    export constexpr int _GL_UNSIGNALED = 0x9118;
    export constexpr int _GL_SIGNALED = 0x9119;
    export constexpr int _GL_ALREADY_SIGNALED = 0x911A;
    export constexpr int _GL_TIMEOUT_EXPIRED = 0x911B;
    export constexpr int _GL_CONDITION_SATISFIED = 0x911C;
    export constexpr int _GL_WAIT_FAILED = 0x911D;
    export constexpr unsigned long long _GL_TIMEOUT_IGNORED = 0xFFFFFFFFFFFFFFFF;
    export constexpr int _GL_SYNC_FLUSH_COMMANDS_BIT = 0x00000001;
    export constexpr int _GL_SAMPLE_POSITION = 0x8E50;
    export constexpr int _GL_SAMPLE_MASK = 0x8E51;
    export constexpr int _GL_SAMPLE_MASK_VALUE = 0x8E52;
    export constexpr int _GL_MAX_SAMPLE_MASK_WORDS = 0x8E59;
    export constexpr int _GL_TEXTURE_2D_MULTISAMPLE = 0x9100;
    export constexpr int _GL_PROXY_TEXTURE_2D_MULTISAMPLE = 0x9101;
    export constexpr int _GL_TEXTURE_2D_MULTISAMPLE_ARRAY = 0x9102;
    export constexpr int _GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY = 0x9103;
    export constexpr int _GL_TEXTURE_BINDING_2D_MULTISAMPLE = 0x9104;
    export constexpr int _GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY = 0x9105;
    export constexpr int _GL_TEXTURE_SAMPLES = 0x9106;
    export constexpr int _GL_TEXTURE_FIXED_SAMPLE_LOCATIONS = 0x9107;
    export constexpr int _GL_SAMPLER_2D_MULTISAMPLE = 0x9108;
    export constexpr int _GL_INT_SAMPLER_2D_MULTISAMPLE = 0x9109;
    export constexpr int _GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE = 0x910A;
    export constexpr int _GL_SAMPLER_2D_MULTISAMPLE_ARRAY = 0x910B;
    export constexpr int _GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY = 0x910C;
    export constexpr int _GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY = 0x910D;
consteval void Check_Random_Stuff28() {
    static_assert(GL_SYNC_FLAGS == _GL_SYNC_FLAGS, "GL_SYNC_FLAGS is not equal to _GL_SYNC_FLAGS");
    static_assert(GL_SYNC_FENCE == _GL_SYNC_FENCE, "GL_SYNC_FENCE is not equal to _GL_SYNC_FENCE");
    static_assert(GL_SYNC_GPU_COMMANDS_COMPLETE == _GL_SYNC_GPU_COMMANDS_COMPLETE, "GL_SYNC_GPU_COMMANDS_COMPLETE is not equal to _GL_SYNC_GPU_COMMANDS_COMPLETE");
    static_assert(GL_UNSIGNALED == _GL_UNSIGNALED, "GL_UNSIGNALED is not equal to _GL_UNSIGNALED");
    static_assert(GL_SIGNALED == _GL_SIGNALED, "GL_SIGNALED is not equal to _GL_SIGNALED");
    static_assert(GL_ALREADY_SIGNALED == _GL_ALREADY_SIGNALED, "GL_ALREADY_SIGNALED is not equal to _GL_ALREADY_SIGNALED");
    static_assert(GL_TIMEOUT_EXPIRED == _GL_TIMEOUT_EXPIRED, "GL_TIMEOUT_EXPIRED is not equal to _GL_TIMEOUT_EXPIRED");
    static_assert(GL_CONDITION_SATISFIED == _GL_CONDITION_SATISFIED, "GL_CONDITION_SATISFIED is not equal to _GL_CONDITION_SATISFIED");
    static_assert(GL_WAIT_FAILED == _GL_WAIT_FAILED, "GL_WAIT_FAILED is not equal to _GL_WAIT_FAILED");
    static_assert(GL_TIMEOUT_IGNORED == _GL_TIMEOUT_IGNORED, "GL_TIMEOUT_IGNORED is not equal to _GL_TIMEOUT_IGNORED"); //-V2523
    static_assert(GL_SYNC_FLUSH_COMMANDS_BIT == _GL_SYNC_FLUSH_COMMANDS_BIT, "GL_SYNC_FLUSH_COMMANDS_BIT is not equal to _GL_SYNC_FLUSH_COMMANDS_BIT");
    static_assert(GL_SAMPLE_POSITION == _GL_SAMPLE_POSITION, "GL_SAMPLE_POSITION is not equal to _GL_SAMPLE_POSITION");
    static_assert(GL_SAMPLE_MASK == _GL_SAMPLE_MASK, "GL_SAMPLE_MASK is not equal to _GL_SAMPLE_MASK");
    static_assert(GL_SAMPLE_MASK_VALUE == _GL_SAMPLE_MASK_VALUE, "GL_SAMPLE_MASK_VALUE is not equal to _GL_SAMPLE_MASK_VALUE");
    static_assert(GL_MAX_SAMPLE_MASK_WORDS == _GL_MAX_SAMPLE_MASK_WORDS, "GL_MAX_SAMPLE_MASK_WORDS is not equal to _GL_MAX_SAMPLE_MASK_WORDS");
    static_assert(GL_TEXTURE_2D_MULTISAMPLE == _GL_TEXTURE_2D_MULTISAMPLE, "GL_TEXTURE_2D_MULT ISAMPLE is not equal to _GL_TEXTURE_2D_MULT ISAMPLE");
    static_assert(GL_PROXY_TEXTURE_2D_MULTISAMPLE == _GL_PROXY_TEXTURE_2D_MULTISAMPLE, "GL_PROXY_TEXTURE_2D_MULT ISAMPLE is not equal to _GL_PROXY_TEXTURE_2D_MULT ISAMPLE");
    static_assert(GL_TEXTURE_2D_MULTISAMPLE_ARRAY == _GL_TEXTURE_2D_MULTISAMPLE_ARRAY, "GL_TEXTURE_2D_MULT ISAMPLE_ARRAY is not equal to _GL_TEXTURE_2D_MULT ISAMPLE_ARRAY");
    static_assert(GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY == _GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY, "GL_PROXY_TEXTURE_2D_MULT ISAMPLE_ARRAY is not equal to _GL_PROXY_TEXTURE_2D_MULT ISAMPLE_ARRAY");
    static_assert(GL_TEXTURE_BINDING_2D_MULTISAMPLE == _GL_TEXTURE_BINDING_2D_MULTISAMPLE, "GL_TEXTURE_BINDING_2D_MULT ISAMPLE is not equal to _GL_TEXTURE_BINDING_2D_MULT ISAMPLE");
    static_assert(GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY == _GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY, "GL_TEXTURE_BINDING_2D_MULT ISAMPLE_ARRAY is not equal to _GL_TEXTURE_BINDING_2D_MULT ISAMPLE_ARRAY");
    static_assert(GL_TEXTURE_SAMPLES == _GL_TEXTURE_SAMPLES, "GL_TEXTURE_SAMPLES is not equal to _GL_TEXTURE_SAMPLES");
    static_assert(GL_TEXTURE_FIXED_SAMPLE_LOCATIONS == _GL_TEXTURE_FIXED_SAMPLE_LOCATIONS, "GL_TEXTURE_FIXED_SAMPLE_LOCATIONS is not equal to _GL_TEXTURE_FIXED_SAMPLE_LOCATIONS");
    static_assert(GL_SAMPLER_2D_MULTISAMPLE == _GL_SAMPLER_2D_MULTISAMPLE, "GL_SAMPLER_2D_MULT ISAMPLE is not equal to _GL_SAMPLER_2D_MULT ISAMPLE");
    static_assert(GL_INT_SAMPLER_2D_MULTISAMPLE == _GL_INT_SAMPLER_2D_MULTISAMPLE, "GL_INT_SAMPLER_2D_MULT ISAMPLE is not equal to _GL_INT_SAMPLER_2D_MULT ISAMPLE");
    static_assert(GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE == _GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE, "GL_UNSIGNED_INT_SAMPLER_2D_MULT ISAMPLE is not equal to _GL_UNSIGNED_INT_SAMPLER_2D_MULT ISAMPLE");
    static_assert(GL_SAMPLER_2D_MULTISAMPLE_ARRAY == _GL_SAMPLER_2D_MULTISAMPLE_ARRAY, "GL_SAMPLER_2D_MULT ISAMPLE_ARRAY is not equal to _GL_SAMPLER_2D_MULT ISAMPLE_ARRAY");
    static_assert(GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY == _GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY, "GL_INT_SAMPLER_2D_MULT ISAMPLE_ARRAY is not equal to _GL_INT_SAMPLER_2D_MULT ISAMPLE_ARRAY");
    static_assert(GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY == _GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY, "GL_UNSIGNED_INT_SAMPLER_2D_MULT ISAMPLE_ARRAY is not equal to _GL_UNSIGNED_INT_SAMPLER_2D_MULT ISAMPLE_ARRAY");
}
#pragma endregion

#pragma region RANDOM_STUFF29
#define GL_MAX_COLOR_TEXTURE_SAMPLES 0x910E
#define GL_MAX_DEPTH_TEXTURE_SAMPLES 0x910F
#define GL_MAX_INTEGER_SAMPLES 0x9110
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR 0x88FE
#define GL_SRC1_COLOR 0x88F9
#define GL_ONE_MINUS_SRC1_COLOR 0x88FA
#define GL_ONE_MINUS_SRC1_ALPHA 0x88FB
#define GL_MAX_DUAL_SOURCE_DRAW_BUFFERS 0x88FC
#define GL_ANY_SAMPLES_PASSED 0x8C2F
#define GL_SAMPLER_BINDING 0x8919
#define GL_RGB10_A2UI 0x906F
#define GL_TEXTURE_SWIZZLE_R 0x8E42
#define GL_TEXTURE_SWIZZLE_G 0x8E43
#define GL_TEXTURE_SWIZZLE_B 0x8E44
#define GL_TEXTURE_SWIZZLE_A 0x8E45
#define GL_TEXTURE_SWIZZLE_RGBA 0x8E46
#define GL_TIME_ELAPSED 0x88BF
#define GL_TIMESTAMP 0x8E28
#define GL_INT_2_10_10_10_REV 0x8D9F
#define GL_SAMPLE_SHADING 0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE 0x8C37
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5F
#define GL_TEXTURE_CUBE_MAP_ARRAY 0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY 0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY 0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW 0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY 0x900E

    export constexpr int _GL_MAX_COLOR_TEXTURE_SAMPLES = 0x910E;
    export constexpr int _GL_MAX_DEPTH_TEXTURE_SAMPLES = 0x910F;
    export constexpr int _GL_MAX_INTEGER_SAMPLES = 0x9110;
    export constexpr int _GL_VERTEX_ATTRIB_ARRAY_DIVISOR = 0x88FE;
    export constexpr int _GL_SRC1_COLOR = 0x88F9;
    export constexpr int _GL_ONE_MINUS_SRC1_COLOR = 0x88FA;
    export constexpr int _GL_ONE_MINUS_SRC1_ALPHA = 0x88FB;
    export constexpr int _GL_MAX_DUAL_SOURCE_DRAW_BUFFERS = 0x88FC;
    export constexpr int _GL_ANY_SAMPLES_PASSED = 0x8C2F;
    export constexpr int _GL_SAMPLER_BINDING = 0x8919;
    export constexpr int _GL_RGB10_A2UI = 0x906F;
    export constexpr int _GL_TEXTURE_SWIZZLE_R = 0x8E42;
    export constexpr int _GL_TEXTURE_SWIZZLE_G = 0x8E43;
    export constexpr int _GL_TEXTURE_SWIZZLE_B = 0x8E44;
    export constexpr int _GL_TEXTURE_SWIZZLE_A = 0x8E45;
    export constexpr int _GL_TEXTURE_SWIZZLE_RGBA = 0x8E46;
    export constexpr int _GL_TIME_ELAPSED = 0x88BF;
    export constexpr int _GL_TIMESTAMP = 0x8E28;
    export constexpr int _GL_INT_2_10_10_10_REV = 0x8D9F;
    export constexpr int _GL_SAMPLE_SHADING = 0x8C36;
    export constexpr int _GL_MIN_SAMPLE_SHADING_VALUE = 0x8C37;
    export constexpr int _GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET = 0x8E5E;
    export constexpr int _GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET = 0x8E5F;
    export constexpr int _GL_TEXTURE_CUBE_MAP_ARRAY = 0x9009;
    export constexpr int _GL_TEXTURE_BINDING_CUBE_MAP_ARRAY = 0x900A;
    export constexpr int _GL_PROXY_TEXTURE_CUBE_MAP_ARRAY = 0x900B;
    export constexpr int _GL_SAMPLER_CUBE_MAP_ARRAY = 0x900C;
    export constexpr int _GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW = 0x900D;
    export constexpr int _GL_INT_SAMPLER_CUBE_MAP_ARRAY = 0x900E;
consteval void Check_Random_Stuff29() {
    static_assert(GL_MAX_COLOR_TEXTURE_SAMPLES == _GL_MAX_COLOR_TEXTURE_SAMPLES, "GL_MAX_COLOR_TEXTURE_SAMPLES is not equal to _GL_MAX_COLOR_TEXTURE_SAMPLES");
    static_assert(GL_MAX_DEPTH_TEXTURE_SAMPLES == _GL_MAX_DEPTH_TEXTURE_SAMPLES, "GL_MAX_DEPTH_TEXTURE_SAMPLES is not equal to _GL_MAX_DEPTH_TEXTURE_SAMPLES");
    static_assert(GL_MAX_INTEGER_SAMPLES == _GL_MAX_INTEGER_SAMPLES, "GL_MAX_INTEGER_SAMPLES is not equal to _GL_MAX_INTEGER_SAMPLES");
    static_assert(GL_VERTEX_ATTRIB_ARRAY_DIVISOR == _GL_VERTEX_ATTRIB_ARRAY_DIVISOR, "GL_VERTEX_ATTRIB_ARRAY_DIVISOR is not equal to _GL_VERTEX_ATTRIB_ARRAY_DIVISOR");
    static_assert(GL_SRC1_COLOR == _GL_SRC1_COLOR, "GL_SRC1_COLOR is not equal to _GL_SRC1_COLOR");
    static_assert(GL_ONE_MINUS_SRC1_COLOR == _GL_ONE_MINUS_SRC1_COLOR, "GL_ONE_MINUS_SRC1_COLOR is not equal to _GL_ONE_MINUS_SRC1_COLOR");
    static_assert(GL_ONE_MINUS_SRC1_ALPHA == _GL_ONE_MINUS_SRC1_ALPHA, "GL_ONE_MINUS_SRC1_ALPHA is not equal to _GL_ONE_MINUS_SRC1_ALPHA");
    static_assert(GL_MAX_DUAL_SOURCE_DRAW_BUFFERS == _GL_MAX_DUAL_SOURCE_DRAW_BUFFERS, "GL_MAX_DUAL_SOURCE_DRAW_BUFFERS is not equal to _GL_MAX_DUAL_SOURCE_DRAW_BUFFERS");
    static_assert(GL_ANY_SAMPLES_PASSED == _GL_ANY_SAMPLES_PASSED, "GL_ANY_SAMPLES_PASSED is not equal to _GL_ANY_SAMPLES_PASSED");
    static_assert(GL_SAMPLER_BINDING == _GL_SAMPLER_BINDING, "GL_SAMPLER_BINDING is not equal to _GL_SAMPLER_BINDING");
    static_assert(GL_RGB10_A2UI == _GL_RGB10_A2UI, "GL_RGB10_A2UI is not equal to _GL_RGB10_A2UI");
    static_assert(GL_TEXTURE_SWIZZLE_R == _GL_TEXTURE_SWIZZLE_R, "GL_TEXTURE_SWIZZLE_R is not equal to _GL_TEXTURE_SWIZZLE_R");
    static_assert(GL_TEXTURE_SWIZZLE_G == _GL_TEXTURE_SWIZZLE_G, "GL_TEXTURE_SWIZZLE_G is not equal to _GL_TEXTURE_SWIZZLE_G");
    static_assert(GL_TEXTURE_SWIZZLE_B == _GL_TEXTURE_SWIZZLE_B, "GL_TEXTURE_SWIZZLE_B is not equal to _GL_TEXTURE_SWIZZLE_B");
    static_assert(GL_TEXTURE_SWIZZLE_A == _GL_TEXTURE_SWIZZLE_A, "GL_TEXTURE_SWIZZLE_A is not equal to _GL_TEXTURE_SWIZZLE_A");
    static_assert(GL_TEXTURE_SWIZZLE_RGBA == _GL_TEXTURE_SWIZZLE_RGBA, "GL_TEXTURE_SWIZZLE_RGBA is not equal to _GL_TEXTURE_SWIZZLE_RGBA");
    static_assert(GL_TIME_ELAPSED == _GL_TIME_ELAPSED, "GL_TIME_ELAPSED is not equal to _GL_TIME_ELAPSED");
    static_assert(GL_TIMESTAMP == _GL_TIMESTAMP, "GL_TIMESTAMP is not equal to _GL_TIMESTAMP");
    static_assert(GL_INT_2_10_10_10_REV == _GL_INT_2_10_10_10_REV, "GL_INT_2_10_10_10_REV is not equal to _GL_INT_2_10_10_10_REV");
    static_assert(GL_SAMPLE_SHADING == _GL_SAMPLE_SHADING, "GL_SAMPLE_SHADING is not equal to _GL_SAMPLE_SHADING");
    static_assert(GL_MIN_SAMPLE_SHADING_VALUE == _GL_MIN_SAMPLE_SHADING_VALUE, "GL_MIN_SAMPLE_SHADING_VALUE is not equal to _GL_MIN_SAMPLE_SHADING_VALUE");
    static_assert(GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET == _GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET, "GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET is not equal to _GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET");
    static_assert(GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET == _GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET, "GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET is not equal to _GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET");
    static_assert(GL_TEXTURE_CUBE_MAP_ARRAY == _GL_TEXTURE_CUBE_MAP_ARRAY, "GL_TEXTURE_CUBE_MAP_ARRAY is not equal to _GL_TEXTURE_CUBE_MAP_ARRAY");
    static_assert(GL_TEXTURE_BINDING_CUBE_MAP_ARRAY == _GL_TEXTURE_BINDING_CUBE_MAP_ARRAY, "GL_TEXTURE_BINDING_CUBE_MAP_ARRAY is not equal to _GL_TEXTURE_BINDING_CUBE_MAP_ARRAY");
    static_assert(GL_PROXY_TEXTURE_CUBE_MAP_ARRAY == _GL_PROXY_TEXTURE_CUBE_MAP_ARRAY, "GL_PROXY_TEXTURE_CUBE_MAP_ARRAY is not equal to _GL_PROXY_TEXTURE_CUBE_MAP_ARRAY");
    static_assert(GL_SAMPLER_CUBE_MAP_ARRAY == _GL_SAMPLER_CUBE_MAP_ARRAY, "GL_SAMPLER_CUBE_MAP_ARRAY is not equal to _GL_SAMPLER_CUBE_MAP_ARRAY");
    static_assert(GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW == _GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW, "GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW is not equal to _GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW");
    static_assert(GL_INT_SAMPLER_CUBE_MAP_ARRAY == _GL_INT_SAMPLER_CUBE_MAP_ARRAY, "GL_INT_SAMPLER_CUBE_MAP_ARRAY is not equal to _GL_INT_SAMPLER_CUBE_MAP_ARRAY");
}
#pragma endregion

#pragma region RANDOM_STUFF30
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY 0x900F
#define GL_DRAW_INDIRECT_BUFFER 0x8F3F
#define GL_DRAW_INDIRECT_BUFFER_BINDING 0x8F43
#define GL_GEOMETRY_SHADER_INVOCATIONS 0x887F
#define GL_MAX_GEOMETRY_SHADER_INVOCATIONS 0x8E5A
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET 0x8E5B
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET 0x8E5C
#define GL_FRAGMENT_INTERPOLATION_OFFSET_BITS 0x8E5D
#define GL_MAX_VERTEX_STREAMS 0x8E71
#define GL_DOUBLE_VEC2 0x8FFC
#define GL_DOUBLE_VEC3 0x8FFD
#define GL_DOUBLE_VEC4 0x8FFE
#define GL_DOUBLE_MAT2 0x8F46
#define GL_DOUBLE_MAT3 0x8F47
#define GL_DOUBLE_MAT4 0x8F48
#define GL_DOUBLE_MAT2x3 0x8F49
#define GL_DOUBLE_MAT2x4 0x8F4A
#define GL_DOUBLE_MAT3x2 0x8F4B
#define GL_DOUBLE_MAT3x4 0x8F4C
#define GL_DOUBLE_MAT4x2 0x8F4D
#define GL_DOUBLE_MAT4x3 0x8F4E
#define GL_ACTIVE_SUBROUTINES 0x8DE5
#define GL_ACTIVE_SUBROUTINE_UNIFORMS 0x8DE6
#define GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS 0x8E47
#define GL_ACTIVE_SUBROUTINE_MAX_LENGTH 0x8E48
#define GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH 0x8E49
#define GL_MAX_SUBROUTINES 0x8DE7
#define GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS 0x8DE8
#define GL_NUM_COMPATIBLE_SUBROUTINES 0x8E4A
#define GL_COMPATIBLE_SUBROUTINES 0x8E4B
    export constexpr int _GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY = 0x900F;
    export constexpr int _GL_DRAW_INDIRECT_BUFFER = 0x8F3F;
    export constexpr int _GL_DRAW_INDIRECT_BUFFER_BINDING = 0x8F43;
    export constexpr int _GL_GEOMETRY_SHADER_INVOCATIONS = 0x887F;
    export constexpr int _GL_MAX_GEOMETRY_SHADER_INVOCATIONS = 0x8E5A;
    export constexpr int _GL_MIN_FRAGMENT_INTERPOLATION_OFFSET = 0x8E5B;
    export constexpr int _GL_MAX_FRAGMENT_INTERPOLATION_OFFSET = 0x8E5C;
    export constexpr int _GL_FRAGMENT_INTERPOLATION_OFFSET_BITS = 0x8E5D;
    export constexpr int _GL_MAX_VERTEX_STREAMS = 0x8E71;
    export constexpr int _GL_DOUBLE_VEC2 = 0x8FFC;
    export constexpr int _GL_DOUBLE_VEC3 = 0x8FFD;
    export constexpr int _GL_DOUBLE_VEC4 = 0x8FFE;
    export constexpr int _GL_DOUBLE_MAT2 = 0x8F46;
    export constexpr int _GL_DOUBLE_MAT3 = 0x8F47;
    export constexpr int _GL_DOUBLE_MAT4 = 0x8F48;
    export constexpr int _GL_DOUBLE_MAT2x3 = 0x8F49;
    export constexpr int _GL_DOUBLE_MAT2x4 = 0x8F4A;
    export constexpr int _GL_DOUBLE_MAT3x2 = 0x8F4B;
    export constexpr int _GL_DOUBLE_MAT3x4 = 0x8F4C;
    export constexpr int _GL_DOUBLE_MAT4x2 = 0x8F4D;
    export constexpr int _GL_DOUBLE_MAT4x3 = 0x8F4E;
    export constexpr int _GL_ACTIVE_SUBROUTINES = 0x8DE5;
    export constexpr int _GL_ACTIVE_SUBROUTINE_UNIFORMS = 0x8DE6;
    export constexpr int _GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS = 0x8E47;
    export constexpr int _GL_ACTIVE_SUBROUTINE_MAX_LENGTH = 0x8E48;
    export constexpr int _GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH = 0x8E49;
    export constexpr int _GL_MAX_SUBROUTINES = 0x8DE7;
    export constexpr int _GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS = 0x8DE8;
    export constexpr int _GL_NUM_COMPATIBLE_SUBROUTINES = 0x8E4A;
    export constexpr int _GL_COMPATIBLE_SUBROUTINES = 0x8E4B;
consteval void Check_Random_Stuff30() {
    static_assert(GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY == _GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY, "GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY is not equal to _GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY");
    static_assert(GL_DRAW_INDIRECT_BUFFER == _GL_DRAW_INDIRECT_BUFFER, "GL_DRAW_INDIRECT_BUFFER is not equal to _GL_DRAW_INDIRECT_BUFFER");
    static_assert(GL_DRAW_INDIRECT_BUFFER_BINDING == _GL_DRAW_INDIRECT_BUFFER_BINDING, "GL_DRAW_INDIRECT_BUFFER_BINDING is not equal to _GL_DRAW_INDIRECT_BUFFER_BINDING");
    static_assert(GL_GEOMETRY_SHADER_INVOCATIONS == _GL_GEOMETRY_SHADER_INVOCATIONS, "GL_GEOMETRY_SHADER_INVOCATIONS is not equal to _GL_GEOMETRY_SHADER_INVOCATIONS");
    static_assert(GL_MAX_GEOMETRY_SHADER_INVOCATIONS == _GL_MAX_GEOMETRY_SHADER_INVOCATIONS, "GL_MAX_GEOMETRY_SHADER_INVOCATIONS is not equal to _GL_MAX_GEOMETRY_SHADER_INVOCATIONS");
    static_assert(GL_MIN_FRAGMENT_INTERPOLATION_OFFSET == _GL_MIN_FRAGMENT_INTERPOLATION_OFFSET, "GL_MIN_FRAGMENT_INTERPOLATION_OFFSET is not equal to _GL_MIN_FRAGMENT_INTERPOLATION_OFFSET");
    static_assert(GL_MAX_FRAGMENT_INTERPOLATION_OFFSET == _GL_MAX_FRAGMENT_INTERPOLATION_OFFSET, "GL_MAX_FRAGMENT_INTERPOLATION_OFFSET is not equal to _GL_MAX_FRAGMENT_INTERPOLATION_OFFSET");
    static_assert(GL_FRAGMENT_INTERPOLATION_OFFSET_BITS == _GL_FRAGMENT_INTERPOLATION_OFFSET_BITS, "GL_FRAGMENT_INTERPOLATION_OFFSET_BITS is not equal to _GL_FRAGMENT_INTERPOLATION_OFFSET_BITS");
    static_assert(GL_MAX_VERTEX_STREAMS == _GL_MAX_VERTEX_STREAMS, "GL_MAX_VERTEX_STREAMS is not equal to _GL_MAX_VERTEX_STREAMS");
    static_assert(GL_DOUBLE_VEC2 == _GL_DOUBLE_VEC2, "GL_DOUBLE_VEC2 is not equal to _GL_DOUBLE_VEC2");
    static_assert(GL_DOUBLE_VEC3 == _GL_DOUBLE_VEC3, "GL_DOUBLE_VEC3 is not equal to _GL_DOUBLE_VEC3");
    static_assert(GL_DOUBLE_VEC4 == _GL_DOUBLE_VEC4, "GL_DOUBLE_VEC4 is not equal to _GL_DOUBLE_VEC4");
    static_assert(GL_DOUBLE_MAT2 == _GL_DOUBLE_MAT2, "GL_DOUBLE_MAT2 is not equal to _GL_DOUBLE_MAT2");
    static_assert(GL_DOUBLE_MAT3 == _GL_DOUBLE_MAT3, " GL_DOUBLE_MAT3 is not equal to _GL_DOUBLE_MAT3");
    static_assert(GL_DOUBLE_MAT4 == _GL_DOUBLE_MAT4, "GL_DOUBLE_MAT4 is not equal to _GL_DOUBLE_MAT4");
    static_assert(GL_DOUBLE_MAT2x3 == _GL_DOUBLE_MAT2x3, "GL_DOUBLE_MAT2x3 is not equal to _GL_DOUBLE_MAT2x3");
    static_assert(GL_DOUBLE_MAT2x4 == _GL_DOUBLE_MAT2x4, "GL_DOUBLE_MAT2x4 is not equal to _GL_DOUBLE_MAT2x4");
    static_assert(GL_DOUBLE_MAT3x2 == _GL_DOUBLE_MAT3x2, "GL_DOUBLE_MAT3x2 is not equal to _GL_DOUBLE_MAT3x2");
    static_assert(GL_DOUBLE_MAT3x4 == _GL_DOUBLE_MAT3x4, "GL_DOUBLE_MAT3x4 is not equal to _GL_DOUBLE_MAT3x4");
    static_assert(GL_DOUBLE_MAT4x2 == _GL_DOUBLE_MAT4x2, "GL_DOUBLE_MAT4x2 is not equal to _GL_DOUBLE_MAT4x2");
    static_assert(GL_DOUBLE_MAT4x3 == _GL_DOUBLE_MAT4x3, "GL_DOUBLE_MAT4x3 is not equal to _GL_DOUBLE_MAT4x3");
    static_assert(GL_ACTIVE_SUBROUTINES == _GL_ACTIVE_SUBROUTINES, "GL_ACTIVE_SUBROUTINES is not equal to _GL_ACTIVE_SUBROUTINES");
    static_assert(GL_ACTIVE_SUBROUTINE_UNIFORMS == _GL_ACTIVE_SUBROUTINE_UNIFORMS, "GL_ACTIVE_SUBROUTINE_UNIFORMS is not equal to _GL_ACTIVE_SUBROUTINE_UNIFORMS");
    static_assert(GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS == _GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS, "GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS is not equal to _GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS");
    static_assert(GL_ACTIVE_SUBROUTINE_MAX_LENGTH == _GL_ACTIVE_SUBROUTINE_MAX_LENGTH, "GL_ACTIVE_SUBROUTINE_MAX_LENGTH is not equal to _GL_ACTIVE_SUBROUTINE_MAX_LENGTH");
    static_assert(GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH == _GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH, "GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH is not equal to _GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH");
    static_assert(GL_MAX_SUBROUTINES == _GL_MAX_SUBROUTINES, "GL_MAX_SUBROUTINES is not equal to _GL_MAX_SUBROUTINES");
    static_assert(GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS == _GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS, "GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS is not equal to _GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS");
    static_assert(GL_NUM_COMPATIBLE_SUBROUTINES == _GL_NUM_COMPATIBLE_SUBROUTINES, "GL_NUM_COMPATIBLE_SUBROUTINES is not equal to _GL_NUM_COMPATIBLE_SUBROUTINES");
    static_assert(GL_COMPATIBLE_SUBROUTINES == _GL_COMPATIBLE_SUBROUTINES, "GL_COMPATIBLE_SUBROUTINES is not equal to _GL_COMPATIBLE_SUBROUTINES");
}
#pragma endregion

#pragma region RANDOM_STUFF31
#define GL_PATCHES 0x000E
#define GL_PATCH_VERTICES 0x8E72
#define GL_PATCH_DEFAULT_INNER_LEVEL 0x8E73
#define GL_PATCH_DEFAULT_OUTER_LEVEL 0x8E74
#define GL_TESS_CONTROL_OUTPUT_VERTICES 0x8E75
#define GL_TESS_GEN_MODE 0x8E76
#define GL_TESS_GEN_SPACING 0x8E77
#define GL_TESS_GEN_VERTEX_ORDER 0x8E78
#define GL_TESS_GEN_POINT_MODE 0x8E79
#define GL_ISOLINES 0x8E7A
#define GL_QUADS 0x0007
#define GL_FRACTIONAL_ODD 0x8E7B
#define GL_FRACTIONAL_EVEN 0x8E7C
#define GL_MAX_PATCH_VERTICES 0x8E7D
#define GL_MAX_TESS_GEN_LEVEL 0x8E7E
#define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E7F
#define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E80
#define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS 0x8E81
#define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS 0x8E82
#define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS 0x8E83
#define GL_MAX_TESS_PATCH_COMPONENTS 0x8E84
#define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS 0x8E85
#define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS 0x8E86
#define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS 0x8E89
#define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS 0x8E8A
#define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS 0x886C
#define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS 0x886D
#define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E1E
#define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E1F
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER 0x84F0
    export constexpr int _GL_PATCHES = 0x000E;
    export constexpr int _GL_PATCH_VERTICES = 0x8E72;
    export constexpr int _GL_PATCH_DEFAULT_INNER_LEVEL = 0x8E73;
    export constexpr int _GL_PATCH_DEFAULT_OUTER_LEVEL = 0x8E74;
    export constexpr int _GL_TESS_CONTROL_OUTPUT_VERTICES = 0x8E75;
    export constexpr int _GL_TESS_GEN_MODE = 0x8E76;
    export constexpr int _GL_TESS_GEN_SPACING = 0x8E77;
    export constexpr int _GL_TESS_GEN_VERTEX_ORDER = 0x8E78;
    export constexpr int _GL_TESS_GEN_POINT_MODE = 0x8E79;
    export constexpr int _GL_ISOLINES = 0x8E7A;
    export constexpr int _GL_QUADS = 0x0007;
    export constexpr int _GL_FRACTIONAL_ODD = 0x8E7B;
    export constexpr int _GL_FRACTIONAL_EVEN = 0x8E7C;
    export constexpr int _GL_MAX_PATCH_VERTICES = 0x8E7D;
    export constexpr int _GL_MAX_TESS_GEN_LEVEL = 0x8E7E;
    export constexpr int _GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS = 0x8E7F;
    export constexpr int _GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS = 0x8E80;
    export constexpr int _GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS = 0x8E81;
    export constexpr int _GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS = 0x8E82;
    export constexpr int _GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS = 0x8E83;
    export constexpr int _GL_MAX_TESS_PATCH_COMPONENTS = 0x8E84;
    export constexpr int _GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS = 0x8E85;
    export constexpr int _GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS = 0x8E86;
    export constexpr int _GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS = 0x8E89;
    export constexpr int _GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS = 0x8E8A;
    export constexpr int _GL_MAX_TESS_CONTROL_INPUT_COMPONENTS = 0x886C;
    export constexpr int _GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS = 0x886D;
    export constexpr int _GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS = 0x8E1E;
    export constexpr int _GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS = 0x8E1F;
    export constexpr int _GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER = 0x84F0;
consteval void Check_Random_Stuff31() {
    static_assert(GL_PATCHES == _GL_PATCHES, "GL_PATCHES is not equal to _GL_PATCHES");
    static_assert(GL_PATCH_VERTICES == _GL_PATCH_VERTICES, "GL_PATCH_VERTICES is not equal to _GL_PATCH_VERTICES");
    static_assert(GL_PATCH_DEFAULT_INNER_LEVEL == _GL_PATCH_DEFAULT_INNER_LEVEL, "GL_PATCH_DEFAULT_INNER_LEVEL is not equal to _GL_PATCH_DEFAULT_INNER_LEVEL");
    static_assert(GL_PATCH_DEFAULT_OUTER_LEVEL == _GL_PATCH_DEFAULT_OUTER_LEVEL, "GL_PATCH_DEFAULT_OUTER_LEVEL is not equal to _GL_PATCH_DEFAULT_OUTER_LEVEL");
    static_assert(GL_TESS_CONTROL_OUTPUT_VERTICES == _GL_TESS_CONTROL_OUTPUT_VERTICES, "GL_TESS_CONTROL_OUTPUT_VERTICES is not equal to _GL_TESS_CONTROL_OUTPUT_VERTICES");
    static_assert(GL_TESS_GEN_MODE == _GL_TESS_GEN_MODE, "GL_TESS_GEN_MODE is not equal to _GL_TESS_GEN_MODE");
    static_assert(GL_TESS_GEN_SPACING == _GL_TESS_GEN_SPACING, "GL_TESS_GEN_SPACING is not equal to _GL_TESS_GEN_SPACING");
    static_assert(GL_TESS_GEN_VERTEX_ORDER == _GL_TESS_GEN_VERTEX_ORDER, "GL_TESS_GEN_VERTEX_ORDER is not equal to _GL_TESS_GEN_VERTEX_ORDER");
    static_assert(GL_TESS_GEN_POINT_MODE == _GL_TESS_GEN_POINT_MODE, "GL_TESS_GEN_POINT_MODE is not equal to _GL_TESS_GEN_POINT_MODE");
    static_assert(GL_ISOLINES == _GL_ISOLINES, "GL_ISOLINES is not equal to _GL_ISOLINES");
    static_assert(GL_QUADS == _GL_QUADS, "GL_QUADS is not equal to _GL_QUADS");
    static_assert(GL_FRACTIONAL_ODD == _GL_FRACTIONAL_ODD, "GL_FRACTIONAL_ODD is not equal to _GL_FRACTIONAL_ODD");
    static_assert(GL_FRACTIONAL_EVEN == _GL_FRACTIONAL_EVEN, "GL_FRACTIONAL_EVEN is not equal to _GL_FRACTIONAL_EVEN");
    static_assert(GL_MAX_PATCH_VERTICES == _GL_MAX_PATCH_VERTICES, "GL_MAX_PATCH_VERTICES is not equal to _GL _MAX_PATCH_VERTICES");
    static_assert(GL_MAX_TESS_GEN_LEVEL == _GL_MAX_TESS_GEN_LEVEL, "GL_MAX_TESS_GEN_LEVEL is not equal to _GL_MAX_TESS_GEN_LEVEL");
    static_assert(GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS == _GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS, "GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS is not equal to _GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS");
    static_assert(GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS == _GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS, "GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS is not equal to _GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS");
    static_assert(GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS == _GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS, "GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS is not equal to _GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS");
    static_assert(GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS == _GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS, "GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS is not equal to _GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS");
    static_assert(GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS == _GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS, "GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS is not equal to _GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS");
    static_assert(GL_MAX_TESS_PATCH_COMPONENTS == _GL_MAX_TESS_PATCH_COMPONENTS, "GL_MAX_TESS_PATCH_COMPONENTS is not equal to _GL_MAX_TESS_PATCH_COMPONENTS");
    static_assert(GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS == _GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS, "GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS is not equal to _GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS");
    static_assert(GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS == _GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS, "GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS is not equal to _GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS");
    static_assert(GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS == _GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS, "GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS is not equal to _GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS");
    static_assert(GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS == _GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS, "GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS is not equal to _GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS");
    static_assert(GL_MAX_TESS_CONTROL_INPUT_COMPONENTS == _GL_MAX_TESS_CONTROL_INPUT_COMPONENTS, "GL_MAX_TESS_CONTROL_INPUT_COMPONENTS is not equal to _GL_MAX_TESS_CONTROL_INPUT_COMPONENTS");
    static_assert(GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS == _GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS, "GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS is not equal to _GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS");
    static_assert(GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS == _GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS, "GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS is not equal to _GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS");
    static_assert(GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS == _GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS, "GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS is not equal to _GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS");
    static_assert(GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER == _GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER, "GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER is not equal to _GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER");
}
#pragma endregion

#pragma region RANDOM_STUFF32
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER 0x84F1
#define GL_TESS_EVALUATION_SHADER 0x8E87
#define GL_TESS_CONTROL_SHADER 0x8E88
#define GL_TRANSFORM_FEEDBACK 0x8E22
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED 0x8E23
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE 0x8E24
#define GL_TRANSFORM_FEEDBACK_BINDING 0x8E25
#define GL_MAX_TRANSFORM_FEEDBACK_BUFFERS 0x8E70
export{
    constexpr int _GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER = 0x84F1;
    constexpr int _GL_TESS_EVALUATION_SHADER = 0x8E87;
    constexpr int _GL_TESS_CONTROL_SHADER = 0x8E88;
    constexpr int _GL_TRANSFORM_FEEDBACK = 0x8E22;
    constexpr int _GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED = 0x8E23;
    constexpr int _GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE = 0x8E24;
    constexpr int _GL_TRANSFORM_FEEDBACK_BINDING = 0x8E25;
    constexpr int _GL_MAX_TRANSFORM_FEEDBACK_BUFFERS = 0x8E70;
}
consteval void Check_Random_Stuff32() {
    static_assert(GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER == _GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER, "GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER is not equal to _GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER");
    static_assert(GL_TESS_EVALUATION_SHADER == _GL_TESS_EVALUATION_SHADER, "GL_TESS_EVALUATION_SHADER is not equal to _GL_TESS_EVALUATION_SHADER");
    static_assert(GL_TESS_CONTROL_SHADER == _GL_TESS_CONTROL_SHADER, "GL_TESS_CONTROL_SHADER is not equal to _GL_TESS_CONTROL_SHADER");
    static_assert(GL_TRANSFORM_FEEDBACK == _GL_TRANSFORM_FEEDBACK, "GL_TRANSFORM_FEEDBACK is not equal to _GL_TRANSFORM_FEEDBACK");
    static_assert(GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED == _GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED, "GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED is not equal to _GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED");
    static_assert(GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE == _GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE, "GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE is not equal to _GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE");
    static_assert(GL_TRANSFORM_FEEDBACK_BINDING == _GL_TRANSFORM_FEEDBACK_BINDING, "GL_TRANSFORM_FEEDBACK_BINDING is not equal to _GL_TRANSFORM_FEEDBACK_BINDING");
    static_assert(GL_MAX_TRANSFORM_FEEDBACK_BUFFERS == _GL_MAX_TRANSFORM_FEEDBACK_BUFFERS, "GL_MAX_TRANSFORM_FEEDBACK_BUFFERS is not equal to _GL_MAX_TRANSFORM_FEEDBACK_BUFFERS");
}
#pragma endregion




#pragma endregion


#pragma region GL_VERSION_1_0

#ifndef GL_VERSION_1_0
#define GL_VERSION_1_0 1



export GLAPI int GLAD_GL_VERSION_1_0;



 export typedef void (APIENTRYP PFNGLCULLFACEPROC)(GLenum mode);
export GLAPI PFNGLCULLFACEPROC glad_glCullFace;
export inline void glCullFace(GLenum mode) { glad_glCullFace(mode); }
#define glCullFace glad_glCullFace



export typedef void (APIENTRYP PFNGLFRONTFACEPROC)(GLenum mode);
export GLAPI PFNGLFRONTFACEPROC glad_glFrontFace;
export inline void glFrontFace(GLenum mode) { glad_glFrontFace(mode); }
#define glFrontFace glad_glFrontFace



export typedef void (APIENTRYP PFNGLHINTPROC)(GLenum target, GLenum mode);
export GLAPI PFNGLHINTPROC glad_glHint;
export inline void glHint(GLenum target, GLenum mode) { glad_glHint(target, mode); }
#define glHint glad_glHint



export typedef void (APIENTRYP PFNGLLINEWIDTHPROC)(GLfloat width);
export GLAPI PFNGLLINEWIDTHPROC glad_glLineWidth;
export inline void glLineWidth(GLfloat width) { glad_glLineWidth(width); }
#define glLineWidth glad_glLineWidth



export typedef void (APIENTRYP PFNGLPOINTSIZEPROC)(GLfloat size);
export GLAPI PFNGLPOINTSIZEPROC glad_glPointSize;
export inline void glPointSize(GLfloat size) { glad_glPointSize(size); }
#define glPointSize glad_glPointSize



export typedef void (APIENTRYP PFNGLPOLYGONMODEPROC)(GLenum face, GLenum mode);
export GLAPI PFNGLPOLYGONMODEPROC glad_glPolygonMode;
export inline void glPolygonMode(GLenum face, GLenum mode) { glad_glPolygonMode(face, mode); }
#define glPolygonMode glad_glPolygonMode



export typedef void (APIENTRYP PFNGLSCISSORPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
export GLAPI PFNGLSCISSORPROC glad_glScissor;
export inline void glScissor(GLint x, GLint y, GLsizei width, GLsizei height) { glad_glScissor(x, y, width, height); }
#define glScissor glad_glScissor



export typedef void (APIENTRYP PFNGLTEXPARAMETERFPROC)(GLenum target, GLenum pname, GLfloat param);
export GLAPI PFNGLTEXPARAMETERFPROC glad_glTexParameterf;
export inline void glTexParameterf(GLenum target, GLenum pname, GLfloat param) { glad_glTexParameterf(target, pname, param); }
#define glTexParameterf glad_glTexParameterf



export typedef void (APIENTRYP PFNGLTEXPARAMETERFVPROC)(GLenum target, GLenum pname, const GLfloat* params);
export GLAPI PFNGLTEXPARAMETERFVPROC glad_glTexParameterfv;
export inline void glTexParameterfv(GLenum target, GLenum pname, const GLfloat* params) { glad_glTexParameterfv(target, pname, params); }
#define glTexParameterfv glad_glTexParameterfv



export typedef void (APIENTRYP PFNGLTEXPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
export GLAPI PFNGLTEXPARAMETERIPROC glad_glTexParameteri;
export inline void glTexParameteri(GLenum target, GLenum pname, GLint param) { glad_glTexParameteri(target, pname, param); }
#define glTexParameteri glad_glTexParameteri
 
 
 
export typedef void (APIENTRYP PFNGLTEXPARAMETERIVPROC)(GLenum target, GLenum pname, const GLint* params);
export GLAPI PFNGLTEXPARAMETERIVPROC glad_glTexParameteriv;
export inline void glTexParameteriv(GLenum target, GLenum pname, const GLint* params) { glad_glTexParameteriv(target, pname, params); }
#define glTexParameteriv glad_glTexParameteriv
 
 
 
export typedef void (APIENTRYP PFNGLTEXIMAGE1DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels);
export GLAPI PFNGLTEXIMAGE1DPROC glad_glTexImage1D;
export inline void glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels) { glad_glTexImage1D(target, level, internalformat, width, border, format, type, pixels); }
#define glTexImage1D glad_glTexImage1D
 
 
 
export typedef void (APIENTRYP PFNGLTEXIMAGE2DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels);
export GLAPI PFNGLTEXIMAGE2DPROC glad_glTexImage2D;
export inline void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels) { glad_glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels); }
#define glTexImage2D glad_glTexImage2D



export typedef void (APIENTRYP PFNGLDRAWBUFFERPROC)(GLenum buf);
export GLAPI PFNGLDRAWBUFFERPROC glad_glDrawBuffer;
export inline void glDrawBuffer(GLenum buf) { glad_glDrawBuffer(buf); }
#define glDrawBuffer glad_glDrawBuffer



export typedef void (APIENTRYP PFNGLCLEARPROC)(GLbitfield mask);
export GLAPI PFNGLCLEARPROC glad_glClear;
export inline void glClear(GLbitfield mask) { glad_glClear(mask); }
#define glClear glad_glClear



export typedef void (APIENTRYP PFNGLCLEARCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
export GLAPI PFNGLCLEARCOLORPROC glad_glClearColor;
export inline void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) { glad_glClearColor(red, green, blue, alpha); }
#define glClearColor glad_glClearColor



export typedef void (APIENTRYP PFNGLCLEARSTENCILPROC)(GLint s);
export GLAPI PFNGLCLEARSTENCILPROC glad_glClearStencil;
export inline void glClearStencil(GLint s) { glad_glClearStencil(s); }
#define glClearStencil glad_glClearStencil



export typedef void (APIENTRYP PFNGLCLEARDEPTHPROC)(GLdouble depth);
export GLAPI PFNGLCLEARDEPTHPROC glad_glClearDepth;
export inline void glClearDepth(GLdouble depth) { glad_glClearDepth(depth); }
#define glClearDepth glad_glClearDepth


export typedef void (APIENTRYP PFNGLSTENCILMASKPROC)(GLuint mask);
export GLAPI PFNGLSTENCILMASKPROC glad_glStencilMask;
export inline void glStencilMask(GLuint mask) { glad_glStencilMask(mask); }
#define glStencilMask glad_glStencilMask


export typedef void (APIENTRYP PFNGLCOLORMASKPROC)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
export GLAPI PFNGLCOLORMASKPROC glad_glColorMask;
export inline void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) { glad_glColorMask(red, green, blue, alpha); }
#define glColorMask glad_glColorMask



export typedef void (APIENTRYP PFNGLDEPTHMASKPROC)(GLboolean flag);
export GLAPI PFNGLDEPTHMASKPROC glad_glDepthMask;
export inline void glDepthMask(GLboolean flag) { glad_glDepthMask(flag); }
#define glDepthMask glad_glDepthMask



export typedef void (APIENTRYP PFNGLDISABLEPROC)(GLenum cap);
export GLAPI PFNGLDISABLEPROC glad_glDisable;
export inline void glDisable(GLenum cap) { glad_glDisable(cap); }
#define glDisable glad_glDisable



export typedef void (APIENTRYP PFNGLENABLEPROC)(GLenum cap);
export GLAPI PFNGLENABLEPROC glad_glEnable;
export inline void glEnable(GLenum cap) { glad_glEnable(cap); }
#define glEnable glad_glEnable



export typedef void (APIENTRYP PFNGLFINISHPROC)(void);
export GLAPI PFNGLFINISHPROC glad_glFinish;
export inline void glFinish() { glad_glFinish(); }
#define glFinish glad_glFinish



export typedef void (APIENTRYP PFNGLFLUSHPROC)(void);
export GLAPI PFNGLFLUSHPROC glad_glFlush;
#define glFlush glad_glFlush



export typedef void (APIENTRYP PFNGLBLENDFUNCPROC)(GLenum sfactor, GLenum dfactor);
export GLAPI PFNGLBLENDFUNCPROC glad_glBlendFunc;
export inline void glBlendFunc(GLenum sfactor, GLenum dfactor) { glad_glBlendFunc(sfactor, dfactor); }
#define glBlendFunc glad_glBlendFunc



export typedef void (APIENTRYP PFNGLLOGICOPPROC)(GLenum opcode);
export GLAPI PFNGLLOGICOPPROC glad_glLogicOp;
export inline void glLogicOp(GLenum opcode) { glad_glLogicOp(opcode); }
#define glLogicOp glad_glLogicOp



export typedef void (APIENTRYP PFNGLSTENCILFUNCPROC)(GLenum func, GLint ref, GLuint mask);
export GLAPI PFNGLSTENCILFUNCPROC glad_glStencilFunc;
export inline void glStencilFunc(GLenum func, GLint ref, GLuint mask) { glad_glStencilFunc(func, ref, mask); }
#define glStencilFunc glad_glStencilFunc



export typedef void (APIENTRYP PFNGLSTENCILOPPROC)(GLenum fail, GLenum zfail, GLenum zpass);
export GLAPI PFNGLSTENCILOPPROC glad_glStencilOp;
export inline void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) { glad_glStencilOp(fail, zfail, zpass); }
#define glStencilOp glad_glStencilOp



export typedef void (APIENTRYP PFNGLDEPTHFUNCPROC)(GLenum func);
export GLAPI PFNGLDEPTHFUNCPROC glad_glDepthFunc;
export inline void glDepthFunc(GLenum func) { glad_glDepthFunc(func); }
#define glDepthFunc glad_glDepthFunc



export typedef void (APIENTRYP PFNGLPIXELSTOREFPROC)(GLenum pname, GLfloat param);
export GLAPI PFNGLPIXELSTOREFPROC glad_glPixelStoref;
export inline void glPixelStoref(GLenum pname, GLfloat param) { glad_glPixelStoref(pname, param); }
#define glPixelStoref glad_glPixelStoref



export typedef void (APIENTRYP PFNGLPIXELSTOREIPROC)(GLenum pname, GLint param);
export GLAPI PFNGLPIXELSTOREIPROC glad_glPixelStorei;
export inline void glPixelStorei(GLenum pname, GLint param) { glad_glPixelStorei(pname, param); }
#define glPixelStorei glad_glPixelStorei



export typedef void (APIENTRYP PFNGLREADBUFFERPROC)(GLenum src);
export GLAPI PFNGLREADBUFFERPROC glad_glReadBuffer;
export inline void glReadBuffer(GLenum src) { glad_glReadBuffer(src); }
#define glReadBuffer glad_glReadBuffer



export typedef void (APIENTRYP PFNGLREADPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void* pixels);
export GLAPI PFNGLREADPIXELSPROC glad_glReadPixels;
export inline void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void* pixels) { glad_glReadPixels(x, y, width, height, format, type, pixels); }
#define glReadPixels glad_glReadPixels



export typedef void (APIENTRYP PFNGLGETBOOLEANVPROC)(GLenum pname, GLboolean* data);
export GLAPI PFNGLGETBOOLEANVPROC glad_glGetBooleanv;
export inline void glGetBooleanv(GLenum pname, GLboolean* data) { glad_glGetBooleanv(pname, data); }
#define glGetBooleanv glad_glGetBooleanv



export typedef void (APIENTRYP PFNGLGETDOUBLEVPROC)(GLenum pname, GLdouble* data);
export GLAPI PFNGLGETDOUBLEVPROC glad_glGetDoublev;
export inline void glGetDoublev(GLenum pname, GLdouble* data) { glad_glGetDoublev(pname, data); }
#define glGetDoublev glad_glGetDoublev



export typedef GLenum(APIENTRYP PFNGLGETERRORPROC)(void);
export GLAPI PFNGLGETERRORPROC glad_glGetError;
export inline GLenum glGetError() { return glad_glGetError(); }
#define glGetError glad_glGetError



export typedef void (APIENTRYP PFNGLGETFLOATVPROC)(GLenum pname, GLfloat* data);
export GLAPI PFNGLGETFLOATVPROC glad_glGetFloatv;
export inline void glGetFloatv(GLenum pname, GLfloat* data) { glad_glGetFloatv(pname, data); }
#define glGetFloatv glad_glGetFloatv



export typedef void (APIENTRYP PFNGLGETINTEGERVPROC)(GLenum pname, GLint* data);
export GLAPI PFNGLGETINTEGERVPROC glad_glGetIntegerv;
export inline void glGetIntegerv(GLenum pname, GLint* data) { glad_glGetIntegerv(pname, data); }
#define glGetIntegerv glad_glGetIntegerv



export typedef const GLubyte* (APIENTRYP PFNGLGETSTRINGPROC)(GLenum name);
export GLAPI PFNGLGETSTRINGPROC glad_glGetString;
export inline const GLubyte* glGetString(GLenum name) { return glad_glGetString(name); }
#define glGetString glad_glGetString



export typedef void (APIENTRYP PFNGLGETTEXIMAGEPROC)(GLenum target, GLint level, GLenum format, GLenum type, void* pixels);
export GLAPI PFNGLGETTEXIMAGEPROC glad_glGetTexImage;
export inline void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void* pixels) { glad_glGetTexImage(target, level, format, type, pixels); }
#define glGetTexImage glad_glGetTexImage



export typedef void (APIENTRYP PFNGLGETTEXPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat* params);
export GLAPI PFNGLGETTEXPARAMETERFVPROC glad_glGetTexParameterfv;
export inline void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat* params) { glad_glGetTexParameterfv(target, pname, params); }
#define glGetTexParameterfv glad_glGetTexParameterfv



export typedef void (APIENTRYP PFNGLGETTEXPARAMETERIVPROC)(GLenum target, GLenum pname, GLint* params);
export GLAPI PFNGLGETTEXPARAMETERIVPROC glad_glGetTexParameteriv;
export inline void glGetTexParameteriv(GLenum target, GLenum pname, GLint* params) { glad_glGetTexParameteriv(target, pname, params); }
#define glGetTexParameteriv glad_glGetTexParameteriv



export typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERFVPROC)(GLenum target, GLint level, GLenum pname, GLfloat* params);
export GLAPI PFNGLGETTEXLEVELPARAMETERFVPROC glad_glGetTexLevelParameterfv;
export inline void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat* params) { glad_glGetTexLevelParameterfv(target, level, pname, params); }
#define glGetTexLevelParameterfv glad_glGetTexLevelParameterfv



export typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERIVPROC)(GLenum target, GLint level, GLenum pname, GLint* params);
export GLAPI PFNGLGETTEXLEVELPARAMETERIVPROC glad_glGetTexLevelParameteriv;
export inline void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint* params) { glad_glGetTexLevelParameteriv(target, level, pname, params); }
#define glGetTexLevelParameteriv glad_glGetTexLevelParameteriv



export typedef GLboolean(APIENTRYP PFNGLISENABLEDPROC)(GLenum cap);
export GLAPI PFNGLISENABLEDPROC glad_glIsEnabled;
export inline GLboolean glIsEnabled(GLenum cap) { return glad_glIsEnabled(cap); }
#define glIsEnabled glad_glIsEnabled



export typedef void (APIENTRYP PFNGLDEPTHRANGEPROC)(GLdouble n, GLdouble f);
export GLAPI PFNGLDEPTHRANGEPROC glad_glDepthRange;
export inline void glDepthRange(GLdouble n, GLdouble f) { glad_glDepthRange(n, f); }
#define glDepthRange glad_glDepthRange



export typedef void (APIENTRYP PFNGLVIEWPORTPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
export GLAPI PFNGLVIEWPORTPROC glad_glViewport;
export inline void glViewport(GLint x, GLint y, GLsizei width, GLsizei height) { glad_glViewport(x, y, width, height); }
#define glViewport glad_glViewport



#endif
#pragma endregion
#pragma region GL_VERSION_1_1
#ifndef GL_VERSION_1_1
#define GL_VERSION_1_1 1
export GLAPI int GLAD_GL_VERSION_1_1;



export typedef void (APIENTRYP PFNGLDRAWARRAYSPROC)(GLenum mode, GLint first, GLsizei count);
export GLAPI PFNGLDRAWARRAYSPROC glad_glDrawArrays;
export inline void glDrawArrays(GLenum mode, GLint first, GLsizei count) { glad_glDrawArrays(mode, first, count); }
#define glDrawArrays glad_glDrawArrays



export typedef void (APIENTRYP PFNGLDRAWELEMENTSPROC)(GLenum mode, GLsizei count, GLenum type, const void* indices);
export GLAPI PFNGLDRAWELEMENTSPROC glad_glDrawElements;
export inline void glDrawElements(GLenum mode, GLsizei count, GLenum type, const void* indices) { glad_glDrawElements(mode, count, type, indices); }
#define glDrawElements glad_glDrawElements



export typedef void (APIENTRYP PFNGLPOLYGONOFFSETPROC)(GLfloat factor, GLfloat units);
export GLAPI PFNGLPOLYGONOFFSETPROC glad_glPolygonOffset;
export inline void glPolygonOffset(GLfloat factor, GLfloat units) { glad_glPolygonOffset(factor, units); }
#define glPolygonOffset glad_glPolygonOffset



export typedef void (APIENTRYP PFNGLCOPYTEXIMAGE1DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
export GLAPI PFNGLCOPYTEXIMAGE1DPROC glad_glCopyTexImage1D;
export inline void glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) { glad_glCopyTexImage1D(target, level, internalformat, x, y, width, border); }
#define glCopyTexImage1D glad_glCopyTexImage1D



export typedef void (APIENTRYP PFNGLCOPYTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
export GLAPI PFNGLCOPYTEXIMAGE2DPROC glad_glCopyTexImage2D;
export inline void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) { glad_glCopyTexImage2D(target, level, internalformat, x, y, width, height, border); }
#define glCopyTexImage2D glad_glCopyTexImage2D



export typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
export GLAPI PFNGLCOPYTEXSUBIMAGE1DPROC glad_glCopyTexSubImage1D;
export inline void glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) { glad_glCopyTexSubImage1D(target, level, xoffset, x, y, width); }
#define glCopyTexSubImage1D glad_glCopyTexSubImage1D



export typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
export GLAPI PFNGLCOPYTEXSUBIMAGE2DPROC glad_glCopyTexSubImage2D;
export inline void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) { glad_glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height); }
#define glCopyTexSubImage2D glad_glCopyTexSubImage2D



export typedef void (APIENTRYP PFNGLTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels);
export GLAPI PFNGLTEXSUBIMAGE1DPROC glad_glTexSubImage1D;
export inline void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels) { glad_glTexSubImage1D(target, level, xoffset, width, format, type, pixels); }
#define glTexSubImage1D glad_glTexSubImage1D



export typedef void (APIENTRYP PFNGLTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels);
export GLAPI PFNGLTEXSUBIMAGE2DPROC glad_glTexSubImage2D;
export inline void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels) { glad_glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels); }
#define glTexSubImage2D glad_glTexSubImage2D



export typedef void (APIENTRYP PFNGLBINDTEXTUREPROC)(GLenum target, GLuint texture);
export GLAPI PFNGLBINDTEXTUREPROC glad_glBindTexture;
export inline void glBindTexture(GLenum target, GLuint texture) { glad_glBindTexture(target, texture); }
#define glBindTexture glad_glBindTexture



export typedef void (APIENTRYP PFNGLDELETETEXTURESPROC)(GLsizei n, const GLuint* textures);
export GLAPI PFNGLDELETETEXTURESPROC glad_glDeleteTextures;
export inline void glDeleteTextures(GLsizei n, const GLuint* textures) { glad_glDeleteTextures(n, textures); }
#define glDeleteTextures glad_glDeleteTextures



export typedef void (APIENTRYP PFNGLGENTEXTURESPROC)(GLsizei n, GLuint* textures);
export GLAPI PFNGLGENTEXTURESPROC glad_glGenTextures;
export inline void glGenTextures(GLsizei n, GLuint* textures) { glad_glGenTextures(n, textures); }
#define glGenTextures glad_glGenTextures



export typedef GLboolean(APIENTRYP PFNGLISTEXTUREPROC)(GLuint texture);
export GLAPI PFNGLISTEXTUREPROC glad_glIsTexture;
export inline GLboolean glIsTexture(GLuint texture) { return glad_glIsTexture(texture); }
#define glIsTexture glad_glIsTexture



#endif

#pragma endregion
#pragma region GL_VERSION_1_2
#ifndef GL_VERSION_1_2
#define GL_VERSION_1_2 1
export GLAPI int GLAD_GL_VERSION_1_2;



export typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices);
export GLAPI PFNGLDRAWRANGEELEMENTSPROC glad_glDrawRangeElements;
export inline void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices) { glad_glDrawRangeElements(mode, start, end, count, type, indices); }
#define glDrawRangeElements glad_glDrawRangeElements



export typedef void (APIENTRYP PFNGLTEXIMAGE3DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels);
export GLAPI PFNGLTEXIMAGE3DPROC glad_glTexImage3D;
export inline void glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels) { glad_glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels); }
#define glTexImage3D glad_glTexImage3D



export typedef void (APIENTRYP PFNGLTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels);
export GLAPI PFNGLTEXSUBIMAGE3DPROC glad_glTexSubImage3D;
export inline void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels) { glad_glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels); }
#define glTexSubImage3D glad_glTexSubImage3D



export typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
export GLAPI PFNGLCOPYTEXSUBIMAGE3DPROC glad_glCopyTexSubImage3D;
export inline void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) { glad_glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height); }
#define glCopyTexSubImage3D glad_glCopyTexSubImage3D



#endif
#pragma endregion
#pragma region GL_VERSION_1_3
#ifndef GL_VERSION_1_3
#define GL_VERSION_1_3 1
export GLAPI int GLAD_GL_VERSION_1_3;



export typedef void (APIENTRYP PFNGLACTIVETEXTUREPROC)(GLenum texture);
export GLAPI PFNGLACTIVETEXTUREPROC glad_glActiveTexture;
export inline void glActiveTexture(GLenum texture) { glad_glActiveTexture(texture); }
#define glActiveTexture glad_glActiveTexture



export typedef void (APIENTRYP PFNGLSAMPLECOVERAGEPROC)(GLfloat value, GLboolean invert);
export GLAPI PFNGLSAMPLECOVERAGEPROC glad_glSampleCoverage;
export inline void glSampleCoverage(GLfloat value, GLboolean invert) { glad_glSampleCoverage(value, invert); }
#define glSampleCoverage glad_glSampleCoverage



export typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE3DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data);
export GLAPI PFNGLCOMPRESSEDTEXIMAGE3DPROC glad_glCompressedTexImage3D;
export inline void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data) { glad_glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data); }
#define glCompressedTexImage3D glad_glCompressedTexImage3D



export typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data);
export GLAPI PFNGLCOMPRESSEDTEXIMAGE2DPROC glad_glCompressedTexImage2D;
export inline void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data) { glad_glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data); }
#define glCompressedTexImage2D glad_glCompressedTexImage2D



export typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE1DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* data);
export GLAPI PFNGLCOMPRESSEDTEXIMAGE1DPROC glad_glCompressedTexImage1D;
export inline void glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* data) { glad_glCompressedTexImage1D(target, level, internalformat, width, border, imageSize, data); }
#define glCompressedTexImage1D glad_glCompressedTexImage1D



export typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data);
export GLAPI PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glad_glCompressedTexSubImage3D;
export inline void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data) { glad_glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data); }
#define glCompressedTexSubImage3D glad_glCompressedTexSubImage3D



export typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data);
export GLAPI PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glad_glCompressedTexSubImage2D;
export inline void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data) { glad_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data); }
#define glCompressedTexSubImage2D glad_glCompressedTexSubImage2D



export typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data);
export GLAPI PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glad_glCompressedTexSubImage1D;
export inline void glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data) { glad_glCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data); }
#define glCompressedTexSubImage1D glad_glCompressedTexSubImage1D



export typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXIMAGEPROC)(GLenum target, GLint level, void* img);
export GLAPI PFNGLGETCOMPRESSEDTEXIMAGEPROC glad_glGetCompressedTexImage;
export inline void glGetCompressedTexImage(GLenum target, GLint level, void* img) { glad_glGetCompressedTexImage(target, level, img); }
#define glGetCompressedTexImage glad_glGetCompressedTexImage



#endif
#pragma endregion
#pragma region GL_VERSION_1_4
#ifndef GL_VERSION_1_4
#define GL_VERSION_1_4 1
export GLAPI int GLAD_GL_VERSION_1_4;



export typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEPROC)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
export GLAPI PFNGLBLENDFUNCSEPARATEPROC glad_glBlendFuncSeparate;
export inline void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) { glad_glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha); }
#define glBlendFuncSeparate glad_glBlendFuncSeparate



export typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSPROC)(GLenum mode, const GLint* first, const GLsizei* count, GLsizei drawcount);
export GLAPI PFNGLMULTIDRAWARRAYSPROC glad_glMultiDrawArrays;
export inline void glMultiDrawArrays(GLenum mode, const GLint* first, const GLsizei* count, GLsizei drawcount) { glad_glMultiDrawArrays(mode, first, count, drawcount); }
#define glMultiDrawArrays glad_glMultiDrawArrays



export typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSPROC)(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount);
export GLAPI PFNGLMULTIDRAWELEMENTSPROC glad_glMultiDrawElements;
export inline void glMultiDrawElements(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount) { glad_glMultiDrawElements(mode, count, type, indices, drawcount); }
#define glMultiDrawElements glad_glMultiDrawElements



export typedef void (APIENTRYP PFNGLPOINTPARAMETERFPROC)(GLenum pname, GLfloat param);
export GLAPI PFNGLPOINTPARAMETERFPROC glad_glPointParameterf;
export inline void glPointParameterf(GLenum pname, GLfloat param) { glad_glPointParameterf(pname, param); }
#define glPointParameterf glad_glPointParameterf



export typedef void (APIENTRYP PFNGLPOINTPARAMETERFVPROC)(GLenum pname, const GLfloat* params);
export GLAPI PFNGLPOINTPARAMETERFVPROC glad_glPointParameterfv;
export inline void glPointParameterfv(GLenum pname, const GLfloat* params) { glad_glPointParameterfv(pname, params); }
#define glPointParameterfv glad_glPointParameterfv



export typedef void (APIENTRYP PFNGLPOINTPARAMETERIPROC)(GLenum pname, GLint param);
export GLAPI PFNGLPOINTPARAMETERIPROC glad_glPointParameteri;
export inline void glPointParameteri(GLenum pname, GLint param) { glad_glPointParameteri(pname, param); }
#define glPointParameteri glad_glPointParameteri



export typedef void (APIENTRYP PFNGLPOINTPARAMETERIVPROC)(GLenum pname, const GLint* params);
export GLAPI PFNGLPOINTPARAMETERIVPROC glad_glPointParameteriv;
export inline void glPointParameteriv(GLenum pname, const GLint* params) { glad_glPointParameteriv(pname, params); }
#define glPointParameteriv glad_glPointParameteriv



export typedef void (APIENTRYP PFNGLBLENDCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
export GLAPI PFNGLBLENDCOLORPROC glad_glBlendColor;
export inline void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) { glad_glBlendColor(red, green, blue, alpha); }
#define glBlendColor glad_glBlendColor



export typedef void (APIENTRYP PFNGLBLENDEQUATIONPROC)(GLenum mode);
export GLAPI PFNGLBLENDEQUATIONPROC glad_glBlendEquation;
export inline void glBlendEquation(GLenum mode) { glad_glBlendEquation(mode); }
#define glBlendEquation glad_glBlendEquation



#endif
#pragma endregion
#pragma region GL_VERSION_1_5
#ifndef GL_VERSION_1_5
#define GL_VERSION_1_5 1
export GLAPI int GLAD_GL_VERSION_1_5;



export typedef void (APIENTRYP PFNGLGENQUERIESPROC)(GLsizei n, GLuint* ids);
export GLAPI PFNGLGENQUERIESPROC glad_glGenQueries;
export inline void glGenQueries(GLsizei n, GLuint* ids) { glad_glGenQueries(n, ids); }
#define glGenQueries glad_glGenQueries



export typedef void (APIENTRYP PFNGLDELETEQUERIESPROC)(GLsizei n, const GLuint* ids);
export GLAPI PFNGLDELETEQUERIESPROC glad_glDeleteQueries;
export inline void glDeleteQueries(GLsizei n, const GLuint* ids) { glad_glDeleteQueries(n, ids); }
#define glDeleteQueries glad_glDeleteQueries



export typedef GLboolean(APIENTRYP PFNGLISQUERYPROC)(GLuint id);
export GLAPI PFNGLISQUERYPROC glad_glIsQuery;
export inline GLboolean glIsQuery(GLuint id) { return glad_glIsQuery(id); }
#define glIsQuery glad_glIsQuery



export typedef void (APIENTRYP PFNGLBEGINQUERYPROC)(GLenum target, GLuint id);
export GLAPI PFNGLBEGINQUERYPROC glad_glBeginQuery;
export inline void glBeginQuery(GLenum target, GLuint id) { glad_glBeginQuery(target, id); }
#define glBeginQuery glad_glBeginQuery



export typedef void (APIENTRYP PFNGLENDQUERYPROC)(GLenum target);
export GLAPI PFNGLENDQUERYPROC glad_glEndQuery;
export inline void glEndQuery(GLenum target) { glad_glEndQuery(target); }
#define glEndQuery glad_glEndQuery



export typedef void (APIENTRYP PFNGLGETQUERYIVPROC)(GLenum target, GLenum pname, GLint* params);
export GLAPI PFNGLGETQUERYIVPROC glad_glGetQueryiv;
export inline void glGetQueryiv(GLenum target, GLenum pname, GLint* params) { glad_glGetQueryiv(target, pname, params); }
#define glGetQueryiv glad_glGetQueryiv



export typedef void (APIENTRYP PFNGLGETQUERYOBJECTIVPROC)(GLuint id, GLenum pname, GLint* params);
export GLAPI PFNGLGETQUERYOBJECTIVPROC glad_glGetQueryObjectiv;
export inline void glGetQueryObjectiv(GLuint id, GLenum pname, GLint* params) { glad_glGetQueryObjectiv(id, pname, params); }
#define glGetQueryObjectiv glad_glGetQueryObjectiv



export typedef void (APIENTRYP PFNGLGETQUERYOBJECTUIVPROC)(GLuint id, GLenum pname, GLuint* params);
export GLAPI PFNGLGETQUERYOBJECTUIVPROC glad_glGetQueryObjectuiv;
export inline void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint* params) { glad_glGetQueryObjectuiv(id, pname, params); }
#define glGetQueryObjectuiv glad_glGetQueryObjectuiv



export typedef void (APIENTRYP PFNGLBINDBUFFERPROC)(GLenum target, GLuint buffer);
export GLAPI PFNGLBINDBUFFERPROC glad_glBindBuffer;
export inline void glBindBuffer(GLenum target, GLuint buffer) { glad_glBindBuffer(target, buffer); }
#define glBindBuffer glad_glBindBuffer



export typedef void (APIENTRYP PFNGLDELETEBUFFERSPROC)(GLsizei n, const GLuint* buffers);
export GLAPI PFNGLDELETEBUFFERSPROC glad_glDeleteBuffers;
/// <summary>
/// Deletes the buffers (count n) specified by the buffers array. the array contains the ids of the buffers to be deleted.
/// </summary>
/// <param name="n"></param>
/// <param name="buffers"></param>
export inline void glDeleteBuffers(GLsizei n, const GLuint* buffers) { glad_glDeleteBuffers(n, buffers); }
#define glDeleteBuffers glad_glDeleteBuffers



export typedef void (APIENTRYP PFNGLGENBUFFERSPROC)(GLsizei n, GLuint* buffers);
export GLAPI PFNGLGENBUFFERSPROC glad_glGenBuffers;
/// <summary>
/// generates n buffers and stores their ids in the buffers array.
/// </summary>
/// <param name="n"></param>
/// <param name="buffers"></param>
export inline void glGenBuffers(GLsizei n, GLuint* buffers) { glad_glGenBuffers(n, buffers); }
#define glGenBuffers glad_glGenBuffers



export typedef GLboolean(APIENTRYP PFNGLISBUFFERPROC)(GLuint buffer);
export GLAPI PFNGLISBUFFERPROC glad_glIsBuffer;
export inline GLboolean glIsBuffer(GLuint buffer) { return glad_glIsBuffer(buffer); }
#define glIsBuffer glad_glIsBuffer



export typedef void (APIENTRYP PFNGLBUFFERDATAPROC)(GLenum target, GLsizeiptr size, const void* data, GLenum usage);
export GLAPI PFNGLBUFFERDATAPROC glad_glBufferData;
export inline void glBufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage) { glad_glBufferData(target, size, data, usage); }
#define glBufferData glad_glBufferData



export typedef void (APIENTRYP PFNGLBUFFERSUBDATAPROC)(GLenum target, GLintptr offset, GLsizeiptr size, const void* data);
export GLAPI PFNGLBUFFERSUBDATAPROC glad_glBufferSubData;
export inline void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void* data) { glad_glBufferSubData(target, offset, size, data); }
#define glBufferSubData glad_glBufferSubData



export typedef void (APIENTRYP PFNGLGETBUFFERSUBDATAPROC)(GLenum target, GLintptr offset, GLsizeiptr size, void* data);
export GLAPI PFNGLGETBUFFERSUBDATAPROC glad_glGetBufferSubData;
export inline void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void* data) { glad_glGetBufferSubData(target, offset, size, data); }
#define glGetBufferSubData glad_glGetBufferSubData



export typedef void* (APIENTRYP PFNGLMAPBUFFERPROC)(GLenum target, GLenum access);
export GLAPI PFNGLMAPBUFFERPROC glad_glMapBuffer;
export inline void* glMapBuffer(GLenum target, GLenum access) { return glad_glMapBuffer(target, access); }
#define glMapBuffer glad_glMapBuffer



export typedef GLboolean(APIENTRYP PFNGLUNMAPBUFFERPROC)(GLenum target);
export GLAPI PFNGLUNMAPBUFFERPROC glad_glUnmapBuffer;
export inline GLboolean glUnmapBuffer(GLenum target) { return glad_glUnmapBuffer(target); }
#define glUnmapBuffer glad_glUnmapBuffer



export typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint* params);
export GLAPI PFNGLGETBUFFERPARAMETERIVPROC glad_glGetBufferParameteriv;
export inline void glGetBufferParameteriv(GLenum target, GLenum pname, GLint* params) { glad_glGetBufferParameteriv(target, pname, params); }
#define glGetBufferParameteriv glad_glGetBufferParameteriv



export typedef void (APIENTRYP PFNGLGETBUFFERPOINTERVPROC)(GLenum target, GLenum pname, void** params);
export GLAPI PFNGLGETBUFFERPOINTERVPROC glad_glGetBufferPointerv;
export inline void glGetBufferPointerv(GLenum target, GLenum pname, void** params) { glad_glGetBufferPointerv(target, pname, params); }
#define glGetBufferPointerv glad_glGetBufferPointerv



#endif
#pragma endregion
#pragma region GL_VERSION_2_0
#ifndef GL_VERSION_2_0
#define GL_VERSION_2_0 1
export GLAPI int GLAD_GL_VERSION_2_0;



export typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEPROC)(GLenum modeRGB, GLenum modeAlpha);
export GLAPI PFNGLBLENDEQUATIONSEPARATEPROC glad_glBlendEquationSeparate;
export inline void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) { glad_glBlendEquationSeparate(modeRGB, modeAlpha); }
#define glBlendEquationSeparate glad_glBlendEquationSeparate



export typedef void (APIENTRYP PFNGLDRAWBUFFERSPROC)(GLsizei n, const GLenum* bufs);
export GLAPI PFNGLDRAWBUFFERSPROC glad_glDrawBuffers;
export inline void glDrawBuffers(GLsizei n, const GLenum* bufs) { glad_glDrawBuffers(n, bufs); }
#define glDrawBuffers glad_glDrawBuffers



export typedef void (APIENTRYP PFNGLSTENCILOPSEPARATEPROC)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
export GLAPI PFNGLSTENCILOPSEPARATEPROC glad_glStencilOpSeparate;
export inline void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) { glad_glStencilOpSeparate(face, sfail, dpfail, dppass); }
#define glStencilOpSeparate glad_glStencilOpSeparate



export typedef void (APIENTRYP PFNGLSTENCILFUNCSEPARATEPROC)(GLenum face, GLenum func, GLint ref, GLuint mask);
export GLAPI PFNGLSTENCILFUNCSEPARATEPROC glad_glStencilFuncSeparate;
export inline void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) { glad_glStencilFuncSeparate(face, func, ref, mask); }
#define glStencilFuncSeparate glad_glStencilFuncSeparate



export typedef void (APIENTRYP PFNGLSTENCILMASKSEPARATEPROC)(GLenum face, GLuint mask);
export GLAPI PFNGLSTENCILMASKSEPARATEPROC glad_glStencilMaskSeparate;
export inline void glStencilMaskSeparate(GLenum face, GLuint mask) { glad_glStencilMaskSeparate(face, mask); }
#define glStencilMaskSeparate glad_glStencilMaskSeparate



export typedef void (APIENTRYP PFNGLATTACHSHADERPROC)(GLuint program, GLuint shader);
export GLAPI PFNGLATTACHSHADERPROC glad_glAttachShader;
export inline void glAttachShader(GLuint program, GLuint shader) { glad_glAttachShader(program, shader); }
#define glAttachShader glad_glAttachShader



export typedef void (APIENTRYP PFNGLBINDATTRIBLOCATIONPROC)(GLuint program, GLuint index, const GLchar* name);
export GLAPI PFNGLBINDATTRIBLOCATIONPROC glad_glBindAttribLocation;
export inline void glBindAttribLocation(GLuint program, GLuint index, const GLchar* name) { glad_glBindAttribLocation(program, index, name); }
#define glBindAttribLocation glad_glBindAttribLocation



export typedef void (APIENTRYP PFNGLCOMPILESHADERPROC)(GLuint shader);
export GLAPI PFNGLCOMPILESHADERPROC glad_glCompileShader;
export inline void glCompileShader(GLuint shader) { glad_glCompileShader(shader); }
#define glCompileShader glad_glCompileShader



export typedef GLuint(APIENTRYP PFNGLCREATEPROGRAMPROC)(void);
export GLAPI PFNGLCREATEPROGRAMPROC glad_glCreateProgram;
export inline GLuint glCreateProgram() { return glad_glCreateProgram(); }
#define glCreateProgram glad_glCreateProgram



export typedef GLuint(APIENTRYP PFNGLCREATESHADERPROC)(GLenum type);
export GLAPI PFNGLCREATESHADERPROC glad_glCreateShader;
export inline GLuint glCreateShader(GLenum type) { return glad_glCreateShader(type); }
#define glCreateShader glad_glCreateShader



export typedef void (APIENTRYP PFNGLDELETEPROGRAMPROC)(GLuint program);
export GLAPI PFNGLDELETEPROGRAMPROC glad_glDeleteProgram;
export inline void glDeleteProgram(GLuint program) { glad_glDeleteProgram(program); }
#define glDeleteProgram glad_glDeleteProgram



export typedef void (APIENTRYP PFNGLDELETESHADERPROC)(GLuint shader);
export GLAPI PFNGLDELETESHADERPROC glad_glDeleteShader;
export inline void glDeleteShader(GLuint shader) { glad_glDeleteShader(shader); }
#define glDeleteShader glad_glDeleteShader



export typedef void (APIENTRYP PFNGLDETACHSHADERPROC)(GLuint program, GLuint shader);
export GLAPI PFNGLDETACHSHADERPROC glad_glDetachShader;
export inline void glDetachShader(GLuint program, GLuint shader) { glad_glDetachShader(program, shader); }
#define glDetachShader glad_glDetachShader



export typedef void (APIENTRYP PFNGLDISABLEVERTEXATTRIBARRAYPROC)(GLuint index);
export GLAPI PFNGLDISABLEVERTEXATTRIBARRAYPROC glad_glDisableVertexAttribArray;
export inline void glDisableVertexAttribArray(GLuint index) { glad_glDisableVertexAttribArray(index); }
#define glDisableVertexAttribArray glad_glDisableVertexAttribArray



export typedef void (APIENTRYP PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint index);
export GLAPI PFNGLENABLEVERTEXATTRIBARRAYPROC glad_glEnableVertexAttribArray;
export inline void glEnableVertexAttribArray(GLuint index) { glad_glEnableVertexAttribArray(index); }
#define glEnableVertexAttribArray glad_glEnableVertexAttribArray



export typedef void (APIENTRYP PFNGLGETACTIVEATTRIBPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
export GLAPI PFNGLGETACTIVEATTRIBPROC glad_glGetActiveAttrib;
export inline void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name) { glad_glGetActiveAttrib(program, index, bufSize, length, size, type, name); }
#define glGetActiveAttrib glad_glGetActiveAttrib



export typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
export GLAPI PFNGLGETACTIVEUNIFORMPROC glad_glGetActiveUniform;
export inline void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name) { glad_glGetActiveUniform(program, index, bufSize, length, size, type, name); }
#define glGetActiveUniform glad_glGetActiveUniform



export typedef void (APIENTRYP PFNGLGETATTACHEDSHADERSPROC)(GLuint program, GLsizei maxCount, GLsizei* count, GLuint* shaders);
export GLAPI PFNGLGETATTACHEDSHADERSPROC glad_glGetAttachedShaders;
export inline void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei* count, GLuint* shaders) { glad_glGetAttachedShaders(program, maxCount, count, shaders); }
#define glGetAttachedShaders glad_glGetAttachedShaders



export typedef GLint(APIENTRYP PFNGLGETATTRIBLOCATIONPROC)(GLuint program, const GLchar* name);
export GLAPI PFNGLGETATTRIBLOCATIONPROC glad_glGetAttribLocation;
export inline GLint glGetAttribLocation(GLuint program, const GLchar* name) { return glad_glGetAttribLocation(program, name); }
#define glGetAttribLocation glad_glGetAttribLocation



export typedef void (APIENTRYP PFNGLGETPROGRAMIVPROC)(GLuint program, GLenum pname, GLint* params);
export GLAPI PFNGLGETPROGRAMIVPROC glad_glGetProgramiv;
export inline void glGetProgramiv(GLuint program, GLenum pname, GLint* params) { glad_glGetProgramiv(program, pname, params); }
#define glGetProgramiv glad_glGetProgramiv



export typedef void (APIENTRYP PFNGLGETPROGRAMINFOLOGPROC)(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
export GLAPI PFNGLGETPROGRAMINFOLOGPROC glad_glGetProgramInfoLog;
export inline void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog) { glad_glGetProgramInfoLog(program, bufSize, length, infoLog); }
#define glGetProgramInfoLog glad_glGetProgramInfoLog



export typedef void (APIENTRYP PFNGLGETSHADERIVPROC)(GLuint shader, GLenum pname, GLint* params);
export GLAPI PFNGLGETSHADERIVPROC glad_glGetShaderiv;
export inline void glGetShaderiv(GLuint shader, GLenum pname, GLint* params) { glad_glGetShaderiv(shader, pname, params); }
#define glGetShaderiv glad_glGetShaderiv



export typedef void (APIENTRYP PFNGLGETSHADERINFOLOGPROC)(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
export GLAPI PFNGLGETSHADERINFOLOGPROC glad_glGetShaderInfoLog;
export inline void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog) { glad_glGetShaderInfoLog(shader, bufSize, length, infoLog); }
#define glGetShaderInfoLog glad_glGetShaderInfoLog



export typedef void (APIENTRYP PFNGLGETSHADERSOURCEPROC)(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source);
export GLAPI PFNGLGETSHADERSOURCEPROC glad_glGetShaderSource;
export inline void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source) { glad_glGetShaderSource(shader, bufSize, length, source); }
#define glGetShaderSource glad_glGetShaderSource



export typedef GLint(APIENTRYP PFNGLGETUNIFORMLOCATIONPROC)(GLuint program, const GLchar* name);
export GLAPI PFNGLGETUNIFORMLOCATIONPROC glad_glGetUniformLocation;
export inline GLint glGetUniformLocation(GLuint program, const GLchar* name) { return glad_glGetUniformLocation(program, name); }
#define glGetUniformLocation glad_glGetUniformLocation



export typedef void (APIENTRYP PFNGLGETUNIFORMFVPROC)(GLuint program, GLint location, GLfloat* params);
export GLAPI PFNGLGETUNIFORMFVPROC glad_glGetUniformfv;
export inline void glGetUniformfv(GLuint program, GLint location, GLfloat* params) { glad_glGetUniformfv(program, location, params); }
#define glGetUniformfv glad_glGetUniformfv



export typedef void (APIENTRYP PFNGLGETUNIFORMIVPROC)(GLuint program, GLint location, GLint* params);
export GLAPI PFNGLGETUNIFORMIVPROC glad_glGetUniformiv;
export inline void glGetUniformiv(GLuint program, GLint location, GLint* params) { glad_glGetUniformiv(program, location, params); }
#define glGetUniformiv glad_glGetUniformiv



export typedef void (APIENTRYP PFNGLGETVERTEXATTRIBDVPROC)(GLuint index, GLenum pname, GLdouble* params);
export GLAPI PFNGLGETVERTEXATTRIBDVPROC glad_glGetVertexAttribdv;
export inline void glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble* params) { glad_glGetVertexAttribdv(index, pname, params); }
#define glGetVertexAttribdv glad_glGetVertexAttribdv



export typedef void (APIENTRYP PFNGLGETVERTEXATTRIBFVPROC)(GLuint index, GLenum pname, GLfloat* params);
export GLAPI PFNGLGETVERTEXATTRIBFVPROC glad_glGetVertexAttribfv;
export inline void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat* params) { glad_glGetVertexAttribfv(index, pname, params); }
#define glGetVertexAttribfv glad_glGetVertexAttribfv



export typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIVPROC)(GLuint index, GLenum pname, GLint* params);
export GLAPI PFNGLGETVERTEXATTRIBIVPROC glad_glGetVertexAttribiv;
export inline void glGetVertexAttribiv(GLuint index, GLenum pname, GLint* params) { glad_glGetVertexAttribiv(index, pname, params); }
#define glGetVertexAttribiv glad_glGetVertexAttribiv



export typedef void (APIENTRYP PFNGLGETVERTEXATTRIBPOINTERVPROC)(GLuint index, GLenum pname, void** pointer);
export GLAPI PFNGLGETVERTEXATTRIBPOINTERVPROC glad_glGetVertexAttribPointerv;
export inline void glGetVertexAttribPointerv(GLuint index, GLenum pname, void** pointer) { glad_glGetVertexAttribPointerv(index, pname, pointer); }
#define glGetVertexAttribPointerv glad_glGetVertexAttribPointerv



export typedef GLboolean(APIENTRYP PFNGLISPROGRAMPROC)(GLuint program);
export GLAPI PFNGLISPROGRAMPROC glad_glIsProgram;
export inline GLboolean glIsProgram(GLuint program) { return glad_glIsProgram(program); }
#define glIsProgram glad_glIsProgram



export typedef GLboolean(APIENTRYP PFNGLISSHADERPROC)(GLuint shader);
export GLAPI PFNGLISSHADERPROC glad_glIsShader;
export inline GLboolean glIsShader(GLuint shader) { return glad_glIsShader(shader); }
#define glIsShader glad_glIsShader



export typedef void (APIENTRYP PFNGLLINKPROGRAMPROC)(GLuint program);
export GLAPI PFNGLLINKPROGRAMPROC glad_glLinkProgram;
export inline void glLinkProgram(GLuint program) { glad_glLinkProgram(program); }
#define glLinkProgram glad_glLinkProgram



export typedef void (APIENTRYP PFNGLSHADERSOURCEPROC)(GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length);
export GLAPI PFNGLSHADERSOURCEPROC glad_glShaderSource;
export inline void glShaderSource(GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length) { glad_glShaderSource(shader, count, string, length); }
#define glShaderSource glad_glShaderSource



export typedef void (APIENTRYP PFNGLUSEPROGRAMPROC)(GLuint program);
export GLAPI PFNGLUSEPROGRAMPROC glad_glUseProgram;
export inline void glUseProgram(GLuint program) { glad_glUseProgram(program); }
#define glUseProgram glad_glUseProgram



export typedef void (APIENTRYP PFNGLUNIFORM1FPROC)(GLint location, GLfloat v0);
export GLAPI PFNGLUNIFORM1FPROC glad_glUniform1f;
export inline void glUniform1f(GLint location, GLfloat v0) { glad_glUniform1f(location, v0); }
#define glUniform1f glad_glUniform1f



export typedef void (APIENTRYP PFNGLUNIFORM2FPROC)(GLint location, GLfloat v0, GLfloat v1);
export GLAPI PFNGLUNIFORM2FPROC glad_glUniform2f;
export inline void glUniform2f(GLint location, GLfloat v0, GLfloat v1) { glad_glUniform2f(location, v0, v1); }
#define glUniform2f glad_glUniform2f



export typedef void (APIENTRYP PFNGLUNIFORM3FPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
export GLAPI PFNGLUNIFORM3FPROC glad_glUniform3f;
export inline void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) { glad_glUniform3f(location, v0, v1, v2); }
#define glUniform3f glad_glUniform3f



export typedef void (APIENTRYP PFNGLUNIFORM4FPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
export GLAPI PFNGLUNIFORM4FPROC glad_glUniform4f;
export inline void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) { glad_glUniform4f(location, v0, v1, v2, v3); }
#define glUniform4f glad_glUniform4f



export typedef void (APIENTRYP PFNGLUNIFORM1IPROC)(GLint location, GLint v0);
export GLAPI PFNGLUNIFORM1IPROC glad_glUniform1i;
export inline void glUniform1i(GLint location, GLint v0) { glad_glUniform1i(location, v0); }
#define glUniform1i glad_glUniform1i



export typedef void (APIENTRYP PFNGLUNIFORM2IPROC)(GLint location, GLint v0, GLint v1);
export GLAPI PFNGLUNIFORM2IPROC glad_glUniform2i;
export inline void glUniform2i(GLint location, GLint v0, GLint v1) { glad_glUniform2i(location, v0, v1); }
#define glUniform2i glad_glUniform2i



export typedef void (APIENTRYP PFNGLUNIFORM3IPROC)(GLint location, GLint v0, GLint v1, GLint v2);
export GLAPI PFNGLUNIFORM3IPROC glad_glUniform3i;
export inline void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) { glad_glUniform3i(location, v0, v1, v2); }
#define glUniform3i glad_glUniform3i



export typedef void (APIENTRYP PFNGLUNIFORM4IPROC)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
export GLAPI PFNGLUNIFORM4IPROC glad_glUniform4i;
export inline void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) { glad_glUniform4i(location, v0, v1, v2, v3); }
#define glUniform4i glad_glUniform4i



export typedef void (APIENTRYP PFNGLUNIFORM1FVPROC)(GLint location, GLsizei count, const GLfloat* value);
export GLAPI PFNGLUNIFORM1FVPROC glad_glUniform1fv;
export inline void glUniform1fv(GLint location, GLsizei count, const GLfloat* value) { glad_glUniform1fv(location, count, value); }
#define glUniform1fv glad_glUniform1fv



export typedef void (APIENTRYP PFNGLUNIFORM2FVPROC)(GLint location, GLsizei count, const GLfloat* value);
export GLAPI PFNGLUNIFORM2FVPROC glad_glUniform2fv;
export inline void glUniform2fv(GLint location, GLsizei count, const GLfloat* value) { glad_glUniform2fv(location, count, value); }
#define glUniform2fv glad_glUniform2fv



export typedef void (APIENTRYP PFNGLUNIFORM3FVPROC)(GLint location, GLsizei count, const GLfloat* value);
export GLAPI PFNGLUNIFORM3FVPROC glad_glUniform3fv;
export inline void glUniform3fv(GLint location, GLsizei count, const GLfloat* value) { glad_glUniform3fv(location, count, value); }
#define glUniform3fv glad_glUniform3fv



export typedef void (APIENTRYP PFNGLUNIFORM4FVPROC)(GLint location, GLsizei count, const GLfloat* value);
export GLAPI PFNGLUNIFORM4FVPROC glad_glUniform4fv;
export inline void glUniform4fv(GLint location, GLsizei count, const GLfloat* value) { glad_glUniform4fv(location, count, value); }
#define glUniform4fv glad_glUniform4fv



export typedef void (APIENTRYP PFNGLUNIFORM1IVPROC)(GLint location, GLsizei count, const GLint* value);
export GLAPI PFNGLUNIFORM1IVPROC glad_glUniform1iv;
export inline void glUniform1iv(GLint location, GLsizei count, const GLint* value) { glad_glUniform1iv(location, count, value); }
#define glUniform1iv glad_glUniform1iv



export typedef void (APIENTRYP PFNGLUNIFORM2IVPROC)(GLint location, GLsizei count, const GLint* value);
export GLAPI PFNGLUNIFORM2IVPROC glad_glUniform2iv;
export inline void glUniform2iv(GLint location, GLsizei count, const GLint* value) { glad_glUniform2iv(location, count, value); }
#define glUniform2iv glad_glUniform2iv



export typedef void (APIENTRYP PFNGLUNIFORM3IVPROC)(GLint location, GLsizei count, const GLint* value);
export GLAPI PFNGLUNIFORM3IVPROC glad_glUniform3iv;
export inline void glUniform3iv(GLint location, GLsizei count, const GLint* value) { glad_glUniform3iv(location, count, value); }
#define glUniform3iv glad_glUniform3iv



export typedef void (APIENTRYP PFNGLUNIFORM4IVPROC)(GLint location, GLsizei count, const GLint* value);
export GLAPI PFNGLUNIFORM4IVPROC glad_glUniform4iv;
export inline void glUniform4iv(GLint location, GLsizei count, const GLint* value) { glad_glUniform4iv(location, count, value); }
#define glUniform4iv glad_glUniform4iv



export typedef void (APIENTRYP PFNGLUNIFORMMATRIX2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
export GLAPI PFNGLUNIFORMMATRIX2FVPROC glad_glUniformMatrix2fv;
export inline void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { glad_glUniformMatrix2fv(location, count, transpose, value); }
#define glUniformMatrix2fv glad_glUniformMatrix2fv



export typedef void (APIENTRYP PFNGLUNIFORMMATRIX3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
export GLAPI PFNGLUNIFORMMATRIX3FVPROC glad_glUniformMatrix3fv;
export inline void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { glad_glUniformMatrix3fv(location, count, transpose, value); }
#define glUniformMatrix3fv glad_glUniformMatrix3fv



export typedef void (APIENTRYP PFNGLUNIFORMMATRIX4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
export GLAPI PFNGLUNIFORMMATRIX4FVPROC glad_glUniformMatrix4fv;
export inline void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { glad_glUniformMatrix4fv(location, count, transpose, value); }
#define glUniformMatrix4fv glad_glUniformMatrix4fv



export typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPROC)(GLuint program);
export GLAPI PFNGLVALIDATEPROGRAMPROC glad_glValidateProgram;
export inline void glValidateProgram(GLuint program) { glad_glValidateProgram(program); }
#define glValidateProgram glad_glValidateProgram



export typedef void (APIENTRYP PFNGLVERTEXATTRIB1DPROC)(GLuint index, GLdouble x);
export GLAPI PFNGLVERTEXATTRIB1DPROC glad_glVertexAttrib1d;
export inline void glVertexAttrib1d(GLuint index, GLdouble x) { glad_glVertexAttrib1d(index, x); }
#define glVertexAttrib1d glad_glVertexAttrib1d



export typedef void (APIENTRYP PFNGLVERTEXATTRIB1DVPROC)(GLuint index, const GLdouble* v);
export GLAPI PFNGLVERTEXATTRIB1DVPROC glad_glVertexAttrib1dv;
export inline void glVertexAttrib1dv(GLuint index, const GLdouble* v) { glad_glVertexAttrib1dv(index, v); }
#define glVertexAttrib1dv glad_glVertexAttrib1dv



export typedef void (APIENTRYP PFNGLVERTEXATTRIB1FPROC)(GLuint index, GLfloat x);
export GLAPI PFNGLVERTEXATTRIB1FPROC glad_glVertexAttrib1f;
export inline void glVertexAttrib1f(GLuint index, GLfloat x) { glad_glVertexAttrib1f(index, x); }
#define glVertexAttrib1f glad_glVertexAttrib1f



export typedef void (APIENTRYP PFNGLVERTEXATTRIB1FVPROC)(GLuint index, const GLfloat* v);
export GLAPI PFNGLVERTEXATTRIB1FVPROC glad_glVertexAttrib1fv;
export inline void glVertexAttrib1fv(GLuint index, const GLfloat* v) { glad_glVertexAttrib1fv(index, v); }
#define glVertexAttrib1fv glad_glVertexAttrib1fv



export typedef void (APIENTRYP PFNGLVERTEXATTRIB1SPROC)(GLuint index, GLshort x);
export GLAPI PFNGLVERTEXATTRIB1SPROC glad_glVertexAttrib1s;
export inline void glVertexAttrib1s(GLuint index, GLshort x) { glad_glVertexAttrib1s(index, x); }
#define glVertexAttrib1s glad_glVertexAttrib1s



export typedef void (APIENTRYP PFNGLVERTEXATTRIB1SVPROC)(GLuint index, const GLshort* v);
export GLAPI PFNGLVERTEXATTRIB1SVPROC glad_glVertexAttrib1sv;
export inline void glVertexAttrib1sv(GLuint index, const GLshort* v) { glad_glVertexAttrib1sv(index, v); }
#define glVertexAttrib1sv glad_glVertexAttrib1sv



export typedef void (APIENTRYP PFNGLVERTEXATTRIB2DPROC)(GLuint index, GLdouble x, GLdouble y);
export GLAPI PFNGLVERTEXATTRIB2DPROC glad_glVertexAttrib2d;
export inline void glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y) { glad_glVertexAttrib2d(index, x, y); }
#define glVertexAttrib2d glad_glVertexAttrib2d



export typedef void (APIENTRYP PFNGLVERTEXATTRIB2DVPROC)(GLuint index, const GLdouble* v);
export GLAPI PFNGLVERTEXATTRIB2DVPROC glad_glVertexAttrib2dv;
export inline void glVertexAttrib2dv(GLuint index, const GLdouble* v) { glad_glVertexAttrib2dv(index, v); }
#define glVertexAttrib2dv glad_glVertexAttrib2dv



export typedef void (APIENTRYP PFNGLVERTEXATTRIB2FPROC)(GLuint index, GLfloat x, GLfloat y);
export GLAPI PFNGLVERTEXATTRIB2FPROC glad_glVertexAttrib2f;
export inline void glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) { glad_glVertexAttrib2f(index, x, y); }
#define glVertexAttrib2f glad_glVertexAttrib2f



export typedef void (APIENTRYP PFNGLVERTEXATTRIB2FVPROC)(GLuint index, const GLfloat* v);
export GLAPI PFNGLVERTEXATTRIB2FVPROC glad_glVertexAttrib2fv;
export inline void glVertexAttrib2fv(GLuint index, const GLfloat* v) { glad_glVertexAttrib2fv(index, v); }
#define glVertexAttrib2fv glad_glVertexAttrib2fv



export typedef void (APIENTRYP PFNGLVERTEXATTRIB2SPROC)(GLuint index, GLshort x, GLshort y);
export GLAPI PFNGLVERTEXATTRIB2SPROC glad_glVertexAttrib2s;
export inline void glVertexAttrib2s(GLuint index, GLshort x, GLshort y) { glad_glVertexAttrib2s(index, x, y); }
#define glVertexAttrib2s glad_glVertexAttrib2s



export typedef void (APIENTRYP PFNGLVERTEXATTRIB2SVPROC)(GLuint index, const GLshort* v);
export GLAPI PFNGLVERTEXATTRIB2SVPROC glad_glVertexAttrib2sv;
export inline void glVertexAttrib2sv(GLuint index, const GLshort* v) { glad_glVertexAttrib2sv(index, v); }
#define glVertexAttrib2sv glad_glVertexAttrib2sv



export typedef void (APIENTRYP PFNGLVERTEXATTRIB3DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
export GLAPI PFNGLVERTEXATTRIB3DPROC glad_glVertexAttrib3d;
export inline void glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) { glad_glVertexAttrib3d(index, x, y, z); }
#define glVertexAttrib3d glad_glVertexAttrib3d



export typedef void (APIENTRYP PFNGLVERTEXATTRIB3DVPROC)(GLuint index, const GLdouble* v);
export GLAPI PFNGLVERTEXATTRIB3DVPROC glad_glVertexAttrib3dv;
export inline void glVertexAttrib3dv(GLuint index, const GLdouble* v) { glad_glVertexAttrib3dv(index, v); }
#define glVertexAttrib3dv glad_glVertexAttrib3dv



export typedef void (APIENTRYP PFNGLVERTEXATTRIB3FPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
export GLAPI PFNGLVERTEXATTRIB3FPROC glad_glVertexAttrib3f;
export inline void glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) { glad_glVertexAttrib3f(index, x, y, z); }
#define glVertexAttrib3f glad_glVertexAttrib3f



export typedef void (APIENTRYP PFNGLVERTEXATTRIB3FVPROC)(GLuint index, const GLfloat* v);
export GLAPI PFNGLVERTEXATTRIB3FVPROC glad_glVertexAttrib3fv;
export inline void glVertexAttrib3fv(GLuint index, const GLfloat* v) { glad_glVertexAttrib3fv(index, v); }
#define glVertexAttrib3fv glad_glVertexAttrib3fv



export typedef void (APIENTRYP PFNGLVERTEXATTRIB3SPROC)(GLuint index, GLshort x, GLshort y, GLshort z);
export GLAPI PFNGLVERTEXATTRIB3SPROC glad_glVertexAttrib3s;
export inline void glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z) { glad_glVertexAttrib3s(index, x, y, z); }
#define glVertexAttrib3s glad_glVertexAttrib3s



export typedef void (APIENTRYP PFNGLVERTEXATTRIB3SVPROC)(GLuint index, const GLshort* v);
export GLAPI PFNGLVERTEXATTRIB3SVPROC glad_glVertexAttrib3sv;
export inline void glVertexAttrib3sv(GLuint index, const GLshort* v) { glad_glVertexAttrib3sv(index, v); }
#define glVertexAttrib3sv glad_glVertexAttrib3sv



export typedef void (APIENTRYP PFNGLVERTEXATTRIB4NBVPROC)(GLuint index, const GLbyte* v);
export GLAPI PFNGLVERTEXATTRIB4NBVPROC glad_glVertexAttrib4Nbv;
export inline void glVertexAttrib4Nbv(GLuint index, const GLbyte* v) { glad_glVertexAttrib4Nbv(index, v); }
#define glVertexAttrib4Nbv glad_glVertexAttrib4Nbv



export typedef void (APIENTRYP PFNGLVERTEXATTRIB4NIVPROC)(GLuint index, const GLint* v);
export GLAPI PFNGLVERTEXATTRIB4NIVPROC glad_glVertexAttrib4Niv;
export inline void glVertexAttrib4Niv(GLuint index, const GLint* v) { glad_glVertexAttrib4Niv(index, v); }
#define glVertexAttrib4Niv glad_glVertexAttrib4Niv



export typedef void (APIENTRYP PFNGLVERTEXATTRIB4NSVPROC)(GLuint index, const GLshort* v);
export GLAPI PFNGLVERTEXATTRIB4NSVPROC glad_glVertexAttrib4Nsv;
export inline void glVertexAttrib4Nsv(GLuint index, const GLshort* v) { glad_glVertexAttrib4Nsv(index, v); }
#define glVertexAttrib4Nsv glad_glVertexAttrib4Nsv



export typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBPROC)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
export GLAPI PFNGLVERTEXATTRIB4NUBPROC glad_glVertexAttrib4Nub;
export inline void glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) { glad_glVertexAttrib4Nub(index, x, y, z, w); }
#define glVertexAttrib4Nub glad_glVertexAttrib4Nub



export typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBVPROC)(GLuint index, const GLubyte* v);
export GLAPI PFNGLVERTEXATTRIB4NUBVPROC glad_glVertexAttrib4Nubv;
export inline void glVertexAttrib4Nubv(GLuint index, const GLubyte* v) { glad_glVertexAttrib4Nubv(index, v); }
#define glVertexAttrib4Nubv glad_glVertexAttrib4Nubv



export typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUIVPROC)(GLuint index, const GLuint* v);
export GLAPI PFNGLVERTEXATTRIB4NUIVPROC glad_glVertexAttrib4Nuiv;
export inline void glVertexAttrib4Nuiv(GLuint index, const GLuint* v) { glad_glVertexAttrib4Nuiv(index, v); }
#define glVertexAttrib4Nuiv glad_glVertexAttrib4Nuiv



export typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUSVPROC)(GLuint index, const GLushort* v);
export GLAPI PFNGLVERTEXATTRIB4NUSVPROC glad_glVertexAttrib4Nusv;
export inline void glVertexAttrib4Nusv(GLuint index, const GLushort* v) { glad_glVertexAttrib4Nusv(index, v); }
#define glVertexAttrib4Nusv glad_glVertexAttrib4Nusv



export typedef void (APIENTRYP PFNGLVERTEXATTRIB4BVPROC)(GLuint index, const GLbyte* v);
export GLAPI PFNGLVERTEXATTRIB4BVPROC glad_glVertexAttrib4bv;
export inline void glVertexAttrib4bv(GLuint index, const GLbyte* v) { glad_glVertexAttrib4bv(index, v); }
#define glVertexAttrib4bv glad_glVertexAttrib4bv



export typedef void (APIENTRYP PFNGLVERTEXATTRIB4DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
export GLAPI PFNGLVERTEXATTRIB4DPROC glad_glVertexAttrib4d;
export inline void glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) { glad_glVertexAttrib4d(index, x, y, z, w); }
#define glVertexAttrib4d glad_glVertexAttrib4d



export typedef void (APIENTRYP PFNGLVERTEXATTRIB4DVPROC)(GLuint index, const GLdouble* v);
export GLAPI PFNGLVERTEXATTRIB4DVPROC glad_glVertexAttrib4dv;
export inline void glVertexAttrib4dv(GLuint index, const GLdouble* v) { glad_glVertexAttrib4dv(index, v); }
#define glVertexAttrib4dv glad_glVertexAttrib4dv



export typedef void (APIENTRYP PFNGLVERTEXATTRIB4FPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
export GLAPI PFNGLVERTEXATTRIB4FPROC glad_glVertexAttrib4f;
export inline void glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) { glad_glVertexAttrib4f(index, x, y, z, w); }
#define glVertexAttrib4f glad_glVertexAttrib4f



export typedef void (APIENTRYP PFNGLVERTEXATTRIB4FVPROC)(GLuint index, const GLfloat* v);
export GLAPI PFNGLVERTEXATTRIB4FVPROC glad_glVertexAttrib4fv;
export inline void glVertexAttrib4fv(GLuint index, const GLfloat* v) { glad_glVertexAttrib4fv(index, v); }
#define glVertexAttrib4fv glad_glVertexAttrib4fv



export typedef void (APIENTRYP PFNGLVERTEXATTRIB4IVPROC)(GLuint index, const GLint* v);
export GLAPI PFNGLVERTEXATTRIB4IVPROC glad_glVertexAttrib4iv;
export inline void glVertexAttrib4iv(GLuint index, const GLint* v) { glad_glVertexAttrib4iv(index, v); }
#define glVertexAttrib4iv glad_glVertexAttrib4iv



export typedef void (APIENTRYP PFNGLVERTEXATTRIB4SPROC)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
export GLAPI PFNGLVERTEXATTRIB4SPROC glad_glVertexAttrib4s;
export inline void glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) { glad_glVertexAttrib4s(index, x, y, z, w); }
#define glVertexAttrib4s glad_glVertexAttrib4s



export typedef void (APIENTRYP PFNGLVERTEXATTRIB4SVPROC)(GLuint index, const GLshort* v);
export GLAPI PFNGLVERTEXATTRIB4SVPROC glad_glVertexAttrib4sv;
export inline void glVertexAttrib4sv(GLuint index, const GLshort* v) { glad_glVertexAttrib4sv(index, v); }
#define glVertexAttrib4sv glad_glVertexAttrib4sv



export typedef void (APIENTRYP PFNGLVERTEXATTRIB4UBVPROC)(GLuint index, const GLubyte* v);
export GLAPI PFNGLVERTEXATTRIB4UBVPROC glad_glVertexAttrib4ubv;
export inline void glVertexAttrib4ubv(GLuint index, const GLubyte* v) { glad_glVertexAttrib4ubv(index, v); }
#define glVertexAttrib4ubv glad_glVertexAttrib4ubv



export typedef void (APIENTRYP PFNGLVERTEXATTRIB4UIVPROC)(GLuint index, const GLuint* v);
export GLAPI PFNGLVERTEXATTRIB4UIVPROC glad_glVertexAttrib4uiv;
export inline void glVertexAttrib4uiv(GLuint index, const GLuint* v) { glad_glVertexAttrib4uiv(index, v); }
#define glVertexAttrib4uiv glad_glVertexAttrib4uiv



export typedef void (APIENTRYP PFNGLVERTEXATTRIB4USVPROC)(GLuint index, const GLushort* v);
export GLAPI PFNGLVERTEXATTRIB4USVPROC glad_glVertexAttrib4usv;
export inline void glVertexAttrib4usv(GLuint index, const GLushort* v) { glad_glVertexAttrib4usv(index, v); }
#define glVertexAttrib4usv glad_glVertexAttrib4usv



export typedef void (APIENTRYP PFNGLVERTEXATTRIBPOINTERPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);
export GLAPI PFNGLVERTEXATTRIBPOINTERPROC glad_glVertexAttribPointer;
export inline void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer) { glad_glVertexAttribPointer(index, size, type, normalized, stride, pointer); }
#define glVertexAttribPointer glad_glVertexAttribPointer



#endif
#pragma endregion
#pragma region GL_VERSION_2_1
#ifndef GL_VERSION_2_1
#define GL_VERSION_2_1 1
export GLAPI int GLAD_GL_VERSION_2_1;



export typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
export GLAPI PFNGLUNIFORMMATRIX2X3FVPROC glad_glUniformMatrix2x3fv;
export inline void glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { glad_glUniformMatrix2x3fv(location, count, transpose, value); }
#define glUniformMatrix2x3fv glad_glUniformMatrix2x3fv



export typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
export GLAPI PFNGLUNIFORMMATRIX3X2FVPROC glad_glUniformMatrix3x2fv;
export inline void glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { glad_glUniformMatrix3x2fv(location, count, transpose, value); }
#define glUniformMatrix3x2fv glad_glUniformMatrix3x2fv



export typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
export GLAPI PFNGLUNIFORMMATRIX2X4FVPROC glad_glUniformMatrix2x4fv;
export inline void glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { glad_glUniformMatrix2x4fv(location, count, transpose, value); }
#define glUniformMatrix2x4fv glad_glUniformMatrix2x4fv



export typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
export GLAPI PFNGLUNIFORMMATRIX4X2FVPROC glad_glUniformMatrix4x2fv;
export inline void glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { glad_glUniformMatrix4x2fv(location, count, transpose, value); }
#define glUniformMatrix4x2fv glad_glUniformMatrix4x2fv



export typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
export GLAPI PFNGLUNIFORMMATRIX3X4FVPROC glad_glUniformMatrix3x4fv;
export inline void glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { glad_glUniformMatrix3x4fv(location, count, transpose, value); }
#define glUniformMatrix3x4fv glad_glUniformMatrix3x4fv



export typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
export GLAPI PFNGLUNIFORMMATRIX4X3FVPROC glad_glUniformMatrix4x3fv;
export inline void glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { glad_glUniformMatrix4x3fv(location, count, transpose, value); }
#define glUniformMatrix4x3fv glad_glUniformMatrix4x3fv



#endif
#pragma endregion
#pragma region GL_VERSION_3_0
#ifndef GL_VERSION_3_0
#define GL_VERSION_3_0 1
export GLAPI int GLAD_GL_VERSION_3_0;



export typedef void (APIENTRYP PFNGLCOLORMASKIPROC)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
export GLAPI PFNGLCOLORMASKIPROC glad_glColorMaski;
export inline void glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) { glad_glColorMaski(index, r, g, b, a); }
#define glColorMaski glad_glColorMaski



export typedef void (APIENTRYP PFNGLGETBOOLEANI_VPROC)(GLenum target, GLuint index, GLboolean* data);
export GLAPI PFNGLGETBOOLEANI_VPROC glad_glGetBooleani_v;
export inline void glGetBooleani_v(GLenum target, GLuint index, GLboolean* data) { glad_glGetBooleani_v(target, index, data); }
#define glGetBooleani_v glad_glGetBooleani_v




export typedef void (APIENTRYP PFNGLGETINTEGERI_VPROC)(GLenum target, GLuint index, GLint* data);
export GLAPI PFNGLGETINTEGERI_VPROC glad_glGetIntegeri_v;
export inline void glGetIntegeri_v(GLenum target, GLuint index, GLint* data) { glad_glGetIntegeri_v(target, index, data); }
#define glGetIntegeri_v glad_glGetIntegeri_v




export typedef void (APIENTRYP PFNGLENABLEIPROC)(GLenum target, GLuint index);
export GLAPI PFNGLENABLEIPROC glad_glEnablei;
export inline void glEnablei(GLenum target, GLuint index) { glad_glEnablei(target, index); }
#define glEnablei glad_glEnablei




export typedef void (APIENTRYP PFNGLDISABLEIPROC)(GLenum target, GLuint index);
export GLAPI PFNGLDISABLEIPROC glad_glDisablei;
export inline void glDisablei(GLenum target, GLuint index) { glad_glDisablei(target, index); }
#define glDisablei glad_glDisablei




export typedef GLboolean(APIENTRYP PFNGLISENABLEDIPROC)(GLenum target, GLuint index);
export GLAPI PFNGLISENABLEDIPROC glad_glIsEnabledi;
export inline GLboolean glIsEnabledi(GLenum target, GLuint index) { return glad_glIsEnabledi(target, index); }
#define glIsEnabledi glad_glIsEnabledi




export typedef void (APIENTRYP PFNGLBEGINTRANSFORMFEEDBACKPROC)(GLenum primitiveMode);
export GLAPI PFNGLBEGINTRANSFORMFEEDBACKPROC glad_glBeginTransformFeedback;
export inline void glBeginTransformFeedback(GLenum primitiveMode) { glad_glBeginTransformFeedback(primitiveMode); }
#define glBeginTransformFeedback glad_glBeginTransformFeedback




export typedef void (APIENTRYP PFNGLENDTRANSFORMFEEDBACKPROC)(void);
export GLAPI PFNGLENDTRANSFORMFEEDBACKPROC glad_glEndTransformFeedback;
export inline void glEndTransformFeedback() { glad_glEndTransformFeedback(); }
#define glEndTransformFeedback glad_glEndTransformFeedback




export typedef void (APIENTRYP PFNGLBINDBUFFERRANGEPROC)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
export GLAPI PFNGLBINDBUFFERRANGEPROC glad_glBindBufferRange;
export inline void glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) { glad_glBindBufferRange(target, index, buffer, offset, size); }
#define glBindBufferRange glad_glBindBufferRange




export typedef void (APIENTRYP PFNGLBINDBUFFERBASEPROC)(GLenum target, GLuint index, GLuint buffer);
export GLAPI PFNGLBINDBUFFERBASEPROC glad_glBindBufferBase;
export inline void glBindBufferBase(GLenum target, GLuint index, GLuint buffer) { glad_glBindBufferBase(target, index, buffer); }
#define glBindBufferBase glad_glBindBufferBase




export typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKVARYINGSPROC)(GLuint program, GLsizei count, const GLchar* const* varyings, GLenum bufferMode);
export GLAPI PFNGLTRANSFORMFEEDBACKVARYINGSPROC glad_glTransformFeedbackVaryings;
export inline void glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar* const* varyings, GLenum bufferMode) { glad_glTransformFeedbackVaryings(program, count, varyings, bufferMode); }
#define glTransformFeedbackVaryings glad_glTransformFeedbackVaryings




export typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name);
export GLAPI PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glad_glGetTransformFeedbackVarying;
export inline void glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name) { glad_glGetTransformFeedbackVarying(program, index, bufSize, length, size, type, name); }
#define glGetTransformFeedbackVarying glad_glGetTransformFeedbackVarying




export typedef void (APIENTRYP PFNGLCLAMPCOLORPROC)(GLenum target, GLenum clamp);
export GLAPI PFNGLCLAMPCOLORPROC glad_glClampColor;
export inline void glClampColor(GLenum target, GLenum clamp) { glad_glClampColor(target, clamp); }
#define glClampColor glad_glClampColor




export typedef void (APIENTRYP PFNGLBEGINCONDITIONALRENDERPROC)(GLuint id, GLenum mode);
export GLAPI PFNGLBEGINCONDITIONALRENDERPROC glad_glBeginConditionalRender;
export inline void glBeginConditionalRender(GLuint id, GLenum mode) { glad_glBeginConditionalRender(id, mode); }
#define glBeginConditionalRender glad_glBeginConditionalRender




export typedef void (APIENTRYP PFNGLENDCONDITIONALRENDERPROC)(void);
export GLAPI PFNGLENDCONDITIONALRENDERPROC glad_glEndConditionalRender;
export inline void glEndConditionalRender() { glad_glEndConditionalRender(); }
#define glEndConditionalRender glad_glEndConditionalRender




export typedef void (APIENTRYP PFNGLVERTEXATTRIBIPOINTERPROC)(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer);
export GLAPI PFNGLVERTEXATTRIBIPOINTERPROC glad_glVertexAttribIPointer;
export inline void glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer) { glad_glVertexAttribIPointer(index, size, type, stride, pointer); }
#define glVertexAttribIPointer glad_glVertexAttribIPointer




export typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIIVPROC)(GLuint index, GLenum pname, GLint* params);
export GLAPI PFNGLGETVERTEXATTRIBIIVPROC glad_glGetVertexAttribIiv;
export inline void glGetVertexAttribIiv(GLuint index, GLenum pname, GLint* params) { glad_glGetVertexAttribIiv(index, pname, params); }
#define glGetVertexAttribIiv glad_glGetVertexAttribIiv




export typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIUIVPROC)(GLuint index, GLenum pname, GLuint* params);
export GLAPI PFNGLGETVERTEXATTRIBIUIVPROC glad_glGetVertexAttribIuiv;
export inline void glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint* params) { glad_glGetVertexAttribIuiv(index, pname, params); }
#define glGetVertexAttribIuiv glad_glGetVertexAttribIuiv




export typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IPROC)(GLuint index, GLint x);
export GLAPI PFNGLVERTEXATTRIBI1IPROC glad_glVertexAttribI1i;
export inline void glVertexAttribI1i(GLuint index, GLint x) { glad_glVertexAttribI1i(index, x); }
#define glVertexAttribI1i glad_glVertexAttribI1i




export typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IPROC)(GLuint index, GLint x, GLint y);
export GLAPI PFNGLVERTEXATTRIBI2IPROC glad_glVertexAttribI2i;
export inline void glVertexAttribI2i(GLuint index, GLint x, GLint y) { glad_glVertexAttribI2i(index, x, y); }
#define glVertexAttribI2i glad_glVertexAttribI2i




export typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IPROC)(GLuint index, GLint x, GLint y, GLint z);
export GLAPI PFNGLVERTEXATTRIBI3IPROC glad_glVertexAttribI3i;
export inline void glVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z) { glad_glVertexAttribI3i(index, x, y, z); }
#define glVertexAttribI3i glad_glVertexAttribI3i




export typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IPROC)(GLuint index, GLint x, GLint y, GLint z, GLint w);
export GLAPI PFNGLVERTEXATTRIBI4IPROC glad_glVertexAttribI4i;
export inline void glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w) { glad_glVertexAttribI4i(index, x, y, z, w); }
#define glVertexAttribI4i glad_glVertexAttribI4i




export typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIPROC)(GLuint index, GLuint x);
export GLAPI PFNGLVERTEXATTRIBI1UIPROC glad_glVertexAttribI1ui;
export inline void glVertexAttribI1ui(GLuint index, GLuint x) { glad_glVertexAttribI1ui(index, x); }
#define glVertexAttribI1ui glad_glVertexAttribI1ui




export typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIPROC)(GLuint index, GLuint x, GLuint y);
export GLAPI PFNGLVERTEXATTRIBI2UIPROC glad_glVertexAttribI2ui;
export inline void glVertexAttribI2ui(GLuint index, GLuint x, GLuint y) { glad_glVertexAttribI2ui(index, x, y); }
#define glVertexAttribI2ui glad_glVertexAttribI2ui




export typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIPROC)(GLuint index, GLuint x, GLuint y, GLuint z);
export GLAPI PFNGLVERTEXATTRIBI3UIPROC glad_glVertexAttribI3ui;
export inline void glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z) { glad_glVertexAttribI3ui(index, x, y, z); }
#define glVertexAttribI3ui glad_glVertexAttribI3ui




export typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIPROC)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
export GLAPI PFNGLVERTEXATTRIBI4UIPROC glad_glVertexAttribI4ui;
export inline void glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) { glad_glVertexAttribI4ui(index, x, y, z, w); }
#define glVertexAttribI4ui glad_glVertexAttribI4ui




export typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IVPROC)(GLuint index, const GLint* v);
export GLAPI PFNGLVERTEXATTRIBI1IVPROC glad_glVertexAttribI1iv;
export inline void glVertexAttribI1iv(GLuint index, const GLint* v) { glad_glVertexAttribI1iv(index, v); }
#define glVertexAttribI1iv glad_glVertexAttribI1iv




export typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IVPROC)(GLuint index, const GLint* v);
export GLAPI PFNGLVERTEXATTRIBI2IVPROC glad_glVertexAttribI2iv;
export inline void glVertexAttribI2iv(GLuint index, const GLint* v) { glad_glVertexAttribI2iv(index, v); }
#define glVertexAttribI2iv glad_glVertexAttribI2iv




export typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IVPROC)(GLuint index, const GLint* v);
export GLAPI PFNGLVERTEXATTRIBI3IVPROC glad_glVertexAttribI3iv;
export inline void glVertexAttribI3iv(GLuint index, const GLint* v) { glad_glVertexAttribI3iv(index, v); }
#define glVertexAttribI3iv glad_glVertexAttribI3iv




export typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IVPROC)(GLuint index, const GLint* v);
export GLAPI PFNGLVERTEXATTRIBI4IVPROC glad_glVertexAttribI4iv;
export inline void glVertexAttribI4iv(GLuint index, const GLint* v) { glad_glVertexAttribI4iv(index, v); }
#define glVertexAttribI4iv glad_glVertexAttribI4iv




export typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIVPROC)(GLuint index, const GLuint* v);
export GLAPI PFNGLVERTEXATTRIBI1UIVPROC glad_glVertexAttribI1uiv;
export inline void glVertexAttribI1uiv(GLuint index, const GLuint* v) { glad_glVertexAttribI1uiv(index, v); }
#define glVertexAttribI1uiv glad_glVertexAttribI1uiv




export typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIVPROC)(GLuint index, const GLuint* v);
export GLAPI PFNGLVERTEXATTRIBI2UIVPROC glad_glVertexAttribI2uiv;
export inline void glVertexAttribI2uiv(GLuint index, const GLuint* v) { glad_glVertexAttribI2uiv(index, v); }
#define glVertexAttribI2uiv glad_glVertexAttribI2uiv




export typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIVPROC)(GLuint index, const GLuint* v);
export GLAPI PFNGLVERTEXATTRIBI3UIVPROC glad_glVertexAttribI3uiv;
export inline void glVertexAttribI3uiv(GLuint index, const GLuint* v) { glad_glVertexAttribI3uiv(index, v); }
#define glVertexAttribI3uiv glad_glVertexAttribI3uiv




export typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIVPROC)(GLuint index, const GLuint* v);
export GLAPI PFNGLVERTEXATTRIBI4UIVPROC glad_glVertexAttribI4uiv;
export inline void glVertexAttribI4uiv(GLuint index, const GLuint* v) { glad_glVertexAttribI4uiv(index, v); }
#define glVertexAttribI4uiv glad_glVertexAttribI4uiv




export typedef void (APIENTRYP PFNGLVERTEXATTRIBI4BVPROC)(GLuint index, const GLbyte* v);
export GLAPI PFNGLVERTEXATTRIBI4BVPROC glad_glVertexAttribI4bv;
export inline void glVertexAttribI4bv(GLuint index, const GLbyte* v) { glad_glVertexAttribI4bv(index, v); }
#define glVertexAttribI4bv glad_glVertexAttribI4bv




export typedef void (APIENTRYP PFNGLVERTEXATTRIBI4SVPROC)(GLuint index, const GLshort* v);
export GLAPI PFNGLVERTEXATTRIBI4SVPROC glad_glVertexAttribI4sv;
export inline void glVertexAttribI4sv(GLuint index, const GLshort* v) { glad_glVertexAttribI4sv(index, v); }
#define glVertexAttribI4sv glad_glVertexAttribI4sv




export typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UBVPROC)(GLuint index, const GLubyte* v);
export GLAPI PFNGLVERTEXATTRIBI4UBVPROC glad_glVertexAttribI4ubv;
export inline void glVertexAttribI4ubv(GLuint index, const GLubyte* v) { glad_glVertexAttribI4ubv(index, v); }
#define glVertexAttribI4ubv glad_glVertexAttribI4ubv




export typedef void (APIENTRYP PFNGLVERTEXATTRIBI4USVPROC)(GLuint index, const GLushort* v);
export GLAPI PFNGLVERTEXATTRIBI4USVPROC glad_glVertexAttribI4usv;
export inline void glVertexAttribI4usv(GLuint index, const GLushort* v) { glad_glVertexAttribI4usv(index, v); }
#define glVertexAttribI4usv glad_glVertexAttribI4usv




export typedef void (APIENTRYP PFNGLGETUNIFORMUIVPROC)(GLuint program, GLint location, GLuint* params);
export GLAPI PFNGLGETUNIFORMUIVPROC glad_glGetUniformuiv;
export inline void glGetUniformuiv(GLuint program, GLint location, GLuint* params) { glad_glGetUniformuiv(program, location, params); }
#define glGetUniformuiv glad_glGetUniformuiv




export typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONPROC)(GLuint program, GLuint color, const GLchar* name);
export GLAPI PFNGLBINDFRAGDATALOCATIONPROC glad_glBindFragDataLocation;
export inline void glBindFragDataLocation(GLuint program, GLuint color, const GLchar* name) { glad_glBindFragDataLocation(program, color, name); }
#define glBindFragDataLocation glad_glBindFragDataLocation




export typedef GLint(APIENTRYP PFNGLGETFRAGDATALOCATIONPROC)(GLuint program, const GLchar* name);
export GLAPI PFNGLGETFRAGDATALOCATIONPROC glad_glGetFragDataLocation;
export inline GLint glGetFragDataLocation(GLuint program, const GLchar* name) { return glad_glGetFragDataLocation(program, name); }
#define glGetFragDataLocation glad_glGetFragDataLocation




export typedef void (APIENTRYP PFNGLUNIFORM1UIPROC)(GLint location, GLuint v0);
export GLAPI PFNGLUNIFORM1UIPROC glad_glUniform1ui;
export inline void glUniform1ui(GLint location, GLuint v0) { glad_glUniform1ui(location, v0); }
#define glUniform1ui glad_glUniform1ui




export typedef void (APIENTRYP PFNGLUNIFORM2UIPROC)(GLint location, GLuint v0, GLuint v1);
export GLAPI PFNGLUNIFORM2UIPROC glad_glUniform2ui;
export inline void glUniform2ui(GLint location, GLuint v0, GLuint v1) { glad_glUniform2ui(location, v0, v1); }
#define glUniform2ui glad_glUniform2ui




export typedef void (APIENTRYP PFNGLUNIFORM3UIPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2);
export GLAPI PFNGLUNIFORM3UIPROC glad_glUniform3ui;
export inline void glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2) { glad_glUniform3ui(location, v0, v1, v2); }
#define glUniform3ui glad_glUniform3ui




export typedef void (APIENTRYP PFNGLUNIFORM4UIPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
export GLAPI PFNGLUNIFORM4UIPROC glad_glUniform4ui;
export inline void glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) { glad_glUniform4ui(location, v0, v1, v2, v3); }
#define glUniform4ui glad_glUniform4ui




export typedef void (APIENTRYP PFNGLUNIFORM1UIVPROC)(GLint location, GLsizei count, const GLuint* value);
export GLAPI PFNGLUNIFORM1UIVPROC glad_glUniform1uiv;
export inline void glUniform1uiv(GLint location, GLsizei count, const GLuint* value) { glad_glUniform1uiv(location, count, value); }
#define glUniform1uiv glad_glUniform1uiv




export typedef void (APIENTRYP PFNGLUNIFORM2UIVPROC)(GLint location, GLsizei count, const GLuint* value);
export GLAPI PFNGLUNIFORM2UIVPROC glad_glUniform2uiv;
export inline void glUniform2uiv(GLint location, GLsizei count, const GLuint* value) { glad_glUniform2uiv(location, count, value); }
#define glUniform2uiv glad_glUniform2uiv




export typedef void (APIENTRYP PFNGLUNIFORM3UIVPROC)(GLint location, GLsizei count, const GLuint* value);
export GLAPI PFNGLUNIFORM3UIVPROC glad_glUniform3uiv;
export inline void glUniform3uiv(GLint location, GLsizei count, const GLuint* value) { glad_glUniform3uiv(location, count, value); }
#define glUniform3uiv glad_glUniform3uiv




export typedef void (APIENTRYP PFNGLUNIFORM4UIVPROC)(GLint location, GLsizei count, const GLuint* value);
export GLAPI PFNGLUNIFORM4UIVPROC glad_glUniform4uiv;
export inline void glUniform4uiv(GLint location, GLsizei count, const GLuint* value) { glad_glUniform4uiv(location, count, value); }
#define glUniform4uiv glad_glUniform4uiv




export typedef void (APIENTRYP PFNGLTEXPARAMETERIIVPROC)(GLenum target, GLenum pname, const GLint* params);
export GLAPI PFNGLTEXPARAMETERIIVPROC glad_glTexParameterIiv;
export inline void glTexParameterIiv(GLenum target, GLenum pname, const GLint* params) { glad_glTexParameterIiv(target, pname, params); }
#define glTexParameterIiv glad_glTexParameterIiv




export typedef void (APIENTRYP PFNGLTEXPARAMETERIUIVPROC)(GLenum target, GLenum pname, const GLuint* params);
export GLAPI PFNGLTEXPARAMETERIUIVPROC glad_glTexParameterIuiv;
export inline void glTexParameterIuiv(GLenum target, GLenum pname, const GLuint* params) { glad_glTexParameterIuiv(target, pname, params); }
#define glTexParameterIuiv glad_glTexParameterIuiv




export typedef void (APIENTRYP PFNGLGETTEXPARAMETERIIVPROC)(GLenum target, GLenum pname, GLint* params);
export GLAPI PFNGLGETTEXPARAMETERIIVPROC glad_glGetTexParameterIiv;
export inline void glGetTexParameterIiv(GLenum target, GLenum pname, GLint* params) { glad_glGetTexParameterIiv(target, pname, params); }
#define glGetTexParameterIiv glad_glGetTexParameterIiv




export typedef void (APIENTRYP PFNGLGETTEXPARAMETERIUIVPROC)(GLenum target, GLenum pname, GLuint* params);
export GLAPI PFNGLGETTEXPARAMETERIUIVPROC glad_glGetTexParameterIuiv;
export inline void glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint* params) { glad_glGetTexParameterIuiv(target, pname, params); }
#define glGetTexParameterIuiv glad_glGetTexParameterIuiv




export typedef void (APIENTRYP PFNGLCLEARBUFFERIVPROC)(GLenum buffer, GLint drawbuffer, const GLint* value);
export GLAPI PFNGLCLEARBUFFERIVPROC glad_glClearBufferiv;
export inline void glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint* value) { glad_glClearBufferiv(buffer, drawbuffer, value); }
#define glClearBufferiv glad_glClearBufferiv




export typedef void (APIENTRYP PFNGLCLEARBUFFERUIVPROC)(GLenum buffer, GLint drawbuffer, const GLuint* value);
export GLAPI PFNGLCLEARBUFFERUIVPROC glad_glClearBufferuiv;
export inline void glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint* value) { glad_glClearBufferuiv(buffer, drawbuffer, value); }
#define glClearBufferuiv glad_glClearBufferuiv




export typedef void (APIENTRYP PFNGLCLEARBUFFERFVPROC)(GLenum buffer, GLint drawbuffer, const GLfloat* value);
export GLAPI PFNGLCLEARBUFFERFVPROC glad_glClearBufferfv;
export inline void glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat* value) { glad_glClearBufferfv(buffer, drawbuffer, value); }
#define glClearBufferfv glad_glClearBufferfv




export typedef void (APIENTRYP PFNGLCLEARBUFFERFIPROC)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
export GLAPI PFNGLCLEARBUFFERFIPROC glad_glClearBufferfi;
export inline void glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) { glad_glClearBufferfi(buffer, drawbuffer, depth, stencil); }
#define glClearBufferfi glad_glClearBufferfi




export typedef const GLubyte* (APIENTRYP PFNGLGETSTRINGIPROC)(GLenum name, GLuint index);
export GLAPI PFNGLGETSTRINGIPROC glad_glGetStringi;
export inline const GLubyte* glGetStringi(GLenum name, GLuint index) { return glad_glGetStringi(name, index); }
#define glGetStringi glad_glGetStringi




export typedef GLboolean(APIENTRYP PFNGLISRENDERBUFFERPROC)(GLuint renderbuffer);
export GLAPI PFNGLISRENDERBUFFERPROC glad_glIsRenderbuffer;
export inline GLboolean glIsRenderbuffer(GLuint renderbuffer) { return glad_glIsRenderbuffer(renderbuffer); }
#define glIsRenderbuffer glad_glIsRenderbuffer




export typedef void (APIENTRYP PFNGLBINDRENDERBUFFERPROC)(GLenum target, GLuint renderbuffer);
export GLAPI PFNGLBINDRENDERBUFFERPROC glad_glBindRenderbuffer;
export inline void glBindRenderbuffer(GLenum target, GLuint renderbuffer) { glad_glBindRenderbuffer(target, renderbuffer); }
#define glBindRenderbuffer glad_glBindRenderbuffer




export typedef void (APIENTRYP PFNGLDELETERENDERBUFFERSPROC)(GLsizei n, const GLuint* renderbuffers);
export GLAPI PFNGLDELETERENDERBUFFERSPROC glad_glDeleteRenderbuffers;
export inline void glDeleteRenderbuffers(GLsizei n, const GLuint* renderbuffers) { glad_glDeleteRenderbuffers(n, renderbuffers); }
#define glDeleteRenderbuffers glad_glDeleteRenderbuffers




export typedef void (APIENTRYP PFNGLGENRENDERBUFFERSPROC)(GLsizei n, GLuint* renderbuffers);
export GLAPI PFNGLGENRENDERBUFFERSPROC glad_glGenRenderbuffers;
export inline void glGenRenderbuffers(GLsizei n, GLuint* renderbuffers) { glad_glGenRenderbuffers(n, renderbuffers); }
#define glGenRenderbuffers glad_glGenRenderbuffers




export typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
export GLAPI PFNGLRENDERBUFFERSTORAGEPROC glad_glRenderbufferStorage;
export inline void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) { glad_glRenderbufferStorage(target, internalformat, width, height); }
#define glRenderbufferStorage glad_glRenderbufferStorage




export typedef void (APIENTRYP PFNGLGETRENDERBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint* params);
export GLAPI PFNGLGETRENDERBUFFERPARAMETERIVPROC glad_glGetRenderbufferParameteriv;
export inline void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint* params) { glad_glGetRenderbufferParameteriv(target, pname, params); }
#define glGetRenderbufferParameteriv glad_glGetRenderbufferParameteriv




export typedef GLboolean(APIENTRYP PFNGLISFRAMEBUFFERPROC)(GLuint framebuffer);
export GLAPI PFNGLISFRAMEBUFFERPROC glad_glIsFramebuffer;
export inline GLboolean glIsFramebuffer(GLuint framebuffer) { return glad_glIsFramebuffer(framebuffer); }
#define glIsFramebuffer glad_glIsFramebuffer




export typedef void (APIENTRYP PFNGLBINDFRAMEBUFFERPROC)(GLenum target, GLuint framebuffer);
export GLAPI PFNGLBINDFRAMEBUFFERPROC glad_glBindFramebuffer;
export inline void glBindFramebuffer(GLenum target, GLuint framebuffer) { glad_glBindFramebuffer(target, framebuffer); }
#define glBindFramebuffer glad_glBindFramebuffer




export typedef void (APIENTRYP PFNGLDELETEFRAMEBUFFERSPROC)(GLsizei n, const GLuint* framebuffers);
export GLAPI PFNGLDELETEFRAMEBUFFERSPROC glad_glDeleteFramebuffers;
export inline void glDeleteFramebuffers(GLsizei n, const GLuint* framebuffers) { glad_glDeleteFramebuffers(n, framebuffers); }
#define glDeleteFramebuffers glad_glDeleteFramebuffers




export typedef void (APIENTRYP PFNGLGENFRAMEBUFFERSPROC)(GLsizei n, GLuint* framebuffers);
export GLAPI PFNGLGENFRAMEBUFFERSPROC glad_glGenFramebuffers;
export inline void glGenFramebuffers(GLsizei n, GLuint* framebuffers) { glad_glGenFramebuffers(n, framebuffers); }
#define glGenFramebuffers glad_glGenFramebuffers




export typedef GLenum(APIENTRYP PFNGLCHECKFRAMEBUFFERSTATUSPROC)(GLenum target);
export GLAPI PFNGLCHECKFRAMEBUFFERSTATUSPROC glad_glCheckFramebufferStatus;
export inline GLenum glCheckFramebufferStatus(GLenum target) { return glad_glCheckFramebufferStatus(target); }
#define glCheckFramebufferStatus glad_glCheckFramebufferStatus




export typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE1DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
export GLAPI PFNGLFRAMEBUFFERTEXTURE1DPROC glad_glFramebufferTexture1D;
export inline void glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) { glad_glFramebufferTexture1D(target, attachment, textarget, texture, level); }
#define glFramebufferTexture1D glad_glFramebufferTexture1D




export typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE2DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
export GLAPI PFNGLFRAMEBUFFERTEXTURE2DPROC glad_glFramebufferTexture2D;
export inline void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) { glad_glFramebufferTexture2D(target, attachment, textarget, texture, level); }
#define glFramebufferTexture2D glad_glFramebufferTexture2D




export typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE3DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
export GLAPI PFNGLFRAMEBUFFERTEXTURE3DPROC glad_glFramebufferTexture3D;
export inline void glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) { glad_glFramebufferTexture3D(target, attachment, textarget, texture, level, zoffset); }
#define glFramebufferTexture3D glad_glFramebufferTexture3D




export typedef void (APIENTRYP PFNGLFRAMEBUFFERRENDERBUFFERPROC)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
export GLAPI PFNGLFRAMEBUFFERRENDERBUFFERPROC glad_glFramebufferRenderbuffer;
export inline void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) { glad_glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer); }
#define glFramebufferRenderbuffer glad_glFramebufferRenderbuffer




export typedef void (APIENTRYP PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLenum target, GLenum attachment, GLenum pname, GLint* params);
export GLAPI PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glad_glGetFramebufferAttachmentParameteriv;
export inline void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint* params) { glad_glGetFramebufferAttachmentParameteriv(target, attachment, pname, params); }
#define glGetFramebufferAttachmentParameteriv glad_glGetFramebufferAttachmentParameteriv




export typedef void (APIENTRYP PFNGLGENERATEMIPMAPPROC)(GLenum target);
export GLAPI PFNGLGENERATEMIPMAPPROC glad_glGenerateMipmap;
export inline void glGenerateMipmap(GLenum target) { glad_glGenerateMipmap(target); }
#define glGenerateMipmap glad_glGenerateMipmap




export typedef void (APIENTRYP PFNGLBLITFRAMEBUFFERPROC)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
export GLAPI PFNGLBLITFRAMEBUFFERPROC glad_glBlitFramebuffer;
export inline void glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) { glad_glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter); }
#define glBlitFramebuffer glad_glBlitFramebuffer




export typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
export GLAPI PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glad_glRenderbufferStorageMultisample;
export inline void glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) { glad_glRenderbufferStorageMultisample(target, samples, internalformat, width, height); }
#define glRenderbufferStorageMultisample glad_glRenderbufferStorageMultisample




export typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURELAYERPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
export GLAPI PFNGLFRAMEBUFFERTEXTURELAYERPROC glad_glFramebufferTextureLayer;
export inline void glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) { glad_glFramebufferTextureLayer(target, attachment, texture, level, layer); }
#define glFramebufferTextureLayer glad_glFramebufferTextureLayer




export typedef void* (APIENTRYP PFNGLMAPBUFFERRANGEPROC)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
export GLAPI PFNGLMAPBUFFERRANGEPROC glad_glMapBufferRange;
export inline void* glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) { return glad_glMapBufferRange(target, offset, length, access); }
#define glMapBufferRange glad_glMapBufferRange




export typedef void (APIENTRYP PFNGLFLUSHMAPPEDBUFFERRANGEPROC)(GLenum target, GLintptr offset, GLsizeiptr length);
export GLAPI PFNGLFLUSHMAPPEDBUFFERRANGEPROC glad_glFlushMappedBufferRange;
export inline void glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length) { glad_glFlushMappedBufferRange(target, offset, length); }
#define glFlushMappedBufferRange glad_glFlushMappedBufferRange




export typedef void (APIENTRYP PFNGLBINDVERTEXARRAYPROC)(GLuint array);
export GLAPI PFNGLBINDVERTEXARRAYPROC glad_glBindVertexArray;
export inline void glBindVertexArray(GLuint array) { glad_glBindVertexArray(array); }
#define glBindVertexArray glad_glBindVertexArray




export typedef void (APIENTRYP PFNGLDELETEVERTEXARRAYSPROC)(GLsizei n, const GLuint* arrays);
export GLAPI PFNGLDELETEVERTEXARRAYSPROC glad_glDeleteVertexArrays;
export inline void glDeleteVertexArrays(GLsizei n, const GLuint* arrays) { glad_glDeleteVertexArrays(n, arrays); }
#define glDeleteVertexArrays glad_glDeleteVertexArrays




export typedef void (APIENTRYP PFNGLGENVERTEXARRAYSPROC)(GLsizei n, GLuint* arrays);
export GLAPI PFNGLGENVERTEXARRAYSPROC glad_glGenVertexArrays;
export inline void glGenVertexArrays(GLsizei n, GLuint* arrays) { glad_glGenVertexArrays(n, arrays); }
#define glGenVertexArrays glad_glGenVertexArrays




export typedef GLboolean(APIENTRYP PFNGLISVERTEXARRAYPROC)(GLuint array);
export GLAPI PFNGLISVERTEXARRAYPROC glad_glIsVertexArray;
export inline GLboolean glIsVertexArray(GLuint array) { return glad_glIsVertexArray(array); }
#define glIsVertexArray glad_glIsVertexArray




#endif
#pragma endregion
#pragma region GL_VERSION_3_1
#ifndef GL_VERSION_3_1
#define GL_VERSION_3_1 1
export GLAPI int GLAD_GL_VERSION_3_1;



export typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDPROC)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
export GLAPI PFNGLDRAWARRAYSINSTANCEDPROC glad_glDrawArraysInstanced;
export inline void glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount) { glad_glDrawArraysInstanced(mode, first, count, instancecount); }
#define glDrawArraysInstanced glad_glDrawArraysInstanced



export typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDPROC)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount);
export GLAPI PFNGLDRAWELEMENTSINSTANCEDPROC glad_glDrawElementsInstanced;
export inline void glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount) { glad_glDrawElementsInstanced(mode, count, type, indices, instancecount); }
#define glDrawElementsInstanced glad_glDrawElementsInstanced



export typedef void (APIENTRYP PFNGLTEXBUFFERPROC)(GLenum target, GLenum internalformat, GLuint buffer);
export GLAPI PFNGLTEXBUFFERPROC glad_glTexBuffer;
export inline void glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer) { glad_glTexBuffer(target, internalformat, buffer); }
#define glTexBuffer glad_glTexBuffer



export typedef void (APIENTRYP PFNGLPRIMITIVERESTARTINDEXPROC)(GLuint index);
export GLAPI PFNGLPRIMITIVERESTARTINDEXPROC glad_glPrimitiveRestartIndex;
export inline void glPrimitiveRestartIndex(GLuint index) { glad_glPrimitiveRestartIndex(index); }
#define glPrimitiveRestartIndex glad_glPrimitiveRestartIndex



export typedef void (APIENTRYP PFNGLCOPYBUFFERSUBDATAPROC)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
export GLAPI PFNGLCOPYBUFFERSUBDATAPROC glad_glCopyBufferSubData;
export inline void glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) { glad_glCopyBufferSubData(readTarget, writeTarget, readOffset, writeOffset, size); }
#define glCopyBufferSubData glad_glCopyBufferSubData



export typedef void (APIENTRYP PFNGLGETUNIFORMINDICESPROC)(GLuint program, GLsizei uniformCount, const GLchar* const* uniformNames, GLuint* uniformIndices);
export GLAPI PFNGLGETUNIFORMINDICESPROC glad_glGetUniformIndices;
export inline void glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar* const* uniformNames, GLuint* uniformIndices) { glad_glGetUniformIndices(program, uniformCount, uniformNames, uniformIndices); }
#define glGetUniformIndices glad_glGetUniformIndices



export typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMSIVPROC)(GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params);
export GLAPI PFNGLGETACTIVEUNIFORMSIVPROC glad_glGetActiveUniformsiv;
export inline void glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params) { glad_glGetActiveUniformsiv(program, uniformCount, uniformIndices, pname, params); }
#define glGetActiveUniformsiv glad_glGetActiveUniformsiv



export typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMNAMEPROC)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName);
export GLAPI PFNGLGETACTIVEUNIFORMNAMEPROC glad_glGetActiveUniformName;
export inline void glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName) { glad_glGetActiveUniformName(program, uniformIndex, bufSize, length, uniformName); }
#define glGetActiveUniformName glad_glGetActiveUniformName



export typedef GLuint(APIENTRYP PFNGLGETUNIFORMBLOCKINDEXPROC)(GLuint program, const GLchar* uniformBlockName);
export GLAPI PFNGLGETUNIFORMBLOCKINDEXPROC glad_glGetUniformBlockIndex;
export inline GLuint glGetUniformBlockIndex(GLuint program, const GLchar* uniformBlockName) { return glad_glGetUniformBlockIndex(program, uniformBlockName); }
#define glGetUniformBlockIndex glad_glGetUniformBlockIndex



export typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKIVPROC)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params);
export GLAPI PFNGLGETACTIVEUNIFORMBLOCKIVPROC glad_glGetActiveUniformBlockiv;
export inline void glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params) { glad_glGetActiveUniformBlockiv(program, uniformBlockIndex, pname, params); }
#define glGetActiveUniformBlockiv glad_glGetActiveUniformBlockiv



export typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName);
export GLAPI PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glad_glGetActiveUniformBlockName;
export inline void glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName) { glad_glGetActiveUniformBlockName(program, uniformBlockIndex, bufSize, length, uniformBlockName); }
#define glGetActiveUniformBlockName glad_glGetActiveUniformBlockName



export typedef void (APIENTRYP PFNGLUNIFORMBLOCKBINDINGPROC)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
export GLAPI PFNGLUNIFORMBLOCKBINDINGPROC glad_glUniformBlockBinding;
export inline void glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) { glad_glUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding); }
#define glUniformBlockBinding glad_glUniformBlockBinding



#endif
#pragma endregion
#pragma region GL_VERSION_3_2
#ifndef GL_VERSION_3_2
#define GL_VERSION_3_2 1
export GLAPI int GLAD_GL_VERSION_3_2;



export typedef void (APIENTRYP PFNGLDRAWELEMENTSBASEVERTEXPROC)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLint basevertex);
export GLAPI PFNGLDRAWELEMENTSBASEVERTEXPROC glad_glDrawElementsBaseVertex;
export inline void glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void* indices, GLint basevertex) { glad_glDrawElementsBaseVertex(mode, count, type, indices, basevertex); }
#define glDrawElementsBaseVertex glad_glDrawElementsBaseVertex



export typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices, GLint basevertex);
export GLAPI PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glad_glDrawRangeElementsBaseVertex;
export inline void glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices, GLint basevertex) { glad_glDrawRangeElementsBaseVertex(mode, start, end, count, type, indices, basevertex); }
#define glDrawRangeElementsBaseVertex glad_glDrawRangeElementsBaseVertex



export typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex);
export GLAPI PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glad_glDrawElementsInstancedBaseVertex;
export inline void glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex) { glad_glDrawElementsInstancedBaseVertex(mode, count, type, indices, instancecount, basevertex); }
#define glDrawElementsInstancedBaseVertex glad_glDrawElementsInstancedBaseVertex



export typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount, const GLint* basevertex);
export GLAPI PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glad_glMultiDrawElementsBaseVertex;
export inline void glMultiDrawElementsBaseVertex(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount, const GLint* basevertex) { glad_glMultiDrawElementsBaseVertex(mode, count, type, indices, drawcount, basevertex); }
#define glMultiDrawElementsBaseVertex glad_glMultiDrawElementsBaseVertex



export typedef void (APIENTRYP PFNGLPROVOKINGVERTEXPROC)(GLenum mode);
export GLAPI PFNGLPROVOKINGVERTEXPROC glad_glProvokingVertex;
export inline void glProvokingVertex(GLenum mode) { glad_glProvokingVertex(mode); }
#define glProvokingVertex glad_glProvokingVertex



export typedef GLsync(APIENTRYP PFNGLFENCESYNCPROC)(GLenum condition, GLbitfield flags);
export GLAPI PFNGLFENCESYNCPROC glad_glFenceSync;
export inline GLsync glFenceSync(GLenum condition, GLbitfield flags) { return glad_glFenceSync(condition, flags); }
#define glFenceSync glad_glFenceSync



export typedef GLboolean(APIENTRYP PFNGLISSYNCPROC)(GLsync sync);
export GLAPI PFNGLISSYNCPROC glad_glIsSync;
export inline GLboolean glIsSync(GLsync sync) { return glad_glIsSync(sync); }
#define glIsSync glad_glIsSync



export typedef void (APIENTRYP PFNGLDELETESYNCPROC)(GLsync sync);
export GLAPI PFNGLDELETESYNCPROC glad_glDeleteSync;
export inline void glDeleteSync(GLsync sync) { glad_glDeleteSync(sync); }
#define glDeleteSync glad_glDeleteSync



export typedef GLenum(APIENTRYP PFNGLCLIENTWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
export GLAPI PFNGLCLIENTWAITSYNCPROC glad_glClientWaitSync;
export inline GLenum glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) { return glad_glClientWaitSync(sync, flags, timeout); }
#define glClientWaitSync glad_glClientWaitSync



export typedef void (APIENTRYP PFNGLWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
export GLAPI PFNGLWAITSYNCPROC glad_glWaitSync;
export inline void glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) { glad_glWaitSync(sync, flags, timeout); }
#define glWaitSync glad_glWaitSync



export typedef void (APIENTRYP PFNGLGETINTEGER64VPROC)(GLenum pname, GLint64* data);
export GLAPI PFNGLGETINTEGER64VPROC glad_glGetInteger64v;
export inline void glGetInteger64v(GLenum pname, GLint64* data) { glad_glGetInteger64v(pname, data); }
#define glGetInteger64v glad_glGetInteger64v



export typedef void (APIENTRYP PFNGLGETSYNCIVPROC)(GLsync sync, GLenum pname, GLsizei count, GLsizei* length, GLint* values);
export GLAPI PFNGLGETSYNCIVPROC glad_glGetSynciv;
export inline void glGetSynciv(GLsync sync, GLenum pname, GLsizei count, GLsizei* length, GLint* values) { glad_glGetSynciv(sync, pname, count, length, values); }
#define glGetSynciv glad_glGetSynciv



export typedef void (APIENTRYP PFNGLGETINTEGER64I_VPROC)(GLenum target, GLuint index, GLint64* data);
export GLAPI PFNGLGETINTEGER64I_VPROC glad_glGetInteger64i_v;
export inline void glGetInteger64i_v(GLenum target, GLuint index, GLint64* data) { glad_glGetInteger64i_v(target, index, data); }
#define glGetInteger64i_v glad_glGetInteger64i_v



export typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERI64VPROC)(GLenum target, GLenum pname, GLint64* params);
export GLAPI PFNGLGETBUFFERPARAMETERI64VPROC glad_glGetBufferParameteri64v;
export inline void glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64* params) { glad_glGetBufferParameteri64v(target, pname, params); }
#define glGetBufferParameteri64v glad_glGetBufferParameteri64v



export typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level);
export GLAPI PFNGLFRAMEBUFFERTEXTUREPROC glad_glFramebufferTexture;
export inline void glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level) { glad_glFramebufferTexture(target, attachment, texture, level); }
#define glFramebufferTexture glad_glFramebufferTexture



export typedef void (APIENTRYP PFNGLTEXIMAGE2DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
export GLAPI PFNGLTEXIMAGE2DMULTISAMPLEPROC glad_glTexImage2DMultisample;
export inline void glTexImage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) { glad_glTexImage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations); }
#define glTexImage2DMultisample glad_glTexImage2DMultisample



export typedef void (APIENTRYP PFNGLTEXIMAGE3DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
export GLAPI PFNGLTEXIMAGE3DMULTISAMPLEPROC glad_glTexImage3DMultisample;
export inline void glTexImage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) { glad_glTexImage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations); }
#define glTexImage3DMultisample glad_glTexImage3DMultisample



export typedef void (APIENTRYP PFNGLGETMULTISAMPLEFVPROC)(GLenum pname, GLuint index, GLfloat* val);
export GLAPI PFNGLGETMULTISAMPLEFVPROC glad_glGetMultisamplefv;
export inline void glGetMultisamplefv(GLenum pname, GLuint index, GLfloat* val) { glad_glGetMultisamplefv(pname, index, val); }
#define glGetMultisamplefv glad_glGetMultisamplefv



export typedef void (APIENTRYP PFNGLSAMPLEMASKIPROC)(GLuint maskNumber, GLbitfield mask);
export GLAPI PFNGLSAMPLEMASKIPROC glad_glSampleMaski;
export inline void glSampleMaski(GLuint maskNumber, GLbitfield mask) { glad_glSampleMaski(maskNumber, mask); }
#define glSampleMaski glad_glSampleMaski



#endif
#pragma endregion
#pragma region GL_VERSION_3_3
#ifndef GL_VERSION_3_3
#define GL_VERSION_3_3 1
export GLAPI int GLAD_GL_VERSION_3_3;



export typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)(GLuint program, GLuint colorNumber, GLuint index, const GLchar* name);
export GLAPI PFNGLBINDFRAGDATALOCATIONINDEXEDPROC glad_glBindFragDataLocationIndexed;
export inline void glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar* name) { glad_glBindFragDataLocationIndexed(program, colorNumber, index, name); }
#define glBindFragDataLocationIndexed glad_glBindFragDataLocationIndexed



export typedef GLint(APIENTRYP PFNGLGETFRAGDATAINDEXPROC)(GLuint program, const GLchar* name);
export GLAPI PFNGLGETFRAGDATAINDEXPROC glad_glGetFragDataIndex;
export inline GLint glGetFragDataIndex(GLuint program, const GLchar* name) { return glad_glGetFragDataIndex(program, name); }
#define glGetFragDataIndex glad_glGetFragDataIndex



export typedef void (APIENTRYP PFNGLGENSAMPLERSPROC)(GLsizei count, GLuint* samplers);
export GLAPI PFNGLGENSAMPLERSPROC glad_glGenSamplers;
export inline void glGenSamplers(GLsizei count, GLuint* samplers) { glad_glGenSamplers(count, samplers); }
#define glGenSamplers glad_glGenSamplers



export typedef void (APIENTRYP PFNGLDELETESAMPLERSPROC)(GLsizei count, const GLuint* samplers);
export GLAPI PFNGLDELETESAMPLERSPROC glad_glDeleteSamplers;
export inline void glDeleteSamplers(GLsizei count, const GLuint* samplers) { glad_glDeleteSamplers(count, samplers); }
#define glDeleteSamplers glad_glDeleteSamplers



export typedef GLboolean(APIENTRYP PFNGLISSAMPLERPROC)(GLuint sampler);
export GLAPI PFNGLISSAMPLERPROC glad_glIsSampler;
export inline GLboolean glIsSampler(GLuint sampler) { return glad_glIsSampler(sampler); }
#define glIsSampler glad_glIsSampler



export typedef void (APIENTRYP PFNGLBINDSAMPLERPROC)(GLuint unit, GLuint sampler);
export GLAPI PFNGLBINDSAMPLERPROC glad_glBindSampler;
export inline void glBindSampler(GLuint unit, GLuint sampler) { glad_glBindSampler(unit, sampler); }
#define glBindSampler glad_glBindSampler



export typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIPROC)(GLuint sampler, GLenum pname, GLint param);
export GLAPI PFNGLSAMPLERPARAMETERIPROC glad_glSamplerParameteri;
export inline void glSamplerParameteri(GLuint sampler, GLenum pname, GLint param) { glad_glSamplerParameteri(sampler, pname, param); }
#define glSamplerParameteri glad_glSamplerParameteri



export typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIVPROC)(GLuint sampler, GLenum pname, const GLint* param);
export GLAPI PFNGLSAMPLERPARAMETERIVPROC glad_glSamplerParameteriv;
export inline void glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint* param) { glad_glSamplerParameteriv(sampler, pname, param); }
#define glSamplerParameteriv glad_glSamplerParameteriv



export typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFPROC)(GLuint sampler, GLenum pname, GLfloat param);
export GLAPI PFNGLSAMPLERPARAMETERFPROC glad_glSamplerParameterf;
export inline void glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param) { glad_glSamplerParameterf(sampler, pname, param); }
#define glSamplerParameterf glad_glSamplerParameterf



export typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFVPROC)(GLuint sampler, GLenum pname, const GLfloat* param);
export GLAPI PFNGLSAMPLERPARAMETERFVPROC glad_glSamplerParameterfv;
export inline void glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat* param) { glad_glSamplerParameterfv(sampler, pname, param); }
#define glSamplerParameterfv glad_glSamplerParameterfv



export typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIIVPROC)(GLuint sampler, GLenum pname, const GLint* param);
export GLAPI PFNGLSAMPLERPARAMETERIIVPROC glad_glSamplerParameterIiv;
export inline void glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint* param) { glad_glSamplerParameterIiv(sampler, pname, param); }
#define glSamplerParameterIiv glad_glSamplerParameterIiv



export typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIUIVPROC)(GLuint sampler, GLenum pname, const GLuint* param);
export GLAPI PFNGLSAMPLERPARAMETERIUIVPROC glad_glSamplerParameterIuiv;
export inline void glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint* param) { glad_glSamplerParameterIuiv(sampler, pname, param); }
#define glSamplerParameterIuiv glad_glSamplerParameterIuiv



export typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIVPROC)(GLuint sampler, GLenum pname, GLint* params);
export GLAPI PFNGLGETSAMPLERPARAMETERIVPROC glad_glGetSamplerParameteriv;
export inline void glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint* params) { glad_glGetSamplerParameteriv(sampler, pname, params); }
#define glGetSamplerParameteriv glad_glGetSamplerParameteriv



export typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIIVPROC)(GLuint sampler, GLenum pname, GLint* params);
export GLAPI PFNGLGETSAMPLERPARAMETERIIVPROC glad_glGetSamplerParameterIiv;
export inline void glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint* params) { glad_glGetSamplerParameterIiv(sampler, pname, params); }
#define glGetSamplerParameterIiv glad_glGetSamplerParameterIiv



export typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERFVPROC)(GLuint sampler, GLenum pname, GLfloat* params);
export GLAPI PFNGLGETSAMPLERPARAMETERFVPROC glad_glGetSamplerParameterfv;
export inline void glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat* params) { glad_glGetSamplerParameterfv(sampler, pname, params); }
#define glGetSamplerParameterfv glad_glGetSamplerParameterfv



export typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIUIVPROC)(GLuint sampler, GLenum pname, GLuint* params);
export GLAPI PFNGLGETSAMPLERPARAMETERIUIVPROC glad_glGetSamplerParameterIuiv;
export inline void glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint* params) { glad_glGetSamplerParameterIuiv(sampler, pname, params); }
#define glGetSamplerParameterIuiv glad_glGetSamplerParameterIuiv



export typedef void (APIENTRYP PFNGLQUERYCOUNTERPROC)(GLuint id, GLenum target);
export GLAPI PFNGLQUERYCOUNTERPROC glad_glQueryCounter;
export inline void glQueryCounter(GLuint id, GLenum target) { glad_glQueryCounter(id, target); }
#define glQueryCounter glad_glQueryCounter



export typedef void (APIENTRYP PFNGLGETQUERYOBJECTI64VPROC)(GLuint id, GLenum pname, GLint64* params);
export GLAPI PFNGLGETQUERYOBJECTI64VPROC glad_glGetQueryObjecti64v;
export inline void glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64* params) { glad_glGetQueryObjecti64v(id, pname, params); }
#define glGetQueryObjecti64v glad_glGetQueryObjecti64v



export typedef void (APIENTRYP PFNGLGETQUERYOBJECTUI64VPROC)(GLuint id, GLenum pname, GLuint64* params);
export GLAPI PFNGLGETQUERYOBJECTUI64VPROC glad_glGetQueryObjectui64v;
export inline void glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64* params) { glad_glGetQueryObjectui64v(id, pname, params); }
#define glGetQueryObjectui64v glad_glGetQueryObjectui64v



export typedef void (APIENTRYP PFNGLVERTEXATTRIBDIVISORPROC)(GLuint index, GLuint divisor);
export GLAPI PFNGLVERTEXATTRIBDIVISORPROC glad_glVertexAttribDivisor;
export inline void glVertexAttribDivisor(GLuint index, GLuint divisor) { glad_glVertexAttribDivisor(index, divisor); }
#define glVertexAttribDivisor glad_glVertexAttribDivisor



export typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
export GLAPI PFNGLVERTEXATTRIBP1UIPROC glad_glVertexAttribP1ui;
export inline void glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { glad_glVertexAttribP1ui(index, type, normalized, value); }
#define glVertexAttribP1ui glad_glVertexAttribP1ui



export typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
export GLAPI PFNGLVERTEXATTRIBP1UIVPROC glad_glVertexAttribP1uiv;
export inline void glVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) { glad_glVertexAttribP1uiv(index, type, normalized, value); }
#define glVertexAttribP1uiv glad_glVertexAttribP1uiv



export typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
export GLAPI PFNGLVERTEXATTRIBP2UIPROC glad_glVertexAttribP2ui;
export inline void glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { glad_glVertexAttribP2ui(index, type, normalized, value); }
#define glVertexAttribP2ui glad_glVertexAttribP2ui



export typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
export GLAPI PFNGLVERTEXATTRIBP2UIVPROC glad_glVertexAttribP2uiv;
export inline void glVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) { glad_glVertexAttribP2uiv(index, type, normalized, value); }
#define glVertexAttribP2uiv glad_glVertexAttribP2uiv



export typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
export GLAPI PFNGLVERTEXATTRIBP3UIPROC glad_glVertexAttribP3ui;
export inline void glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { glad_glVertexAttribP3ui(index, type, normalized, value); }
#define glVertexAttribP3ui glad_glVertexAttribP3ui



export typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
export GLAPI PFNGLVERTEXATTRIBP3UIVPROC glad_glVertexAttribP3uiv;
export inline void glVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) { glad_glVertexAttribP3uiv(index, type, normalized, value); }
#define glVertexAttribP3uiv glad_glVertexAttribP3uiv



export typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
export GLAPI PFNGLVERTEXATTRIBP4UIPROC glad_glVertexAttribP4ui;
export inline void glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { glad_glVertexAttribP4ui(index, type, normalized, value); }
#define glVertexAttribP4ui glad_glVertexAttribP4ui



export typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
export GLAPI PFNGLVERTEXATTRIBP4UIVPROC glad_glVertexAttribP4uiv;
export inline void glVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) { glad_glVertexAttribP4uiv(index, type, normalized, value); }
#define glVertexAttribP4uiv glad_glVertexAttribP4uiv



export typedef void (APIENTRYP PFNGLVERTEXP2UIPROC)(GLenum type, GLuint value);
export GLAPI PFNGLVERTEXP2UIPROC glad_glVertexP2ui;
export inline void glVertexP2ui(GLenum type, GLuint value) { glad_glVertexP2ui(type, value); }
#define glVertexP2ui glad_glVertexP2ui



export typedef void (APIENTRYP PFNGLVERTEXP2UIVPROC)(GLenum type, const GLuint* value);
export GLAPI PFNGLVERTEXP2UIVPROC glad_glVertexP2uiv;
export inline void glVertexP2uiv(GLenum type, const GLuint* value) { glad_glVertexP2uiv(type, value); }
#define glVertexP2uiv glad_glVertexP2uiv



export typedef void (APIENTRYP PFNGLVERTEXP3UIPROC)(GLenum type, GLuint value);
export GLAPI PFNGLVERTEXP3UIPROC glad_glVertexP3ui;
export inline void glVertexP3ui(GLenum type, GLuint value) { glad_glVertexP3ui(type, value); }
#define glVertexP3ui glad_glVertexP3ui



export typedef void (APIENTRYP PFNGLVERTEXP3UIVPROC)(GLenum type, const GLuint* value);
export GLAPI PFNGLVERTEXP3UIVPROC glad_glVertexP3uiv;
export inline void glVertexP3uiv(GLenum type, const GLuint* value) { glad_glVertexP3uiv(type, value); }
#define glVertexP3uiv glad_glVertexP3uiv



export typedef void (APIENTRYP PFNGLVERTEXP4UIPROC)(GLenum type, GLuint value);
export GLAPI PFNGLVERTEXP4UIPROC glad_glVertexP4ui;
export inline void glVertexP4ui(GLenum type, GLuint value) { glad_glVertexP4ui(type, value); }
#define glVertexP4ui glad_glVertexP4ui



export typedef void (APIENTRYP PFNGLVERTEXP4UIVPROC)(GLenum type, const GLuint* value);
export GLAPI PFNGLVERTEXP4UIVPROC glad_glVertexP4uiv;
export inline void glVertexP4uiv(GLenum type, const GLuint* value) { glad_glVertexP4uiv(type, value); }
#define glVertexP4uiv glad_glVertexP4uiv



export typedef void (APIENTRYP PFNGLTEXCOORDP1UIPROC)(GLenum type, GLuint coords);
export GLAPI PFNGLTEXCOORDP1UIPROC glad_glTexCoordP1ui;
export inline void glTexCoordP1ui(GLenum type, GLuint coords) { glad_glTexCoordP1ui(type, coords); }
#define glTexCoordP1ui glad_glTexCoordP1ui



export typedef void (APIENTRYP PFNGLTEXCOORDP1UIVPROC)(GLenum type, const GLuint* coords);
export GLAPI PFNGLTEXCOORDP1UIVPROC glad_glTexCoordP1uiv;
export inline void glTexCoordP1uiv(GLenum type, const GLuint* coords) { glad_glTexCoordP1uiv(type, coords); }
#define glTexCoordP1uiv glad_glTexCoordP1uiv



export typedef void (APIENTRYP PFNGLTEXCOORDP2UIPROC)(GLenum type, GLuint coords);
export GLAPI PFNGLTEXCOORDP2UIPROC glad_glTexCoordP2ui;
export inline void glTexCoordP2ui(GLenum type, GLuint coords) { glad_glTexCoordP2ui(type, coords); }
#define glTexCoordP2ui glad_glTexCoordP2ui



export typedef void (APIENTRYP PFNGLTEXCOORDP2UIVPROC)(GLenum type, const GLuint* coords);
export GLAPI PFNGLTEXCOORDP2UIVPROC glad_glTexCoordP2uiv;
export inline void glTexCoordP2uiv(GLenum type, const GLuint* coords) { glad_glTexCoordP2uiv(type, coords); }
#define glTexCoordP2uiv glad_glTexCoordP2uiv



export typedef void (APIENTRYP PFNGLTEXCOORDP3UIPROC)(GLenum type, GLuint coords);
export GLAPI PFNGLTEXCOORDP3UIPROC glad_glTexCoordP3ui;
export inline void glTexCoordP3ui(GLenum type, GLuint coords) { glad_glTexCoordP3ui(type, coords); }
#define glTexCoordP3ui glad_glTexCoordP3ui



export typedef void (APIENTRYP PFNGLTEXCOORDP3UIVPROC)(GLenum type, const GLuint* coords);
export GLAPI PFNGLTEXCOORDP3UIVPROC glad_glTexCoordP3uiv;
export inline void glTexCoordP3uiv(GLenum type, const GLuint* coords) { glad_glTexCoordP3uiv(type, coords); }
#define glTexCoordP3uiv glad_glTexCoordP3uiv



export typedef void (APIENTRYP PFNGLTEXCOORDP4UIPROC)(GLenum type, GLuint coords);
export GLAPI PFNGLTEXCOORDP4UIPROC glad_glTexCoordP4ui;
export inline void glTexCoordP4ui(GLenum type, GLuint coords) { glad_glTexCoordP4ui(type, coords); }
#define glTexCoordP4ui glad_glTexCoordP4ui



export typedef void (APIENTRYP PFNGLTEXCOORDP4UIVPROC)(GLenum type, const GLuint* coords);
export GLAPI PFNGLTEXCOORDP4UIVPROC glad_glTexCoordP4uiv;
export inline void glTexCoordP4uiv(GLenum type, const GLuint* coords) { glad_glTexCoordP4uiv(type, coords); }
#define glTexCoordP4uiv glad_glTexCoordP4uiv



export typedef void (APIENTRYP PFNGLMULTITEXCOORDP1UIPROC)(GLenum texture, GLenum type, GLuint coords);
export GLAPI PFNGLMULTITEXCOORDP1UIPROC glad_glMultiTexCoordP1ui;
export inline void glMultiTexCoordP1ui(GLenum texture, GLenum type, GLuint coords) { glad_glMultiTexCoordP1ui(texture, type, coords); }
#define glMultiTexCoordP1ui glad_glMultiTexCoordP1ui



export typedef void (APIENTRYP PFNGLMULTITEXCOORDP1UIVPROC)(GLenum texture, GLenum type, const GLuint* coords);
export GLAPI PFNGLMULTITEXCOORDP1UIVPROC glad_glMultiTexCoordP1uiv;
export inline void glMultiTexCoordP1uiv(GLenum texture, GLenum type, const GLuint* coords) { glad_glMultiTexCoordP1uiv(texture, type, coords); }
#define glMultiTexCoordP1uiv glad_glMultiTexCoordP1uiv



export typedef void (APIENTRYP PFNGLMULTITEXCOORDP2UIPROC)(GLenum texture, GLenum type, GLuint coords);
export GLAPI PFNGLMULTITEXCOORDP2UIPROC glad_glMultiTexCoordP2ui;
export inline void glMultiTexCoordP2ui(GLenum texture, GLenum type, GLuint coords) { glad_glMultiTexCoordP2ui(texture, type, coords); }
#define glMultiTexCoordP2ui glad_glMultiTexCoordP2ui



export typedef void (APIENTRYP PFNGLMULTITEXCOORDP2UIVPROC)(GLenum texture, GLenum type, const GLuint* coords);
export GLAPI PFNGLMULTITEXCOORDP2UIVPROC glad_glMultiTexCoordP2uiv;
export inline void glMultiTexCoordP2uiv(GLenum texture, GLenum type, const GLuint* coords) { glad_glMultiTexCoordP2uiv(texture, type, coords); }
#define glMultiTexCoordP2uiv glad_glMultiTexCoordP2uiv



export typedef void (APIENTRYP PFNGLMULTITEXCOORDP3UIPROC)(GLenum texture, GLenum type, GLuint coords);
export GLAPI PFNGLMULTITEXCOORDP3UIPROC glad_glMultiTexCoordP3ui;
export inline void glMultiTexCoordP3ui(GLenum texture, GLenum type, GLuint coords) { glad_glMultiTexCoordP3ui(texture, type, coords); }
#define glMultiTexCoordP3ui glad_glMultiTexCoordP3ui



export typedef void (APIENTRYP PFNGLMULTITEXCOORDP3UIVPROC)(GLenum texture, GLenum type, const GLuint* coords);
export GLAPI PFNGLMULTITEXCOORDP3UIVPROC glad_glMultiTexCoordP3uiv;
export inline void glMultiTexCoordP3uiv(GLenum texture, GLenum type, const GLuint* coords) { glad_glMultiTexCoordP3uiv(texture, type, coords); }
#define glMultiTexCoordP3uiv glad_glMultiTexCoordP3uiv



export typedef void (APIENTRYP PFNGLMULTITEXCOORDP4UIPROC)(GLenum texture, GLenum type, GLuint coords);
export GLAPI PFNGLMULTITEXCOORDP4UIPROC glad_glMultiTexCoordP4ui;
export inline void glMultiTexCoordP4ui(GLenum texture, GLenum type, GLuint coords) { glad_glMultiTexCoordP4ui(texture, type, coords); }
#define glMultiTexCoordP4ui glad_glMultiTexCoordP4ui



export typedef void (APIENTRYP PFNGLMULTITEXCOORDP4UIVPROC)(GLenum texture, GLenum type, const GLuint* coords);
export GLAPI PFNGLMULTITEXCOORDP4UIVPROC glad_glMultiTexCoordP4uiv;
export inline void glMultiTexCoordP4uiv(GLenum texture, GLenum type, const GLuint* coords) { glad_glMultiTexCoordP4uiv(texture, type, coords); }
#define glMultiTexCoordP4uiv glad_glMultiTexCoordP4uiv



export typedef void (APIENTRYP PFNGLNORMALP3UIPROC)(GLenum type, GLuint coords);
export GLAPI PFNGLNORMALP3UIPROC glad_glNormalP3ui;
export inline void glNormalP3ui(GLenum type, GLuint coords) { glad_glNormalP3ui(type, coords); }
#define glNormalP3ui glad_glNormalP3ui



export typedef void (APIENTRYP PFNGLNORMALP3UIVPROC)(GLenum type, const GLuint* coords);
export GLAPI PFNGLNORMALP3UIVPROC glad_glNormalP3uiv;
export inline void glNormalP3uiv(GLenum type, const GLuint* coords) { glad_glNormalP3uiv(type, coords); }
#define glNormalP3uiv glad_glNormalP3uiv



export typedef void (APIENTRYP PFNGLCOLORP3UIPROC)(GLenum type, GLuint color);
export GLAPI PFNGLCOLORP3UIPROC glad_glColorP3ui;
export inline void glColorP3ui(GLenum type, GLuint color) { glad_glColorP3ui(type, color); }
#define glColorP3ui glad_glColorP3ui



export typedef void (APIENTRYP PFNGLCOLORP3UIVPROC)(GLenum type, const GLuint* color);
export GLAPI PFNGLCOLORP3UIVPROC glad_glColorP3uiv;
export inline void glColorP3uiv(GLenum type, const GLuint* color) { glad_glColorP3uiv(type, color); }
#define glColorP3uiv glad_glColorP3uiv



export typedef void (APIENTRYP PFNGLCOLORP4UIPROC)(GLenum type, GLuint color);
export GLAPI PFNGLCOLORP4UIPROC glad_glColorP4ui;
export inline void glColorP4ui(GLenum type, GLuint color) { glad_glColorP4ui(type, color); }
#define glColorP4ui glad_glColorP4ui



export typedef void (APIENTRYP PFNGLCOLORP4UIVPROC)(GLenum type, const GLuint* color);
export GLAPI PFNGLCOLORP4UIVPROC glad_glColorP4uiv;
export inline void glColorP4uiv(GLenum type, const GLuint* color) { glad_glColorP4uiv(type, color); }
#define glColorP4uiv glad_glColorP4uiv



export typedef void (APIENTRYP PFNGLSECONDARYCOLORP3UIPROC)(GLenum type, GLuint color);
export GLAPI PFNGLSECONDARYCOLORP3UIPROC glad_glSecondaryColorP3ui;
export inline void glSecondaryColorP3ui(GLenum type, GLuint color) { glad_glSecondaryColorP3ui(type, color); }
#define glSecondaryColorP3ui glad_glSecondaryColorP3ui



export typedef void (APIENTRYP PFNGLSECONDARYCOLORP3UIVPROC)(GLenum type, const GLuint* color);
export GLAPI PFNGLSECONDARYCOLORP3UIVPROC glad_glSecondaryColorP3uiv;
export inline void glSecondaryColorP3uiv(GLenum type, const GLuint* color) { glad_glSecondaryColorP3uiv(type, color); }
#define glSecondaryColorP3uiv glad_glSecondaryColorP3uiv



#endif
#pragma endregion
#pragma region GL_VERSION_4_0
#ifndef GL_VERSION_4_0
#define GL_VERSION_4_0 1
export GLAPI int GLAD_GL_VERSION_4_0;



export typedef void (APIENTRYP PFNGLMINSAMPLESHADINGPROC)(GLfloat value);
export GLAPI PFNGLMINSAMPLESHADINGPROC glad_glMinSampleShading;
export inline void glMinSampleShading(GLfloat value) { glad_glMinSampleShading(value); }
#define glMinSampleShading glad_glMinSampleShading



export typedef void (APIENTRYP PFNGLBLENDEQUATIONIPROC)(GLuint buf, GLenum mode);
export GLAPI PFNGLBLENDEQUATIONIPROC glad_glBlendEquationi;
export inline void glBlendEquationi(GLuint buf, GLenum mode) { glad_glBlendEquationi(buf, mode); }
#define glBlendEquationi glad_glBlendEquationi



export typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEIPROC)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
export GLAPI PFNGLBLENDEQUATIONSEPARATEIPROC glad_glBlendEquationSeparatei;
export inline void glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha) { glad_glBlendEquationSeparatei(buf, modeRGB, modeAlpha); }
#define glBlendEquationSeparatei glad_glBlendEquationSeparatei



export typedef void (APIENTRYP PFNGLBLENDFUNCIPROC)(GLuint buf, GLenum src, GLenum dst);
export GLAPI PFNGLBLENDFUNCIPROC glad_glBlendFunci;
export inline void glBlendFunci(GLuint buf, GLenum src, GLenum dst) { glad_glBlendFunci(buf, src, dst); }
#define glBlendFunci glad_glBlendFunci



export typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEIPROC)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
export GLAPI PFNGLBLENDFUNCSEPARATEIPROC glad_glBlendFuncSeparatei;
export inline void glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) { glad_glBlendFuncSeparatei(buf, srcRGB, dstRGB, srcAlpha, dstAlpha); }
#define glBlendFuncSeparatei glad_glBlendFuncSeparatei



export typedef void (APIENTRYP PFNGLDRAWARRAYSINDIRECTPROC)(GLenum mode, const void* indirect);
export GLAPI PFNGLDRAWARRAYSINDIRECTPROC glad_glDrawArraysIndirect;
export inline void glDrawArraysIndirect(GLenum mode, const void* indirect) { glad_glDrawArraysIndirect(mode, indirect); }
#define glDrawArraysIndirect glad_glDrawArraysIndirect



export typedef void (APIENTRYP PFNGLDRAWELEMENTSINDIRECTPROC)(GLenum mode, GLenum type, const void* indirect);
export GLAPI PFNGLDRAWELEMENTSINDIRECTPROC glad_glDrawElementsIndirect;
export inline void glDrawElementsIndirect(GLenum mode, GLenum type, const void* indirect) { glad_glDrawElementsIndirect(mode, type, indirect); }
#define glDrawElementsIndirect glad_glDrawElementsIndirect



export typedef void (APIENTRYP PFNGLUNIFORM1DPROC)(GLint location, GLdouble x);
export GLAPI PFNGLUNIFORM1DPROC glad_glUniform1d;
export inline void glUniform1d(GLint location, GLdouble x) { glad_glUniform1d(location, x); }
#define glUniform1d glad_glUniform1d



export typedef void (APIENTRYP PFNGLUNIFORM2DPROC)(GLint location, GLdouble x, GLdouble y);
export GLAPI PFNGLUNIFORM2DPROC glad_glUniform2d;
export inline void glUniform2d(GLint location, GLdouble x, GLdouble y) { glad_glUniform2d(location, x, y); }
#define glUniform2d glad_glUniform2d



export typedef void (APIENTRYP PFNGLUNIFORM3DPROC)(GLint location, GLdouble x, GLdouble y, GLdouble z);
export GLAPI PFNGLUNIFORM3DPROC glad_glUniform3d;
export inline void glUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z) { glad_glUniform3d(location, x, y, z); }
#define glUniform3d glad_glUniform3d



export typedef void (APIENTRYP PFNGLUNIFORM4DPROC)(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
export GLAPI PFNGLUNIFORM4DPROC glad_glUniform4d;
export inline void glUniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) { glad_glUniform4d(location, x, y, z, w); }
#define glUniform4d glad_glUniform4d



export typedef void (APIENTRYP PFNGLUNIFORM1DVPROC)(GLint location, GLsizei count, const GLdouble* value);
export GLAPI PFNGLUNIFORM1DVPROC glad_glUniform1dv;
export inline void glUniform1dv(GLint location, GLsizei count, const GLdouble* value) { glad_glUniform1dv(location, count, value); }
#define glUniform1dv glad_glUniform1dv



export typedef void (APIENTRYP PFNGLUNIFORM2DVPROC)(GLint location, GLsizei count, const GLdouble* value);
export GLAPI PFNGLUNIFORM2DVPROC glad_glUniform2dv;
export inline void glUniform2dv(GLint location, GLsizei count, const GLdouble* value) { glad_glUniform2dv(location, count, value); }
#define glUniform2dv glad_glUniform2dv



export typedef void (APIENTRYP PFNGLUNIFORM3DVPROC)(GLint location, GLsizei count, const GLdouble* value);
export GLAPI PFNGLUNIFORM3DVPROC glad_glUniform3dv;
export inline void glUniform3dv(GLint location, GLsizei count, const GLdouble* value) { glad_glUniform3dv(location, count, value); }
#define glUniform3dv glad_glUniform3dv



export typedef void (APIENTRYP PFNGLUNIFORM4DVPROC)(GLint location, GLsizei count, const GLdouble* value);
export GLAPI PFNGLUNIFORM4DVPROC glad_glUniform4dv;
export inline void glUniform4dv(GLint location, GLsizei count, const GLdouble* value) { glad_glUniform4dv(location, count, value); }
#define glUniform4dv glad_glUniform4dv



export typedef void (APIENTRYP PFNGLUNIFORMMATRIX2DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
export GLAPI PFNGLUNIFORMMATRIX2DVPROC glad_glUniformMatrix2dv;
export inline void glUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) { glad_glUniformMatrix2dv(location, count, transpose, value); }
#define glUniformMatrix2dv glad_glUniformMatrix2dv



export typedef void (APIENTRYP PFNGLUNIFORMMATRIX3DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
export GLAPI PFNGLUNIFORMMATRIX3DVPROC glad_glUniformMatrix3dv;
export inline void glUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) { glad_glUniformMatrix3dv(location, count, transpose, value); }
#define glUniformMatrix3dv glad_glUniformMatrix3dv



export typedef void (APIENTRYP PFNGLUNIFORMMATRIX4DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
export GLAPI PFNGLUNIFORMMATRIX4DVPROC glad_glUniformMatrix4dv;
export inline void glUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) { glad_glUniformMatrix4dv(location, count, transpose, value); }
#define glUniformMatrix4dv glad_glUniformMatrix4dv



export typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
export GLAPI PFNGLUNIFORMMATRIX2X3DVPROC glad_glUniformMatrix2x3dv;
export inline void glUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) { glad_glUniformMatrix2x3dv(location, count, transpose, value); }
#define glUniformMatrix2x3dv glad_glUniformMatrix2x3dv



export typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
export GLAPI PFNGLUNIFORMMATRIX2X4DVPROC glad_glUniformMatrix2x4dv;
export inline void glUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) { glad_glUniformMatrix2x4dv(location, count, transpose, value); }
#define glUniformMatrix2x4dv glad_glUniformMatrix2x4dv



export typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
export GLAPI PFNGLUNIFORMMATRIX3X2DVPROC glad_glUniformMatrix3x2dv;
export inline void glUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) { glad_glUniformMatrix3x2dv(location, count, transpose, value); }
#define glUniformMatrix3x2dv glad_glUniformMatrix3x2dv



export typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
export GLAPI PFNGLUNIFORMMATRIX3X4DVPROC glad_glUniformMatrix3x4dv;
export inline void glUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) { glad_glUniformMatrix3x4dv(location, count, transpose, value); }
#define glUniformMatrix3x4dv glad_glUniformMatrix3x4dv



export typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
export GLAPI PFNGLUNIFORMMATRIX4X2DVPROC glad_glUniformMatrix4x2dv;
export inline void glUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) { glad_glUniformMatrix4x2dv(location, count, transpose, value); }
#define glUniformMatrix4x2dv glad_glUniformMatrix4x2dv



export typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
export GLAPI PFNGLUNIFORMMATRIX4X3DVPROC glad_glUniformMatrix4x3dv;
export inline void glUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) { glad_glUniformMatrix4x3dv(location, count, transpose, value); }
#define glUniformMatrix4x3dv glad_glUniformMatrix4x3dv



export typedef void (APIENTRYP PFNGLGETUNIFORMDVPROC)(GLuint program, GLint location, GLdouble* params);
export GLAPI PFNGLGETUNIFORMDVPROC glad_glGetUniformdv;
export inline void glGetUniformdv(GLuint program, GLint location, GLdouble* params) { glad_glGetUniformdv(program, location, params); }
#define glGetUniformdv glad_glGetUniformdv



export typedef GLint(APIENTRYP PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)(GLuint program, GLenum shadertype, const GLchar* name);
export GLAPI PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC glad_glGetSubroutineUniformLocation;
export inline GLint glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar* name) { return glad_glGetSubroutineUniformLocation(program, shadertype, name); }
#define glGetSubroutineUniformLocation glad_glGetSubroutineUniformLocation



export typedef GLuint(APIENTRYP PFNGLGETSUBROUTINEINDEXPROC)(GLuint program, GLenum shadertype, const GLchar* name);
export GLAPI PFNGLGETSUBROUTINEINDEXPROC glad_glGetSubroutineIndex;
export inline GLuint glGetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar* name) { return glad_glGetSubroutineIndex(program, shadertype, name); }
#define glGetSubroutineIndex glad_glGetSubroutineIndex



export typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint* values);
export GLAPI PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC glad_glGetActiveSubroutineUniformiv;
export inline void glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint* values) { glad_glGetActiveSubroutineUniformiv(program, shadertype, index, pname, values); }
#define glGetActiveSubroutineUniformiv glad_glGetActiveSubroutineUniformiv



export typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name);
export GLAPI PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC glad_glGetActiveSubroutineUniformName;
export inline void glGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name) { glad_glGetActiveSubroutineUniformName(program, shadertype, index, bufSize, length, name); }
#define glGetActiveSubroutineUniformName glad_glGetActiveSubroutineUniformName



export typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINENAMEPROC)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name);
export GLAPI PFNGLGETACTIVESUBROUTINENAMEPROC glad_glGetActiveSubroutineName;
export inline void glGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name) { glad_glGetActiveSubroutineName(program, shadertype, index, bufSize, length, name); }
#define glGetActiveSubroutineName glad_glGetActiveSubroutineName



export typedef void (APIENTRYP PFNGLUNIFORMSUBROUTINESUIVPROC)(GLenum shadertype, GLsizei count, const GLuint* indices);
export GLAPI PFNGLUNIFORMSUBROUTINESUIVPROC glad_glUniformSubroutinesuiv;
export inline void glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint* indices) { glad_glUniformSubroutinesuiv(shadertype, count, indices); }
#define glUniformSubroutinesuiv glad_glUniformSubroutinesuiv



export typedef void (APIENTRYP PFNGLGETUNIFORMSUBROUTINEUIVPROC)(GLenum shadertype, GLint location, GLuint* params);
export GLAPI PFNGLGETUNIFORMSUBROUTINEUIVPROC glad_glGetUniformSubroutineuiv;
export inline void glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint* params) { glad_glGetUniformSubroutineuiv(shadertype, location, params); }
#define glGetUniformSubroutineuiv glad_glGetUniformSubroutineuiv



export typedef void (APIENTRYP PFNGLGETPROGRAMSTAGEIVPROC)(GLuint program, GLenum shadertype, GLenum pname, GLint* values);
export GLAPI PFNGLGETPROGRAMSTAGEIVPROC glad_glGetProgramStageiv;
export inline void glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint* values) { glad_glGetProgramStageiv(program, shadertype, pname, values); }
#define glGetProgramStageiv glad_glGetProgramStageiv



export typedef void (APIENTRYP PFNGLPATCHPARAMETERIPROC)(GLenum pname, GLint value);
export GLAPI PFNGLPATCHPARAMETERIPROC glad_glPatchParameteri;
export inline void glPatchParameteri(GLenum pname, GLint value) { glad_glPatchParameteri(pname, value); }
#define glPatchParameteri glad_glPatchParameteri



export typedef void (APIENTRYP PFNGLPATCHPARAMETERFVPROC)(GLenum pname, const GLfloat* values);
export GLAPI PFNGLPATCHPARAMETERFVPROC glad_glPatchParameterfv;
export inline void glPatchParameterfv(GLenum pname, const GLfloat* values) { glad_glPatchParameterfv(pname, values); }
#define glPatchParameterfv glad_glPatchParameterfv



export typedef void (APIENTRYP PFNGLBINDTRANSFORMFEEDBACKPROC)(GLenum target, GLuint id);
export GLAPI PFNGLBINDTRANSFORMFEEDBACKPROC glad_glBindTransformFeedback;
export inline void glBindTransformFeedback(GLenum target, GLuint id) { glad_glBindTransformFeedback(target, id); }
#define glBindTransformFeedback glad_glBindTransformFeedback


export typedef void (APIENTRYP PFNGLDELETETRANSFORMFEEDBACKSPROC)(GLsizei n, const GLuint* ids);
export GLAPI PFNGLDELETETRANSFORMFEEDBACKSPROC glad_glDeleteTransformFeedbacks;
export inline void glDeleteTransformFeedbacks(GLsizei n, const GLuint* ids) { glad_glDeleteTransformFeedbacks(n, ids); }
#define glDeleteTransformFeedbacks glad_glDeleteTransformFeedbacks



export typedef void (APIENTRYP PFNGLGENTRANSFORMFEEDBACKSPROC)(GLsizei n, GLuint* ids);
export GLAPI PFNGLGENTRANSFORMFEEDBACKSPROC glad_glGenTransformFeedbacks;
export inline void glGenTransformFeedbacks(GLsizei n, GLuint* ids) { glad_glGenTransformFeedbacks(n, ids); }
#define glGenTransformFeedbacks glad_glGenTransformFeedbacks



export typedef GLboolean(APIENTRYP PFNGLISTRANSFORMFEEDBACKPROC)(GLuint id);
export GLAPI PFNGLISTRANSFORMFEEDBACKPROC glad_glIsTransformFeedback;
export inline GLboolean glIsTransformFeedback(GLuint id) { return glad_glIsTransformFeedback(id); }
#define glIsTransformFeedback glad_glIsTransformFeedback



export typedef void (APIENTRYP PFNGLPAUSETRANSFORMFEEDBACKPROC)(void);
export GLAPI PFNGLPAUSETRANSFORMFEEDBACKPROC glad_glPauseTransformFeedback;
export inline void glPauseTransformFeedback() { glad_glPauseTransformFeedback(); }
#define glPauseTransformFeedback glad_glPauseTransformFeedback



export typedef void (APIENTRYP PFNGLRESUMETRANSFORMFEEDBACKPROC)(void);
export GLAPI PFNGLRESUMETRANSFORMFEEDBACKPROC glad_glResumeTransformFeedback;
export inline void glResumeTransformFeedback() { glad_glResumeTransformFeedback(); }
#define glResumeTransformFeedback glad_glResumeTransformFeedback



export typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKPROC)(GLenum mode, GLuint id);
export GLAPI PFNGLDRAWTRANSFORMFEEDBACKPROC glad_glDrawTransformFeedback;
export inline void glDrawTransformFeedback(GLenum mode, GLuint id) { glad_glDrawTransformFeedback(mode, id); }
#define glDrawTransformFeedback glad_glDrawTransformFeedback



export typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)(GLenum mode, GLuint id, GLuint stream);
export GLAPI PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC glad_glDrawTransformFeedbackStream;
export inline void glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream) { glad_glDrawTransformFeedbackStream(mode, id, stream); }
#define glDrawTransformFeedbackStream glad_glDrawTransformFeedbackStream



export typedef void (APIENTRYP PFNGLBEGINQUERYINDEXEDPROC)(GLenum target, GLuint index, GLuint id);
export GLAPI PFNGLBEGINQUERYINDEXEDPROC glad_glBeginQueryIndexed;
export inline void glBeginQueryIndexed(GLenum target, GLuint index, GLuint id) { glad_glBeginQueryIndexed(target, index, id); }
#define glBeginQueryIndexed glad_glBeginQueryIndexed



export typedef void (APIENTRYP PFNGLENDQUERYINDEXEDPROC)(GLenum target, GLuint index);
export GLAPI PFNGLENDQUERYINDEXEDPROC glad_glEndQueryIndexed;
export inline void glEndQueryIndexed(GLenum target, GLuint index) { glad_glEndQueryIndexed(target, index); }
#define glEndQueryIndexed glad_glEndQueryIndexed



export typedef void (APIENTRYP PFNGLGETQUERYINDEXEDIVPROC)(GLenum target, GLuint index, GLenum pname, GLint* params);
export GLAPI PFNGLGETQUERYINDEXEDIVPROC glad_glGetQueryIndexediv;
export inline void glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint* params) { glad_glGetQueryIndexediv(target, index, pname, params); }
#define glGetQueryIndexediv glad_glGetQueryIndexediv



#endif
#pragma endregion




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


//TODO SEPPERATOR----------------------------------------

#pragma region CONSTEXPR


//TODO SEPPERATOR----------------------------------------


//TODO SEPPERATOR----------------------------------------

//TODO SEPPERATOR----------------------------------------

//TODO SEPPERATOR----------------------------------------


//TODO SEPPERATOR----------------------------------------


//TODO SEPPERATOR----------------------------------------

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
//TODO SEPPERATOR----------------------------------------

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




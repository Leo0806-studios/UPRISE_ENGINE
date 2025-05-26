#pragma once
#ifndef UE_GLAD_GLOBALS_INTERNAL_
#define UE_GLAD_GLOBALS_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_OPENGL_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#include "GLAD/STUPIDMACROS/GLAD_MACROS.h"
#ifdef __INTELLISENSE__
#ifndef DONT_INCLUDE_GLAD
/#include <glad/glad.h>
#endif
#if(defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || defined(__GNUC__) || defined(__SCO__) || defined(__USLC__)
#include <stdint.h>
#elif defined(__VMS ) || defined(__sgi)
#include <inttypes.h>
#elif defined(_WIN32) && !defined(__SCITECH_SNAP__)
#elif defined(__sun__) || defined(__digital__)
#elif 0

#else
#include <stdint.h>

#endif
#endif // __INTELLISENSE__
extern"C" GLAPI int gladLoadGL(void);

namespace UPRISE_ENGINE {
    namespace RENDER {
        namespace GLAD {
            struct  gladGLversionStruct {
                int major;
                int minor;
            };
            typedef void* (*GLADloadproc)(const char* name);
            /// <summary>
            /// global instance that holds the version of the loaded OpenGL
            /// </summary>
              GLAPI struct gladGLversionStruct GLVersion;

            /// <summary>
            /// loads the OpenGL library
            /// </summary>
            /// <param name="void"></param>
            /// <returns></returns>
            /// <summary>
            /// 
            /// </summary>
            /// <param name=""></param>
            /// /// <returns></returns>
              GLAPI int gladLoadGLLoader(GLADloadproc);







#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || defined(__GNUC__) || defined(__SCO__) || defined(__USLC__)


            /*
             * Using <stdint.h>
             */
             //#include <stdint.h>
              typedef int32_t                 khronos_int32_t;
              typedef uint32_t                khronos_uint32_t;
              typedef int64_t                 khronos_int64_t;
              typedef uint64_t                khronos_uint64_t;
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
             ///moved to GLAD_MACROS.h

#elif defined(__VMS ) || defined(__sgi)

            /*
             * Using <inttypes.h>
             */
             //#include <inttypes.h>
              typedef int32_t                 khronos_int32_t;
              typedef uint32_t                khronos_uint32_t;
              typedef int64_t                 khronos_int64_t;
              typedef uint64_t                khronos_uint64_t;
              constexpr int _KHRONOS_SUPPORT_INT64 = 1;
              constexpr int _KHRONOS_SUPPORT_FLOAT = 1;





#elif defined(_WIN32) && !defined(__SCITECH_SNAP__)

            /*
             * Win32
             */
              typedef __int32                 khronos_int32_t;
              typedef unsigned __int32        khronos_uint32_t;
              typedef __int64                 khronos_int64_t;
              typedef unsigned __int64        khronos_uint64_t;
              constexpr int _KHRONOS_SUPPORT_INT64 = 1;
              constexpr int _KHRONOS_SUPPORT_FLOAT = 1;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#elif defined(__sun__) || defined(__digital__)

            /*
             * Sun or Digital
             */
              typedef int                     khronos_int32_t;
              typedef unsigned int            khronos_uint32_t;
#if defined(__arch64__) || defined(_LP64)
              typedef long int                khronos_int64_t;
              typedef unsigned long int       khronos_uint64_t;
#else
              typedef long long int           khronos_int64_t;
              typedef unsigned long long int  khronos_uint64_t;
              constexpr int _KHRONOS_SUPPORT_INT64 = 1;
              constexpr int _KHRONOS_SUPPORT_FLOAT = 1;
#endif /* __arch64__ */
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#elif 0

            /*
             * Hypothetical platform with no float or int64 support
             */
              typedef int                     khronos_int32_t;
              typedef unsigned int            khronos_uint32_t;
              constexpr int _KHRONOS_SUPPORT_INT64 = 0;
              constexpr int _KHRONOS_SUPPORT_FLOAT = 0;
#define KHRONOS_SUPPORT_INT64   0
#define KHRONOS_SUPPORT_FLOAT   0

#else

            /*
             * Generic fallback
             */
#include <stdint.h>
              typedef int32_t                 khronos_int32_t;
              typedef uint32_t                khronos_uint32_t;
              typedef int64_t                 khronos_int64_t;
              typedef uint64_t                khronos_uint64_t;
              constexpr int _KHRONOS_SUPPORT_INT64 = 1;
              constexpr int _KHRONOS_SUPPORT_FLOAT = 1;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#endif

            /*
 * Types that are (so far) the same on all platforms
 */
            typedef signed   char          khronos_int8_t;
            typedef unsigned char          khronos_uint8_t;
            typedef signed   short int     khronos_int16_t;
            typedef unsigned short int     khronos_uint16_t;


            /*
 * Types that differ between LLP64 and LP64 architectures - in LLP64,
 * pointers are 64 bits, but 'long' is still 32 bits. Win64 appears
 * to be the only LLP64 architecture in current use.
 */
#ifdef KHRONOS_USE_INTPTR_T
              typedef intptr_t               khronos_intptr_t;
              typedef uintptr_t              khronos_uintptr_t;
#elif defined(_WIN64)
              typedef signed   long long int khronos_intptr_t;
              typedef unsigned long long int khronos_uintptr_t;
#else
              typedef signed   long  int     khronos_intptr_t;
              typedef unsigned long  int     khronos_uintptr_t;
#endif

#if defined(_WIN64)
              typedef signed   long long int khronos_ssize_t;
              typedef unsigned long long int khronos_usize_t;
#else
              typedef signed   long  int     khronos_ssize_t;
              typedef unsigned long  int     khronos_usize_t;
#endif


#if KHRONOS_SUPPORT_FLOAT
            /*
             * Float type
             */
             typedef          float         khronos_float_t;
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
             typedef khronos_uint64_t       khronos_utime_nanoseconds_t;
             typedef khronos_int64_t        khronos_stime_nanoseconds_t;
#endif
            /*
             * Dummy value used to pad enum types to 32 bits.
             */
             constexpr int _KHRONOS_MAX_ENUM = 0x7FFFFFFF;
#ifndef DONT_INCLUDE_GLAD
            consteval void CheckMaxEnum() {
                static_assert(KHRONOS_MAX_ENUM == _KHRONOS_MAX_ENUM, "_KHRONOS_MAX_ENUM is not equal to KHRONOS_MAX_ENUM");
            }
#endif

            /*
 * Enumerated boolean type
 *
 * Values other than zero should be considered to be true.  Therefore
 * comparisons should not be made against KHRONOS_TRUE.
 */
             typedef enum {
                KHRONOS_FALSE = 0,
                KHRONOS_TRUE = 1,
                KHRONOS_BOOLEAN_ENUM_FORCE_SIZE = _KHRONOS_MAX_ENUM
            } khronos_boolean_enum_t;




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


#ifdef __APPLE__
             export typedef void* GLhandleARB;
#else
             export typedef unsigned int GLhandleARB;
#endif


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



             typedef unsigned short GLhalfNV;
             typedef GLintptr GLvdpauSurfaceNV;
             /// <summary>
             /// GL
             /// </summary>
             typedef void (APIENTRY* GLVULKANPROCNV)(void);
        }
    }
}


#endif

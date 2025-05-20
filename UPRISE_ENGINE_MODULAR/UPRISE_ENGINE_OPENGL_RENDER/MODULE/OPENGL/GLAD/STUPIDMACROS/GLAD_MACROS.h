#pragma once
#ifndef UE_GLAD_MACROS_
#define UE_GLAD_MACROS_
#pragma warning(push)
#pragma warning(disable : 4005)
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
#define GL_VERSION_3_0
#pragma warning(pop)
#endif //UE_GLAD_MACROS_
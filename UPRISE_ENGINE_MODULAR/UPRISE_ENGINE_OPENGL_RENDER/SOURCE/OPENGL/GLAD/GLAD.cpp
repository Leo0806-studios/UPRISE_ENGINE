#pragma warning(disable : 4005)
#pragma warning(disable:5045)
#ifdef __INTELLISENSE__
#define DONT_INCLUDE_GLAD
#   include "OPENGL/GLAD/GLAD_INTELLISENSE_FIX.h"
#   include "OPENGL/GLAD/STUPIDMACROS/GLAD_MACROS.h"
#   include <stdio.h>
#   if defined(_WIN32)  || defined(__CYGWIN__)
#   ifndef _WINDOWS_
#       undef APIENTRY
#   endif
#       include <windows.h>
namespace UPRISE_ENGINE::RENDER::GLAD {
    static HMODULE libGL;
    using PFNWGLGETPROCADDRESSPROC_PRIVATE = void* (APIENTRYP)(const char*);
    static PFNWGLGETPROCADDRESSPROC_PRIVATE gladGetProcAddressPtr;
}

#   ifdef _MSC_VER
#       ifdef __has_include
#           if __has_include(<winapifamily.h>)
#               define HAVE_WINAPIFAMILY 1
#           endif
#       elif _MSC_VER >= 1700 && !_USING_V110_SDK71_
#d          efine HAVE_WINAPIFAMILY 1
#       endif
#   endif

#   ifdef HAVE_WINAPIFAMILY
#       include <winapifamily.h>
#       if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) && WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
#           define IS_UWP 1
#       endif
#   endif
#   else
//TODO Fuck this shit ill do it later
#   endif

#else
import GLAD;
#   include "OPENGL/GLAD/STUPIDMACROS/GLAD_MACROS.h"
#include <stdio.h>
#   if defined(_WIN32)  || defined(__CYGWIN__)

import <Windows.h>;
namespace UPRISE_ENGINE::RENDER::GLAD {
    static HMODULE libGL;
    using PFNWGLGETPROCADDRESSPROC_PRIVATE = void* (APIENTRYP)(const char*);
    static PFNWGLGETPROCADDRESSPROC_PRIVATE gladGetProcAddressPtr;
}
#   ifdef _MSC_VER
#       ifdef __has_include
#           if __has_include(<winapifamily.h>)
#               define HAVE_WINAPIFAMILY 1
#           endif
#       elif _MSC_VER >= 1700 && !_USING_V110_SDK71_
#d          efine HAVE_WINAPIFAMILY 1
#       endif
#   endif

#   ifdef HAVE_WINAPIFAMILY
#pragma warning(push)
#pragma warning(disable : 4005)
#include <winapifamily.h>
#pragma warning(pop)
#       if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) && WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
#           define IS_UWP 1
#       endif
#   endif
#   else
//TODO Fuck this shit ill do it later
#   endif

#endif // __INTELLISENSE__


#if defined(_WIN32) || defined(__CYGWIN__)

namespace UPRISE_ENGINE::RENDER::GLAD {



	static int open_gl(void) {
#ifndef IS_UWP
		libGL = LoadLibraryW(L"opengl32.dll");
		if (libGL != nullptr) {
			using funci = void(*)(void);
			void (*tmp)(void) = static_cast<funci>(static_cast<void*>(GetProcAddress(libGL, "wglGetProcAddress")));
			gladGetProcAddressPtr = static_cast<PFNWGLGETPROCADDRESSPROC_PRIVATE>(static_cast<void*>(tmp));
			return gladGetProcAddressPtr != nullptr;
		   
		}
#endif // !IS_UWP
		return 0;
	}
	static void close_gl(void) {
		if (libGL != nullptr) {
			FreeLibrary(libGL);
			libGL = nullptr;
		}
	}

}
#else
//TODO Fuck this shit ill do it later
#endif


namespace UPRISE_ENGINE::RENDER::GLAD {
    static void* get_proc(const char* namez) {
        void* result = nullptr;
        if (libGL == nullptr) {
            return nullptr;
        }
#if !defined(__APPLE__)&&!defined(__HAIKU__)
        if (gladGetProcAddressPtr != nullptr) {
            result = gladGetProcAddressPtr(namez);
        }
#endif
        if (result == nullptr) {
#if defined (_WIN32)|| defined (__CYGWIN__)
            result = static_cast<void*>(GetProcAddress(libGL, namez));
#else
            result = dlsym(libgl, namez);
#endif
        }
        return result;
    }
}
	int gladLoadGL(void) {
		int status = 0;
		if (UPRISE_ENGINE::RENDER::GLAD::open_gl()) {
			status = UPRISE_ENGINE::RENDER::GLAD::gladLoadGLLoader(&UPRISE_ENGINE::RENDER::GLAD::get_proc);
            UPRISE_ENGINE::RENDER::GLAD::close_gl();
		}
		return status;
	}
	
    namespace UPRISE_ENGINE::RENDER::GLAD {

	struct gladGLversionStruct GLVersion = { 0, 0 };
#if defined(GL_ES_VERSION_3_0) || defined(GL_VERSION_3_0)
#   define _GLAD_IS_SOME_NEW_VERSION 1
#endif
	static int max_loaded_major;
	static int max_loaded_minor;
	static const char* exts = nullptr;
	static int num_exts_i = 0;
	static char** exts_i = nullptr;
	static int get_exts(void) {
#ifdef _GLAD_IS_SOME_NEW_VERSION
		if (max_loaded_major < 3) {
#endif
			exts = reinterpret_cast<const char*>(glGetString(CONSTANTS::_GL_EXTENSIONS));
#ifdef _GLAD_IS_SOME_NEW_VERSION
		}
		else {
			int index=0;
			num_exts_i = 0;
			glGetIntegerv(CONSTANTS::_GL_NUM_EXTENSIONS, &num_exts_i);
			if (num_exts_i > 0) {
				exts_i = static_cast<char**>(malloc(static_cast<size_t>(num_exts_i) * (sizeof * exts_i)));
			}
			if (exts_i == nullptr) {
				return 0;
			}
			for (; index < num_exts_i; index++) {
				const char* gl_str_tmp = reinterpret_cast<const char*>(glGetStringi(CONSTANTS::_GL_EXTENSIONS, static_cast<unsigned int>(index)));
				size_t len = strlen(gl_str_tmp);
				char* local_str = static_cast<char*>(malloc((len + 1) * sizeof(char)));
				if (local_str != nullptr) {
					memcpy(local_str, gl_str_tmp, (len + 1) * sizeof(char));
				}
				exts_i[index] = local_str;
			}
		}
#endif // _GLAD_IS_SOME_NEW_VERSION
		return 1;
	}


	static void free_exts(void) {
		if (exts_i != nullptr) {
			int index;
			for (index = 0; index < num_exts_i; index++) {
				free((char*)exts_i[index]);
			}
			free((void*)exts_i);
			exts_i = nullptr;
		}
	}
	static int has_ext(const char* ext) {
#ifdef _GLAD_IS_SOME_NEW_VERSION
		if (max_loaded_major < 3) {
#endif
			const char* extensions;
			const char* loc;
			const char* terminator;
			extensions = exts;
			if (extensions == nullptr || ext == nullptr) {
				return 0;
			}
			while (true) {
				loc = strstr(extensions, ext);
				if (loc == nullptr) {
					return 0;
				}
				terminator = loc + strlen(ext);
				if ((loc == extensions || *(loc - 1) == ' ') &&
					(*terminator == ' ' || *terminator == '\0')) {
					return 1;
				}
				extensions = terminator;
			}
#ifdef _GLAD_IS_SOME_NEW_VERSION
		}
		else {
			int index;
			if (exts_i == nullptr) return 0;
			for (index = 0; index < num_exts_i; index++) {
				const char* e = exts_i[index];
				if (exts_i[index] != nullptr && strcmp(e, ext) == 0) {
					return 1;
				}
			}
		}
#endif
		return 0;
	}
	int UPRISE_ENGINE::RENDER::GLAD::GLAD_GL_VERSION_1_0 = 0;
	int UPRISE_ENGINE::RENDER::GLAD::GLAD_GL_VERSION_1_1 = 0;
	int UPRISE_ENGINE::RENDER::GLAD::GLAD_GL_VERSION_1_2 = 0;
	int UPRISE_ENGINE::RENDER::GLAD::GLAD_GL_VERSION_1_3 = 0;
	int UPRISE_ENGINE::RENDER::GLAD::GLAD_GL_VERSION_1_4 = 0;
	int UPRISE_ENGINE::RENDER::GLAD::GLAD_GL_VERSION_1_5 = 0;
	int UPRISE_ENGINE::RENDER::GLAD::GLAD_GL_VERSION_2_0 = 0;
	int UPRISE_ENGINE::RENDER::GLAD::GLAD_GL_VERSION_2_1 = 0;
	int UPRISE_ENGINE::RENDER::GLAD::GLAD_GL_VERSION_3_0 = 0;
	int UPRISE_ENGINE::RENDER::GLAD::GLAD_GL_VERSION_3_1 = 0;
	int UPRISE_ENGINE::RENDER::GLAD::GLAD_GL_VERSION_3_2 = 0;
	int UPRISE_ENGINE::RENDER::GLAD::GLAD_GL_VERSION_3_3 = 0;
	int UPRISE_ENGINE::RENDER::GLAD::GLAD_GL_VERSION_4_0 = 0;






	PFNGLACTIVETEXTUREPROC glad_glActiveTexture = nullptr;
	PFNGLATTACHSHADERPROC glad_glAttachShader = nullptr;
	PFNGLBEGINCONDITIONALRENDERPROC glad_glBeginConditionalRender = nullptr;
	PFNGLBEGINQUERYPROC glad_glBeginQuery = nullptr;
	PFNGLBEGINQUERYINDEXEDPROC glad_glBeginQueryIndexed = nullptr;
	PFNGLBEGINTRANSFORMFEEDBACKPROC glad_glBeginTransformFeedback = nullptr;
	PFNGLBINDATTRIBLOCATIONPROC glad_glBindAttribLocation = nullptr;
	PFNGLBINDBUFFERPROC glad_glBindBuffer = nullptr;
	PFNGLBINDBUFFERBASEPROC glad_glBindBufferBase = nullptr;
	PFNGLBINDBUFFERRANGEPROC glad_glBindBufferRange = nullptr;
	PFNGLBINDFRAGDATALOCATIONPROC glad_glBindFragDataLocation = nullptr;
	PFNGLBINDFRAGDATALOCATIONINDEXEDPROC glad_glBindFragDataLocationIndexed = nullptr;
	PFNGLBINDFRAMEBUFFERPROC glad_glBindFramebuffer = nullptr;
	PFNGLBINDRENDERBUFFERPROC glad_glBindRenderbuffer = nullptr;
	PFNGLBINDSAMPLERPROC glad_glBindSampler = nullptr;
	PFNGLBINDTEXTUREPROC glad_glBindTexture = nullptr;
	PFNGLBINDTRANSFORMFEEDBACKPROC glad_glBindTransformFeedback = nullptr;
	PFNGLBINDVERTEXARRAYPROC glad_glBindVertexArray = nullptr;
	PFNGLBLENDCOLORPROC glad_glBlendColor = nullptr;
	PFNGLBLENDEQUATIONPROC glad_glBlendEquation = nullptr;
	PFNGLBLENDEQUATIONSEPARATEPROC glad_glBlendEquationSeparate = nullptr;
	PFNGLBLENDEQUATIONSEPARATEIPROC glad_glBlendEquationSeparatei = nullptr;
	PFNGLBLENDEQUATIONIPROC glad_glBlendEquationi = nullptr;
	PFNGLBLENDFUNCPROC glad_glBlendFunc = nullptr;
	PFNGLBLENDFUNCSEPARATEPROC glad_glBlendFuncSeparate = nullptr;
	PFNGLBLENDFUNCSEPARATEIPROC glad_glBlendFuncSeparatei = nullptr;
	PFNGLBLENDFUNCIPROC glad_glBlendFunci = nullptr;
	PFNGLBLITFRAMEBUFFERPROC glad_glBlitFramebuffer = nullptr;
	PFNGLBUFFERDATAPROC glad_glBufferData = nullptr;
	PFNGLBUFFERSUBDATAPROC glad_glBufferSubData = nullptr;
	PFNGLCHECKFRAMEBUFFERSTATUSPROC glad_glCheckFramebufferStatus = nullptr;
	PFNGLCLAMPCOLORPROC glad_glClampColor = nullptr;
	PFNGLCLEARPROC glad_glClear = nullptr;
	PFNGLCLEARBUFFERFIPROC glad_glClearBufferfi = nullptr;
	PFNGLCLEARBUFFERFVPROC glad_glClearBufferfv = nullptr;
	PFNGLCLEARBUFFERIVPROC glad_glClearBufferiv = nullptr;
	PFNGLCLEARBUFFERUIVPROC glad_glClearBufferuiv = nullptr;
	PFNGLCLEARCOLORPROC glad_glClearColor = nullptr;
	PFNGLCLEARDEPTHPROC glad_glClearDepth = nullptr;
	PFNGLCLEARSTENCILPROC glad_glClearStencil = nullptr;
	PFNGLCLIENTWAITSYNCPROC glad_glClientWaitSync = nullptr;
	PFNGLCOLORMASKPROC glad_glColorMask = nullptr;
	PFNGLCOLORMASKIPROC glad_glColorMaski = nullptr;
	PFNGLCOLORP3UIPROC glad_glColorP3ui = nullptr;
	PFNGLCOLORP3UIVPROC glad_glColorP3uiv = nullptr;
	PFNGLCOLORP4UIPROC glad_glColorP4ui = nullptr;
	PFNGLCOLORP4UIVPROC glad_glColorP4uiv = nullptr;
	PFNGLCOMPILESHADERPROC glad_glCompileShader = nullptr;
	PFNGLCOMPRESSEDTEXIMAGE1DPROC glad_glCompressedTexImage1D = nullptr;
	PFNGLCOMPRESSEDTEXIMAGE2DPROC glad_glCompressedTexImage2D = nullptr;
	PFNGLCOMPRESSEDTEXIMAGE3DPROC glad_glCompressedTexImage3D = nullptr;
	PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glad_glCompressedTexSubImage1D = nullptr;
	PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glad_glCompressedTexSubImage2D = nullptr;
	PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glad_glCompressedTexSubImage3D = nullptr;
	PFNGLCOPYBUFFERSUBDATAPROC glad_glCopyBufferSubData = nullptr;
	PFNGLCOPYTEXIMAGE1DPROC glad_glCopyTexImage1D = nullptr;
	PFNGLCOPYTEXIMAGE2DPROC glad_glCopyTexImage2D = nullptr;
	PFNGLCOPYTEXSUBIMAGE1DPROC glad_glCopyTexSubImage1D = nullptr;
	PFNGLCOPYTEXSUBIMAGE2DPROC glad_glCopyTexSubImage2D = nullptr;
	PFNGLCOPYTEXSUBIMAGE3DPROC glad_glCopyTexSubImage3D = nullptr;
	PFNGLCREATEPROGRAMPROC glad_glCreateProgram = nullptr;
	PFNGLCREATESHADERPROC glad_glCreateShader = nullptr;
	PFNGLCULLFACEPROC glad_glCullFace = nullptr;
	PFNGLDELETEBUFFERSPROC glad_glDeleteBuffers = nullptr;
	PFNGLDELETEFRAMEBUFFERSPROC glad_glDeleteFramebuffers = nullptr;
	PFNGLDELETEPROGRAMPROC glad_glDeleteProgram = nullptr;
	PFNGLDELETEQUERIESPROC glad_glDeleteQueries = nullptr;
	PFNGLDELETERENDERBUFFERSPROC glad_glDeleteRenderbuffers = nullptr;
	PFNGLDELETESAMPLERSPROC glad_glDeleteSamplers = nullptr;
	PFNGLDELETESHADERPROC glad_glDeleteShader = nullptr;
	PFNGLDELETESYNCPROC glad_glDeleteSync = nullptr;
	PFNGLDELETETEXTURESPROC glad_glDeleteTextures = nullptr;
	PFNGLDELETETRANSFORMFEEDBACKSPROC glad_glDeleteTransformFeedbacks = nullptr;
	PFNGLDELETEVERTEXARRAYSPROC glad_glDeleteVertexArrays = nullptr;
	PFNGLDEPTHFUNCPROC glad_glDepthFunc = nullptr;
	PFNGLDEPTHMASKPROC glad_glDepthMask = nullptr;
	PFNGLDEPTHRANGEPROC glad_glDepthRange = nullptr;
	PFNGLDETACHSHADERPROC glad_glDetachShader = nullptr;
	PFNGLDISABLEPROC glad_glDisable = nullptr;
	PFNGLDISABLEVERTEXATTRIBARRAYPROC glad_glDisableVertexAttribArray = nullptr;
	PFNGLDISABLEIPROC glad_glDisablei = nullptr;
	PFNGLDRAWARRAYSPROC glad_glDrawArrays = nullptr;
	PFNGLDRAWARRAYSINDIRECTPROC glad_glDrawArraysIndirect = nullptr;
	PFNGLDRAWARRAYSINSTANCEDPROC glad_glDrawArraysInstanced = nullptr;
	PFNGLDRAWBUFFERPROC glad_glDrawBuffer = nullptr;
	PFNGLDRAWBUFFERSPROC glad_glDrawBuffers = nullptr;
	PFNGLDRAWELEMENTSPROC glad_glDrawElements = nullptr;
	PFNGLDRAWELEMENTSBASEVERTEXPROC glad_glDrawElementsBaseVertex = nullptr;
	PFNGLDRAWELEMENTSINDIRECTPROC glad_glDrawElementsIndirect = nullptr;
	PFNGLDRAWELEMENTSINSTANCEDPROC glad_glDrawElementsInstanced = nullptr;
	PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glad_glDrawElementsInstancedBaseVertex = nullptr;
	PFNGLDRAWRANGEELEMENTSPROC glad_glDrawRangeElements = nullptr;
	PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glad_glDrawRangeElementsBaseVertex = nullptr;
	PFNGLDRAWTRANSFORMFEEDBACKPROC glad_glDrawTransformFeedback = nullptr;
	PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC glad_glDrawTransformFeedbackStream = nullptr;
	PFNGLENABLEPROC glad_glEnable = nullptr;
	PFNGLENABLEVERTEXATTRIBARRAYPROC glad_glEnableVertexAttribArray = nullptr;
	PFNGLENABLEIPROC glad_glEnablei = nullptr;
	PFNGLENDCONDITIONALRENDERPROC glad_glEndConditionalRender = nullptr;
	PFNGLENDQUERYPROC glad_glEndQuery = nullptr;
	PFNGLENDQUERYINDEXEDPROC glad_glEndQueryIndexed = nullptr;
	PFNGLENDTRANSFORMFEEDBACKPROC glad_glEndTransformFeedback = nullptr;
	PFNGLFENCESYNCPROC glad_glFenceSync = nullptr;
	PFNGLFINISHPROC glad_glFinish = nullptr;
	PFNGLFLUSHPROC glad_glFlush = nullptr;
	PFNGLFLUSHMAPPEDBUFFERRANGEPROC glad_glFlushMappedBufferRange = nullptr;
	PFNGLFRAMEBUFFERRENDERBUFFERPROC glad_glFramebufferRenderbuffer = nullptr;
	PFNGLFRAMEBUFFERTEXTUREPROC glad_glFramebufferTexture = nullptr;
	PFNGLFRAMEBUFFERTEXTURE1DPROC glad_glFramebufferTexture1D = nullptr;
	PFNGLFRAMEBUFFERTEXTURE2DPROC glad_glFramebufferTexture2D = nullptr;
	PFNGLFRAMEBUFFERTEXTURE3DPROC glad_glFramebufferTexture3D = nullptr;
	PFNGLFRAMEBUFFERTEXTURELAYERPROC glad_glFramebufferTextureLayer = nullptr;
	PFNGLFRONTFACEPROC glad_glFrontFace = nullptr;
	PFNGLGENBUFFERSPROC glad_glGenBuffers = nullptr;
	PFNGLGENFRAMEBUFFERSPROC glad_glGenFramebuffers = nullptr;
	PFNGLGENQUERIESPROC glad_glGenQueries = nullptr;
	PFNGLGENRENDERBUFFERSPROC glad_glGenRenderbuffers = nullptr;
	PFNGLGENSAMPLERSPROC glad_glGenSamplers = nullptr;
	PFNGLGENTEXTURESPROC glad_glGenTextures = nullptr;
	PFNGLGENTRANSFORMFEEDBACKSPROC glad_glGenTransformFeedbacks = nullptr;
	PFNGLGENVERTEXARRAYSPROC glad_glGenVertexArrays = nullptr;
	PFNGLGENERATEMIPMAPPROC glad_glGenerateMipmap = nullptr;
	PFNGLGETACTIVEATTRIBPROC glad_glGetActiveAttrib = nullptr;
	PFNGLGETACTIVESUBROUTINENAMEPROC glad_glGetActiveSubroutineName = nullptr;
	PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC glad_glGetActiveSubroutineUniformName = nullptr;
	PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC glad_glGetActiveSubroutineUniformiv = nullptr;
	PFNGLGETACTIVEUNIFORMPROC glad_glGetActiveUniform = nullptr;
	PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glad_glGetActiveUniformBlockName = nullptr;
	PFNGLGETACTIVEUNIFORMBLOCKIVPROC glad_glGetActiveUniformBlockiv = nullptr;
	PFNGLGETACTIVEUNIFORMNAMEPROC glad_glGetActiveUniformName = nullptr;
	PFNGLGETACTIVEUNIFORMSIVPROC glad_glGetActiveUniformsiv = nullptr;
	PFNGLGETATTACHEDSHADERSPROC glad_glGetAttachedShaders = nullptr;
	PFNGLGETATTRIBLOCATIONPROC glad_glGetAttribLocation = nullptr;
	PFNGLGETBOOLEANI_VPROC glad_glGetBooleani_v = nullptr;
	PFNGLGETBOOLEANVPROC glad_glGetBooleanv = nullptr;
	PFNGLGETBUFFERPARAMETERI64VPROC glad_glGetBufferParameteri64v = nullptr;
	PFNGLGETBUFFERPARAMETERIVPROC glad_glGetBufferParameteriv = nullptr;
	PFNGLGETBUFFERPOINTERVPROC glad_glGetBufferPointerv = nullptr;
	PFNGLGETBUFFERSUBDATAPROC glad_glGetBufferSubData = nullptr;
	PFNGLGETCOMPRESSEDTEXIMAGEPROC glad_glGetCompressedTexImage = nullptr;
	PFNGLGETDOUBLEVPROC glad_glGetDoublev = nullptr;
	PFNGLGETERRORPROC glad_glGetError = nullptr;
	PFNGLGETFLOATVPROC glad_glGetFloatv = nullptr;
	PFNGLGETFRAGDATAINDEXPROC glad_glGetFragDataIndex = nullptr;
	PFNGLGETFRAGDATALOCATIONPROC glad_glGetFragDataLocation = nullptr;
	PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glad_glGetFramebufferAttachmentParameteriv = nullptr;
	PFNGLGETINTEGER64I_VPROC glad_glGetInteger64i_v = nullptr;
	PFNGLGETINTEGER64VPROC glad_glGetInteger64v = nullptr;
	PFNGLGETINTEGERI_VPROC glad_glGetIntegeri_v = nullptr;
	PFNGLGETINTEGERVPROC glad_glGetIntegerv = nullptr;
	PFNGLGETMULTISAMPLEFVPROC glad_glGetMultisamplefv = nullptr;
	PFNGLGETPROGRAMINFOLOGPROC glad_glGetProgramInfoLog = nullptr;
	PFNGLGETPROGRAMSTAGEIVPROC glad_glGetProgramStageiv = nullptr;
	PFNGLGETPROGRAMIVPROC glad_glGetProgramiv = nullptr;
	PFNGLGETQUERYINDEXEDIVPROC glad_glGetQueryIndexediv = nullptr;
	PFNGLGETQUERYOBJECTI64VPROC glad_glGetQueryObjecti64v = nullptr;
	PFNGLGETQUERYOBJECTIVPROC glad_glGetQueryObjectiv = nullptr;
	PFNGLGETQUERYOBJECTUI64VPROC glad_glGetQueryObjectui64v = nullptr;
	PFNGLGETQUERYOBJECTUIVPROC glad_glGetQueryObjectuiv = nullptr;
	PFNGLGETQUERYIVPROC glad_glGetQueryiv = nullptr;
	PFNGLGETRENDERBUFFERPARAMETERIVPROC glad_glGetRenderbufferParameteriv = nullptr;
	PFNGLGETSAMPLERPARAMETERIIVPROC glad_glGetSamplerParameterIiv = nullptr;
	PFNGLGETSAMPLERPARAMETERIUIVPROC glad_glGetSamplerParameterIuiv = nullptr;
	PFNGLGETSAMPLERPARAMETERFVPROC glad_glGetSamplerParameterfv = nullptr;
	PFNGLGETSAMPLERPARAMETERIVPROC glad_glGetSamplerParameteriv = nullptr;
	PFNGLGETSHADERINFOLOGPROC glad_glGetShaderInfoLog = nullptr;
	PFNGLGETSHADERSOURCEPROC glad_glGetShaderSource = nullptr;
	PFNGLGETSHADERIVPROC glad_glGetShaderiv = nullptr;
	PFNGLGETSTRINGPROC glad_glGetString = nullptr;
	PFNGLGETSTRINGIPROC glad_glGetStringi = nullptr;
	PFNGLGETSUBROUTINEINDEXPROC glad_glGetSubroutineIndex = nullptr;
	PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC glad_glGetSubroutineUniformLocation = nullptr;
	PFNGLGETSYNCIVPROC glad_glGetSynciv = nullptr;
	PFNGLGETTEXIMAGEPROC glad_glGetTexImage = nullptr;
	PFNGLGETTEXLEVELPARAMETERFVPROC glad_glGetTexLevelParameterfv = nullptr;
	PFNGLGETTEXLEVELPARAMETERIVPROC glad_glGetTexLevelParameteriv = nullptr;
	PFNGLGETTEXPARAMETERIIVPROC glad_glGetTexParameterIiv = nullptr;
	PFNGLGETTEXPARAMETERIUIVPROC glad_glGetTexParameterIuiv = nullptr;
	PFNGLGETTEXPARAMETERFVPROC glad_glGetTexParameterfv = nullptr;
	PFNGLGETTEXPARAMETERIVPROC glad_glGetTexParameteriv = nullptr;
	PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glad_glGetTransformFeedbackVarying = nullptr;
	PFNGLGETUNIFORMBLOCKINDEXPROC glad_glGetUniformBlockIndex = nullptr;
	PFNGLGETUNIFORMINDICESPROC glad_glGetUniformIndices = nullptr;
	PFNGLGETUNIFORMLOCATIONPROC glad_glGetUniformLocation = nullptr;
	PFNGLGETUNIFORMSUBROUTINEUIVPROC glad_glGetUniformSubroutineuiv = nullptr;
	PFNGLGETUNIFORMDVPROC glad_glGetUniformdv = nullptr;
	PFNGLGETUNIFORMFVPROC glad_glGetUniformfv = nullptr;
	PFNGLGETUNIFORMIVPROC glad_glGetUniformiv = nullptr;
	PFNGLGETUNIFORMUIVPROC glad_glGetUniformuiv = nullptr;
	PFNGLGETVERTEXATTRIBIIVPROC glad_glGetVertexAttribIiv = nullptr;
	PFNGLGETVERTEXATTRIBIUIVPROC glad_glGetVertexAttribIuiv = nullptr;
	PFNGLGETVERTEXATTRIBPOINTERVPROC glad_glGetVertexAttribPointerv = nullptr;
	PFNGLGETVERTEXATTRIBDVPROC glad_glGetVertexAttribdv = nullptr;
	PFNGLGETVERTEXATTRIBFVPROC glad_glGetVertexAttribfv = nullptr;
	PFNGLGETVERTEXATTRIBIVPROC glad_glGetVertexAttribiv = nullptr;
	PFNGLHINTPROC glad_glHint = nullptr;
	PFNGLISBUFFERPROC glad_glIsBuffer = nullptr;
	PFNGLISENABLEDPROC glad_glIsEnabled = nullptr;
	PFNGLISENABLEDIPROC glad_glIsEnabledi = nullptr;
	PFNGLISFRAMEBUFFERPROC glad_glIsFramebuffer = nullptr;
	PFNGLISPROGRAMPROC glad_glIsProgram = nullptr;
	PFNGLISQUERYPROC glad_glIsQuery = nullptr;
	PFNGLISRENDERBUFFERPROC glad_glIsRenderbuffer = nullptr;
	PFNGLISSAMPLERPROC glad_glIsSampler = nullptr;
	PFNGLISSHADERPROC glad_glIsShader = nullptr;
	PFNGLISSYNCPROC glad_glIsSync = nullptr;
	PFNGLISTEXTUREPROC glad_glIsTexture = nullptr;
	PFNGLISTRANSFORMFEEDBACKPROC glad_glIsTransformFeedback = nullptr;
	PFNGLISVERTEXARRAYPROC glad_glIsVertexArray = nullptr;
	PFNGLLINEWIDTHPROC glad_glLineWidth = nullptr;
	PFNGLLINKPROGRAMPROC glad_glLinkProgram = nullptr;
	PFNGLLOGICOPPROC glad_glLogicOp = nullptr;
	PFNGLMAPBUFFERPROC glad_glMapBuffer = nullptr;
	PFNGLMAPBUFFERRANGEPROC glad_glMapBufferRange = nullptr;
	PFNGLMINSAMPLESHADINGPROC glad_glMinSampleShading = nullptr;
	PFNGLMULTIDRAWARRAYSPROC glad_glMultiDrawArrays = nullptr;
	PFNGLMULTIDRAWELEMENTSPROC glad_glMultiDrawElements = nullptr;
	PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glad_glMultiDrawElementsBaseVertex = nullptr;
	PFNGLMULTITEXCOORDP1UIPROC glad_glMultiTexCoordP1ui = nullptr;
	PFNGLMULTITEXCOORDP1UIVPROC glad_glMultiTexCoordP1uiv = nullptr;
	PFNGLMULTITEXCOORDP2UIPROC glad_glMultiTexCoordP2ui = nullptr;
	PFNGLMULTITEXCOORDP2UIVPROC glad_glMultiTexCoordP2uiv = nullptr;
	PFNGLMULTITEXCOORDP3UIPROC glad_glMultiTexCoordP3ui = nullptr;
	PFNGLMULTITEXCOORDP3UIVPROC glad_glMultiTexCoordP3uiv = nullptr;
	PFNGLMULTITEXCOORDP4UIPROC glad_glMultiTexCoordP4ui = nullptr;
	PFNGLMULTITEXCOORDP4UIVPROC glad_glMultiTexCoordP4uiv = nullptr;
	PFNGLNORMALP3UIPROC glad_glNormalP3ui = nullptr;
	PFNGLNORMALP3UIVPROC glad_glNormalP3uiv = nullptr;
	PFNGLPATCHPARAMETERFVPROC glad_glPatchParameterfv = nullptr;
	PFNGLPATCHPARAMETERIPROC glad_glPatchParameteri = nullptr;
	PFNGLPAUSETRANSFORMFEEDBACKPROC glad_glPauseTransformFeedback = nullptr;
	PFNGLPIXELSTOREFPROC glad_glPixelStoref = nullptr;
	PFNGLPIXELSTOREIPROC glad_glPixelStorei = nullptr;
	PFNGLPOINTPARAMETERFPROC glad_glPointParameterf = nullptr;
	PFNGLPOINTPARAMETERFVPROC glad_glPointParameterfv = nullptr;
	PFNGLPOINTPARAMETERIPROC glad_glPointParameteri = nullptr;
	PFNGLPOINTPARAMETERIVPROC glad_glPointParameteriv = nullptr;
	PFNGLPOINTSIZEPROC glad_glPointSize = nullptr;
	PFNGLPOLYGONMODEPROC glad_glPolygonMode = nullptr;
	PFNGLPOLYGONOFFSETPROC glad_glPolygonOffset = nullptr;
	PFNGLPRIMITIVERESTARTINDEXPROC glad_glPrimitiveRestartIndex = nullptr;
	PFNGLPROVOKINGVERTEXPROC glad_glProvokingVertex = nullptr;
	PFNGLQUERYCOUNTERPROC glad_glQueryCounter = nullptr;
	PFNGLREADBUFFERPROC glad_glReadBuffer = nullptr;
	PFNGLREADPIXELSPROC glad_glReadPixels = nullptr;
	PFNGLRENDERBUFFERSTORAGEPROC glad_glRenderbufferStorage = nullptr;
	PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glad_glRenderbufferStorageMultisample = nullptr;
	PFNGLRESUMETRANSFORMFEEDBACKPROC glad_glResumeTransformFeedback = nullptr;
	PFNGLSAMPLECOVERAGEPROC glad_glSampleCoverage = nullptr;
	PFNGLSAMPLEMASKIPROC glad_glSampleMaski = nullptr;
	PFNGLSAMPLERPARAMETERIIVPROC glad_glSamplerParameterIiv = nullptr;
	PFNGLSAMPLERPARAMETERIUIVPROC glad_glSamplerParameterIuiv = nullptr;
	PFNGLSAMPLERPARAMETERFPROC glad_glSamplerParameterf = nullptr;
	PFNGLSAMPLERPARAMETERFVPROC glad_glSamplerParameterfv = nullptr;
	PFNGLSAMPLERPARAMETERIPROC glad_glSamplerParameteri = nullptr;
	PFNGLSAMPLERPARAMETERIVPROC glad_glSamplerParameteriv = nullptr;
	PFNGLSCISSORPROC glad_glScissor = nullptr;
	PFNGLSECONDARYCOLORP3UIPROC glad_glSecondaryColorP3ui = nullptr;
	PFNGLSECONDARYCOLORP3UIVPROC glad_glSecondaryColorP3uiv = nullptr;
	PFNGLSHADERSOURCEPROC glad_glShaderSource = nullptr;
	PFNGLSTENCILFUNCPROC glad_glStencilFunc = nullptr;
	PFNGLSTENCILFUNCSEPARATEPROC glad_glStencilFuncSeparate = nullptr;
	PFNGLSTENCILMASKPROC glad_glStencilMask = nullptr;
	PFNGLSTENCILMASKSEPARATEPROC glad_glStencilMaskSeparate = nullptr;
	PFNGLSTENCILOPPROC glad_glStencilOp = nullptr;
	PFNGLSTENCILOPSEPARATEPROC glad_glStencilOpSeparate = nullptr;
	PFNGLTEXBUFFERPROC glad_glTexBuffer = nullptr;
	PFNGLTEXCOORDP1UIPROC glad_glTexCoordP1ui = nullptr;
	PFNGLTEXCOORDP1UIVPROC glad_glTexCoordP1uiv = nullptr;
	PFNGLTEXCOORDP2UIPROC glad_glTexCoordP2ui = nullptr;
	PFNGLTEXCOORDP2UIVPROC glad_glTexCoordP2uiv = nullptr;
	PFNGLTEXCOORDP3UIPROC glad_glTexCoordP3ui = nullptr;
	PFNGLTEXCOORDP3UIVPROC glad_glTexCoordP3uiv = nullptr;
	PFNGLTEXCOORDP4UIPROC glad_glTexCoordP4ui = nullptr;
	PFNGLTEXCOORDP4UIVPROC glad_glTexCoordP4uiv = nullptr;
	PFNGLTEXIMAGE1DPROC glad_glTexImage1D = nullptr;
	PFNGLTEXIMAGE2DPROC glad_glTexImage2D = nullptr;
	PFNGLTEXIMAGE2DMULTISAMPLEPROC glad_glTexImage2DMultisample = nullptr;
	PFNGLTEXIMAGE3DPROC glad_glTexImage3D = nullptr;
	PFNGLTEXIMAGE3DMULTISAMPLEPROC glad_glTexImage3DMultisample = nullptr;
	PFNGLTEXPARAMETERIIVPROC glad_glTexParameterIiv = nullptr;
	PFNGLTEXPARAMETERIUIVPROC glad_glTexParameterIuiv = nullptr;
	PFNGLTEXPARAMETERFPROC glad_glTexParameterf = nullptr;
	PFNGLTEXPARAMETERFVPROC glad_glTexParameterfv = nullptr;
	PFNGLTEXPARAMETERIPROC glad_glTexParameteri = nullptr;
	PFNGLTEXPARAMETERIVPROC glad_glTexParameteriv = nullptr;
	PFNGLTEXSUBIMAGE1DPROC glad_glTexSubImage1D = nullptr;
	PFNGLTEXSUBIMAGE2DPROC glad_glTexSubImage2D = nullptr;
	PFNGLTEXSUBIMAGE3DPROC glad_glTexSubImage3D = nullptr;
	PFNGLTRANSFORMFEEDBACKVARYINGSPROC glad_glTransformFeedbackVaryings = nullptr;
	PFNGLUNIFORM1DPROC glad_glUniform1d = nullptr;
	PFNGLUNIFORM1DVPROC glad_glUniform1dv = nullptr;
	PFNGLUNIFORM1FPROC glad_glUniform1f = nullptr;
	PFNGLUNIFORM1FVPROC glad_glUniform1fv = nullptr;
	PFNGLUNIFORM1IPROC glad_glUniform1i = nullptr;
	PFNGLUNIFORM1IVPROC glad_glUniform1iv = nullptr;
	PFNGLUNIFORM1UIPROC glad_glUniform1ui = nullptr;
	PFNGLUNIFORM1UIVPROC glad_glUniform1uiv = nullptr;
	PFNGLUNIFORM2DPROC glad_glUniform2d = nullptr;
	PFNGLUNIFORM2DVPROC glad_glUniform2dv = nullptr;
	PFNGLUNIFORM2FPROC glad_glUniform2f = nullptr;
	PFNGLUNIFORM2FVPROC glad_glUniform2fv = nullptr;
	PFNGLUNIFORM2IPROC glad_glUniform2i = nullptr;
	PFNGLUNIFORM2IVPROC glad_glUniform2iv = nullptr;
	PFNGLUNIFORM2UIPROC glad_glUniform2ui = nullptr;
	PFNGLUNIFORM2UIVPROC glad_glUniform2uiv = nullptr;
	PFNGLUNIFORM3DPROC glad_glUniform3d = nullptr;
	PFNGLUNIFORM3DVPROC glad_glUniform3dv = nullptr;
	PFNGLUNIFORM3FPROC glad_glUniform3f = nullptr;
	PFNGLUNIFORM3FVPROC glad_glUniform3fv = nullptr;
	PFNGLUNIFORM3IPROC glad_glUniform3i = nullptr;
	PFNGLUNIFORM3IVPROC glad_glUniform3iv = nullptr;
	PFNGLUNIFORM3UIPROC glad_glUniform3ui = nullptr;
	PFNGLUNIFORM3UIVPROC glad_glUniform3uiv = nullptr;
	PFNGLUNIFORM4DPROC glad_glUniform4d = nullptr;
	PFNGLUNIFORM4DVPROC glad_glUniform4dv = nullptr;
	PFNGLUNIFORM4FPROC glad_glUniform4f = nullptr;
	PFNGLUNIFORM4FVPROC glad_glUniform4fv = nullptr;
	PFNGLUNIFORM4IPROC glad_glUniform4i = nullptr;
	PFNGLUNIFORM4IVPROC glad_glUniform4iv = nullptr;
	PFNGLUNIFORM4UIPROC glad_glUniform4ui = nullptr;
	PFNGLUNIFORM4UIVPROC glad_glUniform4uiv = nullptr;
	PFNGLUNIFORMBLOCKBINDINGPROC glad_glUniformBlockBinding = nullptr;
	PFNGLUNIFORMMATRIX2DVPROC glad_glUniformMatrix2dv = nullptr;
	PFNGLUNIFORMMATRIX2FVPROC glad_glUniformMatrix2fv = nullptr;
	PFNGLUNIFORMMATRIX2X3DVPROC glad_glUniformMatrix2x3dv = nullptr;
	PFNGLUNIFORMMATRIX2X3FVPROC glad_glUniformMatrix2x3fv = nullptr;
	PFNGLUNIFORMMATRIX2X4DVPROC glad_glUniformMatrix2x4dv = nullptr;
	PFNGLUNIFORMMATRIX2X4FVPROC glad_glUniformMatrix2x4fv = nullptr;
	PFNGLUNIFORMMATRIX3DVPROC glad_glUniformMatrix3dv = nullptr;
	PFNGLUNIFORMMATRIX3FVPROC glad_glUniformMatrix3fv = nullptr;
	PFNGLUNIFORMMATRIX3X2DVPROC glad_glUniformMatrix3x2dv = nullptr;
	PFNGLUNIFORMMATRIX3X2FVPROC glad_glUniformMatrix3x2fv = nullptr;
	PFNGLUNIFORMMATRIX3X4DVPROC glad_glUniformMatrix3x4dv = nullptr;
	PFNGLUNIFORMMATRIX3X4FVPROC glad_glUniformMatrix3x4fv = nullptr;
	PFNGLUNIFORMMATRIX4DVPROC glad_glUniformMatrix4dv = nullptr;
	PFNGLUNIFORMMATRIX4FVPROC glad_glUniformMatrix4fv = nullptr;
	PFNGLUNIFORMMATRIX4X2DVPROC glad_glUniformMatrix4x2dv = nullptr;
	PFNGLUNIFORMMATRIX4X2FVPROC glad_glUniformMatrix4x2fv = nullptr;
	PFNGLUNIFORMMATRIX4X3DVPROC glad_glUniformMatrix4x3dv = nullptr;
	PFNGLUNIFORMMATRIX4X3FVPROC glad_glUniformMatrix4x3fv = nullptr;
	PFNGLUNIFORMSUBROUTINESUIVPROC glad_glUniformSubroutinesuiv = nullptr;
	PFNGLUNMAPBUFFERPROC glad_glUnmapBuffer = nullptr;
	PFNGLUSEPROGRAMPROC glad_glUseProgram = nullptr;
	PFNGLVALIDATEPROGRAMPROC glad_glValidateProgram = nullptr;
	PFNGLVERTEXATTRIB1DPROC glad_glVertexAttrib1d = nullptr;
	PFNGLVERTEXATTRIB1DVPROC glad_glVertexAttrib1dv = nullptr;
	PFNGLVERTEXATTRIB1FPROC glad_glVertexAttrib1f = nullptr;
	PFNGLVERTEXATTRIB1FVPROC glad_glVertexAttrib1fv = nullptr;
	PFNGLVERTEXATTRIB1SPROC glad_glVertexAttrib1s = nullptr;
	PFNGLVERTEXATTRIB1SVPROC glad_glVertexAttrib1sv = nullptr;
	PFNGLVERTEXATTRIB2DPROC glad_glVertexAttrib2d = nullptr;
	PFNGLVERTEXATTRIB2DVPROC glad_glVertexAttrib2dv = nullptr;
	PFNGLVERTEXATTRIB2FPROC glad_glVertexAttrib2f = nullptr;
	PFNGLVERTEXATTRIB2FVPROC glad_glVertexAttrib2fv = nullptr;
	PFNGLVERTEXATTRIB2SPROC glad_glVertexAttrib2s = nullptr;
	PFNGLVERTEXATTRIB2SVPROC glad_glVertexAttrib2sv = nullptr;
	PFNGLVERTEXATTRIB3DPROC glad_glVertexAttrib3d = nullptr;
	PFNGLVERTEXATTRIB3DVPROC glad_glVertexAttrib3dv = nullptr;
	PFNGLVERTEXATTRIB3FPROC glad_glVertexAttrib3f = nullptr;
	PFNGLVERTEXATTRIB3FVPROC glad_glVertexAttrib3fv = nullptr;
	PFNGLVERTEXATTRIB3SPROC glad_glVertexAttrib3s = nullptr;
	PFNGLVERTEXATTRIB3SVPROC glad_glVertexAttrib3sv = nullptr;
	PFNGLVERTEXATTRIB4NBVPROC glad_glVertexAttrib4Nbv = nullptr;
	PFNGLVERTEXATTRIB4NIVPROC glad_glVertexAttrib4Niv = nullptr;
	PFNGLVERTEXATTRIB4NSVPROC glad_glVertexAttrib4Nsv = nullptr;
	PFNGLVERTEXATTRIB4NUBPROC glad_glVertexAttrib4Nub = nullptr;
	PFNGLVERTEXATTRIB4NUBVPROC glad_glVertexAttrib4Nubv = nullptr;
	PFNGLVERTEXATTRIB4NUIVPROC glad_glVertexAttrib4Nuiv = nullptr;
	PFNGLVERTEXATTRIB4NUSVPROC glad_glVertexAttrib4Nusv = nullptr;
	PFNGLVERTEXATTRIB4BVPROC glad_glVertexAttrib4bv = nullptr;
	PFNGLVERTEXATTRIB4DPROC glad_glVertexAttrib4d = nullptr;
	PFNGLVERTEXATTRIB4DVPROC glad_glVertexAttrib4dv = nullptr;
	PFNGLVERTEXATTRIB4FPROC glad_glVertexAttrib4f = nullptr;
	PFNGLVERTEXATTRIB4FVPROC glad_glVertexAttrib4fv = nullptr;
	PFNGLVERTEXATTRIB4IVPROC glad_glVertexAttrib4iv = nullptr;
	PFNGLVERTEXATTRIB4SPROC glad_glVertexAttrib4s = nullptr;
	PFNGLVERTEXATTRIB4SVPROC glad_glVertexAttrib4sv = nullptr;
	PFNGLVERTEXATTRIB4UBVPROC glad_glVertexAttrib4ubv = nullptr;
	PFNGLVERTEXATTRIB4UIVPROC glad_glVertexAttrib4uiv = nullptr;
	PFNGLVERTEXATTRIB4USVPROC glad_glVertexAttrib4usv = nullptr;
	PFNGLVERTEXATTRIBDIVISORPROC glad_glVertexAttribDivisor = nullptr;
	PFNGLVERTEXATTRIBI1IPROC glad_glVertexAttribI1i = nullptr;
	PFNGLVERTEXATTRIBI1IVPROC glad_glVertexAttribI1iv = nullptr;
	PFNGLVERTEXATTRIBI1UIPROC glad_glVertexAttribI1ui = nullptr;
	PFNGLVERTEXATTRIBI1UIVPROC glad_glVertexAttribI1uiv = nullptr;
	PFNGLVERTEXATTRIBI2IPROC glad_glVertexAttribI2i = nullptr;
	PFNGLVERTEXATTRIBI2IVPROC glad_glVertexAttribI2iv = nullptr;
	PFNGLVERTEXATTRIBI2UIPROC glad_glVertexAttribI2ui = nullptr;
	PFNGLVERTEXATTRIBI2UIVPROC glad_glVertexAttribI2uiv = nullptr;
	PFNGLVERTEXATTRIBI3IPROC glad_glVertexAttribI3i = nullptr;
	PFNGLVERTEXATTRIBI3IVPROC glad_glVertexAttribI3iv = nullptr;
	PFNGLVERTEXATTRIBI3UIPROC glad_glVertexAttribI3ui = nullptr;
	PFNGLVERTEXATTRIBI3UIVPROC glad_glVertexAttribI3uiv = nullptr;
	PFNGLVERTEXATTRIBI4BVPROC glad_glVertexAttribI4bv = nullptr;
	PFNGLVERTEXATTRIBI4IPROC glad_glVertexAttribI4i = nullptr;
	PFNGLVERTEXATTRIBI4IVPROC glad_glVertexAttribI4iv = nullptr;
	PFNGLVERTEXATTRIBI4SVPROC glad_glVertexAttribI4sv = nullptr;
	PFNGLVERTEXATTRIBI4UBVPROC glad_glVertexAttribI4ubv = nullptr;
	PFNGLVERTEXATTRIBI4UIPROC glad_glVertexAttribI4ui = nullptr;
	PFNGLVERTEXATTRIBI4UIVPROC glad_glVertexAttribI4uiv = nullptr;
	PFNGLVERTEXATTRIBI4USVPROC glad_glVertexAttribI4usv = nullptr;
	PFNGLVERTEXATTRIBIPOINTERPROC glad_glVertexAttribIPointer = nullptr;
	PFNGLVERTEXATTRIBP1UIPROC glad_glVertexAttribP1ui = nullptr;
	PFNGLVERTEXATTRIBP1UIVPROC glad_glVertexAttribP1uiv = nullptr;
	PFNGLVERTEXATTRIBP2UIPROC glad_glVertexAttribP2ui = nullptr;
	PFNGLVERTEXATTRIBP2UIVPROC glad_glVertexAttribP2uiv = nullptr;
	PFNGLVERTEXATTRIBP3UIPROC glad_glVertexAttribP3ui = nullptr;
	PFNGLVERTEXATTRIBP3UIVPROC glad_glVertexAttribP3uiv = nullptr;
	PFNGLVERTEXATTRIBP4UIPROC glad_glVertexAttribP4ui = nullptr;
	PFNGLVERTEXATTRIBP4UIVPROC glad_glVertexAttribP4uiv = nullptr;
	PFNGLVERTEXATTRIBPOINTERPROC glad_glVertexAttribPointer = nullptr;
	PFNGLVERTEXP2UIPROC glad_glVertexP2ui = nullptr;
	PFNGLVERTEXP2UIVPROC glad_glVertexP2uiv = nullptr;
	PFNGLVERTEXP3UIPROC glad_glVertexP3ui = nullptr;
	PFNGLVERTEXP3UIVPROC glad_glVertexP3uiv = nullptr;
	PFNGLVERTEXP4UIPROC glad_glVertexP4ui = nullptr;
	PFNGLVERTEXP4UIVPROC glad_glVertexP4uiv = nullptr;
	PFNGLVIEWPORTPROC glad_glViewport = nullptr;
	PFNGLWAITSYNCPROC glad_glWaitSync = nullptr;
	static void load_GL_VERSION_1_0(GLADloadproc load) {
		if(!GLAD_GL_VERSION_1_0) return;
		glad_glCullFace = static_cast<PFNGLCULLFACEPROC>(load("glCullFace"));
		glad_glFrontFace = static_cast<PFNGLFRONTFACEPROC>(load("glFrontFace"));
		glad_glHint = static_cast<PFNGLHINTPROC>(load("glHint"));
		glad_glLineWidth = static_cast<PFNGLLINEWIDTHPROC>(load("glLineWidth"));
		glad_glPointSize = static_cast<PFNGLPOINTSIZEPROC>(load("glPointSize"));
		glad_glPolygonMode = static_cast<PFNGLPOLYGONMODEPROC>(load("glPolygonMode"));
		glad_glScissor = static_cast<PFNGLSCISSORPROC>(load("glScissor"));
		glad_glTexParameterf = static_cast<PFNGLTEXPARAMETERFPROC>(load("glTexParameterf"));
		glad_glTexParameterfv = static_cast<PFNGLTEXPARAMETERFVPROC>(load("glTexParameterfv"));
		glad_glTexParameteri = static_cast<PFNGLTEXPARAMETERIPROC>(load("glTexParameteri"));
		glad_glTexParameteriv = static_cast<PFNGLTEXPARAMETERIVPROC>(load("glTexParameteriv"));
		glad_glTexImage1D = static_cast<PFNGLTEXIMAGE1DPROC>(load("glTexImage1D"));
		glad_glTexImage2D = static_cast<PFNGLTEXIMAGE2DPROC>(load("glTexImage2D"));
		glad_glDrawBuffer = static_cast<PFNGLDRAWBUFFERPROC>(load("glDrawBuffer"));
		glad_glClear = static_cast<PFNGLCLEARPROC>(load("glClear"));
		glad_glClearColor = static_cast<PFNGLCLEARCOLORPROC>(load("glClearColor"));
		glad_glClearStencil = static_cast<PFNGLCLEARSTENCILPROC>(load("glClearStencil"));
		glad_glClearDepth = static_cast<PFNGLCLEARDEPTHPROC>(load("glClearDepth"));
		glad_glStencilMask = static_cast<PFNGLSTENCILMASKPROC>(load("glStencilMask"));
		glad_glColorMask = static_cast<PFNGLCOLORMASKPROC>(load("glColorMask"));
		glad_glDepthMask = static_cast<PFNGLDEPTHMASKPROC>(load("glDepthMask"));
		glad_glDisable = static_cast<PFNGLDISABLEPROC>(load("glDisable"));
		glad_glEnable = static_cast<PFNGLENABLEPROC>(load("glEnable"));
		glad_glFinish = static_cast<PFNGLFINISHPROC>(load("glFinish"));
		glad_glFlush = static_cast<PFNGLFLUSHPROC>(load("glFlush"));
		glad_glBlendFunc = static_cast<PFNGLBLENDFUNCPROC>(load("glBlendFunc"));
		glad_glLogicOp = static_cast<PFNGLLOGICOPPROC>(load("glLogicOp"));
		glad_glStencilFunc = static_cast<PFNGLSTENCILFUNCPROC>(load("glStencilFunc"));
		glad_glStencilOp = static_cast<PFNGLSTENCILOPPROC>(load("glStencilOp"));
		glad_glDepthFunc = static_cast<PFNGLDEPTHFUNCPROC>(load("glDepthFunc"));
		glad_glPixelStoref = static_cast<PFNGLPIXELSTOREFPROC>(load("glPixelStoref"));
		glad_glPixelStorei = static_cast<PFNGLPIXELSTOREIPROC>(load("glPixelStorei"));
		glad_glReadBuffer = static_cast<PFNGLREADBUFFERPROC>(load("glReadBuffer"));
		glad_glReadPixels = static_cast<PFNGLREADPIXELSPROC>(load("glReadPixels"));
		glad_glGetBooleanv = static_cast<PFNGLGETBOOLEANVPROC>(load("glGetBooleanv"));
		glad_glGetDoublev = static_cast<PFNGLGETDOUBLEVPROC>(load("glGetDoublev"));
		glad_glGetError = static_cast<PFNGLGETERRORPROC>(load("glGetError"));
		glad_glGetFloatv = static_cast<PFNGLGETFLOATVPROC>(load("glGetFloatv"));
		glad_glGetIntegerv = static_cast<PFNGLGETINTEGERVPROC>(load("glGetIntegerv"));
		glad_glGetString = static_cast<PFNGLGETSTRINGPROC>(load("glGetString"));
		glad_glGetTexImage = static_cast<PFNGLGETTEXIMAGEPROC>(load("glGetTexImage"));
		glad_glGetTexParameterfv = static_cast<PFNGLGETTEXPARAMETERFVPROC>(load("glGetTexParameterfv"));
		glad_glGetTexParameteriv = static_cast<PFNGLGETTEXPARAMETERIVPROC>(load("glGetTexParameteriv"));
		glad_glGetTexLevelParameterfv = static_cast<PFNGLGETTEXLEVELPARAMETERFVPROC>(load("glGetTexLevelParameterfv"));
		glad_glGetTexLevelParameteriv = static_cast<PFNGLGETTEXLEVELPARAMETERIVPROC>(load("glGetTexLevelParameteriv"));
		glad_glIsEnabled = static_cast<PFNGLISENABLEDPROC>(load("glIsEnabled"));
		glad_glDepthRange = static_cast<PFNGLDEPTHRANGEPROC>(load("glDepthRange"));
		glad_glViewport = static_cast<PFNGLVIEWPORTPROC>(load("glViewport"));
	}
    static void load_GL_VERSION_1_1(GLADloadproc load) {
        if (!GLAD_GL_VERSION_1_1) return;
        glad_glDrawArrays = static_cast<PFNGLDRAWARRAYSPROC>(load("glDrawArrays"));
        glad_glDrawElements = static_cast<PFNGLDRAWELEMENTSPROC>(load("glDrawElements"));
        glad_glPolygonOffset = static_cast<PFNGLPOLYGONOFFSETPROC>(load("glPolygonOffset"));
        glad_glCopyTexImage1D = static_cast<PFNGLCOPYTEXIMAGE1DPROC>(load("glCopyTexImage1D"));
        glad_glCopyTexImage2D = static_cast<PFNGLCOPYTEXIMAGE2DPROC>(load("glCopyTexImage2D"));
        glad_glCopyTexSubImage1D = static_cast<PFNGLCOPYTEXSUBIMAGE1DPROC>(load("glCopyTexSubImage1D"));
        glad_glCopyTexSubImage2D = static_cast<PFNGLCOPYTEXSUBIMAGE2DPROC>(load("glCopyTexSubImage2D"));
        glad_glTexSubImage1D = static_cast<PFNGLTEXSUBIMAGE1DPROC>(load("glTexSubImage1D"));
        glad_glTexSubImage2D = static_cast<PFNGLTEXSUBIMAGE2DPROC>(load("glTexSubImage2D"));
        glad_glBindTexture = static_cast<PFNGLBINDTEXTUREPROC>(load("glBindTexture"));
        glad_glDeleteTextures = static_cast<PFNGLDELETETEXTURESPROC>(load("glDeleteTextures"));
        glad_glGenTextures = static_cast<PFNGLGENTEXTURESPROC>(load("glGenTextures"));
        glad_glIsTexture = static_cast<PFNGLISTEXTUREPROC>(load("glIsTexture"));
    }
    static void load_GL_VERSION_1_2(GLADloadproc load) {
        if (!GLAD_GL_VERSION_1_2) return;
        glad_glDrawRangeElements = static_cast<PFNGLDRAWRANGEELEMENTSPROC>(load("glDrawRangeElements"));
        glad_glTexImage3D = static_cast<PFNGLTEXIMAGE3DPROC>(load("glTexImage3D"));
        glad_glTexSubImage3D = static_cast<PFNGLTEXSUBIMAGE3DPROC>(load("glTexSubImage3D"));
        glad_glCopyTexSubImage3D = static_cast<PFNGLCOPYTEXSUBIMAGE3DPROC>(load("glCopyTexSubImage3D"));
    }
    static void load_GL_VERSION_1_3(GLADloadproc load) {
        if (!GLAD_GL_VERSION_1_3) return;
        glad_glActiveTexture = static_cast<PFNGLACTIVETEXTUREPROC>(load("glActiveTexture"));
        glad_glSampleCoverage = static_cast<PFNGLSAMPLECOVERAGEPROC>(load("glSampleCoverage"));
        glad_glCompressedTexImage3D = static_cast<PFNGLCOMPRESSEDTEXIMAGE3DPROC>(load("glCompressedTexImage3D"));
        glad_glCompressedTexImage2D = static_cast<PFNGLCOMPRESSEDTEXIMAGE2DPROC>(load("glCompressedTexImage2D"));
        glad_glCompressedTexImage1D = static_cast<PFNGLCOMPRESSEDTEXIMAGE1DPROC>(load("glCompressedTexImage1D"));
        glad_glCompressedTexSubImage3D = static_cast<PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC>(load("glCompressedTexSubImage3D"));
        glad_glCompressedTexSubImage2D = static_cast<PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC>(load("glCompressedTexSubImage2D"));
        glad_glCompressedTexSubImage1D = static_cast<PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC>(load("glCompressedTexSubImage1D"));
        glad_glGetCompressedTexImage = static_cast<PFNGLGETCOMPRESSEDTEXIMAGEPROC>(load("glGetCompressedTexImage"));
    }
    static void load_GL_VERSION_1_4(GLADloadproc load) {
        if (!GLAD_GL_VERSION_1_4) return;
        glad_glBlendFuncSeparate = static_cast<PFNGLBLENDFUNCSEPARATEPROC>(load("glBlendFuncSeparate"));
        glad_glMultiDrawArrays = static_cast<PFNGLMULTIDRAWARRAYSPROC>(load("glMultiDrawArrays"));
        glad_glMultiDrawElements = static_cast<PFNGLMULTIDRAWELEMENTSPROC>(load("glMultiDrawElements"));
        glad_glPointParameterf = static_cast<PFNGLPOINTPARAMETERFPROC>(load("glPointParameterf"));
        glad_glPointParameterfv = static_cast<PFNGLPOINTPARAMETERFVPROC>(load("glPointParameterfv"));
        glad_glPointParameteri = static_cast<PFNGLPOINTPARAMETERIPROC>(load("glPointParameteri"));
        glad_glPointParameteriv = static_cast<PFNGLPOINTPARAMETERIVPROC>(load("glPointParameteriv"));
        glad_glBlendColor = static_cast<PFNGLBLENDCOLORPROC>(load("glBlendColor"));
        glad_glBlendEquation = static_cast<PFNGLBLENDEQUATIONPROC>(load("glBlendEquation"));
    }
    static void load_GL_VERSION_1_5(GLADloadproc load) {
        if (!GLAD_GL_VERSION_1_5) return;
        glad_glGenQueries = static_cast<PFNGLGENQUERIESPROC>(load("glGenQueries"));
        glad_glDeleteQueries = static_cast<PFNGLDELETEQUERIESPROC>(load("glDeleteQueries"));
        glad_glIsQuery = static_cast<PFNGLISQUERYPROC>(load("glIsQuery"));
        glad_glBeginQuery = static_cast<PFNGLBEGINQUERYPROC>(load("glBeginQuery"));
        glad_glEndQuery = static_cast<PFNGLENDQUERYPROC>(load("glEndQuery"));
        glad_glGetQueryiv = static_cast<PFNGLGETQUERYIVPROC>(load("glGetQueryiv"));
        glad_glGetQueryObjectiv = static_cast<PFNGLGETQUERYOBJECTIVPROC>(load("glGetQueryObjectiv"));
        glad_glGetQueryObjectuiv = static_cast<PFNGLGETQUERYOBJECTUIVPROC>(load("glGetQueryObjectuiv"));
        glad_glBindBuffer = static_cast<PFNGLBINDBUFFERPROC>(load("glBindBuffer"));
        glad_glDeleteBuffers = static_cast<PFNGLDELETEBUFFERSPROC>(load("glDeleteBuffers"));
        glad_glGenBuffers = static_cast<PFNGLGENBUFFERSPROC>(load("glGenBuffers"));
        glad_glIsBuffer = static_cast<PFNGLISBUFFERPROC>(load("glIsBuffer"));
        glad_glBufferData = static_cast<PFNGLBUFFERDATAPROC>(load("glBufferData"));
        glad_glBufferSubData = static_cast<PFNGLBUFFERSUBDATAPROC>(load("glBufferSubData"));
        glad_glGetBufferSubData = static_cast<PFNGLGETBUFFERSUBDATAPROC>(load("glGetBufferSubData"));
        glad_glMapBuffer = static_cast<PFNGLMAPBUFFERPROC>(load("glMapBuffer"));
        glad_glUnmapBuffer = static_cast<PFNGLUNMAPBUFFERPROC>(load("glUnmapBuffer"));
        glad_glGetBufferParameteriv = static_cast<PFNGLGETBUFFERPARAMETERIVPROC>(load("glGetBufferParameteriv"));
        glad_glGetBufferPointerv = static_cast<PFNGLGETBUFFERPOINTERVPROC>(load("glGetBufferPointerv"));
    }
    static void load_GL_VERSION_2_0(GLADloadproc load) {
        if (!GLAD_GL_VERSION_2_0) return;
        glad_glBlendEquationSeparate = static_cast<PFNGLBLENDEQUATIONSEPARATEPROC>(load("glBlendEquationSeparate"));
        glad_glDrawBuffers = static_cast<PFNGLDRAWBUFFERSPROC>(load("glDrawBuffers"));
        glad_glStencilOpSeparate = static_cast<PFNGLSTENCILOPSEPARATEPROC>(load("glStencilOpSeparate"));
        glad_glStencilFuncSeparate = static_cast<PFNGLSTENCILFUNCSEPARATEPROC>(load("glStencilFuncSeparate"));
        glad_glStencilMaskSeparate = static_cast<PFNGLSTENCILMASKSEPARATEPROC>(load("glStencilMaskSeparate"));
        glad_glAttachShader = static_cast<PFNGLATTACHSHADERPROC>(load("glAttachShader"));
        glad_glBindAttribLocation = static_cast<PFNGLBINDATTRIBLOCATIONPROC>(load("glBindAttribLocation"));
        glad_glCompileShader = static_cast<PFNGLCOMPILESHADERPROC>(load("glCompileShader"));
        glad_glCreateProgram = static_cast<PFNGLCREATEPROGRAMPROC>(load("glCreateProgram"));
        glad_glCreateShader = static_cast<PFNGLCREATESHADERPROC>(load("glCreateShader"));
        glad_glDeleteProgram = static_cast<PFNGLDELETEPROGRAMPROC>(load("glDeleteProgram"));
        glad_glDeleteShader = static_cast<PFNGLDELETESHADERPROC>(load("glDeleteShader"));
        glad_glDetachShader = static_cast<PFNGLDETACHSHADERPROC>(load("glDetachShader"));
        glad_glDisableVertexAttribArray = static_cast<PFNGLDISABLEVERTEXATTRIBARRAYPROC>(load("glDisableVertexAttribArray"));
        glad_glEnableVertexAttribArray = static_cast<PFNGLENABLEVERTEXATTRIBARRAYPROC>(load("glEnableVertexAttribArray"));
        glad_glGetActiveAttrib = static_cast<PFNGLGETACTIVEATTRIBPROC>(load("glGetActiveAttrib"));
        glad_glGetActiveUniform = static_cast<PFNGLGETACTIVEUNIFORMPROC>(load("glGetActiveUniform"));
        glad_glGetAttachedShaders = static_cast<PFNGLGETATTACHEDSHADERSPROC>(load("glGetAttachedShaders"));
        glad_glGetAttribLocation = static_cast<PFNGLGETATTRIBLOCATIONPROC>(load("glGetAttribLocation"));
        glad_glGetProgramiv = static_cast<PFNGLGETPROGRAMIVPROC>(load("glGetProgramiv"));
        glad_glGetProgramInfoLog = static_cast<PFNGLGETPROGRAMINFOLOGPROC>(load("glGetProgramInfoLog"));
        glad_glGetShaderiv = static_cast<PFNGLGETSHADERIVPROC>(load("glGetShaderiv"));
        glad_glGetShaderInfoLog = static_cast<PFNGLGETSHADERINFOLOGPROC>(load("glGetShaderInfoLog"));
        glad_glGetShaderSource = static_cast<PFNGLGETSHADERSOURCEPROC>(load("glGetShaderSource"));
        glad_glGetUniformLocation = static_cast<PFNGLGETUNIFORMLOCATIONPROC>(load("glGetUniformLocation"));
        glad_glGetUniformfv = static_cast<PFNGLGETUNIFORMFVPROC>(load("glGetUniformfv"));
        glad_glGetUniformiv = static_cast<PFNGLGETUNIFORMIVPROC>(load("glGetUniformiv"));
        glad_glGetVertexAttribdv = static_cast<PFNGLGETVERTEXATTRIBDVPROC>(load("glGetVertexAttribdv"));
        glad_glGetVertexAttribfv = static_cast<PFNGLGETVERTEXATTRIBFVPROC>(load("glGetVertexAttribfv"));
        glad_glGetVertexAttribiv = static_cast<PFNGLGETVERTEXATTRIBIVPROC>(load("glGetVertexAttribiv"));
        glad_glGetVertexAttribPointerv = static_cast<PFNGLGETVERTEXATTRIBPOINTERVPROC>(load("glGetVertexAttribPointerv"));
        glad_glIsProgram = static_cast<PFNGLISPROGRAMPROC>(load("glIsProgram"));
        glad_glIsShader = static_cast<PFNGLISSHADERPROC>(load("glIsShader"));
        glad_glLinkProgram = static_cast<PFNGLLINKPROGRAMPROC>(load("glLinkProgram"));
        glad_glShaderSource = static_cast<PFNGLSHADERSOURCEPROC>(load("glShaderSource"));
        glad_glUseProgram = static_cast<PFNGLUSEPROGRAMPROC>(load("glUseProgram"));
        glad_glUniform1f = static_cast<PFNGLUNIFORM1FPROC>(load("glUniform1f"));
        glad_glUniform2f = static_cast<PFNGLUNIFORM2FPROC>(load("glUniform2f"));
        glad_glUniform3f = static_cast<PFNGLUNIFORM3FPROC>(load("glUniform3f"));
        glad_glUniform4f = static_cast<PFNGLUNIFORM4FPROC>(load("glUniform4f"));
        glad_glUniform1i = static_cast<PFNGLUNIFORM1IPROC>(load("glUniform1i"));
        glad_glUniform2i = static_cast<PFNGLUNIFORM2IPROC>(load("glUniform2i"));
        glad_glUniform3i = static_cast<PFNGLUNIFORM3IPROC>(load("glUniform3i"));
        glad_glUniform4i = static_cast<PFNGLUNIFORM4IPROC>(load("glUniform4i"));
        glad_glUniform1fv = static_cast<PFNGLUNIFORM1FVPROC>(load("glUniform1fv"));
        glad_glUniform2fv = static_cast<PFNGLUNIFORM2FVPROC>(load("glUniform2fv"));
        glad_glUniform3fv = static_cast<PFNGLUNIFORM3FVPROC>(load("glUniform3fv"));
        glad_glUniform4fv = static_cast<PFNGLUNIFORM4FVPROC>(load("glUniform4fv"));
        glad_glUniform1iv = static_cast<PFNGLUNIFORM1IVPROC>(load("glUniform1iv"));
        glad_glUniform2iv = static_cast<PFNGLUNIFORM2IVPROC>(load("glUniform2iv"));
        glad_glUniform3iv = static_cast<PFNGLUNIFORM3IVPROC>(load("glUniform3iv"));
        glad_glUniform4iv = static_cast<PFNGLUNIFORM4IVPROC>(load("glUniform4iv"));
        glad_glUniformMatrix2fv = static_cast<PFNGLUNIFORMMATRIX2FVPROC>(load("glUniformMatrix2fv"));
        glad_glUniformMatrix3fv = static_cast<PFNGLUNIFORMMATRIX3FVPROC>(load("glUniformMatrix3fv"));
        glad_glUniformMatrix4fv = static_cast<PFNGLUNIFORMMATRIX4FVPROC>(load("glUniformMatrix4fv"));
        glad_glValidateProgram = static_cast<PFNGLVALIDATEPROGRAMPROC>(load("glValidateProgram"));
        glad_glVertexAttrib1d = static_cast<PFNGLVERTEXATTRIB1DPROC>(load("glVertexAttrib1d"));
        glad_glVertexAttrib1dv = static_cast<PFNGLVERTEXATTRIB1DVPROC>(load("glVertexAttrib1dv"));
        glad_glVertexAttrib1f = static_cast<PFNGLVERTEXATTRIB1FPROC>(load("glVertexAttrib1f"));
        glad_glVertexAttrib1fv = static_cast<PFNGLVERTEXATTRIB1FVPROC>(load("glVertexAttrib1fv"));
        glad_glVertexAttrib1s = static_cast<PFNGLVERTEXATTRIB1SPROC>(load("glVertexAttrib1s"));
        glad_glVertexAttrib1sv = static_cast<PFNGLVERTEXATTRIB1SVPROC>(load("glVertexAttrib1sv"));
        glad_glVertexAttrib2d = static_cast<PFNGLVERTEXATTRIB2DPROC>(load("glVertexAttrib2d"));
        glad_glVertexAttrib2dv = static_cast<PFNGLVERTEXATTRIB2DVPROC>(load("glVertexAttrib2dv"));
        glad_glVertexAttrib2f = static_cast<PFNGLVERTEXATTRIB2FPROC>(load("glVertexAttrib2f"));
        glad_glVertexAttrib2fv = static_cast<PFNGLVERTEXATTRIB2FVPROC>(load("glVertexAttrib2fv"));
        glad_glVertexAttrib2s = static_cast<PFNGLVERTEXATTRIB2SPROC>(load("glVertexAttrib2s"));
        glad_glVertexAttrib2sv = static_cast<PFNGLVERTEXATTRIB2SVPROC>(load("glVertexAttrib2sv"));
        glad_glVertexAttrib3d = static_cast<PFNGLVERTEXATTRIB3DPROC>(load("glVertexAttrib3d"));
        glad_glVertexAttrib3dv = static_cast<PFNGLVERTEXATTRIB3DVPROC>(load("glVertexAttrib3dv"));
        glad_glVertexAttrib3f = static_cast<PFNGLVERTEXATTRIB3FPROC>(load("glVertexAttrib3f"));
        glad_glVertexAttrib3fv = static_cast<PFNGLVERTEXATTRIB3FVPROC>(load("glVertexAttrib3fv"));
        glad_glVertexAttrib3s = static_cast<PFNGLVERTEXATTRIB3SPROC>(load("glVertexAttrib3s"));
        glad_glVertexAttrib3sv = static_cast<PFNGLVERTEXATTRIB3SVPROC>(load("glVertexAttrib3sv"));
        glad_glVertexAttrib4Nbv = static_cast<PFNGLVERTEXATTRIB4NBVPROC>(load("glVertexAttrib4Nbv"));
        glad_glVertexAttrib4Niv = static_cast<PFNGLVERTEXATTRIB4NIVPROC>(load("glVertexAttrib4Niv"));
        glad_glVertexAttrib4Nsv = static_cast<PFNGLVERTEXATTRIB4NSVPROC>(load("glVertexAttrib4Nsv"));
        glad_glVertexAttrib4Nub = static_cast<PFNGLVERTEXATTRIB4NUBPROC>(load("glVertexAttrib4Nub"));
        glad_glVertexAttrib4Nubv = static_cast<PFNGLVERTEXATTRIB4NUBVPROC>(load("glVertexAttrib4Nubv"));
        glad_glVertexAttrib4Nuiv = static_cast<PFNGLVERTEXATTRIB4NUIVPROC>(load("glVertexAttrib4Nuiv"));
        glad_glVertexAttrib4Nusv = static_cast<PFNGLVERTEXATTRIB4NUSVPROC>(load("glVertexAttrib4Nusv"));
        glad_glVertexAttrib4bv = static_cast<PFNGLVERTEXATTRIB4BVPROC>(load("glVertexAttrib4bv"));
        glad_glVertexAttrib4d = static_cast<PFNGLVERTEXATTRIB4DPROC>(load("glVertexAttrib4d"));
        glad_glVertexAttrib4dv = static_cast<PFNGLVERTEXATTRIB4DVPROC>(load("glVertexAttrib4dv"));
        glad_glVertexAttrib4f = static_cast<PFNGLVERTEXATTRIB4FPROC>(load("glVertexAttrib4f"));
        glad_glVertexAttrib4fv = static_cast<PFNGLVERTEXATTRIB4FVPROC>(load("glVertexAttrib4fv"));
        glad_glVertexAttrib4iv = static_cast<PFNGLVERTEXATTRIB4IVPROC>(load("glVertexAttrib4iv"));
        glad_glVertexAttrib4s = static_cast<PFNGLVERTEXATTRIB4SPROC>(load("glVertexAttrib4s"));
        glad_glVertexAttrib4sv = static_cast<PFNGLVERTEXATTRIB4SVPROC>(load("glVertexAttrib4sv"));
        glad_glVertexAttrib4ubv = static_cast<PFNGLVERTEXATTRIB4UBVPROC>(load("glVertexAttrib4ubv"));
        glad_glVertexAttrib4uiv = static_cast<PFNGLVERTEXATTRIB4UIVPROC>(load("glVertexAttrib4uiv"));
        glad_glVertexAttrib4usv = static_cast<PFNGLVERTEXATTRIB4USVPROC>(load("glVertexAttrib4usv"));
        glad_glVertexAttribPointer = static_cast<PFNGLVERTEXATTRIBPOINTERPROC>(load("glVertexAttribPointer"));
    }
    static void load_GL_VERSION_2_1(GLADloadproc load) {
        if (!GLAD_GL_VERSION_2_1) return;
        glad_glUniformMatrix2x3fv = static_cast<PFNGLUNIFORMMATRIX2X3FVPROC>(load("glUniformMatrix2x3fv"));
        glad_glUniformMatrix3x2fv = static_cast<PFNGLUNIFORMMATRIX3X2FVPROC>(load("glUniformMatrix3x2fv"));
        glad_glUniformMatrix2x4fv = static_cast<PFNGLUNIFORMMATRIX2X4FVPROC>(load("glUniformMatrix2x4fv"));
        glad_glUniformMatrix4x2fv = static_cast<PFNGLUNIFORMMATRIX4X2FVPROC>(load("glUniformMatrix4x2fv"));
        glad_glUniformMatrix3x4fv = static_cast<PFNGLUNIFORMMATRIX3X4FVPROC>(load("glUniformMatrix3x4fv"));
        glad_glUniformMatrix4x3fv = static_cast<PFNGLUNIFORMMATRIX4X3FVPROC>(load("glUniformMatrix4x3fv"));
    }
    static void load_GL_VERSION_3_0(GLADloadproc load) {
        if (!GLAD_GL_VERSION_3_0) return;
        glad_glColorMaski = static_cast<PFNGLCOLORMASKIPROC>(load("glColorMaski"));
        glad_glGetBooleani_v = static_cast<PFNGLGETBOOLEANI_VPROC>(load("glGetBooleani_v"));
        glad_glGetIntegeri_v = static_cast<PFNGLGETINTEGERI_VPROC>(load("glGetIntegeri_v"));
        glad_glEnablei = static_cast<PFNGLENABLEIPROC>(load("glEnablei"));
        glad_glDisablei = static_cast<PFNGLDISABLEIPROC>(load("glDisablei"));
        glad_glIsEnabledi = static_cast<PFNGLISENABLEDIPROC>(load("glIsEnabledi"));
        glad_glBeginTransformFeedback = static_cast<PFNGLBEGINTRANSFORMFEEDBACKPROC>(load("glBeginTransformFeedback"));
        glad_glEndTransformFeedback = static_cast<PFNGLENDTRANSFORMFEEDBACKPROC>(load("glEndTransformFeedback"));
        glad_glBindBufferRange = static_cast<PFNGLBINDBUFFERRANGEPROC>(load("glBindBufferRange"));
        glad_glBindBufferBase = static_cast<PFNGLBINDBUFFERBASEPROC>(load("glBindBufferBase"));
        glad_glTransformFeedbackVaryings = static_cast<PFNGLTRANSFORMFEEDBACKVARYINGSPROC>(load("glTransformFeedbackVaryings"));
        glad_glGetTransformFeedbackVarying = static_cast<PFNGLGETTRANSFORMFEEDBACKVARYINGPROC>(load("glGetTransformFeedbackVarying"));
        glad_glClampColor = static_cast<PFNGLCLAMPCOLORPROC>(load("glClampColor"));
        glad_glBeginConditionalRender = static_cast<PFNGLBEGINCONDITIONALRENDERPROC>(load("glBeginConditionalRender"));
        glad_glEndConditionalRender = static_cast<PFNGLENDCONDITIONALRENDERPROC>(load("glEndConditionalRender"));
        glad_glVertexAttribIPointer = static_cast<PFNGLVERTEXATTRIBIPOINTERPROC>(load("glVertexAttribIPointer"));
        glad_glGetVertexAttribIiv = static_cast<PFNGLGETVERTEXATTRIBIIVPROC>(load("glGetVertexAttribIiv"));
        glad_glGetVertexAttribIuiv = static_cast<PFNGLGETVERTEXATTRIBIUIVPROC>(load("glGetVertexAttribIuiv"));
        glad_glVertexAttribI1i = static_cast<PFNGLVERTEXATTRIBI1IPROC>(load("glVertexAttribI1i"));
        glad_glVertexAttribI2i = static_cast<PFNGLVERTEXATTRIBI2IPROC>(load("glVertexAttribI2i"));
        glad_glVertexAttribI3i = static_cast<PFNGLVERTEXATTRIBI3IPROC>(load("glVertexAttribI3i"));
        glad_glVertexAttribI4i = static_cast<PFNGLVERTEXATTRIBI4IPROC>(load("glVertexAttribI4i"));
        glad_glVertexAttribI1ui = static_cast<PFNGLVERTEXATTRIBI1UIPROC>(load("glVertexAttribI1ui"));
        glad_glVertexAttribI2ui = static_cast<PFNGLVERTEXATTRIBI2UIPROC>(load("glVertexAttribI2ui"));
        glad_glVertexAttribI3ui = static_cast<PFNGLVERTEXATTRIBI3UIPROC>(load("glVertexAttribI3ui"));
        glad_glVertexAttribI4ui = static_cast<PFNGLVERTEXATTRIBI4UIPROC>(load("glVertexAttribI4ui"));
        glad_glVertexAttribI1iv = static_cast<PFNGLVERTEXATTRIBI1IVPROC>(load("glVertexAttribI1iv"));
        glad_glVertexAttribI2iv = static_cast<PFNGLVERTEXATTRIBI2IVPROC>(load("glVertexAttribI2iv"));
        glad_glVertexAttribI3iv = static_cast<PFNGLVERTEXATTRIBI3IVPROC>(load("glVertexAttribI3iv"));
        glad_glVertexAttribI4iv = static_cast<PFNGLVERTEXATTRIBI4IVPROC>(load("glVertexAttribI4iv"));
        glad_glVertexAttribI1uiv = static_cast<PFNGLVERTEXATTRIBI1UIVPROC>(load("glVertexAttribI1uiv"));
        glad_glVertexAttribI2uiv = static_cast<PFNGLVERTEXATTRIBI2UIVPROC>(load("glVertexAttribI2uiv"));
        glad_glVertexAttribI3uiv = static_cast<PFNGLVERTEXATTRIBI3UIVPROC>(load("glVertexAttribI3uiv"));
        glad_glVertexAttribI4uiv = static_cast<PFNGLVERTEXATTRIBI4UIVPROC>(load("glVertexAttribI4uiv"));
        glad_glVertexAttribI4bv = static_cast<PFNGLVERTEXATTRIBI4BVPROC>(load("glVertexAttribI4bv"));
        glad_glVertexAttribI4sv = static_cast<PFNGLVERTEXATTRIBI4SVPROC>(load("glVertexAttribI4sv"));
        glad_glVertexAttribI4ubv = static_cast<PFNGLVERTEXATTRIBI4UBVPROC>(load("glVertexAttribI4ubv"));
        glad_glVertexAttribI4usv = static_cast<PFNGLVERTEXATTRIBI4USVPROC>(load("glVertexAttribI4usv"));
        glad_glGetUniformuiv = static_cast<PFNGLGETUNIFORMUIVPROC>(load("glGetUniformuiv"));
        glad_glBindFragDataLocation = static_cast<PFNGLBINDFRAGDATALOCATIONPROC>(load("glBindFragDataLocation"));
        glad_glGetFragDataLocation = static_cast<PFNGLGETFRAGDATALOCATIONPROC>(load("glGetFragDataLocation"));
        glad_glUniform1ui = static_cast<PFNGLUNIFORM1UIPROC>(load("glUniform1ui"));
        glad_glUniform2ui = static_cast<PFNGLUNIFORM2UIPROC>(load("glUniform2ui"));
        glad_glUniform3ui = static_cast<PFNGLUNIFORM3UIPROC>(load("glUniform3ui"));
        glad_glUniform4ui = static_cast<PFNGLUNIFORM4UIPROC>(load("glUniform4ui"));
        glad_glUniform1uiv = static_cast<PFNGLUNIFORM1UIVPROC>(load("glUniform1uiv"));
        glad_glUniform2uiv = static_cast<PFNGLUNIFORM2UIVPROC>(load("glUniform2uiv"));
        glad_glUniform3uiv = static_cast<PFNGLUNIFORM3UIVPROC>(load("glUniform3uiv"));
        glad_glUniform4uiv = static_cast<PFNGLUNIFORM4UIVPROC>(load("glUniform4uiv"));
        glad_glTexParameterIiv = static_cast<PFNGLTEXPARAMETERIIVPROC>(load("glTexParameterIiv"));
        glad_glTexParameterIuiv = static_cast<PFNGLTEXPARAMETERIUIVPROC>(load("glTexParameterIuiv"));
        glad_glGetTexParameterIiv = static_cast<PFNGLGETTEXPARAMETERIIVPROC>(load("glGetTexParameterIiv"));
        glad_glGetTexParameterIuiv = static_cast<PFNGLGETTEXPARAMETERIUIVPROC>(load("glGetTexParameterIuiv"));
        glad_glClearBufferiv = static_cast<PFNGLCLEARBUFFERIVPROC>(load("glClearBufferiv"));
        glad_glClearBufferuiv = static_cast<PFNGLCLEARBUFFERUIVPROC>(load("glClearBufferuiv"));
        glad_glClearBufferfv = static_cast<PFNGLCLEARBUFFERFVPROC>(load("glClearBufferfv"));
        glad_glClearBufferfi = static_cast<PFNGLCLEARBUFFERFIPROC>(load("glClearBufferfi"));
        glad_glGetStringi = static_cast<PFNGLGETSTRINGIPROC>(load("glGetStringi"));
        glad_glIsRenderbuffer = static_cast<PFNGLISRENDERBUFFERPROC>(load("glIsRenderbuffer"));
        glad_glBindRenderbuffer = static_cast<PFNGLBINDRENDERBUFFERPROC>(load("glBindRenderbuffer"));
        glad_glDeleteRenderbuffers = static_cast<PFNGLDELETERENDERBUFFERSPROC>(load("glDeleteRenderbuffers"));
        glad_glGenRenderbuffers = static_cast<PFNGLGENRENDERBUFFERSPROC>(load("glGenRenderbuffers"));
        glad_glRenderbufferStorage = static_cast<PFNGLRENDERBUFFERSTORAGEPROC>(load("glRenderbufferStorage"));
        glad_glGetRenderbufferParameteriv = static_cast<PFNGLGETRENDERBUFFERPARAMETERIVPROC>(load("glGetRenderbufferParameteriv"));
        glad_glIsFramebuffer = static_cast<PFNGLISFRAMEBUFFERPROC>(load("glIsFramebuffer"));
        glad_glBindFramebuffer = static_cast<PFNGLBINDFRAMEBUFFERPROC>(load("glBindFramebuffer"));
        glad_glDeleteFramebuffers = static_cast<PFNGLDELETEFRAMEBUFFERSPROC>(load("glDeleteFramebuffers"));
        glad_glGenFramebuffers = static_cast<PFNGLGENFRAMEBUFFERSPROC>(load("glGenFramebuffers"));
        glad_glCheckFramebufferStatus = static_cast<PFNGLCHECKFRAMEBUFFERSTATUSPROC>(load("glCheckFramebufferStatus"));
        glad_glFramebufferTexture1D = static_cast<PFNGLFRAMEBUFFERTEXTURE1DPROC>(load("glFramebufferTexture1D"));
        glad_glFramebufferTexture2D = static_cast<PFNGLFRAMEBUFFERTEXTURE2DPROC>(load("glFramebufferTexture2D"));
        glad_glFramebufferTexture3D = static_cast<PFNGLFRAMEBUFFERTEXTURE3DPROC>(load("glFramebufferTexture3D"));
        glad_glFramebufferRenderbuffer = static_cast<PFNGLFRAMEBUFFERRENDERBUFFERPROC>(load("glFramebufferRenderbuffer"));
        glad_glGetFramebufferAttachmentParameteriv = static_cast<PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC>(load("glGetFramebufferAttachmentParameteriv"));
        glad_glGenerateMipmap = static_cast<PFNGLGENERATEMIPMAPPROC>(load("glGenerateMipmap"));
        glad_glBlitFramebuffer = static_cast<PFNGLBLITFRAMEBUFFERPROC>(load("glBlitFramebuffer"));
        glad_glRenderbufferStorageMultisample = static_cast<PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC>(load("glRenderbufferStorageMultisample"));
        glad_glFramebufferTextureLayer = static_cast<PFNGLFRAMEBUFFERTEXTURELAYERPROC>(load("glFramebufferTextureLayer"));
        glad_glMapBufferRange = static_cast<PFNGLMAPBUFFERRANGEPROC>(load("glMapBufferRange"));
        glad_glFlushMappedBufferRange = static_cast<PFNGLFLUSHMAPPEDBUFFERRANGEPROC>(load("glFlushMappedBufferRange"));
        glad_glBindVertexArray = static_cast<PFNGLBINDVERTEXARRAYPROC>(load("glBindVertexArray"));
        glad_glDeleteVertexArrays = static_cast<PFNGLDELETEVERTEXARRAYSPROC>(load("glDeleteVertexArrays"));
        glad_glGenVertexArrays = static_cast<PFNGLGENVERTEXARRAYSPROC>(load("glGenVertexArrays"));
        glad_glIsVertexArray = static_cast<PFNGLISVERTEXARRAYPROC>(load("glIsVertexArray"));
    }
    static void load_GL_VERSION_3_1(GLADloadproc load) {
        if (!GLAD_GL_VERSION_3_1) return;
        glad_glDrawArraysInstanced = static_cast<PFNGLDRAWARRAYSINSTANCEDPROC>(load("glDrawArraysInstanced"));
        glad_glDrawElementsInstanced = static_cast<PFNGLDRAWELEMENTSINSTANCEDPROC>(load("glDrawElementsInstanced"));
        glad_glTexBuffer = static_cast<PFNGLTEXBUFFERPROC>(load("glTexBuffer"));
        glad_glPrimitiveRestartIndex = static_cast<PFNGLPRIMITIVERESTARTINDEXPROC>(load("glPrimitiveRestartIndex"));
        glad_glCopyBufferSubData = static_cast<PFNGLCOPYBUFFERSUBDATAPROC>(load("glCopyBufferSubData"));
        glad_glGetUniformIndices = static_cast<PFNGLGETUNIFORMINDICESPROC>(load("glGetUniformIndices"));
        glad_glGetActiveUniformsiv = static_cast<PFNGLGETACTIVEUNIFORMSIVPROC>(load("glGetActiveUniformsiv"));
        glad_glGetActiveUniformName = static_cast<PFNGLGETACTIVEUNIFORMNAMEPROC>(load("glGetActiveUniformName"));
        glad_glGetUniformBlockIndex = static_cast<PFNGLGETUNIFORMBLOCKINDEXPROC>(load("glGetUniformBlockIndex"));
        glad_glGetActiveUniformBlockiv = static_cast<PFNGLGETACTIVEUNIFORMBLOCKIVPROC>(load("glGetActiveUniformBlockiv"));
        glad_glGetActiveUniformBlockName = static_cast<PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC>(load("glGetActiveUniformBlockName"));
        glad_glUniformBlockBinding = static_cast<PFNGLUNIFORMBLOCKBINDINGPROC>(load("glUniformBlockBinding"));
        glad_glBindBufferRange = static_cast<PFNGLBINDBUFFERRANGEPROC>(load("glBindBufferRange"));
        glad_glBindBufferBase = static_cast<PFNGLBINDBUFFERBASEPROC>(load("glBindBufferBase"));
        glad_glGetIntegeri_v = static_cast<PFNGLGETINTEGERI_VPROC>(load("glGetIntegeri_v"));
    }
    static void load_GL_VERSION_3_2(GLADloadproc load) {
        if (!GLAD_GL_VERSION_3_2) return;
        glad_glDrawElementsBaseVertex = static_cast<PFNGLDRAWELEMENTSBASEVERTEXPROC>(load("glDrawElementsBaseVertex"));
        glad_glDrawRangeElementsBaseVertex = static_cast<PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC>(load("glDrawRangeElementsBaseVertex"));
        glad_glDrawElementsInstancedBaseVertex = static_cast<PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC>(load("glDrawElementsInstancedBaseVertex"));
        glad_glMultiDrawElementsBaseVertex = static_cast<PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC>(load("glMultiDrawElementsBaseVertex"));
        glad_glProvokingVertex = static_cast<PFNGLPROVOKINGVERTEXPROC>(load("glProvokingVertex"));
        glad_glFenceSync = static_cast<PFNGLFENCESYNCPROC>(load("glFenceSync"));
        glad_glIsSync = static_cast<PFNGLISSYNCPROC>(load("glIsSync"));
        glad_glDeleteSync = static_cast<PFNGLDELETESYNCPROC>(load("glDeleteSync"));
        glad_glClientWaitSync = static_cast<PFNGLCLIENTWAITSYNCPROC>(load("glClientWaitSync"));
        glad_glWaitSync = static_cast<PFNGLWAITSYNCPROC>(load("glWaitSync"));
        glad_glGetInteger64v = static_cast<PFNGLGETINTEGER64VPROC>(load("glGetInteger64v"));
        glad_glGetSynciv = static_cast<PFNGLGETSYNCIVPROC>(load("glGetSynciv"));
        glad_glGetInteger64i_v = static_cast<PFNGLGETINTEGER64I_VPROC>(load("glGetInteger64i_v"));
        glad_glGetBufferParameteri64v = static_cast<PFNGLGETBUFFERPARAMETERI64VPROC>(load("glGetBufferParameteri64v"));
        glad_glFramebufferTexture = static_cast<PFNGLFRAMEBUFFERTEXTUREPROC>(load("glFramebufferTexture"));
        glad_glTexImage2DMultisample = static_cast<PFNGLTEXIMAGE2DMULTISAMPLEPROC>(load("glTexImage2DMultisample"));
        glad_glTexImage3DMultisample = static_cast<PFNGLTEXIMAGE3DMULTISAMPLEPROC>(load("glTexImage3DMultisample"));
        glad_glGetMultisamplefv = static_cast<PFNGLGETMULTISAMPLEFVPROC>(load("glGetMultisamplefv"));
        glad_glSampleMaski = static_cast<PFNGLSAMPLEMASKIPROC>(load("glSampleMaski"));
    }
    static void load_GL_VERSION_3_3(GLADloadproc load) {
        if (!GLAD_GL_VERSION_3_3) return;
        glad_glBindFragDataLocationIndexed = static_cast<PFNGLBINDFRAGDATALOCATIONINDEXEDPROC>(load("glBindFragDataLocationIndexed"));
        glad_glGetFragDataIndex = static_cast<PFNGLGETFRAGDATAINDEXPROC>(load("glGetFragDataIndex"));
        glad_glGenSamplers = static_cast<PFNGLGENSAMPLERSPROC>(load("glGenSamplers"));
        glad_glDeleteSamplers = static_cast<PFNGLDELETESAMPLERSPROC>(load("glDeleteSamplers"));
        glad_glIsSampler = static_cast<PFNGLISSAMPLERPROC>(load("glIsSampler"));
        glad_glBindSampler = static_cast<PFNGLBINDSAMPLERPROC>(load("glBindSampler"));
        glad_glSamplerParameteri = static_cast<PFNGLSAMPLERPARAMETERIPROC>(load("glSamplerParameteri"));
        glad_glSamplerParameteriv = static_cast<PFNGLSAMPLERPARAMETERIVPROC>(load("glSamplerParameteriv"));
        glad_glSamplerParameterf = static_cast<PFNGLSAMPLERPARAMETERFPROC>(load("glSamplerParameterf"));
        glad_glSamplerParameterfv = static_cast<PFNGLSAMPLERPARAMETERFVPROC>(load("glSamplerParameterfv"));
        glad_glSamplerParameterIiv = static_cast<PFNGLSAMPLERPARAMETERIIVPROC>(load("glSamplerParameterIiv"));
        glad_glSamplerParameterIuiv = static_cast<PFNGLSAMPLERPARAMETERIUIVPROC>(load("glSamplerParameterIuiv"));
        glad_glGetSamplerParameteriv = static_cast<PFNGLGETSAMPLERPARAMETERIVPROC>(load("glGetSamplerParameteriv"));
        glad_glGetSamplerParameterIiv = static_cast<PFNGLGETSAMPLERPARAMETERIIVPROC>(load("glGetSamplerParameterIiv"));
        glad_glGetSamplerParameterfv = static_cast<PFNGLGETSAMPLERPARAMETERFVPROC>(load("glGetSamplerParameterfv"));
        glad_glGetSamplerParameterIuiv = static_cast<PFNGLGETSAMPLERPARAMETERIUIVPROC>(load("glGetSamplerParameterIuiv"));
        glad_glQueryCounter = static_cast<PFNGLQUERYCOUNTERPROC>(load("glQueryCounter"));
        glad_glGetQueryObjecti64v = static_cast<PFNGLGETQUERYOBJECTI64VPROC>(load("glGetQueryObjecti64v"));
        glad_glGetQueryObjectui64v = static_cast<PFNGLGETQUERYOBJECTUI64VPROC>(load("glGetQueryObjectui64v"));
        glad_glVertexAttribDivisor = static_cast<PFNGLVERTEXATTRIBDIVISORPROC>(load("glVertexAttribDivisor"));
        glad_glVertexAttribP1ui = static_cast<PFNGLVERTEXATTRIBP1UIPROC>(load("glVertexAttribP1ui"));
        glad_glVertexAttribP1uiv = static_cast<PFNGLVERTEXATTRIBP1UIVPROC>(load("glVertexAttribP1uiv"));
        glad_glVertexAttribP2ui = static_cast<PFNGLVERTEXATTRIBP2UIPROC>(load("glVertexAttribP2ui"));
        glad_glVertexAttribP2uiv = static_cast<PFNGLVERTEXATTRIBP2UIVPROC>(load("glVertexAttribP2uiv"));
        glad_glVertexAttribP3ui = static_cast<PFNGLVERTEXATTRIBP3UIPROC>(load("glVertexAttribP3ui"));
        glad_glVertexAttribP3uiv = static_cast<PFNGLVERTEXATTRIBP3UIVPROC>(load("glVertexAttribP3uiv"));
        glad_glVertexAttribP4ui = static_cast<PFNGLVERTEXATTRIBP4UIPROC>(load("glVertexAttribP4ui"));
        glad_glVertexAttribP4uiv = static_cast<PFNGLVERTEXATTRIBP4UIVPROC>(load("glVertexAttribP4uiv"));
        glad_glVertexP2ui = static_cast<PFNGLVERTEXP2UIPROC>(load("glVertexP2ui"));
        glad_glVertexP2uiv = static_cast<PFNGLVERTEXP2UIVPROC>(load("glVertexP2uiv"));
        glad_glVertexP3ui = static_cast<PFNGLVERTEXP3UIPROC>(load("glVertexP3ui"));
        glad_glVertexP3uiv = static_cast<PFNGLVERTEXP3UIVPROC>(load("glVertexP3uiv"));
        glad_glVertexP4ui = static_cast<PFNGLVERTEXP4UIPROC>(load("glVertexP4ui"));
        glad_glVertexP4uiv = static_cast<PFNGLVERTEXP4UIVPROC>(load("glVertexP4uiv"));
        glad_glTexCoordP1ui = static_cast<PFNGLTEXCOORDP1UIPROC>(load("glTexCoordP1ui"));
        glad_glTexCoordP1uiv = static_cast<PFNGLTEXCOORDP1UIVPROC>(load("glTexCoordP1uiv"));
        glad_glTexCoordP2ui = static_cast<PFNGLTEXCOORDP2UIPROC>(load("glTexCoordP2ui"));
        glad_glTexCoordP2uiv = static_cast<PFNGLTEXCOORDP2UIVPROC>(load("glTexCoordP2uiv"));
        glad_glTexCoordP3ui = static_cast<PFNGLTEXCOORDP3UIPROC>(load("glTexCoordP3ui"));
        glad_glTexCoordP3uiv = static_cast<PFNGLTEXCOORDP3UIVPROC>(load("glTexCoordP3uiv"));
        glad_glTexCoordP4ui = static_cast<PFNGLTEXCOORDP4UIPROC>(load("glTexCoordP4ui"));
        glad_glTexCoordP4uiv = static_cast<PFNGLTEXCOORDP4UIVPROC>(load("glTexCoordP4uiv"));
        glad_glMultiTexCoordP1ui = static_cast<PFNGLMULTITEXCOORDP1UIPROC>(load("glMultiTexCoordP1ui"));
        glad_glMultiTexCoordP1uiv = static_cast<PFNGLMULTITEXCOORDP1UIVPROC>(load("glMultiTexCoordP1uiv"));
        glad_glMultiTexCoordP2ui = static_cast<PFNGLMULTITEXCOORDP2UIPROC>(load("glMultiTexCoordP2ui"));
        glad_glMultiTexCoordP2uiv = static_cast<PFNGLMULTITEXCOORDP2UIVPROC>(load("glMultiTexCoordP2uiv"));
        glad_glMultiTexCoordP3ui = static_cast<PFNGLMULTITEXCOORDP3UIPROC>(load("glMultiTexCoordP3ui"));
        glad_glMultiTexCoordP3uiv = static_cast<PFNGLMULTITEXCOORDP3UIVPROC>(load("glMultiTexCoordP3uiv"));
        glad_glMultiTexCoordP4ui = static_cast<PFNGLMULTITEXCOORDP4UIPROC>(load("glMultiTexCoordP4ui"));
        glad_glMultiTexCoordP4uiv = static_cast<PFNGLMULTITEXCOORDP4UIVPROC>(load("glMultiTexCoordP4uiv"));
        glad_glNormalP3ui = static_cast<PFNGLNORMALP3UIPROC>(load("glNormalP3ui"));
        glad_glNormalP3uiv = static_cast<PFNGLNORMALP3UIVPROC>(load("glNormalP3uiv"));
        glad_glColorP3ui = static_cast<PFNGLCOLORP3UIPROC>(load("glColorP3ui"));
        glad_glColorP3uiv = static_cast<PFNGLCOLORP3UIVPROC>(load("glColorP3uiv"));
        glad_glColorP4ui = static_cast<PFNGLCOLORP4UIPROC>(load("glColorP4ui"));
        glad_glColorP4uiv = static_cast<PFNGLCOLORP4UIVPROC>(load("glColorP4uiv"));
        glad_glSecondaryColorP3ui = static_cast<PFNGLSECONDARYCOLORP3UIPROC>(load("glSecondaryColorP3ui"));
        glad_glSecondaryColorP3uiv = static_cast<PFNGLSECONDARYCOLORP3UIVPROC>(load("glSecondaryColorP3uiv"));
    }
    static void load_GL_VERSION_4_0(GLADloadproc load) {
        if (!GLAD_GL_VERSION_4_0) return;
        glad_glMinSampleShading = static_cast<PFNGLMINSAMPLESHADINGPROC>(load("glMinSampleShading"));
        glad_glBlendEquationi = static_cast<PFNGLBLENDEQUATIONIPROC>(load("glBlendEquationi"));
        glad_glBlendEquationSeparatei = static_cast<PFNGLBLENDEQUATIONSEPARATEIPROC>(load("glBlendEquationSeparatei"));
        glad_glBlendFunci = static_cast<PFNGLBLENDFUNCIPROC>(load("glBlendFunci"));
        glad_glBlendFuncSeparatei = static_cast<PFNGLBLENDFUNCSEPARATEIPROC>(load("glBlendFuncSeparatei"));
        glad_glDrawArraysIndirect = static_cast<PFNGLDRAWARRAYSINDIRECTPROC>(load("glDrawArraysIndirect"));
        glad_glDrawElementsIndirect = static_cast<PFNGLDRAWELEMENTSINDIRECTPROC>(load("glDrawElementsIndirect"));
        glad_glUniform1d = static_cast<PFNGLUNIFORM1DPROC>(load("glUniform1d"));
        glad_glUniform2d = static_cast<PFNGLUNIFORM2DPROC>(load("glUniform2d"));
        glad_glUniform3d = static_cast<PFNGLUNIFORM3DPROC>(load("glUniform3d"));
        glad_glUniform4d = static_cast<PFNGLUNIFORM4DPROC>(load("glUniform4d"));
        glad_glUniform1dv = static_cast<PFNGLUNIFORM1DVPROC>(load("glUniform1dv"));
        glad_glUniform2dv = static_cast<PFNGLUNIFORM2DVPROC>(load("glUniform2dv"));
        glad_glUniform3dv = static_cast<PFNGLUNIFORM3DVPROC>(load("glUniform3dv"));
        glad_glUniform4dv = static_cast<PFNGLUNIFORM4DVPROC>(load("glUniform4dv"));
        glad_glUniformMatrix2dv = static_cast<PFNGLUNIFORMMATRIX2DVPROC>(load("glUniformMatrix2dv"));
        glad_glUniformMatrix3dv = static_cast<PFNGLUNIFORMMATRIX3DVPROC>(load("glUniformMatrix3dv"));
        glad_glUniformMatrix4dv = static_cast<PFNGLUNIFORMMATRIX4DVPROC>(load("glUniformMatrix4dv"));
        glad_glUniformMatrix2x3dv = static_cast<PFNGLUNIFORMMATRIX2X3DVPROC>(load("glUniformMatrix2x3dv"));
        glad_glUniformMatrix2x4dv = static_cast<PFNGLUNIFORMMATRIX2X4DVPROC>(load("glUniformMatrix2x4dv"));
        glad_glUniformMatrix3x2dv = static_cast<PFNGLUNIFORMMATRIX3X2DVPROC>(load("glUniformMatrix3x2dv"));
        glad_glUniformMatrix3x4dv = static_cast<PFNGLUNIFORMMATRIX3X4DVPROC>(load("glUniformMatrix3x4dv"));
        glad_glUniformMatrix4x2dv = static_cast<PFNGLUNIFORMMATRIX4X2DVPROC>(load("glUniformMatrix4x2dv"));
        glad_glUniformMatrix4x3dv = static_cast<PFNGLUNIFORMMATRIX4X3DVPROC>(load("glUniformMatrix4x3dv"));
        glad_glGetUniformdv = static_cast<PFNGLGETUNIFORMDVPROC>(load("glGetUniformdv"));
        glad_glGetSubroutineUniformLocation = static_cast<PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC>(load("glGetSubroutineUniformLocation"));
        glad_glGetSubroutineIndex = static_cast<PFNGLGETSUBROUTINEINDEXPROC>(load("glGetSubroutineIndex"));
        glad_glGetActiveSubroutineUniformiv = static_cast<PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC>(load("glGetActiveSubroutineUniformiv"));
        glad_glGetActiveSubroutineUniformName = static_cast<PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC>(load("glGetActiveSubroutineUniformName"));
        glad_glGetActiveSubroutineName = static_cast<PFNGLGETACTIVESUBROUTINENAMEPROC>(load("glGetActiveSubroutineName"));
        glad_glUniformSubroutinesuiv = static_cast<PFNGLUNIFORMSUBROUTINESUIVPROC>(load("glUniformSubroutinesuiv"));
        glad_glGetUniformSubroutineuiv = static_cast<PFNGLGETUNIFORMSUBROUTINEUIVPROC>(load("glGetUniformSubroutineuiv"));
        glad_glGetProgramStageiv = static_cast<PFNGLGETPROGRAMSTAGEIVPROC>(load("glGetProgramStageiv"));
        glad_glPatchParameteri = static_cast<PFNGLPATCHPARAMETERIPROC>(load("glPatchParameteri"));
        glad_glPatchParameterfv = static_cast<PFNGLPATCHPARAMETERFVPROC>(load("glPatchParameterfv"));
        glad_glBindTransformFeedback = static_cast<PFNGLBINDTRANSFORMFEEDBACKPROC>(load("glBindTransformFeedback"));
        glad_glDeleteTransformFeedbacks = static_cast<PFNGLDELETETRANSFORMFEEDBACKSPROC>(load("glDeleteTransformFeedbacks"));
        glad_glGenTransformFeedbacks = static_cast<PFNGLGENTRANSFORMFEEDBACKSPROC>(load("glGenTransformFeedbacks"));
        glad_glIsTransformFeedback = static_cast<PFNGLISTRANSFORMFEEDBACKPROC>(load("glIsTransformFeedback"));
        glad_glPauseTransformFeedback = static_cast<PFNGLPAUSETRANSFORMFEEDBACKPROC>(load("glPauseTransformFeedback"));
        glad_glResumeTransformFeedback = static_cast<PFNGLRESUMETRANSFORMFEEDBACKPROC>(load("glResumeTransformFeedback"));
        glad_glDrawTransformFeedback = static_cast<PFNGLDRAWTRANSFORMFEEDBACKPROC>(load("glDrawTransformFeedback"));
        glad_glDrawTransformFeedbackStream = static_cast<PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC>(load("glDrawTransformFeedbackStream"));
        glad_glBeginQueryIndexed = static_cast<PFNGLBEGINQUERYINDEXEDPROC>(load("glBeginQueryIndexed"));
        glad_glEndQueryIndexed = static_cast<PFNGLENDQUERYINDEXEDPROC>(load("glEndQueryIndexed"));
        glad_glGetQueryIndexediv = static_cast<PFNGLGETQUERYINDEXEDIVPROC>(load("glGetQueryIndexediv"));
    }
    static int find_extensionsGL(void) {
        if (!get_exts()) return 0;
        (void)(&has_ext);
        free_exts();
        return 1;
    }
    static void find_coreGL(void) {
        /* Thank you @elmindreda
        * i carry the comment from glad.c to this file to give creddit
        * https://github.com/elmindreda/greg/blob/master/templates/greg.c.in#L176
        * https://github.com/glfw/glfw/blob/master/src/context.c#L36
        */
        int i;
        int major;
        int minor;
        const char* version;
        const char* prefixes[] = {
            "OpenGL ES-CM ",
            "OpenGL ES-CL ",
            "OpenGL Es ",
            nullptr
        };
        version = reinterpret_cast<const char*>(glGetString(CONSTANTS::_GL_VERSION));
        if (!version) {
            return;
        }
        for (i = 0; prefixes[i]; i++) {
            const size_t length = strlen(prefixes[i]);
            if (strncmp(version, prefixes[i], length) == 0) {
                version += length;
                break;
            }
        }
        /* PR #18 */
#ifdef _MSC_VER
        sscanf_s(version, "%d.%d", &major, &minor);
#else
        sscanf(version, "%d.%d", &major, &minor);
#endif

        GLVersion.major = major; GLVersion.minor = minor;
        max_loaded_major = major; max_loaded_minor = minor;
        GLAD_GL_VERSION_1_0 = (major == 1 && minor >= 0) || major > 1;
        GLAD_GL_VERSION_1_1 = (major == 1 && minor >= 1) || major > 1;
        GLAD_GL_VERSION_1_2 = (major == 1 && minor >= 2) || major > 1;
        GLAD_GL_VERSION_1_3 = (major == 1 && minor >= 3) || major > 1;
        GLAD_GL_VERSION_1_4 = (major == 1 && minor >= 4) || major > 1;
        GLAD_GL_VERSION_1_5 = (major == 1 && minor >= 5) || major > 1;
        GLAD_GL_VERSION_2_0 = (major == 2 && minor >= 0) || major > 2;
        GLAD_GL_VERSION_2_1 = (major == 2 && minor >= 1) || major > 2;
        GLAD_GL_VERSION_3_0 = (major == 3 && minor >= 0) || major > 3;
        GLAD_GL_VERSION_3_1 = (major == 3 && minor >= 1) || major > 3;
        GLAD_GL_VERSION_3_2 = (major == 3 && minor >= 2) || major > 3;
        GLAD_GL_VERSION_3_3 = (major == 3 && minor >= 3) || major > 3;
        GLAD_GL_VERSION_4_0 = (major == 4 && minor >= 0) || major > 4;
        if (GLVersion.major > 4 || (GLVersion.major >= 4 && GLVersion.minor >= 0)) {
            max_loaded_major = 4;
            max_loaded_minor = 0;
        }
    }
    int gladLoadGLLoader(GLADloadproc load) {
        GLVersion.major = 0; GLVersion.minor = 0;
        glad_glGetString = (PFNGLGETSTRINGPROC)load("glGetString");
        if (glad_glGetString == nullptr) return 0;
        if (glGetString(CONSTANTS::_GL_VERSION) == nullptr) return 0;
        find_coreGL();
        load_GL_VERSION_1_0(load);
        load_GL_VERSION_1_1(load);
        load_GL_VERSION_1_2(load);
        load_GL_VERSION_1_3(load);
        load_GL_VERSION_1_4(load);
        load_GL_VERSION_1_5(load);
        load_GL_VERSION_2_0(load);
        load_GL_VERSION_2_1(load);
        load_GL_VERSION_3_0(load);
        load_GL_VERSION_3_1(load);
        load_GL_VERSION_3_2(load);
        load_GL_VERSION_3_3(load);
        load_GL_VERSION_4_0(load);

        if (!find_extensionsGL()) return 0;
        return GLVersion.major != 0 || GLVersion.minor != 0;
    }
}

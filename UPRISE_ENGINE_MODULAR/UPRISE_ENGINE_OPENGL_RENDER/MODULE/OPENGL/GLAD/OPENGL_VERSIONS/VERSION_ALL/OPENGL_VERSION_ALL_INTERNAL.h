#pragma once
#ifndef UE_OENGL_VERSION_ALL_INTERNAL_
#define UE_VERSION_ALL_INTERNAL_
#ifndef __INTELLISENSE__
#ifndef UE_OPENGL_BUILD_
#error "this file should not be directly included in user code. use import UPRISE_ENGINE_CORE instead"
#endif
#endif
#include "OPENGL/GLAD/STUPIDMACROS/GLAD_MACROS.h"
#ifdef __INTELLISENSE__
#define DONT_INCLUDE_GLAD
#include "OPENGL/GLAD/GLAD_GLOBALS/GLAD_GLOBALS_INTERNAL.h"
#endif // __INTELLISENSE__
#ifdef GL_VERSION_3_0
#define undefed_gl_version_3_0
#undef GL_VERSION_3_0
#endif // GL_VERSION_3_0

namespace UPRISE_ENGINE {
    namespace RENDER {
        namespace GLAD {
            export GLAPI int GLAD_GL_VERSION_1_0;
            export typedef void (APIENTRYP PFNGLCULLFACEPROC)(GLenum mode);
            export GLAPI PFNGLCULLFACEPROC glad_glCullFace;
            export inline void glCullFace(GLenum mode) { glad_glCullFace(mode); }
            export typedef void (APIENTRYP PFNGLFRONTFACEPROC)(GLenum mode);
            export GLAPI PFNGLFRONTFACEPROC glad_glFrontFace;
            export inline void glFrontFace(GLenum mode) { glad_glFrontFace(mode); }
            export typedef void (APIENTRYP PFNGLHINTPROC)(GLenum target, GLenum mode);
            export GLAPI PFNGLHINTPROC glad_glHint;
            export inline void glHint(GLenum target, GLenum mode) { glad_glHint(target, mode); }
            export typedef void (APIENTRYP PFNGLLINEWIDTHPROC)(GLfloat width);
            export GLAPI PFNGLLINEWIDTHPROC glad_glLineWidth;
            export inline void glLineWidth(GLfloat width) { glad_glLineWidth(width); }
            export typedef void (APIENTRYP PFNGLPOINTSIZEPROC)(GLfloat size);
            export GLAPI PFNGLPOINTSIZEPROC glad_glPointSize;
            export inline void glPointSize(GLfloat size) { glad_glPointSize(size); }
            export typedef void (APIENTRYP PFNGLPOLYGONMODEPROC)(GLenum face, GLenum mode);
            export GLAPI PFNGLPOLYGONMODEPROC glad_glPolygonMode;
            export inline void glPolygonMode(GLenum face, GLenum mode) { glad_glPolygonMode(face, mode); }
            export typedef void (APIENTRYP PFNGLSCISSORPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
            export GLAPI PFNGLSCISSORPROC glad_glScissor;
            export inline void glScissor(GLint x, GLint y, GLsizei width, GLsizei height) { glad_glScissor(x, y, width, height); }
            export typedef void (APIENTRYP PFNGLTEXPARAMETERFPROC)(GLenum target, GLenum pname, GLfloat param);
            export GLAPI PFNGLTEXPARAMETERFPROC glad_glTexParameterf;
            export inline void glTexParameterf(GLenum target, GLenum pname, GLfloat param) { glad_glTexParameterf(target, pname, param); }
            export typedef void (APIENTRYP PFNGLTEXPARAMETERFVPROC)(GLenum target, GLenum pname, const GLfloat* params);
            export GLAPI PFNGLTEXPARAMETERFVPROC glad_glTexParameterfv;
            export inline void glTexParameterfv(GLenum target, GLenum pname, const GLfloat* params) { glad_glTexParameterfv(target, pname, params); }
            export typedef void (APIENTRYP PFNGLTEXPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
            export GLAPI PFNGLTEXPARAMETERIPROC glad_glTexParameteri;
            export inline void glTexParameteri(GLenum target, GLenum pname, GLint param) { glad_glTexParameteri(target, pname, param); }
            export typedef void (APIENTRYP PFNGLTEXPARAMETERIVPROC)(GLenum target, GLenum pname, const GLint* params);
            export GLAPI PFNGLTEXPARAMETERIVPROC glad_glTexParameteriv;
            export inline void glTexParameteriv(GLenum target, GLenum pname, const GLint* params) { glad_glTexParameteriv(target, pname, params); }
            export typedef void (APIENTRYP PFNGLTEXIMAGE1DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels);
            export GLAPI PFNGLTEXIMAGE1DPROC glad_glTexImage1D;
            export inline void glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels) { glad_glTexImage1D(target, level, internalformat, width, border, format, type, pixels); }
            export typedef void (APIENTRYP PFNGLTEXIMAGE2DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels);
            export GLAPI PFNGLTEXIMAGE2DPROC glad_glTexImage2D;
            export inline void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels) { glad_glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels); }
            export typedef void (APIENTRYP PFNGLDRAWBUFFERPROC)(GLenum buf);
            export GLAPI PFNGLDRAWBUFFERPROC glad_glDrawBuffer;
            export inline void glDrawBuffer(GLenum buf) { glad_glDrawBuffer(buf); }
            export typedef void (APIENTRYP PFNGLCLEARPROC)(GLbitfield mask);
            export GLAPI PFNGLCLEARPROC glad_glClear;
            export inline void glClear(GLbitfield mask) { glad_glClear(mask); }
            export typedef void (APIENTRYP PFNGLCLEARCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
            export GLAPI PFNGLCLEARCOLORPROC glad_glClearColor;
            export inline void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) { glad_glClearColor(red, green, blue, alpha); }
            export typedef void (APIENTRYP PFNGLCLEARSTENCILPROC)(GLint s);
            export GLAPI PFNGLCLEARSTENCILPROC glad_glClearStencil;
            export inline void glClearStencil(GLint s) { glad_glClearStencil(s); }
            export typedef void (APIENTRYP PFNGLCLEARDEPTHPROC)(GLdouble depth);
            export GLAPI PFNGLCLEARDEPTHPROC glad_glClearDepth;
            export inline void glClearDepth(GLdouble depth) { glad_glClearDepth(depth); }
            export typedef void (APIENTRYP PFNGLSTENCILMASKPROC)(GLuint mask);
            export GLAPI PFNGLSTENCILMASKPROC glad_glStencilMask;
            export inline void glStencilMask(GLuint mask) { glad_glStencilMask(mask); }
            export typedef void (APIENTRYP PFNGLCOLORMASKPROC)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
            export GLAPI PFNGLCOLORMASKPROC glad_glColorMask;
            export inline void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) { glad_glColorMask(red, green, blue, alpha); }
            export typedef void (APIENTRYP PFNGLDEPTHMASKPROC)(GLboolean flag);
            export GLAPI PFNGLDEPTHMASKPROC glad_glDepthMask;
            export inline void glDepthMask(GLboolean flag) { glad_glDepthMask(flag); }
            export typedef void (APIENTRYP PFNGLDISABLEPROC)(GLenum cap);
            export GLAPI PFNGLDISABLEPROC glad_glDisable;
            export inline void glDisable(GLenum cap) { glad_glDisable(cap); }
            export typedef void (APIENTRYP PFNGLENABLEPROC)(GLenum cap);
            export GLAPI PFNGLENABLEPROC glad_glEnable;
            export inline void glEnable(GLenum cap) { glad_glEnable(cap); }
            export typedef void (APIENTRYP PFNGLFINISHPROC)(void);
            export GLAPI PFNGLFINISHPROC glad_glFinish;
            export inline void glFinish() { glad_glFinish(); }
            export typedef void (APIENTRYP PFNGLFLUSHPROC)(void);
            export GLAPI PFNGLFLUSHPROC glad_glFlush;
            export typedef void (APIENTRYP PFNGLBLENDFUNCPROC)(GLenum sfactor, GLenum dfactor);
            export GLAPI PFNGLBLENDFUNCPROC glad_glBlendFunc;
            export inline void glBlendFunc(GLenum sfactor, GLenum dfactor) { glad_glBlendFunc(sfactor, dfactor); }
            export typedef void (APIENTRYP PFNGLLOGICOPPROC)(GLenum opcode);
            export GLAPI PFNGLLOGICOPPROC glad_glLogicOp;
            export inline void glLogicOp(GLenum opcode) { glad_glLogicOp(opcode); }
            export typedef void (APIENTRYP PFNGLSTENCILFUNCPROC)(GLenum func, GLint ref, GLuint mask);
            export GLAPI PFNGLSTENCILFUNCPROC glad_glStencilFunc;
            export inline void glStencilFunc(GLenum func, GLint ref, GLuint mask) { glad_glStencilFunc(func, ref, mask); }
            export typedef void (APIENTRYP PFNGLSTENCILOPPROC)(GLenum fail, GLenum zfail, GLenum zpass);
            export GLAPI PFNGLSTENCILOPPROC glad_glStencilOp;
            export inline void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) { glad_glStencilOp(fail, zfail, zpass); }
            export typedef void (APIENTRYP PFNGLDEPTHFUNCPROC)(GLenum func);
            export GLAPI PFNGLDEPTHFUNCPROC glad_glDepthFunc;
            export inline void glDepthFunc(GLenum func) { glad_glDepthFunc(func); }
            export typedef void (APIENTRYP PFNGLPIXELSTOREFPROC)(GLenum pname, GLfloat param);
            export GLAPI PFNGLPIXELSTOREFPROC glad_glPixelStoref;
            export inline void glPixelStoref(GLenum pname, GLfloat param) { glad_glPixelStoref(pname, param); }
            export typedef void (APIENTRYP PFNGLPIXELSTOREIPROC)(GLenum pname, GLint param);
            export GLAPI PFNGLPIXELSTOREIPROC glad_glPixelStorei;
            export inline void glPixelStorei(GLenum pname, GLint param) { glad_glPixelStorei(pname, param); }
            export typedef void (APIENTRYP PFNGLREADBUFFERPROC)(GLenum src);
            export GLAPI PFNGLREADBUFFERPROC glad_glReadBuffer;
            export inline void glReadBuffer(GLenum src) { glad_glReadBuffer(src); }
            export typedef void (APIENTRYP PFNGLREADPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void* pixels);
            export GLAPI PFNGLREADPIXELSPROC glad_glReadPixels;
            export inline void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void* pixels) { glad_glReadPixels(x, y, width, height, format, type, pixels); }
            export typedef void (APIENTRYP PFNGLGETBOOLEANVPROC)(GLenum pname, GLboolean* data);
            export GLAPI PFNGLGETBOOLEANVPROC glad_glGetBooleanv;
            export inline void glGetBooleanv(GLenum pname, GLboolean* data) { glad_glGetBooleanv(pname, data); }
            export typedef void (APIENTRYP PFNGLGETDOUBLEVPROC)(GLenum pname, GLdouble* data);
            export GLAPI PFNGLGETDOUBLEVPROC glad_glGetDoublev;
            export inline void glGetDoublev(GLenum pname, GLdouble* data) { glad_glGetDoublev(pname, data); }
            export typedef GLenum(APIENTRYP PFNGLGETERRORPROC)(void);
            export GLAPI PFNGLGETERRORPROC glad_glGetError;
            export inline GLenum glGetError() { return glad_glGetError(); }
            export typedef void (APIENTRYP PFNGLGETFLOATVPROC)(GLenum pname, GLfloat* data);
            export GLAPI PFNGLGETFLOATVPROC glad_glGetFloatv;
            export inline void glGetFloatv(GLenum pname, GLfloat* data) { glad_glGetFloatv(pname, data); }
            export typedef void (APIENTRYP PFNGLGETINTEGERVPROC)(GLenum pname, GLint* data);
            export GLAPI PFNGLGETINTEGERVPROC glad_glGetIntegerv;
            export inline void glGetIntegerv(GLenum pname, GLint* data) { glad_glGetIntegerv(pname, data); }
            export typedef const GLubyte* (APIENTRYP PFNGLGETSTRINGPROC)(GLenum name);
            export GLAPI PFNGLGETSTRINGPROC glad_glGetString;
            export inline const GLubyte* glGetString(GLenum name) { return glad_glGetString(name); }
            export typedef void (APIENTRYP PFNGLGETTEXIMAGEPROC)(GLenum target, GLint level, GLenum format, GLenum type, void* pixels);
            export GLAPI PFNGLGETTEXIMAGEPROC glad_glGetTexImage;
            export inline void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void* pixels) { glad_glGetTexImage(target, level, format, type, pixels); }
            export typedef void (APIENTRYP PFNGLGETTEXPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat* params);
            export GLAPI PFNGLGETTEXPARAMETERFVPROC glad_glGetTexParameterfv;
            export inline void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat* params) { glad_glGetTexParameterfv(target, pname, params); }
            export typedef void (APIENTRYP PFNGLGETTEXPARAMETERIVPROC)(GLenum target, GLenum pname, GLint* params);
            export GLAPI PFNGLGETTEXPARAMETERIVPROC glad_glGetTexParameteriv;
            export inline void glGetTexParameteriv(GLenum target, GLenum pname, GLint* params) { glad_glGetTexParameteriv(target, pname, params); }
            export typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERFVPROC)(GLenum target, GLint level, GLenum pname, GLfloat* params);
            export GLAPI PFNGLGETTEXLEVELPARAMETERFVPROC glad_glGetTexLevelParameterfv;
            export inline void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat* params) { glad_glGetTexLevelParameterfv(target, level, pname, params); }
            export typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERIVPROC)(GLenum target, GLint level, GLenum pname, GLint* params);
            export GLAPI PFNGLGETTEXLEVELPARAMETERIVPROC glad_glGetTexLevelParameteriv;
            export inline void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint* params) { glad_glGetTexLevelParameteriv(target, level, pname, params); }
            export typedef GLboolean(APIENTRYP PFNGLISENABLEDPROC)(GLenum cap);
            export GLAPI PFNGLISENABLEDPROC glad_glIsEnabled;
            export inline GLboolean glIsEnabled(GLenum cap) { return glad_glIsEnabled(cap); }
            export typedef void (APIENTRYP PFNGLDEPTHRANGEPROC)(GLdouble n, GLdouble f);
            export GLAPI PFNGLDEPTHRANGEPROC glad_glDepthRange;
            export inline void glDepthRange(GLdouble n, GLdouble f) { glad_glDepthRange(n, f); }
            export typedef void (APIENTRYP PFNGLVIEWPORTPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
            export GLAPI PFNGLVIEWPORTPROC glad_glViewport;
            export inline void glViewport(GLint x, GLint y, GLsizei width, GLsizei height) { glad_glViewport(x, y, width, height); }
#endif
#ifndef GL_VERSION_1_1
            export GLAPI int GLAD_GL_VERSION_1_1;
            export typedef void (APIENTRYP PFNGLDRAWARRAYSPROC)(GLenum mode, GLint first, GLsizei count);
            export GLAPI PFNGLDRAWARRAYSPROC glad_glDrawArrays;
            export inline void glDrawArrays(GLenum mode, GLint first, GLsizei count) { glad_glDrawArrays(mode, first, count); }
            export typedef void (APIENTRYP PFNGLDRAWELEMENTSPROC)(GLenum mode, GLsizei count, GLenum type, const void* indices);
            export GLAPI PFNGLDRAWELEMENTSPROC glad_glDrawElements;
            export inline void glDrawElements(GLenum mode, GLsizei count, GLenum type, const void* indices) { glad_glDrawElements(mode, count, type, indices); }
            export typedef void (APIENTRYP PFNGLPOLYGONOFFSETPROC)(GLfloat factor, GLfloat units);
            export GLAPI PFNGLPOLYGONOFFSETPROC glad_glPolygonOffset;
            export inline void glPolygonOffset(GLfloat factor, GLfloat units) { glad_glPolygonOffset(factor, units); }
            export typedef void (APIENTRYP PFNGLCOPYTEXIMAGE1DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
            export GLAPI PFNGLCOPYTEXIMAGE1DPROC glad_glCopyTexImage1D;
            export inline void glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) { glad_glCopyTexImage1D(target, level, internalformat, x, y, width, border); }
            export typedef void (APIENTRYP PFNGLCOPYTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
            export GLAPI PFNGLCOPYTEXIMAGE2DPROC glad_glCopyTexImage2D;
            export inline void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) { glad_glCopyTexImage2D(target, level, internalformat, x, y, width, height, border); }
            export typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
            export GLAPI PFNGLCOPYTEXSUBIMAGE1DPROC glad_glCopyTexSubImage1D;
            export inline void glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) { glad_glCopyTexSubImage1D(target, level, xoffset, x, y, width); }
            export typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
            export GLAPI PFNGLCOPYTEXSUBIMAGE2DPROC glad_glCopyTexSubImage2D;
            export inline void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) { glad_glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height); }
            export typedef void (APIENTRYP PFNGLTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels);
            export GLAPI PFNGLTEXSUBIMAGE1DPROC glad_glTexSubImage1D;
            export inline void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels) { glad_glTexSubImage1D(target, level, xoffset, width, format, type, pixels); }
            export typedef void (APIENTRYP PFNGLTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels);
            export GLAPI PFNGLTEXSUBIMAGE2DPROC glad_glTexSubImage2D;
            export inline void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels) { glad_glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels); }
            export typedef void (APIENTRYP PFNGLBINDTEXTUREPROC)(GLenum target, GLuint texture);
            export GLAPI PFNGLBINDTEXTUREPROC glad_glBindTexture;
            export inline void glBindTexture(GLenum target, GLuint texture) { glad_glBindTexture(target, texture); }
            export typedef void (APIENTRYP PFNGLDELETETEXTURESPROC)(GLsizei n, const GLuint* textures);
            export GLAPI PFNGLDELETETEXTURESPROC glad_glDeleteTextures;
            export inline void glDeleteTextures(GLsizei n, const GLuint* textures) { glad_glDeleteTextures(n, textures); }
            export typedef void (APIENTRYP PFNGLGENTEXTURESPROC)(GLsizei n, GLuint* textures);
            export GLAPI PFNGLGENTEXTURESPROC glad_glGenTextures;
            export inline void glGenTextures(GLsizei n, GLuint* textures) { glad_glGenTextures(n, textures); }
            export typedef GLboolean(APIENTRYP PFNGLISTEXTUREPROC)(GLuint texture);
            export GLAPI PFNGLISTEXTUREPROC glad_glIsTexture;
            export inline GLboolean glIsTexture(GLuint texture) { return glad_glIsTexture(texture); }
#endif
#ifndef GL_VERSION_1_2
            export GLAPI int GLAD_GL_VERSION_1_2;
            export typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices);
            export GLAPI PFNGLDRAWRANGEELEMENTSPROC glad_glDrawRangeElements;
            export inline void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices) { glad_glDrawRangeElements(mode, start, end, count, type, indices); }
            export typedef void (APIENTRYP PFNGLTEXIMAGE3DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels);
            export GLAPI PFNGLTEXIMAGE3DPROC glad_glTexImage3D;
            export inline void glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels) { glad_glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels); }
            export typedef void (APIENTRYP PFNGLTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels);
            export GLAPI PFNGLTEXSUBIMAGE3DPROC glad_glTexSubImage3D;
            export inline void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels) { glad_glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels); }
            export typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
            export GLAPI PFNGLCOPYTEXSUBIMAGE3DPROC glad_glCopyTexSubImage3D;
            export inline void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) { glad_glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height); }
#endif
#ifndef GL_VERSION_1_3
            export GLAPI int GLAD_GL_VERSION_1_3;
            export typedef void (APIENTRYP PFNGLACTIVETEXTUREPROC)(GLenum texture);
            export GLAPI PFNGLACTIVETEXTUREPROC glad_glActiveTexture;
            export inline void glActiveTexture(GLenum texture) { glad_glActiveTexture(texture); }
            export typedef void (APIENTRYP PFNGLSAMPLECOVERAGEPROC)(GLfloat value, GLboolean invert);
            export GLAPI PFNGLSAMPLECOVERAGEPROC glad_glSampleCoverage;
            export inline void glSampleCoverage(GLfloat value, GLboolean invert) { glad_glSampleCoverage(value, invert); }
            export typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE3DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data);
            export GLAPI PFNGLCOMPRESSEDTEXIMAGE3DPROC glad_glCompressedTexImage3D;
            export inline void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data) { glad_glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data); }
            export typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data);
            export GLAPI PFNGLCOMPRESSEDTEXIMAGE2DPROC glad_glCompressedTexImage2D;
            export inline void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data) { glad_glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data); }
            export typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE1DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* data);
            export GLAPI PFNGLCOMPRESSEDTEXIMAGE1DPROC glad_glCompressedTexImage1D;
            export inline void glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* data) { glad_glCompressedTexImage1D(target, level, internalformat, width, border, imageSize, data); }
            export typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data);
            export GLAPI PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glad_glCompressedTexSubImage3D;
            export inline void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data) { glad_glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data); }
            export typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data);
            export GLAPI PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glad_glCompressedTexSubImage2D;
            export inline void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data) { glad_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data); }
            export typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data);
            export GLAPI PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glad_glCompressedTexSubImage1D;
            export inline void glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data) { glad_glCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data); }
            export typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXIMAGEPROC)(GLenum target, GLint level, void* img);
            export GLAPI PFNGLGETCOMPRESSEDTEXIMAGEPROC glad_glGetCompressedTexImage;
            export inline void glGetCompressedTexImage(GLenum target, GLint level, void* img) { glad_glGetCompressedTexImage(target, level, img); }
#endif
#ifndef GL_VERSION_1_4
            export GLAPI int GLAD_GL_VERSION_1_4;
            export typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEPROC)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
            export GLAPI PFNGLBLENDFUNCSEPARATEPROC glad_glBlendFuncSeparate;
            export inline void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) { glad_glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha); }
            export typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSPROC)(GLenum mode, const GLint* first, const GLsizei* count, GLsizei drawcount);
            export GLAPI PFNGLMULTIDRAWARRAYSPROC glad_glMultiDrawArrays;
            export inline void glMultiDrawArrays(GLenum mode, const GLint* first, const GLsizei* count, GLsizei drawcount) { glad_glMultiDrawArrays(mode, first, count, drawcount); }
            export typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSPROC)(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount);
            export GLAPI PFNGLMULTIDRAWELEMENTSPROC glad_glMultiDrawElements;
            export inline void glMultiDrawElements(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount) { glad_glMultiDrawElements(mode, count, type, indices, drawcount); }
            export typedef void (APIENTRYP PFNGLPOINTPARAMETERFPROC)(GLenum pname, GLfloat param);
            export GLAPI PFNGLPOINTPARAMETERFPROC glad_glPointParameterf;
            export inline void glPointParameterf(GLenum pname, GLfloat param) { glad_glPointParameterf(pname, param); }
            export typedef void (APIENTRYP PFNGLPOINTPARAMETERFVPROC)(GLenum pname, const GLfloat* params);
            export GLAPI PFNGLPOINTPARAMETERFVPROC glad_glPointParameterfv;
            export inline void glPointParameterfv(GLenum pname, const GLfloat* params) { glad_glPointParameterfv(pname, params); }
            export typedef void (APIENTRYP PFNGLPOINTPARAMETERIPROC)(GLenum pname, GLint param);
            export GLAPI PFNGLPOINTPARAMETERIPROC glad_glPointParameteri;
            export inline void glPointParameteri(GLenum pname, GLint param) { glad_glPointParameteri(pname, param); }
            export typedef void (APIENTRYP PFNGLPOINTPARAMETERIVPROC)(GLenum pname, const GLint* params);
            export GLAPI PFNGLPOINTPARAMETERIVPROC glad_glPointParameteriv;
            export inline void glPointParameteriv(GLenum pname, const GLint* params) { glad_glPointParameteriv(pname, params); }
            export typedef void (APIENTRYP PFNGLBLENDCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
            export GLAPI PFNGLBLENDCOLORPROC glad_glBlendColor;
            export inline void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) { glad_glBlendColor(red, green, blue, alpha); }
            export typedef void (APIENTRYP PFNGLBLENDEQUATIONPROC)(GLenum mode);
            export GLAPI PFNGLBLENDEQUATIONPROC glad_glBlendEquation;
            export inline void glBlendEquation(GLenum mode) { glad_glBlendEquation(mode); }
#endif
#ifndef GL_VERSION_1_5
            export GLAPI int GLAD_GL_VERSION_1_5;
            export typedef void (APIENTRYP PFNGLGENQUERIESPROC)(GLsizei n, GLuint* ids);
            export GLAPI PFNGLGENQUERIESPROC glad_glGenQueries;
            export inline void glGenQueries(GLsizei n, GLuint* ids) { glad_glGenQueries(n, ids); }
            export typedef void (APIENTRYP PFNGLDELETEQUERIESPROC)(GLsizei n, const GLuint* ids);
            export GLAPI PFNGLDELETEQUERIESPROC glad_glDeleteQueries;
            export inline void glDeleteQueries(GLsizei n, const GLuint* ids) { glad_glDeleteQueries(n, ids); }
            export typedef GLboolean(APIENTRYP PFNGLISQUERYPROC)(GLuint id);
            export GLAPI PFNGLISQUERYPROC glad_glIsQuery;
            export inline GLboolean glIsQuery(GLuint id) { return glad_glIsQuery(id); }
            export typedef void (APIENTRYP PFNGLBEGINQUERYPROC)(GLenum target, GLuint id);
            export GLAPI PFNGLBEGINQUERYPROC glad_glBeginQuery;
            export inline void glBeginQuery(GLenum target, GLuint id) { glad_glBeginQuery(target, id); }
            export typedef void (APIENTRYP PFNGLENDQUERYPROC)(GLenum target);
            export GLAPI PFNGLENDQUERYPROC glad_glEndQuery;
            export inline void glEndQuery(GLenum target) { glad_glEndQuery(target); }
            export typedef void (APIENTRYP PFNGLGETQUERYIVPROC)(GLenum target, GLenum pname, GLint* params);
            export GLAPI PFNGLGETQUERYIVPROC glad_glGetQueryiv;
            export inline void glGetQueryiv(GLenum target, GLenum pname, GLint* params) { glad_glGetQueryiv(target, pname, params); }
            export typedef void (APIENTRYP PFNGLGETQUERYOBJECTIVPROC)(GLuint id, GLenum pname, GLint* params);
            export GLAPI PFNGLGETQUERYOBJECTIVPROC glad_glGetQueryObjectiv;
            export inline void glGetQueryObjectiv(GLuint id, GLenum pname, GLint* params) { glad_glGetQueryObjectiv(id, pname, params); }
            export typedef void (APIENTRYP PFNGLGETQUERYOBJECTUIVPROC)(GLuint id, GLenum pname, GLuint* params);
            export GLAPI PFNGLGETQUERYOBJECTUIVPROC glad_glGetQueryObjectuiv;
            export inline void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint* params) { glad_glGetQueryObjectuiv(id, pname, params); }
            export typedef void (APIENTRYP PFNGLBINDBUFFERPROC)(GLenum target, GLuint buffer);
            export GLAPI PFNGLBINDBUFFERPROC glad_glBindBuffer;
            export inline void glBindBuffer(GLenum target, GLuint buffer) { glad_glBindBuffer(target, buffer); }
            export typedef void (APIENTRYP PFNGLDELETEBUFFERSPROC)(GLsizei n, const GLuint* buffers);
            export GLAPI PFNGLDELETEBUFFERSPROC glad_glDeleteBuffers;
            /// <summary>
            /// Deletes the buffers (count n) specified by the buffers array. the array contains the ids of the buffers to be deleted.
            /// </summary>
            /// <param name="n"></param>
            /// <param name="buffers"></param>
            export inline void glDeleteBuffers(GLsizei n, const GLuint* buffers) { glad_glDeleteBuffers(n, buffers); }
            export typedef void (APIENTRYP PFNGLGENBUFFERSPROC)(GLsizei n, GLuint* buffers);
            export GLAPI PFNGLGENBUFFERSPROC glad_glGenBuffers;
            /// <summary>
            /// generates n buffers and stores their ids in the buffers array.
            /// </summary>
            /// <param name="n"></param>
            /// <param name="buffers"></param>
            export inline void glGenBuffers(GLsizei n, GLuint* buffers) { glad_glGenBuffers(n, buffers); }
            export typedef GLboolean(APIENTRYP PFNGLISBUFFERPROC)(GLuint buffer);
            export GLAPI PFNGLISBUFFERPROC glad_glIsBuffer;
            export inline GLboolean glIsBuffer(GLuint buffer) { return glad_glIsBuffer(buffer); }
            export typedef void (APIENTRYP PFNGLBUFFERDATAPROC)(GLenum target, GLsizeiptr size, const void* data, GLenum usage);
            export GLAPI PFNGLBUFFERDATAPROC glad_glBufferData;
            export inline void glBufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage) { glad_glBufferData(target, size, data, usage); }
            export typedef void (APIENTRYP PFNGLBUFFERSUBDATAPROC)(GLenum target, GLintptr offset, GLsizeiptr size, const void* data);
            export GLAPI PFNGLBUFFERSUBDATAPROC glad_glBufferSubData;
            export inline void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void* data) { glad_glBufferSubData(target, offset, size, data); }
            export typedef void (APIENTRYP PFNGLGETBUFFERSUBDATAPROC)(GLenum target, GLintptr offset, GLsizeiptr size, void* data);
            export GLAPI PFNGLGETBUFFERSUBDATAPROC glad_glGetBufferSubData;
            export inline void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void* data) { glad_glGetBufferSubData(target, offset, size, data); }
            export typedef void* (APIENTRYP PFNGLMAPBUFFERPROC)(GLenum target, GLenum access);
            export GLAPI PFNGLMAPBUFFERPROC glad_glMapBuffer;
            export inline void* glMapBuffer(GLenum target, GLenum access) { return glad_glMapBuffer(target, access); }
            export typedef GLboolean(APIENTRYP PFNGLUNMAPBUFFERPROC)(GLenum target);
            export GLAPI PFNGLUNMAPBUFFERPROC glad_glUnmapBuffer;
            export inline GLboolean glUnmapBuffer(GLenum target) { return glad_glUnmapBuffer(target); }
            export typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint* params);
            export GLAPI PFNGLGETBUFFERPARAMETERIVPROC glad_glGetBufferParameteriv;
            export inline void glGetBufferParameteriv(GLenum target, GLenum pname, GLint* params) { glad_glGetBufferParameteriv(target, pname, params); }
            export typedef void (APIENTRYP PFNGLGETBUFFERPOINTERVPROC)(GLenum target, GLenum pname, void** params);
            export GLAPI PFNGLGETBUFFERPOINTERVPROC glad_glGetBufferPointerv;
            export inline void glGetBufferPointerv(GLenum target, GLenum pname, void** params) { glad_glGetBufferPointerv(target, pname, params); }
#endif
#ifndef GL_VERSION_2_0
            export GLAPI int GLAD_GL_VERSION_2_0;
            export typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEPROC)(GLenum modeRGB, GLenum modeAlpha);
            export GLAPI PFNGLBLENDEQUATIONSEPARATEPROC glad_glBlendEquationSeparate;
            export inline void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) { glad_glBlendEquationSeparate(modeRGB, modeAlpha); }
            export typedef void (APIENTRYP PFNGLDRAWBUFFERSPROC)(GLsizei n, const GLenum* bufs);
            export GLAPI PFNGLDRAWBUFFERSPROC glad_glDrawBuffers;
            export inline void glDrawBuffers(GLsizei n, const GLenum* bufs) { glad_glDrawBuffers(n, bufs); }
            export typedef void (APIENTRYP PFNGLSTENCILOPSEPARATEPROC)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
            export GLAPI PFNGLSTENCILOPSEPARATEPROC glad_glStencilOpSeparate;
            export inline void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) { glad_glStencilOpSeparate(face, sfail, dpfail, dppass); }
            export typedef void (APIENTRYP PFNGLSTENCILFUNCSEPARATEPROC)(GLenum face, GLenum func, GLint ref, GLuint mask);
            export GLAPI PFNGLSTENCILFUNCSEPARATEPROC glad_glStencilFuncSeparate;
            export inline void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) { glad_glStencilFuncSeparate(face, func, ref, mask); }
            export typedef void (APIENTRYP PFNGLSTENCILMASKSEPARATEPROC)(GLenum face, GLuint mask);
            export GLAPI PFNGLSTENCILMASKSEPARATEPROC glad_glStencilMaskSeparate;
            export inline void glStencilMaskSeparate(GLenum face, GLuint mask) { glad_glStencilMaskSeparate(face, mask); }
            export typedef void (APIENTRYP PFNGLATTACHSHADERPROC)(GLuint program, GLuint shader);
            export GLAPI PFNGLATTACHSHADERPROC glad_glAttachShader;
            export inline void glAttachShader(GLuint program, GLuint shader) { glad_glAttachShader(program, shader); }
            export typedef void (APIENTRYP PFNGLBINDATTRIBLOCATIONPROC)(GLuint program, GLuint index, const GLchar* name);
            export GLAPI PFNGLBINDATTRIBLOCATIONPROC glad_glBindAttribLocation;
            export inline void glBindAttribLocation(GLuint program, GLuint index, const GLchar* name) { glad_glBindAttribLocation(program, index, name); }
            export typedef void (APIENTRYP PFNGLCOMPILESHADERPROC)(GLuint shader);
            export GLAPI PFNGLCOMPILESHADERPROC glad_glCompileShader;
            export inline void glCompileShader(GLuint shader) { glad_glCompileShader(shader); }
            export typedef GLuint(APIENTRYP PFNGLCREATEPROGRAMPROC)(void);
            export GLAPI PFNGLCREATEPROGRAMPROC glad_glCreateProgram;
            export inline GLuint glCreateProgram() { return glad_glCreateProgram(); }
            export typedef GLuint(APIENTRYP PFNGLCREATESHADERPROC)(GLenum type);
            export GLAPI PFNGLCREATESHADERPROC glad_glCreateShader;
            export inline GLuint glCreateShader(GLenum type) { return glad_glCreateShader(type); }
            export typedef void (APIENTRYP PFNGLDELETEPROGRAMPROC)(GLuint program);
            export GLAPI PFNGLDELETEPROGRAMPROC glad_glDeleteProgram;
            export inline void glDeleteProgram(GLuint program) { glad_glDeleteProgram(program); }
            export typedef void (APIENTRYP PFNGLDELETESHADERPROC)(GLuint shader);
            export GLAPI PFNGLDELETESHADERPROC glad_glDeleteShader;
            export inline void glDeleteShader(GLuint shader) { glad_glDeleteShader(shader); }
            export typedef void (APIENTRYP PFNGLDETACHSHADERPROC)(GLuint program, GLuint shader);
            export GLAPI PFNGLDETACHSHADERPROC glad_glDetachShader;
            export inline void glDetachShader(GLuint program, GLuint shader) { glad_glDetachShader(program, shader); }
            export typedef void (APIENTRYP PFNGLDISABLEVERTEXATTRIBARRAYPROC)(GLuint index);
            export GLAPI PFNGLDISABLEVERTEXATTRIBARRAYPROC glad_glDisableVertexAttribArray;
            export inline void glDisableVertexAttribArray(GLuint index) { glad_glDisableVertexAttribArray(index); }
            export typedef void (APIENTRYP PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint index);
            export GLAPI PFNGLENABLEVERTEXATTRIBARRAYPROC glad_glEnableVertexAttribArray;
            export inline void glEnableVertexAttribArray(GLuint index) { glad_glEnableVertexAttribArray(index); }
            export typedef void (APIENTRYP PFNGLGETACTIVEATTRIBPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
            export GLAPI PFNGLGETACTIVEATTRIBPROC glad_glGetActiveAttrib;
            export inline void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name) { glad_glGetActiveAttrib(program, index, bufSize, length, size, type, name); }
            export typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
            export GLAPI PFNGLGETACTIVEUNIFORMPROC glad_glGetActiveUniform;
            export inline void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name) { glad_glGetActiveUniform(program, index, bufSize, length, size, type, name); }
            export typedef void (APIENTRYP PFNGLGETATTACHEDSHADERSPROC)(GLuint program, GLsizei maxCount, GLsizei* count, GLuint* shaders);
            export GLAPI PFNGLGETATTACHEDSHADERSPROC glad_glGetAttachedShaders;
            export inline void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei* count, GLuint* shaders) { glad_glGetAttachedShaders(program, maxCount, count, shaders); }
            export typedef GLint(APIENTRYP PFNGLGETATTRIBLOCATIONPROC)(GLuint program, const GLchar* name);
            export GLAPI PFNGLGETATTRIBLOCATIONPROC glad_glGetAttribLocation;
            export inline GLint glGetAttribLocation(GLuint program, const GLchar* name) { return glad_glGetAttribLocation(program, name); }
            export typedef void (APIENTRYP PFNGLGETPROGRAMIVPROC)(GLuint program, GLenum pname, GLint* params);
            export GLAPI PFNGLGETPROGRAMIVPROC glad_glGetProgramiv;
            export inline void glGetProgramiv(GLuint program, GLenum pname, GLint* params) { glad_glGetProgramiv(program, pname, params); }
            export typedef void (APIENTRYP PFNGLGETPROGRAMINFOLOGPROC)(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
            export GLAPI PFNGLGETPROGRAMINFOLOGPROC glad_glGetProgramInfoLog;
            export inline void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog) { glad_glGetProgramInfoLog(program, bufSize, length, infoLog); }
            export typedef void (APIENTRYP PFNGLGETSHADERIVPROC)(GLuint shader, GLenum pname, GLint* params);
            export GLAPI PFNGLGETSHADERIVPROC glad_glGetShaderiv;
            export inline void glGetShaderiv(GLuint shader, GLenum pname, GLint* params) { glad_glGetShaderiv(shader, pname, params); }
            export typedef void (APIENTRYP PFNGLGETSHADERINFOLOGPROC)(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
            export GLAPI PFNGLGETSHADERINFOLOGPROC glad_glGetShaderInfoLog;
            export inline void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog) { glad_glGetShaderInfoLog(shader, bufSize, length, infoLog); }
            export typedef void (APIENTRYP PFNGLGETSHADERSOURCEPROC)(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source);
            export GLAPI PFNGLGETSHADERSOURCEPROC glad_glGetShaderSource;
            export inline void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source) { glad_glGetShaderSource(shader, bufSize, length, source); }
            export typedef GLint(APIENTRYP PFNGLGETUNIFORMLOCATIONPROC)(GLuint program, const GLchar* name);
            export GLAPI PFNGLGETUNIFORMLOCATIONPROC glad_glGetUniformLocation;
            export inline GLint glGetUniformLocation(GLuint program, const GLchar* name) { return glad_glGetUniformLocation(program, name); }
            export typedef void (APIENTRYP PFNGLGETUNIFORMFVPROC)(GLuint program, GLint location, GLfloat* params);
            export GLAPI PFNGLGETUNIFORMFVPROC glad_glGetUniformfv;
            export inline void glGetUniformfv(GLuint program, GLint location, GLfloat* params) { glad_glGetUniformfv(program, location, params); }
            export typedef void (APIENTRYP PFNGLGETUNIFORMIVPROC)(GLuint program, GLint location, GLint* params);
            export GLAPI PFNGLGETUNIFORMIVPROC glad_glGetUniformiv;
            export inline void glGetUniformiv(GLuint program, GLint location, GLint* params) { glad_glGetUniformiv(program, location, params); }
            export typedef void (APIENTRYP PFNGLGETVERTEXATTRIBDVPROC)(GLuint index, GLenum pname, GLdouble* params);
            export GLAPI PFNGLGETVERTEXATTRIBDVPROC glad_glGetVertexAttribdv;
            export inline void glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble* params) { glad_glGetVertexAttribdv(index, pname, params); }
            export typedef void (APIENTRYP PFNGLGETVERTEXATTRIBFVPROC)(GLuint index, GLenum pname, GLfloat* params);
            export GLAPI PFNGLGETVERTEXATTRIBFVPROC glad_glGetVertexAttribfv;
            export inline void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat* params) { glad_glGetVertexAttribfv(index, pname, params); }
            export typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIVPROC)(GLuint index, GLenum pname, GLint* params);
            export GLAPI PFNGLGETVERTEXATTRIBIVPROC glad_glGetVertexAttribiv;
            export inline void glGetVertexAttribiv(GLuint index, GLenum pname, GLint* params) { glad_glGetVertexAttribiv(index, pname, params); }
            export typedef void (APIENTRYP PFNGLGETVERTEXATTRIBPOINTERVPROC)(GLuint index, GLenum pname, void** pointer);
            export GLAPI PFNGLGETVERTEXATTRIBPOINTERVPROC glad_glGetVertexAttribPointerv;
            export inline void glGetVertexAttribPointerv(GLuint index, GLenum pname, void** pointer) { glad_glGetVertexAttribPointerv(index, pname, pointer); }
            export typedef GLboolean(APIENTRYP PFNGLISPROGRAMPROC)(GLuint program);
            export GLAPI PFNGLISPROGRAMPROC glad_glIsProgram;
            export inline GLboolean glIsProgram(GLuint program) { return glad_glIsProgram(program); }
            export typedef GLboolean(APIENTRYP PFNGLISSHADERPROC)(GLuint shader);
            export GLAPI PFNGLISSHADERPROC glad_glIsShader;
            export inline GLboolean glIsShader(GLuint shader) { return glad_glIsShader(shader); }
            export typedef void (APIENTRYP PFNGLLINKPROGRAMPROC)(GLuint program);
            export GLAPI PFNGLLINKPROGRAMPROC glad_glLinkProgram;
            export inline void glLinkProgram(GLuint program) { glad_glLinkProgram(program); }
            export typedef void (APIENTRYP PFNGLSHADERSOURCEPROC)(GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length);
            export GLAPI PFNGLSHADERSOURCEPROC glad_glShaderSource;
            export inline void glShaderSource(GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length) { glad_glShaderSource(shader, count, string, length); }
            export typedef void (APIENTRYP PFNGLUSEPROGRAMPROC)(GLuint program);
            export GLAPI PFNGLUSEPROGRAMPROC glad_glUseProgram;
            export inline void glUseProgram(GLuint program) { glad_glUseProgram(program); }
            export typedef void (APIENTRYP PFNGLUNIFORM1FPROC)(GLint location, GLfloat v0);
            export GLAPI PFNGLUNIFORM1FPROC glad_glUniform1f;
            export inline void glUniform1f(GLint location, GLfloat v0) { glad_glUniform1f(location, v0); }
            export typedef void (APIENTRYP PFNGLUNIFORM2FPROC)(GLint location, GLfloat v0, GLfloat v1);
            export GLAPI PFNGLUNIFORM2FPROC glad_glUniform2f;
            export inline void glUniform2f(GLint location, GLfloat v0, GLfloat v1) { glad_glUniform2f(location, v0, v1); }
            export typedef void (APIENTRYP PFNGLUNIFORM3FPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
            export GLAPI PFNGLUNIFORM3FPROC glad_glUniform3f;
            export inline void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) { glad_glUniform3f(location, v0, v1, v2); }
            export typedef void (APIENTRYP PFNGLUNIFORM4FPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
            export GLAPI PFNGLUNIFORM4FPROC glad_glUniform4f;
            export inline void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) { glad_glUniform4f(location, v0, v1, v2, v3); }
            export typedef void (APIENTRYP PFNGLUNIFORM1IPROC)(GLint location, GLint v0);
            export GLAPI PFNGLUNIFORM1IPROC glad_glUniform1i;
            export inline void glUniform1i(GLint location, GLint v0) { glad_glUniform1i(location, v0); }
            export typedef void (APIENTRYP PFNGLUNIFORM2IPROC)(GLint location, GLint v0, GLint v1);
            export GLAPI PFNGLUNIFORM2IPROC glad_glUniform2i;
            export inline void glUniform2i(GLint location, GLint v0, GLint v1) { glad_glUniform2i(location, v0, v1); }
            export typedef void (APIENTRYP PFNGLUNIFORM3IPROC)(GLint location, GLint v0, GLint v1, GLint v2);
            export GLAPI PFNGLUNIFORM3IPROC glad_glUniform3i;
            export inline void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) { glad_glUniform3i(location, v0, v1, v2); }
            export typedef void (APIENTRYP PFNGLUNIFORM4IPROC)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
            export GLAPI PFNGLUNIFORM4IPROC glad_glUniform4i;
            export inline void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) { glad_glUniform4i(location, v0, v1, v2, v3); }
            export typedef void (APIENTRYP PFNGLUNIFORM1FVPROC)(GLint location, GLsizei count, const GLfloat* value);
            export GLAPI PFNGLUNIFORM1FVPROC glad_glUniform1fv;
            export inline void glUniform1fv(GLint location, GLsizei count, const GLfloat* value) { glad_glUniform1fv(location, count, value); }
            export typedef void (APIENTRYP PFNGLUNIFORM2FVPROC)(GLint location, GLsizei count, const GLfloat* value);
            export GLAPI PFNGLUNIFORM2FVPROC glad_glUniform2fv;
            export inline void glUniform2fv(GLint location, GLsizei count, const GLfloat* value) { glad_glUniform2fv(location, count, value); }
            export typedef void (APIENTRYP PFNGLUNIFORM3FVPROC)(GLint location, GLsizei count, const GLfloat* value);
            export GLAPI PFNGLUNIFORM3FVPROC glad_glUniform3fv;
            export inline void glUniform3fv(GLint location, GLsizei count, const GLfloat* value) { glad_glUniform3fv(location, count, value); }
            export typedef void (APIENTRYP PFNGLUNIFORM4FVPROC)(GLint location, GLsizei count, const GLfloat* value);
            export GLAPI PFNGLUNIFORM4FVPROC glad_glUniform4fv;
            export inline void glUniform4fv(GLint location, GLsizei count, const GLfloat* value) { glad_glUniform4fv(location, count, value); }
            export typedef void (APIENTRYP PFNGLUNIFORM1IVPROC)(GLint location, GLsizei count, const GLint* value);
            export GLAPI PFNGLUNIFORM1IVPROC glad_glUniform1iv;
            export inline void glUniform1iv(GLint location, GLsizei count, const GLint* value) { glad_glUniform1iv(location, count, value); }
            export typedef void (APIENTRYP PFNGLUNIFORM2IVPROC)(GLint location, GLsizei count, const GLint* value);
            export GLAPI PFNGLUNIFORM2IVPROC glad_glUniform2iv;
            export inline void glUniform2iv(GLint location, GLsizei count, const GLint* value) { glad_glUniform2iv(location, count, value); }
            export typedef void (APIENTRYP PFNGLUNIFORM3IVPROC)(GLint location, GLsizei count, const GLint* value);
            export GLAPI PFNGLUNIFORM3IVPROC glad_glUniform3iv;
            export inline void glUniform3iv(GLint location, GLsizei count, const GLint* value) { glad_glUniform3iv(location, count, value); }
            export typedef void (APIENTRYP PFNGLUNIFORM4IVPROC)(GLint location, GLsizei count, const GLint* value);
            export GLAPI PFNGLUNIFORM4IVPROC glad_glUniform4iv;
            export inline void glUniform4iv(GLint location, GLsizei count, const GLint* value) { glad_glUniform4iv(location, count, value); }
            export typedef void (APIENTRYP PFNGLUNIFORMMATRIX2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
            export GLAPI PFNGLUNIFORMMATRIX2FVPROC glad_glUniformMatrix2fv;
            export inline void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { glad_glUniformMatrix2fv(location, count, transpose, value); }
            export typedef void (APIENTRYP PFNGLUNIFORMMATRIX3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
            export GLAPI PFNGLUNIFORMMATRIX3FVPROC glad_glUniformMatrix3fv;
            export inline void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { glad_glUniformMatrix3fv(location, count, transpose, value); }
            export typedef void (APIENTRYP PFNGLUNIFORMMATRIX4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
            export GLAPI PFNGLUNIFORMMATRIX4FVPROC glad_glUniformMatrix4fv;
            export inline void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { glad_glUniformMatrix4fv(location, count, transpose, value); }
            export typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPROC)(GLuint program);
            export GLAPI PFNGLVALIDATEPROGRAMPROC glad_glValidateProgram;
            export inline void glValidateProgram(GLuint program) { glad_glValidateProgram(program); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB1DPROC)(GLuint index, GLdouble x);
            export GLAPI PFNGLVERTEXATTRIB1DPROC glad_glVertexAttrib1d;
            export inline void glVertexAttrib1d(GLuint index, GLdouble x) { glad_glVertexAttrib1d(index, x); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB1DVPROC)(GLuint index, const GLdouble* v);
            export GLAPI PFNGLVERTEXATTRIB1DVPROC glad_glVertexAttrib1dv;
            export inline void glVertexAttrib1dv(GLuint index, const GLdouble* v) { glad_glVertexAttrib1dv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB1FPROC)(GLuint index, GLfloat x);
            export GLAPI PFNGLVERTEXATTRIB1FPROC glad_glVertexAttrib1f;
            export inline void glVertexAttrib1f(GLuint index, GLfloat x) { glad_glVertexAttrib1f(index, x); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB1FVPROC)(GLuint index, const GLfloat* v);
            export GLAPI PFNGLVERTEXATTRIB1FVPROC glad_glVertexAttrib1fv;
            export inline void glVertexAttrib1fv(GLuint index, const GLfloat* v) { glad_glVertexAttrib1fv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB1SPROC)(GLuint index, GLshort x);
            export GLAPI PFNGLVERTEXATTRIB1SPROC glad_glVertexAttrib1s;
            export inline void glVertexAttrib1s(GLuint index, GLshort x) { glad_glVertexAttrib1s(index, x); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB1SVPROC)(GLuint index, const GLshort* v);
            export GLAPI PFNGLVERTEXATTRIB1SVPROC glad_glVertexAttrib1sv;
            export inline void glVertexAttrib1sv(GLuint index, const GLshort* v) { glad_glVertexAttrib1sv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB2DPROC)(GLuint index, GLdouble x, GLdouble y);
            export GLAPI PFNGLVERTEXATTRIB2DPROC glad_glVertexAttrib2d;
            export inline void glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y) { glad_glVertexAttrib2d(index, x, y); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB2DVPROC)(GLuint index, const GLdouble* v);
            export GLAPI PFNGLVERTEXATTRIB2DVPROC glad_glVertexAttrib2dv;
            export inline void glVertexAttrib2dv(GLuint index, const GLdouble* v) { glad_glVertexAttrib2dv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB2FPROC)(GLuint index, GLfloat x, GLfloat y);
            export GLAPI PFNGLVERTEXATTRIB2FPROC glad_glVertexAttrib2f;
            export inline void glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) { glad_glVertexAttrib2f(index, x, y); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB2FVPROC)(GLuint index, const GLfloat* v);
            export GLAPI PFNGLVERTEXATTRIB2FVPROC glad_glVertexAttrib2fv;
            export inline void glVertexAttrib2fv(GLuint index, const GLfloat* v) { glad_glVertexAttrib2fv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB2SPROC)(GLuint index, GLshort x, GLshort y);
            export GLAPI PFNGLVERTEXATTRIB2SPROC glad_glVertexAttrib2s;
            export inline void glVertexAttrib2s(GLuint index, GLshort x, GLshort y) { glad_glVertexAttrib2s(index, x, y); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB2SVPROC)(GLuint index, const GLshort* v);
            export GLAPI PFNGLVERTEXATTRIB2SVPROC glad_glVertexAttrib2sv;
            export inline void glVertexAttrib2sv(GLuint index, const GLshort* v) { glad_glVertexAttrib2sv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB3DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
            export GLAPI PFNGLVERTEXATTRIB3DPROC glad_glVertexAttrib3d;
            export inline void glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) { glad_glVertexAttrib3d(index, x, y, z); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB3DVPROC)(GLuint index, const GLdouble* v);
            export GLAPI PFNGLVERTEXATTRIB3DVPROC glad_glVertexAttrib3dv;
            export inline void glVertexAttrib3dv(GLuint index, const GLdouble* v) { glad_glVertexAttrib3dv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB3FPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
            export GLAPI PFNGLVERTEXATTRIB3FPROC glad_glVertexAttrib3f;
            export inline void glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) { glad_glVertexAttrib3f(index, x, y, z); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB3FVPROC)(GLuint index, const GLfloat* v);
            export GLAPI PFNGLVERTEXATTRIB3FVPROC glad_glVertexAttrib3fv;
            export inline void glVertexAttrib3fv(GLuint index, const GLfloat* v) { glad_glVertexAttrib3fv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB3SPROC)(GLuint index, GLshort x, GLshort y, GLshort z);
            export GLAPI PFNGLVERTEXATTRIB3SPROC glad_glVertexAttrib3s;
            export inline void glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z) { glad_glVertexAttrib3s(index, x, y, z); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB3SVPROC)(GLuint index, const GLshort* v);
            export GLAPI PFNGLVERTEXATTRIB3SVPROC glad_glVertexAttrib3sv;
            export inline void glVertexAttrib3sv(GLuint index, const GLshort* v) { glad_glVertexAttrib3sv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB4NBVPROC)(GLuint index, const GLbyte* v);
            export GLAPI PFNGLVERTEXATTRIB4NBVPROC glad_glVertexAttrib4Nbv;
            export inline void glVertexAttrib4Nbv(GLuint index, const GLbyte* v) { glad_glVertexAttrib4Nbv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB4NIVPROC)(GLuint index, const GLint* v);
            export GLAPI PFNGLVERTEXATTRIB4NIVPROC glad_glVertexAttrib4Niv;
            export inline void glVertexAttrib4Niv(GLuint index, const GLint* v) { glad_glVertexAttrib4Niv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB4NSVPROC)(GLuint index, const GLshort* v);
            export GLAPI PFNGLVERTEXATTRIB4NSVPROC glad_glVertexAttrib4Nsv;
            export inline void glVertexAttrib4Nsv(GLuint index, const GLshort* v) { glad_glVertexAttrib4Nsv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBPROC)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
            export GLAPI PFNGLVERTEXATTRIB4NUBPROC glad_glVertexAttrib4Nub;
            export inline void glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) { glad_glVertexAttrib4Nub(index, x, y, z, w); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBVPROC)(GLuint index, const GLubyte* v);
            export GLAPI PFNGLVERTEXATTRIB4NUBVPROC glad_glVertexAttrib4Nubv;
            export inline void glVertexAttrib4Nubv(GLuint index, const GLubyte* v) { glad_glVertexAttrib4Nubv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUIVPROC)(GLuint index, const GLuint* v);
            export GLAPI PFNGLVERTEXATTRIB4NUIVPROC glad_glVertexAttrib4Nuiv;
            export inline void glVertexAttrib4Nuiv(GLuint index, const GLuint* v) { glad_glVertexAttrib4Nuiv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUSVPROC)(GLuint index, const GLushort* v);
            export GLAPI PFNGLVERTEXATTRIB4NUSVPROC glad_glVertexAttrib4Nusv;
            export inline void glVertexAttrib4Nusv(GLuint index, const GLushort* v) { glad_glVertexAttrib4Nusv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB4BVPROC)(GLuint index, const GLbyte* v);
            export GLAPI PFNGLVERTEXATTRIB4BVPROC glad_glVertexAttrib4bv;
            export inline void glVertexAttrib4bv(GLuint index, const GLbyte* v) { glad_glVertexAttrib4bv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB4DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
            export GLAPI PFNGLVERTEXATTRIB4DPROC glad_glVertexAttrib4d;
            export inline void glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) { glad_glVertexAttrib4d(index, x, y, z, w); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB4DVPROC)(GLuint index, const GLdouble* v);
            export GLAPI PFNGLVERTEXATTRIB4DVPROC glad_glVertexAttrib4dv;
            export inline void glVertexAttrib4dv(GLuint index, const GLdouble* v) { glad_glVertexAttrib4dv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB4FPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
            export GLAPI PFNGLVERTEXATTRIB4FPROC glad_glVertexAttrib4f;
            export inline void glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) { glad_glVertexAttrib4f(index, x, y, z, w); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB4FVPROC)(GLuint index, const GLfloat* v);
            export GLAPI PFNGLVERTEXATTRIB4FVPROC glad_glVertexAttrib4fv;
            export inline void glVertexAttrib4fv(GLuint index, const GLfloat* v) { glad_glVertexAttrib4fv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB4IVPROC)(GLuint index, const GLint* v);
            export GLAPI PFNGLVERTEXATTRIB4IVPROC glad_glVertexAttrib4iv;
            export inline void glVertexAttrib4iv(GLuint index, const GLint* v) { glad_glVertexAttrib4iv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB4SPROC)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
            export GLAPI PFNGLVERTEXATTRIB4SPROC glad_glVertexAttrib4s;
            export inline void glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) { glad_glVertexAttrib4s(index, x, y, z, w); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB4SVPROC)(GLuint index, const GLshort* v);
            export GLAPI PFNGLVERTEXATTRIB4SVPROC glad_glVertexAttrib4sv;
            export inline void glVertexAttrib4sv(GLuint index, const GLshort* v) { glad_glVertexAttrib4sv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB4UBVPROC)(GLuint index, const GLubyte* v);
            export GLAPI PFNGLVERTEXATTRIB4UBVPROC glad_glVertexAttrib4ubv;
            export inline void glVertexAttrib4ubv(GLuint index, const GLubyte* v) { glad_glVertexAttrib4ubv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB4UIVPROC)(GLuint index, const GLuint* v);
            export GLAPI PFNGLVERTEXATTRIB4UIVPROC glad_glVertexAttrib4uiv;
            export inline void glVertexAttrib4uiv(GLuint index, const GLuint* v) { glad_glVertexAttrib4uiv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIB4USVPROC)(GLuint index, const GLushort* v);
            export GLAPI PFNGLVERTEXATTRIB4USVPROC glad_glVertexAttrib4usv;
            export inline void glVertexAttrib4usv(GLuint index, const GLushort* v) { glad_glVertexAttrib4usv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIBPOINTERPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);
            export GLAPI PFNGLVERTEXATTRIBPOINTERPROC glad_glVertexAttribPointer;
            export inline void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer) { glad_glVertexAttribPointer(index, size, type, normalized, stride, pointer); }
#endif
#ifndef GL_VERSION_2_1
            export GLAPI int GLAD_GL_VERSION_2_1;
            export typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
            export GLAPI PFNGLUNIFORMMATRIX2X3FVPROC glad_glUniformMatrix2x3fv;
            export inline void glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { glad_glUniformMatrix2x3fv(location, count, transpose, value); }
            export typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
            export GLAPI PFNGLUNIFORMMATRIX3X2FVPROC glad_glUniformMatrix3x2fv;
            export inline void glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { glad_glUniformMatrix3x2fv(location, count, transpose, value); }
            export typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
            export GLAPI PFNGLUNIFORMMATRIX2X4FVPROC glad_glUniformMatrix2x4fv;
            export inline void glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { glad_glUniformMatrix2x4fv(location, count, transpose, value); }
            export typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
            export GLAPI PFNGLUNIFORMMATRIX4X2FVPROC glad_glUniformMatrix4x2fv;
            export inline void glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { glad_glUniformMatrix4x2fv(location, count, transpose, value); }
            export typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
            export GLAPI PFNGLUNIFORMMATRIX3X4FVPROC glad_glUniformMatrix3x4fv;
            export inline void glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { glad_glUniformMatrix3x4fv(location, count, transpose, value); }
            export typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
            export GLAPI PFNGLUNIFORMMATRIX4X3FVPROC glad_glUniformMatrix4x3fv;
            export inline void glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { glad_glUniformMatrix4x3fv(location, count, transpose, value); }
#endif
#ifndef GL_VERSION_3_0
            export GLAPI int GLAD_GL_VERSION_3_0;
            export typedef void (APIENTRYP PFNGLCOLORMASKIPROC)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
            export GLAPI PFNGLCOLORMASKIPROC glad_glColorMaski;
            export inline void glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) { glad_glColorMaski(index, r, g, b, a); }
            export typedef void (APIENTRYP PFNGLGETBOOLEANI_VPROC)(GLenum target, GLuint index, GLboolean* data);
            export GLAPI PFNGLGETBOOLEANI_VPROC glad_glGetBooleani_v;
            export inline void glGetBooleani_v(GLenum target, GLuint index, GLboolean* data) { glad_glGetBooleani_v(target, index, data); }
            export typedef void (APIENTRYP PFNGLGETINTEGERI_VPROC)(GLenum target, GLuint index, GLint* data);
            export GLAPI PFNGLGETINTEGERI_VPROC glad_glGetIntegeri_v;
            export inline void glGetIntegeri_v(GLenum target, GLuint index, GLint* data) { glad_glGetIntegeri_v(target, index, data); }
            export typedef void (APIENTRYP PFNGLENABLEIPROC)(GLenum target, GLuint index);
            export GLAPI PFNGLENABLEIPROC glad_glEnablei;
            export inline void glEnablei(GLenum target, GLuint index) { glad_glEnablei(target, index); }
            export typedef void (APIENTRYP PFNGLDISABLEIPROC)(GLenum target, GLuint index);
            export GLAPI PFNGLDISABLEIPROC glad_glDisablei;
            export inline void glDisablei(GLenum target, GLuint index) { glad_glDisablei(target, index); }
            export typedef GLboolean(APIENTRYP PFNGLISENABLEDIPROC)(GLenum target, GLuint index);
            export GLAPI PFNGLISENABLEDIPROC glad_glIsEnabledi;
            export inline GLboolean glIsEnabledi(GLenum target, GLuint index) { return glad_glIsEnabledi(target, index); }
            export typedef void (APIENTRYP PFNGLBEGINTRANSFORMFEEDBACKPROC)(GLenum primitiveMode);
            export GLAPI PFNGLBEGINTRANSFORMFEEDBACKPROC glad_glBeginTransformFeedback;
            export inline void glBeginTransformFeedback(GLenum primitiveMode) { glad_glBeginTransformFeedback(primitiveMode); }
            export typedef void (APIENTRYP PFNGLENDTRANSFORMFEEDBACKPROC)(void);
            export GLAPI PFNGLENDTRANSFORMFEEDBACKPROC glad_glEndTransformFeedback;
            export inline void glEndTransformFeedback() { glad_glEndTransformFeedback(); }
            export typedef void (APIENTRYP PFNGLBINDBUFFERRANGEPROC)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
            export GLAPI PFNGLBINDBUFFERRANGEPROC glad_glBindBufferRange;
            export inline void glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) { glad_glBindBufferRange(target, index, buffer, offset, size); }
            export typedef void (APIENTRYP PFNGLBINDBUFFERBASEPROC)(GLenum target, GLuint index, GLuint buffer);
            export GLAPI PFNGLBINDBUFFERBASEPROC glad_glBindBufferBase;
            export inline void glBindBufferBase(GLenum target, GLuint index, GLuint buffer) { glad_glBindBufferBase(target, index, buffer); }
            export typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKVARYINGSPROC)(GLuint program, GLsizei count, const GLchar* const* varyings, GLenum bufferMode);
            export GLAPI PFNGLTRANSFORMFEEDBACKVARYINGSPROC glad_glTransformFeedbackVaryings;
            export inline void glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar* const* varyings, GLenum bufferMode) { glad_glTransformFeedbackVaryings(program, count, varyings, bufferMode); }
            export typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name);
            export GLAPI PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glad_glGetTransformFeedbackVarying;
            export inline void glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name) { glad_glGetTransformFeedbackVarying(program, index, bufSize, length, size, type, name); }
            export typedef void (APIENTRYP PFNGLCLAMPCOLORPROC)(GLenum target, GLenum clamp);
            export GLAPI PFNGLCLAMPCOLORPROC glad_glClampColor;
            export inline void glClampColor(GLenum target, GLenum clamp) { glad_glClampColor(target, clamp); }
            export typedef void (APIENTRYP PFNGLBEGINCONDITIONALRENDERPROC)(GLuint id, GLenum mode);
            export GLAPI PFNGLBEGINCONDITIONALRENDERPROC glad_glBeginConditionalRender;
            export inline void glBeginConditionalRender(GLuint id, GLenum mode) { glad_glBeginConditionalRender(id, mode); }
            export typedef void (APIENTRYP PFNGLENDCONDITIONALRENDERPROC)(void);
            export GLAPI PFNGLENDCONDITIONALRENDERPROC glad_glEndConditionalRender;
            export inline void glEndConditionalRender() { glad_glEndConditionalRender(); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIBIPOINTERPROC)(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer);
            export GLAPI PFNGLVERTEXATTRIBIPOINTERPROC glad_glVertexAttribIPointer;
            export inline void glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer) { glad_glVertexAttribIPointer(index, size, type, stride, pointer); }
            export typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIIVPROC)(GLuint index, GLenum pname, GLint* params);
            export GLAPI PFNGLGETVERTEXATTRIBIIVPROC glad_glGetVertexAttribIiv;
            export inline void glGetVertexAttribIiv(GLuint index, GLenum pname, GLint* params) { glad_glGetVertexAttribIiv(index, pname, params); }
            export typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIUIVPROC)(GLuint index, GLenum pname, GLuint* params);
            export GLAPI PFNGLGETVERTEXATTRIBIUIVPROC glad_glGetVertexAttribIuiv;
            export inline void glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint* params) { glad_glGetVertexAttribIuiv(index, pname, params); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IPROC)(GLuint index, GLint x);
            export GLAPI PFNGLVERTEXATTRIBI1IPROC glad_glVertexAttribI1i;
            export inline void glVertexAttribI1i(GLuint index, GLint x) { glad_glVertexAttribI1i(index, x); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IPROC)(GLuint index, GLint x, GLint y);
            export GLAPI PFNGLVERTEXATTRIBI2IPROC glad_glVertexAttribI2i;
            export inline void glVertexAttribI2i(GLuint index, GLint x, GLint y) { glad_glVertexAttribI2i(index, x, y); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IPROC)(GLuint index, GLint x, GLint y, GLint z);
            export GLAPI PFNGLVERTEXATTRIBI3IPROC glad_glVertexAttribI3i;
            export inline void glVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z) { glad_glVertexAttribI3i(index, x, y, z); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IPROC)(GLuint index, GLint x, GLint y, GLint z, GLint w);
            export GLAPI PFNGLVERTEXATTRIBI4IPROC glad_glVertexAttribI4i;
            export inline void glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w) { glad_glVertexAttribI4i(index, x, y, z, w); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIPROC)(GLuint index, GLuint x);
            export GLAPI PFNGLVERTEXATTRIBI1UIPROC glad_glVertexAttribI1ui;
            export inline void glVertexAttribI1ui(GLuint index, GLuint x) { glad_glVertexAttribI1ui(index, x); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIPROC)(GLuint index, GLuint x, GLuint y);
            export GLAPI PFNGLVERTEXATTRIBI2UIPROC glad_glVertexAttribI2ui;
            export inline void glVertexAttribI2ui(GLuint index, GLuint x, GLuint y) { glad_glVertexAttribI2ui(index, x, y); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIPROC)(GLuint index, GLuint x, GLuint y, GLuint z);
            export GLAPI PFNGLVERTEXATTRIBI3UIPROC glad_glVertexAttribI3ui;
            export inline void glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z) { glad_glVertexAttribI3ui(index, x, y, z); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIPROC)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
            export GLAPI PFNGLVERTEXATTRIBI4UIPROC glad_glVertexAttribI4ui;
            export inline void glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) { glad_glVertexAttribI4ui(index, x, y, z, w); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IVPROC)(GLuint index, const GLint* v);
            export GLAPI PFNGLVERTEXATTRIBI1IVPROC glad_glVertexAttribI1iv;
            export inline void glVertexAttribI1iv(GLuint index, const GLint* v) { glad_glVertexAttribI1iv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IVPROC)(GLuint index, const GLint* v);
            export GLAPI PFNGLVERTEXATTRIBI2IVPROC glad_glVertexAttribI2iv;
            export inline void glVertexAttribI2iv(GLuint index, const GLint* v) { glad_glVertexAttribI2iv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IVPROC)(GLuint index, const GLint* v);
            export GLAPI PFNGLVERTEXATTRIBI3IVPROC glad_glVertexAttribI3iv;
            export inline void glVertexAttribI3iv(GLuint index, const GLint* v) { glad_glVertexAttribI3iv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IVPROC)(GLuint index, const GLint* v);
            export GLAPI PFNGLVERTEXATTRIBI4IVPROC glad_glVertexAttribI4iv;
            export inline void glVertexAttribI4iv(GLuint index, const GLint* v) { glad_glVertexAttribI4iv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIVPROC)(GLuint index, const GLuint* v);
            export GLAPI PFNGLVERTEXATTRIBI1UIVPROC glad_glVertexAttribI1uiv;
            export inline void glVertexAttribI1uiv(GLuint index, const GLuint* v) { glad_glVertexAttribI1uiv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIVPROC)(GLuint index, const GLuint* v);
            export GLAPI PFNGLVERTEXATTRIBI2UIVPROC glad_glVertexAttribI2uiv;
            export inline void glVertexAttribI2uiv(GLuint index, const GLuint* v) { glad_glVertexAttribI2uiv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIVPROC)(GLuint index, const GLuint* v);
            export GLAPI PFNGLVERTEXATTRIBI3UIVPROC glad_glVertexAttribI3uiv;
            export inline void glVertexAttribI3uiv(GLuint index, const GLuint* v) { glad_glVertexAttribI3uiv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIVPROC)(GLuint index, const GLuint* v);
            export GLAPI PFNGLVERTEXATTRIBI4UIVPROC glad_glVertexAttribI4uiv;
            export inline void glVertexAttribI4uiv(GLuint index, const GLuint* v) { glad_glVertexAttribI4uiv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIBI4BVPROC)(GLuint index, const GLbyte* v);
            export GLAPI PFNGLVERTEXATTRIBI4BVPROC glad_glVertexAttribI4bv;
            export inline void glVertexAttribI4bv(GLuint index, const GLbyte* v) { glad_glVertexAttribI4bv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIBI4SVPROC)(GLuint index, const GLshort* v);
            export GLAPI PFNGLVERTEXATTRIBI4SVPROC glad_glVertexAttribI4sv;
            export inline void glVertexAttribI4sv(GLuint index, const GLshort* v) { glad_glVertexAttribI4sv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UBVPROC)(GLuint index, const GLubyte* v);
            export GLAPI PFNGLVERTEXATTRIBI4UBVPROC glad_glVertexAttribI4ubv;
            export inline void glVertexAttribI4ubv(GLuint index, const GLubyte* v) { glad_glVertexAttribI4ubv(index, v); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIBI4USVPROC)(GLuint index, const GLushort* v);
            export GLAPI PFNGLVERTEXATTRIBI4USVPROC glad_glVertexAttribI4usv;
            export inline void glVertexAttribI4usv(GLuint index, const GLushort* v) { glad_glVertexAttribI4usv(index, v); }
            export typedef void (APIENTRYP PFNGLGETUNIFORMUIVPROC)(GLuint program, GLint location, GLuint* params);
            export GLAPI PFNGLGETUNIFORMUIVPROC glad_glGetUniformuiv;
            export inline void glGetUniformuiv(GLuint program, GLint location, GLuint* params) { glad_glGetUniformuiv(program, location, params); }
            export typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONPROC)(GLuint program, GLuint color, const GLchar* name);
            export GLAPI PFNGLBINDFRAGDATALOCATIONPROC glad_glBindFragDataLocation;
            export inline void glBindFragDataLocation(GLuint program, GLuint color, const GLchar* name) { glad_glBindFragDataLocation(program, color, name); }
            export typedef GLint(APIENTRYP PFNGLGETFRAGDATALOCATIONPROC)(GLuint program, const GLchar* name);
            export GLAPI PFNGLGETFRAGDATALOCATIONPROC glad_glGetFragDataLocation;
            export inline GLint glGetFragDataLocation(GLuint program, const GLchar* name) { return glad_glGetFragDataLocation(program, name); }
            export typedef void (APIENTRYP PFNGLUNIFORM1UIPROC)(GLint location, GLuint v0);
            export GLAPI PFNGLUNIFORM1UIPROC glad_glUniform1ui;
            export inline void glUniform1ui(GLint location, GLuint v0) { glad_glUniform1ui(location, v0); }
            export typedef void (APIENTRYP PFNGLUNIFORM2UIPROC)(GLint location, GLuint v0, GLuint v1);
            export GLAPI PFNGLUNIFORM2UIPROC glad_glUniform2ui;
            export inline void glUniform2ui(GLint location, GLuint v0, GLuint v1) { glad_glUniform2ui(location, v0, v1); }
            export typedef void (APIENTRYP PFNGLUNIFORM3UIPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2);
            export GLAPI PFNGLUNIFORM3UIPROC glad_glUniform3ui;
            export inline void glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2) { glad_glUniform3ui(location, v0, v1, v2); }
            export typedef void (APIENTRYP PFNGLUNIFORM4UIPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
            export GLAPI PFNGLUNIFORM4UIPROC glad_glUniform4ui;
            export inline void glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) { glad_glUniform4ui(location, v0, v1, v2, v3); }
            export typedef void (APIENTRYP PFNGLUNIFORM1UIVPROC)(GLint location, GLsizei count, const GLuint* value);
            export GLAPI PFNGLUNIFORM1UIVPROC glad_glUniform1uiv;
            export inline void glUniform1uiv(GLint location, GLsizei count, const GLuint* value) { glad_glUniform1uiv(location, count, value); }
            export typedef void (APIENTRYP PFNGLUNIFORM2UIVPROC)(GLint location, GLsizei count, const GLuint* value);
            export GLAPI PFNGLUNIFORM2UIVPROC glad_glUniform2uiv;
            export inline void glUniform2uiv(GLint location, GLsizei count, const GLuint* value) { glad_glUniform2uiv(location, count, value); }
            export typedef void (APIENTRYP PFNGLUNIFORM3UIVPROC)(GLint location, GLsizei count, const GLuint* value);
            export GLAPI PFNGLUNIFORM3UIVPROC glad_glUniform3uiv;
            export inline void glUniform3uiv(GLint location, GLsizei count, const GLuint* value) { glad_glUniform3uiv(location, count, value); }
            export typedef void (APIENTRYP PFNGLUNIFORM4UIVPROC)(GLint location, GLsizei count, const GLuint* value);
            export GLAPI PFNGLUNIFORM4UIVPROC glad_glUniform4uiv;
            export inline void glUniform4uiv(GLint location, GLsizei count, const GLuint* value) { glad_glUniform4uiv(location, count, value); }
            export typedef void (APIENTRYP PFNGLTEXPARAMETERIIVPROC)(GLenum target, GLenum pname, const GLint* params);
            export GLAPI PFNGLTEXPARAMETERIIVPROC glad_glTexParameterIiv;
            export inline void glTexParameterIiv(GLenum target, GLenum pname, const GLint* params) { glad_glTexParameterIiv(target, pname, params); }
            export typedef void (APIENTRYP PFNGLTEXPARAMETERIUIVPROC)(GLenum target, GLenum pname, const GLuint* params);
            export GLAPI PFNGLTEXPARAMETERIUIVPROC glad_glTexParameterIuiv;
            export inline void glTexParameterIuiv(GLenum target, GLenum pname, const GLuint* params) { glad_glTexParameterIuiv(target, pname, params); }
            export typedef void (APIENTRYP PFNGLGETTEXPARAMETERIIVPROC)(GLenum target, GLenum pname, GLint* params);
            export GLAPI PFNGLGETTEXPARAMETERIIVPROC glad_glGetTexParameterIiv;
            export inline void glGetTexParameterIiv(GLenum target, GLenum pname, GLint* params) { glad_glGetTexParameterIiv(target, pname, params); }
            export typedef void (APIENTRYP PFNGLGETTEXPARAMETERIUIVPROC)(GLenum target, GLenum pname, GLuint* params);
            export GLAPI PFNGLGETTEXPARAMETERIUIVPROC glad_glGetTexParameterIuiv;
            export inline void glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint* params) { glad_glGetTexParameterIuiv(target, pname, params); }
            export typedef void (APIENTRYP PFNGLCLEARBUFFERIVPROC)(GLenum buffer, GLint drawbuffer, const GLint* value);
            export GLAPI PFNGLCLEARBUFFERIVPROC glad_glClearBufferiv;
            export inline void glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint* value) { glad_glClearBufferiv(buffer, drawbuffer, value); }
            export typedef void (APIENTRYP PFNGLCLEARBUFFERUIVPROC)(GLenum buffer, GLint drawbuffer, const GLuint* value);
            export GLAPI PFNGLCLEARBUFFERUIVPROC glad_glClearBufferuiv;
            export inline void glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint* value) { glad_glClearBufferuiv(buffer, drawbuffer, value); }
            export typedef void (APIENTRYP PFNGLCLEARBUFFERFVPROC)(GLenum buffer, GLint drawbuffer, const GLfloat* value);
            export GLAPI PFNGLCLEARBUFFERFVPROC glad_glClearBufferfv;
            export inline void glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat* value) { glad_glClearBufferfv(buffer, drawbuffer, value); }
            export typedef void (APIENTRYP PFNGLCLEARBUFFERFIPROC)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
            export GLAPI PFNGLCLEARBUFFERFIPROC glad_glClearBufferfi;
            export inline void glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) { glad_glClearBufferfi(buffer, drawbuffer, depth, stencil); }
            export typedef const GLubyte* (APIENTRYP PFNGLGETSTRINGIPROC)(GLenum name, GLuint index);
            export GLAPI PFNGLGETSTRINGIPROC glad_glGetStringi;
            export inline const GLubyte* glGetStringi(GLenum name, GLuint index) { return glad_glGetStringi(name, index); }
            export typedef GLboolean(APIENTRYP PFNGLISRENDERBUFFERPROC)(GLuint renderbuffer);
            export GLAPI PFNGLISRENDERBUFFERPROC glad_glIsRenderbuffer;
            export inline GLboolean glIsRenderbuffer(GLuint renderbuffer) { return glad_glIsRenderbuffer(renderbuffer); }
            export typedef void (APIENTRYP PFNGLBINDRENDERBUFFERPROC)(GLenum target, GLuint renderbuffer);
            export GLAPI PFNGLBINDRENDERBUFFERPROC glad_glBindRenderbuffer;
            export inline void glBindRenderbuffer(GLenum target, GLuint renderbuffer) { glad_glBindRenderbuffer(target, renderbuffer); }
            export typedef void (APIENTRYP PFNGLDELETERENDERBUFFERSPROC)(GLsizei n, const GLuint* renderbuffers);
            export GLAPI PFNGLDELETERENDERBUFFERSPROC glad_glDeleteRenderbuffers;
            export inline void glDeleteRenderbuffers(GLsizei n, const GLuint* renderbuffers) { glad_glDeleteRenderbuffers(n, renderbuffers); }
            export typedef void (APIENTRYP PFNGLGENRENDERBUFFERSPROC)(GLsizei n, GLuint* renderbuffers);
            export GLAPI PFNGLGENRENDERBUFFERSPROC glad_glGenRenderbuffers;
            export inline void glGenRenderbuffers(GLsizei n, GLuint* renderbuffers) { glad_glGenRenderbuffers(n, renderbuffers); }
            export typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
            export GLAPI PFNGLRENDERBUFFERSTORAGEPROC glad_glRenderbufferStorage;
            export inline void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) { glad_glRenderbufferStorage(target, internalformat, width, height); }
            export typedef void (APIENTRYP PFNGLGETRENDERBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint* params);
            export GLAPI PFNGLGETRENDERBUFFERPARAMETERIVPROC glad_glGetRenderbufferParameteriv;
            export inline void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint* params) { glad_glGetRenderbufferParameteriv(target, pname, params); }
            export typedef GLboolean(APIENTRYP PFNGLISFRAMEBUFFERPROC)(GLuint framebuffer);
            export GLAPI PFNGLISFRAMEBUFFERPROC glad_glIsFramebuffer;
            export inline GLboolean glIsFramebuffer(GLuint framebuffer) { return glad_glIsFramebuffer(framebuffer); }
            export typedef void (APIENTRYP PFNGLBINDFRAMEBUFFERPROC)(GLenum target, GLuint framebuffer);
            export GLAPI PFNGLBINDFRAMEBUFFERPROC glad_glBindFramebuffer;
            export inline void glBindFramebuffer(GLenum target, GLuint framebuffer) { glad_glBindFramebuffer(target, framebuffer); }
            export typedef void (APIENTRYP PFNGLDELETEFRAMEBUFFERSPROC)(GLsizei n, const GLuint* framebuffers);
            export GLAPI PFNGLDELETEFRAMEBUFFERSPROC glad_glDeleteFramebuffers;
            export inline void glDeleteFramebuffers(GLsizei n, const GLuint* framebuffers) { glad_glDeleteFramebuffers(n, framebuffers); }
            export typedef void (APIENTRYP PFNGLGENFRAMEBUFFERSPROC)(GLsizei n, GLuint* framebuffers);
            export GLAPI PFNGLGENFRAMEBUFFERSPROC glad_glGenFramebuffers;
            export inline void glGenFramebuffers(GLsizei n, GLuint* framebuffers) { glad_glGenFramebuffers(n, framebuffers); }
            export typedef GLenum(APIENTRYP PFNGLCHECKFRAMEBUFFERSTATUSPROC)(GLenum target);
            export GLAPI PFNGLCHECKFRAMEBUFFERSTATUSPROC glad_glCheckFramebufferStatus;
            export inline GLenum glCheckFramebufferStatus(GLenum target) { return glad_glCheckFramebufferStatus(target); }
            export typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE1DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
            export GLAPI PFNGLFRAMEBUFFERTEXTURE1DPROC glad_glFramebufferTexture1D;
            export inline void glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) { glad_glFramebufferTexture1D(target, attachment, textarget, texture, level); }
            export typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE2DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
            export GLAPI PFNGLFRAMEBUFFERTEXTURE2DPROC glad_glFramebufferTexture2D;
            export inline void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) { glad_glFramebufferTexture2D(target, attachment, textarget, texture, level); }
            export typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE3DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
            export GLAPI PFNGLFRAMEBUFFERTEXTURE3DPROC glad_glFramebufferTexture3D;
            export inline void glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) { glad_glFramebufferTexture3D(target, attachment, textarget, texture, level, zoffset); }
            export typedef void (APIENTRYP PFNGLFRAMEBUFFERRENDERBUFFERPROC)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
            export GLAPI PFNGLFRAMEBUFFERRENDERBUFFERPROC glad_glFramebufferRenderbuffer;
            export inline void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) { glad_glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer); }
            export typedef void (APIENTRYP PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLenum target, GLenum attachment, GLenum pname, GLint* params);
            export GLAPI PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glad_glGetFramebufferAttachmentParameteriv;
            export inline void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint* params) { glad_glGetFramebufferAttachmentParameteriv(target, attachment, pname, params); }
            export typedef void (APIENTRYP PFNGLGENERATEMIPMAPPROC)(GLenum target);
            export GLAPI PFNGLGENERATEMIPMAPPROC glad_glGenerateMipmap;
            export inline void glGenerateMipmap(GLenum target) { glad_glGenerateMipmap(target); }
            export typedef void (APIENTRYP PFNGLBLITFRAMEBUFFERPROC)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
            export GLAPI PFNGLBLITFRAMEBUFFERPROC glad_glBlitFramebuffer;
            export inline void glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) { glad_glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter); }
            export typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
            export GLAPI PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glad_glRenderbufferStorageMultisample;
            export inline void glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) { glad_glRenderbufferStorageMultisample(target, samples, internalformat, width, height); }
            export typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURELAYERPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
            export GLAPI PFNGLFRAMEBUFFERTEXTURELAYERPROC glad_glFramebufferTextureLayer;
            export inline void glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) { glad_glFramebufferTextureLayer(target, attachment, texture, level, layer); }
            export typedef void* (APIENTRYP PFNGLMAPBUFFERRANGEPROC)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
            export GLAPI PFNGLMAPBUFFERRANGEPROC glad_glMapBufferRange;
            export inline void* glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) { return glad_glMapBufferRange(target, offset, length, access); }
            export typedef void (APIENTRYP PFNGLFLUSHMAPPEDBUFFERRANGEPROC)(GLenum target, GLintptr offset, GLsizeiptr length);
            export GLAPI PFNGLFLUSHMAPPEDBUFFERRANGEPROC glad_glFlushMappedBufferRange;
            export inline void glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length) { glad_glFlushMappedBufferRange(target, offset, length); }
            export typedef void (APIENTRYP PFNGLBINDVERTEXARRAYPROC)(GLuint array);
            export GLAPI PFNGLBINDVERTEXARRAYPROC glad_glBindVertexArray;
            export inline void glBindVertexArray(GLuint array) { glad_glBindVertexArray(array); }
            export typedef void (APIENTRYP PFNGLDELETEVERTEXARRAYSPROC)(GLsizei n, const GLuint* arrays);
            export GLAPI PFNGLDELETEVERTEXARRAYSPROC glad_glDeleteVertexArrays;
            export inline void glDeleteVertexArrays(GLsizei n, const GLuint* arrays) { glad_glDeleteVertexArrays(n, arrays); }
            export typedef void (APIENTRYP PFNGLGENVERTEXARRAYSPROC)(GLsizei n, GLuint* arrays);
            export GLAPI PFNGLGENVERTEXARRAYSPROC glad_glGenVertexArrays;
            export inline void glGenVertexArrays(GLsizei n, GLuint* arrays) { glad_glGenVertexArrays(n, arrays); }
            export typedef GLboolean(APIENTRYP PFNGLISVERTEXARRAYPROC)(GLuint array);
            export GLAPI PFNGLISVERTEXARRAYPROC glad_glIsVertexArray;
            export inline GLboolean glIsVertexArray(GLuint array) { return glad_glIsVertexArray(array); }
#endif
#ifndef GL_VERSION_3_1
            export GLAPI int GLAD_GL_VERSION_3_1;
            export typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDPROC)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
            export GLAPI PFNGLDRAWARRAYSINSTANCEDPROC glad_glDrawArraysInstanced;
            export inline void glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount) { glad_glDrawArraysInstanced(mode, first, count, instancecount); }
            export typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDPROC)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount);
            export GLAPI PFNGLDRAWELEMENTSINSTANCEDPROC glad_glDrawElementsInstanced;
            export inline void glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount) { glad_glDrawElementsInstanced(mode, count, type, indices, instancecount); }
            export typedef void (APIENTRYP PFNGLTEXBUFFERPROC)(GLenum target, GLenum internalformat, GLuint buffer);
            export GLAPI PFNGLTEXBUFFERPROC glad_glTexBuffer;
            export inline void glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer) { glad_glTexBuffer(target, internalformat, buffer); }
            export typedef void (APIENTRYP PFNGLPRIMITIVERESTARTINDEXPROC)(GLuint index);
            export GLAPI PFNGLPRIMITIVERESTARTINDEXPROC glad_glPrimitiveRestartIndex;
            export inline void glPrimitiveRestartIndex(GLuint index) { glad_glPrimitiveRestartIndex(index); }
            export typedef void (APIENTRYP PFNGLCOPYBUFFERSUBDATAPROC)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
            export GLAPI PFNGLCOPYBUFFERSUBDATAPROC glad_glCopyBufferSubData;
            export inline void glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) { glad_glCopyBufferSubData(readTarget, writeTarget, readOffset, writeOffset, size); }
            export typedef void (APIENTRYP PFNGLGETUNIFORMINDICESPROC)(GLuint program, GLsizei uniformCount, const GLchar* const* uniformNames, GLuint* uniformIndices);
            export GLAPI PFNGLGETUNIFORMINDICESPROC glad_glGetUniformIndices;
            export inline void glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar* const* uniformNames, GLuint* uniformIndices) { glad_glGetUniformIndices(program, uniformCount, uniformNames, uniformIndices); }
            export typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMSIVPROC)(GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params);
            export GLAPI PFNGLGETACTIVEUNIFORMSIVPROC glad_glGetActiveUniformsiv;
            export inline void glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params) { glad_glGetActiveUniformsiv(program, uniformCount, uniformIndices, pname, params); }
            export typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMNAMEPROC)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName);
            export GLAPI PFNGLGETACTIVEUNIFORMNAMEPROC glad_glGetActiveUniformName;
            export inline void glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName) { glad_glGetActiveUniformName(program, uniformIndex, bufSize, length, uniformName); }
            export typedef GLuint(APIENTRYP PFNGLGETUNIFORMBLOCKINDEXPROC)(GLuint program, const GLchar* uniformBlockName);
            export GLAPI PFNGLGETUNIFORMBLOCKINDEXPROC glad_glGetUniformBlockIndex;
            export inline GLuint glGetUniformBlockIndex(GLuint program, const GLchar* uniformBlockName) { return glad_glGetUniformBlockIndex(program, uniformBlockName); }
            export typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKIVPROC)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params);
            export GLAPI PFNGLGETACTIVEUNIFORMBLOCKIVPROC glad_glGetActiveUniformBlockiv;
            export inline void glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params) { glad_glGetActiveUniformBlockiv(program, uniformBlockIndex, pname, params); }
            export typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName);
            export GLAPI PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glad_glGetActiveUniformBlockName;
            export inline void glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName) { glad_glGetActiveUniformBlockName(program, uniformBlockIndex, bufSize, length, uniformBlockName); }
            export typedef void (APIENTRYP PFNGLUNIFORMBLOCKBINDINGPROC)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
            export GLAPI PFNGLUNIFORMBLOCKBINDINGPROC glad_glUniformBlockBinding;
            export inline void glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) { glad_glUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding); }
#endif
#ifndef GL_VERSION_3_2
            export GLAPI int GLAD_GL_VERSION_3_2;
            export typedef void (APIENTRYP PFNGLDRAWELEMENTSBASEVERTEXPROC)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLint basevertex);
            export GLAPI PFNGLDRAWELEMENTSBASEVERTEXPROC glad_glDrawElementsBaseVertex;
            export inline void glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void* indices, GLint basevertex) { glad_glDrawElementsBaseVertex(mode, count, type, indices, basevertex); }
            export typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices, GLint basevertex);
            export GLAPI PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glad_glDrawRangeElementsBaseVertex;
            export inline void glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices, GLint basevertex) { glad_glDrawRangeElementsBaseVertex(mode, start, end, count, type, indices, basevertex); }
            export typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex);
            export GLAPI PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glad_glDrawElementsInstancedBaseVertex;
            export inline void glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex) { glad_glDrawElementsInstancedBaseVertex(mode, count, type, indices, instancecount, basevertex); }
            export typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount, const GLint* basevertex);
            export GLAPI PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glad_glMultiDrawElementsBaseVertex;
            export inline void glMultiDrawElementsBaseVertex(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount, const GLint* basevertex) { glad_glMultiDrawElementsBaseVertex(mode, count, type, indices, drawcount, basevertex); }
            export typedef void (APIENTRYP PFNGLPROVOKINGVERTEXPROC)(GLenum mode);
            export GLAPI PFNGLPROVOKINGVERTEXPROC glad_glProvokingVertex;
            export inline void glProvokingVertex(GLenum mode) { glad_glProvokingVertex(mode); }
            export typedef GLsync(APIENTRYP PFNGLFENCESYNCPROC)(GLenum condition, GLbitfield flags);
            export GLAPI PFNGLFENCESYNCPROC glad_glFenceSync;
            export inline GLsync glFenceSync(GLenum condition, GLbitfield flags) { return glad_glFenceSync(condition, flags); }
            export typedef GLboolean(APIENTRYP PFNGLISSYNCPROC)(GLsync sync);
            export GLAPI PFNGLISSYNCPROC glad_glIsSync;
            export inline GLboolean glIsSync(GLsync sync) { return glad_glIsSync(sync); }
            export typedef void (APIENTRYP PFNGLDELETESYNCPROC)(GLsync sync);
            export GLAPI PFNGLDELETESYNCPROC glad_glDeleteSync;
            export inline void glDeleteSync(GLsync sync) { glad_glDeleteSync(sync); }
            export typedef GLenum(APIENTRYP PFNGLCLIENTWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
            export GLAPI PFNGLCLIENTWAITSYNCPROC glad_glClientWaitSync;
            export inline GLenum glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) { return glad_glClientWaitSync(sync, flags, timeout); }
            export typedef void (APIENTRYP PFNGLWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
            export GLAPI PFNGLWAITSYNCPROC glad_glWaitSync;
            export inline void glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) { glad_glWaitSync(sync, flags, timeout); }
            export typedef void (APIENTRYP PFNGLGETINTEGER64VPROC)(GLenum pname, GLint64* data);
            export GLAPI PFNGLGETINTEGER64VPROC glad_glGetInteger64v;
            export inline void glGetInteger64v(GLenum pname, GLint64* data) { glad_glGetInteger64v(pname, data); }
            export typedef void (APIENTRYP PFNGLGETSYNCIVPROC)(GLsync sync, GLenum pname, GLsizei count, GLsizei* length, GLint* values);
            export GLAPI PFNGLGETSYNCIVPROC glad_glGetSynciv;
            export inline void glGetSynciv(GLsync sync, GLenum pname, GLsizei count, GLsizei* length, GLint* values) { glad_glGetSynciv(sync, pname, count, length, values); }
            export typedef void (APIENTRYP PFNGLGETINTEGER64I_VPROC)(GLenum target, GLuint index, GLint64* data);
            export GLAPI PFNGLGETINTEGER64I_VPROC glad_glGetInteger64i_v;
            export inline void glGetInteger64i_v(GLenum target, GLuint index, GLint64* data) { glad_glGetInteger64i_v(target, index, data); }
            export typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERI64VPROC)(GLenum target, GLenum pname, GLint64* params);
            export GLAPI PFNGLGETBUFFERPARAMETERI64VPROC glad_glGetBufferParameteri64v;
            export inline void glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64* params) { glad_glGetBufferParameteri64v(target, pname, params); }
            export typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level);
            export GLAPI PFNGLFRAMEBUFFERTEXTUREPROC glad_glFramebufferTexture;
            export inline void glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level) { glad_glFramebufferTexture(target, attachment, texture, level); }
            export typedef void (APIENTRYP PFNGLTEXIMAGE2DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
            export GLAPI PFNGLTEXIMAGE2DMULTISAMPLEPROC glad_glTexImage2DMultisample;
            export inline void glTexImage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) { glad_glTexImage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations); }
            export typedef void (APIENTRYP PFNGLTEXIMAGE3DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
            export GLAPI PFNGLTEXIMAGE3DMULTISAMPLEPROC glad_glTexImage3DMultisample;
            export inline void glTexImage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) { glad_glTexImage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations); }
            export typedef void (APIENTRYP PFNGLGETMULTISAMPLEFVPROC)(GLenum pname, GLuint index, GLfloat* val);
            export GLAPI PFNGLGETMULTISAMPLEFVPROC glad_glGetMultisamplefv;
            export inline void glGetMultisamplefv(GLenum pname, GLuint index, GLfloat* val) { glad_glGetMultisamplefv(pname, index, val); }
            export typedef void (APIENTRYP PFNGLSAMPLEMASKIPROC)(GLuint maskNumber, GLbitfield mask);
            export GLAPI PFNGLSAMPLEMASKIPROC glad_glSampleMaski;
            export inline void glSampleMaski(GLuint maskNumber, GLbitfield mask) { glad_glSampleMaski(maskNumber, mask); }
#endif
#ifndef GL_VERSION_3_3
            export GLAPI int GLAD_GL_VERSION_3_3;
            export typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)(GLuint program, GLuint colorNumber, GLuint index, const GLchar* name);
            export GLAPI PFNGLBINDFRAGDATALOCATIONINDEXEDPROC glad_glBindFragDataLocationIndexed;
            export inline void glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar* name) { glad_glBindFragDataLocationIndexed(program, colorNumber, index, name); }
            export typedef GLint(APIENTRYP PFNGLGETFRAGDATAINDEXPROC)(GLuint program, const GLchar* name);
            export GLAPI PFNGLGETFRAGDATAINDEXPROC glad_glGetFragDataIndex;
            export inline GLint glGetFragDataIndex(GLuint program, const GLchar* name) { return glad_glGetFragDataIndex(program, name); }
            export typedef void (APIENTRYP PFNGLGENSAMPLERSPROC)(GLsizei count, GLuint* samplers);
            export GLAPI PFNGLGENSAMPLERSPROC glad_glGenSamplers;
            export inline void glGenSamplers(GLsizei count, GLuint* samplers) { glad_glGenSamplers(count, samplers); }
            export typedef void (APIENTRYP PFNGLDELETESAMPLERSPROC)(GLsizei count, const GLuint* samplers);
            export GLAPI PFNGLDELETESAMPLERSPROC glad_glDeleteSamplers;
            export inline void glDeleteSamplers(GLsizei count, const GLuint* samplers) { glad_glDeleteSamplers(count, samplers); }
            export typedef GLboolean(APIENTRYP PFNGLISSAMPLERPROC)(GLuint sampler);
            export GLAPI PFNGLISSAMPLERPROC glad_glIsSampler;
            export inline GLboolean glIsSampler(GLuint sampler) { return glad_glIsSampler(sampler); }
            export typedef void (APIENTRYP PFNGLBINDSAMPLERPROC)(GLuint unit, GLuint sampler);
            export GLAPI PFNGLBINDSAMPLERPROC glad_glBindSampler;
            export inline void glBindSampler(GLuint unit, GLuint sampler) { glad_glBindSampler(unit, sampler); }
            export typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIPROC)(GLuint sampler, GLenum pname, GLint param);
            export GLAPI PFNGLSAMPLERPARAMETERIPROC glad_glSamplerParameteri;
            export inline void glSamplerParameteri(GLuint sampler, GLenum pname, GLint param) { glad_glSamplerParameteri(sampler, pname, param); }
            export typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIVPROC)(GLuint sampler, GLenum pname, const GLint* param);
            export GLAPI PFNGLSAMPLERPARAMETERIVPROC glad_glSamplerParameteriv;
            export inline void glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint* param) { glad_glSamplerParameteriv(sampler, pname, param); }
            export typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFPROC)(GLuint sampler, GLenum pname, GLfloat param);
            export GLAPI PFNGLSAMPLERPARAMETERFPROC glad_glSamplerParameterf;
            export inline void glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param) { glad_glSamplerParameterf(sampler, pname, param); }
            export typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFVPROC)(GLuint sampler, GLenum pname, const GLfloat* param);
            export GLAPI PFNGLSAMPLERPARAMETERFVPROC glad_glSamplerParameterfv;
            export inline void glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat* param) { glad_glSamplerParameterfv(sampler, pname, param); }
            export typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIIVPROC)(GLuint sampler, GLenum pname, const GLint* param);
            export GLAPI PFNGLSAMPLERPARAMETERIIVPROC glad_glSamplerParameterIiv;
            export inline void glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint* param) { glad_glSamplerParameterIiv(sampler, pname, param); }
            export typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIUIVPROC)(GLuint sampler, GLenum pname, const GLuint* param);
            export GLAPI PFNGLSAMPLERPARAMETERIUIVPROC glad_glSamplerParameterIuiv;
            export inline void glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint* param) { glad_glSamplerParameterIuiv(sampler, pname, param); }
            export typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIVPROC)(GLuint sampler, GLenum pname, GLint* params);
            export GLAPI PFNGLGETSAMPLERPARAMETERIVPROC glad_glGetSamplerParameteriv;
            export inline void glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint* params) { glad_glGetSamplerParameteriv(sampler, pname, params); }
            export typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIIVPROC)(GLuint sampler, GLenum pname, GLint* params);
            export GLAPI PFNGLGETSAMPLERPARAMETERIIVPROC glad_glGetSamplerParameterIiv;
            export inline void glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint* params) { glad_glGetSamplerParameterIiv(sampler, pname, params); }
            export typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERFVPROC)(GLuint sampler, GLenum pname, GLfloat* params);
            export GLAPI PFNGLGETSAMPLERPARAMETERFVPROC glad_glGetSamplerParameterfv;
            export inline void glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat* params) { glad_glGetSamplerParameterfv(sampler, pname, params); }
            export typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIUIVPROC)(GLuint sampler, GLenum pname, GLuint* params);
            export GLAPI PFNGLGETSAMPLERPARAMETERIUIVPROC glad_glGetSamplerParameterIuiv;
            export inline void glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint* params) { glad_glGetSamplerParameterIuiv(sampler, pname, params); }
            export typedef void (APIENTRYP PFNGLQUERYCOUNTERPROC)(GLuint id, GLenum target);
            export GLAPI PFNGLQUERYCOUNTERPROC glad_glQueryCounter;
            export inline void glQueryCounter(GLuint id, GLenum target) { glad_glQueryCounter(id, target); }
            export typedef void (APIENTRYP PFNGLGETQUERYOBJECTI64VPROC)(GLuint id, GLenum pname, GLint64* params);
            export GLAPI PFNGLGETQUERYOBJECTI64VPROC glad_glGetQueryObjecti64v;
            export inline void glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64* params) { glad_glGetQueryObjecti64v(id, pname, params); }
            export typedef void (APIENTRYP PFNGLGETQUERYOBJECTUI64VPROC)(GLuint id, GLenum pname, GLuint64* params);
            export GLAPI PFNGLGETQUERYOBJECTUI64VPROC glad_glGetQueryObjectui64v;
            export inline void glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64* params) { glad_glGetQueryObjectui64v(id, pname, params); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIBDIVISORPROC)(GLuint index, GLuint divisor);
            export GLAPI PFNGLVERTEXATTRIBDIVISORPROC glad_glVertexAttribDivisor;
            export inline void glVertexAttribDivisor(GLuint index, GLuint divisor) { glad_glVertexAttribDivisor(index, divisor); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
            export GLAPI PFNGLVERTEXATTRIBP1UIPROC glad_glVertexAttribP1ui;
            export inline void glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { glad_glVertexAttribP1ui(index, type, normalized, value); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
            export GLAPI PFNGLVERTEXATTRIBP1UIVPROC glad_glVertexAttribP1uiv;
            export inline void glVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) { glad_glVertexAttribP1uiv(index, type, normalized, value); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
            export GLAPI PFNGLVERTEXATTRIBP2UIPROC glad_glVertexAttribP2ui;
            export inline void glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { glad_glVertexAttribP2ui(index, type, normalized, value); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
            export GLAPI PFNGLVERTEXATTRIBP2UIVPROC glad_glVertexAttribP2uiv;
            export inline void glVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) { glad_glVertexAttribP2uiv(index, type, normalized, value); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
            export GLAPI PFNGLVERTEXATTRIBP3UIPROC glad_glVertexAttribP3ui;
            export inline void glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { glad_glVertexAttribP3ui(index, type, normalized, value); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
            export GLAPI PFNGLVERTEXATTRIBP3UIVPROC glad_glVertexAttribP3uiv;
            export inline void glVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) { glad_glVertexAttribP3uiv(index, type, normalized, value); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
            export GLAPI PFNGLVERTEXATTRIBP4UIPROC glad_glVertexAttribP4ui;
            export inline void glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { glad_glVertexAttribP4ui(index, type, normalized, value); }
            export typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
            export GLAPI PFNGLVERTEXATTRIBP4UIVPROC glad_glVertexAttribP4uiv;
            export inline void glVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) { glad_glVertexAttribP4uiv(index, type, normalized, value); }
            export typedef void (APIENTRYP PFNGLVERTEXP2UIPROC)(GLenum type, GLuint value);
            export GLAPI PFNGLVERTEXP2UIPROC glad_glVertexP2ui;
            export inline void glVertexP2ui(GLenum type, GLuint value) { glad_glVertexP2ui(type, value); }
            export typedef void (APIENTRYP PFNGLVERTEXP2UIVPROC)(GLenum type, const GLuint* value);
            export GLAPI PFNGLVERTEXP2UIVPROC glad_glVertexP2uiv;
            export inline void glVertexP2uiv(GLenum type, const GLuint* value) { glad_glVertexP2uiv(type, value); }
            export typedef void (APIENTRYP PFNGLVERTEXP3UIPROC)(GLenum type, GLuint value);
            export GLAPI PFNGLVERTEXP3UIPROC glad_glVertexP3ui;
            export inline void glVertexP3ui(GLenum type, GLuint value) { glad_glVertexP3ui(type, value); }
            export typedef void (APIENTRYP PFNGLVERTEXP3UIVPROC)(GLenum type, const GLuint* value);
            export GLAPI PFNGLVERTEXP3UIVPROC glad_glVertexP3uiv;
            export inline void glVertexP3uiv(GLenum type, const GLuint* value) { glad_glVertexP3uiv(type, value); }
            export typedef void (APIENTRYP PFNGLVERTEXP4UIPROC)(GLenum type, GLuint value);
            export GLAPI PFNGLVERTEXP4UIPROC glad_glVertexP4ui;
            export inline void glVertexP4ui(GLenum type, GLuint value) { glad_glVertexP4ui(type, value); }
            export typedef void (APIENTRYP PFNGLVERTEXP4UIVPROC)(GLenum type, const GLuint* value);
            export GLAPI PFNGLVERTEXP4UIVPROC glad_glVertexP4uiv;
            export inline void glVertexP4uiv(GLenum type, const GLuint* value) { glad_glVertexP4uiv(type, value); }
            export typedef void (APIENTRYP PFNGLTEXCOORDP1UIPROC)(GLenum type, GLuint coords);
            export GLAPI PFNGLTEXCOORDP1UIPROC glad_glTexCoordP1ui;
            export inline void glTexCoordP1ui(GLenum type, GLuint coords) { glad_glTexCoordP1ui(type, coords); }
            export typedef void (APIENTRYP PFNGLTEXCOORDP1UIVPROC)(GLenum type, const GLuint* coords);
            export GLAPI PFNGLTEXCOORDP1UIVPROC glad_glTexCoordP1uiv;
            export inline void glTexCoordP1uiv(GLenum type, const GLuint* coords) { glad_glTexCoordP1uiv(type, coords); }
            export typedef void (APIENTRYP PFNGLTEXCOORDP2UIPROC)(GLenum type, GLuint coords);
            export GLAPI PFNGLTEXCOORDP2UIPROC glad_glTexCoordP2ui;
            export inline void glTexCoordP2ui(GLenum type, GLuint coords) { glad_glTexCoordP2ui(type, coords); }
            export typedef void (APIENTRYP PFNGLTEXCOORDP2UIVPROC)(GLenum type, const GLuint* coords);
            export GLAPI PFNGLTEXCOORDP2UIVPROC glad_glTexCoordP2uiv;
            export inline void glTexCoordP2uiv(GLenum type, const GLuint* coords) { glad_glTexCoordP2uiv(type, coords); }
            export typedef void (APIENTRYP PFNGLTEXCOORDP3UIPROC)(GLenum type, GLuint coords);
            export GLAPI PFNGLTEXCOORDP3UIPROC glad_glTexCoordP3ui;
            export inline void glTexCoordP3ui(GLenum type, GLuint coords) { glad_glTexCoordP3ui(type, coords); }
            export typedef void (APIENTRYP PFNGLTEXCOORDP3UIVPROC)(GLenum type, const GLuint* coords);
            export GLAPI PFNGLTEXCOORDP3UIVPROC glad_glTexCoordP3uiv;
            export inline void glTexCoordP3uiv(GLenum type, const GLuint* coords) { glad_glTexCoordP3uiv(type, coords); }
            export typedef void (APIENTRYP PFNGLTEXCOORDP4UIPROC)(GLenum type, GLuint coords);
            export GLAPI PFNGLTEXCOORDP4UIPROC glad_glTexCoordP4ui;
            export inline void glTexCoordP4ui(GLenum type, GLuint coords) { glad_glTexCoordP4ui(type, coords); }
            export typedef void (APIENTRYP PFNGLTEXCOORDP4UIVPROC)(GLenum type, const GLuint* coords);
            export GLAPI PFNGLTEXCOORDP4UIVPROC glad_glTexCoordP4uiv;
            export inline void glTexCoordP4uiv(GLenum type, const GLuint* coords) { glad_glTexCoordP4uiv(type, coords); }
            export typedef void (APIENTRYP PFNGLMULTITEXCOORDP1UIPROC)(GLenum texture, GLenum type, GLuint coords);
            export GLAPI PFNGLMULTITEXCOORDP1UIPROC glad_glMultiTexCoordP1ui;
            export inline void glMultiTexCoordP1ui(GLenum texture, GLenum type, GLuint coords) { glad_glMultiTexCoordP1ui(texture, type, coords); }
            export typedef void (APIENTRYP PFNGLMULTITEXCOORDP1UIVPROC)(GLenum texture, GLenum type, const GLuint* coords);
            export GLAPI PFNGLMULTITEXCOORDP1UIVPROC glad_glMultiTexCoordP1uiv;
            export inline void glMultiTexCoordP1uiv(GLenum texture, GLenum type, const GLuint* coords) { glad_glMultiTexCoordP1uiv(texture, type, coords); }
            export typedef void (APIENTRYP PFNGLMULTITEXCOORDP2UIPROC)(GLenum texture, GLenum type, GLuint coords);
            export GLAPI PFNGLMULTITEXCOORDP2UIPROC glad_glMultiTexCoordP2ui;
            export inline void glMultiTexCoordP2ui(GLenum texture, GLenum type, GLuint coords) { glad_glMultiTexCoordP2ui(texture, type, coords); }
            export typedef void (APIENTRYP PFNGLMULTITEXCOORDP2UIVPROC)(GLenum texture, GLenum type, const GLuint* coords);
            export GLAPI PFNGLMULTITEXCOORDP2UIVPROC glad_glMultiTexCoordP2uiv;
            export inline void glMultiTexCoordP2uiv(GLenum texture, GLenum type, const GLuint* coords) { glad_glMultiTexCoordP2uiv(texture, type, coords); }
            export typedef void (APIENTRYP PFNGLMULTITEXCOORDP3UIPROC)(GLenum texture, GLenum type, GLuint coords);
            export GLAPI PFNGLMULTITEXCOORDP3UIPROC glad_glMultiTexCoordP3ui;
            export inline void glMultiTexCoordP3ui(GLenum texture, GLenum type, GLuint coords) { glad_glMultiTexCoordP3ui(texture, type, coords); }
            export typedef void (APIENTRYP PFNGLMULTITEXCOORDP3UIVPROC)(GLenum texture, GLenum type, const GLuint* coords);
            export GLAPI PFNGLMULTITEXCOORDP3UIVPROC glad_glMultiTexCoordP3uiv;
            export inline void glMultiTexCoordP3uiv(GLenum texture, GLenum type, const GLuint* coords) { glad_glMultiTexCoordP3uiv(texture, type, coords); }
            export typedef void (APIENTRYP PFNGLMULTITEXCOORDP4UIPROC)(GLenum texture, GLenum type, GLuint coords);
            export GLAPI PFNGLMULTITEXCOORDP4UIPROC glad_glMultiTexCoordP4ui;
            export inline void glMultiTexCoordP4ui(GLenum texture, GLenum type, GLuint coords) { glad_glMultiTexCoordP4ui(texture, type, coords); }
            export typedef void (APIENTRYP PFNGLMULTITEXCOORDP4UIVPROC)(GLenum texture, GLenum type, const GLuint* coords);
            export GLAPI PFNGLMULTITEXCOORDP4UIVPROC glad_glMultiTexCoordP4uiv;
            export inline void glMultiTexCoordP4uiv(GLenum texture, GLenum type, const GLuint* coords) { glad_glMultiTexCoordP4uiv(texture, type, coords); }
            export typedef void (APIENTRYP PFNGLNORMALP3UIPROC)(GLenum type, GLuint coords);
            export GLAPI PFNGLNORMALP3UIPROC glad_glNormalP3ui;
            export inline void glNormalP3ui(GLenum type, GLuint coords) { glad_glNormalP3ui(type, coords); }
            export typedef void (APIENTRYP PFNGLNORMALP3UIVPROC)(GLenum type, const GLuint* coords);
            export GLAPI PFNGLNORMALP3UIVPROC glad_glNormalP3uiv;
            export inline void glNormalP3uiv(GLenum type, const GLuint* coords) { glad_glNormalP3uiv(type, coords); }
            export typedef void (APIENTRYP PFNGLCOLORP3UIPROC)(GLenum type, GLuint color);
            export GLAPI PFNGLCOLORP3UIPROC glad_glColorP3ui;
            export inline void glColorP3ui(GLenum type, GLuint color) { glad_glColorP3ui(type, color); }
            export typedef void (APIENTRYP PFNGLCOLORP3UIVPROC)(GLenum type, const GLuint* color);
            export GLAPI PFNGLCOLORP3UIVPROC glad_glColorP3uiv;
            export inline void glColorP3uiv(GLenum type, const GLuint* color) { glad_glColorP3uiv(type, color); }
            export typedef void (APIENTRYP PFNGLCOLORP4UIPROC)(GLenum type, GLuint color);
            export GLAPI PFNGLCOLORP4UIPROC glad_glColorP4ui;
            export inline void glColorP4ui(GLenum type, GLuint color) { glad_glColorP4ui(type, color); }
            export typedef void (APIENTRYP PFNGLCOLORP4UIVPROC)(GLenum type, const GLuint* color);
            export GLAPI PFNGLCOLORP4UIVPROC glad_glColorP4uiv;
            export inline void glColorP4uiv(GLenum type, const GLuint* color) { glad_glColorP4uiv(type, color); }
            export typedef void (APIENTRYP PFNGLSECONDARYCOLORP3UIPROC)(GLenum type, GLuint color);
            export GLAPI PFNGLSECONDARYCOLORP3UIPROC glad_glSecondaryColorP3ui;
            export inline void glSecondaryColorP3ui(GLenum type, GLuint color) { glad_glSecondaryColorP3ui(type, color); }
            export typedef void (APIENTRYP PFNGLSECONDARYCOLORP3UIVPROC)(GLenum type, const GLuint* color);
            export GLAPI PFNGLSECONDARYCOLORP3UIVPROC glad_glSecondaryColorP3uiv;
            export inline void glSecondaryColorP3uiv(GLenum type, const GLuint* color) { glad_glSecondaryColorP3uiv(type, color); }
#endif
#ifndef GL_VERSION_4_0
            export GLAPI int GLAD_GL_VERSION_4_0;
            export typedef void (APIENTRYP PFNGLMINSAMPLESHADINGPROC)(GLfloat value);
            export GLAPI PFNGLMINSAMPLESHADINGPROC glad_glMinSampleShading;
            export inline void glMinSampleShading(GLfloat value) { glad_glMinSampleShading(value); }
            export typedef void (APIENTRYP PFNGLBLENDEQUATIONIPROC)(GLuint buf, GLenum mode);
            export GLAPI PFNGLBLENDEQUATIONIPROC glad_glBlendEquationi;
            export inline void glBlendEquationi(GLuint buf, GLenum mode) { glad_glBlendEquationi(buf, mode); }
            export typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEIPROC)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
            export GLAPI PFNGLBLENDEQUATIONSEPARATEIPROC glad_glBlendEquationSeparatei;
            export inline void glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha) { glad_glBlendEquationSeparatei(buf, modeRGB, modeAlpha); }
            export typedef void (APIENTRYP PFNGLBLENDFUNCIPROC)(GLuint buf, GLenum src, GLenum dst);
            export GLAPI PFNGLBLENDFUNCIPROC glad_glBlendFunci;
            export inline void glBlendFunci(GLuint buf, GLenum src, GLenum dst) { glad_glBlendFunci(buf, src, dst); }
            export typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEIPROC)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
            export GLAPI PFNGLBLENDFUNCSEPARATEIPROC glad_glBlendFuncSeparatei;
            export inline void glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) { glad_glBlendFuncSeparatei(buf, srcRGB, dstRGB, srcAlpha, dstAlpha); }
            export typedef void (APIENTRYP PFNGLDRAWARRAYSINDIRECTPROC)(GLenum mode, const void* indirect);
            export GLAPI PFNGLDRAWARRAYSINDIRECTPROC glad_glDrawArraysIndirect;
            export inline void glDrawArraysIndirect(GLenum mode, const void* indirect) { glad_glDrawArraysIndirect(mode, indirect); }
            export typedef void (APIENTRYP PFNGLDRAWELEMENTSINDIRECTPROC)(GLenum mode, GLenum type, const void* indirect);
            export GLAPI PFNGLDRAWELEMENTSINDIRECTPROC glad_glDrawElementsIndirect;
            export inline void glDrawElementsIndirect(GLenum mode, GLenum type, const void* indirect) { glad_glDrawElementsIndirect(mode, type, indirect); }
            export typedef void (APIENTRYP PFNGLUNIFORM1DPROC)(GLint location, GLdouble x);
            export GLAPI PFNGLUNIFORM1DPROC glad_glUniform1d;
            export inline void glUniform1d(GLint location, GLdouble x) { glad_glUniform1d(location, x); }
            export typedef void (APIENTRYP PFNGLUNIFORM2DPROC)(GLint location, GLdouble x, GLdouble y);
            export GLAPI PFNGLUNIFORM2DPROC glad_glUniform2d;
            export inline void glUniform2d(GLint location, GLdouble x, GLdouble y) { glad_glUniform2d(location, x, y); }
            export typedef void (APIENTRYP PFNGLUNIFORM3DPROC)(GLint location, GLdouble x, GLdouble y, GLdouble z);
            export GLAPI PFNGLUNIFORM3DPROC glad_glUniform3d;
            export inline void glUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z) { glad_glUniform3d(location, x, y, z); }
            export typedef void (APIENTRYP PFNGLUNIFORM4DPROC)(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
            export GLAPI PFNGLUNIFORM4DPROC glad_glUniform4d;
            export inline void glUniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) { glad_glUniform4d(location, x, y, z, w); }
            export typedef void (APIENTRYP PFNGLUNIFORM1DVPROC)(GLint location, GLsizei count, const GLdouble* value);
            export GLAPI PFNGLUNIFORM1DVPROC glad_glUniform1dv;
            export inline void glUniform1dv(GLint location, GLsizei count, const GLdouble* value) { glad_glUniform1dv(location, count, value); }
            export typedef void (APIENTRYP PFNGLUNIFORM2DVPROC)(GLint location, GLsizei count, const GLdouble* value);
            export GLAPI PFNGLUNIFORM2DVPROC glad_glUniform2dv;
            export inline void glUniform2dv(GLint location, GLsizei count, const GLdouble* value) { glad_glUniform2dv(location, count, value); }
            export typedef void (APIENTRYP PFNGLUNIFORM3DVPROC)(GLint location, GLsizei count, const GLdouble* value);
            export GLAPI PFNGLUNIFORM3DVPROC glad_glUniform3dv;
            export inline void glUniform3dv(GLint location, GLsizei count, const GLdouble* value) { glad_glUniform3dv(location, count, value); }
            export typedef void (APIENTRYP PFNGLUNIFORM4DVPROC)(GLint location, GLsizei count, const GLdouble* value);
            export GLAPI PFNGLUNIFORM4DVPROC glad_glUniform4dv;
            export inline void glUniform4dv(GLint location, GLsizei count, const GLdouble* value) { glad_glUniform4dv(location, count, value); }
            export typedef void (APIENTRYP PFNGLUNIFORMMATRIX2DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
            export GLAPI PFNGLUNIFORMMATRIX2DVPROC glad_glUniformMatrix2dv;
            export inline void glUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) { glad_glUniformMatrix2dv(location, count, transpose, value); }
            export typedef void (APIENTRYP PFNGLUNIFORMMATRIX3DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
            export GLAPI PFNGLUNIFORMMATRIX3DVPROC glad_glUniformMatrix3dv;
            export inline void glUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) { glad_glUniformMatrix3dv(location, count, transpose, value); }
            export typedef void (APIENTRYP PFNGLUNIFORMMATRIX4DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
            export GLAPI PFNGLUNIFORMMATRIX4DVPROC glad_glUniformMatrix4dv;
            export inline void glUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) { glad_glUniformMatrix4dv(location, count, transpose, value); }
            export typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
            export GLAPI PFNGLUNIFORMMATRIX2X3DVPROC glad_glUniformMatrix2x3dv;
            export inline void glUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) { glad_glUniformMatrix2x3dv(location, count, transpose, value); }
            export typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
            export GLAPI PFNGLUNIFORMMATRIX2X4DVPROC glad_glUniformMatrix2x4dv;
            export inline void glUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) { glad_glUniformMatrix2x4dv(location, count, transpose, value); }
            export typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
            export GLAPI PFNGLUNIFORMMATRIX3X2DVPROC glad_glUniformMatrix3x2dv;
            export inline void glUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) { glad_glUniformMatrix3x2dv(location, count, transpose, value); }
            export typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
            export GLAPI PFNGLUNIFORMMATRIX3X4DVPROC glad_glUniformMatrix3x4dv;
            export inline void glUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) { glad_glUniformMatrix3x4dv(location, count, transpose, value); }
            export typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
            export GLAPI PFNGLUNIFORMMATRIX4X2DVPROC glad_glUniformMatrix4x2dv;
            export inline void glUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) { glad_glUniformMatrix4x2dv(location, count, transpose, value); }
            export typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
            export GLAPI PFNGLUNIFORMMATRIX4X3DVPROC glad_glUniformMatrix4x3dv;
            export inline void glUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) { glad_glUniformMatrix4x3dv(location, count, transpose, value); }
            export typedef void (APIENTRYP PFNGLGETUNIFORMDVPROC)(GLuint program, GLint location, GLdouble* params);
            export GLAPI PFNGLGETUNIFORMDVPROC glad_glGetUniformdv;
            export inline void glGetUniformdv(GLuint program, GLint location, GLdouble* params) { glad_glGetUniformdv(program, location, params); }
            export typedef GLint(APIENTRYP PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)(GLuint program, GLenum shadertype, const GLchar* name);
            export GLAPI PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC glad_glGetSubroutineUniformLocation;
            export inline GLint glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar* name) { return glad_glGetSubroutineUniformLocation(program, shadertype, name); }
            export typedef GLuint(APIENTRYP PFNGLGETSUBROUTINEINDEXPROC)(GLuint program, GLenum shadertype, const GLchar* name);
            export GLAPI PFNGLGETSUBROUTINEINDEXPROC glad_glGetSubroutineIndex;
            export inline GLuint glGetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar* name) { return glad_glGetSubroutineIndex(program, shadertype, name); }
            export typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint* values);
            export GLAPI PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC glad_glGetActiveSubroutineUniformiv;
            export inline void glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint* values) { glad_glGetActiveSubroutineUniformiv(program, shadertype, index, pname, values); }
            export typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name);
            export GLAPI PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC glad_glGetActiveSubroutineUniformName;
            export inline void glGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name) { glad_glGetActiveSubroutineUniformName(program, shadertype, index, bufSize, length, name); }
            export typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINENAMEPROC)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name);
            export GLAPI PFNGLGETACTIVESUBROUTINENAMEPROC glad_glGetActiveSubroutineName;
            export inline void glGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name) { glad_glGetActiveSubroutineName(program, shadertype, index, bufSize, length, name); }
            export typedef void (APIENTRYP PFNGLUNIFORMSUBROUTINESUIVPROC)(GLenum shadertype, GLsizei count, const GLuint* indices);
            export GLAPI PFNGLUNIFORMSUBROUTINESUIVPROC glad_glUniformSubroutinesuiv;
            export inline void glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint* indices) { glad_glUniformSubroutinesuiv(shadertype, count, indices); }
            export typedef void (APIENTRYP PFNGLGETUNIFORMSUBROUTINEUIVPROC)(GLenum shadertype, GLint location, GLuint* params);
            export GLAPI PFNGLGETUNIFORMSUBROUTINEUIVPROC glad_glGetUniformSubroutineuiv;
            export inline void glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint* params) { glad_glGetUniformSubroutineuiv(shadertype, location, params); }
            export typedef void (APIENTRYP PFNGLGETPROGRAMSTAGEIVPROC)(GLuint program, GLenum shadertype, GLenum pname, GLint* values);
            export GLAPI PFNGLGETPROGRAMSTAGEIVPROC glad_glGetProgramStageiv;
            export inline void glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint* values) { glad_glGetProgramStageiv(program, shadertype, pname, values); }
            export typedef void (APIENTRYP PFNGLPATCHPARAMETERIPROC)(GLenum pname, GLint value);
            export GLAPI PFNGLPATCHPARAMETERIPROC glad_glPatchParameteri;
            export inline void glPatchParameteri(GLenum pname, GLint value) { glad_glPatchParameteri(pname, value); }
            export typedef void (APIENTRYP PFNGLPATCHPARAMETERFVPROC)(GLenum pname, const GLfloat* values);
            export GLAPI PFNGLPATCHPARAMETERFVPROC glad_glPatchParameterfv;
            export inline void glPatchParameterfv(GLenum pname, const GLfloat* values) { glad_glPatchParameterfv(pname, values); }
            export typedef void (APIENTRYP PFNGLBINDTRANSFORMFEEDBACKPROC)(GLenum target, GLuint id);
            export GLAPI PFNGLBINDTRANSFORMFEEDBACKPROC glad_glBindTransformFeedback;
            export inline void glBindTransformFeedback(GLenum target, GLuint id) { glad_glBindTransformFeedback(target, id); }
            export typedef void (APIENTRYP PFNGLDELETETRANSFORMFEEDBACKSPROC)(GLsizei n, const GLuint* ids);
            export GLAPI PFNGLDELETETRANSFORMFEEDBACKSPROC glad_glDeleteTransformFeedbacks;
            export inline void glDeleteTransformFeedbacks(GLsizei n, const GLuint* ids) { glad_glDeleteTransformFeedbacks(n, ids); }
            export typedef void (APIENTRYP PFNGLGENTRANSFORMFEEDBACKSPROC)(GLsizei n, GLuint* ids);
            export GLAPI PFNGLGENTRANSFORMFEEDBACKSPROC glad_glGenTransformFeedbacks;
            export inline void glGenTransformFeedbacks(GLsizei n, GLuint* ids) { glad_glGenTransformFeedbacks(n, ids); }
            export typedef GLboolean(APIENTRYP PFNGLISTRANSFORMFEEDBACKPROC)(GLuint id);
            export GLAPI PFNGLISTRANSFORMFEEDBACKPROC glad_glIsTransformFeedback;
            export inline GLboolean glIsTransformFeedback(GLuint id) { return glad_glIsTransformFeedback(id); }
            export typedef void (APIENTRYP PFNGLPAUSETRANSFORMFEEDBACKPROC)(void);
            export GLAPI PFNGLPAUSETRANSFORMFEEDBACKPROC glad_glPauseTransformFeedback;
            export inline void glPauseTransformFeedback() { glad_glPauseTransformFeedback(); }
            export typedef void (APIENTRYP PFNGLRESUMETRANSFORMFEEDBACKPROC)(void);
            export GLAPI PFNGLRESUMETRANSFORMFEEDBACKPROC glad_glResumeTransformFeedback;
            export inline void glResumeTransformFeedback() { glad_glResumeTransformFeedback(); }
            export typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKPROC)(GLenum mode, GLuint id);
            export GLAPI PFNGLDRAWTRANSFORMFEEDBACKPROC glad_glDrawTransformFeedback;
            export inline void glDrawTransformFeedback(GLenum mode, GLuint id) { glad_glDrawTransformFeedback(mode, id); }
            export typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)(GLenum mode, GLuint id, GLuint stream);
            export GLAPI PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC glad_glDrawTransformFeedbackStream;
            export inline void glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream) { glad_glDrawTransformFeedbackStream(mode, id, stream); }
            export typedef void (APIENTRYP PFNGLBEGINQUERYINDEXEDPROC)(GLenum target, GLuint index, GLuint id);
            export GLAPI PFNGLBEGINQUERYINDEXEDPROC glad_glBeginQueryIndexed;
            export inline void glBeginQueryIndexed(GLenum target, GLuint index, GLuint id) { glad_glBeginQueryIndexed(target, index, id); }
            export typedef void (APIENTRYP PFNGLENDQUERYINDEXEDPROC)(GLenum target, GLuint index);
            export GLAPI PFNGLENDQUERYINDEXEDPROC glad_glEndQueryIndexed;
            export inline void glEndQueryIndexed(GLenum target, GLuint index) { glad_glEndQueryIndexed(target, index); }
            export typedef void (APIENTRYP PFNGLGETQUERYINDEXEDIVPROC)(GLenum target, GLuint index, GLenum pname, GLint* params);
            export GLAPI PFNGLGETQUERYINDEXEDIVPROC glad_glGetQueryIndexediv;
            export inline void glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint* params) { glad_glGetQueryIndexediv(target, index, pname, params); }
        }
    }
}

#ifdef undefed_gl_version_3_0
#define GL_VERSION_3_0
#undef undefed_gl_version_3_0
#endif // undefed_gl_version_3_0
#endif
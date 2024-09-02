#pragma once
#ifndef _RENDER_SETUP_
#define _RENDER_SETUP_
#include "GLINCLUDES.h"
#include "pch.h"
#include "MODULE_IMPORTS.h"
#include "CAMERA.h"
namespace PAIN {
	class Shader;


	class RenderStup {
	private:
		static bool setup_call;
	public:
		static GameObject Render_cam;

		static GLFWwindow* Windowvar;
		static GLFWwindow* Window(int w, int h, const char* Title);
		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

		/// <summary>
		/// HAS TO BE CALLED TWICE!!
		/// </summary>
		/// <param name="w"></param>
		/// <param name="h"></param>
		/// <param name="Title"></param>

		static void Setup(int w, int h, const char* Title);

	};
}
#endif // !_RENDER_SETUP_

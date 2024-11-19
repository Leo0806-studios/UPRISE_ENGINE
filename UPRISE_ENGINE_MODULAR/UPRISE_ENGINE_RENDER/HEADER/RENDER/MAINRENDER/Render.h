#pragma once
#ifndef _Render_
#define _Render_
#include "GLOBAL/GLINCLUDES.h"
#include "GLOBAL.h"
import REF_WRAPPER;
import std;
class GameObject;
namespace RENDER{
		class Material;
		UPRISE_RENDER_API class Render {
	private:
		static std::unordered_map<std::string, int> materialIDlinkdict;
		static RefWrapper<GameObject, true> renderCamera;
		static GLFWwindow* Windowvar;

	public:
		
		Render() = default;
		~Render() {}

		/// <summary>
		/// Set the render camera
		/// </summary>
		/// <param name="cam"></param>
		static void SetRenderCamera(RefWrapper<GameObject, true> cam);
		__inline static  GLFWwindow* GetWindow();

		class RenderSetup {
		private:
			static bool setup_call;
		public:
			static GLFWwindow* Window(int w, int h, const char* Title);
			static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
			static void Setup(int w, int h, const char* Title);
		};
	};
}
#endif // !_Render_

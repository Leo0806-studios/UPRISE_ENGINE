#pragma once
#ifndef _Render_
#define _Render_
#include "GLOBAL/GLINCLUDES.h"
#include "GLOBAL.h"
import REF_WRAPPER;
import std;
class GameObject;
namespace RENDER{
    enum class Render_Backend {
       RB_OPENGL,
        RB_VULKAN,
        RB_DIRECTX11,
        RB_DIRECTX12
    };
		class Material;
		 class Render {
	private:
        UPRISE_RENDER_API static std::unordered_map<std::string, int> materialIDlinkdict;
        UPRISE_RENDER_API static RefWrapper<GameObject, true> renderCamera;
        UPRISE_RENDER_API static GLFWwindow* Windowvar;

	public:
		
		Render() = default;
		~Render() {}

		/// <summary>
		/// Set the render camera
		/// </summary>
		/// <param name="cam"></param>
        UPRISE_RENDER_API static void SetRenderCamera(RefWrapper<GameObject, true> cam);
        UPRISE_RENDER_API __inline static  GLFWwindow* GetWindow();

		class RenderSetup {
		private:
            UPRISE_RENDER_API static bool setup_call;
		public:
            UPRISE_RENDER_API  static void SetRenderBackend(Render_Backend backend);
            UPRISE_RENDER_API   static void CreateBackend();
            UPRISE_RENDER_API static GLFWwindow* Window(int w, int h, const char* Title);
            UPRISE_RENDER_API static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
            UPRISE_RENDER_API static void Setup(int w, int h, const char* Title);
		};
	};
}
#endif // !_Render_

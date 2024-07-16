
//#include "Helpers.h"
#include "pch.h"
#include "RENDER.h"
#include "RENDERSETUP.h"
#include "RENDER_MATERIAL.h"
#include "GAMEOBJECT.h"
#include "DEBUG_LOGGER.h"
// The number of swap chain back buffers.
namespace Renderer {
	
}
bool PAIN::RenderStup::setup_call = 0;
GameObject PAIN::RenderStup::Render_cam;
GLFWwindow* PAIN::RenderStup::Windowvar;
GLFWwindow* PAIN::RenderStup::Window(int w, int h, const char* Title)
{
	GLFWwindow* window = glfwCreateWindow(w, h, "UPRISE", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create window\n";
		std::cout << "either with or heeight or the window title is invalid. try deleting the config file to reset to default values \n" << " or put a 1 at the first spot in the first line to start safe\n";
		glfwTerminate();
		exit( - 1);
	}
	Log << "		- Setting Context";
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "womp womp";;
		exit(-1);
	}
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	return window;
}

void PAIN::RenderStup::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void PAIN::RenderStup::Setup(int w, int h, const char* Title)
{
	if (setup_call == true) {

		return;
	}
	setup_call = true;
	Log << "		- GLFW Init";
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	Log << "		- Creating Window";
	 Windowvar = Window(w,h,Title);
	 Log << "		- Creating Viewport";
	 glViewport(0, 0, w, h);
	 Log << "		- Creating Camera";
	Render_cam = GameObject::CreateCamera(TS_P_Vector3(0,0,0));
	//CORE::Behaviour::updateAll();
	PAIN::Render::CAM = Render_cam.behaviours[2];
	PAIN::Render::RenderCam = &Render_cam.GetComponentDynamic(Camera())->camera;
	//PAIN::Render::RenderCam;

}

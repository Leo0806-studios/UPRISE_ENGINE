#include "INPUT.h"


GLFWwindow* CORE::Input::winow;
 CORE::Input::Input() {}
 CORE::Input::Input(GLFWwindow* Window) { winow = Window; }

 TS_P_Vector2 CORE::Input::MousePosition;
int CORE::Input::GetKey(int key) {
	return glfwGetKey(winow, key);

}

CORE::Input::MouseMode CORE::Input::SetMouseMode(MouseMode mode)
{
	switch (mode) {
	case MouseFree:{
		glfwSetInputMode(winow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		return MouseFree;
			break;
		}
	case MouseLocked: {
		glfwSetInputMode(winow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		return MouseLocked;
		break;
	}
	}
	return MouseMode();
}

void CORE::Input::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	MousePosition.y = ypos;
	MousePosition.x = xpos;
}



void CORE::Input::Init(GLFWwindow* Window)
{
	winow = Window;
	glfwSetCursorPosCallback(winow, mouse_callback);
}

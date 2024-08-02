#include "pch.h"
#include "INPUT.h"


GLFWwindow* CORE::Input::winow;
 CORE::Input::Input() {}
 CORE::Input::Input(GLFWwindow* Window) {
	TrPr(ctx, __func__)
	 winow = Window; 
	TrPrE(ctx);
 }

 TS_P_Vector2 CORE::Input::MousePosition;
int CORE::Input::GetKey(int key) {

	return glfwGetKey(winow, key);

}

CORE::Input::MouseMode CORE::Input::SetMouseMode(MouseMode mode)
{
	TrPr(ctx, __func__)
	switch (mode) {
	case MouseFree:{
		glfwSetInputMode(winow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		TrPrE(ctx);
		return MouseFree;
			break;
		}
	case MouseLocked: {
		glfwSetInputMode(winow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		TrPrE(ctx);
		return MouseLocked;
		break;
	}
	}
	TrPrE(ctx);
	return MouseMode();
}

void CORE::Input::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	TrPr(ctx, __func__)
	MousePosition.y = ypos;
	MousePosition.x = xpos;
	TrPrE(ctx);
}



void CORE::Input::Init(GLFWwindow* Window)
{
	TrPr(ctx, __func__)
	winow = Window;
	glfwSetCursorPosCallback(winow, mouse_callback);
	TrPrE(ctx);
}

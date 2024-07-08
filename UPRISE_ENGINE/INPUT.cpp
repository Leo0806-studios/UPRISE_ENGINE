#include "INPUT.h"


GLFWwindow* CORE::Input::winow;
 CORE::Input::Input() {}
 CORE::Input::Input(GLFWwindow* Window) { winow = Window; }
int CORE::Input::GetKey(int key) {
	return glfwGetKey(winow, key);

}
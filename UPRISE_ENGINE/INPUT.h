#pragma once
#include <glfw3.h>
#define A GLFW_KEY_A
#define B GLFW_KEY_B
#define C GLFW_KEY_C
#define D GLFW_KEY_D
#define E GLFW_KEY_E
#define F GLFW_KEY_F
#define G GLFW_KEY_G
#define H GLFW_KEY_H
#define I GLFW_KEY_I
#define J GLFW_KEY_J
#define K GLFW_KEY_K
#define L GLFW_KEY_L
#define M GLFW_KEY_M
#define N GLFW_KEY_N
#define O GLFW_KEY_O
#define P GLFW_KEY_P
#define Q GLFW_KEY_Q
#define R GLFW_KEY_R
#define S GLFW_KEY_S
#define T GLFW_KEY_T
#define U GLFW_KEY_U
#define V GLFW_KEY_V
#define W GLFW_KEY_W
#define X GLFW_KEY_X
#define Y GLFW_KEY_Y
#define Z GLFW_KEY_Z
#define one GLFW_KEY_1   
#define two GLFW_KEY_2   
#define three GLFW_KEY_3   
#define four GLFW_KEY_4   
#define five GLFW_KEY_5
#define six GLFW_KEY_6
#define seven GLFW_KEY_7
#define nine GLFW_KEY_9
#define eight GLFW_KEY_8 
#define zero GLFW_KEY_0
#define crt GLFW_KEY_LEFT_CONTROL   
#define alt GLFW_KEY_LEFT_ALT   
#define shift GLFW_KEY_LEFT_SHIFT   
namespace CORE {

	static class Input {


	public :static	GLFWwindow* winow;

	public :
		Input() {};
		Input(GLFWwindow* Window) { winow = Window; }


		static int GetKey(int key) {


			return glfwGetKey(winow, key);
		}



	};
}
#ifndef _INPUT_
#define _INPUT_

#include "GLINCLUDES.h"
#include "DATATYPES.h"
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
#define Lcrt GLFW_KEY_LEFT_CONTROL   
#define Lalt GLFW_KEY_LEFT_ALT   
#define Lshift GLFW_KEY_LEFT_SHIFT   
#define Space GLFW_KEY_SPACE
#
namespace CORE {

	 class Input {
		

		


	public :
		enum MouseMode {
			MouseLocked,
			MouseFree
		};
		static	GLFWwindow* winow;

		Input();
		Input(GLFWwindow* Window);

		static TS_P_Vector2 MousePosition;
		static int GetKey(int key);
		static MouseMode SetMouseMode(MouseMode mode);
		static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
		static void Init(GLFWwindow* Window);



	};
}

#endif // !_INPUT_

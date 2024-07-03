// UPRISE_ENGINE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "GLINCLUDES.h"

#include "glad.h"
#include "glfw3.h"
//#include "pch.h"
#include "Helpers.h"

//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
#include "random"
#include "RENDER_DATATYPES.h"
#include "stb_image.h"
#include "filesystem"
#include "TS_P_VECTOR3.h"
#include "GAMEOBJECT.h"
#include "RENDER_OBJECT_SPAWNING.h"
#include "MESSAGES.h"
#include "CORE.h"
#include "INPUT.h"
#include "memory"
#include "TEST.h"
#include "BEHAVIOUR.h"
#include "MESH.h"







MESSAGES::Message_Bus* Messagebus;
ENTITYS::GameObject TestObj;
std::vector<DATATYPES::TS_P_Vector3> VERTS;
bool spawned = false;
GLFWwindow* CORE::Input::winow = nullptr;
std::vector<std::shared_ptr<CORE::Behaviour>> CORE::Behaviour::behaviours;
std::vector<std::shared_ptr<CORE::Behaviour>> CORE::Behaviour::AWAKES;
std::vector<std::shared_ptr<CORE::Behaviour>> CORE::Behaviour::Starts;


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
void processInput(GLFWwindow* window)
{
	if (CORE::Input::GetKey(A)) {
		std::cout << "pressed A";
	}
	if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS) {
		TestObj = TestObj.Create(DATATYPES::TS_P_Vector3(0, 0, 0));
		//TestObj.Mesh.SetMesh(DATATYPES::Mesh(VERTS));
		const  char* pth = "C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\\GAMEDATA\\backpack.obj";

		TestObj.Mesh = COMPONENTS::_Mesh(pth);
		auto a = Camera();
		//CORE::Component* comp = &a;
		a.FOV = 80085;
		//TestObj.AddComponent(a);
		//auto rr = std::make_shared<CORE::Component>(comp);
	
		//auto aaaa = rr.get();
		void* test = &a;


		auto ppp = Test();
		void* msc = &ppp;
		
		TestObj.AddComponent(Test(), msc);
		TestObj.AddComponent(Camera(), test);
		//using element_type = remove_extent_t<_Ty>;

		//const auto _Ptr = dynamic_cast<typename shared_ptr<COMPONENTS::Camera>::element_type*>(_Other.get());
		//auto componentPtr = TestObj.Conponents[0];
		//auto Pp = std::static_pointer_cast<COMPONENTS::Camera>(TestObj.Conponents[0]);
		//std::shared_ptr<COMPONENTS::Camera> Pp = std::dynamic_pointer_cast< COMPONENTS::Camera>(TestObj.Conponents[0]);//std::dynamic_pointer_cast<COMPONENTS::Camera>(TestObj.Conponents[0]);

		Camera* cam =(Camera*) TestObj.Components[0];

		Camera ooo = *TestObj.GetComponent(Camera());
		auto erererere = *cam;
		std::cout << "pressed O";

		//auto base =CORE::Behaviour();
		CORE::Behaviour::updateAll();
		spawned = true;
	}
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"out vec4 pos;\n"
"void main()\n"
"{\n"
"	pos=vec4(aPos.x,aPos.y,aPos.z,1.0);\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"in vec4 pos;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(pos.x*pos.x+0.1f, pos.y*pos.x+0.1f, pos.z*pos.x+0.1f, 0);\n"
"}\n\0";

int main()
{
CORE::SYSTEMS z;
	z=CORE::Startup::Start_Systems() ;
	//std::cout << Messagebus->Exists;
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//auto a = CORE::Object();
	GLFWwindow* window = glfwCreateWindow(800, 600, "UPRISE", NULL, NULL);
	CORE::Input::winow = window;
	if (window == NULL) {
		std::cout << "Womp Womp";
		glfwTerminate();
		return-1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "womp womp";;
		return-1;
	}
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glViewport(0, 0, 800, 600);
	// MSG msg;
	std::cout << "Hello World!\n";

	// build and compile our shader program
	// ------------------------------------
	// vertex shader
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	// check for shader compile errors
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// fragment shader
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	// check for shader compile errors
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// link shaders
	unsigned int shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	// check for linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);


	PAIN::Shader shader("C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\x64\\Debug\\6.1.coordinate_systems.vs", "C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\x64\\Debug\\6.1.coordinate_systems.fs");

	// ------------------------------------------------------------------
	//float vertices[] = {
	//	// positions          // texture coords
	//	 0.5f,  0.5f, 0.0f,   1.0f, 1.0f, // top right
	//	 0.5f, -0.5f, 0.0f,   1.0f, 0.0f, // bottom right
	//	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, // bottom left
	//	-0.5f,  0.5f, 0.0f,   0.0f, 1.0f  // top left 
	//};
	//unsigned int indices[] = {
	//	0, 1, 3, // first triangle
	//	1, 2, 3  // second triangle
	//};
	float vertices[] = {
-0.5f, -0.5f, -0.5f,
0.0f, 0.0f,0.5f,
-0.5f, -0.5f, 1.0f,
0.0f,0.5f, 0.5f,
-0.5f, 1.0f, 1.0f,
0.5f, 0.5f, -0.5f,
1.0f, 1.0f,-0.5f,
0.5f, -0.5f, 0.0f,
1.0f,-0.5f, -0.5f,
-0.5f, 0.0f, 0.0f,
-0.5f, -0.5f, 0.5f,
0.0f, 0.0f,0.5f,
-0.5f, 0.5f, 1.0f,
0.0f,0.5f, 0.5f,
0.5f, 1.0f, 1.0f,
0.5f, 0.5f, 0.5f, 
1.0f, 1.0f,-0.5f,
0.5f, 0.5f, 0.0f, 
1.0f,-0.5f, -0.5f,
0.5f, 0.0f, 0.0f,
-0.5f, 0.5f, 0.5f, 
1.0f, 0.0f,-0.5f,
0.5f, -0.5f, 1.0f, 
1.0f,-0.5f, -0.5f,
-0.5f, 0.0f, 1.0f,
-0.5f, -0.5f, -0.5f,
0.0f, 1.0f,-0.5f, 
-0.5f, 0.5f, 0.0f, 
0.0f,-0.5f, 0.5f,
0.5f, 1.0f, 0.0f,
0.5f, 0.5f, 0.5f,
1.0f, 0.0f,0.5f,
0.5f, -0.5f, 1.0f,
1.0f,0.5f, -0.5f,
-0.5f, 0.0f, 1.0f,
0.5f, -0.5f, -0.5f,
0.0f, 1.0f,0.5f,
-0.5f, 0.5f, 0.0f,
0.0f,0.5f, 0.5f,
0.5f, 1.0f, 0.0f,
-0.5f, -0.5f, -0.5f,
0.0f, 1.0f,0.5f,
-0.5f, -0.5f, 1.0f,
1.0f,0.5f, -0.5f,
0.5f, 1.0f, 0.0f,
0.5f, -0.5f, 0.5f,
1.0f, 0.0f,-0.5f,
-0.5f, 0.5f, 0.0f,
0.0f,-0.5f, -0.5f,
-0.5f, 0.0f, 1.0f,
-0.5f, 0.5f, -0.5f,
0.0f, 1.0f,0.5f,
0.5f, -0.5f, 1.0f, 
1.0f,0.5f, 0.5f, 
0.5f, 1.0f, 0.0f,
0.5f, 0.5f, 0.5f,
1.0f, 0.0f,-0.5f, 
0.5f, 0.5f, 0.0f,
0.0f,-0.5f, 0.5f,
-0.5f, 0.0f, 1.0f
	};
	std::vector<DATATYPES::TS_P_Vector3> verts;
	for (int i = 0; i < 36 * 3; i=i + 3) {
		DATATYPES::TS_P_Vector3 tmp = DATATYPES::TS_P_Vector3(vertices[i], vertices[i + 1], vertices[i + 2]);
		verts.push_back(tmp);

	}
	VERTS = verts;
	unsigned int VBO, VAO, EBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//
//	glBindVertexArray(VAO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	// position attribute
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	// texture coord attribute
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//
//
//	// load and create a texture 
//// -------------------------
	unsigned int texture1, texture2;
//	// texture 1
//	// ---------
//	glGenTextures(1, &texture1);
//	glBindTexture(GL_TEXTURE_2D, texture1);
//	// set the texture wrapping parameters
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	// set texture filtering parameters
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glEnable(GL_DEPTH_TEST);
//	// load image, create texture and generate mipmaps
//	int width, height, nrChannels;
//	stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
//	unsigned char* data = stbi_load("C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\x64\\Debug\\container.jpg", &width, &height, &nrChannels, 0);
//	if (data)
//	{
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else
//	{
//		std::cout << "Failed to load texture" << std::endl;
//	}
//	stbi_image_free(data);
//	// texture 2
//	// ---------
//	glGenTextures(1, &texture2);
//	glBindTexture(GL_TEXTURE_2D, texture2);
//	// set the texture wrapping parameters
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	// set texture filtering parameters
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	// load image, create texture and generate mipmaps
//	data = stbi_load("C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\x64\\Debug\\awesomeface.png", &width, &height, &nrChannels, 0);
//	if (data)
//	{
//		// note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else
//	{
//		std::cout << "Failed to load texture" << std::endl;
//	}
//	stbi_image_free(data);
//
//
//
//	shader.use();
//	shader.setInt("texture1", 0);
//	shader.setInt("texture2", 1);
	auto a = PAIN::Spawning();
	//glm::mat4 proj = glm::perspective(glm::radians(45.0f), (float)800 /
	//	(float)600, 0.1f, 100.0f);
	float ff = 0;
	glm::vec3 cubePositions[] = {
glm::vec3(0.0f, 0.0f, 0.0f),
glm::vec3(2.0f, 5.0f, -15.0f),
glm::vec3(-1.5f, -2.2f, -2.5f),
glm::vec3(-3.8f, -2.0f, -12.3f),
glm::vec3(2.4f, -0.4f, -3.5f),
glm::vec3(-1.7f, 3.0f, -7.5f),
glm::vec3(1.3f, -2.0f, -2.5f),
glm::vec3(1.5f, 2.0f, -2.5f),
glm::vec3(1.5f, 0.2f, -1.5f),
glm::vec3(-1.3f, 1.0f, -1.5f)
	};
	const  char* pth = "C:\\Users\\leo08\\source\\repos\\UPRISE_ENGINE\\\GAMEDATA\\backpack.obj";
	PAIN::Model modell = PAIN::Model(pth);
	bool hasrun = false;
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glActiveTexture(GL_TEXTURE0);
		glActiveTexture(GL_TEXTURE1);



		if (spawned == true&&hasrun==false) {
			//a.SpawnHandler(TestObj.Mesh.mesh.Vertecies, &shader, &VBO, &VAO, &EBO,&texture1,&texture2);
			hasrun = true;
		}
		if (spawned == true) {
			//glBindTexture(GL_TEXTURE_2D, texture1);
		//	glBindTexture(GL_TEXTURE_2D, texture2);

		}
		ff = ff + 0.01f;
		/*glUseProgram(shaderProgram);*/
		shader.use();
		// create transformations
		glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 projection = glm::mat4(1.0f);
		model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f),
			glm::vec3(0.5f, 1.0f, 0.0f));
		//model = glm::rotate(model, glm::radians(ff), glm::vec3(1.0f, 0.0f, 0.0f));
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -10.0f));
		projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);
		// retrieve the matrix uniform locations
		unsigned int modelLoc = glGetUniformLocation(shader.ID, "model");
		unsigned int viewLoc = glGetUniformLocation(shader.ID, "view");
		// pass them to the shaders (3 different ways)
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
		shader.setMat4("projection", projection);
		//shader.setm
		if (spawned==true) {
		//	glBindVertexArray(VAO);
			//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
			//glDrawArrays(GL_TRIANGLES, 0, 36);

			TestObj.Mesh.Model.Draw(shader);
		}
		//modell.Draw(shader);

		
		//for (unsigned int i = 0; i < 10; i++)
		//{
		//	glm::mat4 model = glm::mat4(1.0f);
		//	int r;
		//	//r = rand() % 20 + 1;
		//	glm::vec3 test(0, -ff*0.1f, 0);
		//	model = glm::translate(model, cubePositions[i]+test);
		//	float angle = 20.0f * i;
		//	model = glm::rotate(model, glm::radians(angle+ff*10),
		//		glm::vec3(1.0f, 0.3f, 0.5f));
		//	shader.setMat4("model", model);
		//	glDrawArrays(GL_TRIANGLES, 0, 36);
		//}
		//glDrawArrays(GL_TRIANGLES, 0, 6);
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		
		CORE::Behaviour::updateAll();


		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	
	return 0;
	// int i = 0;
  //   while (i < 10000000000) { i++; i--; i++; i--; i++; }
}

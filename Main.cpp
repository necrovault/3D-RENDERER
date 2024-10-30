#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

/*###########################################################################

##### #####       ###    #####
  #   #   #       #  #   #   #
  #   #   #  ###  #   #  #   #
  #   #   #       #   #  #   #
  #   #####       ####   #####

 
  ** CREATE AN INPUT CLASS (KEYBOARD + MOUSE)
  ** BASIC IMGUI FUNCTINOALITY
  ** IMGUI LAYER CLASS (EVENTS)
  ** IMPLEMENT CLASSES IN MAIN 
 
###########################################################################
*/
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// window settings
unsigned int WIDTH = 800;
unsigned int HEIGHT = 600;

int main()
{
	// set up opengl 4.6
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// create window
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "window", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "COULD NOT CREATE WINDOW " << '\n';
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// intialize glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "COULD NOT INTIALIZE GLAD " << '\n';
		glfwTerminate();
		return -1;
	}

	// render loop
	while (!glfwWindowShouldClose(window))
	{
		// input
		processInput(window);
		
		// background color
		glClearColor(0.15f, 0.15f, 0.15f, 0.15f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, WIDTH, HEIGHT);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
#include "Window.h"

Window::Window(int width, int height, const char* title) {
	if (!glewInit()) {
		std::cout << "Could not initialize GLEW!" << std::endl;
		return;
	}

	if (!glfwInit()) {
		std::cout << "Could not initialize GLFW!" << std::endl;
		return;
	}

	_width = width;
	_height = height;
	_title = title;

	_window = glfwCreateWindow(_width, _height, _title, NULL, NULL);

	std::cout << "Using GLFW version: " << glfwGetVersionString() << std::endl;
}

Window::~Window()
{
	glfwDestroyWindow(_window);
	glfwTerminate();
}

bool Window::ShouldWindowClose() {
	return glfwWindowShouldClose(_window);
}

void Window::WindowRenderScene() {
	glClear(GL_COLOR_BUFFER_BIT || GL_DEPTH_BUFFER_BIT);

	_renderer->RenderScene();

	glfwSwapBuffers(_window);
	glfwPollEvents();
}

bool Window::GetKeyDown(int glfwKey) {
	return (glfwGetKey(_window, glfwKey) == GLFW_PRESS);
}

void Window::CloseWindow() {
	glfwSetWindowShouldClose(_window, GLFW_TRUE);
}
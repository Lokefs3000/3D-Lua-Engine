#pragma onces

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include "Renderer.h"

class Window
{
private:
	GLFWwindow* _window;
	int _width, _height;
	const char* _title;
	Renderer* _renderer;
public:
	Window(int width, int height, const char* title);
	~Window();

	bool ShouldWindowClose();
	bool GetKeyDown(int glfwKey);

	void WindowRenderScene();
	void CloseWindow();
};
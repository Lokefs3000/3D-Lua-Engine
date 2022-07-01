#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Engine/Core/Window.h"

int main() {
	std::cout << "Engine version: 0.0.7v" << std::endl;

	const char* title = "Voxel stuff (i guess)";
	Window* window = new Window(900, 600, title);

	Mesh testingMesh(getAsset("teapot.obj"))
	GameObject testingMesh()

	while (!window->ShouldWindowClose())
	{
		window->WindowRenderScene();

		if (window->GetKeyDown(GLFW_KEY_ESCAPE)) {
			window->CloseWindow();
		}
	}

	return 0;
}
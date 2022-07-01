#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <list>
#include "../Object/GameObject.h"

class Renderer
{
private:
	std::list<GameObject> gameObjects;
public:
	void RenderScene();
};


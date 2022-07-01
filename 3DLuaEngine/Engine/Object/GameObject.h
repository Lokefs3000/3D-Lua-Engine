#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../../glm/vec3.hpp"
#include "Mesh.h"

class GameObject
{
private:
	Mesh _mesh;
public:
	GameObject(Mesh mesh);
	~GameObject();

	Mesh getMesh();

	glm::vec3 Position;
	glm::vec3 Rotation;
	glm::vec3 Scale;
};


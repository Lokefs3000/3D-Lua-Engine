#include "Renderer.h"

void Renderer::RenderScene()
{
	std::list<GameObject> clonedGameObjects = gameObjects;
	for (size_t i = 0; i < gameObjects.size(); i++)
	{
		clonedGameObjects.front().getMesh().RenderMesh();
		clonedGameObjects.pop_front();
	}
}

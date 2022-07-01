#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <list>

class Mesh
{
private:
	GLuint vaoId, vboTextId, vboVertId, vboIndiId, vboNormId;
	int vertexCount;
public:
	Mesh(std::list<float> positions[], std::list<float> textCoords[], std::list<float> normals[], std::list<int> indices[]);
	Mesh();
	~Mesh();

	GLuint getVaoId();
	GLuint getTextVboId();
	GLuint getVertVboId();
	GLuint getIndiVboId();
	GLuint getNormVboId();

	void RenderMesh();
};


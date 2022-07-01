#include "Mesh.h"

Mesh::Mesh(std::list<float> positions[], std::list<float> textCoords[], std::list<float> normals[], std::list<int> indices[]) {
	vertexCount = indices->size();

	glGenVertexArrays(1, &vaoId);
	glBindVertexArray(vaoId);

	glGenBuffers(1, &vboNormId);
	glBindBuffer(GL_ARRAY_BUFFER, vboNormId);
	glBufferData(GL_ARRAY_BUFFER, normals->size(), normals, GL_STATIC_DRAW);
	glVertexAttribPointer(2, 2, GL_FLOAT, false, 0, 0);

	glGenBuffers(1, &vboTextId);
	glBindBuffer(GL_ARRAY_BUFFER, vboTextId);
	glBufferData(GL_ARRAY_BUFFER, textCoords->size(), textCoords, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 2, GL_FLOAT, false, 0, 0);

	glGenBuffers(1, &vboVertId);
	glBindBuffer(GL_ARRAY_BUFFER, vboTextId);
	glBufferData(GL_ARRAY_BUFFER, positions->size(), positions, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &vboIndiId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboIndiId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices->size(), indices, GL_STATIC_DRAW);

	glBindVertexArray(0);
}

Mesh::Mesh() {}

Mesh::~Mesh() {
	glDeleteVertexArrays(1, &vaoId);
	glDeleteBuffers(1, &vboNormId);
	glDeleteBuffers(1, &vboVertId);
	glDeleteBuffers(1, &vboVertId);
	glDeleteBuffers(1, &vboIndiId);
}

GLuint Mesh::getTextVboId()
{
	return vboTextId;
}

GLuint Mesh::getVertVboId()
{
	return vboVertId;
}

GLuint Mesh::getIndiVboId()
{
	return vboIndiId;
}

GLuint Mesh::getNormVboId()
{
	return vboNormId;
}

GLuint Mesh::getVaoId() {
	return vaoId;
}

void Mesh::RenderMesh() {
	glBindVertexArray(vaoId);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glDrawElements(GL_TRIANGLES, vertexCount, GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	glBindVertexArray(0);

	glBindTexture(GL_TEXTURE_2D, 0);
}
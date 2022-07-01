#include "GameObject.h"

GameObject::GameObject(Mesh mesh)
	: Position(0, 0, 0), Rotation(0, 0, 0), Scale(0, 0, 0), _mesh() {
	_mesh = mesh;
}

GameObject::~GameObject() {

}

Mesh GameObject::getMesh() {
	return _mesh;
}
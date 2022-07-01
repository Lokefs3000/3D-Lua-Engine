#include "OBJLoader.h"

void OBJLoader::LoadMesh(char* filePath)
{
    std::list<char*> lines = Utils::readPathAsLines(filePath);

    std::list<glm::vec3>* vertices = new std::list<glm::vec3>;
    std::list<glm::vec2>* textures = new std::list<glm::vec2>;
    std::list<glm::vec3>* normals = new std::list<glm::vec3>;
    std::list<int>* faces = new std::list<int>;

    for (String line : lines) {
        String[] tokens = line.split("\\s+");
        switch (tokens[0]) {
        case "v":
            // Geometric vertex
            Vector3f vec3f = new Vector3f(
                Float.parseFloat(tokens[1]),
                Float.parseFloat(tokens[2]),
                Float.parseFloat(tokens[3]));
            vertices.add(vec3f);
            break;
        case "vt":
            // Texture coordinate
            Vector2f vec2f = new Vector2f(
                Float.parseFloat(tokens[1]),
                Float.parseFloat(tokens[2]));
            textures.add(vec2f);
            break;
        case "vn":
            // Vertex normal
            Vector3f vec3fNorm = new Vector3f(
                Float.parseFloat(tokens[1]),
                Float.parseFloat(tokens[2]),
                Float.parseFloat(tokens[3]));
            normals.add(vec3fNorm);
            break;
        case "f":
            Face face = new Face(tokens[1], tokens[2], tokens[3]);
            faces.add(face);
            break;
        default:
            // Ignore other lines
            break;
        }
    }
    return reorderLists(vertices, textures, normals, faces);
}

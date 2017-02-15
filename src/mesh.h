#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include <vector>

namespace ObjView
{

struct Mesh
{
	std::vector<glm::vec3> vertices, normals;
	std::vector<glm::vec2> uvs;
	std::vector<unsigned int> indices;
};

}

#endif // MESH_H
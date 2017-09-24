#include "Mesh.h"

#include "OBJ_Loader.h"

#include <glm\glm.hpp>

#include <iostream>

Mesh::Mesh()
{
	_locked = false;
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &_vertexArrayObject);
}

void Mesh::Draw()
{
	glBindVertexArray(_vertexArrayObject);

	glDrawArrays(GL_TRIANGLES, 0, _drawCount);

	glBindVertexArray(0);
}

bool Mesh::CreateMesh(Vertex * verticies, int numVertices)
{
	if (_locked)
		return false;

	_drawCount = numVertices;

	glGenVertexArrays(1, &_vertexArrayObject);
	glBindVertexArray(_vertexArrayObject);

	glGenBuffers(NUM_BUFFERS, _vertexArrayBuffers);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexArrayBuffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(Vertex), verticies, GL_STATIC_DRAW); // Static draw means the information will not be changed.

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); // Data for position. 2nd to last parameter is the stride between positions.

	glBindVertexArray(0);

	_locked = true;
	return true;
}

bool Mesh::ImportFromObj(const char * fileName)
{
	if (!_locked)
	{
		_vertices.clear();

		std::vector<glm::vec3> vertices;
		std::vector<glm::vec2> uvs;
		std::vector<glm::vec3> normals;

		bool success = OBJ_Loader::OBJ_Loader::LoadObjFromFile(fileName, vertices, uvs, normals);
		if (!success)
		{
			std::cout << "Failed to load mesh " << fileName << std::endl;
			return false;
		}

		for (int i = vertices.size() - 1; i >= 0; i--)
		{
			Vertex v;
			v.x = vertices[i].x;
			v.y = vertices[i].y;
			v.z = vertices[i].z;
			v.u = uvs[i].x;
			v.v = uvs[i].y;
			v.nx = normals[i].x;
			v.ny = normals[i].y;
			v.nz = normals[i].z;

			_vertices.push_back(v);
		}

		//for (int i = 0; i < vertices.size(); i++)
		//{
		//	Vertex v;
		//	v.x = vertices[i].x;
		//	v.y = vertices[i].y;
		//	v.z = vertices[i].z;
		//	v.u = uvs[i].x;
		//	v.v = uvs[i].y;
		//	v.nx = normals[i].x;
		//	v.ny = normals[i].y;
		//	v.nz = normals[i].z;

		//	_vertices.push_back(v);
		//}

		return true;
	}
	std::cout << "Mesh is locks so can't load .obj: " << fileName << std::endl;
	return false;
}
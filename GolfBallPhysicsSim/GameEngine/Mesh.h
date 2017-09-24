#pragma once

#include "Vertex.h"

#include <vector>
#include <GL\glew.h>

class Mesh
{
public:
	Mesh();
	~Mesh();

	void Draw();

	bool CreateMesh(Vertex* verticies, int numVertices);

	bool ImportFromObj(const char* filename);

	GLuint GetVAO() { return _vertexArrayObject; }
private:
	enum
	{
		POSITION_VB,

		NUM_BUFFERS
	};

	GLuint _vertexArrayObject;
	GLuint _vertexArrayBuffers[NUM_BUFFERS];
	int _drawCount;

	std::vector<Vertex> _vertices;
	bool _locked;
};


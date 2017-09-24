#pragma once

#include "Vertex.h"

#include <GL\glew.h>

class Mesh
{
public:
	Mesh(Vertex* verticies, int numVertices);
	~Mesh();

	void Draw();

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
};


#include "Mesh.h"


Mesh::Mesh(Vertex * verticies, int numVertices)
{
	_drawCount = numVertices;

	glGenVertexArrays(1, &_vertexArrayObject);
	glBindVertexArray(_vertexArrayObject);

	glGenBuffers(NUM_BUFFERS, _vertexArrayBuffers);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexArrayBuffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(Vertex), verticies, GL_STATIC_DRAW); // Static draw means the information will not be changed.

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); // Data for position. 2nd to last parameter is the stride between positions.

	glBindVertexArray(0);
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

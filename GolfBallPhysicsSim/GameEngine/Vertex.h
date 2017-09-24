#pragma once

#include <glm\glm.hpp>

class Vertex
{
public:
	Vertex() {}
	Vertex(const glm::vec3& pos) { _pos = pos; }

	void SetPos(glm::vec3 pos) { _pos = pos; }
private:
	glm::vec3 _pos;
	//glm::vec3 _normal;
	//glm::vec2 _UV;
};
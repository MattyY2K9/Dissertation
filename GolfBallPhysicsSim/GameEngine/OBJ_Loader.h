#pragma once
#include <vector>
// GLM
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

namespace OBJ_Loader
{
	class OBJ_Loader
	{
	public:
		static bool LoadObjFromFile(const char * fileName, std::vector<glm::vec3> &verticies, std::vector<glm::vec2> &uvs, std::vector<glm::vec3> &normals);

	private:
		OBJ_Loader() {}
	};
}


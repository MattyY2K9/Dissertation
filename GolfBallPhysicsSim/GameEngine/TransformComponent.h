#pragma once

#include "glm\glm.hpp"

#include "Component.h"

class TransformComponent : public Component
{
public:
	TransformComponent(GameObject* gob);
	virtual ~TransformComponent();

	// Getters/Setters
	glm::vec3 GetAngle() const;
	void SetAngle(glm::vec3 v) { rotation = v; }

	glm::vec3 GetScale() const;
	void SetScale(glm::vec3 v) { scale = v; }

	glm::vec3 GetPosition() const;
	void SetPosition(glm::vec3 v) { position = v; }

	glm::vec3 GetLocalPosition() { return position; }
private:
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};


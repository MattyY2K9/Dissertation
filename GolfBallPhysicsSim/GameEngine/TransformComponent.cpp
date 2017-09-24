#include "TransformComponent.h"



TransformComponent::TransformComponent(GameObject* gob) : Component(gob, "transform"), position(glm::vec3(0, 0, 0)), rotation(glm::vec3(0, 0, 0)), scale(glm::vec3(1, 1, 1))
{
}

TransformComponent::~TransformComponent()
{
}


glm::vec3 TransformComponent::GetAngle() const
{
	return rotation;
}

glm::vec3 TransformComponent::GetScale() const
{
	return scale;
}

glm::vec3 TransformComponent::GetPosition() const
{
	return position;
}
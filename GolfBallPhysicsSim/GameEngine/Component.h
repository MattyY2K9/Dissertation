#pragma once

#include "GameObject.h"

#include "glm\gtx\rotate_vector.hpp"

#include <string>

class GameObject;

class Component
{
protected:
	GameObject* parent;
	std::string componentType;
public:
	Component(GameObject* p, std::string t) { parent = p; componentType = t; }
	virtual ~Component();

	// Getters/Setters
	GameObject* GetGameObject() const { return parent; }
	std::string GetComponentType() const { return componentType; }

	// Functions
	virtual void Initialise() = 0;
	virtual void Update(double deltaTime) = 0;
	virtual void End() = 0;
};


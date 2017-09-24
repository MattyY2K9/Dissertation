#pragma once
#include <string>
#include <map>

#include "glm\glm.hpp"

// Forward declerations
class Component;

// Typedefs
typedef std::map<std::string, Component*> ComponentMap;
typedef std::map<std::string, Component*>::iterator ComponentMapIterator;

class GameObject
{
protected:
	GameObject* parent;
	
	bool alive;

	ComponentMap components;
public:
	// Constructors
	GameObject();
	virtual ~GameObject();

	bool IsAlive() const { return alive; }
	void SetAlive(bool v) { alive = v; }

	void SetParent(GameObject* p) { parent = p; }
	GameObject* GetParent() { return parent; }

	// Functions
	bool AddComponent(Component* componenet);
	bool RemoveComponent(Component* componenet);
	bool RemoveComponent(std::string componentType);
	Component* GetComponent(std::string type);

	virtual void Initialise();
	virtual void Update(double deltaTime);
	virtual void End();
};


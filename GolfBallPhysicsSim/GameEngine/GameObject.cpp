#include "GameObject.h"
#include "Component.h"

#include <glm\gtx\rotate_vector.hpp>

GameObject::GameObject()
{
	parent = 0;
	SetAlive(true);
}


GameObject::~GameObject()
{
	End();
}

bool GameObject::AddComponent(Component * componenet)
{
	if (components.find(componenet->GetComponentType()) == components.end()) // If component map doesn't contain element it will return the end of the map
	{
		components[componenet->GetComponentType()] = componenet;
		return true;
	}
	return false;
}

bool GameObject::RemoveComponent(Component* goc)
{
	return RemoveComponent(goc->GetComponentType());
}

bool GameObject::RemoveComponent(std::string type)
{
	if (components.find(type) != components.end()) // If component contains element
	{
		components.erase(type);
		return true;
	}
	// Couldn't find it
	return false;
}

Component* GameObject::GetComponent(std::string type)
{
	if (components.find(type) != components.end())
	{
		// Return it
		return components[type];
	}

	// Couldn't find it
	return NULL;
}

void GameObject::Initialise()
{
	// Initialise all objects
	for (ComponentMapIterator i = components.begin();
		i != components.end();
		++i)
	{
		i->second->Initialise();
	}
}

void GameObject::Update(double deltaTime)
{
	// Update all objects
	for (ComponentMapIterator i = components.begin();
		i != components.end();
		++i)
	{
		i->second->Update(deltaTime);
	}
}

void GameObject::End()
{
	// End all objects
	for (ComponentMapIterator i = components.begin();
		i != components.end();
		++i)
	{
		Component* component = i->second;
		component->End();
		delete component;
	}

	// Clear list
	components.clear();
}
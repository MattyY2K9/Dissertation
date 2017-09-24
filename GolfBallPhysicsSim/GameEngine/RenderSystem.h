#pragma once

#include <vector>

#include "RenderComponent.h"
#include "GameObject.h"
#include "Mesh.h"
#include "Shader.h"
#include "Window.h"

class RenderSystem
{
public:
	RenderSystem();
	~RenderSystem();

	void Initialise(Window* window) { _window = window; }
	void Render(std::vector<GameObject*> _gameObjects);
private:
	Window* _window;
	Shader* _activeShader;
};


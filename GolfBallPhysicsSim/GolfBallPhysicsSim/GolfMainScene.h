#pragma once

#include "Scene.h"

#include "GameObject.h"
#include "Shader.h"
#include "Mesh.h"
#include "RenderSystem.h"

class GolfMainScene : public Scene
{
public:
	GolfMainScene();
	~GolfMainScene();

	void Initialise();
	void Update(double deltaTime);
	void Render(RenderSystem* renderer);
};


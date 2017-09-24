#include "Scene.h"

#include "RenderSystem.h"

Scene::Scene()
{
}


Scene::~Scene()
{
}

void Scene::Update(double deltaTime)
{
}

void Scene::Render(RenderSystem * renderer)
{
	renderer->Render(GetGameObjects());
}

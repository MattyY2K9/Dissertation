#include "SceneManager.h"
#include "Scene.h"

SceneManager::SceneManager(GameManager* g) : _game(g)
{
}

SceneManager::~SceneManager()
{
}
void SceneManager::AddGameObject(GameObject* obj)
{
	Scene* currentScene = GetCurrentScene();
	if (currentScene)
	{
		currentScene->AddGameObject(obj);
	}
}

std::vector<GameObject*>& SceneManager::GetGameObjects()
{
	Scene* currentScene = GetCurrentScene();
	if (currentScene)
	{
		return currentScene->GetGameObjects();
	}
	return std::vector<GameObject*>();
}

void SceneManager::Update(double deltaTime)
{
	Scene* currentScene = GetCurrentScene();
	if (currentScene)
	{
		currentScene->Update(deltaTime);
	}
}

void SceneManager::Render(RenderSystem* renderer)
{
	Scene* currentScene = GetCurrentScene();
	if (currentScene)
	{
		currentScene->Render(renderer);
	}
}

void SceneManager::PushScene(Scene* s)
{
	_scenes.push(s);
	s->SetSceneManager(this);
	s->Initialise();
}

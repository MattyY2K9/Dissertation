#pragma once
#include <vector>

class GameObject;
class RenderSystem;
class SceneManager;

class Scene
{
protected:
	SceneManager* sceneManager;
	std::vector<GameObject*> gameObjects;
public:
	Scene();
	virtual ~Scene();

	// Getters/Setters
	std::vector<GameObject*>& GetGameObjects() { return gameObjects; }
	void AddGameObject(GameObject* obj) { gameObjects.push_back(obj); }
	
	void SetSceneManager(SceneManager* s) { sceneManager = s; }
	SceneManager* GetSceneManager()				const { return sceneManager; }


	// Functions
	virtual void Initialise() = 0;
	
	virtual void Update(double deltaTime);

	virtual void Render(RenderSystem* renderer);
};
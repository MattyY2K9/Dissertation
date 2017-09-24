#pragma once
#include <stack>
#include <vector>

class RenderSystem;
class Scene;
class GameManager;
class GameObject;

class SceneManager
{
public:
	SceneManager(GameManager* g);
	~SceneManager();

	// Getters
	Scene* GetCurrentScene() const { if (_scenes.size() > 0) return _scenes.top(); else return NULL; }
	GameManager* GetGame() const { return _game; }

	// Functions
	void AddGameObject(GameObject* obj);
	std::vector<GameObject*>& GetGameObjects();

	// Update current scene
	void Update(double deltaTime);

	// Render current scene
	void Render(RenderSystem* renderer);

	// Pop the top scene. If no scenes remain, we should quit.
	void PopScene() { _scenes.pop(); }

	// Push a new scene
	void PushScene(Scene* s);

protected:
	GameManager* _game;
	std::stack<Scene*> _scenes;
};


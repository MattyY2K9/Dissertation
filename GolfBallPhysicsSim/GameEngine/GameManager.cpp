#include "GameManager.h"



GameManager::GameManager() : quitFlag(false), sceneManger(this)
{
}


GameManager::~GameManager()
{
}

void GameManager::Initialise(Window * w)
{
	window = w;

	renderer.Initialise(w);

	sceneManger = SceneManager(this);

	Shader* shader = new Shader();
	shader->LoadShader("../Assets/Shaders/shader");
	AddShader("default", shader);
}

void GameManager::Run()
{
	// Get delta time
	double temp_time = clock();
	deltaTime = (temp_time - currentTime) / CLOCKS_PER_SEC;
	currentTime = temp_time;
}

Mesh * GameManager::GetMesh(std::string name)
{
	if (meshDictionary.find(name) != meshDictionary.end())  // If it exists
	{
		return meshDictionary[name];						// Return it
	}
	return NULL;
}

Shader * GameManager::GetShader(std::string name)
{
	if (shaderDictionary.find(name) != shaderDictionary.end())  // If it exists
	{
		return shaderDictionary[name];						// Return it
	}
	return NULL;
}

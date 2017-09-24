#pragma once

#include <map>
#include <ctime>

#include "Window.h"
#include "RenderSystem.h"
#include "SceneManager.h"
#include "Mesh.h"
#include "Shader.h"

// Typedefs
typedef std::map<std::string, Mesh*> MeshMap;
typedef std::map<std::string, Shader*> ShaderMap;

class GameManager
{
public:
	GameManager();
	virtual ~GameManager();

	virtual void Initialise(Window* w);
	virtual void Run();

	// Getters/Setters
	Mesh* GetMesh(std::string name);
	void AddMesh(std::string name, Mesh* mesh) { meshDictionary[name] = mesh; }

	Shader* GetShader(std::string name);
	void AddShader(std::string name, Shader* mesh) { shaderDictionary[name] = mesh; }


	void SetQuitFlag(const bool &quit) { quitFlag = quit; }
protected:
	bool keyStates[256];		// Holds state of keys

	double currentTime;
	double deltaTime;
	bool quitFlag;

	Window* window;

	RenderSystem renderer;
	SceneManager sceneManger;

	MeshMap meshDictionary;
	ShaderMap shaderDictionary;
};


#include "GolfBallSimulation.h"

#include "GolfMainScene.h"

GolfBallSimulation::GolfBallSimulation()
{
}


GolfBallSimulation::~GolfBallSimulation()
{
}

void GolfBallSimulation::Initialise(Window * w)
{
	GameManager::Initialise(w);

	Shader* shader = new Shader();
	shader->LoadShader("../Assets/Shaders/shader");
	AddShader("default", shader);
	
	GolfMainScene* _scene = new GolfMainScene();
	sceneManger.PushScene(_scene);
}

void GolfBallSimulation::Run()
{
	GameManager::Run();

	sceneManger.Update(deltaTime);
	sceneManger.Render(&renderer);

	if (sceneManger.GetCurrentScene() == NULL)
		SetQuitFlag(true);
}

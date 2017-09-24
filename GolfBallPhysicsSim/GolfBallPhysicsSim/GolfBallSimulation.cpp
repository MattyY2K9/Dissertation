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

	Vertex vertices[] = {
		Vertex(glm::vec3(0, 0.5f, 0)),
		Vertex(glm::vec3(0.5f, -0.5f, 0)),
		Vertex(glm::vec3(-0.5f, -0.5f, 0))
	};

	Mesh* mesh = new Mesh(vertices, sizeof(vertices) / sizeof(Vertex));
	AddMesh("triangle", mesh);

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

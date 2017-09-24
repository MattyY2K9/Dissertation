#include "RenderSystem.h"

RenderSystem::RenderSystem()
{
}

RenderSystem::~RenderSystem()
{
}

void RenderSystem::Render(std::vector<GameObject*> _gameObjects)
{
	_window->Clear();

	for each (GameObject* obj in _gameObjects)
	{
		RenderComponent* render = (RenderComponent*)obj->GetComponent("render");
		if (render)
		{
			if (render->GetShader() != _activeShader)
			{
				_activeShader = render->GetShader();
				_activeShader->Bind();
			}

			render->Draw();
		}
	}

	_window->SwapBuffers();
}
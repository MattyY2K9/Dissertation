#include "RenderComponent.h"


RenderComponent::RenderComponent(GameObject * obj) : Component(obj, "render")
{
}

RenderComponent::~RenderComponent()
{
}

void RenderComponent::Draw()
{
	_mesh->Draw();
}

#pragma once

#include "GameObject.h"
#include "Component.h"
#include "Mesh.h"
#include "Shader.h"

class RenderComponent : public Component
{
public:
	RenderComponent(GameObject* obj);
	~RenderComponent();

	// Functions
	virtual void Initialise() {};
	virtual void Update(double deltaTime) {};
	virtual void End() {};
	void Draw();

	Mesh* GetMesh() { return _mesh; }
	void SetMesh(Mesh* mesh) { _mesh = mesh; }

	Shader* GetShader() { return _shader; }
	void SetShader(Shader* shader) { _shader = shader; }
private:
	Mesh* _mesh;
	Shader* _shader;
};


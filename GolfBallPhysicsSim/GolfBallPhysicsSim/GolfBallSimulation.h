#pragma once

#include "GameManager.h"

class GolfBallSimulation : public GameManager
{
public:
	GolfBallSimulation();
	~GolfBallSimulation();

	void Initialise(Window* w);
	void Run();
};


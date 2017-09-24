#include <iostream>

#include "Window_GL.h"
#include "GolfBallSimulation.h"

#include <vector>


int main(int argc, char** argv)
{
	Window_GL window(argc, argv);
	RenderSystem renderer;
	GolfBallSimulation simulation;
	renderer.Initialise(&window);

	window.Initialise(800, 600, "Golf Ball Simulation");

	simulation.Initialise(&window);

	while (true)
	{
		simulation.Run();
	}

	return 0;
}
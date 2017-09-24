#include "Window_GL.h"

Window_GL::Window_GL(int args, char** filepath)
{
	glutInit(&args, filepath);

	_clearColour[0] = 0.1f;
	_clearColour[1] = 0.1f;
	_clearColour[2] = 0.8f;
	_clearColour[3] = 1;
}


Window_GL::~Window_GL()
{
}

void Window_GL::Initialise(int width, int height, const std::string & windowName)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_STENCIL); // Double Buffered
	glutInitWindowSize(width, height); // Set the window's initial width & height

	glutCreateWindow(windowName.c_str()); // Create a window with the given title

	GLenum _status = glewInit();
	if (_status != GLEW_OK)
	{
		std::cout << "Glew initialisation failed" << std::endl;
	}

	std::cout << "Initialised Window '" << windowName << "'" << std::endl;
}

void Window_GL::Clear()
{
	glClearColor(_clearColour[0], _clearColour[1], _clearColour[2], _clearColour[3]);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window_GL::Clear(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window_GL::SwapBuffers()
{
	glutSwapBuffers();
}


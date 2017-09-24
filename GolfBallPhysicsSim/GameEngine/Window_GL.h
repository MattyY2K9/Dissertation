#pragma once


#include "Window.h"

#include <GL\glew.h>
#include <GL\glut.h>

class Window_GL : public Window
{
public:
	Window_GL(int args, char** filepath);
	~Window_GL();

	virtual void Initialise(int width, int height, const std::string& windowName);

	void Clear();
	void Clear(float r, float g, float b, float a);
	void SwapBuffers();

	void SetClearColour(float r, float g, float b, float a) { _clearColour[0] = r; _clearColour[1] = g;	_clearColour[2] = b; _clearColour[3] = a; }
private:
	float _clearColour[4];
};


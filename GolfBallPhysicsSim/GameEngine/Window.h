#pragma once

#include <string>
#include <iostream>

class Window
{
public:
	Window();
	virtual ~Window();

	virtual void Clear() = 0;
	virtual void Initialise(int width, int height, const std::string& windowName) = 0;
	virtual void SwapBuffers() = 0;
private:
	// Copy Constructors
	Window(const Window& other) {}
	Window& operator=(const Window& other) {}

};


#pragma once

#include <fstream>
#include <iostream>
#include <string>

#include "GL\glew.h"

class Shader
{
public:
	Shader();
	~Shader();

	void LoadShader(const std::string& fileName);

	void Bind();

private:
	static const unsigned int NUM_SHADER = 2;

	GLuint _program;
	GLuint _shaders[NUM_SHADER];

	std::string GetShaderText(const std::string& filename);
	GLuint CreateShader(const std::string& text, GLenum shaderType);
	void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
};


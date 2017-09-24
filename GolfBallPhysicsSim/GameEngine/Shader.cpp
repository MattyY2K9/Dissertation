#include "Shader.h"


Shader::Shader()
{
	_program = glCreateProgram();
}


Shader::~Shader()
{
	for (int i = 0; i < NUM_SHADER; ++i)
	{
		glDetachShader(_program, _shaders[i]);
		glDeleteShader(_shaders[i]);
	}

	glDeleteProgram(_program);
}

void Shader::LoadShader(const std::string & fileName)
{
	// Vertex Shader
	_shaders[0] = CreateShader(GetShaderText(fileName + ".vs"), GL_VERTEX_SHADER);
	// Fragment Shader
	_shaders[1] = CreateShader(GetShaderText(fileName + ".fs"), GL_FRAGMENT_SHADER);

	for (int i = 0; i < NUM_SHADER; ++i)
	{
		glAttachShader(_program, _shaders[i]);
	}

	glBindAttribLocation(_program, 0, "position");

	glLinkProgram(_program);
	glValidateProgram(_program);
}

void Shader::Bind()
{
	glUseProgram(_program);
}

std::string Shader::GetShaderText(const std::string & filename)
{
	std::ifstream file;
	file.open(filename);

	std::string output;
	std::string line;

	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, line);
			output.append(line + "\n");
		}
	}
	else
	{
		std::cout << "Shader loading failed at '" << filename << "'" << std::endl;
	}

	return output;
}

GLuint Shader::CreateShader(const std::string & text, GLenum shaderType)
{
	GLuint shader = glCreateShader(shaderType);

	if (shader == 0)
	{
		std::cout << "Error: Shader creation failed!" << std::endl;
	}

	int shaderSourceStringLengths[1];
	const GLchar* shaderSourceStrings[1];

	shaderSourceStrings[0] = text.c_str();
	shaderSourceStringLengths[0] = text.length();

	glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringLengths);
	glCompileShader(shader);

	CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error: Shader failed to compile!: ");

	return shader;
}

void Shader::CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
	GLint success = 0;
	GLchar error[1024] = { 0 };

	if (isProgram)
		glGetProgramiv(shader, flag, &success);
	else
		glGetShaderiv(shader, flag, &success);

	if (success == GL_FALSE)
	{
		if (isProgram)
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		else
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);

		std::cout << errorMessage << ": '" << error << "'" << std::endl;
	}
}

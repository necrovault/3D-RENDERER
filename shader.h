#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
	unsigned int ID;

	// constructor
	Shader(const char* vertexPath, const char* fragmentPath);

	// use function
	void use() const;

	// utility functions
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setVec2(const std::string& name, const glm::vec2 vector) const;
	void setVec2(const std::string& name, float x, float y) const;
	void setVec3(const std::string& name, const glm::vec3 vector) const;
	void setVec3(const std::string& name, float x, float y, float z) const;
	void setVec4(const std::string& name, const glm::vec4 vector) const;
	void setVec4(const std::string& name, float x, float y, float z, float w) const;
	void setMat2(const std::string& name, const glm::mat2 matrix) const;
	void setMat3(const std::string& name, const glm::mat3 matrix) const;
	void setMat4(const std::string& name, const glm::mat4 matrix) const;

private:
	void checkCompileErrors(GLuint shader, std::string type);
};


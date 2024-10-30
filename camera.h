#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum CameraMovement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};


class Camera
{
public:
	// camera attributes
	glm::vec3 Position;
	glm::vec3 Front;
	glm::vec3 Up;
	glm::vec3 Right;
	glm::vec3 WorldUp;
	
	// euler angles
	float Yaw, Pitch;

	// camera options
	float MovementSpeed;
	float MouseSensitivity;
	float Zoom;

	// constructor with vectors
	Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch);
	// constructor with scalar values
	Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);

	// return the view matrix calculated using euler angles and the lookAt matrix
	glm::mat4 GetViewMatrix();
	// processes input from keyboard
	void processKeyboard(CameraMovement direction, float deltaTime);
	// processes input from mouse
	void processMouse(float xoffset, float yoffset, GLboolean constrainPitch);
	void processMouseScroll(float yoffset);

private:
	void updateCameraVectors();
};


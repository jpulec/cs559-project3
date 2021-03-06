#pragma once
/************************************************************************/
/* Camera
/* ------
/* A simple 3d camera
/************************************************************************/
#include <glm/glm.hpp>
#include "../Utility/Mesh.h"
#include "HeightMap.h"


namespace sf
{
	class Clock;
	class Input;
}


class Camera
{
public:
	enum Direction { left, right, up, down, lroll, rroll };

private:
	static const float MOUSE_SENSITIVITY;

	bool debug;
	bool mouseLook;

	HeightMap& heightmap;

	glm::vec3 _position;
	glm::vec3 _rotation;
	glm::vec3 _rotationSpeed;

	glm::mat4 _view;
	glm::mat4 _projection;

	void turn(const Direction& direction, float speed, const sf::Clock& clock);
	void move(const float forwardSpeed, const float strafeSpeed=0.f);
	void moveY(const float speed=1.f);

public:
	Camera(HeightMap& heightmap 
		 , const glm::vec3& pos=glm::vec3(0,0,0)
		 , const glm::vec3& rot=glm::vec3(0,0,0)
		 , const glm::vec3& rotSpeed=glm::vec3(0.7, 1.0, 1.0)
		 , const glm::mat4& v=glm::mat4(1.0)
		 , const glm::mat4& proj=glm::mat4(1.0));

	void apply();
	void lookAt(const glm::vec3& eye, const glm::vec3& center, const glm::vec3& up);
	void update(const sf::Clock& clock, const sf::Input& input);
	void processInput(const sf::Input& input, const sf::Clock& clock);

	glm::vec3 getViewDir() const;

	void toggleDebug();
	void toggleMouseLook();
	bool isMouseLook() const;

	void position(const glm::vec3& p);
	void position(const float x, const float y, const float z);
	const glm::vec3& position() const;

	void rotation(const glm::vec3& r);
	void rotation(const float x, const float y, const float z);
	const glm::vec3& rotation() const;

	void rotationSpeed(const glm::vec3& r);
	void rotationSpeed(const float x, const float y, const float z);
	const glm::vec3& rotationSpeed() const;

	void view(const glm::mat4& v);
	const glm::mat4& view() const;

	void projection(const glm::mat4& v);
	const glm::mat4& projection() const;
};


glm::vec3 Camera::getViewDir() const { return glm::vec3(-_view[0][2], -_view[1][2], -_view[2][2]);}

void Camera::toggleDebug() { debug = !debug; }
void Camera::toggleMouseLook() { mouseLook = !mouseLook; }
bool Camera::isMouseLook() const { return mouseLook; }

void Camera::position(const glm::vec3& p) { _position = p; }
void Camera::position(const float x, const float y, const float z) { _position = glm::vec3(x,y,z); }
const glm::vec3& Camera::position() const { return _position; }

void Camera::rotation(const glm::vec3& r) { _rotation = r; }
void Camera::rotation(const float x, const float y, const float z) { _rotation = glm::vec3(x,y,z); }
const glm::vec3& Camera::rotation() const { return _rotation; }

void Camera::rotationSpeed(const glm::vec3& r) { _rotationSpeed = r; }
void Camera::rotationSpeed(const float x, const float y, const float z) { _rotationSpeed = glm::vec3(x,y,z); }
const glm::vec3& Camera::rotationSpeed() const { return _rotationSpeed; }

void Camera::view(const glm::mat4& v) { _view = v; }
const glm::mat4& Camera::view() const { return _view; }

void Camera::projection(const glm::mat4& p) { _projection = p; }
const glm::mat4& Camera::projection() const { return _projection; }

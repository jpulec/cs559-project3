#pragma once
/************************************************************************/
/* Render 
/* ------
/* A static helper class for rendering various things 
/************************************************************************/
#include "../Scene/Camera.h"

#include <glm/glm.hpp>

#include "Plane.h"


class Render
{
public:
	// Draw a basic cube at the specified position with the specified scale
	static void cube(const glm::vec3& position=glm::vec3(0,0,0)
					,const float scale=1.f);

	// Draw the specified plane as a quad with the specified radius
	static void plane(const Plane& plane, const float radius=10.f);

	//draw pyramid
	static void pyramid(const glm::vec3& pos, const float radius, const float height);

	// Draw a vector from the specified point
	static void vector(const glm::vec3& v, const glm::vec3& point
					 , const glm::vec3& color=glm::vec3(1,1,1));

	// Draw the projection matrix frustum for the specified camera
	static void frustum(const Camera& camera);

	// Draw the specified coordinate axes
	static void basis(const glm::vec3& x=glm::vec3(1,0,0)
					, const glm::vec3& y=glm::vec3(0,1,0)
					, const glm::vec3& z=glm::vec3(0,0,1));
};

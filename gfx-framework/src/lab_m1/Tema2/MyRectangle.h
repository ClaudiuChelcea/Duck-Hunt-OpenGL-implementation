#pragma once

#include "components/simple_scene.h"

class MyRectangle
{
	private:
		glm::vec3 corners[8] = {
			{ 0.0f, 0.0f, 0.5f },
			{ 0.5f, 0.0f, 0.5f },
			{ 0.0f, 0.5f, 0.5f },
			{ 0.5f, 0.5f, 0.5f },
			{ 0.0f, 0.0f, 0.0f },
			{ 0.5f, 0.0f, 0.0f },
			{ 0.0f, 0.5f, 0.0f },
			{ 0.5f, 0.5f, 0.0f },
		};
	public:
		// Constructor
		MyRectangle() = default;

		// Getters
		glm::vec3* getCorners();
};

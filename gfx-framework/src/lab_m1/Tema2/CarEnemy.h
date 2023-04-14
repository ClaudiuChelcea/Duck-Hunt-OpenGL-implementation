#pragma once

#include "components/simple_scene.h"
#include "transform3D.h"

class CarEnemy
{
	private:
		glm::vec3 position = { 0.0f, 0.0f, 0.0f };
		glm::vec3 ground_offset = { 0.0f, 0.0f, 0.0f };
		float fill_rate = 0.0f;
		float speed = 0.0f;
		float trajectory_offset = 0.0f;
		glm::vec3 color = { 0.0f, 0.0f, 0.0f };
		std::string object_name = "";
		int start_index = 0;
		std::vector<unsigned int> defaultIndicesCar =
		{
			0, 1, 2,
			2, 3, 7,
			2, 7, 6,
			1, 7, 3,
			1, 5, 7,
			6, 7, 4,
			7, 5, 4,
			0, 4, 1,
			1, 4, 5,
			2, 6, 4,
			0, 2, 4,
		};
	public:
		// Constructors
		CarEnemy(glm::vec3 _position = { 0.0f, 0.0f, 0.0f }, glm::vec3 _color = { 0.0f, 0.0f, 0.0f }, glm::vec3 _ground_offset = { 0.0f, 0.0f, 0.0f },
			float _fill_rate = 0.0f, float _speed = 0.0f, float _trajectory_offset = 0.0f, std::string _object_name = "", int _start_index = 0);
		
		// Getters
		glm::vec3 getColor();
		glm::vec3 getPos();
		glm::vec3 getGroundOffset();
		float getFillRate();
		float getSpeed();
		float getTrajectoryOffset();
		std::string getObjectName();
		int getStartIndex();
		std::vector<unsigned int> getDefaultIndicesCar();

		// Setters
		void setStartIndex(int _start_index);
		void setPos(float _x, float _y, float _z);
		
		// Methods
		void increaseFillRate(); // ++ fill rate
		void nullifyFillRate(); // set fill rate to 0
		void carMovement(glm::mat4& modelMatrix, glm::vec3 points[]);
};


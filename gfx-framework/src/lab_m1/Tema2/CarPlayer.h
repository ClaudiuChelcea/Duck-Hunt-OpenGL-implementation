#pragma once

#include "components/simple_scene.h"
#include "transform3D.h"

class CarPlayer
{
	private:
		float speed = 0.0f;
		glm::vec3 carCenter = glm::vec3( 0.25f, 0.0f, 0.25f );
		float offset = 0.0f;
		float speed_reducer = 0.0f;
		glm::vec2 newTR_star = { 0.0f, 0.0f };
		glm::vec3 translation = { 0.0f, 0.0f, 0.0f };
		float rotationAngle = 0.0f;
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
		glm::vec3 player_color = { 0.0f, 0.0f, 0.0f };
		std::string objectName = "player";
	public:
		// Constructors
		CarPlayer(float _speed = 0.0f, glm::vec3 _carCenter = { 0.25f, 0.0f, 0.25f },
			float _offset = 0.0f, float _speed_reducer = 0.0f, glm::vec2 _newTR_star = { 0.0f, 0.0f },
			glm::vec3 _translation = { 0.0f, 0.0f, 0.0f }, float _rotation_angle = 0.0f,
			glm::vec3 _player_color = { 0.0f, 0.0f, 0.0f });
		
		// Getters
		float getSpeed();
		glm::vec3 getCarCenter();
		float getOffset();
		float getSpeedReducer();
		glm::vec2 getnewTR_star();
		glm::vec3 getTranslation();
		float getRotationAngle();
		std::vector<unsigned int> getDefaultIndicesCar();
		std::string getObjectName();
		glm::vec3 getPlayerColor();

		// Setters
		void setNewTR_star(float _x, float _y);
		void setNewTR_star(glm::vec2 _newTR_star);
		void setTranslation(glm::vec3 _translation);
		void setTranslation(float _x, float _y, float _z);
		void setRotationAngle(float _rotationAngle);

		// Methods
};


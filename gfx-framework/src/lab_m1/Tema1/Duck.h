#ifndef __DUCK_H
#define __DUCK_H

#pragma once

#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"

class Duck {
private:
	// Body
	Mesh* body{ NULL }; // The body of the duck
	std::pair<float, float> bodyPos{ 0, 0 };
	float bodyRotation{ 0.0f };
	std::pair<int, int> duckWidth{ -85, 40 }; // LEFT AND RIGHT
	std::pair<int, int> duckHeight{ -85, 40 }; // LEFT AND RIGHT
	std::pair<float, float> gravityCenter{ 0.0f, 0.0f };

	// Wing Left
	Mesh* wingLeft{ NULL }; // The left wing of the duck
	std::pair<float, float> leftWingBodyOffset{ 25.0f, -25.0f };

	// Wing Right
	Mesh* wingRight{ NULL }; // The right wing of the duck
	std::pair<float, float> rightWingBodyOffset{ -25.0f, 25.0f };

	// Head
	Mesh* head { NULL }; // The head of the duck
	std::pair<float, float> headBodyOffset{ -45.0f, -30.0f };

	// Beak
	Mesh* beak { NULL }; // The beak of the duck
	std::pair<float, float> beakBodyOffset{ -40.0f, -35.0f };

	// Hitbox
	Mesh* hitbox { NULL }; // The beak of the duck
	std::pair<float, float> hitboxBodyOffset{ 100.0f, 100.0f };

	// Eye left
	Mesh* eyeLeft{ NULL }; // The left eye of the duck
	std::pair<float, float> eyeLeftBodyOffset{ -45.0f, -50.0f };
	Mesh* eyeLeftPupil{ NULL }; // The left eye of the duck
	std::pair<float, float> eyeLeftBodyOffsetPupil{ -45.0f, -50.0f };
	
	// Eye right
	Mesh* eyeRight{ NULL }; // The right eye of the duck
	std::pair<float, float> eyeRightBodyOffset{ -70.0f, -30.0f };
	Mesh* eyeRightPupil{ NULL }; // The right eye of the duck
	std::pair<float, float> eyeRightBodyOffsetPupil{ -70.0f, -30.0f };

	// Speed
	float Speed{ 300.0f };

	// Direction
	float translateX{ 0.0f }; 
	float translateY{ 0.0f };

	// Orientation
	float travellingAngle{ 45 };
	float duckAngle{ 180 };

	// Status
	float timeAlive = 0.0f;
	float timeAliveLimit = 8.0f;
	int livesCount = 3;
	int bulletsCount = 3;
	bool wasShot = false;
	bool evading = false;
public:
	// Constructor
	Duck() = default;

	// Create default duck
	void createDuck();

	/* Getters */
	// Body
	Mesh* getBody();
	std::string getBodyString();
	std::pair<float, float> getBodyPosition();
	float getBodyRotation();
	std::pair<int, int> getDuckWidth();
	std::pair<int, int> getDuckHeight();
	std::pair<float, float> getGravityCenter();

	// Wing Left
	Mesh* getWingLeft();
	std::string getWingLeftString();
	std::pair<float, float> getLeftWingBodyOffset();

	// Wing Right
	Mesh* getWingRight();
	std::string getWingRightString();
	std::pair<float, float> getRightWingBodyOffset();

	// Head
	Mesh* getHead();
	std::string getHeadString();
	std::pair<float, float> getHeadBodyOffset();

	// Beak
	Mesh* getBeak();
	std::string getBeakString();
	std::pair<float, float> getBeakBodyOffset();
	
	// Hitbox
	Mesh* getHitbox();
	std::string getHitboxString();
	std::pair<float, float> getHitboxBodyOffset();

	// Eye left
	Mesh* getEyeLeft();
	std::string getEyeLeftString();
	std::pair<float, float> getEyeLeftBodyOffset();
	Mesh* getEyeLeftPupil();
	std::string getEyeLeftStringPupil();
	std::pair<float, float> getEyeLeftBodyOffsetPupil();

	// Eye right
	Mesh* getEyeRightPupil();
	std::string getEyeRightStringPupil();
	std::pair<float, float> getEyeRightBodyOffsetPupil();
	Mesh* getEyeRight();
	std::string getEyeRightString();
	std::pair<float, float> getEyeRightBodyOffset();

	// Speed
	float getSpeed();
	float getInitialSpeed();

	// Direction
	float getTranslateX();
	float getTranslateY();

	// Orientation
	float getTravellingAngle();
	float getDuckAngle();

	// Status
	float getTimeAlive();
	float getTimeAliveLimit();
	int getLivesCount();
	int getBulletsCount();
	bool getWasShot();
	bool getEvading();
	
	/* Setters */
	// Body
	void setBodyPosition(std::pair<float, float> position);
	void setBodyRotation(float radians);
	void setGravityCenter(std::pair<float, float> _gravity_center);

	// Speed
	void setSpeed(float _Speed);

	// Direction
	void setTranslateX(float _translateX);
	void setTranslateY(float _translateY);

	// Orientation
	void setTravellingAngle(float _travellingAngle);
	void setDuckAngle(float _duckAngle);

	// Status
	void setTimeAlive(float _timeAlive);
	void setTimeAliveLimit(float _timeAliveLimit);
	void setLivesCount(int _livesCount);
	void setBulletsCount(int _bulletsCount);
	void setWasShot(bool _wasShot);
	void setEvading(bool _evading);
};

#endif // __DUCK_H

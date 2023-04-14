#include "Duck.h"

// Constructor
void Duck::createDuck()
{
	// Create body
	this->body = Triangle::CreateTriangle("body", glm::vec3 (0.0f, 0.0f, 0.0f), 90.0f, glm::vec3(0.0f, 0.0f, 0.0f));

	// Create wingLeft
	this->wingLeft = Triangle::CreateTriangle("wingLeft", glm::vec3(0.0f, 0.0f, 0.0f), 45.0f, glm::vec3(0.0f, 0.0f, 1.0f));

	// Create wingRight
	this->wingRight = Triangle::CreateTriangle("wingRight", glm::vec3(0.0f, 0.0f, 0.0f), 45.0f, glm::vec3(0.0f, 0.0f, 1.0f));

	// Create head
	this->head = Circle::CreateCircle("head", glm::vec3(0.0f, 0.0f, 0.0f), 50.0f, 100.0f, glm::vec3(0.0f, 0.0f, 1.0f));

	// Create beak
	this->beak = Triangle::CreateTriangle("beak", glm::vec3(0.0f, 0.0f, 0.0f), 25.0f, glm::vec3(0.64f, 1.0f, 0.0f));

	// Create hitbox
	this->hitbox = Rectangle::CreateRectangle("hitbox", glm::vec3(0.0f, 0.0f, 0.0f), 180.0f, 130.0f, glm::vec3(1.0f, 0.0f, 0.0f));

	// Create eyeLeft
	this->eyeLeft = Circle::CreateCircle("eyeLeft", glm::vec3(0.0f, 0.0f, 0.0f), 10.0f, 100.0f, glm::vec3(1.0f, 1.0f, 1.0f));
	this->eyeLeftPupil = Circle::CreateCircle("eyeLeftPupil", glm::vec3(0.0f, 0.0f, 0.0f), 5.0f, 100.0f, glm::vec3(0.0f, 0.0f, 0.0f));

	// Create eyeRight
	this->eyeRight = Circle::CreateCircle("eyeRight", glm::vec3(0.0f, 0.0f, 0.0f), 10.0f, 100.0f, glm::vec3(1.0f, 1.0f, 1.0f));
	this->eyeRightPupil = Circle::CreateCircle("eyeRightPupil", glm::vec3(0.0f, 0.0f, 0.0f), 5.0f, 100.0f, glm::vec3(0.0f, 0.0f, 0.0f));

	// Calculate gravity center
	gravityCenter.first = (0 + 125) / 2;
	gravityCenter.second = (0 + 125) / 2;
}

/* Getters */
// Body
Mesh* Duck::getBody()
{
	return body;
}

std::string Duck::getBodyString()
{
	return std::string("body");
}

std::pair<float, float> Duck::getBodyPosition()
{
	return bodyPos;
}

float Duck::getBodyRotation() {
	return this->bodyRotation;
}

std::pair<int, int> Duck::getDuckWidth()
{
	return duckWidth;
}

std::pair<int, int> Duck::getDuckHeight()
{
	return duckHeight;
}

std::pair<float, float> Duck::getGravityCenter()
{
	return gravityCenter;
}

// Wing Left
Mesh* Duck::getWingLeft()
{
	return wingLeft;
}

std::pair<float, float> Duck::getLeftWingBodyOffset()
{
	return this->leftWingBodyOffset;
}

std::string Duck::getWingLeftString()
{
	return std::string("wingLeft");
}

// Wing Right
Mesh* Duck::getWingRight()
{
	return wingRight;
}


std::string Duck::getWingRightString()
{
	return std::string("wingRight");
}

std::pair<float, float> Duck::getRightWingBodyOffset()
{
	return this->rightWingBodyOffset;
}

// Head
Mesh* Duck::getHead()
{
	return head;
}

std::string Duck::getHeadString()
{
	return std::string("head");
}

std::pair<float, float> Duck::getHeadBodyOffset()
{
	return this->headBodyOffset;
}

// Beak
Mesh* Duck::getBeak()
{
	return beak;
}

std::string Duck::getBeakString()
{
	return std::string("beak");
}

std::pair<float, float> Duck::getBeakBodyOffset()
{
	return this->beakBodyOffset;
}

// Hitbox
Mesh* Duck::getHitbox()
{
	return hitbox;
}

std::string Duck::getHitboxString()
{ 
	return std::string("hitbox");
}

std::pair<float, float> Duck::getHitboxBodyOffset()
{
	return this->hitboxBodyOffset;
}

// Eye left
Mesh* Duck::getEyeLeft()
{
	return eyeLeft;
}

std::string Duck::getEyeLeftString()
{
	return "eyeLeft";
}

std::pair<float, float> Duck::getEyeLeftBodyOffset()
{
	return eyeLeftBodyOffset;
}

Mesh* Duck::getEyeLeftPupil()
{
	return eyeLeftPupil;
}

std::string Duck::getEyeLeftStringPupil()
{
	return "eyeLeftPupil";
}

std::pair<float, float> Duck::getEyeLeftBodyOffsetPupil()
{
	return eyeLeftBodyOffsetPupil;
}

// Eye right
Mesh* Duck::getEyeRight()
{
	return eyeRight;
}

std::string Duck::getEyeRightString()
{
	return "eyeRight";
}

std::pair<float, float> Duck::getEyeRightBodyOffset()
{
	return eyeRightBodyOffset;
}

Mesh* Duck::getEyeRightPupil()
{
	return eyeRightPupil;
}

std::string Duck::getEyeRightStringPupil()
{
	return "eyeRightPupil";
}

std::pair<float, float> Duck::getEyeRightBodyOffsetPupil()
{
	return eyeRightBodyOffsetPupil;
}

// Speed
float Duck::getSpeed()
{
	return Speed;
}

// Speed
float Duck::getInitialSpeed()
{
	return 300.0f;
}


// Direction
float Duck::getTranslateX()
{
	return translateX;
}
float Duck::getTranslateY()
{
	return translateY;
}

// Orientation
float Duck::getTravellingAngle()
{
	return travellingAngle;
}

float Duck::getDuckAngle()
{
	return duckAngle;
}

// Status
float Duck::getTimeAlive()
{
	return timeAlive;
}

float Duck::getTimeAliveLimit()
{
	return timeAliveLimit;
}

int Duck::getLivesCount()
{
	return livesCount;
}

int Duck::getBulletsCount()
{
	return bulletsCount;
}

bool Duck::getWasShot()
{
	return wasShot;
}

bool Duck::getEvading()
{
	return evading;
}

/* Setters */
// Body
void Duck::setBodyPosition(std::pair<float, float> position)
{
	this->bodyPos.first = position.first;
	this->bodyPos.second = position.second;
}

void Duck::setBodyRotation(float radians)
{
	this->bodyRotation = radians;
}

void Duck::setGravityCenter(std::pair<float, float> _gravity_center)
{
	gravityCenter.first = _gravity_center.first;
	gravityCenter.second = _gravity_center.second;
}

// Speed
void Duck::setSpeed(float _Speed)
{
	Speed = _Speed;
}

// Direction
void Duck::setTranslateX(float _translateX)
{
	translateX = _translateX;
}

void Duck::setTranslateY(float _translateY)
{
	translateY = _translateY;
}

// Orientation
void Duck::setTravellingAngle(float _travellingAngle)
{
	travellingAngle = _travellingAngle;
}

void Duck::setDuckAngle(float _duckAngle)
{
	duckAngle = _duckAngle;
}

// Status
void Duck::setTimeAlive(float _timeAlive)
{
	timeAlive = _timeAlive;
}

void Duck::setTimeAliveLimit(float _timeAliveLimit)
{
	timeAliveLimit = _timeAliveLimit;
}

void Duck::setLivesCount(int _livesCount)
{
	livesCount = _livesCount;
}

void Duck::setBulletsCount(int _bulletsCount)
{
	bulletsCount = _bulletsCount;
}

void Duck::setWasShot(bool _wasShot)
{
	wasShot = _wasShot;
}

void Duck::setEvading(bool _evading)
{
	evading = _evading;
}

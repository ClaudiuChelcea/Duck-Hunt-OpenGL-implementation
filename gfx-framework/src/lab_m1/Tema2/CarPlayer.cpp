#include "CarPlayer.h"

// Constructors
CarPlayer::CarPlayer(float _speed, glm::vec3 _carCenter, float _offset, float _speed_reducer,
	glm::vec2 _newTR_star, glm::vec3 _translation, float _rotationAngle, glm::vec3 _player_color)
{
	this->speed = _speed;
	this->carCenter = _carCenter;
	this->offset = _offset;
	this->speed_reducer = _speed_reducer;
	this->newTR_star = _newTR_star;
	this->translation = _translation;
	this->rotationAngle = _rotationAngle;
	this->player_color = _player_color;
}

// Getters
float CarPlayer::getSpeed()
{
	return this->speed;
}

glm::vec3 CarPlayer::getCarCenter()
{
	return this->carCenter;
}

float CarPlayer::getOffset()
{
	return this->offset;
}

float CarPlayer::getSpeedReducer()
{
	return this->speed_reducer;
}

glm::vec2 CarPlayer::getnewTR_star()
{
	return this->newTR_star;
}

glm::vec3 CarPlayer::getTranslation()
{
	return this->translation;
}

float CarPlayer::getRotationAngle()
{
	return this->rotationAngle;
}

std::vector<unsigned int> CarPlayer::getDefaultIndicesCar()
{
	return this->defaultIndicesCar;
}

std::string CarPlayer::getObjectName()
{
	return this->objectName;
}

glm::vec3 CarPlayer::getPlayerColor()
{
	return this->player_color;
}

// Setters
void CarPlayer::setNewTR_star(float _x, float _y)
{
	this->newTR_star.x = _x;
	this->newTR_star.y = _y;
}

void CarPlayer::setNewTR_star(glm::vec2 _newTR_star)
{
	this->newTR_star = _newTR_star;
}

void CarPlayer::setTranslation(glm::vec3 _translation)
{
	this->translation = _translation;
}

void CarPlayer::setTranslation(float _x, float _y, float _z)
{
	this->translation.x = _x;
	this->translation.y = _y;
	this->translation.z = _z;
}

void CarPlayer::setRotationAngle(float _rotationAngle)
{
	this->rotationAngle = _rotationAngle;
}

// Methods
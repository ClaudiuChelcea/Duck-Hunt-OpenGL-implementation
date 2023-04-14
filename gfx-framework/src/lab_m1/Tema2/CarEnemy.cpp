#include "CarEnemy.h"

// Constructors
CarEnemy::CarEnemy(glm::vec3 _position, glm::vec3 _color, glm::vec3 _ground_offset,
	float _fill_rate, float _speed, float _trajectory_offset, std::string _object_name, int _start_index)
{
	this->position = _position;
	this->color = _color;
	this->ground_offset = _ground_offset;
	this->fill_rate = _fill_rate;
	this->speed = _speed;
	this->trajectory_offset = _trajectory_offset;
	this->object_name = _object_name;
	this->start_index = _start_index;
}

// Getters
glm::vec3 CarEnemy::getColor()
{
	return this->color;
}

glm::vec3 CarEnemy::getGroundOffset()
{
	return this->ground_offset;
}

glm::vec3 CarEnemy::getPos()
{
	return this->position;
}

float CarEnemy::getFillRate()
{
	return this->fill_rate;
}

float CarEnemy::getSpeed()
{
	return this->speed;
}

float CarEnemy::getTrajectoryOffset()
{
	return this->trajectory_offset;
}

std::string CarEnemy::getObjectName()
{
	return this->object_name;
}

int CarEnemy::getStartIndex()
{
	return this->start_index;
}

// Setters
void CarEnemy::setStartIndex(int _start_index)
{
	this->start_index = _start_index;
}

void CarEnemy::setPos(float _x, float _y, float _z)
{
	this->position.x = _x;
	this->position.y = _y;
	this->position.z = _z;
}

// Methods
void CarEnemy::increaseFillRate()
{
	// ++ fill rate
	this->fill_rate++;
}

void CarEnemy::nullifyFillRate()
{
	// set fill rate to 0
	this->fill_rate = 0;
}

void CarEnemy::carMovement(glm::mat4& modelMatrix, glm::vec3 points[])
{
    // First enemy
    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(this->getGroundOffset().x, this->getGroundOffset().y, this->getGroundOffset().z);
    if (this->getStartIndex() == 70) {
        if (this->getFillRate() == 0) {
            this->setPos(points[70].x + this->getTrajectoryOffset(), points[70].y, points[70].z + this->getTrajectoryOffset());
        }

        this->increaseFillRate();
        this->setPos(this->getPos().x + (points[0].x - points[70].x) / this->getSpeed(),
            this->getPos().y + (points[0].y - points[70].y) / this->getSpeed(),
            this->getPos().z + (points[0].z - points[70].z) / this->getSpeed());

        if (this->getFillRate() == this->getSpeed()) {
            this->setStartIndex(0);
            this->nullifyFillRate();
        }

        modelMatrix *= transform3D::Translate(this->getPos().x, this->getPos().y, this->getPos().z);
    }
    else {
        if (this->getFillRate() == 0) {
            this->setPos(points[this->getStartIndex()].x + this->getTrajectoryOffset(), points[this->getStartIndex()].y, points[this->getStartIndex()].z + this->getTrajectoryOffset());
        }

        this->increaseFillRate();
        this->setPos(
            this->getPos().x + (points[this->getStartIndex() + 1].x - points[this->getStartIndex()].x) / this->getSpeed(),
            this->getPos().y + (points[this->getStartIndex() + 1].y - points[this->getStartIndex()].y) / this->getSpeed(),
            this->getPos().z + (points[this->getStartIndex() + 1].z - points[this->getStartIndex()].z) / this->getSpeed());


        if (this->getFillRate() == this->getSpeed()) {
            this->setStartIndex(this->getStartIndex() + 1);
            this->nullifyFillRate();
        }

        modelMatrix *= transform3D::Translate(this->getPos().x, this->getPos().y, this->getPos().z);
    }
}

std::vector<unsigned int> CarEnemy::getDefaultIndicesCar()
{
    return defaultIndicesCar;
}
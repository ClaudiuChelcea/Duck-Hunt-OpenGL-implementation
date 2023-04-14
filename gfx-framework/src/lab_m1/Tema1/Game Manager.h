#ifndef __GAME_MANAGER_H
#define __GAME_MANAGER_H

#pragma once

#include <iostream>
#include "components/simple_scene.h"
#include "transform2D.h"
#include "Duck.h"

namespace GameManager
{
	class DuckManager {
	private:
		// Duck
		Duck* my_duck = NULL;
		std::pair<int, int> spawnPoint{ 0, 0 };
		std::vector<std::pair<int, int>> spawnPoints;

	public:
		// default constructor
		DuckManager() {};

		// create a duck (only one can exist at a time)
		void createDuck(std::pair<float, float> startingBodyPosition = { 0.0f, 0.0f });

		// Getters
		Duck* getDuckAlive();
		std::pair<int, int> getSpawnPoint();
		std::vector<std::pair<int, int>>& getSpawnPoints();

		// Setters
		void setSpawnPoint(std::pair<int, int> _spawnPoint = { 0, 0 });
	};

	class myMath
	{
	public:
		// Degrees
		static float degreesToRadians(float degrees) {
			return degrees * PI / 180;
		}

		static float radiansToDegrees(float radians) {
			return (180 / PI) * radians;
		}
	};

	class UI
	{
	private:
		// Ground
		Mesh* ground;

		// Sky
		Mesh* sky;

		// Lives
		Mesh* life1;
		Mesh* life2;
		Mesh* life3;

		// Bullets
		Mesh* bullet1;
		Mesh* bullet2;
		Mesh* bullet3;

		// Healthbar
		Mesh* healthBarBorder;
		Mesh* healthProgressBar;
		float progress_bar_max_val = 217.0f;

		// Tree 1
		Mesh* tree1trunk;
		Mesh* tree1crown;

		// Tree 2
		Mesh* tree2trunk;
		Mesh* tree2crown;

	public:
		UI(); // create the whole UI

		/* Getters */
		// Ground
		Mesh* getGround();
		std::string getGroundString();

		// Sky
		Mesh* getSky();
		std::string getSkyString();

		// Lives
		Mesh* getLife1();
		std::string getLife1String();
		Mesh* getLife2();
		std::string getLife2String();
		Mesh* getLife3();
		std::string getLife3String();

		// Bullets
		Mesh* getBullet1();
		std::string getBullet1String();
		Mesh* getBullet2();
		std::string getBullet2String();
		Mesh* getBullet3();
		std::string getBullet3String();

		// Healthbar
		Mesh* gethealthBarBorder();
		std::string gethealthBarBorderString();
		Mesh* gethealthProgressBar();
		Mesh** gethealthProgressBarReference();
		std::string gethealthProgressBarString();
		float getProgressBarMaxVal();

		// Trees
		Mesh* getTree1trunk();
		std::string getTree1trunkString();
		Mesh* getTree1crown();
		std::string getTree1crownString();
		Mesh* getTree2trunk();
		std::string getTree2trunkString();
		Mesh* getTree2crown();
		std::string getTree2crownString();
	};
}

#endif // __GAME_MANAGER_H



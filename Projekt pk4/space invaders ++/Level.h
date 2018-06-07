#pragma once
#include "Enemy.h"
#include "SmallEnemy.h"
#include "MediumEnemy.h"
#include "BigEnemy.h"
#include "sprite.h"
#include <fstream>

class Level
{
private:
	std::vector<Enemy*> enemies;
	int levelId;
	MySprite*target;
public:
	Level() :Level(1) {}
	Level(int levelId) :Level(NULL, levelId) {}
	Level(MySprite*target) :Level(target, 1) {}
	Level(MySprite*target, int levelId);
	~Level();

	const std::vector<Enemy*> & getenemies();
	bool checkiflevelpassed();
	void addenemy(Enemy* enemy);
	void loadlevel();
	void createenemy(std::string enemyname, Vector2u position);
	void removeenemy(int i);
	Level& operator++();
};


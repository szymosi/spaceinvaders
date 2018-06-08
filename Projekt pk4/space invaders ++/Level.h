#pragma once
#include "Enemy.h"
#include "SmallEnemy.h"
#include "MediumEnemy.h"
#include "BigEnemy.h"
#include "sprite.h"
#include <fstream>
#include <regex>
#include <string>

class Level
{
private:
	std::vector<Enemy*> enemies;
	int levelId;
	MySprite*target;
	std::regex patterndefault=std::regex("([A-Za-z]+)\ \([[:digit:]]+)\ \([[:digit:]]+)");
	std::regex patternhpdmg = std::regex("([A-Za-z]+)\ \([[:digit:]]+)\ \([[:digit:]]+)\ \([[:digit:]]+)\ \([[:digit:]]+)");
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
	void createenemy(std::string enemyname, Vector2u position,int hp, int damage);
	void removeenemy(int i);
	void nextlevel();
};

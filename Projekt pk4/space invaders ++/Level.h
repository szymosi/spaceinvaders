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

	void setLevelId(int LevelId);
	const std::vector<Enemy*> & getenemies();//returns vector of enemies not allewing changes
	bool checkiflevelpassed();//returns true if all enemies dead
	void addenemy(Enemy* enemy);//adds enemy to enemies vector
	void loadlevel();//loads level given by levelid
	void createenemy(std::string enemyname, Vector2u position);//creates enemy using its name and possition
	void createenemy(std::string enemyname, Vector2u position,int hp, int damage);//creates enemy using its name, possition, hp and damage of its bullets
	void removeenemy(int i);//removes enemy at i position
	void nextlevel();//increments levelid and loasds level
	int getlevelid();// returns current levelid
};

#include "stdafx.h"
#include "Level.h"

Level::Level(MySprite * traget, int levelId)
{
	this->target = target;
	this->levelId = levelId;
}

Level::~Level()
{
}

const std::vector<Enemy*>& Level::getenemies()
{
	return enemies;
}

bool Level::checkiflevelpassed()
{
	if (this->enemies.size()==0)
		return true;
	else
		return false;
}

void Level::addenemy(Enemy * enemy)
{
	this->enemies.push_back(enemy);
}

void Level::loadlevel()
{
	std::string enemyname;
	Vector2u position;
	std::ifstream levelfile;
	std::string filename= std::to_string(levelId) + ".lvl";
	levelfile.open(filename);
	if (levelfile.is_open())
	{
		while (!levelfile.eof())
		{
			levelfile >> enemyname;
			levelfile >> position.x;
			levelfile >> position.y;
			createenemy(enemyname, position);
		}
	}
}

void Level::createenemy(std::string enemyname, Vector2u position)
{
	if (enemyname == "SmallEnemy")
		addenemy(new SmallEnemy(position));
	else
		if (enemyname == "MediumEnemy")
			addenemy(new MediumEnemy(position));
		else
			if (enemyname == "BigEnemy")
				if(target!=NULL)
				addenemy(new BigEnemy(target,position));
			//else
				//dodac wyj¹tek
}

#include "stdafx.h"
#include "Level.h"

Level::Level(MySprite * target, int levelId)
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
//	std::string enemyname;
//	Vector2u position;
	std::smatch result;
	std::string line;
	std::ifstream levelfile;
	std::string filename= std::to_string(levelId) + ".lvl";
	levelfile.open(filename);
	if (levelfile.is_open())
	{
		while (!levelfile.eof())
		{
			getline(levelfile, line);
			if (regex_match(line, patterndefault))
			{
				regex_search(line, result, patterndefault);
				createenemy(result[1], Vector2u(stoi(result[2]), stoi(result[3])));
			}
			if (regex_match(line, patternhpdmg))
			{
				regex_search(line, result, patternhpdmg);
				createenemy(result[1], Vector2u(stoi(result[2]), stoi(result[3])), stoi(result[4]), stoi(result[5]));
			}
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

void Level::createenemy(std::string enemyname, Vector2u position, int hp, int damage)
{
	if (enemyname == "SmallEnemy")
		addenemy(new SmallEnemy(position,hp,damage));
	else
		if (enemyname == "MediumEnemy")
			addenemy(new MediumEnemy(position, hp, damage));
		else
			if (enemyname == "BigEnemy")
				if (target != NULL)
					addenemy(new BigEnemy(target, position, hp, damage));
}

void Level::removeenemy(int i)
{
	if (i < enemies.size() && i >= 0)
	{
		delete enemies[i];
		this->enemies.erase(enemies.begin() + i);
	}
}

void Level::nextlevel()
{
	this->levelId++;
	loadlevel();
}


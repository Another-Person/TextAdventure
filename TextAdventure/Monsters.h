#ifndef MONSTERS_H
#define MONSTERS_H

enum class Monsters
{
	ORC,
	GIANTSPIDER,
	TROLL
};

struct Orc
{
	int health = 20;
	int damage = 5;
};

struct GiantSpider
{
	int health = 15;
	int damage = 5;
};

struct Troll
{
	int health = 30;
	int damage = 10;
};

#endif MONSTERS_H
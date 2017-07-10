#ifndef MONSTERS_H
#define MONSTERS_H

enum class Monsters
{
	BLANKMONSTER,
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

struct GenericMobTemplate
{
	Monsters whichMonster;
	int health;
	int damage;
};

void SetcurrentMobValues(Monsters monster);

void SubtractFromcurrentMobHealth(int amount);

void AddTocurrentMobHealth(int amount);

int GetcurrentMobHealth();

int GetcurrentMobDamage();

#endif MONSTERS_H
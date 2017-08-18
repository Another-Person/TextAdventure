#include "stdafx.h"
#include <iostream>
#include "Monsters.h"

/* Block of old encapsulation code for currentMob; replaced by class.
 * Never even really used yet (never got to the point) so will probably be thown out soon.
 * Kept in case class seems to not work despite being the exact same code, just in a class.
static GenericMobTemplate currentMob;

void SetcurrentMobValues(Monsters monster)
{
	if (monster == Monsters::ORC)
	{
		Orc orc;
		currentMob.whichMonster = monster;
		currentMob.health = orc.health;
		currentMob.damage = orc.damage;
	}
	else if (monster == Monsters::GIANTSPIDER)
	{
		GiantSpider giantspider;
		currentMob.whichMonster = monster;
		currentMob.health = giantspider.health;
		currentMob.damage = giantspider.damage;
	}
	else if (monster == Monsters::TROLL)
	{
		Troll troll;
		currentMob.whichMonster = monster;
		currentMob.health = troll.health;
		currentMob.damage = troll.damage;
	}
	else
	{
		std::cout << "ERROR: Something went wrong. Debug info: MonstersSource.SetcurrentMobValues.INVALIDMONSTERPASSED" << std::endl;
		exit(1);
	}
}

void SubtractFromcurrentMobHealth(int amount)
{
	currentMob.health = currentMob.health - amount;
}

void AddTocurrentMobHealth(int amount)
{
	currentMob.health = currentMob.health + amount;
}

int GetcurrentMobHealth()
{
	return currentMob.health;
}

int GetcurrentMobDamage()
{
	return currentMob.damage;
}

Monsters GetcurrentMobwhichMonster()
{
	return currentMob.whichMonster;
}

void ClearcurrentMobValues()
{
	currentMob.whichMonster = Monsters::BLANKMONSTER;
	currentMob.health = 0;
	currentMob.damage = 0;
}
*/

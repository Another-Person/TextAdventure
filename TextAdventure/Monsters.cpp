/* Monsters.cpp
 * Last updated with 0.2.3
 * Holds code for the Monsters class and related functionality.
 */

#include "stdafx.h"
#include <iostream>
#include "Monsters.h"

CurrentMob::CurrentMob(Monsters startMonster, int startHealth, int startDamage) : whichMonster{ startMonster }, health{ startHealth }, damage{ startDamage }
{
}

void CurrentMob::setCurrentMobValues(Monsters monster) // Uses a bunch of if-else-if blocks comparing the name of the passed in monster to the pre-defined structs for each monster
{
	if (monster == Monsters::ORC)
	{
		Orc orc;
		whichMonster = monster;
		health = orc.health;
		damage = orc.damage;
	}
	else if (monster == Monsters::GIANTSPIDER)
	{
		GiantSpider giantspider;
		whichMonster = monster;
		health = giantspider.health;
		damage = giantspider.damage;
	}
	else if (monster == Monsters::TROLL)
	{
		Troll troll;
		whichMonster = monster;
		health = troll.health;
		damage = troll.damage;
	}
	else
	{
		std::cout << "ERROR: Something went wrong. Debug info: _class_CurrentMob.SetCurrentMobValues.INVALIDMONSTERPASSED" << std::endl;
		exit(1);
	}
}

void CurrentMob::clearCurrentMobValues()
{
	whichMonster = Monsters::BLANKMONSTER;
	health = -1;
	damage = -1;
}
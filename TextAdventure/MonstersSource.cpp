#include "stdafx.h"
#include <iostream>
#include "Monsters.h"

static GenericMobTemplate currentMob;

void SetcurrentMobValues(Monsters monster)
{
	if (monster == Monsters::ORC)
	{
		Orc orc;
		currentMob.health = orc.health;
		currentMob.damage = orc.damage;
	}
	else if (monster == Monsters::GIANTSPIDER)
	{
		GiantSpider giantspider;
		currentMob.health = giantspider.health;
		currentMob.damage = giantspider.damage;
	}
	else if (monster == Monsters::TROLL)
	{
		Troll troll;
		currentMob.health = troll.health;
		currentMob.damage = troll.damage;
	}
	else
	{
		std::cout << "ERROR: Something went wrong. Debug info: MonstersSource.SetcurrentMobValues.INVALIDMONSTERPASSED" << std::endl;
		exit(1);
	}
}
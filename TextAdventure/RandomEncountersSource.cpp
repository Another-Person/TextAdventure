#include "stdafx.h"
#include <random>
#include <iostream>
#include <time.h>
#include <string>
#include "RandNumGens.h"

void RandEncounterNature()
{
	int chance = RandInt(1, 3);
	if (chance == 3) 
	{
		int randomlySelectObject = RandInt(1, 4);
		if (randomlySelectObject == 1)
		{
			std::cout << "You see a small squirrel run up a tree." << std::endl;
		}
		if (randomlySelectObject == 2)
		{
			std::cout << "You notice a single flower growing in the dirt in front of you." << std::endl;
		}
		if (randomlySelectObject == 3)
		{
			std::cout << "A fox runs in the distance." << std::endl;
		}
		if (randomlySelectObject == 4)
		{
			std::cout << "There are some rather fresh pawprints in the dirt besides you." << std::endl;
		}
	}
}

int RandEncounterMonster()
{
	int encounteredMonster = 0;
	int chance = RandInt(1, 4);
	if (chance == 4) 
	{
		encounteredMonster = 1;
		int randomlySelectMonster = RandInt(1, 3);
		if (randomlySelectMonster == 1)
		{
			std::cout << "An orc appeared from a nearby cave!" << std::endl;
		}
		if (randomlySelectMonster == 2)
		{
			std::cout << "A giant spider crawled up behind you!" << std::endl;
		}
		if (randomlySelectMonster == 3)
		{
			std::cout << "A troll slowly lumbers up next to you!" << std::endl;
		}
	}
	return encounteredMonster;
}
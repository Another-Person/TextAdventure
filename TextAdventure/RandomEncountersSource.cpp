#include "stdafx.h"
#include <random>
#include <iostream>
#include <time.h>
#include <string>
#include "RandNumGens.h"
#include "PlayerVars.h"

void RandEncounterNature()
{
	int chance = RandInt(1, 3);
	if (chance == 3) 
	{
		
		int randomlySelectObject = RandInt(1, 4);
		switch (randomlySelectObject)
		{
		case 1:
			std::cout << "You see a small squirrel run up a tree." << std::endl;
			break;
		case 2:
			std::cout << "You notice a single flower growing in the dirt in front of you." << std::endl;
			break;
		case 3:
			std::cout << "A fox runs in the distance." << std::endl;
			break;
		case 4:
			std::cout << "There are some rather fresh pawprints in the dirt besides you." << std::endl;
			break;
		default:
			std::cout << "ERROR: Something went wrong. Debug info: RandomEncountersSource.RandEncounterNature.randomlySelectObject.OUTOFRANGE" << std::endl;
			exit(1);
		}
	}
}

bool RandEncounterMonster()
{
	bool encounteredMonster = false;
	int chance = RandInt(1, 4);
	if (chance == 4) 
	{
		encounteredMonster = true;
		int randomlySelectMonster = RandInt(1, 3);
		switch (randomlySelectMonster)
		{
		case 1:
			std::cout << "An orc appeared from a nearby cave!" << std::endl;
			SetWhatFighting(Monsters::ORC);
			break;
		case 2:
			std::cout << "A giant spider crawled up behind you!" << std::endl;
			SetWhatFighting(Monsters::GIANTSPIDER);
			break;
		case 3:
			std::cout << "A troll slowly lumbers up next to you!" << std::endl;
			SetWhatFighting(Monsters::TROLL);
			break;
		default:
			std::cout << "ERROR: Something went wrong. Debug info: RandomEncountersSource.RandEncounterMonster.randomlySelectMonster.OUTOFRANGE" << std::endl;
			exit(1);
		}
	}
	return encounteredMonster;
}
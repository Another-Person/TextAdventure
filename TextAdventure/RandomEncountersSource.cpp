/* RandomEncountersSource.cpp
 * Last updated with 0.2.3
 * Holds functions that make the player randomly encounter details of nature and monsters to fight.
 */


#include "stdafx.h"
// #include <random> Is this necesarry here?
#include <iostream>
// #include <time.h> Is this necesarry here?
#include <string>
#include "RandNumGens.h"
#include "Player.h"

extern CurrentMob currentMob;
extern Player thePlayer;

void RandEncounterNature()  // Has random chance to display a message telling the player they have encountered some natural thing.
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
			exit(1);  // TODO: Find a better solution than exit()
		}
	}
}

bool RandEncounterMonster()  // Randomly makes the player run into various monsters and sets appropriate values for other parts of the game.
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
			thePlayer.SetWhatIsFighting(Monsters::ORC);
			currentMob.setCurrentMobValues(Monsters::ORC);
			break;
		case 2:
			std::cout << "A giant spider crawled up behind you!" << std::endl;
			thePlayer.SetWhatIsFighting(Monsters::GIANTSPIDER);
			currentMob.setCurrentMobValues(Monsters::GIANTSPIDER);
			break;
		case 3:
			std::cout << "A troll slowly lumbers up next to you!" << std::endl;
			thePlayer.SetWhatIsFighting(Monsters::TROLL);
			currentMob.setCurrentMobValues(Monsters::TROLL);
			break;
		default:
			std::cout << "ERROR: Something went wrong. Debug info: RandomEncountersSource.RandEncounterMonster.randomlySelectMonster.OUTOFRANGE" << std::endl;
			exit(1);  // TODO: Find a better solution than exit()
		}
	}
	return encounteredMonster;
}
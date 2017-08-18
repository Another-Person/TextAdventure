#include "stdafx.h"
#include <iostream>
#include <string>
#include "RandNumGens.h"
#include "PlayerVars.h"
#include "Monsters.h"

extern CurrentMob currentMob;
extern Player thePlayer;

void CheckHealthCommand()
{
	std::cout << "You have " << thePlayer.GetPlayerHealth() << " health remaining.\n";
}

void CheckInvCommand()
{
	std::cout << "You have the following items in your inventory: \n"; 
	thePlayer.PrintPlayerInvStrings();
	std::cout << std::endl;
}

PlayerCheckCommandArgs CheckArgStringEnumConvert(std::string input)
{
	if (input == "health")
		return PlayerCheckCommandArgs::HEALTH;
	else if (input == "inv")
		return PlayerCheckCommandArgs::INV;
	else
	{
		// No return value here; blank return leads to default path for invalid input handling
	}
}


void CheckCommand(std::string input)
{
	PlayerCheckCommandArgs argument = CheckArgStringEnumConvert(input);
	switch (argument)
	{
	case PlayerCheckCommandArgs::HEALTH:
		CheckHealthCommand();
		break;
	case PlayerCheckCommandArgs::INV:
		CheckInvCommand();
		break;
	default:
		std::cout << "Sorry, this argument isn't valid. \n";
		break;
	}
}

void FightCommand(bool isFighting)
{
	if (isFighting == true)
	{
		if ( thePlayer.GetwhatFighting() != Monsters::BLANKMONSTER)
		{
			
		}
		else
		{
			std::cout << "ERROR: Something went wrong. Debug info: PlayerSource.FightCommand.INVALIDMONSTERBATTLE" << std::endl;
			exit(1);
		}
		thePlayer.SetFighting(false); // Maybe move somewhere else (end of first if branch?)
	}
	else
	{
		std::cout << "You prepare yourself to battle, only to realize that you have nothing to fight.\n";
	}
}
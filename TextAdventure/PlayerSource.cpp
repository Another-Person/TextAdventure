#include "stdafx.h"
#include <iostream>
#include <string>
#include "RandNumGens.h"
#include "PlayerVars.h"

void CheckHealthCommand()
{
	std::cout << "You have " << GetPlayerHealth() << " health remaining." << std::endl;
}

void CheckInvCommand()
{
	std::cout << "You have the following items in your inventory: " << std::endl; 
	PrintPlayerInvStrings();
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
		std::cout << "Sorry, this argument isn't valid." << std::endl;
		break;
	}
}

void FightCommand(bool isFighting)
{
	if (isFighting == true)
	{
		// placeholder
		SetFighting(false);
	}
	else
	{
		std::cout << "You prepare yourself to battle, only to realize that you have nothing to fight." << std::endl;
	}
}
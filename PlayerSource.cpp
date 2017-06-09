#include "stdafx.h"
#include <iostream>
#include <string>
#include "RandNumGens.h"
#include "PlayerVarsDefine.h"

extern PlayerVars Player;

void CheckHealthCommand()
{
	std::cout << "You have " << Player.health << " health remaining." << std::endl;
}

void CheckInvCommand()
{
	std::cout << "You have nothing in your inventory." << std::endl;
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
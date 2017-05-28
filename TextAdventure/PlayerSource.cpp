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

void CheckCommand(std::string input)
{
	
	if (input == "health")
	{
		CheckHealthCommand();
	}
	if (input == "inv")
	{
		CheckInvCommand();
	}
	// This block doesn't work yet; I havent made the input the enum so it just uses a test variable so it compiles correctly
	PlayerCheckCommandArgs testing = PlayerCheckCommandArgs::HEALTH;
	switch (testing)
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
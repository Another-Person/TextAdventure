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
}
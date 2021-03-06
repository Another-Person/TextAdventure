#include "stdafx.h"
#include <random>
#include <iostream>
#include <time.h>
#include <string>
#include "RandNumGens.h"
#include "RandomEncounters.h"
#include "PlayerVarsDefine.h"
#include "PlayerFuncDefine.h"

extern PlayerVars Player{ 20 };

enum class MoveCommandArgs
{
	NORTH,
	EAST,
	SOUTH,
	WEST
};

enum class Commands
{
	MOVE,
	HELP,
	CHECK,
	EXIT
};

void GenerateLand()
{
	int randomLandTypeSelection = RandInt(1,4);
	switch (randomLandTypeSelection)
	{
	case 1:
	{
		std::cout << "You are in a forest." << std::endl;
		RandEncounterNature();
		int encounteredMonster = RandEncounterMonster();
		break;
	}
	case 2:
	{
		std::cout << "You are in a plain." << std::endl;
		RandEncounterNature();
		int encounteredMonster = RandEncounterMonster();
		break;
	}
	case 3:
	{
		std::cout << "You are in a desert." << std::endl;
		RandEncounterNature();
		int encounteredMonster = RandEncounterMonster();
		break;
	}
	case 4:
	{
		std::cout << "You are in a tundra." << std::endl;
		RandEncounterNature();
		int encounteredMonster = RandEncounterMonster();
		break;
	}
	default:
		std::cout << "ERROR: Something went wrong. Debug info: TextAdventure.GenerateLand.randomLandTypeSelection.OUTOFRANGE" << std::endl;
		exit(1);
	}
}

std::string GetCommand()
{
	std::cout << "Please enter a command: ";
	std::string tempString;
	std::cin >> tempString;
	return tempString;
}

std::string GetCommandArgument()
{
	std::string tempString;
	std::cin >> tempString;
	return tempString;
}

MoveCommandArgs MoveArgsStringEnumConvert(std::string input)
{
	if (input == "north")
		return MoveCommandArgs::NORTH;
	else if (input == "east")
		return MoveCommandArgs::EAST;
	else if (input == "west")
		return MoveCommandArgs::WEST;
	else if (input == "south")
		return MoveCommandArgs::SOUTH;
	else
	{
		// No return here; blank return leads to default path for invalid input handling
	}
}

Commands CommandsStringEnumConvert(std::string input)
{
	if (input == "check")
		return Commands::CHECK;
	else if (input == "exit")
		return Commands::EXIT;
	else if (input == "help")
		return Commands::HELP;
	else if (input == "move")
		return Commands::MOVE;
	else
	{
		// No return here; blank return leads to default path for invalid input handling
	}
}

void MoveCommand(std::string direction)
{
	MoveCommandArgs argument = MoveArgsStringEnumConvert(direction);
	switch (argument)
	{
	case MoveCommandArgs::NORTH:
		std::cout << "You moved north." << std::endl;
		GenerateLand();
		break;
	case MoveCommandArgs::EAST:
		std::cout << "You moved east." << std::endl;
		GenerateLand();
		break;
	case MoveCommandArgs::SOUTH:
		std::cout << "You moved south." << std::endl;
		GenerateLand();
		break;
	case MoveCommandArgs::WEST:
		std::cout << "You moved west." << std::endl;
		GenerateLand();
		break;
	default:
		std::cout << "Sorry, invalid direction. Please use compass directions (north, east, south, west)." << std::endl;
		break;
	}
}

void ParseCommands(std::string commandInput)
{
	Commands command = CommandsStringEnumConvert(commandInput);
	switch (command)
	{
	case Commands::MOVE:
		MoveCommand(GetCommandArgument());
		break;
	case Commands::HELP:
		std::cout << "Enter a command in the format <command> <argument>." << std::endl;
		std::cout << "Example commands: move, help, exit " << std::endl;
		break;
	case Commands::CHECK:
		CheckCommand(GetCommandArgument());
		break;
	case Commands::EXIT:
		exit(0);
	default:
		std::cout << "Sorry, invalid command. Try typing \"Help\" if you need some assistance." << std::endl;
		break;
	}
}

int main()
{
	PlayerVars Player{ 20 };
	while (true)
	{
		std::string command = GetCommand();
		ParseCommands(command);
	}
    return 0;
}
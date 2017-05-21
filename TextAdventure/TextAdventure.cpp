#include "stdafx.h"
#include <random>
#include <iostream>
#include <time.h>
#include <string>

int RandInt(int minGen, int maxGen)
{
	std::default_random_engine generator(time(NULL));
	std::uniform_int_distribution<int> distribution(minGen, maxGen);
	int numberGenerated = distribution(generator);
	return numberGenerated;
}

void GenerateLand()
{
	int randomLandTypeSelection = RandInt(1,4);
	if (randomLandTypeSelection == 1)
	{
		std::cout << "You are in a forest." << std::endl;
	}
	if (randomLandTypeSelection == 2)
	{
		std::cout << "You are in a plain." << std::endl;
	}
	if (randomLandTypeSelection == 3)
	{
		std::cout << "You are in a desert." << std::endl;
	}
	if (randomLandTypeSelection == 4)
	{
		std::cout << "You are in a tundra." << std::endl;
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

void MoveCommand(std::string direction)
{
	if (direction == "north")
	{
		std::cout << "You moved north." << std::endl;
		GenerateLand();
	}
	if (direction == "east")
	{
		std::cout << "You moved east." << std::endl;
		GenerateLand();
	}
	if (direction == "south")
	{
		std::cout << "You moved south." << std::endl;
		GenerateLand();
	}
	if (direction == "west")
	{
		std::cout << "You moved west." << std::endl;
		GenerateLand();
	}
}

void ParseCommands(std::string commandInput)
{
	if (commandInput == "help")
	{
		std::cout << "Enter a command in the format <command> <argument>." << std::endl;
		std::cout << "Example commands: Move, Help " << std::endl;
	}
	if (commandInput == "move")
	{
		MoveCommand(GetCommandArgument());
	}
	if (commandInput == "Help")
	{
		std::cout << "Enter a command in the format <command> <argument>." << std::endl;
		std::cout << "Example commands: Move, Help " << std::endl;
	}
	if (commandInput == "Move")
	{
		MoveCommand(GetCommandArgument());
	}
	if (commandInput == "exit")
	{
		exit(0);
	}
	if (commandInput == "Exit")
	{
		exit(0);
	}
/*	else
	{
		std::cout << "Sorry, invalid command. Try typing \"Help\" if you need some assistance." << std::endl;
	} */
}

int main()
{
	while (true)
	{
		std::string command = GetCommand();
		ParseCommands(command);
	}
    return 0;
}

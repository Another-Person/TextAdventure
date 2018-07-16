/* Text Adventure by Joey Sachtleben
 * Version 0.2.3
 * 
 * A small text adventure game. There is no real point, just go around exploring and fighting things. Still a major work in progress.
 *
 */

/* TextAdventure.cpp
 * Last edited with 0.2.2
 * Holds the core of the game, including the core instances of the current mob (subject to change when the Map Update is finished) and the Player, the command parser, several key functions and enum's, and the main run loop.
 */

#include "stdafx.h"
#include <random>
#include <iostream>
#include <time.h>
#include <string>
#include "RandNumGens.h"
#include "RandomEncounters.h"
#include "PlayerVars.h"
#include "PlayerFuncDefine.h"

CurrentMob currentMob;   // Global instance of the currentMob class
Player thePlayer;        // Global instance of the Player class

enum class MoveCommandArgs  // Directions used by the Move command
{
	NORTH,
	EAST,
	SOUTH,
	WEST
};

enum class Commands  // Enum of all commands
{
	MOVE,
	HELP,
	CHECK,
	FIGHT,
	EXIT
};

void GenerateLand()  // Determine what type of eviroment the player has moved into
{
	int randomLandTypeSelection = RandInt(1,4);
	switch (randomLandTypeSelection)  // Use random integer from above to determine the eviroment
	{
	case 1:  // Forest eviroment
	{
		std::cout << "You are in a forest.\n";
		RandEncounterNature();
		thePlayer.SetFighting(RandEncounterMonster());
		break;
	}
	case 2:  // Plains eviroment
	{
		std::cout << "You are in a plain.\n";
		RandEncounterNature();
		thePlayer.SetFighting(RandEncounterMonster());
		break;
	}
	case 3:  // Desert eviroment
	{
		std::cout << "You are in a desert.\n";
		RandEncounterNature();
		thePlayer.SetFighting(RandEncounterMonster());
		break;
	}
	case 4:  // Tundra eviroment
	{
		std::cout << "You are in a tundra. \n";
		RandEncounterNature();
		thePlayer.SetFighting(RandEncounterMonster());
		break;
	}
	default:  // Error and exit if the integer does not correspond to one of the cases
		std::cout << "ERROR: Something went wrong. Debug info: TextAdventure.GenerateLand.randomLandTypeSelection.OUTOFRANGE" << std::endl;
		exit(1);
	}
}

std::string GetCommand()  // Asks the player for a command and then returns it
{
	std::cout << "Please enter a command: ";
	std::string tempString;
	std::cin >> tempString;
	return tempString;
}

std::string GetCommandArgument()  // If the command entered has any arguments, get them from the console and returns them
{
	std::string tempString;
	std::cin >> tempString;
	return tempString;
}

MoveCommandArgs MoveArgsStringEnumConvert(std::string input)  // Convert string arguments for the move command to the Enum types
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

Commands CommandsStringEnumConvert(std::string input)  // Convert input strings into Enum types for the commands
{
	if (input == "check")
		return Commands::CHECK;
	else if (input == "exit")
		return Commands::EXIT;
	else if (input == "help")
		return Commands::HELP;
	else if (input == "move")
		return Commands::MOVE;
	else if (input == "fight")
		return Commands::FIGHT;
	else
	{
		// No return here; blank return leads to default path for invalid input handling
	}
}

void MoveCommand(std::string direction)  // Implements the Move command
{
	MoveCommandArgs argument = MoveArgsStringEnumConvert(direction);
	switch (argument)
	{
	case MoveCommandArgs::NORTH:
		std::cout << "You moved north.\n";
		GenerateLand();
		break;
	case MoveCommandArgs::EAST:
		std::cout << "You moved east.\n";
		GenerateLand();
		break;
	case MoveCommandArgs::SOUTH:
		std::cout << "You moved south.\n";
		GenerateLand();
		break;
	case MoveCommandArgs::WEST:
		std::cout << "You moved west. \n";
		GenerateLand();
		break;
	default:
		std::cout << "Sorry, invalid direction. Please use compass directions (north, east, south, west).\n";
		break;
	}
}

bool ParseCommands(std::string commandInput)  // Parses the given command and begins execution of it
{
	bool keepRunning = true;
	Commands command = CommandsStringEnumConvert(commandInput);
	switch (command)
	{
	case Commands::MOVE:
		MoveCommand(GetCommandArgument());
		break;
	case Commands::HELP:
		std::cout << "Enter a command in the format <command> <argument>.\n";
		std::cout << "Example commands: move, help, exit \n";
		break;
	case Commands::CHECK:
		CheckCommand(GetCommandArgument());
		break;
	case Commands::FIGHT:
		FightCommand(thePlayer.GetisFighting());
		break;
	case Commands::EXIT:
		keepRunning = false;
		break;
	default:
		std::cout << "Sorry, invalid command. Try typing \"Help\" if you need some assistance.\n";
		break;
	}
	
	return keepRunning;
}

int main()
{
	while (true)  // I can't think of a simpler and/or better way to make this repeat itself, so it's always true
	{
		bool continueRunning; // Stores whether to continue running or not
		std::string command = GetCommand();
		continueRunning = ParseCommands(command);

		if (continueRunning == true)
		{
			// do nothing; just continue running the loop
		}
		else if (continueRunning == false)
		{
			break;  // exits the infite loop
		}

		if (thePlayer.GetPlayerHealth() < 20)  // Player slowly heals over time
		{
			thePlayer.AddToPlayerHealth(5);
		}
		else if (thePlayer.GetPlayerHealth() < 30)
		{
			if (RandInt(1, 2) == 2)  // Once the player has 20+ health, slow down their regeneration by adding in a little random chance
			{
				thePlayer.AddToPlayerHealth(5);
			}
		}

	}
    return 0;
}
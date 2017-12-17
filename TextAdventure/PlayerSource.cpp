/* PlayerSource.cpp
 * Last updated with 0.2.2
 * Holds code for the Check and Fight commands along with support code
 */

#include "stdafx.h"
#include <iostream>
#include <string>
#include "RandNumGens.h"
#include "PlayerVars.h"
#include "Monsters.h"

extern CurrentMob currentMob;
extern Player thePlayer;

void CheckHealthCommand()  // Prints out a statement indicating how much health the player has left.
{
	std::cout << "You have " << thePlayer.GetPlayerHealth() << " health remaining.\n";
}

void CheckInvCommand()  // Prins out a statement and a list of the player's inventory
{
	std::cout << "You have the following items in your inventory: \n"; 
	thePlayer.PrintPlayerInvStrings();
	std::cout << std::endl;
}

PlayerCheckCommandArgs CheckArgStringEnumConvert(std::string input)  // Converts user-inputted strings to struct values for the Check command for comparision
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


void CheckCommand(std::string input) // Chooses between branches of the Check command to determine which one to run
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

void FightCommand(bool isFighting)  // Implements the Fight command for fighting monsters
{
	if (isFighting == true)
	{
		if ( thePlayer.GetwhatFighting() != Monsters::BLANKMONSTER)
		{
			currentMob.subtractFromCurrentMobHealth(thePlayer.Getdamage());
			if (currentMob.getCurrentMobHealth() > 5)
			{
				thePlayer.SubtractFromPlayerHealth(currentMob.getCurrentMobDamage());
				std::cout << "You sucessfully strike the monster, but he returns your strike with a hard hit. \n";
				if (thePlayer.GetPlayerHealth() < 1)
				{
					std::cout << "The monster's blow knocks you out, and you do not awaken." << std::endl;
					exit(0); // TODO: FInd a better solution than exit()
				}
			}
			else if (1 <= currentMob.getCurrentMobHealth())
			{
				if (currentMob.getCurrentMobHealth() <= 5)
					std::cout << "You deliver a crushing blow to the monster. \n";
			}
			else if (currentMob.getCurrentMobHealth() <= 0)
			{
				std::cout << "With one more strike, you end the monster's life.\n";
				currentMob.clearCurrentMobValues();
				thePlayer.SetFighting(false);
				thePlayer.SetwhatFighting(Monsters::BLANKMONSTER);
			}
		}
		else
		{
			std::cout << "ERROR: Something went wrong. Debug info: PlayerSource.FightCommand.INVALIDMONSTERBATTLE" << std::endl;
			exit(1); // TODO: find a better solution than exit()
		}
	}
	else
	{
		std::cout << "You prepare yourself to battle, only to realize that you have nothing to fight.\n";
	}
}
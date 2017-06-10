#include "stdafx.h"
#include "PlayerVars.h"
#include <iostream>
#include <string>

static PlayerVars Player{ 20 };

int GetPlayerHealth()
{
	return Player.health;
}

// Encapsulation functions for the global variable
void AddToPlayerHealth(int amount)
{
	Player.health = Player.health + amount;
}

void SubtractFromPlayerHealth(int amount)
{
	Player.health = Player.health - amount;
}

void PrintPlayerInvIDs()
{
	for (int invSlot = 0; invSlot < Player.invObjects.size(); ++invSlot)
		std::cout << "Slot " << invSlot+1 << ": " << Player.invObjects.at(invSlot) << std::endl;
}

std::string InvObjIDToString(int objID)
{
	switch (objID)
	{
		case 0:
			return "Nothing";
			break;
		default:
			std::cout << "ERROR: Something went wrong. Debug info: PlayerVarSource.InvObjIDToString.objID.INVALIDOBJID" << std::endl;
			exit(1);
	}
}

void PrintPlayerInvStrings()
{
	for (int invSlot = 0; invSlot < Player.invObjects.size(); ++invSlot)
		std::cout << "Slot " << invSlot + 1 << ": " << InvObjIDToString(Player.invObjects.at(invSlot)) << std::endl;
}
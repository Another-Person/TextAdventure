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
		case 1:
			return "Sword";
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

void AddItemToInv(int objID)
{
	bool invIsFull = false;
	if (invIsFull == false)
	{
		for (int invSlot = 0; invSlot < Player.invObjects.size(); ++invSlot)
			if (Player.invObjects.at(invSlot) == 0)
			{
				Player.invObjects.at(invSlot) = objID;
				break;
			}
			else
			{
				invIsFull = true;
			}
	}
	else
	{
		if (Player.invObjects.at(Player.invObjects.size()) != 0)
		{
			std::cout << "Sorry, you don't have an open inventory slot for this." << std::endl;
			std::cout << "Please enter a slot to replace this item: ";
			int slot;
			std::cin >> slot;
			std::cout << std::endl;
			Player.invObjects.at(slot) = objID;
		}
	}
}

void SetFighting(bool isFighting)
{
	Player.isFighting = isFighting;
}

bool GetIsFighting()
{
	return Player.isFighting;
}

Monsters GetWhatFighting()
{
	return Player.whatFighting;
}

void SetWhatFighting(Monsters whatFighting)
{
	Player.whatFighting = whatFighting;
}
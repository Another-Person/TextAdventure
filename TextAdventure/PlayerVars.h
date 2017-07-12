#ifndef PLAYERVARSDEFINE_H
#define PLAYERVARSDEFINE_H
#include <array>
#include <vector>
#include "Monsters.h"
#include "PlayerInvItems.h"

enum class PlayerCheckCommandArgs
{
	HEALTH,
	INV
};

class Player
{
private:
	int health;                             // Default to 20 health for player
	std::array<int, 10> invObjects = { };   // Player has 10 empty slots by default | What if we want to give him the ability to carry more later in the game? Perhaps make this a dynamically allocated array?
	bool isFighting;                        // Player doesn't start off fighting something
	Monsters whatFighting;                  // Initialized with the BlankMonster placeholder; if isFighting is true but BlankMonster is here then something is wrong
	std::vector<int> inventory;             // Makes dynamicially sized array player inv, primarily for future use

public:
	// Constructor for priv variables
	Player(int startHealth = 20, bool fighting = false, Monsters startFighting = Monsters::BLANKMONSTER)
	{
		health = startHealth;
		isFighting = fighting;
		whatFighting = startFighting;
	}

	int GetPlayerHealth() // Returns current amount of health player has
	{
		return health;
	}

	void AddToPlayerHealth(int amount)
	{
		health = health + amount;
	}

	void SubtractFromPlayerHealth(int amount)
	{
		health = health - amount;
	}

	std::string invObjIDToString(int objID)
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
			std::cout << "ERROR: Something went wrong. Debug info: _class_Player.public.invObjIDToString.objID.INVALIDOBJID" << std::endl;
			exit(1);
		}
	}

	void PrintPlayerInvStrings()
	{
		for (int invSlot = 0; invSlot < invObjects.size(); ++invSlot)
			std::cout << "Slot " << invSlot + 1 << ": " << invObjIDToString(invObjects.at(invSlot)) << std::endl;
	}
	
	void AddItemToInv(int objID)
	{
		bool invIsFull;
		for (int invSlot = 0; invSlot < invObjects.size(); ++invSlot)
			if (invObjects.at(invSlot) == 0)
			{
				invIsFull = false;
				break;
			}
			else
			{
				invIsFull = true;
			}
		if (invIsFull == false)
		{
			for (int invSlot = 0; invSlot < invObjects.size(); ++invSlot)
				if (invObjects.at(invSlot) == 0)
					invObjects.at(invSlot) = objID;
		}
		else
		{
			std::cout << "Sorry, you don't have an open inventory slot for this.\n";
			std::cout << "Please enter a slot to replace this item. The item in that slot will be destroyed.\n";
			std::cout << "Slot: ";
			int slot;
			std::cin >> slot;
			std::cout << "\n";
			invObjects.at(slot) = objID;
		}
	}

	void SetFighting(bool fightingState)
	{
		isFighting = fightingState;
	}

	bool GetisFighting()
	{
		return isFighting;
	}

	Monsters GetwhatFighting()
	{
		return whatFighting;
	}

	void SetwhatFighting(Monsters fighting)
	{
		whatFighting = fighting;
	}
};

#endif PLAYERSVARSDEFINE_H

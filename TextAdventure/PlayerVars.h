#ifndef PLAYERVARSDEFINE_H
#define PLAYERVARSDEFINE_H
#include <array>
#include <vector>
#include "Monsters.h"
#include "PlayerInvItems.h"

enum class PlayerCheckCommandArgs  // Enums for different arguments for the Check command
{
	HEALTH,
	INV
};

class Player
{
private:
	int health;                             // Holds health of the player
	std::array<int, 10> invObjects = { };   // Player has 10 empty slots by default | What if we want to give him the ability to carry more later in the game? Perhaps make this a dynamically allocated array?
	bool isFighting;                        // Player doesn't start off fighting something
	Monsters whatFighting;                  // Initialized with the BlankMonster placeholder; if isFighting is true but BlankMonster is here then something is wrong
	std::vector<ItemList> inventory; // Makes dynamicially sized array player inv, primarily for future use
	int damage;                             // Holds how much damage the player can do

public:
	// Constructor for priv variables
	Player(int startHealth = 30, bool fighting = false, Monsters startFighting = Monsters::BLANKMONSTER, int startDamage = 10): health { startHealth }, isFighting { fighting }, whatFighting { startFighting }, damage { startDamage }
	{
		inventory = { ItemList::GENERIC_HAND, ItemList::GENERIC_HAND, ItemList::GENERIC_HAND, ItemList::GENERIC_HAND, ItemList::GENERIC_HAND, ItemList::GENERIC_HAND, ItemList::GENERIC_HAND, ItemList::GENERIC_HAND, ItemList::GENERIC_HAND, ItemList::GENERIC_HAND };
	}

	int GetPlayerHealth()  // Returns current amount of health player has.
	{
		return health;
	}

	void AddToPlayerHealth(int amount)  // Adds a given amount of health to the player.
	{
		health = health + amount;
	}

	void SubtractFromPlayerHealth(int amount)  // Subtracts a given amount of health from the player.
	{
		health = health - amount;
	}

	std::string invObjIDToString(int objID)  // Converts the raw int objID's stored in the player inv into text strings.
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

	void PrintPlayerInvStrings()  // Prints out the player inventory as a list of text strings.
	{
		for (int invSlot = 0; invSlot < invObjects.size(); ++invSlot)
			std::cout << "Slot " << invSlot + 1 << ": " << invObjIDToString(invObjects.at(invSlot)) << std::endl;
	}
	
	void AddItemToInv(int objID)  // Adds an item to the player's inventory in the first open slot. If none is open, prompts the player to choose a slot to replace with the new item. | TODO: 1. List what is in the chosen slot and confirm choice 2. Add an option to not replace any slot if full
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

	void SetFighting(bool fightingState)  // Sets the isFighting variable to the given state.
	{
		isFighting = fightingState;
	}

	bool GetisFighting()  // Returns the current state of isFighting.
	{
		return isFighting;
	}

	Monsters GetwhatFighting()  // Returns the current value of whatFighting.
	{
		return whatFighting;
	}

	void SetwhatFighting(Monsters fighting)  // Sets the whatFighting variable to a given value.
	{
		whatFighting = fighting;
	}

	int Getdamage()  // Returns the value of damage.
	{
		return damage;
	}

	void AddTodamage(int amount)  // Adds the given amount to damage
	{
		damage = damage + amount;
	}

	void SubtractFromdamage(int amount) // Subtracts the given amount from damage
	{
		damage = damage - amount;
	}

};

#endif PLAYERSVARSDEFINE_H

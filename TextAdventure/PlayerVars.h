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
	std::vector<ItemList> inventory;        // Makes dynamicially sized array player inv, primarily for future use
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

	std::string invObjIDToString(int objID)  // Converts the raw int objID's stored in the player inv into text strings.  | DEPRECIATED: This function is depreciated in favor of the ItemsToString function as part of a redo of the inventory system.
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
		for (int invSlot = 0; invSlot < inventory.size(); ++invSlot)
			std::cout << "Slot " << invSlot + 1 << ": " << ItemsToStrings(inventory.at(invSlot)) << std::endl;
	}

	void ReplaceItemInInv(ItemList item)  // Replaces an item currently in a player's inventory with a new one.
	{
		std::cout << "Do you want to replace another slot's contents with this " << ItemsToStrings(item) << "?\n";  // Asks the player if they want to replace something in their inventory with the new item
		std::cout << "Y/N: ";
		std::string responce;
		std::cin >> responce;
		if (responce == "Y")  // Takes branch for if they do
		{
			std::cout << "Please enter a slot to replace it's contents with this.\n";  // Asks player for slot to replace
			std::cout << "Slot: ";
			int slot;
			std::cin >> slot;
			std::cout << "Are you sure you want to replace " << ItemsToStrings(inventory.at(slot)) << " with " << ItemsToStrings(item) << "?/n";   // Confirms that player entered the correct slot number
			std::cout << "Y/N: ";
			std::string responce2;
			std::cin >> responce2;
			std::cout << "\n";
			if (responce2 == "Y")  // If they did, replace item
			{
				inventory.at(slot) = item;
				std::cout << "You dropped the previous item to replace it with a " << ItemsToStrings(inventory.at(slot)) << ".\n";
			}
			else if (responce2 == "N")  // If they didn't, go though the whole process again ( I didn't want to split this into yet another function at every question point)
			{
				ReplaceItemInInv(item);
			}
			else  // If they gave an invalid answer, tell them this and try again
			{
				std::cout << "Please respond with either Y for yes or N for no.\n";
				ReplaceItemInInv(item);
			}
		}
		else if (responce == "N") // Takes branch for if they player doesn't want to replace something
		{
			std::cout << "You put back down the " << ItemsToStrings(item) << ".\n";
		}
		else  // If they gave in invalid answer, tell them this and try again
		{
			std::cout << "Please respond with either Y for yes or N for no.\n";
			ReplaceItemInInv(item);

		}
	}

	void AddItemToInv(ItemList item)  // Adds an item to the players inventory.
	{
		bool invIsFull;
		for (int invSlot = 0; invSlot < inventory.size(); ++invSlot)  // Search through players inventory to determine if it's full
			if (inventory.at(invSlot) == ItemList::GENERIC_HAND)  // GENERIC_HAND is used as the placeholder value
			{
				invIsFull = false;
			}
			else
			{
				invIsFull = true;
			}
		if (invIsFull == false)  // Runs to open slot and places new item in it
		{
			for (int invSlot = 0; invSlot < inventory.size(); ++invSlot)
				if (inventory.at(invSlot) == ItemList::GENERIC_HAND)
				{
					inventory.at(invSlot) = item;
					std::cout << "You added the " << ItemsToStrings(item) << " to your inventory.\n";
				}
		}
		else  // If the player's inventory is full, then tell them this and run the ReplaceItemInInv funtion (see above)
		{
			std::cout << "Sorry, you do not have an open inventory slot for this.\n";
			ReplaceItemInInv(item);
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

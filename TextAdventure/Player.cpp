/* PlayerSource.cpp
 * Last updated with 0.2.3
 * Provides the Player class functionality and other code for the player.
 */

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Player.h"
#include "Items.h"
#include "Monsters.h"
#include "Map.h"

Player::Player(CoordPoint startPosition, double startHealth, double startDamage, bool fighting, Monsters startFighting) : position{ startPosition }, health{ startHealth }, damage{ startDamage }, isFighting{ fighting }, whatIsFighting{ startFighting }
{
	inventory = { ItemList::GENERIC_HAND, ItemList::GENERIC_HAND, ItemList::GENERIC_HAND, ItemList::GENERIC_HAND, ItemList::GENERIC_HAND, ItemList::GENERIC_HAND, ItemList::GENERIC_HAND, ItemList::GENERIC_HAND, ItemList::GENERIC_HAND, ItemList::GENERIC_HAND };
}

void Player::AddToPlayerHealth(double amount) { health = health + amount; }

void Player::SubtractFromPlayerHealth(double amount) { health = health - amount; }

void Player::AddToPlayerDamage(double amount) {	damage = damage + amount; }

void Player::SubtractFromPlayerDamage(double amount) {	damage = damage - amount; }

void Player::SetIsFighting(bool fightingState) { isFighting = fightingState; }

void Player::SetWhatIsFighting(Monsters monster) { whatIsFighting = monster; }

void Player::UpdatePlayerStats(ItemList item, ItemEvents event)
{
	if (event == ItemEvents::PICKED_UP)
	{
		AddToPlayerDamage(GetWeaponsDamage(item));
	}
	else if (event == ItemEvents::DROPPED)
	{
		SubtractFromPlayerDamage(GetWeaponsDamage(item));
	}
	else if (event == ItemEvents::USED)
	{
		// No items can actually be 'used' right now, so as such there is nothing here
		// Just prep for future updates 
	}
}

void Player::PrintPlayerInvStrings()
{
	for (int invSlot = 0; invSlot < inventory.size(); ++invSlot)
		std::cout << "Slot " << invSlot + 1 << ": " << ItemsToStrings(inventory.at(invSlot)) << std::endl;
}

void Player::ReplaceItemInInv(ItemList item)
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
			UpdatePlayerStats(inventory.at(slot), ItemEvents::DROPPED);
			inventory.at(slot) = item;
			std::cout << "You dropped the previous item to replace it with a " << ItemsToStrings(inventory.at(slot)) << ".\n";
			UpdatePlayerStats(item, ItemEvents::PICKED_UP);
		}
		else if (responce2 == "N")  // If they didn't, go though the whole process again (I didn't want to split this into yet another function at every question point)
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

void Player::AddItemToInv(ItemList item)
{
	bool invIsFull = false;
	for (int invSlot = 0; invSlot < inventory.size(); ++invSlot)  // Search through players inventory to determine if it's full
		if (inventory.at(invSlot) == ItemList::GENERIC_HAND)  // GENERIC_HAND is used as the empty value
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
				UpdatePlayerStats(item, ItemEvents::PICKED_UP);
			}
	}
	else  // If the player's inventory is full, then tell them this and run the ReplaceItemInInv funtion (see above)
	{
		std::cout << "Sorry, you do not have an open inventory slot for this.\n";
		ReplaceItemInInv(item);
	}
}

void Player::RemoveItemFromInv(int slot)
{
	UpdatePlayerStats(inventory.at(slot), ItemEvents::DROPPED);
	inventory.at(slot) = ItemList::GENERIC_HAND;
	UpdatePlayerStats(inventory.at(slot), ItemEvents::PICKED_UP);
}

void Player::PlayerDropItemFromInv()
{
	int slot;
	std::cout << "What item would you like to drop?\n"; // Asks the player what slot to remove the item from
	std::cout << "Slot #: ";
	std::cin >> slot;
	std::cout << "\n";
	std::cout << "Are you sure you want to drop this " << ItemsToStrings(inventory.at(slot)) << " from your inventory?/n"; // Confirms they would like to remove this item
	std::string responce;
	std::cout << "Y/N : ";
	std::cin >> responce;
	std::cout << "/n";
	if (responce == "Y") // If yes removes the player's item
	{
		RemoveItemFromInv(slot);
	}
	else if (responce == "N") // If no, does nothing (returns player to normal command prompt)
	{

	}
	else // If invalid responce (not Y or N), tells them this and asks again
	{
		std::cout << "Please respond with Y or N./n";
		PlayerDropItemFromInv();
	}
}

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
		if (thePlayer.GetWhatIsFighting() != Monsters::BLANKMONSTER)
		{
			currentMob.subtractFromCurrentMobHealth(thePlayer.GetDamage());
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
				thePlayer.SetIsFighting(false);
				thePlayer.SetWhatIsFighting(Monsters::BLANKMONSTER);
			}
		}
		else
		{
			std::cout << "ERROR: Something went wrong. Debug info: Player.FightCommand.INVALIDMONSTERBATTLE" << std::endl;
			exit(1); // TODO: find a better solution than exit()
		}
	}
	else
	{
		std::cout << "You prepare yourself to battle, only to realize that you have nothing to fight.\n";
	}
}
/* InvItems.h
 * Last updated with 0.2.3
 * Header file for PlayerInvItemsSource.cpp
 * Also contains the enum for all items
 */

#ifndef PLAYERINVITEMS_H
#define PLAYERINVITEMS_H
#include <string>

enum class ItemList  // Enum of all in game items
{
	/* Description of naming scheme:
	 * GENERIC_ : Otherwise uncategorized items.
	 * WEAPONS_ : Weapons; improve the players (or other monsters) damage output during attacks.
	 */
	GENERIC_HAND,  // Effectively used as the 'empty slot' item for the players inventory. Also is technicially a weapon, as the player need not be wielding a WEAPONS_ item to attack and can use their hand.
	WEAPONS_SWORD, // Basic weapon used to improve a players damage output.
};

enum class ItemEvents // Lables of the different events that can happen to an item
{
	USED,
	PICKED_UP,
	DROPPED
};

std::string ItemsToStrings(ItemList item);

int GetWeaponsDamage(ItemList item);


#endif PLAYERINVITEMS_H
#ifndef PLAYERINVITEMS_H
#define PLAYERINVITEMS_H

enum class ItemList
{
	/* Description of naming scheme:
	 * GENERIC_ : Otherwise uncategorized items.
	 * WEAPONS_ : Weapons; improve the players (or other monsters) damage output during attacks.
	 */
	GENERIC_HAND,  // Effectively used as the 'empty slot' item for the players inventory. Also is technicially a weapon, as the player need not be wielding a WEAPONS_ item to attack and can use their hand.
	WEAPONS_SWORD, // Basic weapon used to improve a players damage output.
};

std::string ItemsToStrings(ItemList item);


#endif PLAYERINVITEMS_H
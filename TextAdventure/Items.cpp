/* InvItemsSource.cpp
 * Last updated with 0.2.2
 * Holds code related to the handling and attributes of inventory items
 */

#include "stdafx.h"
#include "Items.h"
#include <iostream>
#include <string>

std::string ItemsToStrings(ItemList item)  // Converts the internal Item ID's into text strings.
{
	switch (item)
	{
	case ItemList::GENERIC_HAND:
		return "Hand";
		break;
	case ItemList::WEAPONS_SWORD:
		return "Sword";
		break;
	default:
		std::cout << "ERROR: Something went wrong. Error info: PlayerInvItems.ItemsToStrings.INVALID_ITEM_PASSED" << std::endl;
		exit(1);  // TODO: Find a better solution than exit()
	}
}

int GetWeaponsDamage(ItemList item)  // Returns how much damage the given weapon does
{
	switch (item)
	{
	case ItemList::WEAPONS_SWORD:
		return 20;
		break;
	default:
		return 10;
		break;
	}
}
#ifndef PLAYERINVITEMS_H
#define PLAYERINVITEMS_H

class Items
{
public:
	enum class ItemList
	{
		GENERIC_HAND,
		WEAPONS_SWORD,
	};

	std::string ItemsToStrings(ItemList item)
	{
		switch (item)
		{
		case ItemList::GENERIC_HAND:
		{
			return "Hand";
			break;
		}
		case ItemList::WEAPONS_SWORD:
		{
			return "Sword";
			break;
		}
		default:
		{
			std::cout << "ERROR: Something went wrong. Error info: _class_Items.ItemsToStrings.INVALID_ITEM_PASSED" << std::endl;
			exit(1);
		}
		}
	}
};
#endif PLAYERINVITEMS_H
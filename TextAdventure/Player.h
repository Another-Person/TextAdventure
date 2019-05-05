/* Player.h
 * Last updated with 0.2.3
 * Provides the Player class interface and other code for the player; header file for Player.cpp
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <iostream>
#include "Monsters.h"
#include "Items.h"

enum class PlayerCheckCommandArgs // Type for different arguments of the Check command
{
	HEALTH,
	INV
};

class Player // The Player class. Holds the player variables and related functions. 
{
private:
	int mapXCoord;                     // Holds the player's x-coordinate on the map
	int mapYCoord;                     // Holds the player's y-coordinate on the map
	double health;                     // Holds health of the player
	double damage;	                   // Holds how much damage the player can do
	bool isFighting;                   // Player doesn't start off fighting something
	Monsters whatIsFighting;           // Initialized with the BlankMonster placeholder; if isFighting is true but BlankMonster is here then something is wrong
	std::vector<ItemList> inventory;   // Player inventory object

public:
	Player(int startXCoord = 5, int startYCoord = 5, double startHealth = 30, double startDamage = 10, bool fighting = false, Monsters startFighting = Monsters::BLANKMONSTER);

	double GetPlayerHealth() { return health; }
	void AddToPlayerHealth(double amount);
	void SubtractFromPlayerHealth(double amount);

	double GetDamage() { return damage; }
	void AddToPlayerDamage(double amount);
	void SubtractFromPlayerDamage(double amount);

	bool GetIsFighting() { return isFighting; }
	void SetIsFighting(bool fightingState);

	Monsters GetWhatIsFighting() { return whatIsFighting; }
	void SetWhatIsFighting(Monsters fighting);

	void UpdatePlayerStats(ItemList item, ItemEvents event);
	
	void PrintPlayerInvStrings();

	void ReplaceItemInInv(ItemList item);

	void AddItemToInv(ItemList item);

	void RemoveItemFromInv(int slot);

	void PlayerDropItemFromInv();

};

void CheckHealthCommand();

void CheckCommand(std::string input);

void FightCommand(bool isFighting);


#endif PLAYER_H // !PLAYER_H


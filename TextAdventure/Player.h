/* Player.h
 * Last updated with 0.2.3
 * Provides the Player class interface and other code for the player; header file for PlayerSource.cpp
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
	double health;                     // Holds health of the player
	double damage;	                   // Holds how much damage the player can do
	bool isFighting;                   // Player doesn't start off fighting something
	Monsters whatIsFighting;           // Initialized with the BlankMonster placeholder; if isFighting is true but BlankMonster is here then something is wrong
	std::vector<ItemList> inventory;   // Player inventory object

public:



};


#endif PLAYER_H // !PLAYER_H


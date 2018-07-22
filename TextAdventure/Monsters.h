/* Monsters.h
 * Last updated with 0.2.3
 * Holds enum of all the monsters, along with structs for their default values and defines the CurrentMob class. Header file for Monsters.cpp
 */

#ifndef MONSTERS_H
#define MONSTERS_H

enum class Monsters  // Enum for all the different types of monsters
{
	BLANKMONSTER,
	ORC,
	GIANTSPIDER,
	TROLL
};

// Structs defining the characteristics of each monster

struct Orc
{
	int health = 20;
	int damage = 5;
};

struct GiantSpider
{
	int health = 15;
	int damage = 5;
};

struct Troll
{
	int health = 30;
	int damage = 10;
};

class CurrentMob  // Contains information on the contained mob | TODO: make stuff const; make sure is fully extensible
{
private:
	Monsters whichMonster;     // Which type of monster is being stored in the class
	int health;                // How much health the monster currently has
	int damage;                // How much damage the current monster can deal
public:
	// Constructor for priv variables
	CurrentMob(Monsters startMonster = Monsters::BLANKMONSTER, int startHealth = -1, int startDamage = -1);

	void setCurrentMobValues(Monsters monster);  // Sets the private varibles with the appropriate values for the mob passed into the function. | TODO: Make it less dependent on the if / else-if block, as hard to extend in the future
	void clearCurrentMobValues();  // Resets CurrentMob to default, generic values.
	
	int getCurrentMobHealth() { return health; } 
	void addToCurrentMobHealth(int amount) { health = health + amount; } 
	void subtractFromCurrentMobHealth(int amount) { health = health - amount; } 

	int getCurrentMobDamage() { return damage; } // TODO: Probably add functions to change this for myriad reasons

	Monsters getCurrentMobwhichMonster() { return whichMonster; } 

	
};

#endif MONSTERS_H
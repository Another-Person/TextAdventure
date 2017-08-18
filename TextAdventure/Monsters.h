#ifndef MONSTERS_H
#define MONSTERS_H

enum class Monsters
{
	BLANKMONSTER,
	ORC,
	GIANTSPIDER,
	TROLL
};

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

class CurrentMob
{
private:
	Monsters whichMonster;     // Which type of monster is being stored in the class
	int health;                // How much health the monster currently has
	int damage;                // How much damage the current monster can deal
public:
	// Constructor for priv variables
	CurrentMob(Monsters startMonster = Monsters::BLANKMONSTER, int startHealth = -1, int startDamage = -1) : whichMonster{ startMonster }, health{ startHealth }, damage{ startDamage }
	{
	}

	void setCurrentMobValues(Monsters monster)  // Sets the private varibles with the appropriate values for the mob passed into the function. | TODO: Make it less dependent on the if / else-if block, as hard to extend in the future
	{
		if (monster == Monsters::ORC)
		{
			Orc orc;
			whichMonster = monster;
			health = orc.health;
			damage = orc.damage;
		}
		else if (monster == Monsters::GIANTSPIDER)
		{
			GiantSpider giantspider;
			whichMonster = monster;
			health = giantspider.health;
			damage = giantspider.damage;
		}
		else if (monster == Monsters::TROLL)
		{
			Troll troll;
			whichMonster = monster;
			health = troll.health;
			damage = troll.damage;
		}
		else
		{
			std::cout << "ERROR: Something went wrong. Debug info: _class_CurrentMob.SetCurrentMobValues.INVALIDMONSTERPASSED" << std::endl;
			exit(1);
		}
	}

	int getCurrentMobHealth()  // Returns the current health of the mob.
	{
		return health;
	}

	void addToCurrentMobHealth(int amount) // Adds a given amount of heath to the mob.
	{
		health = health + amount;
	}

	void subtractFromCurrentMobHealth(int amount)  // Takes away a given amount of health from the mob.
	{
		health = health - amount;
	}

	int getCurrentMobDamage()  // Returns how much damage the mob can do. | TODO: Probably add functions to change this for myriad reasons
	{
		return damage;
	}

	Monsters getCurrentMobwhichMonster() // Returns which monster is currently stored in the Class.
	{
		return whichMonster;
	}

	void clearCurrentMobValues()  // Resets CurrentMob to default, generic values.
	{
		whichMonster = Monsters::BLANKMONSTER;
		health = -1;
		damage = -1;
	}
};

/* The functions have been depreciated in favor of a class.
 * These will most likely be thrown out shortly.
struct GenericMobTemplate
{
	Monsters whichMonster;
	int health;
	int damage;
};


void SetcurrentMobValues(Monsters monster);

void SubtractFromcurrentMobHealth(int amount);

void AddTocurrentMobHealth(int amount);

int GetcurrentMobHealth();

int GetcurrentMobDamage();
*/
#endif MONSTERS_H
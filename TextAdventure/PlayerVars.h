#ifndef PLAYERVARSDEFINE_H
#define PLAYERVARSDEFINE_H

enum class PlayerCheckCommandArgs
{
	HEALTH,
	INV
};

struct PlayerVars
{
    int health;
    int invObjects[10]; // 10 slots of inventory space for our player
};

int GetPlayerHealth();

void AddToPlayerHealth(int amount);

void SubtractFromPlayerHealth(int amount);


#endif PLAYERSVARSDEFINE_H

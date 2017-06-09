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

#endif PLAYERSVARSDEFINE_H

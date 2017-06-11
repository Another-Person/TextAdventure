#ifndef PLAYERVARSDEFINE_H
#define PLAYERVARSDEFINE_H
#include <array>

enum class PlayerCheckCommandArgs
{
	HEALTH,
	INV
};

struct PlayerVars
{
    int health;
	std::array<int, 10> invObjects = { }; // Sets 10 empty slots of inventory space for our pla
};

int GetPlayerHealth();

void AddToPlayerHealth(int amount);

void SubtractFromPlayerHealth(int amount);

void PrintPlayerInvIDs();

std::string InvObjIDToString(int objID);

void PrintPlayerInvStrings();

void AddItemToInv(int objID);

#endif PLAYERSVARSDEFINE_H

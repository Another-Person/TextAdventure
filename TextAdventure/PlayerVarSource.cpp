#include "stdafx.h"
#include "PlayerVars.h"

static PlayerVars Player{ 20 };

int GetPlayerHealth()
{
	return Player.health;
}

// Encapsulation functions for the global variable
void AddToPlayerHealth(int amount)
{
	Player.health = Player.health + amount;
}

void SubtractFromPlayerHealth(int amount)
{
	Player.health = Player.health - amount;
}
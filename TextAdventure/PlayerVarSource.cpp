#include "stdafx.h"
#include "PlayerVars.h"

static PlayerVars Player{ 20 };

int GetPlayerHealth()
{
	return Player.health;
}

// Encapsulation functions for the global bariable
void AddToPlayerHealth(int amount)
{
	Player.health = Player.health + amount;
}
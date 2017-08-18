#ifndef PLAYERFUNCDEFINE_H
#define PLAYERFUNCDEFINE_H
#include "Monsters.h"

void CheckHealthCommand();

void CheckCommand(std::string input);

void FightCommand(bool isFighting, Monsters whatFighting);

#endif PLAYERFUNCDEFINE_H 
#include "stdafx.h"
#include <iostream>
#include <string>
#include "RandNumGens.h"
#include "PlayerVarsDefine.h"

void CheckHealthCommand()
{
	PlayerVars Player{ 20 };
	std::cout << "You have" << Player.health << "health remaining." << std::endl;
}
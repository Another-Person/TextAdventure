/* RandNumGensSource.cpp
 * Last updated with 0.2.2
 * Holds functions that wrap the std random library code for easy use across the project 
 */

#include "stdafx.h"
#include <random>
#include <ctime>

namespace MyRandom
{
	std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
}

int RandInt(int minGen, int maxGen)  // Generates random integers between a given minimum and maximum
{
	std::uniform_int_distribution<int> distribution(minGen, maxGen);
	return distribution(MyRandom::mersenne);
}
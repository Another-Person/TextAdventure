/* RandNumGensSource.cpp
 * Last updated with 0.2.2
 * Holds functions that wrap the std random library code for easy use across the project 
 */

#include "stdafx.h"
#include <random>
#include <time.h>

int RandInt(int minGen, int maxGen)  // Generates random integers between a given minimum and maximum
{
	std::default_random_engine generator(time(NULL));
	std::uniform_int_distribution<int> distribution(minGen, maxGen);
	int numberGenerated = distribution(generator);
	return numberGenerated;
}
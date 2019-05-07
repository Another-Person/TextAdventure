/* Map.cpp
 * Last editied with 0.3.0
 * Holds code for the Map class and related code.
 */


#include "stdafx.h"
#include "RandNumGens.h"
#include "Map.h"

Map::Map()
{
	for (int x = 0; x < theMap.size(); x++)
	{
		for (int y = 0; y < theMap.at(x).size(); y++)
		{
			Terrain setTerrain = Terrain::DESERT;
			int num = RandInt(1, 4);
			if (num == 1)
				setTerrain = Terrain::DESERT;
			else if (num == 2)
				setTerrain = Terrain::FOREST;
			else if (num == 3)
				setTerrain = Terrain::PLAIN;
			else if (num == 4)
				setTerrain = Terrain::TUNDRA;
			theMap.at(x).at(y) = { {x,y}, Monsters::BLANKMONSTER, ItemList::GENERIC_HAND, setTerrain };
		}

	}
}

/* Map.cpp
 * Last editied with 0.3.0_dr8
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

/*  Advice from Jordan Ball on how to 
{
	MapTile placeholder = { the stuff }
	vector<MapTile> v1 { the maptiles, another, etc };
	map.pushback(v1);
}
*/
Terrain Map::GetTileTerrain(CoordPoint point)
{
	Terrain returnValue = Terrain::DESERT;
	for (int x = 0; x < theMap.size(); x++)
	{
		for (int y = 0; y < theMap.at(x).size(); y++)
		{
			if (theMap.at(x).at(y).coordinates == point)
			{
				returnValue = theMap.at(x).at(y).tileTerrain;
			}
		}
	}
	return returnValue;
}

bool operator==(const CoordPoint& p1, const CoordPoint& p2)
{
	return ( p1.xCoord == p2.xCoord && p1.yCoord == p2.yCoord );
}

bool operator!=(const CoordPoint& p1, const CoordPoint& p2)
{
	return !(p1 == p2);
}

std::string TerrainToString(Terrain terrain)
{
	if (terrain == Terrain::DESERT)
	{
		return "desert";
	}
	else if (terrain == Terrain::FOREST)
	{
		return "forest";
	}
	else if (terrain == Terrain::PLAIN)
	{
		return "plain";
	}
	else if (terrain == Terrain::TUNDRA)
	{
		return "tundra";
	}
}

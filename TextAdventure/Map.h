/* Map.h
 * Last updated with 0.3.0
 * Provides the Map class and related code.
 */

#ifndef MAP_H
#define MAP_H
#include "Monsters.h"
#include "Items.h"
#include <array>

enum class Terrain
{
	FOREST,
	PLAIN,
	TUNDRA,
	DESERT
};

struct CoordPoint
{
	int xCoord;
	int yCoord;
};

struct MapTile
{
	CoordPoint coordinates;
	Monsters monsterInTile;
	ItemList itemInTile;
	Terrain tileTerrain;
};

class Map
{
private:
	std::array<std::array<MapTile,10>,10> theMap;

public:
	Map();
};

#endif // !MAP_H

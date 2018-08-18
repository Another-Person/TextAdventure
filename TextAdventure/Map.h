/* Map.h
 * Last updated with 0.3.0
 * Provides the Map class and related code.
 */

#ifndef MAP_H
#define MAP_H
#include "Monsters.h"
#include "Items.h"
#include <vector>

enum class Terrain
{
	FOREST,
	PLAIN,
	TUNDRA,
	DESERT
};

struct MapTile
{
	bool playerInTile;
	Monsters monsterInTile;
	ItemList itemInTile;
	Terrain tileTerrain;
};

class Map
{
private:
	std::vector<std::vector<MapTile>> theMap;

public:
	Map();
};

#endif // !MAP_H

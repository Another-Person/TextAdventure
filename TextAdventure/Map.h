/* Map.h
 * Last updated with 0.3.0_dr8
 * Provides the Map class and related code.
 */

#ifndef MAP_H
#define MAP_H
#include "Monsters.h"
#include "Items.h"
#include <array>
#include <vector>

using namespace std;

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

bool operator== (const CoordPoint& p1, const CoordPoint& p2);
bool operator!= (const CoordPoint& p1, const CoordPoint& p2);

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
	vector<vector<MapTile>> theMap;

public:
	Map();

	Terrain GetTileTerrain(CoordPoint point);
};

std::string TerrainToString(Terrain terrain);

#endif // !MAP_H

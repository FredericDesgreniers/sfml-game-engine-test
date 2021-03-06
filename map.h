#pragma once
#include <vector>
#include "gridPosition.h"
#define TILE_SIZE 20
#define TILE_AIR 0
#define TILE_WALL 1
#define TILE_SAND 2
#define TILE_GRASS 3
#define TILE_WATER_DEEP 4
namespace GameEngine
{
	class Map
	{
	public:
		Map(int width, int height);
		GridPosition*** getGrid();
		int getWidth(), getHeight();
		GridPosition* getAt(int x, int y);
		bool isNearWater(int x, int y);
	private:
		GridPosition*** grid;
		int height;
		int width;
	};


}

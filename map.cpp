#include "map.h"
#include <random>
#include <time.h>
#include <iostream>
using namespace GameEngine;

Map::Map(int width, int height)
{
	srand(time(NULL));
	this->width = width;
	this->height = height;
	int lakeX = (rand()%width);
	int lakeY = (rand()%width);
	int maxDistance = (rand() % 6) + 3;
	int lakeSizeX = (rand() % 6) + 4;
	int lakeSizeY = (rand() % 6) + 4;
	std::cout << lakeX << " : " << lakeY << std::endl;
	grid = new GridPosition**[height];
	for (int y = 0; y < height; y++)
	{
		grid[y] = new GridPosition*[width];
		for (int x = 0; x < width; x++)
		{
			int dX = std::abs(x - lakeX);
			int dY = std::abs(y - lakeY);
			double distance = sqrt(dX*dX + dY*dY);
			grid[y][x] = new GridPosition(x,y,(distance < 3)?TILE_WATER_DEEP:(dX < lakeSizeX && dY < lakeSizeY && distance < maxDistance)?TILE_WALL:TILE_GRASS);
		}
	}

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			GridPosition* tile = grid[y][x];
			if (tile->getId() != TILE_WALL && tile->getId() != TILE_WATER_DEEP && isNearWater(x,y)) {
				tile->setId(TILE_SAND);
			}
		}
	}

}
GridPosition ***Map::getGrid()
{
	return grid;
}

int Map::getHeight()
{
	return height;
}

int Map::getWidth()
{
	return width;
}

GridPosition* Map::getAt(int x, int y)
{
	return grid[y][x];
}

bool Map::isNearWater(int x, int y) {
	if (x > 0 &&( grid[y][x - 1]->getId() == TILE_WALL || grid[y][x - 1]->getId() == TILE_WATER_DEEP))
		return true;

	if (y > 0 && (grid[y-1][x]->getId() == TILE_WALL || grid[y-1][x]->getId() == TILE_WATER_DEEP))
		return true;

	if (x < width-1 && (grid[y][x+1]->getId() == TILE_WALL || grid[y][x + 1]->getId() == TILE_WATER_DEEP))
		return true;

	if (y < height-1 && (grid[y+1][x]->getId() == TILE_WALL || grid[y+1][x]->getId() == TILE_WATER_DEEP))
		return true;
	return false;

}

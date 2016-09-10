#include "map.h"

using namespace GameEngine;

Map::Map(int width, int height)
{
	this->width = width;
	this->height = height;

	grid = new GridPosition**[height];
	for (int y = 0; y < height; y++)
	{
		grid[y] = new GridPosition*[width];
		for (int x = 0; x < width; x++)
		{
			grid[y][x] = new GridPosition(x,y,0);
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

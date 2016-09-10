#include "gridPosition.h"

using namespace GameEngine;

GridPosition::GridPosition(int x, int y, int id)
{
	this->x = x;
	this->y = y;
	this->id = id;
}

int GridPosition::getId()
{
	return id;
}

int GridPosition::getX()
{
	return x;
}

int GridPosition::getY()
{
	return y;
}

void GridPosition::setId(int id)
{
	this->id = id;
}





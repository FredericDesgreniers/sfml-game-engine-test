#include "entity.h"

using namespace GameEngine;

Entity::Entity(int posX, int posY, float health)
{
	this->posX = posX;
	this->posY = posY;
	this->health = health;
}

int Entity::getPosY()
{
	return posY;
}

int Entity::getPosX()
{
	return posY;
}

float Entity::getHealth()
{
	return health;
}

void Entity::moveDown(int l)
{
	posY++;
}
void Entity::moveLeft(int l)
{
	posX--;
}
void Entity::moveRight(int l)
{
	posX++;
}
void Entity::moveUp(int l)
{
	posY--;
}








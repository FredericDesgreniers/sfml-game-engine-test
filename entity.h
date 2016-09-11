#pragma once


namespace GameEngine
{
	class Entity
	{
	public:
		Entity(int posX, int posY, float health);

		int getPosX(), getPosY();
		float getHealth();

		void moveRight(int l);
		void moveLeft(int l);
		void moveUp(int l);
		void moveDown(int l);

	private:

		int posX, posY;
		float health;
	};
}
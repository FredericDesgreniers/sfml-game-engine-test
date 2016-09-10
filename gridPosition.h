#pragma once

namespace GameEngine
{
	class GridPosition
	{
	public:
		GridPosition(int x,int y, int id);
		int getX(), getY(), getId();
		void setId(int id);
	private:
		int id;
		int x, y;

	};
}
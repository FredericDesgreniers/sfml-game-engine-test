#pragma once
#include "view.h"

namespace ViewEngine
{
	class TitleView:public View
	{
	public:
		TitleView(MainEngine::Game* game);
		void render(sf::RenderWindow* rWindow);
		void update(sf::RenderWindow* rWindow);
		void initialize(sf::RenderWindow* rWindow);
		void buttonPressed(Button* button);
	private:
		int counter;
	};
}
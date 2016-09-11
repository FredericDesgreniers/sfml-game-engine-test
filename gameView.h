#pragma once
#include "view.h"
#include "map.h"
#include "entity.h"

namespace ViewEngine
{
	class GameView :public View
	{
	public:
		GameView(MainEngine::Game* game);
		void render(sf::RenderWindow* rWindow);
		void update(sf::RenderWindow* rWindow);
		void initialize(sf::RenderWindow* rWindow);
		void buttonPressed(Button* button);
		void keyPressed(sf::Event::KeyEvent keyEvent);
	private:
		GameEngine::Map map;
		GameEngine::Entity player;
	};
}

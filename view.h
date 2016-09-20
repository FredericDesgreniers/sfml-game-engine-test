#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include "Button.h"
#include "game.h"
#include <SFML/Window/Event.hpp>

namespace MainEngine
{
	class Game;
}
namespace ViewEngine
{
	class View
	{
	public:
		View(MainEngine::Game* game);
		~View();
		virtual void render(sf::RenderWindow* rWindow);
		virtual void update(sf::RenderWindow* rWindow);
		virtual void initialize(sf::RenderWindow* rWindow);
		void addButton(Button button);

		void setChildView(View* view);
		
		//inputs
		virtual	void onLeftMousePress(sf::Vector2i pos);
		virtual void buttonPressed(Button* button);
		virtual void keyPressed(sf::Event::KeyEvent keyEvent);

		View* removeChildView();
		View* removeLowestView();
		View* getLowestView();
		View* getParentView();
		
	protected:
		void setLowestView(View* view);
		void setParentView(View* view);

		sf::Font defaultFont;
		std::vector<Button> buttons;
		MainEngine::Game* game;

		View* childView;
		View* parentView;
		View* lowestView;

	};
}

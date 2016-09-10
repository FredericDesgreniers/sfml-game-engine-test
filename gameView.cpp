#include "gameView.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
using namespace ViewEngine;

GameView::GameView(MainEngine::Game* game) :View(game), map(20,20)
{

}

void GameView::initialize(sf::RenderWindow* rWindow)
{
	View::initialize(rWindow);
}

void GameView::render(sf::RenderWindow* rWindow)
{
	View::render(rWindow);
	sf::Text text("This is the game", defaultFont, 50);
	text.setFillColor(sf::Color::White);

	text.setPosition(0, 0);

	rWindow->draw(text);
	sf::Vector2f mapPosition(0,100);
	for (int x = 0; x < map.getWidth(); x++)
	{
		for (int y = 0; y < map.getHeight(); y++)
		{
			GameEngine::GridPosition* tile = map.getAt(x, y);
			if (tile->getX() == 2)
				tile->setId(1);
			sf::RectangleShape tileShape;
			tileShape.setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
			tileShape.setPosition(mapPosition + sf::Vector2f(x*TILE_SIZE,y*TILE_SIZE));
			sf::Color color;
			switch(tile->getId())
			{
			case 0:
				color = sf::Color::White;
				break;
			case 1:
				color = sf::Color::Blue;
				break;
			}
			tileShape.setFillColor(color);
			
			rWindow->draw(tileShape);
		}
	}

}
void GameView::update(sf::RenderWindow* rWindow)
{
	View::update(rWindow);

}

void GameView::buttonPressed(Button* button)
{

}

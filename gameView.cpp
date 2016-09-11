#include "gameView.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
using namespace ViewEngine;

GameView::GameView(MainEngine::Game* game) :View(game), map(20, 20), player(10, 10, 100)
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
	sf::Vector2f mapPosition(10,100);
	sf::RectangleShape mapBackground;
	mapBackground.setPosition(mapPosition.x, mapPosition.y);
	mapBackground.setSize(sf::Vector2f(TILE_SIZE*map.getWidth(), TILE_SIZE*map.getHeight()));
	mapBackground.setFillColor(sf::Color::Black);
	mapBackground.setOutlineColor(sf::Color(255, 200, 200));
	mapBackground.setOutlineThickness(2);
;	rWindow->draw(mapBackground);
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
			case TILE_AIR:
				color = sf::Color::White;
				break;
			case TILE_WALL:
				color = sf::Color::Blue;
				break;
			default:
				color = sf::Color::Black;
				break;
			}
			tileShape.setFillColor(color);
			
			rWindow->draw(tileShape);
		}
	}
	sf::RectangleShape playerShape;
	playerShape.setFillColor(sf::Color::Red);
	playerShape.setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
	playerShape.setPosition(mapPosition + sf::Vector2f(player.getPosX()*TILE_SIZE, player.getPosY()*TILE_SIZE));
	rWindow->draw(playerShape);
}
void GameView::update(sf::RenderWindow* rWindow)
{
	View::update(rWindow);

}

void GameView::buttonPressed(Button* button)
{

}
void GameView::keyPressed(sf::Event::KeyEvent keyEvent)
{
	switch (keyEvent.code)
	{
	case sf::Keyboard::W:
		if (player.getPosY() > 0)
			player.moveUp(1);
		break;
	case sf::Keyboard::S:
		if (player.getPosY()+1 < map.getHeight())
			player.moveDown(1);
		break;
	case sf::Keyboard::A:
		if (player.getPosX() > 0)
			player.moveLeft(1);
		break;
	case sf::Keyboard::D:
		if (player.getPosX()+1 < map.getHeight())
			player.moveRight(1);
		break;
	}
}

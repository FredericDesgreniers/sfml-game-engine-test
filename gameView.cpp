#include "gameView.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Mouse.hpp>
using namespace ViewEngine;

GameView::GameView(MainEngine::Game* game) :View(game)
{
}

void GameView::initialize(sf::RenderWindow* rWindow)
{
	View::initialize(rWindow);
	addButton(Button(0, "Exit Game", sf::Vector2f(0, 100), sf::Vector2f(200, 50)));
}

void GameView::render(sf::RenderWindow* rWindow)
{
	View::render(rWindow);
	sf::Text text("This is the game", defaultFont, 50);
	text.setFillColor(sf::Color::White);

	text.setPosition(0, 0);

	rWindow->draw(text);

}
void GameView::update(sf::RenderWindow* rWindow)
{
	View::update(rWindow);

}

void GameView::buttonPressed(Button* button)
{

}

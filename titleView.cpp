#include "titleView.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Mouse.hpp>
#include "gameView.h"
#include <iostream>
using namespace ViewEngine;

TitleView::TitleView(MainEngine::Game* game):View(game)
{
	counter = 0;

	
}

void TitleView::initialize(sf::RenderWindow* rWindow) 
{
	View::initialize(rWindow);
	addButton(Button(0, "New Game", sf::Vector2f(0, 100), sf::Vector2f(200, 50)));
}

void TitleView::render(sf::RenderWindow* rWindow)
{
	View::render(rWindow);
	sf::Text text("Game v1", defaultFont, 50);
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Style::Italic);
	text.setPosition(0, 0);


	sf::Text counterText("Counter: " + std::to_string(counter),defaultFont, 20);
	counterText.setPosition(0, rWindow->getSize().y-20);

	sf::Text mouseText("mouse: " + std::to_string(sf::Mouse::getPosition(*rWindow).x) +" : "+ std::to_string(sf::Mouse::getPosition(*rWindow).y), defaultFont, 20);
	mouseText.setPosition(0, rWindow->getSize().y - 60);

	rWindow->draw(text);

	rWindow->draw(mouseText);
	rWindow->draw(counterText);
}
void TitleView::update(sf::RenderWindow* rWindow)
{
	View::update(rWindow);
	counter++;
}


void TitleView::buttonPressed(Button* button)
{
	switch(button->code)
	{
	case 0:
		setChildView(new GameView(game));
		break;
	}
}
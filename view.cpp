#include "view.h"

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Mouse.hpp>

using namespace ViewEngine;

View::View(MainEngine::Game* game)
{
	this->game = game;
	defaultFont.loadFromFile("res/Dragonfly.ttf");
	lowestView = this;
	
}

void View::render(sf::RenderWindow* rWindow)
{
	for (auto &b : buttons)
	{
		/*
		sf::RectangleShape rect(b.getDimension());
		rect.setPosition(b.getPosition());
		rect.setFillColor(sf::Color::Transparent);
		rect.setOutlineColor(sf::Color::White);
		rect.setOutlineThickness(2);
		rWindow->draw(rect);
		*/


		sf::Text text(b.getText(), defaultFont, 30);
		text.setOrigin((text.getGlobalBounds().width / 2), text.getGlobalBounds().height / 2);
		text.setPosition(b.getPosition().x + (b.getDimension().x / 2), b.getPosition().y + b.getDimension().y / 2); 
		text.setFillColor(sf::Color::White);

		if(b.getHovering())
		{
			text.setStyle(sf::Text::Style::Underlined);
		}
		rWindow->draw(text);
	}
}

void View::update(sf::RenderWindow* rWindow)
{
	sf::Vector2i mPos = sf::Mouse::getPosition(*rWindow);
	for (auto &b : buttons)
	{
		sf::Vector2f bPos = b.getPosition();
		sf::Vector2f bDim = b.getDimension();
		if(mPos.x > bPos.x && mPos.x < bPos.x + bDim.x && mPos.y > bPos.y && mPos.y < bPos.y + bDim.y)
		{
			b.setHovering(true);
		}else
		{
			b.setHovering(false);
		}
	}
}

void View::initialize(sf::RenderWindow* rWindow)
{
	buttons.clear();
}


void View::addButton(Button button)
{
	buttons.push_back(button);
}


View* View::getParentView()
{
	return parentView;
}

void View::setChildView(View* view)
{
	view->initialize(game->getWindow());
	childView = view;
	if(parentView!=NULL)
		parentView->setLowestView(childView->getLowestView());
	setLowestView(childView->getLowestView());
	childView->setParentView(this);

}
void View::setParentView(View* view)
{
	parentView = view;
}

void View::setLowestView(View* view)
{
	if (parentView != NULL)
		parentView->setLowestView(lowestView);
	lowestView = view;
}


View* View::getLowestView()
{
	return lowestView;
}

void View::onLeftMousePress(sf::Vector2i mPos)
{
	for (auto &b : buttons)
	{
		sf::Vector2f bPos = b.getPosition();
		sf::Vector2f bDim = b.getDimension();

		if (mPos.x > bPos.x && mPos.x < bPos.x + bDim.x && mPos.y > bPos.y && mPos.y < bPos.y + bDim.y)
		{
			buttonPressed(&b);
		}
	}

}

void View::buttonPressed(Button* button)
{
	
}
void View::keyPressed(sf::Event::KeyEvent keyEvent)
{
	
}

View* View::removeChildView()
{
	View* v = childView;
	childView = NULL;
	removeLowestView();

	return NULL;
	

}

View* View::removeLowestView()
{
	View* v = lowestView;
	setLowestView(this);
	return v;
}

View::~View()
{
	delete &defaultFont;
}

#include "game.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "titleView.h"
using namespace MainEngine;

/**
 * \brief main game loop.
 * 
 * This loops as long as the window is open and calls the other components of the engine to update / render. No game logic should be present here. 
 */
void Game::run()
{
	window->setFramerateLimit(30);
	while (window->isOpen())
	{

		sf::Event event;
		while (window->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window->close();
				break;
			case sf::Event::MouseButtonPressed:
				currentView->getLowestView()->onLeftMousePress(sf::Mouse::getPosition(*window));
				break;
			case sf::Event::KeyPressed: 
				currentView->getLowestView()->keyPressed(event.key);
			}
		}
		currentView->getLowestView()->update(window);
		window->clear();
		renderer->renderFrame(currentView->getLowestView());
		window->display();
	}
}

/**
 * \brief Sets up the sfml window.
 * 
 * Sets the sfml window to be sued for rendering. It also initializes the RenderEngine
 */
void Game::setupWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(800,800), "Fred's Game Engine v1");
	
	renderer = new RenderEngine::Renderer(window);
}

void Game::start()
{
	setupWindow();
	setView(new ViewEngine::TitleView(this));
	run();
}

void Game::setView(ViewEngine::View* view)
{
	currentView = view;
	view->initialize(window);
}

sf::RenderWindow* Game::getWindow()
{
	return window;
}


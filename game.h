#pragma once
#include "renderer.h"
#include "view.h"
namespace ViewEngine
{
	class View;
}
namespace RenderEngine
{
	class Renderer;
}
namespace MainEngine{
class Game
{
public:
	void start();
	void setView(ViewEngine::View* view);
	sf::RenderWindow* getWindow();
private:
	void run();
	void setupWindow();
	ViewEngine::View* currentView;
	RenderEngine::Renderer* renderer;
	sf::RenderWindow* window;

};
}
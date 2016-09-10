#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "view.h"
namespace ViewEngine
{
	class View;
}
namespace RenderEngine{
class Renderer
{
public:
	Renderer(sf::RenderWindow* window);
	void renderFrame(ViewEngine::View* view);

private:
	sf::RenderWindow* window;

};

}

#include "renderer.h"
using namespace RenderEngine;

/** \brief Main Render Constructor.
*
*/
Renderer::Renderer(sf::RenderWindow* window)
{
	this->window = window;
}


/**
 * \brief Render loop update.
 * 
 *  This is called each frame to render the current view.  
 */
void Renderer::renderFrame(ViewEngine::View* view)
{
	view->render(window);
}

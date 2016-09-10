#include "Button.h"

using namespace ViewEngine;

Button::Button(int code, std::string text, sf::Vector2f position, sf::Vector2f dimension) : code(code)
{
	this->text = text;
	this->position = position;
	this->dimension = dimension;
	hovering = false;
}

bool Button::getHovering()
{
	return hovering;
}
void Button::setHovering(bool h)
{
	hovering = h;
}


#pragma once
#include <SFML/System/Vector2.hpp>
#include <string>

namespace ViewEngine
{
	class Button
	{
	public:
		Button(int code, std::string text, sf::Vector2f position, sf::Vector2f dimension);
		std::string getText()
		{
			return text;
		}
		sf::Vector2f getPosition()
		{
			return position;
		};
		sf::Vector2f getDimension()
		{
			return dimension;
		}
		void setHovering(bool h);
		bool getHovering();
		const int code;
	private:
		sf::Vector2f position;
		sf::Vector2f dimension;
		std::string text;
		bool hovering;
	};
}

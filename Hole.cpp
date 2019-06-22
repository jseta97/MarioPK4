#include "Hole.h"

Hole::Hole()
{
}

Hole::Hole(float x, float y, float width, float height)
{
	this->shape = sf::RectangleShape(sf::Vector2f(width, height));
	this->shape.setPosition(sf::Vector2f(x, y));
}
#include "Block.h"
#include<SFML/Graphics.hpp>

Block::Block()
{

}



Block::Block(float x, float y, float width, float height, bool extra)
{
	this->shape = sf::RectangleShape(sf::Vector2f(width, height));
	this->shape.setPosition(sf::Vector2f(x, y));
	this->extra = extra;
}

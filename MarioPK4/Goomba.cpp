#include "Goomba.h"

#define ALIVE 0
#define DEAD 1

Goomba::Goomba(float maxLeft, float maxRight, float posY)
{
	init(maxRight,posY);
	this->maxLeft = maxLeft;
	this->maxRight = maxRight;

}

void Goomba::init(float position, float posY)
{
	texture.loadFromFile("C:/Users/jseta/source/repos/MarioPK4/goombaassets.png");
	width = texture.getSize().x / 2;
	height = texture.getSize().y / 2;
	shape = sf::RectangleShape(sf::Vector2f(width, height));
	shape.setTexture(&texture);
	shape.setPosition(position, posY - height);
	velocity = 100.0f;
	animation = Animation(&texture, sf::Vector2u(2, 2), 0.2f);
	deltaTime = clock.restart().asSeconds();
	animation.Update(state, deltaTime);
	shape.setTextureRect(animation.uvRect);
}



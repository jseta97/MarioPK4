#include "Mushroom.h"

Mushroom::Mushroom(float positionX, float positionY)
{
	init(positionX, positionY);
}

void Mushroom::init(float positionX, float positionY)
{
	texture.loadFromFile("C:/Users/jseta/source/repos/MarioPK4/mushroom.png");
	width = texture.getSize().x / 1;
	height = texture.getSize().y / 1;
	shape = sf::RectangleShape(sf::Vector2f(width, height));
	shape.setTexture(&texture);
	shape.setPosition(positionX, positionY - height);
	animation = Animation(&texture, sf::Vector2u(1, 1), 0.2f);
	deltaTime = clock.restart().asSeconds();
	animation.Update(state, deltaTime);
	shape.setTextureRect(animation.uvRect);
}

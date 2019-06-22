#include "PiranhaPlant.h"



PiranhaPlant::PiranhaPlant(float positionX, float positionY)
{
	init(positionX, positionY);
}

void PiranhaPlant::init(float positionX, float positionY)
{
	texture.loadFromFile("C:/Users/jseta/source/repos/MarioPK4/piranhaplantassets.png");
	width = texture.getSize().x / 2;
	height = texture.getSize().y / 1;
	shape = sf::RectangleShape(sf::Vector2f(width, height));
	shape.setTexture(&texture);
	shape.setPosition(positionX, positionY-height);
	animation = Animation(&texture, sf::Vector2u(2, 1), 0.2f);
	deltaTime = clock.restart().asSeconds();
	animation.Update(state, deltaTime);
	shape.setTextureRect(animation.uvRect);
}

void PiranhaPlant::updatePosition()
{
	wait--;
	if (active == true && wait == 0)
	{
		if (shape.getSize().y >= 0.0f)
		{
			shape.setSize(sf::Vector2f(shape.getSize().x, shape.getSize().y - 1.0f));
			shape.setPosition(sf::Vector2f(shape.getPosition().x, shape.getPosition().y + 1.0f));
			wait = 1;
		}
		else
		{
			active = false;
			wait = 120;
		}
	}
	if (active == false && wait == 0) 
	{
		if (shape.getSize().y <= 47.0f)
		{
			shape.setSize(sf::Vector2f(shape.getSize().x, shape.getSize().y + 1.0f));
			shape.setPosition(sf::Vector2f(shape.getPosition().x, shape.getPosition().y - 1.0f));
			wait = 1;
		}
		else
		{
			active = true;
			wait = 120;
		}
	}
	if (shape.getSize().y < 5.0f)
	{
		state = 1;
	}
	else
	{
		state = 0;
	}
}

void PiranhaPlant::draw(sf::RenderWindow & window)
{
	deltaTime = clock.restart().asSeconds();
	animation.Update(state, deltaTime);
	shape.setTextureRect(animation.uvRect);
	updatePosition();
	window.draw(shape);
}

#include "KoopaTroopa.h"

#define ALIVE_L 0
#define DEAD 1
#define ALIVE_R 2
#define LEFT_DIR 0
#define RIGHT_DIR 1

KoopaTroopa::KoopaTroopa(float maxLeft, float maxRight, float posY)
{
	init(maxRight,posY);
	this->maxLeft = maxLeft;
	this->maxRight = maxRight;
}

void KoopaTroopa::init(float position, float posY)
{
	texture.loadFromFile("C:/Users/jseta/source/repos/MarioPK4/koopatroopaassets.png");
	width = texture.getSize().x / 4;
	height = texture.getSize().y / 3;
	shape = sf::RectangleShape(sf::Vector2f(width, height));
	shape.setTexture(&texture);
	shape.setPosition(position, posY - height);
	animation = Animation(&texture, sf::Vector2u(4, 3), 0.1f);
	velocity = 100.0f;
	deltaTime = clock.restart().asSeconds();
	animation.Update(state, deltaTime);
	shape.setTextureRect(animation.uvRect);
}

void KoopaTroopa::updatePosition()
{
	sf::Vector2f movement(0.0f, 0.0f);
	if (shape.getPosition().x <= maxLeft)
	{
		direction = RIGHT_DIR;
	}
	if (shape.getPosition().x >= maxRight)
	{
		direction = LEFT_DIR;
	}
	if (direction == RIGHT_DIR)
	{
		state = ALIVE_R;
		movement.x += velocity * deltaTime;
	}
	else
	{
		state = ALIVE_L;
		movement.x -= velocity * deltaTime;
	}
	shape.move(movement);

}

void KoopaTroopa::draw(sf::RenderWindow & window)
{
	deltaTime = clock.restart().asSeconds();
	animation.Update(state, deltaTime);
	shape.setTextureRect(animation.uvRect);
	if(state!=1)
	updatePosition();
	window.draw(shape);
}





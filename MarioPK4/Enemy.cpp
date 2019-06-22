#include "Enemy.h"
#include <iostream>
#define DEAD 1
#define LEFT_DIR 0
#define RIGHT_DIR 1
void Enemy::turnLeft()
{
	isTurnLeft = true;
	isTurnRight = false;
}

void Enemy::turnRight()
{
	isTurnLeft = false;
	isTurnRight = true;
}

void Enemy::dead()
{
	state = DEAD;
}



void Enemy::updatePosition()
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
		movement.x += velocity * deltaTime;
	}
	else
	{
		movement.x -= velocity * deltaTime;
	}
	shape.move(movement);

}

void Enemy::draw(sf::RenderWindow & window)
{
	deltaTime = clock.restart().asSeconds();
	animation.Update(state, deltaTime);
	shape.setTextureRect(animation.uvRect);
	if(state!=1)
	updatePosition();
	window.draw(shape);
}
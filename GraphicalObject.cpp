#include "GraphicalObject.h"

void GraphicalObject::setState(int state)
{
	this->state = state;
}

int GraphicalObject::getState()
{
	return this->state;
}

void GraphicalObject::transform()
{
}

void GraphicalObject::draw(sf::RenderWindow & window)
{
}

void GraphicalObject::setX(float x)
{
}

void GraphicalObject::setY(float y)
{
}

float GraphicalObject::getX()
{
	return 0.0f;
}

float GraphicalObject::getY()
{
	return 0.0f;
}

void GraphicalObject::updatePosition()
{
}



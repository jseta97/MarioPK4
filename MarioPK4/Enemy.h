#pragma once
#include "GraphicalObject.h"
#include "Animation.h"
class Enemy : public GraphicalObject
{
public:

	Animation animation;
	sf::Clock clock;
	float deltaTime = 0.0f;
	float maxLeft;
	float maxRight;
	bool isTurnRight = false;
	bool isTurnLeft = false;
	void turnLeft();
	void turnRight();
	void dead();
	void updatePosition();
	void draw(sf::RenderWindow &window);
};
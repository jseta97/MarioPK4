#pragma once
#include "GraphicalObject.h"
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include <iostream>
class Mario : public GraphicalObject
{
public:
	sf::Texture superTexture;
	Animation animation;
	sf::Clock clock;
	float deltaTime = 0.0f;
	float velocity = 0.0f;
	Mario();
	void init();
	void transform();
	void updatePosition();
	float getX();
	float getY();
	void setX(float x);
	void setY(float y);
	void draw(sf::RenderWindow &window);
};


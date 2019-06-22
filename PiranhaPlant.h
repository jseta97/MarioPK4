#pragma once
#include "Enemy.h"
#include "Animation.h"
class PiranhaPlant : public Enemy
{
public:
	bool active = true;
	int wait = 120;
	PiranhaPlant(float positionX, float positionY);
	void init(float positionX,float positionY);
	void updatePosition();
	void draw(sf::RenderWindow &window);
}; 

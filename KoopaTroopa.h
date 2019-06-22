#pragma once
#include "Enemy.h"
#include "Animation.h"
class KoopaTroopa : public Enemy
{
public:
	KoopaTroopa(float maxLeft, float maxRight, float posY);
	void init(float position, float posY);
	void updatePosition();
	void draw(sf::RenderWindow &window);
};

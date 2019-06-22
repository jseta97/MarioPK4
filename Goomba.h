#pragma once
#include "Enemy.h"
#include "Animation.h"
class Goomba : public Enemy
{
public:
	Goomba(float maxLeft, float maxRight, float posY);
	void init(float position, float posY);
	
};
#pragma once
#include "GraphicalObject.h"
#include "Enemy.h"
class Mushroom : public Enemy
{
public:
	Mushroom(float positionX, float positionY);
	void init(float position, float positionY);

};
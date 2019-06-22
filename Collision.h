#pragma once
#include<SFML/Graphics.hpp>
#include"GraphicalObject.h"
#include"Block.h"
#include"Mushroom.h"
#include"Goomba.h"
#include"KoopaTroopa.h"
#include"FinishHole.h"
#include <vector>
#include<iostream>
class Collision
{
private:
	GraphicalObject* block;
	GraphicalObject * object;
	float blockX;
	float blockY;
	float blockWidth;
	float blockHeight;
	float objectX;
	float objectY;
	float objectWidth;
	float objectHeight;
public:
	Collision(GraphicalObject * object, GraphicalObject *block);
	~Collision();
	void checkCollision(std::vector<Mushroom> &mushrooms);
	void checkRightCollision();
	void checkLeftCollision();
	void checkBottomCollision(std::vector<Mushroom>& mushrooms);
	void checkTopCollision(std::vector<Mushroom>& mushrooms);
};
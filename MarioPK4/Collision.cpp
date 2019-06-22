#include "Collision.h"
#include "Mushroom.h"
#include "Goomba.h"
#include "KoopaTroopa.h"
#include "PiranhaPlant.h"
#include "Hole.h"
#include <vector>
#include <iostream>

Collision::Collision(GraphicalObject * object, GraphicalObject * block) :object(object), block(block)
{
	objectX = object->getShape().getPosition().x;
	objectY = object->getShape().getPosition().y;
	objectWidth = object->getShape().getSize().x;
	objectHeight = object->getShape().getSize().y;
	blockX = block->getShape().getPosition().x;
	blockY = block-> getShape().getPosition().y;
	blockWidth = block->getShape().getSize().x;
	blockHeight = block->getShape().getSize().y;
}

Collision::~Collision()
{
}

void Collision::checkCollision(std::vector<Mushroom> &mushrooms)
{
	if (objectX <= blockX + blockWidth && objectX + objectWidth >= blockX &&
		objectY <= blockY + blockHeight && objectY + objectHeight >= blockY)
	{
		FinishHole tempF = FinishHole(0, 0, 0, 0);
		if (typeid(*block).name() == typeid(tempF).name())
		{
			object->state = 5;
		}
		else
		{
			checkTopCollision(mushrooms);
			checkBottomCollision(mushrooms);
			checkLeftCollision();
			checkRightCollision();
		}
	}
}

void Collision::checkRightCollision()
{
	Goomba tempG = Goomba(0, 0,0);
	KoopaTroopa tempK = KoopaTroopa(0, 0,0);
	PiranhaPlant tempP = PiranhaPlant(0, 0);
	if (objectY <= blockY + blockHeight && objectY + objectHeight >= blockY+6.0f
		&& objectX + objectWidth >= blockX && objectX + objectWidth <= blockX + 10.0f)
	{
		if (typeid(*block).name() == typeid(tempG).name()
			|| typeid(*block).name() == typeid(tempK).name()
			|| typeid(*block).name() == typeid(tempP).name())
		{
			if (block->state != 1) {
				if (object->transformState == 0)
				{
					object->state = 2;
				}
				else
				{
					object->transform();
				}
			}
		}
		object->canRight = false;
		object->canLeft = true;
	}
}

void Collision::checkLeftCollision()
{
	Goomba tempG = Goomba(0, 0,0);
	KoopaTroopa tempK = KoopaTroopa(0, 0,0);
	PiranhaPlant tempP = PiranhaPlant(0, 0);
	if (objectY <= blockY + blockHeight && objectY + objectHeight >= blockY + 6.0f
		&& objectX <= blockX + blockWidth && objectX >= blockX + blockWidth - 10.0f)
	{
		if (typeid(*block).name() == typeid(tempG).name()
			|| typeid(*block).name() == typeid(tempK).name()
			|| typeid(*block).name() == typeid(tempP).name())
		{
			if (block->state != 1) {
				if (object->transformState == 0)
				{
					object->state = 2;
				}
				else
				{
					object->transform();
				}
			}
		}
		object->canLeft = false;
		object->canRight = true;
	}
}

void Collision::checkBottomCollision(std::vector<Mushroom> &mushrooms)
{
	Goomba tempG = Goomba(0, 0,0);
	KoopaTroopa tempK = KoopaTroopa(0, 0,0);
	PiranhaPlant tempP = PiranhaPlant(0, 0);
	Hole tempH = Hole();
	if (objectX + objectWidth >= blockX && objectX <= blockX + blockWidth
		&& objectY + objectHeight >= blockY && objectY + objectHeight<=blockY + 15.0f)
	{	
		if (typeid(*block).name() == typeid(tempP).name())
		{
			if (block->state != 1) {
				if (object->transformState == 0)
				{
					object->state = 2;
				}
				else
				{
					object->transform();
				}
			}
		}
			if (typeid(*block).name() == typeid(tempG).name())
			{
				block->state=1;
			}
			if (typeid(*block).name() == typeid(tempK).name())
			{
				block->state=1;
			}
			if (typeid(*block).name() == typeid(tempH).name())
			{
				object->state = 2;
			}
			object->getShape().setPosition(objectX, blockY + objectHeight+2.0f);
			object->canFall = false;
			object->canJump = true;
			object->velocityY = 0.0f;
			if (block->activeExtra)
			{
				if (object->transformState == 0)
				{
					object->transform();
				}
				block->activeExtra = false;
				mushrooms.pop_back();
			}
	}
	
}

void Collision::checkTopCollision(std::vector<Mushroom> &mushrooms)
{
	if (objectX + objectWidth >= blockX && objectX <= blockX + blockWidth
		&& objectY <= blockY+blockHeight && objectY >= blockY + blockHeight-15.0f)
	{
		object->getShape().setPosition(objectX, blockY - blockHeight);
		object->canFall = true;
		object->canJump = false;
		object->isJump = false;
		object->velocityY = 0.0f;
		if (block->extra)
		{
			block->extra = false;
			block->activeExtra = true;
		}
		if (block->activeExtra)
		{
			Mushroom mushroom = Mushroom(blockX, blockY);
			mushrooms.push_back(mushroom);
		}
	}
}

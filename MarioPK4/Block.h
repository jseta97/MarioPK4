#pragma once
#include "GraphicalObject.h"
class Block : public GraphicalObject
{
public:
	Block();
	Block(float x, float y, float width, float height,bool extra=false);
};
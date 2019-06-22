#pragma once
#include <SFML/Graphics.hpp>
class GraphicalObject
{
public:
	float height;
	float width;
	bool canRight = true;
	bool canLeft = true;
	bool canJump = true;
	bool canFall = false;
	bool isJump = false;
	int direction = 0;
	float velocity = 0.0f;
	float velocityY = 0.0f;
	float floor = 400.0f;
	bool extra = false;
	int state=0;
	int transformState = 0;
	bool activeExtra = false;
	sf::RectangleShape shape;
	sf::Texture texture;
	sf::RectangleShape getShape() { return shape; }
	void setState(int state);
	int getState();
	virtual void transform();
	virtual void draw(sf::RenderWindow &window);
	virtual void setX(float x);
	virtual void setY(float y);
	virtual float getX();
	virtual float getY();
	virtual void updatePosition();
	
};
#include "Mario.h"

#define JUMP 0
#define ALIVE 1
#define DEAD 2
#define WALK_R 3
#define WALK_L 4
#define END 5
Mario::Mario()
{
	init();
}

void Mario::init()
{
	texture.loadFromFile("C:/Users/jseta/source/repos/MarioPK4/marioassets.png");
	superTexture.loadFromFile("C:/Users/jseta/source/repos/MarioPK4/supermarioassets.png");
	width = texture.getSize().x / 3;
	height = texture.getSize().y / 5;
	shape = sf::RectangleShape(sf::Vector2f(width, height));
	shape.setTexture(&texture);
	shape.setPosition(0.0f, floor-height);
	velocity = 250.0f;
	animation=Animation(&texture, sf::Vector2u(3, 5), 0.05f);
	deltaTime = clock.restart().asSeconds();
	animation.Update(state, deltaTime);
	shape.setTextureRect(animation.uvRect);
	
}

void Mario::transform()
{
	if (transformState == 0)
	{
		
		width = superTexture.getSize().x / 3;
		height = superTexture.getSize().y / 5;
		shape.setSize(sf::Vector2f(width, height));
		//shape = sf::RectangleShape(sf::Vector2f(width, height));
		shape.setTexture(&superTexture);
		setY(getY() - height);
		animation = Animation(&superTexture, sf::Vector2u(3, 5), 0.05f);
		transformState = 1;
	}
	else
	{
		width = texture.getSize().x / 3;
		height = texture.getSize().y / 5;
		shape.setSize(sf::Vector2f(width, height));
		//shape = sf::RectangleShape(sf::Vector2f(width, height));
		shape.setTexture(&texture);
		setY(getY() - height);
		animation = Animation(&texture, sf::Vector2u(3, 5), 0.05f);
		transformState = 0;
	}
}






void Mario::updatePosition()
{
	deltaTime = clock.restart().asSeconds();
	sf::Vector2f movement(0.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && canLeft)
	{
		movement.x -= velocity * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && canRight)
	{
		movement.x += velocity * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
	{
		velocity = 400;
	}
	else
	{
		velocity = 250.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && canJump)
	{
		canJump = false;
		isJump = true;
		velocityY = 0.0f;
	}
	if (movement.x == 0.0f)
	{
		state = ALIVE;
	}
	else if (movement.x > 0.0f)
	{
		state = WALK_R;
	}
	else
	{
		state = WALK_L;
	}
	
	if (isJump)
	{
		if (velocityY <= 100.0f)
		{
			velocityY += 10.0f;
			movement.y -= 15.0f;
		}
		else
		{
			velocityY = 0.0f;
			canFall = true;
			isJump = false;
		}
	}
	if (canFall)
	{
		if (shape.getPosition().y + shape.getSize().y >= floor)
		{
			canFall = false;
			canJump = true;
			isJump = false;
			velocityY = 0.0f;
			setY(floor - shape.getSize().y);
		}
		else
		{
			//velocityY += 0.2;
			//movement.y += velocityY;
			movement.y += 7.0f;
		}

	}
	animation.Update(state, deltaTime);
	shape.setTextureRect(animation.uvRect);
	shape.move(movement);
}

float Mario::getX()
{
	return shape.getPosition().x;
}

float Mario::getY()
{
	return shape.getPosition().y;
}

void Mario::setX(float x)
{
	shape.setPosition(x, this->getY());
}

void Mario::setY(float y)
{
	float a = this->getX();
	shape.setPosition(this->getX(), y);
}




void Mario::draw(sf::RenderWindow & window)
{
	window.draw(shape);
}

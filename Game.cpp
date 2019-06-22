#include "Game.h"

#define DEAD 2
#define FINISH 5

using namespace std; 
void Game::checkCollisions(GraphicalObject * mario)
{
	mario->canLeft = true;
	mario->canRight = true;
	if (mario->isJump)
	{
		mario->canFall = false;
	}
	else
	{
		mario->canFall = true;
	}
	for (auto it = enemies.begin(); it != enemies.end(); it++)
	{
		Collision(mario, (*it).get()).checkCollision(mushrooms);
	}

	for (auto it = obstacles.begin(); it != obstacles.end(); it++)
	{
		Collision(mario, (*it).get()).checkCollision(mushrooms);
	}
	if (mario->getState() != DEAD && mario->getState() != FINISH)
	{
		mario->updatePosition();
	}
}

void Game::drawObjects(sf::RenderWindow & window, GraphicalObject * mario, sf::View & view, sf::Sprite & background)
{
	window.clear();
	window.setView(view);

	window.draw(background);
	for (auto it = mushrooms.begin(); it != mushrooms.end(); it++)
	{
		Mushroom mush = Mushroom((*it).shape.getPosition().x,
			(*it).shape.getPosition().y + (*it).shape.getSize().y);
		mush.draw(window);
	}
	mario->draw(window);
	for (auto it = enemies.begin(); it != enemies.end(); it++)
	{
		(*(*it).get()).draw(window);
	}
	window.display();
}

void Game::newGame(sf::Event & event, sf::RenderWindow & window, GraphicalObject * mario)
{
	if (event.type == sf::Event::Closed)
		window.close();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		window.close();
	}
	if ((mario->getState() == 5 || mario->getState() == 2) && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		mario->setState(1);
		mario->setX(0);
		mario->setY(mario->floor - mario->height);
		mario->transformState = 0;
		enemies.clear();
		obstacles.clear();
		mushrooms.clear();
		createEnemies();
		createObstacles();
	}
}

void Game::createBackground(sf::Texture & backgroundTexture, sf::Sprite & background)
{
	backgroundTexture.loadFromFile("C:/Users/jseta/source/repos/MarioPK4/world1.png");
	background.setTexture(backgroundTexture);
	background.setPosition(0, 0);
	background.scale(2, 2);
}

void Game::createFont(sf::Font & font, sf::Text & text)
{
	if (font.loadFromFile("C:/Users/jseta/source/repos/MarioPK4/arial.ttf")==1)
	{
		text.setFont(font);
		text.setCharacterSize(48);
		text.setPosition(350, 200);
		text.setFillColor(sf::Color::Red);
	}
	
}

void Game::setView(sf::View& view, GraphicalObject * mario)
{
	if (mario->getX() < 400.0f)
	{
		view.setCenter(sf::Vector2f(400, 223));
	}
	else
	{
		view.setCenter(sf::Vector2f(mario->getX(), 223));
	}
}

void Game::drawText(sf::Text & text, sf::RenderWindow & window, GraphicalObject * mario)
{
	if (mario->getX() < 400.0f)
		text.setPosition(sf::Vector2f(400 - 50, 200));
	else
		text.setPosition(sf::Vector2f(mario->getX() - 50, 200));
	window.clear();
	if (mario->getState() == 2)
	{
		text.setString("Dead");
	}
	if (mario->getState() == 5)
	{
		text.setString("Finish");
	}
	window.draw(text);
	window.display();
}

void Game::createObstacles()
{
	string x, y, w, h;
	fstream file;

	file.open("C:/Users/jseta/source/repos/MarioPK4/obstacles.txt", ios::in);
	if (file.good() == true)
	{
		for (int i = 0; i < 5; i++)
		{
			file >> x;
			file >> y;
			file >> w;
			file >> h;
			obstacles.push_back(std::shared_ptr<GraphicalObject>((new Block(stoi(x) * 2, stoi(y) * 2, stoi(w), stoi(h), true))));

		}
		for (int i = 0; i < 100; i++)
		{
			file >> x;
			file >> y;
			file >> w;
			file >> h;
			obstacles.push_back(std::shared_ptr<GraphicalObject>((new Block(stoi(x) * 2, stoi(y) * 2, stoi(w), stoi(h)))));

		}
		for (int i = 0; i < 3; i++)
		{
			file >> x;
			file >> y;
			file >> w;
			file >> h;
			obstacles.push_back(std::shared_ptr<GraphicalObject>((new Hole(stoi(x) * 2, stoi(y) * 2, stoi(w), stoi(h)))));

		}
		file >> x;
		file >> y;
		file >> w;
		file >> h;
		obstacles.push_back(std::shared_ptr<GraphicalObject>((new FinishHole(stoi(x) * 2, stoi(y) * 2, stoi(w), stoi(h)))));
		file.close();
	}

}

void Game::createEnemies()
{

	string x,y,z;
	fstream file;

	file.open("C:/Users/jseta/source/repos/MarioPK4/enemies.txt", ios::in);
	if (file.good() == true)
	{
		for (int i = 0; i < 5; i++)
		{
			file >> x;
			file >> y;
			file >> z;
			enemies.push_back(std::shared_ptr<GraphicalObject>((new Goomba(stoi(x) * 2, stoi(y) * 2, stoi(z) * 2))));
			
		}
		for (int i = 0; i < 5; i++)
		{
			file >> x;
			file >> y;
			file >> z;
			enemies.push_back(std::shared_ptr<GraphicalObject>((new KoopaTroopa(stoi(x) * 2, stoi(y) * 2, stoi(z) * 2))));

		}
		for (int i = 0; i < 3; i++)
		{
			file >> x;
			file >> y;
			enemies.push_back(std::shared_ptr<GraphicalObject>((new PiranhaPlant(stoi(x) * 2, stoi(y) * 2))));

		}
		file.close();
	}
}

void Game::start()
{
	{
		sf::RenderWindow window(sf::VideoMode(800, 446), "Malario!");
		window.setVerticalSyncEnabled(true);
		window.setFramerateLimit(30);
		sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(800, 446));
		Mario marioObject = Mario();
		GraphicalObject *mario = &marioObject;
		sf::Texture backgroundTexture;
		sf::Sprite background;
		createBackground(backgroundTexture, background);
		sf::Font font;
		sf::Text text;
		createFont(font, text);
		createObstacles();
		createEnemies();
		while (window.isOpen())
		{
			
			sf::Event event;
			while (window.pollEvent(event))
			{
				newGame(event,window,mario);
			}
			if (mario->getState() != DEAD && mario->getState() != FINISH)
			{
			checkCollisions(mario);
			setView(view, mario);
			drawObjects(window, mario, view, background);
			}
			else
			{
				drawText(text, window, mario);
			}
		}
	}
}



#include <iostream>
#include <SFML/Graphics.hpp>
#include "Mario.h"
#include "Goomba.h"
#include "KoopaTroopa.h"
#include "PiranhaPlant.h"
#include "Animation.h"
#include "Collision.h"
#include "Block.h"
#include "Hole.h"
#include "FinishHole.h"
#include "Mushroom.h"
#include <vector>
#include <crtdbg.h>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;


class Game
{
public:
	vector<std::shared_ptr<GraphicalObject>> obstacles;
	vector<std::shared_ptr<GraphicalObject>> enemies;
	vector<Mushroom>mushrooms;
	
	void checkCollisions(GraphicalObject * mario);
	void drawObjects(sf::RenderWindow& window, GraphicalObject * mario, sf::View& view, sf::Sprite& background);
	void createObstacles();
	void createEnemies();
	void start();
	void newGame(sf::Event& event, sf::RenderWindow& window, GraphicalObject * mario);
	void createBackground(sf::Texture& backgroundTexture, sf::Sprite& background);
	void createFont(sf::Font& font, sf::Text& text);
	void setView(sf::View& view, GraphicalObject * mario);
	void drawText(sf::Text& text, sf::RenderWindow& window, GraphicalObject * mario);
};
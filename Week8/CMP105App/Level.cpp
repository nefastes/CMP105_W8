#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ballTex.loadFromFile("gfx/Beach_Ball.png");

	ball1.setTexture(&ballTex);
	ball1.setSize(sf::Vector2f(64.f, 64.f));
	ball1.setOrigin(sf::Vector2f(ball1.getSize().x / 2, ball1.getSize().y / 2));
	ball1.setPosition(0 + ball1.getSize().x, window->getSize().y / 2);
	ball1.setVelocity(sf::Vector2f(1.f, 0));
	ball1.setWindow(window);

	ball2.setTexture(&ballTex);
	ball2.setSize(sf::Vector2f(64.f, 64.f));
	ball2.setOrigin(sf::Vector2f(ball2.getSize().x / 2, ball2.getSize().y / 2));
	ball2.setPosition(window->getSize().x - ball2.getSize().x, window->getSize().y/2);
	ball2.setVelocity(sf::Vector2f(-1.f, 0));
	ball2.setWindow(window);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	ball1.update(dt);
	ball2.update(dt);
	if (Collision::checkBoundingCircle(&ball1, &ball2))
	{
		ball1.collisionResponse(NULL);
		ball2.collisionResponse(NULL);
	}
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ball1);
	window->draw(ball2);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}
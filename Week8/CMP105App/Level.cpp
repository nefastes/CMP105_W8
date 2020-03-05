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
	ball1.setVelocity(sf::Vector2f(100.f, 0));
	ball1.setWindow(window);

	ball2.setTexture(&ballTex);
	ball2.setSize(sf::Vector2f(64.f, 64.f));
	ball2.setOrigin(sf::Vector2f(ball2.getSize().x / 2, ball2.getSize().y / 2));
	ball2.setPosition(window->getSize().x - ball2.getSize().x, window->getSize().y/2);
	ball2.setVelocity(sf::Vector2f(-100.f, 0));
	ball2.setWindow(window);

	goombaTex.loadFromFile("gfx/Goomba.png");
	mushTex.loadFromFile("gfx/Mushroom.png");

	goomba1.setTexture(&goombaTex);
	goomba1.setSize(sf::Vector2f(64.f, 64.f));
	goomba1.setOrigin(sf::Vector2f(goomba1.getSize().x / 2, goomba1.getSize().y / 3));
	goomba1.setPosition(0 + goomba1.getSize().x/2, window->getSize().y / 3);
	goomba1.setVelocity(sf::Vector2f(100.f, 0));
	goomba1.setWindow(window);
	goomba1.setCollisionBox(sf::FloatRect(-goomba1.getSize().x / 2, -goomba1.getSize().y / 2, goomba1.getSize().x, goomba1.getSize().y));

	goomba2.setTexture(&mushTex);
	goomba2.setSize(sf::Vector2f(64.f, 64.f));
	goomba2.setOrigin(sf::Vector2f(goomba2.getSize().x / 2, goomba2.getSize().y / 3));
	goomba2.setPosition(window->getSize().x - goomba2.getSize().x/2, window->getSize().y / 3);
	goomba2.setVelocity(sf::Vector2f(-100.f, 0));
	goomba2.setWindow(window);
	goomba2.setCollisionBox(sf::FloatRect(-goomba2.getSize().x / 2, -goomba2.getSize().y / 2, goomba2.getSize().x, goomba2.getSize().y));
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
	goomba1.update(dt);
	goomba2.update(dt);
	if (Collision::checkBoundingBox(&goomba1, &goomba2))
	{
		goomba1.collisionResponse(NULL);
		goomba2.collisionResponse(NULL);
	}
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
	window->draw(goomba1);
	window->draw(goomba2);
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
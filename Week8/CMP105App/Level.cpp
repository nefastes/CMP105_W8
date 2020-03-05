#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	/*
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
	*/
	bar1.setSize(sf::Vector2f(30.f, 120.f));
	bar1.setFillColor(sf::Color::Red);
	bar1.setOrigin(sf::Vector2f(bar1.getSize().x / 2, bar1.getSize().y / 2));
	bar1.setPosition(sf::Vector2f(0 + bar1.getSize().x, window->getSize().y / 2));
	bar1.setVelocity(sf::Vector2f(0, 300.f));
	bar1.setCollisionBox(sf::FloatRect(0, 0, bar1.getSize().x, bar1.getSize().y));
	bar1.setWindow(window);
	bar1.setInput(input);
	bar1.setPlayerMode(1);

	bar2.setSize(sf::Vector2f(30.f, 120.f));
	bar2.setFillColor(sf::Color::Red);
	bar2.setOrigin(sf::Vector2f(bar2.getSize().x / 2, bar2.getSize().y / 2));
	bar2.setPosition(sf::Vector2f(window->getSize().x - bar2.getSize().x, window->getSize().y / 2));
	bar2.setVelocity(sf::Vector2f(0, 300.f));
	bar2.setCollisionBox(sf::FloatRect(0, 0, bar2.getSize().x, bar2.getSize().y));
	bar2.setWindow(window);
	bar2.setInput(input);
	bar2.setPlayerMode(2);

	ballTex.loadFromFile("gfx/Beach_Ball.png");
	pongBall.setTexture(&ballTex);
	pongBall.setSize(sf::Vector2f(64.f, 64.f));
	pongBall.setOrigin(sf::Vector2f(pongBall.getSize().x / 2, pongBall.getSize().y / 2));
	pongBall.setPosition(window->getSize().x / 2, window->getSize().y / 2);
	pongBall.setCollisionBox(0, 0, pongBall.getSize().x, pongBall.getSize().y);
	rng = rand() % 4;
	rngSpeedY = rand() % 500 + 1;
	pongBall.setVelocity(sf::Vector2f(500.f, rngSpeedY));
	if (rng == 1) pongBall.setVelocity(pongBall.getVelocity().x * -1.f, pongBall.getVelocity().y);
	if (rng == 2) pongBall.setVelocity(pongBall.getVelocity().x, pongBall.getVelocity().y * -1.f);
	if (rng == 2) pongBall.setVelocity(pongBall.getVelocity().x * -1.f, pongBall.getVelocity().y * -1.f);
	pongBall.setWindow(window);

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	bar1.handleInput(dt);
	bar2.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	/*ball1.update(dt);
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
	}*/
	pongBall.update(dt);
	if (Collision::checkBoundingBox(&bar1, &pongBall))
	{
		pongBall.collisionResponse(&bar1);
	}
	if (Collision::checkBoundingBox(&bar2, &pongBall))
	{
		pongBall.collisionResponse(&bar2);
	}
}

// Render level
void Level::render()
{
	beginDraw();
	/*window->draw(ball1);
	window->draw(ball2);
	window->draw(goomba1);
	window->draw(goomba2);*/
	window->draw(bar1);
	window->draw(bar2);
	window->draw(pongBall);
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
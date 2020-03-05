#include "PongBar.h"
#include <iostream>
PongBar::PongBar()
{
	playerMode = 0;
}

PongBar::~PongBar()
{

}

void PongBar::update(float dt)
{

}

void PongBar::handleInput(float dt)
{
	if (playerMode == 1)
	{
		if (input->isKeyDown(sf::Keyboard::W) && getPosition().y > 0 + getSize().y / 2) move(-velocity * dt);
		if (input->isKeyDown(sf::Keyboard::S) && getPosition().y < window->getSize().y - getSize().y / 2) move(velocity * dt);
	}
	else if (playerMode == 2)
	{
		if (input->isKeyDown(sf::Keyboard::Up) && getPosition().y > 0 + getSize().y / 2) move(-velocity * dt);
		if (input->isKeyDown(sf::Keyboard::Down) && getPosition().y < window->getSize().y - getSize().y / 2) move(velocity * dt);
	}
	else std::cout << "No player mode has been set." << std::endl;
}

void PongBar::collisionResponse(GameObject* collider)
{
	velocity *= -1.f;
}

void PongBar::setPlayerMode(int n)
{
	playerMode = n;
}
#include "Goomba.h"
Goomba::Goomba()
{

}

Goomba::~Goomba()
{

}

void Goomba::update(float dt)
{
	if (getPosition().x < 0 + getSize().x / 2)
	{
		setPosition(sf::Vector2f(0 + getSize().x / 2, window->getSize().y / 3));
		velocity.x *= -1.f;
	}
	else if (getPosition().x > window->getSize().x - getSize().x / 2)
	{
		setPosition(sf::Vector2f(window->getSize().x - getSize().x / 2, window->getSize().y / 3));
		velocity.x *= -1.f;
	}
	else move(velocity * dt);
}

void Goomba::collisionResponse(GameObject* collider)
{
	velocity *= -1.f;
}
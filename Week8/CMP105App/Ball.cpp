#include "Ball.h"
Ball::Ball()
{

}

Ball::~Ball()
{

}

void Ball::update(float dt)
{
	if (getPosition().x < 0 + getSize().x/2)
	{
		setPosition(sf::Vector2f(0 + getSize().x/2, window->getSize().y/2));
		velocity.x *= -1.f;
	}
	else if (getPosition().x > window->getSize().x - getSize().x/2)
	{
		setPosition(sf::Vector2f(window->getSize().x - getSize().x/2, window->getSize().y/2));
		velocity.x *= -1.f;
	}
	else move(velocity*dt);
}

void Ball::collisionResponse(GameObject* collider)
{
	velocity.x *= -1.f;
}
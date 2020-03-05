#include "Ball.h"
Ball::Ball()
{

}

Ball::~Ball()
{

}

void Ball::update(float dt)
{
	if (getPosition().x < 0 - getSize().x/2)
	{
		setPosition(sf::Vector2f(window->getSize().x/2, window->getSize().y/2));
		velocity.x *= -1.f;
	}
	else if (getPosition().x > window->getSize().x + getSize().x/2)
	{
		setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2));
		velocity.x *= -1.f;
	}
	else if (getPosition().y < 0 + getSize().y / 2)
	{
		setPosition(sf::Vector2f(getPosition().x, 0 + getSize().y / 2));
		velocity.y *= -1.f/4.f;
	}
	else if (getPosition().y > window->getSize().y - getSize().y / 2)
	{
		setPosition(sf::Vector2f(getPosition().x, window->getSize().y - getSize().y / 2));
		velocity.y *= -1.f;
	}
	else move(velocity * dt);
}

void Ball::collisionResponse(GameObject* collider)
{
	if(velocity.x >= 0) setPosition(sf::Vector2f(collider->getPosition().x - collider->getSize().x / 2 - getSize().x / 2, getPosition().y));
	else if (velocity.x < 0) setPosition(sf::Vector2f(collider->getPosition().x + collider->getSize().x / 2 + getSize().x / 2, getPosition().y));
	velocity.x *= -1.f;
}
#pragma once
#include "Framework/GameObject.h"
#include "Framework/Collision.h"
class Ball : public GameObject
{
private:
	sf::RenderWindow* window;

public:
	Ball();
	~Ball();
	void update(float dt) override;
	void collisionResponse(GameObject* collider);
	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; };
};


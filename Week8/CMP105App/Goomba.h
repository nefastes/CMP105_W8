#pragma once
#include "Framework/GameObject.h"
#include "Framework/Collision.h"
class Goomba : public GameObject
{
private:
	sf::RenderWindow* window;

public:
	Goomba();
	~Goomba();
	void update(float dt) override;
	void collisionResponse(GameObject* collider) override;
	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; };
};


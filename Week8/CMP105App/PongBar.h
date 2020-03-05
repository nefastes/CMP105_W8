#pragma once
#include "Framework/GameObject.h"
#include "Framework/Collision.h"
class PongBar : public GameObject
{
private:
	int playerMode;
	sf::RenderWindow* window;

public:
	PongBar();
	~PongBar();
	void update(float dt) override;
	void handleInput(float dt) override;
	void collisionResponse(GameObject* collider) override;
	void setPlayerMode(int n);
	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; };
};


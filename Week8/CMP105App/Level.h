#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Ball.h"
#include "Goomba.h"
#include "PongBar.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	//GameObjects
	Ball ball1;
	Ball ball2;
	sf::Texture ballTex;

	Goomba goomba1;
	Goomba goomba2;
	sf::Texture goombaTex;
	sf::Texture mushTex;

	PongBar bar1;
	PongBar bar2;
	Ball pongBall;

	//Rng
	int rng;
	int rngSpeedY;
};
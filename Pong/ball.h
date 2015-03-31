#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

#include "globals.h"
#include "paddle.h"

class Ball
{
	private:
		sf::RectangleShape rect;
		float x, y, dx, dy;
	public:
		Ball(float xx, float yy);
		~Ball();

		// Accesors
		float getX() const;
		float getY() const;

		// Mutators
		void setVelocity(sf::Vector2f vel);
		void setX(float xx);
		void setY(float yy);

		// Actions
		void draw(sf::RenderWindow &window);
		void update(sf::Time deltaTime, Paddle* paddles[]);
};

#endif
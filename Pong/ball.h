#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

#include "globals.h"

class Ball
{
	private:
		sf::RectangleShape rect;
		float x, y, dx, dy;
	public:
		Ball(float xx, float yy);
		~Ball();

		// Accesors
		float getY() const;

		// Mutators
		void setVelocity(sf::Vector2f vel);

		// Actions
		void draw(sf::RenderWindow &window);
		void update(sf::Time deltaTime);
};

#endif
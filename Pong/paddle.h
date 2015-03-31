#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>

#include "globals.h"

class Paddle
{
	private:
		sf::RectangleShape rect;
		float x, y;
	public:
		Paddle(float xx, float yy);
		~Paddle();

		// Actions
		virtual void draw(sf::RenderWindow &window);
		virtual void update();
};

#endif
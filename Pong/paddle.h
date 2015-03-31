#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>

#include "globals.h"

class Paddle
{
	private:
		sf::RectangleShape rect;
		float x, y;
		int dir;
	public:
		Paddle(float xx, float yy);
		~Paddle();

		// Mutators
		void setDir(int d);
		void setY(int yy);

		// Actions
		void draw(sf::RenderWindow &window);
		void update(sf::Time deltaTime);
};

#endif
#include "paddle.h"

Paddle::Paddle(float xx, float yy)
{
	// Direction and Position
	dir = 0;
	x = xx;
	y = yy;

	// Size and Origin
	rect.setSize(sf::Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT));
	rect.setOrigin(sf::Vector2f(PADDLE_WIDTH / 2, PADDLE_HEIGHT / 2));

	// Colour
	rect.setFillColor(sf::Color::White);
}

Paddle::~Paddle()
{

}


/* Mutators */
void Paddle::setDir(int d)
{
	dir = d;
}

void Paddle::setY(int yy)
{
	y = yy;
}


/* Actions */
void Paddle::draw(sf::RenderWindow &window)
{
	// Set position
	rect.setPosition(sf::Vector2f(x, y));

	// Draw rect
	window.draw(rect);
}

void Paddle::update(sf::Time deltaTime)
{
	// Update position
	y += (float)((double)dir * (double)PADDLE_SPEED * deltaTime.asMilliseconds());

	if (y + (PADDLE_HEIGHT / 2) > ROOM_HEIGHT) y = ROOM_HEIGHT - (PADDLE_HEIGHT / 2);
}
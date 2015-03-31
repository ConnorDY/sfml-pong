#include "paddle.h"

Paddle::Paddle(float xx, float yy)
{
	// Position
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

void Paddle::draw(sf::RenderWindow &window)
{
	// Set position
	rect.setPosition(sf::Vector2f(x, y));

	// Draw rect
	window.draw(rect);
}

void Paddle::update()
{

}
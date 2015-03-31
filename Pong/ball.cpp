#include "ball.h"

Ball::Ball(float xx, float yy)
{
	// Velocity and Position
	dx = 0;
	dy = 0;

	x = xx;
	y = yy;

	// Size and Origin
	rect.setSize(sf::Vector2f(BALL_WIDTH, BALL_HEIGHT));
	rect.setOrigin(sf::Vector2f(BALL_WIDTH / 2, BALL_HEIGHT / 2));

	// Colour
	rect.setFillColor(sf::Color::White);
}

Ball::~Ball()
{

}


/* Accessors */
float Ball::getY() const
{
	return y;
}


/* Mutators */
void Ball::setVelocity(sf::Vector2f vel)
{
	dx = vel.x;
	dy = vel.y;
}


/* Actions */
void Ball::draw(sf::RenderWindow &window)
{
	// Set position
	rect.setPosition(sf::Vector2f(x, y));

	// Draw rect
	window.draw(rect);
}

void Ball::update(sf::Time deltaTime, Paddle* paddles[])
{
	// Update position
	x += (float)((double)dx * deltaTime.asMilliseconds());
	y += (float)((double)dy * deltaTime.asMilliseconds());

	// Check Collision
	sf::FloatRect rect(x - (BALL_WIDTH / 2), y - (BALL_HEIGHT / 2), BALL_WIDTH, BALL_HEIGHT);

	for (int i = 0; i < 2; i++)
	{
		sf::FloatRect paddle(paddles[i]->getX() - (PADDLE_WIDTH / 2), paddles[i]->getY() - (PADDLE_HEIGHT / 2), PADDLE_WIDTH, PADDLE_HEIGHT);

		if (rect.intersects(paddle))
		{
			float intersectY = paddles[i]->getY() - y;

			if (abs(intersectY) < PADDLE_HEIGHT / 2)
			{
				float angle = (float)((double)intersectY / (PADDLE_HEIGHT / 2) * MAX_ANGLE);

				int dir = 1;
				if (dx < 0) dir = -1;

				dx = (float)((double)-dir * cos(angle) * BALL_SPEED);
				dy = (float)((double)-dir * -sin(angle) * BALL_SPEED);

				std::cout << angle << std::endl;
			}
		}
	}

	if (rect.top < 0 || rect.top + rect.height > ROOM_HEIGHT) dy *= -1;
}
#include "game_state.h"

Game_State::Game_State(StateManager &sM)
	: State(sM)
{
	// Load font
	if (!fnt.loadFromFile("res/Tewi-normal-11.bdf")) std::cout << "Failed to load font!" << std::endl;
	const_cast<sf::Texture&>(fnt.getTexture(11)).setSmooth(false);

	// Score
	lscore = 0;
	rscore = 0;

	// Create paddles
	paddleL = new Paddle(16, ROOM_HEIGHT / 2);
	paddleR = new Paddle(ROOM_WIDTH - 16, ROOM_HEIGHT / 2);

	// Create ball
	ball = new Ball(ROOM_WIDTH / 2, ROOM_HEIGHT / 2);
	ball->setVelocity(sf::Vector2f(-.2f, .05f));
}

Game_State::~Game_State()
{
	delete paddleL, paddleR, ball;
}


/* Actions */
void Game_State::draw(sf::RenderWindow &window)
{
	// Create text
	sf::Text text;
	text.setFont(fnt);
	text.setCharacterSize(11);
	text.setColor(sf::Color::White);

	// Draw Title text
	text.setString("Pong");
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(round(textRect.left + textRect.width / 2.0f), 0);
	text.setPosition(sf::Vector2f(200, 0));
	window.draw(text);

	// Draw Left Score
	text.setString(std::to_string(lscore));
	text.setOrigin(0, 0);
	text.setPosition(sf::Vector2f(3, 0));
	window.draw(text);

	// Draw Right Score
	text.setString(std::to_string(rscore));
	textRect = text.getLocalBounds();
	text.setOrigin(round(textRect.left + textRect.width), 0);
	text.setPosition(sf::Vector2f(ROOM_WIDTH - 3, 0));
	window.draw(text);

	// Draw paddles
	paddleL->draw(window);
	paddleR->draw(window);

	// Draw ball
	ball->draw(window);
}

void Game_State::update(sf::RenderWindow &window, InputHandler &inputHandler)
{
	sf::Time deltaTime = restartClock();
	int dir = 0;

	// Get Input
	sf::Event event;

	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		default:
			break;

		case sf::Event::Closed:
			window.close();
			break;
		}

		// Escape
		if (inputHandler.checkInput(InputHandler::Input::Exit, event))
		{
			window.close();
			return;
		}
	}

	if (inputHandler.checkInput(InputHandler::Input::Up)) dir--;
	if (inputHandler.checkInput(InputHandler::Input::Down)) dir++;

	// Update paddles
	paddleL->setDir(dir);
	
	float dy = ball->getY() - paddleR->getY();
	double maxSpeed = BOT_SPEED * deltaTime.asMilliseconds();

	if (dy < -maxSpeed) dy = -maxSpeed;
	else if (dy > maxSpeed) dy = maxSpeed;

	paddleR->setY(paddleR->getY() + dy);

	paddleL->update(deltaTime);
	paddleR->update(deltaTime);

	// Update ball
	Paddle* paddles[] = {paddleL, paddleR};
	ball->update(deltaTime, paddles);

	// Check if ball has left the screen
	if (ball->getX() < -BALL_WIDTH / 2 || ball->getX() > ROOM_WIDTH + (BALL_WIDTH / 2))
	{
		if (ball->getX() < -BALL_WIDTH / 2) rscore++;
		else lscore++;

		ball->setX(ROOM_WIDTH / 2);
		ball->setY(ROOM_HEIGHT / 2);
		ball->setVelocity(sf::Vector2f(-.2f, .05f));

		paddleL->setY(ROOM_HEIGHT / 2);
		paddleR->setY(ROOM_HEIGHT / 2);
		paddleL->setDir(0);
	}
}
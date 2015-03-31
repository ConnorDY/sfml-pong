#include "game_state.h"

Game_State::Game_State(StateManager &sM)
	: State(sM)
{
	// Load font
	if (!fnt.loadFromFile("res/Tewi-normal-11.bdf")) std::cout << "Failed to load font!" << std::endl;
	const_cast<sf::Texture&>(fnt.getTexture(11)).setSmooth(false);

	// Create paddles
	paddleL = new Paddle(16, ROOM_HEIGHT / 2);
	paddleR = new Paddle(ROOM_WIDTH - 16, ROOM_HEIGHT / 2);

	// Create ball
	ball = new Ball(ROOM_WIDTH / 2, ROOM_HEIGHT / 2);
	ball->setVelocity(sf::Vector2f(.1, .1));
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
	text.setString("Pong");

	// Text colour
	text.setColor(sf::Color::White);

	// Center text
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(round(textRect.left + textRect.width / 2.0f), 0);

	// Set position
	text.setPosition(sf::Vector2f(200, 2));

	// Draw text
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
	paddleR->setY(ball->getY());

	paddleL->update(deltaTime);
	paddleR->update(deltaTime);

	// Update ball
	Paddle* paddles[] = {paddleL, paddleR};
	ball->update(deltaTime, paddles);
}
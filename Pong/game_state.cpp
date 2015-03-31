#include "game_state.h"

Game_State::Game_State(StateManager &sM)
	: State(sM)
{
	// Load Font
	if (!fnt.loadFromFile("res/Tewi-normal-11.bdf")) std::cout << "Failed to load menu font!" << std::endl;
	const_cast<sf::Texture&>(fnt.getTexture(11)).setSmooth(false);
}

Game_State::~Game_State()
{

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
}

void Game_State::update(sf::RenderWindow &window, InputHandler &inputHandler)
{
	restartClock();

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

		// Up
		if (inputHandler.checkInput(InputHandler::Input::Up, event))
		{
			
		}

		// Down
		if (inputHandler.checkInput(InputHandler::Input::Down, event))
		{
			
		}
	}
}
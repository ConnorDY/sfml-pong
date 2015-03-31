#include <SFML/Graphics.hpp>

#include "state_manager.h"

int main()
{
	// Create State Manager
	StateManager stateManager;

	// Create Window
	sf::RenderWindow window(sf::VideoMode(400, 400), "Pong", sf::Style::Close | sf::Style::Titlebar);
	window.setVerticalSyncEnabled(true);

	// Game Loop
	while (window.isOpen())
	{
		// Update State
		stateManager.update(window);

		// Draw the State
		window.clear();
		stateManager.draw(window);
		window.display();
	}

	return 0;
}
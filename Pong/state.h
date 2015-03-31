#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "state_manager.h"

class State
{
	private:
		StateManager &stateManager;
		sf::View view;
		sf::Clock clock;
	public:
		explicit State(StateManager &sm);
		virtual ~State();

		// Accessors
		sf::Clock const& getClock() const;
		StateManager& getStateManager();

		// Actions
		virtual void draw(sf::RenderWindow &window) = 0;
		virtual void update(sf::RenderWindow &window, InputHandler &inputHandler) = 0;
		sf::Time restartClock();
};

#endif
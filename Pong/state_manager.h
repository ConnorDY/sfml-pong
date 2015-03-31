#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <memory>

#include "input_handler.h"

class State;

class StateManager
{
private:
	InputHandler inputHandler;
	std::unique_ptr<State> currentState;
public:
	StateManager();
	~StateManager();

	// Actions
	void draw(sf::RenderWindow &window);
	void update(sf::RenderWindow &window);
	void setState(std::unique_ptr<State> state);
};

#endif
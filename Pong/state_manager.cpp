#include "state_manager.h"

#include "game_state.h"

StateManager::StateManager()
	: currentState(new Game_State(*this))
{
}

StateManager::~StateManager()
{
}


/* Actions */
void StateManager::draw(sf::RenderWindow &window)
{
	currentState->draw(window);
}

void StateManager::update(sf::RenderWindow &window)
{
	currentState->update(window, inputHandler);
}

void StateManager::setState(std::unique_ptr<State> state)
{
	currentState = std::move(state);
}
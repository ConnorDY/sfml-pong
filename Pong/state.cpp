#include "state.h"

State::State(StateManager &sm) : stateManager(sm)
{

}

State::~State()
{

}


// Accesors
sf::Clock const& State::getClock() const { return clock; }

StateManager& State::getStateManager()
{
	return stateManager;
}


// Actions
sf::Time State::restartClock()
{
	return clock.restart();
}
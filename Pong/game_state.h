#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <SFML/Audio.hpp>
#include <vector>

#include "state.h"

class Game_State : public State
{
private:
	sf::Font fnt;
public:
	Game_State(StateManager &sM);
	virtual ~Game_State();

	// Actions
	virtual void draw(sf::RenderWindow &window);
	virtual void update(sf::RenderWindow &window, InputHandler &inputHandler);
};

#endif
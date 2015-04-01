#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <vector>

#include "globals.h"
#include "state.h"
#include "paddle.h"
#include "ball.h"

class Game_State : public State
{
	private:
		Paddle *paddleL, *paddleR;
		Ball *ball;
		sf::Font fnt;
		unsigned int lscore, rscore;
	public:
		Game_State(StateManager &sM);
		virtual ~Game_State();

		// Actions
		virtual void draw(sf::RenderWindow &window);
		virtual void update(sf::RenderWindow &window, InputHandler &inputHandler);
};

#endif
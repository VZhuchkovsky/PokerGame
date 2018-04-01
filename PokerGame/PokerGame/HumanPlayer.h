#ifndef __HUMAN_PLAYER__
#define __HUMAN_PLAYER__

#include "Player.h"

class HumanPlayer : public Player {
public:
	HumanPlayer();
	vector<bool> chooseCardsToReturn();
};

#endif __HUMAN_PLAYER__


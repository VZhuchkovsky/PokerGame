#ifndef __AI_PLAYER__
#define __AI_PLAYER__

#include "Player.h"
#include "funcs.h"
#include <algorithm>

#include <iostream>//for testing purpose
using std::cout;//for testing purpose
using std::endl;//for testing purpose

class AIPlayer : public Player {
public:
	AIPlayer();
	vector<bool> chooseCardsToReturn();

private:
	//const int riskRule = ROYAL_FLUSH / 2;//sample
};

#endif __AI_PLAYER__


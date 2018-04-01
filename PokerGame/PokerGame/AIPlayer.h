#ifndef __AI_PLAYER__
#define __AI_PLAYER__

#include "Player.h"

class AIPlayer : public Player {
public:
	AIPlayer();
	vector<bool> chooseCardsToReturn();
};

#endif __AI_PLAYER__


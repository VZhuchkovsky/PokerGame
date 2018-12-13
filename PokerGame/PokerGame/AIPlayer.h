#ifndef __AI_PLAYER__
#define __AI_PLAYER__

#include "Player.h"
#include "funcs.h"

class AIPlayer : public Player {
public:
	AIPlayer(string n);
	vector<unique_ptr<Card>>& getPlayerDiscard() override;
	static int getCurrentName();//get current name index

private:
	bool checked; //if player's deck was already checked on points
	static int currentNameIndex;//current name index from AIPlayerFactory default names

};

#endif __AI_PLAYER__


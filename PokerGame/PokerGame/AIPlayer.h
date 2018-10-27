#ifndef __AI_PLAYER__
#define __AI_PLAYER__

#include "Player.h"
#include "funcs.h"

class AIPlayer : public Player {
public:
	AIPlayer(string n);
	//vector<bool> setCardsToReturn();
	vector<Card>& getPlayerDiscard();

	void setPlayerDeck(vector<Card> c) {
		playerDeck = c;
	};

private:
	//const int riskRule = ROYAL_FLUSH / 2;//sample
	bool checked; //if player's deck was already checked on points
};

#endif __AI_PLAYER__


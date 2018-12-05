#ifndef __HUMAN_PLAYER__
#define __HUMAN_PLAYER__

#include "Player.h"

#include <vector>
using std::vector;

class HumanPlayer : public Player 
{
public:
	HumanPlayer(string n);
	vector<Card>& getPlayerDiscard();
	void setPlayerDiscard(vector<bool> positionsOfReturnedCards);

	/*void setPlayerDeck(vector<Card> c) {
		playerDeck = c;
	};*/
};

#endif __HUMAN_PLAYER__


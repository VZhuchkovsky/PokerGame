#ifndef __PLAYER__
#define __PLAYER__

#include <vector>
#include "Card.h"
using std::vector;

class Player {
public:
	//create Human and UI type of players
	Player();
	vector<Card>& getPlayerDeck();
	vector<Card>& getPlayerDiscard();
	virtual vector<bool> chooseCardsToReturn() = 0;
	void splitTheDeck(vector<bool> positionsOfReturnedCards);
	void show();//test function

private:
	vector<Card> playerDeck;
	vector<Card> playerDiscard;

};

#endif __PLAYER__

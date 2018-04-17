#ifndef __PLAYER__
#define __PLAYER__

#include <vector>
#include "Card.h"
using std::vector;

class Player {
public:
	Player();
	vector<Card>& getPlayerDeck();
	vector<Card>& getPlayerDiscard();
	virtual vector<bool> chooseCardsToReturn() = 0;
	void splitTheDeck(vector<bool> positionsOfReturnedCards);
	void show();//test function
	int getDeckCombination();//get deck's combination, estimated by Croupier
	void setDeckCombination(int c);//set combination points
	int getDeckElderDignity();//get elder card's dignity, estimated by Croupier
	void setDeckElderDignity(int ec);//set elder card's dignity

protected:
	vector<Card> playerDeck;

private:
	vector<Card> playerDiscard;
	int deckCombination;
	int deckElderDignity;

};

#endif __PLAYER__

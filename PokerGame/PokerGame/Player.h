#ifndef __PLAYER__
#define __PLAYER__

#include "Card.h"

#include <vector>
#include <string>
using std::vector;
using std::string;

class Player {
public:
	Player(string n);
	~Player();
	vector<Card>& getPlayerDeck();
	virtual vector<Card>& getPlayerDiscard() = 0;
	string getName();
	//virtual vector<bool> setCardsToReturn() = 0;
	//void splitTheDeck(vector<bool> positionsOfReturnedCards);
	void show();//test function
	int getDeckCombination();//get deck's combination, estimated by Croupier
	void setDeckCombination(int c);//set combination points
	int getDeckElderDignity();//get elder card's dignity, estimated by Croupier
	void setDeckElderDignity(int ec);//set elder card's dignity
	virtual void setPlayerDiscard(vector<bool> positionsOfReturnedCards);//does nothing by default

protected:
	vector<Card> playerDeck;
	vector<Card> playerDiscard;

private:
	int deckCombination;
	int deckElderDignity;
	string name;

};

#endif __PLAYER__

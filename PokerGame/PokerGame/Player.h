#ifndef __PLAYER__
#define __PLAYER__

#include "Card.h"

#include <vector>
#include <memory>
#include <string>
using std::vector;
using std::unique_ptr;
using std::string;

class Player {
public:
	Player(string n);
	~Player();
	vector<unique_ptr<Card>>& getPlayerDeck();
	virtual vector<unique_ptr<Card>>& getPlayerDiscard() = 0;
	string getName() const;
	int getDeckCombination() const;//get deck's combination, estimated by Croupier
	void setDeckCombination(int c);//set combination points
	int getDeckElderDignity() const;//get elder card's dignity, estimated by Croupier
	void setDeckElderDignity(int ec);//set elder card's dignity
	virtual void setPlayerDiscard(vector<bool> positionsOfReturnedCards);//does nothing by default

protected:
	vector<unique_ptr<Card>> playerDeck;
	vector<unique_ptr<Card>> playerDiscard;

private:
	int deckCombination;
	int deckElderDignity;
	string name;

};

#endif __PLAYER__

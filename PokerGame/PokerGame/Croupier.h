#ifndef __CROUPIER__
#define __CROUPIER__

#include "globals.h"
#include "Player.h"

class Croupier {
public:
	Croupier(gameMode mode);
	void mix(); //randomizing cards' initial places
	void giveCards(Player& player);//fill the player's deck
	void takeCardsBack(Player& player);//return cards discarded by the player to the main deck
	void show();//test function
	void showSize();//test function

private:
	vector<Card> mainDeck;

};

#endif __CROUPIER__

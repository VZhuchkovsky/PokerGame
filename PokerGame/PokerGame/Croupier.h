#ifndef __CROUPIER__
#define __CROUPIER__

#include "globals.h"
#include "funcs.h"
#include "Player.h"

class Croupier {
public:
	Croupier();
	void mix(); //randomizing cards' initial places
	void giveCards(Player& player);//fill the player's deck
	void takeCardsBack(Player& player);//return cards discarded by the player to the main deck
	//void show();//test function
	//void showSize();//test function
	void scoring(Player& player);//scoring the player's result and comparing it with current leader
	vector<Player*> getTheLeader();

private:
	vector<Card> mainDeck;
	vector<Player*> currentLeader;//points to the player with currently highest score
	//the reason of using vector of pointers is that there can be 4 potentional players
	//with a same score.

};

#endif __CROUPIER__

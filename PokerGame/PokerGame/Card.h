#ifndef __CARD__
#define __CARD__

#include "globals.h"

class Card {

public:
	//Card();
	Card(cardDignity d, cardSuit s);
	void show();//test function
	cardDignity getCardDignity();
	cardSuit getCardSuit();
	bool operator < (const Card& d) const;//to sort vector<Card> by dignity

private:
	cardDignity dignity;
	cardSuit suit;

};

#endif __CARD__
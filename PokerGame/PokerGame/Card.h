#ifndef __CARD__
#define __CARD__

#include "globals.h"

class Card 
{
public:
	Card(cardDignity d, cardSuit s);
	~Card();
	//void show();//test function
	cardDignity getCardDignity() const;
	cardSuit getCardSuit() const;
	bool operator < (const Card& d) const;//to sort vector<Card> by dignity

private:
	cardDignity dignity;
	cardSuit suit;

};

#endif __CARD__
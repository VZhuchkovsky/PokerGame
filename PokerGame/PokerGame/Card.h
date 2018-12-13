#ifndef __CARD__
#define __CARD__

#include "globals.h"

class Card 
{
public:
	Card(cardDignity d, cardSuit s);
	~Card();
	cardDignity getCardDignity() const;
	cardSuit getCardSuit() const;

private:
	cardDignity dignity;
	cardSuit suit;

};

#endif __CARD__
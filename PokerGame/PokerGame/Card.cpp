#include "Card.h"

Card::Card(cardDignity d, cardSuit s) : dignity(d), suit(s)
{
}

Card::~Card()
{
}

cardDignity Card::getCardDignity() const
{
	return dignity;
}

cardSuit Card::getCardSuit() const
{
	return suit;
}
#include "Card.h"

#include <iostream>
//using std::cout;//for testing purpose
//using std::endl;//for testing purpose

Card::Card(cardDignity d, cardSuit s) : dignity(d), suit(s)
{
	std::cout << "Card " << dignity << " , " << suit << " is created" << std::endl;
}

Card::~Card()
{
	std::cout << "Card " << dignity << " , " << suit << " is deleted" << std::endl;
}

cardDignity Card::getCardDignity() const
{
	return dignity;
}

cardSuit Card::getCardSuit() const
{
	return suit;
}

/*void Card::show() 
{
	std::cout << "Dignity: " << dignity << std::endl;
	std::cout << "Suit: " << suit << std::endl;
}*/

bool Card::operator<(const Card& d) const 
{
	return (dignity < d.dignity);
}
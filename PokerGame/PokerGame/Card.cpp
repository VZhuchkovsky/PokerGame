#include "Card.h"

#include <iostream>
using std::cout;//for testing purpose
using std::endl;//for testing purpose

Card::Card(cardDignity d, cardSuit s) {
	dignity = d;
	suit = s;
}

Card::~Card()
{
	//cout << "Card " << dignity << " , " << suit << " is deleted" << endl;
}

cardDignity Card::getCardDignity() {
	return dignity;
}

cardSuit Card::getCardSuit() {
	return suit;
}

void Card::show() {
	std::cout << "Dignity: " << dignity << std::endl;
	std::cout << "Suit: " << suit << std::endl;
}

bool Card::operator<(const Card& d) const {
	return (dignity < d.dignity);
}
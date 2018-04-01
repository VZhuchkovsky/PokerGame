#include "Card.h"
#include <iostream>

Card::Card(cardDignity d, cardSuit s) {
	dignity = d;
	suit = s;
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
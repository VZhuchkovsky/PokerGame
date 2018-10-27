#include "Player.h"

#include <iostream>
using std::cout;//for testing purpose
using std::endl;//for testing purpose


Player::Player(string n) : name(n) {

	playerDeck.reserve(PLAYER_DECK_SIZE);

}

Player::~Player()
{

	cout << "Player is deleted." << endl;

}

vector<Card>& Player::getPlayerDeck() {
	return playerDeck;
}

/*vector<Card>& Player::getPlayerDiscard() {
	return playerDiscard;
}*/

string Player::getName()
{
	return name;
}

/*void Player::splitTheDeck(vector<bool> positionsOfReturnedCards) {

	//positionsOfReturnedCards = chooseCardsToReturn();

	for (int i = 0; i < positionsOfReturnedCards.size(); i++) {

		if (positionsOfReturnedCards[i]) {

			playerDiscard.push_back(playerDeck[i]);

			playerDeck.erase(playerDeck.begin() + i);

			positionsOfReturnedCards.erase(positionsOfReturnedCards.begin() + i);

			i = 0;

		}

	}

}*/

void Player::show() {
	for (int i = 0; i < playerDeck.size(); i++) {
		playerDeck[i].show();
		std::cout << std::endl;
	}
}

int Player::getDeckCombination() {
	return deckCombination;
}

void Player::setDeckCombination(int c) {
	deckCombination = c;
}

int Player::getDeckElderDignity() {
	return deckElderDignity;
}

void Player::setDeckElderDignity(int ec) {
	deckElderDignity = ec;
}

void Player::setPlayerDiscard(vector<bool> positionsOfReturnedCards){}

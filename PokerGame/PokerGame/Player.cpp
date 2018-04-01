#include "Player.h"
#include <iostream>

Player::Player() {

	playerDeck.reserve(PLAYER_DECK_SIZE);

}

vector<Card>& Player::getPlayerDeck() {
	return playerDeck;
}

vector<Card>& Player::getPlayerDiscard() {
	return playerDiscard;
}

void Player::splitTheDeck(vector<bool> positionsOfReturnedCards) {

	//positionsOfReturnedCards = chooseCardsToReturn();

	for (int i = 0; i < positionsOfReturnedCards.size(); i++) {

		if (positionsOfReturnedCards[i]) {

			playerDiscard.push_back(playerDeck[i]);

			playerDeck.erase(playerDeck.begin() + i);

			positionsOfReturnedCards.erase(positionsOfReturnedCards.begin() + i);

			i = 0;

		}

	}

}

void Player::show() {
	for (int i = 0; i < playerDeck.size(); i++) {
		playerDeck[i].show();
		std::cout << std::endl;
	}
}
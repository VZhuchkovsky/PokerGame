#include "Player.h"


Player::Player(string n) : name(n) {

	playerDeck.reserve(PLAYER_DECK_SIZE);

}

Player::~Player(){}

vector<Card>& Player::getPlayerDeck() {
	return playerDeck;
}

string Player::getName()
{
	return name;
}

/*void Player::show() {
	for (int i = 0; i < playerDeck.size(); i++) {
		playerDeck[i].show();
		std::cout << std::endl;
	}
}*/

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

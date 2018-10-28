#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(string n) : Player(n) {}

vector<Card>& HumanPlayer::getPlayerDiscard(){
	return playerDiscard;
}

void HumanPlayer::setPlayerDiscard(vector<bool> positionsOfReturnedCards){

	for (int i = 0; i < positionsOfReturnedCards.size();) {

		if (positionsOfReturnedCards[i]) {

			playerDiscard.push_back(playerDeck[i]);

			playerDeck.erase(playerDeck.begin() + i);

			positionsOfReturnedCards.erase(positionsOfReturnedCards.begin() + i);

			i = 0;

		}
		else {

			i++;

		}

	}

};


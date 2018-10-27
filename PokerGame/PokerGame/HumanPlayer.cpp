#include "HumanPlayer.h"

//#include <iostream>
//using namespace std;

HumanPlayer::HumanPlayer(string n) : Player(n) {}

vector<Card>& HumanPlayer::getPlayerDiscard(){
	return playerDiscard;
}

void HumanPlayer::setPlayerDiscard(vector<bool> positionsOfReturnedCards){

	//show();
	//cout << endl;

	for (int i = 0; i < positionsOfReturnedCards.size();) {

		//cout << "Position " << i << endl;

		if (positionsOfReturnedCards[i]) {

			//cout << "Position " << i << " is marked" << endl;
			//cout << "Following card will be discarded" << endl;
			//playerDeck[i].show();

			playerDiscard.push_back(playerDeck[i]);

			playerDeck.erase(playerDeck.begin() + i);

			positionsOfReturnedCards.erase(positionsOfReturnedCards.begin() + i);

			//cout << "Current size of pD:" << playerDeck.size() << endl;
			//cout << "Current size of pOR:" <<  positionsOfReturnedCards.size() << endl;

			i = 0;

			//cout << "Final i is " << i << endl;

		}
		else {

			i++;

		}

	}

};


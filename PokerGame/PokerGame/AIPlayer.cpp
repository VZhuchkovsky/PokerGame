#include "AIPlayer.h"


AIPlayer::AIPlayer() : Player() {};

vector<bool> AIPlayer::chooseCardsToReturn() {

	vector<bool> s(PLAYER_DECK_SIZE);//positions of cards to return
									 //false - keep the card, true - discard the card
	//sort(playerDeck.begin(), playerDeck.end());//sort playerDeck by dignity from small to high

	int currentEstimation = estimation(playerDeck)[0];

	//if (currentEstimation < riskRule) {


	if (currentEstimation <= THREE_OF_A_KIND) {


		if (currentEstimation == 0) {//when player's deck has no combination
			
			cout << "currentEstimation == 0" << endl;

			int countSameSuit = 1, countStraight = 1;

			sort(playerDeck.begin(), playerDeck.end(), sortBySuit);//sort playerDeck by Suit

			bool almostFlush = false;//true, if there are 4 cards of the same suit in the deck
			int mostPopularSuit = 0;

			cout << "Entering the flush counting..." << endl;

			for (int i = 0; i < playerDeck.size(); i++) {//counting flush

				if (i != (playerDeck.size() / 2) + 1 && playerDeck[i].getCardSuit() == playerDeck[(playerDeck.size() / 2) + 1].getCardSuit()) {
					//[(playerDeck.size() / 2) + 1] is the position of player's deck middle card
					//AI's strategy works as follows: in player's deck, sorted by suit, if there are 4 cards of the same suit, than
					//middle card's suit will represent the most popular suit in the deck. 
					//P.S.: also it's possible to use same strategy for 3 cards, but this feature is currently inactive.
					++countSameSuit;
				}

			}

			cout << "There are " << countSameSuit << " cards with a same suit." << endl;

			if (countSameSuit == PLAYER_DECK_SIZE - 1) {//if there are 4 cards of the same suit 
														//P.S.: to make it possible to use the AI flush strategy with
														//3 cards make additional condition here.
				almostFlush = true;

				for (int i = 0; i < PLAYER_DECK_SIZE; i++) {

					if (playerDeck[i].getCardSuit() != playerDeck[(playerDeck.size() / 2) + 1].getCardSuit()) {
						//if card has suit, that is different from the most popular in the deck,
						//than mark this card to discard.
						s[i] = true;
						cout << "D: " << playerDeck[i].getCardDignity() << "; S: " << playerDeck[i].getCardSuit() << endl;
					}

				}

			}
			

			if (!almostFlush) {//if there are less than 4 cards of the same suit

				s = { true, true, true , true, true };//mark all cards to discard

				cout << "Entering the straight counting..." << endl;

				sort(playerDeck.begin(), playerDeck.end());//sort playerDeck by Dignity

				for (int i = 1; i < playerDeck.size(); i++) {//counting straight
				//The reason why straight counting cycle works only if almostFlush flag is false is
				//because AI prefer to go for a flush combination rather than straight, because
				//it gives more points and, at the same time, more likely to be collected
				//(in the CLASSIC game mode at least).
					if (playerDeck[i - 1].getCardDignity() == playerDeck[i].getCardDignity() - 1) {
						//if previous card has dignity of the current card - 1, then count straight
						++countStraight;
						//and dismark the cards
						s[i - 1] = s[i] = false;

					}

				}

				if (countStraight != PLAYER_DECK_SIZE - 1) {//if there are less than 4 cards in the deck that make straight

					for (int i = 0; i < s.size(); i++) {//then mark all cards int the deck to discard

						if (!s[i]) {
								s[i] = true;
						}

					}

				}

			}
		}
		else {//when deck certainly contains one of the following combinations:
			  //ONE_PAIR,TWO_PAIRS,THREE_OF_A_KIND

				int countSameDignity = 1;

				for (int i = 0; i < playerDeck.size(); i++) {//searching for cards, that have unique dignity 
															 //in the playerDeck
					for (int j = 0; j < playerDeck.size(); j++) {

						if (i != j && playerDeck[i].getCardDignity() == playerDeck[j].getCardDignity()) {
							++countSameDignity;
						}

					}

					if (countSameDignity == 1) {//if card's dignity is unique in the deck
						s[i] = true;            //mark it as card to return to Croupier
					}

					countSameDignity = 1;

				}

			}


		}

		//}

		cout << endl;
		for (int i = 0; i < s.size(); i++) {
			cout << s[i] << " ";
		}
		cout << endl;


		return s;//sample
	};
#include "funcs.h"
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;

vector<int> estimation(vector<Card> deck) {

	sort(deck.begin(), deck.end());//sort vector<Card> by dignity from small to high

	int countSameDignity = 1, countSameSuit = 1, countStraight = 1;
	vector<int> combinationPoints{ 0,0 }; //points for the deck's combination; 
										  //combinationPoints[0] represents combination of several cards (PAIR, FLUSH and etc.)
										  //combinationPoints[1] represents the elder dignity
	vector<bool> recordedDignityPositions(PLAYER_DECK_SIZE); //to mark cards with a same dignity
	bool onePair = false, secondPair = false, trinity = false, flush = false, straight = false;

	combinationPoints[1] = deck.back().getCardDignity();//last card in sorted deck has elder dignity

	cout << "Elder dignity: " << combinationPoints[1] << endl;

	for (int i = 0; i < deck.size(); i++) {

		if (recordedDignityPositions[i]) {
			continue; //preventing unnecessary iterations
		}
		else {
			recordedDignityPositions[i] = true;
		}


		for (int j = 0; j < deck.size(); j++) {

			if (recordedDignityPositions[j]) {
				continue;
			}

			if (i != j) {

				if (deck[i].getCardDignity() == deck[j].getCardDignity()) {

					recordedDignityPositions[j] = true;

					++countSameDignity;

				}

				if (i == 0 && countSameDignity == 1) {//to prevent unnecessary iterations
												      //(flush and straight cannot exist if the deck already has pair/trinity/four)
						if (deck[i].getCardSuit() == deck[j].getCardSuit()) {//counting flush
							++countSameSuit;

							cout << "Flush count " << countSameSuit << endl;


						}

						if (deck[j - 1].getCardDignity() == deck[j].getCardDignity() - 1) { //counting straight
																							//if previous card has dignity of the current card - 1, then count straight
							++countStraight;

							cout << "Straight count " << countStraight << endl;


						}

				}

			}

		}

		cout << "Iteration " << i << " counts " << countSameDignity << " cards of the same dignity." << endl;

		if (countSameSuit == 5) {
			flush = true;
			combinationPoints[0] = FLUSH;
			cout << "FLUSH" << endl;
			//break;
		}

		if (countStraight == 5) {
			straight = true;
			combinationPoints[0] = STRAIGHT;
			cout << "STRAIGHT" << endl;
			//break;
		}

		if (straight || flush) {

			if (straight && flush) {

				if (deck[PLAYER_DECK_SIZE - 1].getCardDignity() == A) {
					combinationPoints[0] = ROYAL_FLUSH;
					cout << "ROYAL FLUSH" << endl;
					break;
				}
				else {
					combinationPoints[0] = STRAIGHT_FLUSH;
					cout << "STRAIGHT FLUSH" << endl;
					break;
				}

			}
			else {
				break;
			}

		}


		if (countSameDignity == 4) {
			combinationPoints[0] = FOUR_OF_A_KIND;
			cout << "FOUR OF A KIND" << endl;
			break;
		}

		if (countSameDignity == 3) {
			trinity = true;
			combinationPoints[0] = THREE_OF_A_KIND;
			cout << "THREE OF A KIND" << endl;
		}

		if (countSameDignity == 2) {
			if (onePair) { //if the deck already has one pair
				combinationPoints[0] = TWO_PAIRS;
				cout << "TWO PAIRS" << endl;
				break;
				//secondPair = true;
			}
			else {
				onePair = true;
				combinationPoints[0] = ONE_PAIR;
				cout << "ONE PAIR" << endl;
			}
		}

		if (onePair && trinity) {
			combinationPoints[0] = FULL_HOUSE;
			cout << "FULL HOUSE" << endl;
			break;
		}


		countSameDignity = 1;

	}


	/*if (combinationPoints == 0) { //if no combination found

		int maxDignity = 0;

		for (int i = 0; i < deck.size(); i++) {

			if (deck[i].getCardDignity() > maxDignity) {

				maxDignity = deck[i].getCardDignity();

			}

		}

		cout << "NO COMBINATION. GREATEST CARD IS " << maxDignity << endl;

		combinationPoints = maxDignity;

	}*/



	cout << "Marks: ";
	for (int i = 0; i < recordedDignityPositions.size(); i++) {
		cout << recordedDignityPositions[i] << " ";
	}
	cout << endl;

	cout << "countSameDignity is " << countSameDignity << endl;
	cout << "Combination points is " << combinationPoints[0] << endl;

	return combinationPoints;

}

bool sortBySuit(Card c1, Card c2) {

	return (c1.getCardSuit() < c2.getCardSuit());

}

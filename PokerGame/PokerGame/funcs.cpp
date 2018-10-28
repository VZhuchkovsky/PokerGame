#include "funcs.h"

#include <algorithm>

vector<int> estimation(vector<Card> deck) {

	sort(deck.begin(), deck.end());//sort vector<Card> by dignity from small to high

	int countSameDignity = 1, countSameSuit = 1, countStraight = 1;
	vector<int> combinationPoints{ 0,0 }; //points for the deck's combination; 
										  //combinationPoints[0] represents combination of several cards (PAIR, FLUSH and etc.)
										  //combinationPoints[1] represents the elder dignity
	vector<bool> recordedDignityPositions(PLAYER_DECK_SIZE); //to mark cards with a same dignity
	bool onePair = false, secondPair = false, trinity = false, flush = false, straight = false;

	combinationPoints[1] = deck.back().getCardDignity();//last card in sorted deck has elder dignity

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

						}

						if (deck[j - 1].getCardDignity() == deck[j].getCardDignity() - 1) { //counting straight
																							//if previous card has dignity of the current card - 1, then count straight
							++countStraight;

						}

				}

			}

		}

		if (countSameSuit == 5) {
			flush = true;
			combinationPoints[0] = FLUSH;
		}

		if (countStraight == 5) {
			straight = true;
			combinationPoints[0] = STRAIGHT;
		}

		if (straight || flush) {

			if (straight && flush) {

				if (deck[PLAYER_DECK_SIZE - 1].getCardDignity() == A) {
					combinationPoints[0] = ROYAL_FLUSH;
					break;
				}
				else {
					combinationPoints[0] = STRAIGHT_FLUSH;
					break;
				}

			}
			else {
				break;
			}

		}


		if (countSameDignity == 4) {
			combinationPoints[0] = FOUR_OF_A_KIND;
			break;
		}

		if (countSameDignity == 3) {
			trinity = true;
			combinationPoints[0] = THREE_OF_A_KIND;
		}

		if (countSameDignity == 2) {
			if (onePair) { //if the deck already has one pair
				combinationPoints[0] = TWO_PAIRS;
				break;
				//secondPair = true;
			}
			else {
				onePair = true;
				combinationPoints[0] = ONE_PAIR;
			}
		}

		if (onePair && trinity) {
			combinationPoints[0] = FULL_HOUSE;
			break;
		}


		countSameDignity = 1;

	}

	return combinationPoints;

}

bool sortBySuit(Card c1, Card c2) {

	return (c1.getCardSuit() < c2.getCardSuit());

}

const string enumToString(cardDignity c)
{
	switch (c)
	{
	case TWO:    return "2";
	case THREE:  return "3";
	case FOUR:   return "4";
	case FIVE:   return "5";
	case SIX:    return "6";
	case SEVEN:  return "7";
	case EIGHT:  return "8";
	case NINE:   return "9";
	case TEN:    return "10";
	case J:      return "J";
	case Q:      return "Q";
	case K:	     return "K";
	case A:      return "A";
	}
}

const string enumToString(cardSuit c)
{
	switch (c)
	{
	case PEAKS:   return "Peak ";
	case HEARTS:   return "Heart";
	case TAMBOURINES: return "Tamb ";
	case CLUBS:   return "Club ";
	}
}

const string combinationToString(int c)
{
	switch (c)
	{
	case 0: return "No combination";
	case 1:   return "Pair";
	case 2:   return "Two pairs";
	case 3: return "Three of a kind";
	case 4:   return "Straight";
	case 5:   return "Flush";
	case 6: return "Full house";
	case 7:   return "Four of a kind";
	case 8:   return "Straight flush";
	case 9: return "Royal flush";
	}
		
}

const string dignityToString(int c)
{
	switch (c)
	{
	case 0:  return "2";
	case 1:  return "3";
	case 2:  return "4";
	case 3:  return "5";
	case 4:  return "6";
	case 5:  return "7";
	case 6:  return "8";
	case 7:  return "9";
	case 8:  return "10";
	case 9:  return "J";
	case 10: return "Q";
	case 11: return "K";
	case 12: return "A";
	}
}

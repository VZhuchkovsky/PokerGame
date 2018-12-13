#include "funcs.h"

#include <algorithm>
#include <memory>
#include <cassert>

using std::array;

bool sortBySuit(const std::unique_ptr<Card>& c1, const std::unique_ptr<Card>& c2)
{
	return (c1->getCardSuit() < c2->getCardSuit());
}

bool sortByDignity(const std::unique_ptr<Card>& c1, const std::unique_ptr<Card>& c2)
{
	return (c1->getCardDignity() < c2->getCardDignity());
}

bool cardComparison(const std::unique_ptr<Card>& c1, const std::unique_ptr<Card>& c2)
{
	return ((c1->getCardDignity() == c2->getCardDignity()) && (c1->getCardSuit() == c2->getCardSuit()));
}

array<int, 2> estimation(vector<std::unique_ptr<Card>>& deck) {
	
	assert(deck.size() == 5);//additional verification

	sort(deck.begin(), deck.end(), sortByDignity);//sort vector<Card> by dignity from small to high

	int countSameDignity = 1, countSameSuit = 1, countStraight = 1;// , elderCardInCombination = 0;
	array<int, 2> combinationPoints; //points for the deck's combination; 
									 //combinationPoints[0] represents combination of several cards (PAIR, FLUSH and etc.)
									 //combinationPoints[1] represents the elder dignity overall or 
									 //in combination i.e. PAIR, TWO PAIRS, THREE OF A KID, FOUR OF A KIND
	combinationPoints.fill(0);//filling combination point
	vector<bool> recordedDignityPositions(PLAYER_DECK_SIZE); //to mark cards with a same dignity
	bool onePair = false, secondPair = false, trinity = false, flush = false, straight = false;

	for (int i = 0; i < deck.size(); i++)
	{

		if (recordedDignityPositions.at(i))
			continue; //preventing unnecessary iterations
		else
			recordedDignityPositions.at(i) = true;

		for (int j = 0; j < deck.size(); j++)
		{

			if (recordedDignityPositions.at(j))
				continue;

			if (i != j) {

				if (deck.at(i)->getCardDignity() == deck.at(j)->getCardDignity())
				{
					recordedDignityPositions.at(j) = true;
					++countSameDignity;
					//elder dignity in combination
					if (countSameDignity > 1 && deck.at(i)->getCardDignity() > combinationPoints.at(ELDER_DIGNITY))
						combinationPoints.at(ELDER_DIGNITY) = deck.at(i)->getCardDignity();
				}

				if (i == 0 && countSameDignity == 1) {//to prevent unnecessary iterations
													  //(flush and straight cannot exist if the deck already has pair/trinity/four)
					if (deck.at(i)->getCardSuit() == deck.at(j)->getCardSuit()) //counting flush
						++countSameSuit;

					if (deck.at(j - 1)->getCardDignity() == deck.at(j)->getCardDignity() - 1)  //counting straight
						++countStraight; //if previous card has dignity of the current card - 1, then count straight

				}

			}

		}

		if (countSameSuit == 5)
		{
			flush = true;
			combinationPoints.at(COMBINATION) = FLUSH;
		}

		if (countStraight == 5)
		{
			straight = true;
			combinationPoints.at(COMBINATION) = STRAIGHT;
		}

		if (straight || flush)
		{
			//elder dignity in combination
			combinationPoints.at(ELDER_DIGNITY) = deck.back()->getCardDignity();//last card in sorted deck has elder dignity

			if (straight && flush)
			{

				if (deck.at(PLAYER_DECK_SIZE - 1)->getCardDignity() == A)
				{
					combinationPoints.at(COMBINATION) = ROYAL_FLUSH;
					break;
				}
				else
				{
					combinationPoints.at(COMBINATION) = STRAIGHT_FLUSH;
					break;
				}

			}

			else
			{
				break;
			}

		}


		if (countSameDignity == 4)
		{
			combinationPoints.at(COMBINATION) = FOUR_OF_A_KIND;
			break;
		}

		if (countSameDignity == 3)
		{
			trinity = true;
			combinationPoints.at(COMBINATION) = THREE_OF_A_KIND;
		}

		if (countSameDignity == 2) {
			if (onePair) { //if the deck already has one pair
				combinationPoints.at(COMBINATION) = TWO_PAIRS;
				break;
			}
			else
			{
				onePair = true;
				combinationPoints.at(COMBINATION) = ONE_PAIR;
			}
		}

		if (onePair && trinity)
		{
			combinationPoints.at(COMBINATION) = FULL_HOUSE;
			break;
		}

		countSameDignity = 1;

	}

	//if there is no combination in the deck - mark the elder card
	if (!combinationPoints.at(COMBINATION))
		combinationPoints.at(ELDER_DIGNITY) = deck.back()->getCardDignity();//last card in sorted deck has elder dignity

	return combinationPoints;

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

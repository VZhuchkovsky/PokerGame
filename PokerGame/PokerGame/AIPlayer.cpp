#include "AIPlayer.h"

#include <algorithm>


AIPlayer::AIPlayer(string n) : Player(n), checked(false) 
{}

vector<Card>& AIPlayer::getPlayerDiscard() 
{

	if (checked) //if player's deck has already been checked
		return playerDiscard;

	vector<bool> positionsOfReturnedCards(PLAYER_DECK_SIZE);//positions of cards to return
									 //false - keep the card, true - discard the card

	int currentEstimation = estimation(playerDeck).at(0);

	if (currentEstimation <= THREE_OF_A_KIND) 
	{
		//when player's deck has no combination
		if (currentEstimation == 0) 
		{
			int countSameSuit = 1, countStraight = 1;
			sort(playerDeck.begin(), playerDeck.end(), sortBySuit);//sort playerDeck by Suit
			bool almostFlush = false;//true, if there are 4 cards of the same suit in the deck
									 //counting flush
			for (int i = 0; i < playerDeck.size(); i++) 
			{
				//[(playerDeck.size() / 2) + 1] is the position of player's deck middle card
				//AI's strategy works as follows: in player's deck, sorted by suit, if there are 4 cards of the same suit, than
				//middle card's suit will represent the most popular suit in the deck. 
				//P.S.: also it's possible to use same strategy for 3 cards, but this feature is currently inactive.
				if (i != (playerDeck.size() / 2) + 1 && playerDeck.at(i).getCardSuit() == playerDeck.at((playerDeck.size() / 2) + 1).getCardSuit())
					++countSameSuit;
			}

			//if there are 4 cards of the same suit 
			//P.S.: to make it possible to use the AI flush strategy with
			//3 cards make additional condition here.
			if (countSameSuit == PLAYER_DECK_SIZE - 1) 
			{
				almostFlush = true;

				for (int i = 0; i < PLAYER_DECK_SIZE; i++) 
				{
					//if card has suit, that is different from the most popular in the deck,
					//than mark this card to discard.
					if (playerDeck.at(i).getCardSuit() != playerDeck.at((playerDeck.size() / 2) + 1).getCardSuit())
						positionsOfReturnedCards.at(i) = true;
				}

			}

			//if there are less than 4 cards of the same suit
			if (!almostFlush) 
			{
				positionsOfReturnedCards = { true, true, true , true, true };//mark all cards to discard
				sort(playerDeck.begin(), playerDeck.end());//sort playerDeck by Dignity

				//counting straight
				//The reason why straight counting cycle works only if almostFlush flag is false is
				//because AI prefer to go for a flush combination rather than straight, because
				//it gives more points and, at the same time, more likely to be collected
				//(in the CLASSIC game mode at least).
				for (int i = 1; i < playerDeck.size(); i++) 
				{
					//if previous card has dignity of the current card - 1, then count straight
					if (playerDeck.at(i - 1).getCardDignity() == playerDeck.at(i).getCardDignity() - 1)
					{
						++countStraight;
						//and dismark the cards
						positionsOfReturnedCards.at(i - 1) = positionsOfReturnedCards.at(i) = false;
					}
					//to prevent from false counting situation
					//f.e. 3,4,5,Q,K
					else if (countStraight > 1) 
						break;

				}

				//if there are less than 4 cards in the deck that make straight
				if (countStraight != PLAYER_DECK_SIZE - 1) 
				{
					//then mark all cards int the deck to discard
					for (int i = 0; i < positionsOfReturnedCards.size(); i++) 
					{
							positionsOfReturnedCards.at(i) = true;
					}

				}

			}
		}

		//when deck certainly contains one of the following combinations:
		//ONE_PAIR,TWO_PAIRS,THREE_OF_A_KIND
		else 
		{
			int countSameDignity = 1;
			//searching for cards, that have unique dignity 
			//in the playerDeck
			for (int i = 0; i < playerDeck.size(); i++) 
			{
				for (int j = 0; j < playerDeck.size(); j++) 
				{
					if (i != j && playerDeck.at(i).getCardDignity() == playerDeck.at(j).getCardDignity())
						++countSameDignity;
				}
				//if card's dignity is unique in the deck
				if (countSameDignity == 1) 
					positionsOfReturnedCards.at(i) = true; //mark it as card to return to Croupier

				countSameDignity = 1;
			}

		}

	}

	checked = true; // set checked status

	for (int i = 0; i < positionsOfReturnedCards.size();) 
	{

		if (positionsOfReturnedCards.at(i))
		{
			playerDiscard.push_back(playerDeck.at(i));
			playerDeck.erase(playerDeck.begin() + i);
			positionsOfReturnedCards.erase(positionsOfReturnedCards.begin() + i);
			i = 0;
		}
		else
			i++;

	}

	return playerDiscard;
		
}


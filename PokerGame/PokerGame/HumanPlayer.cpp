#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(string n) : Player(n) 
{
}

std::vector<unique_ptr<Card>>& HumanPlayer::getPlayerDiscard()
{
	return playerDiscard;
}

void HumanPlayer::setPlayerDiscard(vector<bool> positionsOfReturnedCards)
{

	for (int i = 0; i < positionsOfReturnedCards.size();) 
	{

		if (positionsOfReturnedCards.at(i)) 
		{
			playerDiscard.emplace_back(move(playerDeck.at(i)));
			playerDeck.erase(playerDeck.begin() + i);
			positionsOfReturnedCards.erase(positionsOfReturnedCards.begin() + i);
			i = 0;
		}
		else 
			i++;
		
	}

};


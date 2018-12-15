#include "Croupier.h"

#include <ctime>
#include <algorithm>
#include <cassert>

Croupier::Croupier() : fullDeckSize(52)
{
	//filling the main deck

	mainDeck.emplace_back(new Card(A, PEAKS));
	mainDeck.emplace_back(new Card(A, HEARTS));
	mainDeck.emplace_back(new Card(A, TAMBOURINES));
	mainDeck.emplace_back(new Card(A, CLUBS));
	mainDeck.emplace_back(new Card(K, PEAKS));
	mainDeck.emplace_back(new Card(K, HEARTS));
	mainDeck.emplace_back(new Card(K, TAMBOURINES));
	mainDeck.emplace_back(new Card(K, CLUBS));
	mainDeck.emplace_back(new Card(Q, PEAKS));
	mainDeck.emplace_back(new Card(Q, HEARTS));
	mainDeck.emplace_back(new Card(Q, TAMBOURINES));
	mainDeck.emplace_back(new Card(Q, CLUBS));
	mainDeck.emplace_back(new Card(J, PEAKS));
	mainDeck.emplace_back(new Card(J, HEARTS));
	mainDeck.emplace_back(new Card(J, TAMBOURINES));
	mainDeck.emplace_back(new Card(J, CLUBS));
	mainDeck.emplace_back(new Card(TEN, PEAKS));
	mainDeck.emplace_back(new Card(TEN, HEARTS));
	mainDeck.emplace_back(new Card(TEN, TAMBOURINES));
	mainDeck.emplace_back(new Card(TEN, CLUBS));
	mainDeck.emplace_back(new Card(NINE, PEAKS));
	mainDeck.emplace_back(new Card(NINE, HEARTS));
	mainDeck.emplace_back(new Card(NINE, TAMBOURINES));
	mainDeck.emplace_back(new Card(NINE, CLUBS));
	mainDeck.emplace_back(new Card(EIGHT, PEAKS));
	mainDeck.emplace_back(new Card(EIGHT, HEARTS));
	mainDeck.emplace_back(new Card(EIGHT, TAMBOURINES));
	mainDeck.emplace_back(new Card(EIGHT, CLUBS));
	mainDeck.emplace_back(new Card(SEVEN, PEAKS));
	mainDeck.emplace_back(new Card(SEVEN, HEARTS));
	mainDeck.emplace_back(new Card(SEVEN, TAMBOURINES));
	mainDeck.emplace_back(new Card(SEVEN, CLUBS));
	mainDeck.emplace_back(new Card(SIX, PEAKS));
	mainDeck.emplace_back(new Card(SIX, HEARTS));
	mainDeck.emplace_back(new Card(SIX, TAMBOURINES));
	mainDeck.emplace_back(new Card(SIX, CLUBS));
	mainDeck.emplace_back(new Card(FIVE, PEAKS));
	mainDeck.emplace_back(new Card(FIVE, HEARTS));
	mainDeck.emplace_back(new Card(FIVE, TAMBOURINES));
	mainDeck.emplace_back(new Card(FIVE, CLUBS));
	mainDeck.emplace_back(new Card(FOUR, PEAKS));
	mainDeck.emplace_back(new Card(FOUR, HEARTS));
	mainDeck.emplace_back(new Card(FOUR, TAMBOURINES));
	mainDeck.emplace_back(new Card(FOUR, CLUBS));
	mainDeck.emplace_back(new Card(THREE, PEAKS));
	mainDeck.emplace_back(new Card(THREE, HEARTS));
	mainDeck.emplace_back(new Card(THREE, TAMBOURINES));
	mainDeck.emplace_back(new Card(THREE, CLUBS));
	mainDeck.emplace_back(new Card(TWO, PEAKS));
	mainDeck.emplace_back(new Card(TWO, HEARTS));
	mainDeck.emplace_back(new Card(TWO, TAMBOURINES));
	mainDeck.emplace_back(new Card(TWO, CLUBS));

	//deck verification
	//sort by dignity
	sort(mainDeck.begin(), mainDeck.end(), sortByDignity);
	//sort by suit
	for (int i = 0; i < mainDeck.size() - 1; i++)
	{
		//if sorted by dignity, but not by suit
		if (mainDeck.at(i)->getCardDignity() == mainDeck.at(i + 1)->getCardDignity() &&
			mainDeck.at(i)->getCardSuit() > mainDeck.at(i + 1)->getCardSuit())
		{
			sort(mainDeck.begin() + i, mainDeck.begin() + (i + 2), sortBySuit);
			i = 0;//restart the cycle from the beginning
		}
	}

	mainDeck.erase(unique(mainDeck.begin(), mainDeck.end(), cardComparison), mainDeck.end());
	
	assert(mainDeck.size() == fullDeckSize);

}

Croupier::~Croupier()
{
}

Croupier & Croupier::getInstance()
{
	static Croupier instance;
	return instance;
}

void Croupier::mix() 
{
	srand(std::time(0));
	random_shuffle(mainDeck.begin(), mainDeck.end());
}

void Croupier::giveCards(Player& player) 
{

	int lack = PLAYER_DECK_SIZE - player.getPlayerDeck().size();

	for (int i = 0; i < lack; i++) 
	{
		player.getPlayerDeck().emplace_back(std::move(mainDeck.front()));
		mainDeck.erase(mainDeck.begin());
	}

}

void Croupier::takeCardsBack(Player& player) 
{

	for (; player.getPlayerDiscard().size();) 
	{
		mainDeck.emplace_back(std::move(player.getPlayerDiscard().front()));
		player.getPlayerDiscard().erase(player.getPlayerDiscard().begin());
	}

}

void Croupier::scoring(Player& player) 
{

	//set deck combination and deck elder dignity of the player according to estimation function 
	player.setDeckCombination(estimation(player.getPlayerDeck()).at(COMBINATION));
	player.setDeckElderDignity(estimation(player.getPlayerDeck()).at(ELDER_DIGNITY));

		if (!currentLeader.size()) //if there are no possible winners yet
			currentLeader.push_back(&player); //set pointer to player
		else 
		{
			//if current leader has lesser combination than current player
			if (currentLeader.front()->getDeckCombination() < player.getDeckCombination()) 
			{
				currentLeader.clear();//if there were more than one previous current leader - erase all pointers
				currentLeader.push_back(&player);//then current player becomes current leader
			}
			//if current leader has equal to current player combination 
			else if (currentLeader.front()->getDeckCombination() == player.getDeckCombination()) 
			{
				//then compare their elder dignity
				//if current leader has lesser elder dignity than current player
				if (currentLeader.front()->getDeckElderDignity() < player.getDeckElderDignity()) 
				{
					currentLeader.clear();//if there were more than one previous current leader - erase all pointers
					currentLeader.push_back(&player);//then current player becomes current leader
				}
				//if current leader and current player are equal
				else if (currentLeader.front()->getDeckElderDignity() == player.getDeckElderDignity()) 
					currentLeader.push_back(&player);

			}

		}


}

vector<Player*> Croupier::getTheLeader() const
{
	return currentLeader;
}

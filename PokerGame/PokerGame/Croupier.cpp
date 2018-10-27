#include "Croupier.h"

#include <iostream>//for testing purpose
#include <ctime>
#include <algorithm>
using std::cout;//for testing purpose
using std::endl;//for testing purpose

Croupier::Croupier() {

	currentLeader = {nullptr, nullptr, nullptr, nullptr };//null pointers

	//filling the main deck
	mainDeck.push_back(Card(A, PEAKS));
	mainDeck.push_back(Card(A, HEARTS));
	mainDeck.push_back(Card(A, TAMBOURINES));
	mainDeck.push_back(Card(A, CLUBS));
	mainDeck.push_back(Card(K, PEAKS));
	mainDeck.push_back(Card(K, HEARTS));
	mainDeck.push_back(Card(K, TAMBOURINES));
	mainDeck.push_back(Card(K, CLUBS));
	mainDeck.push_back(Card(Q, PEAKS));
	mainDeck.push_back(Card(Q, HEARTS));
	mainDeck.push_back(Card(Q, TAMBOURINES));
	mainDeck.push_back(Card(Q, CLUBS));
	mainDeck.push_back(Card(J, PEAKS));
	mainDeck.push_back(Card(J, HEARTS));
	mainDeck.push_back(Card(J, TAMBOURINES));
	mainDeck.push_back(Card(J, CLUBS));
	mainDeck.push_back(Card(TEN, PEAKS));
	mainDeck.push_back(Card(TEN, HEARTS));
	mainDeck.push_back(Card(TEN, TAMBOURINES));
	mainDeck.push_back(Card(TEN, CLUBS));
	mainDeck.push_back(Card(NINE, PEAKS));
	mainDeck.push_back(Card(NINE, HEARTS));
	mainDeck.push_back(Card(NINE, TAMBOURINES));
	mainDeck.push_back(Card(NINE, CLUBS));
	mainDeck.push_back(Card(EIGHT, PEAKS));
	mainDeck.push_back(Card(EIGHT, HEARTS));
	mainDeck.push_back(Card(EIGHT, TAMBOURINES));
	mainDeck.push_back(Card(EIGHT, CLUBS));
	mainDeck.push_back(Card(SEVEN, PEAKS));
	mainDeck.push_back(Card(SEVEN, HEARTS));
	mainDeck.push_back(Card(SEVEN, TAMBOURINES));
	mainDeck.push_back(Card(SEVEN, CLUBS));
	mainDeck.push_back(Card(SIX, PEAKS));
	mainDeck.push_back(Card(SIX, HEARTS));
	mainDeck.push_back(Card(SIX, TAMBOURINES));
	mainDeck.push_back(Card(SIX, CLUBS));
	mainDeck.push_back(Card(FIVE, PEAKS));
	mainDeck.push_back(Card(FIVE, HEARTS));
	mainDeck.push_back(Card(FIVE, TAMBOURINES));
	mainDeck.push_back(Card(FIVE, CLUBS));
	mainDeck.push_back(Card(FOUR, PEAKS));
	mainDeck.push_back(Card(FOUR, HEARTS));
	mainDeck.push_back(Card(FOUR, TAMBOURINES));
	mainDeck.push_back(Card(FOUR, CLUBS));
	mainDeck.push_back(Card(THREE, PEAKS));
	mainDeck.push_back(Card(THREE, HEARTS));
	mainDeck.push_back(Card(THREE, TAMBOURINES));
	mainDeck.push_back(Card(THREE, CLUBS));
	mainDeck.push_back(Card(TWO, PEAKS));
	mainDeck.push_back(Card(TWO, HEARTS));
	mainDeck.push_back(Card(TWO, TAMBOURINES));
	mainDeck.push_back(Card(TWO, CLUBS));
	

}

void Croupier::mix() {
	srand(std::time(0));

	random_shuffle(mainDeck.begin(), mainDeck.end());
}

void Croupier::show() {

	for (int i = 0; i < mainDeck.size(); i++) {
		mainDeck[i].show();
		std::cout << std::endl;
	}

}

void Croupier::showSize() {
	std::cout << "Main deck size is: " << mainDeck.size() << std::endl;
}

void Croupier::giveCards(Player& player) {

	int lack = PLAYER_DECK_SIZE - player.getPlayerDeck().size();

	for (int i = 0; i < lack; i++) {

		player.getPlayerDeck().push_back(mainDeck.back());

		mainDeck.pop_back();

	}

}

void Croupier::takeCardsBack(Player& player) {

	for (; player.getPlayerDiscard().size();) {

		mainDeck.push_back(player.getPlayerDiscard().back());

		player.getPlayerDiscard().pop_back();

	}

}

void Croupier::scoring(Player& player) {

	//set deck combination and deck elder dignity of the player according to estimation function 
	player.setDeckCombination(estimation(player.getPlayerDeck())[0]);
	player.setDeckElderDignity(estimation(player.getPlayerDeck())[1]);

	for (int i = 0; i < currentLeader.size(); i++) {

		if (!currentLeader[i]) {//if it is null pointer
			currentLeader[i] = &player; //set pointer to player
			//cout << "First leader." << endl;
			break;
		}
		else {

			if (currentLeader[i]->getDeckCombination() > player.getDeckCombination()) {//if current leader has greater combination than current player
				//cout << "Current leader remains with " << currentLeader[i]->getDeckCombination() << " points against " << player.getDeckCombination() << endl;
				break;//in this case leader remains
			}
			else if (currentLeader[i]->getDeckCombination() < player.getDeckCombination()) {//if current leader has lesser combination than current player
				//cout << "Current leader loses with " << currentLeader[i]->getDeckCombination() << " points against " << player.getDeckCombination() << endl;
				currentLeader[i] = &player;//then current player becomes current leader

				if (currentLeader[i + 1]) {//if there were more than one previous current leader
					//set all these pointers to null
					for (int j = i + 1; j < currentLeader.size(); j++) {
						currentLeader[j] = 0;
					}

				}

				break;
			}
			else if (currentLeader[i]->getDeckCombination() == player.getDeckCombination()) {//if current leader has equal to current player combination 
				//then compare their elder dignity
				if (currentLeader[i]->getDeckElderDignity() > player.getDeckElderDignity()) {//if current leader has greater elder dignity than current player
					//cout << "Current leader remains with greater dignity, which is " << currentLeader[i]->getDeckElderDignity() << " against " << player.getDeckElderDignity() << endl;
					break;//in this case leader remains
				}
				else if (currentLeader[i]->getDeckElderDignity() < player.getDeckElderDignity()) {//if current leader has lesser elder dignity than current player
					//cout << "Current leader loses with lesser dignity, which is " << currentLeader[i]->getDeckElderDignity() << " against " << player.getDeckElderDignity() << endl;
					currentLeader[i] = &player;//then current player becomes current leader
					break;
				}
				else if (currentLeader[i]->getDeckElderDignity() == player.getDeckElderDignity()) {//if current leader and current player are equal
					//cout << "Current leader and player are equal with: " << currentLeader[i]->getDeckCombination() << " " << player.getDeckCombination() << " and " << currentLeader[i]->getDeckElderDignity() << " " << player.getDeckElderDignity() << endl;
					continue;//then progress to next iteration to set next pointer to current player
				}

			}

		}

	}

	/*cout << "QUANTITY OF CURRENT LEADERS: ";
	int q = 0;
	for (int i = 0; i < currentLeader.size(); i++) {
		if (currentLeader[i]) {
			++q;
		}
	}

	cout << q << endl << endl;*/

}

vector<Player*> Croupier::getTheLeader()
{
	return currentLeader;
}

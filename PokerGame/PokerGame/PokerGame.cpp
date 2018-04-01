// PokerGame.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;


const int PLAYER_DECK_SIZE = 5;

enum gameMode {
	SMALL,
	CLASSIC
};

enum cardDignity { 
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	J,
	Q,
	K,
	A
};

enum cardSuit {
	PEAKS,
	HEARTS,
	TAMBOURINES,
	CLUBS
};

enum combinations {
	ONE_PAIR = A + 1, //if no combination found - assign points for the greatest dignity
	TWO_PAIRS,
	THREE_OF_A_KIND,
	STRAIGHT,
	FLUSH,
	FULL_HOUSE, 
	FOUR_OF_A_KIND,
	STRAIGHT_FLUSH,
	ROYAL_FLUSH
};


//-----class Card-------//
class Card {

public:
	//Card();
	Card(cardDignity d, cardSuit s);
	void show();//test function
	cardDignity getCardDignity();
	cardSuit getCardSuit();
	bool operator < (const Card& d) const;//to sort vector<Card> by dignity

private:
	cardDignity dignity;
	cardSuit suit;

};

//Card::Card() { }

Card::Card(cardDignity d, cardSuit s) {
	dignity = d;
	suit = s;
}

cardDignity Card::getCardDignity() {
	return dignity;
}

cardSuit Card::getCardSuit() {
	return suit;
}

void Card::show() {
	cout << "Dignity: " << dignity << endl;
	cout << "Suit: " << suit << endl;
}

bool Card::operator<(const Card& d) const {
	return (dignity < d.dignity);
}
//-----class Card-------//

//-----class Player-------//
class Player {
public:
	//create Human and UI type of players
	Player();
	vector<Card>& getPlayerDeck();
	vector<Card>& getPlayerDiscard();
	virtual vector<bool> chooseCardsToReturn() = 0;
	void splitTheDeck(vector<bool> positionsOfReturnedCards);
	void show();//test function

private:
	vector<Card> playerDeck;
	vector<Card> playerDiscard;

};

Player::Player() {

	playerDeck.reserve(PLAYER_DECK_SIZE);

}

vector<Card>& Player::getPlayerDeck() {
	return playerDeck;
}

vector<Card>& Player::getPlayerDiscard() {
	return playerDiscard;
}

void Player::splitTheDeck(vector<bool> positionsOfReturnedCards) {

	//positionsOfReturnedCards = chooseCardsToReturn();

	for (int i = 0; i < positionsOfReturnedCards.size(); i++) {

		if (positionsOfReturnedCards[i]) {

			playerDiscard.push_back(playerDeck[i]);

			playerDeck.erase(playerDeck.begin() + i);

			positionsOfReturnedCards.erase(positionsOfReturnedCards.begin() + i);

			i = 0;

		}

	}

}

void Player::show() {
	for (int i = 0; i < playerDeck.size(); i++) {
		playerDeck[i].show();
		cout << endl;
	}
}
//-----class Player-------//

//-----class HumanPlayer-------//

class HumanPlayer : public Player {
public:
	HumanPlayer();
	vector<bool> chooseCardsToReturn();
};

HumanPlayer::HumanPlayer() : Player() {};

vector<bool> HumanPlayer::chooseCardsToReturn() { //sample
	vector<bool> chosenToDiscard = { true, true, false, false, true }; 
	return chosenToDiscard;
}

//-----class HumanPlayer-------//

//-----class AIPlayer-------//

class AIPlayer : public Player {
public:
	AIPlayer();
	vector<bool> chooseCardsToReturn();
};

AIPlayer::AIPlayer() : Player() {};

vector<bool> AIPlayer::chooseCardsToReturn() {};

//-----class AIPlayer-------//

//-----class Сroupier-------//
class Croupier {
public:
	Croupier(gameMode mode);
	void mix(); //randomizing cards' initial places
	void giveCards(Player& player);//fill the player's deck
	void takeCardsBack(Player& player);//return cards discarded by the player to the main deck
	void show();//test function
	void showSize();//test function

private:
	vector<Card> mainDeck;

};

Croupier::Croupier(gameMode mode) {

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
	if (mode == CLASSIC) {
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

}

void Croupier::mix() {
	srand(time(0));

	random_shuffle(mainDeck.begin(), mainDeck.end());
}

void Croupier::show() {

	for (int i = 0; i < mainDeck.size(); i++) {
		mainDeck[i].show();
		cout << endl;
	}

}

void Croupier::showSize() {
	cout << "Main deck size is: " << mainDeck.size() << endl;
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

//-----class Сroupier-------//

//make it a masterpiece
int estimation(vector<Card> v) {

	sort(v.begin(), v.end());//sort vector<Card> by dignity from small to high

	int countSameDignity = 1, countSameSuit = 1, countStraight = 1;
	int combinationPoints = 0; //points for the deck's combination; 0 represents no combination
	vector<bool> recordedDignityPositions(PLAYER_DECK_SIZE); //to mark cards with a same dignity
	bool onePair = false, secondPair = false, trinity = false, flush = false, straight = false;

	for (int i = 0; i < v.size(); i++) {

		if (recordedDignityPositions[i]) {
			continue; //preventing unnecessary iterations
		}
		else {
			recordedDignityPositions[i] = true;
		}


		for (int j = 0; j < v.size(); j++) {
			
			if (recordedDignityPositions[j]) {
				continue;
			}

			if (i != j) {

				if (v[i].getCardDignity() == v[j].getCardDignity()) {

					recordedDignityPositions[j] = true;

					++countSameDignity;

				}

				if (i == 0 && countSameDignity == 1) { //to prevent unnecessary iterations
					                                   //(flush and straight cannot exist if the deck already has pair/trinity/four)
					if (v[i].getCardSuit() == v[j].getCardSuit()) {
						++countSameSuit;

						cout << "Flush count " << countSameSuit << endl;

						
					}

					if (v[j - 1].getCardDignity() == v[j].getCardDignity() - 1) { //mistake
						++countStraight;

						cout << "Straight count " << countStraight << endl;

						
					}

				}	

			}

		}

		cout << "Iteration " << i << " counts " << countSameDignity << " cards of the same dignity." << endl;

		if (countSameSuit == 5) {
			flush = true;
			combinationPoints = FLUSH;
			cout << "FLUSH" << endl;
			//break;
		}

		if (countStraight == 5) {
			straight = true;
			combinationPoints = STRAIGHT;
			cout << "STRAIGHT" << endl;
			//break;
		}

		if (straight || flush) {

			if (straight && flush) {

				if (v[PLAYER_DECK_SIZE - 1].getCardDignity() == A) {
					combinationPoints = ROYAL_FLUSH;
					cout << "ROYAL FLUSH" << endl;
					break;
				}
				else {
					combinationPoints = STRAIGHT_FLUSH;
					cout << "STRAIGHT FLUSH" << endl;
					break;
				}

			}
			else {
				break;
			}

		}


		if (countSameDignity == 4) {
			combinationPoints = FOUR_OF_A_KIND;
			cout << "FOUR OF A KIND" << endl;
			break;
		}

		if (countSameDignity == 3) {
			trinity = true;	
			combinationPoints = THREE_OF_A_KIND;
			cout << "THREE OF A KIND" << endl;
		}

		if (countSameDignity == 2) {
			if (onePair) { //if the deck already has one pair
				combinationPoints = TWO_PAIRS;
				cout << "TWO PAIRS" << endl;
				break;
				//secondPair = true;
			}
			else {
				onePair = true;
				combinationPoints = ONE_PAIR;
				cout << "ONE PAIR" << endl;
			}
		}

		if (onePair && trinity) {
			combinationPoints = FULL_HOUSE;
			cout << "FULL HOUSE" << endl;
			break;
		}


		countSameDignity = 1;

	}		
		

	if (combinationPoints == 0) { //if no combination found

		int maxDignity = 0;

		for (int i = 0; i < v.size(); i++) {
			
			if (v[i].getCardDignity() > maxDignity) {
				
				maxDignity = v[i].getCardDignity();

			}

		}

		cout << "NO COMBINATION. GREATEST CARD IS " << maxDignity << endl;

		combinationPoints = maxDignity;

	}

	

	cout << "Marks: ";
	for (int i = 0; i < recordedDignityPositions.size(); i++) {
		cout << recordedDignityPositions[i] << " ";
	}
	cout << endl;

	cout << "countSameDignity is " << countSameDignity << endl;

	return combinationPoints;

}



int main()
{
	/*Croupier croupier(CLASSIC);
	//cout << "First show: " << endl;
	//croupier.show();
	croupier.mix();
	//cout << "Mixed deck: " << endl;
	//croupier.show();
	croupier.showSize();
	HumanPlayer player;
	//cout << "Given cards: " << endl;
	croupier.giveCards(player);
	cout << "Deck without player's cards: " << endl;
	//croupier.show();
	croupier.showSize();
	cout << "Player's deck: " << endl;
	player.show();
	cout << "Size: " << player.getPlayerDeck().size() << endl;

	vector<bool> b{ true, false, true, true, false };

	player.splitTheDeck(b);

	cout << endl << "Discard: " << endl;
	for (int i = 0; i < player.getPlayerDiscard().size(); i++) {
		cout << "Dignity: " << player.getPlayerDiscard()[i].getCardDignity() << endl;
		cout << "Suit: " << player.getPlayerDiscard()[i].getCardSuit() << endl;
		cout << endl;
	}

	cout << endl << "Another test: " << endl;
	player.show();
	cout << "Current size: " << player.getPlayerDeck().size() << endl;

	croupier.giveCards(player);

	cout << endl << "Player's deck after second giveaway: " << endl;
	player.show();

	croupier.showSize();

	croupier.takeCardsBack(player);

	croupier.showSize();

	cout << endl << "Main deck after discarded cards returned: " << endl;

	croupier.show();

	cout << "Size of player's discard: " << player.getPlayerDiscard().size() << endl;*/
	////////////////////////////////////////////////////////////////////////////////////

	/*vector<Card> v1 = { Card(SIX,CLUBS), Card(SIX,PEAKS), Card(SIX,HEARTS), Card(SIX,TAMBOURINES), Card(SEVEN,CLUBS) };
	cout << "6C, 6P, 6H, 6T, 7C" << endl;
	cout << "Combination points: " << estimation(v1) << endl << endl;

	vector<Card> v2 = { Card(SIX,CLUBS), Card(SIX,PEAKS), Card(SIX,HEARTS), Card(EIGHT,TAMBOURINES), Card(SEVEN,CLUBS) };
	cout << "6C, 6P, 6H, 8T, 7C" << endl;
	cout << "Combination points: " << estimation(v2) << endl << endl;

	vector<Card> v3 = { Card(SIX,CLUBS), Card(SIX,PEAKS), Card(SIX,HEARTS), Card(EIGHT,TAMBOURINES), Card(EIGHT,CLUBS) };
	cout << "6C, 6P, 6H, 8T, 8C" << endl;
	cout << "Combination points: " << estimation(v3) << endl << endl;

	vector<Card> v4 = { Card(SIX,CLUBS), Card(EIGHT,PEAKS), Card(EIGHT,HEARTS), Card(EIGHT,TAMBOURINES), Card(EIGHT,CLUBS) };
	cout << "6C, 8P, 8H, 8T, 8C" << endl;
	cout << "Combination points: " << estimation(v4) << endl << endl;

	vector<Card> v5 = { Card(SIX,CLUBS), Card(EIGHT, PEAKS), Card(SIX,HEARTS), Card(SIX,TAMBOURINES), Card(SIX,PEAKS) };
	cout << "6C, 8P, 6H, 6T, 6P" << endl;
	cout << "Combination points: " << estimation(v5) << endl << endl;

	vector<Card> v6 = { Card(SIX,CLUBS), Card(EIGHT, PEAKS), Card(SIX,HEARTS), Card(SEVEN,TAMBOURINES), Card(SEVEN,PEAKS) };
	cout << "6C, 8P, 6H, 7T, 7P" << endl;
	cout << "Combination points: " << estimation(v6) << endl << endl;

	vector<Card> v7 = { Card(SIX,CLUBS), Card(EIGHT, PEAKS), Card(SIX,HEARTS), Card(SEVEN,TAMBOURINES), Card(FIVE,PEAKS) };
	cout << "6C, 8P, 6H, 7T, 5P" << endl;
	cout << "Combination points: " << estimation(v7) << endl << endl;

	vector<Card> v8 = { Card(SIX,CLUBS), Card(EIGHT, PEAKS), Card(TEN,HEARTS), Card(SEVEN,TAMBOURINES), Card(FIVE,PEAKS) };
	cout << "6C, 8P, 10H, 7T, 5P" << endl;
	cout << "Combination points: " << estimation(v8) << endl << endl;

	vector<Card> v9 = { Card(SIX,CLUBS), Card(EIGHT, PEAKS), Card(NINE,HEARTS), Card(SEVEN,TAMBOURINES), Card(FIVE,PEAKS) };
	cout << "6C, 8P, 9H, 7T, 5P" << endl;
	cout << "Combination points: " << estimation(v9) << endl << endl;

	vector<Card> v10 = { Card(SIX,HEARTS), Card(EIGHT, HEARTS), Card(NINE,HEARTS), Card(SEVEN,HEARTS), Card(FIVE,HEARTS) };
	cout << "6H, 8H, 9H, 7H, 5H" << endl;
	cout << "Combination points: " << estimation(v10) << endl << endl;

	vector<Card> v11 = { Card(SIX,HEARTS), Card(K, HEARTS), Card(NINE,HEARTS), Card(SEVEN,HEARTS), Card(FIVE,HEARTS) };
	cout << "6H, KH, 9H, 7H, 5H" << endl;
	cout << "Combination points: " << estimation(v11) << endl << endl;

	vector<Card> v12 = { Card(Q,HEARTS), Card(K, HEARTS), Card(A,HEARTS), Card(TEN,HEARTS), Card(J,HEARTS) };
	cout << "QH, KH, AH, TH, JH" << endl;
	cout << "Combination points: " << estimation(v12) << endl << endl;

	vector<Card> v13 = { Card(Q,HEARTS), Card(Q, TAMBOURINES), Card(A,HEARTS), Card(TEN,HEARTS), Card(J,HEARTS) };
	cout << "QH, QT, AH, TH, JH" << endl;
	cout << "Combination points: " << estimation(v13) << endl << endl;

	vector<Card> v14 = { Card(EIGHT,HEARTS), Card(SIX, HEARTS), Card(A,HEARTS), Card(TEN,HEARTS), Card(J,HEARTS) };
	cout << "8H, 6H, AH, TH, JH" << endl;
	cout << "Combination points: " << estimation(v14) << endl << endl;*/



	/*for (int i = 0; i < v10.size(); i++) {
		cout << v10[i].getCardDignity() << " ";
	}

	cout << endl;

	sort(v10.begin(), v10.end());

	for (int i = 0; i < v10.size(); i++) {
		cout << v10[i].getCardDignity() << " ";
	}

	cout << endl;

	int sum = 1;

	for (int i = 0; i < PLAYER_DECK_SIZE; i++) {
		cout << "Iteration " << i << endl;
		for (int j = 0; j < PLAYER_DECK_SIZE; j++) {

			if (i == 0 && i != j && v10[j - 1].getCardDignity() == v10[j].getCardDignity() - 1) {
				cout << "Sum++ in " << j << endl;
				++sum;
			}

		}
	}

	cout << "Sum is " << sum << endl;*/



	/*vector<Card> c{Card(SIX,CLUBS), Card(EIGHT, TAMBOURINES), Card(A, CLUBS), Card(SEVEN, HEARTS)};

	for (int i = 0; i < c.size(); i++) {
		cout << c[i].getCardDignity() << " ";
	}
	cout << endl;

	sort(c.begin(), c.end());

	for (int i = 0; i < c.size(); i++) {
		cout << c[i].getCardDignity() << " ";
	}
	cout << endl;*/



	//vector<Card> c;

	//int count = 0;

	/*for (int i = 0; i < b.size(); i++) {
	cout << b[i] << " ";
	}*/

	//cout << endl;
	//works
	/*for (int i = 0; i < player.getPlayerDeck().size(); i++) {

	if (b[i]) {

	cout << "Position is " << i << endl;

	c.push_back(player.getPlayerDeck()[i]);

	player.getPlayerDeck().erase(player.getPlayerDeck().begin() + i);

	b.erase(b.begin() + i);

	++count;

	i = 0;

	}

	}*/


	//cout << "Test: " << endl;

	//cout << "Count - " << count << endl;

	/*for (int i = 0; i < c.size(); i++) {
	cout << "Dignity: " << c[i].getCardDignity() << endl;
	cout << "Suit: " << c[i].getCardSuit() << endl;
	}*/

	//player.getPlayerDeck().erase(player.getPlayerDeck().begin() + 1);

	/*vector<Card> tempDeck;
	for (int i = 0; i < PLAYER_DECK_SIZE; i++) {
	tempDeck.push_back(Card(SIX, CLUBS));
	}

	player.setPlayerDeck(tempDeck);

	cout << "Size: " << player.getPlayerDeck().size() << endl;*/

	system("pause");
	return 0;
}

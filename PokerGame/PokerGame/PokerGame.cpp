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
	A,
	K,
	Q,
	J,
	TEN,
	NINE,
	EIGHT,
	SEVEN,
	SIX,
	FIVE,
	FOUR,
	THREE,
	TWO
};

enum cardSuit {
	PEAKS,
	HEARTS,
	TAMBOURINES,
	CLUBS
};

enum combinations {
	NO_HAND,
	ONE_PAIR,
	TWO_PAIRS,
	THREE_OF_A_KIND,
	STRAIGHT,
	FLUSH,
	FULL_HOUSE, FOUR_OF_A_KIND,
	STRAIGHT_FLUSH,
	ROYAL_FLUSH
};


//-----class Card-------//
class Card {

public:
	Card(cardDignity d, cardSuit s);
	void show();//test function
	cardDignity getCardDignity();
	cardSuit getCardSuit();

private:
	cardDignity dignity;
	cardSuit suit;

};

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
//-----class Card-------//

//-----class Deck-------//
/*class Deck {
public:
Deck(deckSize size);
vector<Card> getDeck();

private:
vector<Card> deck;
};

Deck::Deck(deckSize size) {
deck.push_back(Card(A, PEAKS));
deck.push_back(Card(A, HEARTS));
deck.push_back(Card(A, TAMBOURINES));
deck.push_back(Card(A, CLUBS));
deck.push_back(Card(K, PEAKS));
deck.push_back(Card(K, HEARTS));
deck.push_back(Card(K, TAMBOURINES));
deck.push_back(Card(K, CLUBS));
deck.push_back(Card(Q, PEAKS));
deck.push_back(Card(Q, HEARTS));
deck.push_back(Card(Q, TAMBOURINES));
deck.push_back(Card(Q, CLUBS));
deck.push_back(Card(J, PEAKS));
deck.push_back(Card(J, HEARTS));
deck.push_back(Card(J, TAMBOURINES));
deck.push_back(Card(J, CLUBS));
deck.push_back(Card(TEN, PEAKS));
deck.push_back(Card(TEN, HEARTS));
deck.push_back(Card(TEN, TAMBOURINES));
deck.push_back(Card(TEN, CLUBS));
deck.push_back(Card(NINE, PEAKS));
deck.push_back(Card(NINE, HEARTS));
deck.push_back(Card(NINE, TAMBOURINES));
deck.push_back(Card(NINE, CLUBS));
deck.push_back(Card(EIGHT, PEAKS));
deck.push_back(Card(EIGHT, HEARTS));
deck.push_back(Card(EIGHT, TAMBOURINES));
deck.push_back(Card(EIGHT, CLUBS));
deck.push_back(Card(SEVEN, PEAKS));
deck.push_back(Card(SEVEN, HEARTS));
deck.push_back(Card(SEVEN, TAMBOURINES));
deck.push_back(Card(SEVEN, CLUBS));
deck.push_back(Card(SIX, PEAKS));
deck.push_back(Card(SIX, HEARTS));
deck.push_back(Card(SIX, TAMBOURINES));
deck.push_back(Card(SIX, CLUBS));
if (size == CLASSIC) {
deck.push_back(Card(FIVE, PEAKS));
deck.push_back(Card(FIVE, HEARTS));
deck.push_back(Card(FIVE, TAMBOURINES));
deck.push_back(Card(FIVE, CLUBS));
deck.push_back(Card(FOUR, PEAKS));
deck.push_back(Card(FOUR, HEARTS));
deck.push_back(Card(FOUR, TAMBOURINES));
deck.push_back(Card(FOUR, CLUBS));
deck.push_back(Card(THREE, PEAKS));
deck.push_back(Card(THREE, HEARTS));
deck.push_back(Card(THREE, TAMBOURINES));
deck.push_back(Card(THREE, CLUBS));
deck.push_back(Card(TWO, PEAKS));
deck.push_back(Card(TWO, HEARTS));
deck.push_back(Card(TWO, TAMBOURINES));
deck.push_back(Card(TWO, CLUBS));
}
}*/
/*
vector<Card> Deck::getDeck() {
return deck;
}*/
//-----class Deck-------//

//-----class Player-------//
class Player {
public:
	//create Human and UI type of players
	Player();
	vector<Card>& getPlayerDeck();
	vector<Card>& getPlayerDiscard();
	//vector<bool> chooseCardsToReturn(); //think of necessity
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






int main()
{
	Croupier croupier(CLASSIC);
	cout << "First show: " << endl;
	croupier.show();
	croupier.mix();
	cout << "Mixed deck: " << endl;
	croupier.show();
	croupier.showSize();
	Player player;
	//cout << "Given cards: " << endl;
	croupier.giveCards(player);
	cout << "Deck without player's cards: " << endl;
	croupier.show();
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

	cout << "Size of player's discard: " << player.getPlayerDiscard().size() << endl;



	//for (int i = 0; i < 2/*player.getPlayerDiscard().size()*/;i++) {

	//cout << "D: " << player.getPlayerDiscard().size() << endl;

	//player.getPlayerDiscard().pop_back();

	//}


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



	//the results without "time" are not random between debugging
	//srand(time(0));

	//vector<string> v, deck(5);

	//Actual cards
	/*
	v.push_back("A0");
	v.push_back("A1");
	v.push_back("A2");
	v.push_back("A3");
	v.push_back("K0");
	v.push_back("K1");
	v.push_back("K2");
	v.push_back("K3");
	v.push_back("Q0");
	v.push_back("Q1");
	v.push_back("Q2");
	v.push_back("Q3");
	v.push_back("J0");
	v.push_back("J1");
	v.push_back("J2");
	v.push_back("J3");
	v.push_back("TEN0");
	v.push_back("TEN1");
	v.push_back("TEN2");
	v.push_back("TEN3");
	v.push_back("NINE0");
	v.push_back("NINE1");
	v.push_back("NINE2");
	v.push_back("NINE3");
	v.push_back("EIGHT0");
	v.push_back("EIGHT1");
	v.push_back("EIGHT2");
	v.push_back("EIGHT3");
	v.push_back("SEVEN0");
	v.push_back("SEVEN1");
	v.push_back("SEVEN2");
	v.push_back("SEVEN3");
	v.push_back("SIX0");
	v.push_back("SIX1");
	v.push_back("SIX2");
	v.push_back("SIX3");
	v.push_back("FIVE0");
	v.push_back("FIVE1");
	v.push_back("FIVE2");
	v.push_back("FIVE3");
	v.push_back("FOUR0");
	v.push_back("FOUR1");
	v.push_back("FOUR2");
	v.push_back("FOUR3");
	v.push_back("THREE0");
	v.push_back("THREE1");
	v.push_back("THREE2");
	v.push_back("THREE3");
	v.push_back("TWO0");
	v.push_back("TWO1");
	v.push_back("TWO2");
	v.push_back("TWO3");


	for (int i = 0; i < v.size(); i++) {
	cout << v[i] << endl;
	}

	cout << endl;
	//randomizing cards' initial places
	random_shuffle(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
	cout << v[i] << endl;
	}

	cout << endl;
	//creating a player's deck
	//and removing these cards from general deck
	for (int i = 0; i < deck.size(); i++) {
	deck[i] = v.back();
	v.pop_back();
	}

	cout << endl << endl;

	for (int i = 0; i < deck.size(); i++) {
	cout << deck[i] << endl;
	}

	cout << endl;

	for (int i = 0; i < v.size(); i++) {
	cout << v[i] << endl;
	}

	cout << endl;
	*/
	//using "find" to check the deck
	//vector<string>::iterator p;
	/*if (find(deck.begin(), deck.end(), "A1") != deck.end() &&
	find(deck.begin(), deck.end(), "A2") != deck.end()) {
	cout << "Jacks or better!" << endl;
	}*/

	//cout << endl;



	//int count = 0;
	/*
	//estimation system
	for (int i = 0; i < deck.size(); i++) {

	if (deck[i].find("A") != string::npos) {
	count++;
	}
	}

	string sample = deck[0].substr(0, deck[0].size() - 1);

	cout << sample << endl;

	cout << "There are " << count << " of A." << endl;
	*/
	//Card A4(A, HEARTS);
	//A4.show();

	system("pause");
	return 0;
}

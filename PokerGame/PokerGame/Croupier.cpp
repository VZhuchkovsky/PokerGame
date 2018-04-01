#include "Croupier.h"
#include <iostream>
#include <ctime>
#include <algorithm>

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
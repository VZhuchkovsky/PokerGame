// PokerGame.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

#include "globals.h"
#include "Card.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "Croupier.h"
#include "funcs.h"
#include "GameUI.h"

#include <iostream>
#include <iomanip> 
#include <cstring>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

/*class AR {
private:
	int a;
public:
	AR() {
		a = 10;
	}
	virtual void show() {
		cout << "Class A shows -> " << a << endl;
	}
};

class B : public AR {
private:
	int b;
public:
	B() {
		b = 15;
	}
	void show() {
		cout << "Class B shows -> " << b << endl;
	}
};

class C : public AR {
private:
	int c;
public:
	C() {
		c = 20;
	}
	void show() {
		cout << "Class C shows -> " << c << endl;
	}
};*/

int main()
{
	/*AR a;
	B b;
	C c;

	AR ar1 = c;
	ar1.show();
	AR &ar2 = c;
	ar2.show();
	AR *ar3 = &c;
	ar3->show();*/



	//Croupier croupier;
	//cout << "First show: " << endl;
	//croupier.show();
	//croupier.mix();
	//cout << "Mixed deck: " << endl;
	//croupier.show();
	//croupier.showSize();
	//HumanPlayer player;
	/*AIPlayer player;
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

	cout << "Discard size: " << player.getPlayerDiscard().size() << endl;

	//cout << endl << "Main deck after discarded cards returned: " << endl;

	//croupier.show();

	//cout << "Size of player's discard: " << player.getPlayerDiscard().size() << endl;*/
	/*AIPlayer player1, player2, player3;

	Player *p;

	cout << "Player1: " << endl;

	croupier.giveCards(player1);

	player1.show();

	cout << "Player2: " << endl;

	croupier.giveCards(player2);

	player2.show();

	if (estimation(player1.getPlayerDeck())[0] >= estimation(player2.getPlayerDeck())[0]) {
		p = &player1;
	}
	else {
		p = &player2;
	}

	p->show();*/

	/*AIPlayer player1, player2, player3, player4, player5, player6;

	vector<AIPlayer> v = { player1, player2, player3, player4, player5, player6 };
	//CHECK WHEN THERE MORE THAN ONE CURRENT LEADER
	for (int i = 0; i < 6; i++) {
		croupier.giveCards(v[i]);
		cout << "Player " << i + 1 << ": " << endl;
		v[i].show();
	}

	for (int i = 0; i < 6; i++) {
		cout << "Player " << i + 1 << " is being scored." << endl;
		croupier.scoring(v[i]);
	}

	for (int i = 0; i < 6; i++) {
		cout << "Player " << i + 1 << " has combination " << v[i].getDeckCombination() << " and elder dignity " << v[i].getDeckElderDignity() << endl;

	}*/

	/*vector<Card> v1 = { Card(SIX,CLUBS), Card(SIX,PEAKS), Card(SIX,HEARTS), Card(SIX,TAMBOURINES), Card(SEVEN,CLUBS) };

	for (int i = 0; i < v1.size(); i++) {

		cout << setw(5) << enumToString(v1[i].getCardDignity())
			<< setw(10) << enumToString(v1[i].getCardSuit()) << endl;


	}



	cout << endl;*/

	GameUI game;
	game.start();

	/*AIPlayer player("SSS");

	vector<Card> v1 = { Card(THREE,PEAKS), Card(TEN,TAMBOURINES), Card(FOUR,TAMBOURINES), Card(J,PEAKS), Card(FIVE,PEAKS) };
	cout << "6C, 6P, 6H, 6T, 7C" << endl;

	player.setPlayerDeck(v1);

	player.getPlayerDiscard();

	cout << "AI DECK: " << endl;

	player.show();

	cout << "DDDDDDDDDDDDDDDDDDDDDDDDDDDDDD" << endl << endl;

	HumanPlayer hp("SSAS");

	hp.setPlayerDeck(v1);

	vector<bool> tr = { true, false, true, true, true };

	hp.setPlayerDiscard(tr);

	cout << "HP DECK: " << endl;

	hp.show();*/

	//cout << "DeckCombination is " << player.getDeckCombination() << endl;
	//cout << "DeckElderDignity is " << player.getDeckElderDignity() << endl;


	
	////////////////////////////////////////////////////////////////////////////////////

	/*vector<Card> v1 = { Card(SIX,CLUBS), Card(SIX,PEAKS), Card(SIX,HEARTS), Card(SIX,TAMBOURINES), Card(SEVEN,CLUBS) };
	cout << "6C, 6P, 6H, 6T, 7C" << endl;
	estimation(v1);
	cout << endl << endl;

	vector<Card> v2 = { Card(SIX,CLUBS), Card(SIX,PEAKS), Card(SIX,HEARTS), Card(EIGHT,TAMBOURINES), Card(SEVEN,CLUBS) };
	cout << "6C, 6P, 6H, 8T, 7C" << endl;
	estimation(v2);
	cout << endl << endl;

	vector<Card> v3 = { Card(SIX,CLUBS), Card(SIX,PEAKS), Card(SIX,HEARTS), Card(EIGHT,TAMBOURINES), Card(EIGHT,CLUBS) };
	cout << "6C, 6P, 6H, 8T, 8C" << endl;
	estimation(v3);
	cout << endl << endl;

	vector<Card> v4 = { Card(SIX,CLUBS), Card(EIGHT,PEAKS), Card(EIGHT,HEARTS), Card(EIGHT,TAMBOURINES), Card(EIGHT,CLUBS) };
	cout << "6C, 8P, 8H, 8T, 8C" << endl;
	estimation(v4);
	cout << endl << endl;

	vector<Card> v5 = { Card(SIX,CLUBS), Card(EIGHT, PEAKS), Card(SIX,HEARTS), Card(SIX,TAMBOURINES), Card(SIX,PEAKS) };
	cout << "6C, 8P, 6H, 6T, 6P" << endl;
	estimation(v5);
	cout << endl << endl;

	vector<Card> v6 = { Card(SIX,CLUBS), Card(EIGHT, PEAKS), Card(SIX,HEARTS), Card(SEVEN,TAMBOURINES), Card(SEVEN,PEAKS) };
	cout << "6C, 8P, 6H, 7T, 7P" << endl;
	estimation(v6);
	cout << endl << endl;

	vector<Card> v7 = { Card(SIX,CLUBS), Card(EIGHT, PEAKS), Card(SIX,HEARTS), Card(SEVEN,TAMBOURINES), Card(FIVE,PEAKS) };
	cout << "6C, 8P, 6H, 7T, 5P" << endl;
	estimation(v7);
	cout << endl << endl;

	vector<Card> v8 = { Card(SIX,CLUBS), Card(EIGHT, PEAKS), Card(TEN,HEARTS), Card(SEVEN,TAMBOURINES), Card(FIVE,PEAKS) };
	cout << "6C, 8P, 10H, 7T, 5P" << endl;
	estimation(v8);
	cout << endl << endl;

	vector<Card> v9 = { Card(SIX,CLUBS), Card(EIGHT, PEAKS), Card(NINE,HEARTS), Card(SEVEN,TAMBOURINES), Card(FIVE,PEAKS) };
	cout << "6C, 8P, 9H, 7T, 5P" << endl;
	estimation(v9);
	cout << endl << endl;

	vector<Card> v10 = { Card(SIX,HEARTS), Card(EIGHT, HEARTS), Card(NINE,HEARTS), Card(SEVEN,HEARTS), Card(FIVE,HEARTS) };
	cout << "6H, 8H, 9H, 7H, 5H" << endl;
	estimation(v10);
	cout << endl << endl;

	vector<Card> v11 = { Card(SIX,HEARTS), Card(K, HEARTS), Card(NINE,HEARTS), Card(SEVEN,HEARTS), Card(FIVE,HEARTS) };
	cout << "6H, KH, 9H, 7H, 5H" << endl;
	estimation(v11);
	cout << endl << endl;

	vector<Card> v12 = { Card(Q,HEARTS), Card(K, HEARTS), Card(A,HEARTS), Card(TEN,HEARTS), Card(J,HEARTS) };
	cout << "QH, KH, AH, TH, JH" << endl;
	estimation(v12);
	cout << endl << endl;

	vector<Card> v13 = { Card(Q,HEARTS), Card(Q, TAMBOURINES), Card(A,HEARTS), Card(TEN,HEARTS), Card(J,HEARTS) };
	cout << "QH, QT, AH, TH, JH" << endl;
	estimation(v13);
	cout << endl << endl;

	vector<Card> v14 = { Card(EIGHT,HEARTS), Card(SIX, HEARTS), Card(A,HEARTS), Card(TEN,HEARTS), Card(J,HEARTS) };
	cout << "8H, 6H, AH, TH, JH" << endl;
	estimation(v14);
	cout << endl << endl;*/



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

// PokerGame.cpp : Defines the entry point for the console application.

#include "GameUI.h"

#include <iostream>

using namespace std;

int main()
{
	/*GameUI game;
	game.start();*/

	//& croupier = Croupier::getInstance();

	vector<Card> v1 = { Card(TWO,TAMBOURINES), Card(K,TAMBOURINES), Card(K,CLUBS), Card(A,CLUBS), Card(TEN,CLUBS) };
	//vector<Card> v2 = { Card(SIX,CLUBS), Card(EIGHT, PEAKS), Card(SIX,HEARTS), Card(SEVEN,TAMBOURINES), Card(SEVEN,PEAKS) };
	//vector<Card> v3 = { Card(Q,HEARTS), Card(K, HEARTS), Card(A,HEARTS), Card(TEN,HEARTS), Card(J,HEARTS) };
	//vector<Card> v4 = { Card(TEN,TAMBOURINES), Card(K, HEARTS), Card(A,HEARTS), Card(TEN,HEARTS), Card(TEN,HEARTS) };

	cout << estimation(v1)[0] << " " << estimation(v1)[1] << endl;

	system("pause");
	return 0;
}

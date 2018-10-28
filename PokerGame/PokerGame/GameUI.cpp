#include "GameUI.h"

#include <vector>
#include <iostream>
#include <iomanip> 
#include <cassert>
#include <chrono> //for sleep
#include <thread> //for sleep
#include <conio.h> //getchar()
#include <typeinfo>
//#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::this_thread::sleep_for;
//using std::string;

GameUI::GameUI():currentPointerPosition(0) {

	positionsOfCardsToReturn = { false, false, false, false, false };

	croupier = new Croupier;
	aiFactory = new AIPlayerFactory;
	humanFactory = new HumanPlayerFactory;
	

}

GameUI::~GameUI()
{

	delete croupier;
	delete aiFactory;
	delete humanFactory;

	for (int i = 0; i < players.size(); i++) {

		cout << "Player " << i << "is deleted." << endl; //test
		delete players[i];

	}

}


void GameUI::start() {

	cout << "Welcome to PokerGame! \nPlease, type your name: ";
	
	string currentPlayerName;
	cin >> currentPlayerName;
	cout << endl;

	bool flag1 = true;
	int numberOfRivals = 0;

	while (flag1) {

		cout << "How many rivals do you want? Please insert number (1-3): ";
		cin >> numberOfRivals;

		if (numberOfRivals > 0 && numberOfRivals <= MAX_PLAYERS) {
			
			flag1 = false;

		}
		else {

			system("cls");

			cout << "Oops! It seems your input was incorrect. Please, try again." << endl;

		}

	}

	assert(numberOfRivals > 0 && numberOfRivals <= MAX_PLAYERS); // additional verification

	system("cls");

	cout << "You chose " << numberOfRivals;

	numberOfRivals > 1 ? cout << " rivals!" : cout << " rival!";

	cout << endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(1400)); // sleep



	//creating AI player(s)
	for (int i = 0; i < numberOfRivals; i++) {

		assert(i < defaultNames.size()); // additional verification

		players.push_back(aiFactory->createPlayer(defaultNames[i]));

	}

	players.push_back(humanFactory->createPlayer(currentPlayerName)); //creating human player



	cout  << players.size() << " players in game." << endl;//test

	std::this_thread::sleep_for(std::chrono::milliseconds(1400)); 
	
	cout << "The game begins!" << endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(1400)); 

	system("cls");

	bool flag2 = true;

	while (flag2) {

		croupier->mix(); //mix the deck

		//give cards to each player and visualizing their decks
		for (int i = 0; i < players.size(); i++) {

			croupier->giveCards(*players[i]);

			cout << players[i]->getName() << "'s deck" << endl;

			visualizeTheDeck(players[i]);

		}

		cout << setw(10) << "Press SPACE to continue" << endl;

		bool flag3 = true;

		int pressedButton;

		while (flag3) {

			pressedButton = _getch();
			//space button pressed
			if (pressedButton == 32) {
				system("cls");
				flag3 = false;
			}

		}


		//AI discard cycle
		for (int i = 0; i < players.size(); i++) {

			if (typeid(*players[i]) == typeid(AIPlayer)) {

				players[i]->getPlayerDiscard();

			}

		}

		//visualizing decks and human discard cycle
		bool flag4 = true;

		while (flag4) {

			for (int i = 0; i < players.size(); i++) {

				if (typeid(*players[i]) == typeid(AIPlayer)) {

					int currentDeckSize = players[i]->getPlayerDeck().size();

					if (currentDeckSize == PLAYER_DECK_SIZE) {

						cout << players[i]->getName() << " stays with current deck." << endl;

					}
					else if (currentDeckSize ==  0) {

						cout << players[i]->getName() << " returned the whole deck." << endl;

						for (int j = 0; j < visualHeight; j++) {
							cout << endl;
						}

					}
					else {

						cout << players[i]->getName() << " has returned " << PLAYER_DECK_SIZE - currentDeckSize << " cards." << endl;

					}

					visualizeTheDeck(players[i]);

				}
				else {

					cout << "Choose cards to discard: " << endl;

					visualizeTheDeck(players[i]);

					visualizeThePointer(players[i]);

					cout << "Press SPACE to confirm discard." << endl;

					pressedButton = _getch();

					if (pressedButton == 32) {

						players[i]->setPlayerDiscard(getPositionsOfCardsToReturn());

						//croupier->takeCardsBack(*players[i]);

						flag4 = false;

					}
					else if (pressedButton == 75) {
						previousPosition();
						break;
					}
					else if (pressedButton == 77) {
						nextPosition();
						break;
					}
					else if (pressedButton == 13) {
						markPosition();
						break;
					}

					std::this_thread::sleep_for(std::chrono::milliseconds(100)); //for making sure visualization is complete

				}

			}

			system("cls");

		}



		for (int i = 0; i < players.size(); i++) {

			croupier->giveCards(*players[i]); //giving missing cards

			croupier->takeCardsBack(*players[i]); //returning cards to the main deck

			croupier->scoring(*players[i]); //scoring

		}

		//reveal = true;

		visualizeDiscardMark = false;
		
		//visualizing results
		for (int i = 0; i < players.size(); i++) {

			cout << players[i]->getName() << "'s results: Combination - " << combinationToString(players[i]->getDeckCombination()) << 
				", Elder Card - " << dignityToString(players[i]->getDeckElderDignity()) << endl;

			visualizeTheDeck(players[i]);

		}

		cout << "Croupier's verdict: ";

		int quantityOfWinners = 0;

		for (int i = 0; i < croupier->getTheLeader().size(); i++) {

			if (croupier->getTheLeader()[i] != 0) {
				++quantityOfWinners;
			}

		}

		if (quantityOfWinners > 1) {

			cout << "There are several winners: ";

			for (int i = 0; i < croupier->getTheLeader().size(); i++) {

				if (croupier->getTheLeader()[i]) {
					cout << croupier->getTheLeader()[i]->getName() << "   ";
				}

			}

			cout << endl;

		}
		else {

			cout << croupier->getTheLeader()[0]->getName() << " is victorious!" << endl;

		}

		flag2 = false;

	}

}

int GameUI::getCurrentPointerPosition(){

	return currentPointerPosition;

}

vector<bool> GameUI::getPositionsOfCardsToReturn(){

	return positionsOfCardsToReturn;

}

void GameUI::nextPosition(){

	//place asserts
	if (currentPointerPosition == PLAYER_DECK_SIZE - 1) {
		currentPointerPosition = 0;
	}
	else {
		++currentPointerPosition;
	}

}

void GameUI::previousPosition(){

	if (currentPointerPosition == 0) {
		currentPointerPosition = PLAYER_DECK_SIZE - 1;
	}
	else {
		--currentPointerPosition;
	}

}

void GameUI::markPosition(){

	positionsOfCardsToReturn[currentPointerPosition] = !positionsOfCardsToReturn[currentPointerPosition];

}

void GameUI::visualizeTheDeck(Player * player){

	string dignity;

	for (int j = 0; j < visualHeight; j++) {

		for (int i = 0; i < player->getPlayerDeck().size(); i++) {

			if (typeid(*player) == typeid(HumanPlayer)) {
				dignity = enumToString(player->getPlayerDeck()[i].getCardDignity());
			}
			else {
				dignity = "*";
			}


			if (j == 0 || j == visualHeight - 1) {

				for (int k = 0; k <= visualHeight; k++) {

					if (k == 0) {

						cout << setw(2) << " ";

					}
					else if (k == visualHeight) {

						cout << " ";

					}
					else {

						cout << "-";

					}

				}

			}
			else if (j == 1) {

				cout << setw(2) << "|" << dignity << setw(visualWidth - (dignity.size() + 2)) << "|";

			}
			else if (typeid(*player) == typeid(HumanPlayer) && positionsOfCardsToReturn[i] && visualizeDiscardMark && j == 3) {

				cout << setw(2) << "|" << setw(2) << "TO DISCARD" << setw(2) << "|";

			}
			else if (typeid(*player) == typeid(HumanPlayer) && j == 6) {

				cout << setw(2) << "|" << setw(visualWidth - 6) << enumToString(player->getPlayerDeck()[i].getCardSuit()) << setw(visualWidth - 10) << "|";

			}
			else if (j == visualHeight - 2) {

				cout << setw(2) << "|" << setw(visualWidth - 3) << dignity << "|";

			}
			else {

				cout << setw(2) << "|" << setw(visualWidth - 2) << "|";

			}

			if (i == player->getPlayerDeck().size() - 1) {
				cout << endl;
			}

		}

	}

	cout << endl;

}

void GameUI::visualizeThePointer(Player * player){

	if (typeid(*player) == typeid(HumanPlayer)) {

		cout << setw((visualWidth / 2) * 2 * currentPointerPosition + 9) << "/\\" << endl;

	}

}

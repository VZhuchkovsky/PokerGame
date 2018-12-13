#include "GameUI.h"

#include <array>
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

GameUI::GameUI():currentPointerPosition(0), revealAIDeck(false), visualizeDiscardMark(true), croupier(Croupier::getInstance())
{
	positionsOfCardsToReturn = { false, false, false, false, false };
}

GameUI::~GameUI()
{
}


void GameUI::start() 
{
	cout << "Welcome to PokerGame!" << endl;

	bool flag0 = true;
	string currentPlayerName;

	while (flag0) {

		cout << "Please, type your name: ";
		cin >> currentPlayerName;
		cout << endl;

		for (int i = 0; i < currentPlayerName.size(); i++) {

			if (!(((int)currentPlayerName.at(i) >= 65 && (int)currentPlayerName.at(i) <= 90) ||
				((int)currentPlayerName.at(i) >= 97 && (int)currentPlayerName.at(i) <= 122)))
			{
				system("cls");
				cout << "Oops! It seems your input was incorrect. Please, try again and use only English letters." << endl;
				break;
			}
			else if (i == currentPlayerName.size() - 1)
			{
				flag0 = false;
			}

		}

	}

	system("cls");

	bool flag1 = true;
	int numberOfRivals = 0;

	while (flag1) 
	{
		cout << "How many rivals do you want? Please insert number (1-3): ";
		cin >> numberOfRivals;

		if (numberOfRivals > 0 && numberOfRivals <= MAX_PLAYERS) flag1 = false;

		else 
		{
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
	for (int i = 0; i < numberOfRivals; i++) 
	{
		players.push_back(AIPlayerFactory::createPlayer());
	}

	players.push_back(HumanPlayerFactory::createPlayer(currentPlayerName)); //creating human player

	cout  << players.size() << " players in game." << endl;//test

	std::this_thread::sleep_for(std::chrono::milliseconds(1400)); 
	
	cout << "The game begins!" << endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(1400)); 

	system("cls");

	bool flag2 = true;

	while (flag2) 
	{
		croupier.mix(); //mix the deck
		//give cards to each player and visualizing their decks
		for (int i = 0; i < players.size(); i++) 
		{
			croupier.giveCards(*players.at(i));
			cout << players.at(i)->getName() << "'s deck" << endl;
			visualizeTheDeck(players.at(i));
		}

		cout << setw(10) << "Press SPACE to continue" << endl;

		bool flag3 = true;

		int pressedButton;

		while (flag3) 
		{
			pressedButton = _getch();
			//space button pressed
			if (pressedButton == 32) 
			{
				system("cls");
				flag3 = false;
			}
		}

		//AI discard cycle
		for (int i = 0; i < players.size(); i++) 
		{
			if (typeid(*players.at(i)) == typeid(AIPlayer)) players.at(i)->getPlayerDiscard();
		}

		//visualizing decks and human discard cycle
		bool flag4 = true;

		while (flag4) 
		{
			for (int i = 0; i < players.size(); i++) 
			{
				if (typeid(*players.at(i)) == typeid(AIPlayer))
				{
					int currentDeckSize = players.at(i)->getPlayerDeck().size();

					if (currentDeckSize == PLAYER_DECK_SIZE) 
						cout << players.at(i)->getName() << " stays with current deck." << endl;
					else if (currentDeckSize ==  0) 
					{
						cout << players.at(i)->getName() << " returned the whole deck." << endl;
						for (int j = 0; j < VISUAL_HEIGHT; j++) cout << endl;
					}
					else cout << players.at(i)->getName() << " has returned " << PLAYER_DECK_SIZE - currentDeckSize << " cards." << endl;

					visualizeTheDeck(players.at(i));
				}
				else 
				{
					cout << "Choose cards to discard: " << endl;
					visualizeTheDeck(players.at(i));
					visualizeThePointer(players.at(i));
					cout << "Press SPACE to confirm discard." << endl;
					pressedButton = _getch();

					if (pressedButton == 32) 
					{
						players.at(i)->setPlayerDiscard(getPositionsOfCardsToReturn());
						//croupier->takeCardsBack(*players[i]);

						flag4 = false;
					}
					else if (pressedButton == 75) 
					{
						previousPosition();
						break;
					}
					else if (pressedButton == 77) 
					{
						nextPosition();
						break;
					}
					else if (pressedButton == 13) 
					{
						markPosition();
						break;
					}

					std::this_thread::sleep_for(std::chrono::milliseconds(100)); //for making sure visualization is complete

				}

			}

			system("cls");

		}



		for (int i = 0; i < players.size(); i++) 
		{
			croupier.giveCards(*players.at(i)); //giving missing cards
			croupier.takeCardsBack(*players.at(i)); //returning cards to the main deck
			croupier.scoring(*players.at(i)); //scoring
		}

		//reveal = true;

		//hide discard mark
		visualizeDiscardMark = false;
		
		//reveal AI deck
		revealAIDeck = true;

		//visualizing results
		for (int i = 0; i < players.size(); i++) 
		{
			cout << players.at(i)->getName() << "'s results: Combination - " << combinationToString(players.at(i)->getDeckCombination());
			cout <<	", Elder Card - " << dignityToString(players.at(i)->getDeckElderDignity()) << endl;
			visualizeTheDeck(players.at(i));
		}

		cout << "Croupier's verdict: ";

		int quantityOfWinners = 0;

		for (int i = 0; i < croupier.getTheLeader().size(); i++) 
		{
			if (croupier.getTheLeader().at(i) != 0)
				++quantityOfWinners;
		}

		if (quantityOfWinners > 1) 
		{
			cout << "There are several winners: ";

			for (int i = 0; i < croupier.getTheLeader().size(); i++) 
			{
				if (croupier.getTheLeader().at(i))
					cout << croupier.getTheLeader().at(i)->getName() << "   ";
			}

			cout << endl;

		}
		else
			cout << croupier.getTheLeader().at(0)->getName() << " is victorious!" << endl;

		flag2 = false;

	}

}

int GameUI::getCurrentPointerPosition()
{
	return currentPointerPosition;
}

vector<bool> GameUI::getPositionsOfCardsToReturn() const
{
	return positionsOfCardsToReturn;
}

void GameUI::nextPosition()
{
	//place asserts
	if (currentPointerPosition == PLAYER_DECK_SIZE - 1) 
		currentPointerPosition = 0;
	else 
		++currentPointerPosition;
}

void GameUI::previousPosition()
{

	if (currentPointerPosition == 0)
		currentPointerPosition = PLAYER_DECK_SIZE - 1;
	else 
		--currentPointerPosition;

}

void GameUI::markPosition()
{
	positionsOfCardsToReturn[currentPointerPosition] = !positionsOfCardsToReturn[currentPointerPosition];
}

void GameUI::visualizeTheDeck(std::shared_ptr<Player> player)
{

	string dignity;

	for (int j = 0; j < VISUAL_HEIGHT; j++)
	{

		for (int i = 0; i < player->getPlayerDeck().size(); i++) 
		{

			if (typeid(*player) == typeid(HumanPlayer) || 
				(typeid(*player) == typeid(AIPlayer) && revealAIDeck))
				dignity = enumToString(player->getPlayerDeck().at(i)->getCardDignity());
			else 
				dignity = "*";


			if (j == 0 || j == VISUAL_HEIGHT - 1)
			{
				for (int k = 0; k <= VISUAL_HEIGHT; k++)
				{
					if (k == 0)
						cout << setw(2) << " ";
					else if (k == VISUAL_HEIGHT)
						cout << " ";
					else
						cout << "-";
				}
			}
			else if (j == 1)
				cout << setw(2) << "|" << dignity << setw(VISUAL_WIDTH - (dignity.size() + 2)) << "|";
			else if (typeid(*player) == typeid(HumanPlayer) && positionsOfCardsToReturn.at(i) && visualizeDiscardMark && j == 3)
				cout << setw(2) << "|" << setw(2) << "TO DISCARD" << setw(2) << "|";
			else if (j == 6 && (typeid(*player) == typeid(HumanPlayer) || (typeid(*player) == typeid(AIPlayer) && revealAIDeck)))
				cout << setw(2) << "|" << setw(VISUAL_WIDTH - 6) << enumToString(player->getPlayerDeck().at(i)->getCardSuit()) << setw(VISUAL_WIDTH - 10) << "|";
			else if (j == VISUAL_HEIGHT - 2)
				cout << setw(2) << "|" << setw(VISUAL_WIDTH - 3) << dignity << "|";
			else 
				cout << setw(2) << "|" << setw(VISUAL_WIDTH - 2) << "|";

			if (i == player->getPlayerDeck().size() - 1)
				cout << endl;

		}

	}

	cout << endl;

}

void GameUI::visualizeThePointer(std::shared_ptr<Player> player)
{

	if (typeid(*player) == typeid(HumanPlayer)) 
		cout << setw((VISUAL_WIDTH / 2) * 2 * currentPointerPosition + 9) << "/\\" << endl;

}

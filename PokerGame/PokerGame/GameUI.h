#ifndef __GAME_UI__
#define __GAME_UI__

#include "Croupier.h"
#include "AIPlayerFactory.h"
#include "HumanPlayerFactory.h"
#include "funcs.h"

class GameUI
{
public:
	GameUI();
	~GameUI();
	void start();
private:
	Croupier * croupier;
	AIPlayerFactory * aiFactory;
	HumanPlayerFactory * humanFactory;
	vector<Player*> players;
	int currentPointerPosition; //doubly connected ring list's basis
	vector<bool> positionsOfCardsToReturn; //positions of cards to be discarded
	const int visualWidth = 14, visualHeight = 12;

	int getCurrentPointerPosition();
	//bool reveal = false;
	bool visualizeDiscardMark = true;
	vector<bool> getPositionsOfCardsToReturn();
	void nextPosition();
	void previousPosition();
	void markPosition();
	void visualizeTheDeck(Player *player);
	void visualizeThePointer(Player* player);
};

#endif __GAME_UI__



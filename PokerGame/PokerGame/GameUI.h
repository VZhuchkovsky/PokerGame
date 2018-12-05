#ifndef __GAME_UI__
#define __GAME_UI__

#include "Croupier.h"
#include "AIPlayerFactory.h"
#include "HumanPlayerFactory.h"
//#include "funcs.h"

class GameUI
{
public:
	GameUI();
	~GameUI();
	void start();
private:
	Croupier& croupier;
	AIPlayerFactory aiFactory;
	HumanPlayerFactory humanFactory;
	vector<std::shared_ptr<Player>> players;
	int currentPointerPosition; //doubly connected ring list's basis
	vector<bool> positionsOfCardsToReturn; //positions of cards to be discarded
	const int visualWidth = 14, visualHeight = 12;

	int getCurrentPointerPosition();
	bool revealAIDeck;
	bool visualizeDiscardMark;
	vector<bool> getPositionsOfCardsToReturn() const;
	void nextPosition();
	void previousPosition();
	void markPosition();
	void visualizeTheDeck(std::shared_ptr<Player> player);
	void visualizeThePointer(std::shared_ptr<Player> player);
};

#endif __GAME_UI__



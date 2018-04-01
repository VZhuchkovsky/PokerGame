#include "HumanPlayer.h"

HumanPlayer::HumanPlayer() : Player() {};

vector<bool> HumanPlayer::chooseCardsToReturn() { //sample
	vector<bool> chosenToDiscard = { true, true, false, false, true };
	return chosenToDiscard;
}

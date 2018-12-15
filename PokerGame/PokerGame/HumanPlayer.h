#ifndef __HUMAN_PLAYER__
#define __HUMAN_PLAYER__

#include "Player.h"

#include <vector>

class HumanPlayer : public Player 
{
public:
	HumanPlayer(string n);
	std::vector<unique_ptr<Card>>& getPlayerDiscard() override;
	void setPlayerDiscard(std::vector<bool> positionsOfReturnedCards) override;

};

#endif __HUMAN_PLAYER__


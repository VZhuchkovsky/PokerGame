#ifndef __HUMAN_PLAYER_FACTORY__
#define __HUMAN_PLAYER_FACTORY__

#include "PlayerFactory.h"
#include "HumanPlayer.h"

class HumanPlayerFactory
{
public:
	static std::shared_ptr<Player> createPlayer(string name);
	~HumanPlayerFactory();
};

#endif __HUMAN_PLAYER_FACTORY__


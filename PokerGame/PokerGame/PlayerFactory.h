#ifndef __PLAYER_FACTORY__
#define __PLAYER_FACTORY__

#include "Player.h"

#include <memory>

class PlayerFactory
{
public:
	virtual std::shared_ptr<Player> createPlayer(string name) = 0;
	virtual ~PlayerFactory();
};

#endif __PLAYER_FACTORY__

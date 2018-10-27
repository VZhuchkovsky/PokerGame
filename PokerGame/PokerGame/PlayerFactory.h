#ifndef __PLAYER_FACTORY__
#define __PLAYER_FACTORY__

#include "Player.h"

class PlayerFactory
{
public:
	virtual Player* createPlayer(string name) = 0;
	virtual ~PlayerFactory();
};

#endif __PLAYER_FACTORY__

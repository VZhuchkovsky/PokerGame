#ifndef __AI_PLAYER_FACTORY__
#define __AI_PLAYER_FACTORY__

#include "PlayerFactory.h"
#include "AIPlayer.h"

class AIPlayerFactory : public PlayerFactory
{
public:
	Player * createPlayer(string name);
	~AIPlayerFactory();
};

#endif __AI_PLAYER_FACTORY__


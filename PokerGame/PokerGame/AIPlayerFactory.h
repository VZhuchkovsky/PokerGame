#ifndef __AI_PLAYER_FACTORY__
#define __AI_PLAYER_FACTORY__

#include "PlayerFactory.h"
#include "AIPlayer.h"

class AIPlayerFactory : public PlayerFactory
{
public:
	static std::shared_ptr<Player> createPlayer(string name = defaultNames.at(AIPlayer::getCurrentName()));
	~AIPlayerFactory();

private:
	static const vector<string> defaultNames;//default names for AI players
};

#endif __AI_PLAYER_FACTORY__


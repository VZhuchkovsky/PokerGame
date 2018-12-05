#include "AIPlayerFactory.h"


std::shared_ptr<Player> AIPlayerFactory::createPlayer(string name)
{
	return std::shared_ptr<Player>(new AIPlayer(name));
}

AIPlayerFactory::~AIPlayerFactory()
{
}

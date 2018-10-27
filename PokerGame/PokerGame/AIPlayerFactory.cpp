#include "AIPlayerFactory.h"



Player * AIPlayerFactory::createPlayer(string name)
{
	return new AIPlayer(name);
}

AIPlayerFactory::~AIPlayerFactory()
{
}

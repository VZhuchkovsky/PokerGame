#include "HumanPlayerFactory.h"

Player* HumanPlayerFactory::createPlayer(string name) {
	return new HumanPlayer(name);
}

HumanPlayerFactory::~HumanPlayerFactory()
{
}

#include "HumanPlayerFactory.h"
#include <memory>


std::shared_ptr<Player> HumanPlayerFactory::createPlayer(string name)
{
	return std::shared_ptr<Player>(new HumanPlayer(name));
}

HumanPlayerFactory::~HumanPlayerFactory()
{}

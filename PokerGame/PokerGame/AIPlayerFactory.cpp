#include "AIPlayerFactory.h"

#include<cassert>

std::shared_ptr<Player> AIPlayerFactory::createPlayer(string name)
{
	std::shared_ptr<Player> sptr(new AIPlayer(name));
	return sptr;
}

AIPlayerFactory::~AIPlayerFactory()
{
}

const vector<string> AIPlayerFactory::defaultNames 
({
	"McCree",
	"Erron Black",
	"Big Iron",
	"Unreachable"//to prevent creating more than MAX_PLAYERS players
});


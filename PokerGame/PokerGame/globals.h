#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include <string>
#include <vector>
using std::string;
using std::vector;

const int PLAYER_DECK_SIZE = 5;
const int MAX_PLAYERS = 3;

/*enum gameMode {
	SMALL,
	CLASSIC
};*/

enum cardDignity {
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	J,
	Q,
	K,
	A
};

enum cardSuit {
	PEAKS,
	HEARTS,
	TAMBOURINES,
	CLUBS
};

enum combinations {
	ONE_PAIR = 1,//0 represents no combination
	TWO_PAIRS,
	THREE_OF_A_KIND,
	STRAIGHT,
	FLUSH,
	FULL_HOUSE,
	FOUR_OF_A_KIND,
	STRAIGHT_FLUSH,
	ROYAL_FLUSH
};

//default names for AI players
static vector<string> defaultNames = {
	"McCree",
	"Erron Black",
	"Big Iron"
};


#endif // __GLOBALS_H__

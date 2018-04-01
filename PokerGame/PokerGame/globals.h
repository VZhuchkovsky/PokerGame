#ifndef __GLOBALS_H__
#define __GLOBALS_H__

const int PLAYER_DECK_SIZE = 5;

enum gameMode {
	SMALL,
	CLASSIC
};

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
	ONE_PAIR,
	TWO_PAIRS,
	THREE_OF_A_KIND,
	STRAIGHT,
	FLUSH,
	FULL_HOUSE,
	FOUR_OF_A_KIND,
	STRAIGHT_FLUSH,
	ROYAL_FLUSH
};


#endif // __GLOBALS_H__

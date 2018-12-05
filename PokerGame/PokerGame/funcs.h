#ifndef __FUNCS_H__
#define __FUNCS_H__

#include <array>
#include "Card.h"
#include "globals.h"
using std::array;

array<int,2> estimation(vector<Card> deck);
bool sortBySuit(Card c1, Card c2);//bool function used as parameter
								  //for sort algorithm to sort cards by suit
const string enumToString(cardDignity c);//temporary solution for cards' in-game presentation
const string enumToString(cardSuit c);
const string combinationToString(int c);
const string dignityToString(int c);

#endif __FUNCS_H__


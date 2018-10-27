#ifndef __FUNCS_H__
#define __FUNCS_H__

#include <vector>
#include "Card.h"
#include "globals.h"
using std::vector;

vector<int> estimation(vector<Card> deck);
bool sortBySuit(Card c1, Card c2);//bool function used as parameter
								  //for sort algorithm to sort cards by suit
const string enumToString(cardDignity c);//temporary solution for cards' in-game presentation
const string enumToString(cardSuit c);
const string combinationToString(int c);
const string dignityToString(int c);

#endif __FUNCS_H__


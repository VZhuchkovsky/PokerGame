#ifndef __FUNCS_H__
#define __FUNCS_H__

#include <vector>
#include "Card.h"
using std::vector;

vector<int> estimation(vector<Card> deck);
bool sortBySuit(Card c1, Card c2);//bool function used as parameter
								  //for sort algorithm to sort cards by suit
#endif __FUNCS_H__


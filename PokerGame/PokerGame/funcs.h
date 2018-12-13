#ifndef __FUNCS_H__
#define __FUNCS_H__

#include "Card.h"
#include "globals.h"

#include <array>
#include <memory>

bool sortBySuit(const std::unique_ptr<Card>& c1, const std::unique_ptr<Card>& c2);//bool function used as parameter
								  //for sort algorithm to sort cards by suit
bool sortByDignity(const std::unique_ptr<Card>& c1, const std::unique_ptr<Card>& c2);//sort deck by dignity
bool cardComparison(const std::unique_ptr<Card>& c1, const std::unique_ptr<Card>& c2);//card comparison function
                                  //for Croupier's deck integrity verification
std::array<int,2> estimation(vector<std::unique_ptr<Card>>& deck);//estimation of the deck
const string enumToString(cardDignity c);//temporary solution for cards' in-game presentation
const string enumToString(cardSuit c);
const string combinationToString(int c);
const string dignityToString(int c);

#endif __FUNCS_H__


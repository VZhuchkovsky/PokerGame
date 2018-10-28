// PokerGame.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

#include "globals.h"
#include "Card.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "Croupier.h"
#include "funcs.h"
#include "GameUI.h"

#include <iostream>
#include <iomanip> 
#include <cstring>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

int main()
{

	GameUI game;
	game.start();


	system("pause");
	return 0;
}

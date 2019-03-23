#pragma once
#ifndef GAME_H
#define GAME_H

#include "pile.h"


class Game
{
private:
	pile havile;
	int coreect_get;
public:
	Game(const int num);//ctor
	void Run();//run game
	~Game();//dtor
};
#endif // !GAME_H


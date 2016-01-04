/*
 * Dice.cpp
 *
 *  Created on: 7 déc. 2015
 *      Author: Quincy
 */

#include "Dice.hpp"
#include <stdlib.h>
#include <ctime>

Dice::Dice(int nMaxNumber) : Displayable(view::DiceView)
{
	this->nMaxNum = nMaxNumber;
	srand(time(0));
}

Dice::~Dice()
{
}

int Dice::GetMoveNumber()
{
	int nRandom = rand() % nMaxNum + 1;
	return nRandom;
}

/*
 * MoveFactory.h
 *
 *  Created on: 7 déc. 2015
 *      Author: Quincy
 */

#ifndef MOVEFACTORY_H_
#define MOVEFACTORY_H_

#include <map>
#include "Dice.hpp"
#include "Cards.hpp"
#include "../player/Player.hpp"

//This class has pattern factory
class MoveFactory
{
private:
	static MoveFactory* mfUnique;
	std::map <int, Dice*> mDiceMap;

public:
	static MoveFactory* getInstance();
	Dice* createDice(int nSizeOfDice);
	Cards* createCards(int nAmountOfCards, Player* pOwner);
};

#endif /* MOVEFACTORY_H_ */

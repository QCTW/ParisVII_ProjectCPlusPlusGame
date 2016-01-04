/*
 * MoveFactory.cpp
 *
 *  Created on: 7 déc. 2015
 *      Author: Quincy
 */

#include "MoveFactory.hpp"

MoveFactory* MoveFactory::mfUnique = nullptr;
MoveFactory* MoveFactory::getInstance()
{
	if(MoveFactory::mfUnique == nullptr)
	{
		MoveFactory::mfUnique = new MoveFactory();
	}
	return MoveFactory::mfUnique;
}

Dice* MoveFactory::createDice(int nSizeOfDice)
{
	auto search = mDiceMap.find(nSizeOfDice);
	if(search != mDiceMap.end())
	{
		return search->second;
	}
	else
	{
		Dice* dNew = new Dice(nSizeOfDice);
		mDiceMap.insert( std::make_pair(nSizeOfDice, dNew) );
		return dNew;
	}
}

/**
 * This method has not implemented yet
 */
Cards* MoveFactory::createCards(int nAmountOfCards, Player* pUser)
{
	return nullptr;
}

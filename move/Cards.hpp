/*
 * Cards.h
 *
 *  Created on: 7 déc. 2015
 *      Author: Quincy
 */

#ifndef CARDS_HPP_
#define CARDS_HPP_ :
#include "Tool.hpp"
#include "../player/Player.hpp"
class Player;
class Cards : public Tool
{
public:
	Cards(int nNumberOfCards, Player* pOwner);
	virtual ~Cards();
	virtual int GetMoveNumber();
};

#endif /* CARDS_HPP_ */

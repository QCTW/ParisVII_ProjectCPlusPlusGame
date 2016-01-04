/*
 * Dice.h
 *
 *  Created on: 7 déc. 2015
 *      Author: Quincy
 */

#ifndef DICE_H_
#define DICE_H_
#include "Tool.hpp"
#include "../view/Displayable.hpp"

class Dice : public Tool, public view::Displayable
{
private:
	int nMaxNum;

public:
	Dice(int nSize);
	virtual ~Dice();
	int GetMoveNumber();
};

#endif /* DICE_H_ */

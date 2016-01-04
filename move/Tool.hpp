/*
 * MoveFacility.h
 *
 *  Created on: 7 déc. 2015
 *      Author: Quincy
 */

#ifndef TOOL_H_
#define TOOL_H_

class Tool
{
public:
	Tool();
	virtual ~Tool();
	/**
	 * This method will give you a number which indicates you:
	 * - How many steps to move for Dice
	 * - Which cell ID to move to for Cards
	 */
	virtual int GetMoveNumber() = 0;
};

#endif /* TOOL_H_ */

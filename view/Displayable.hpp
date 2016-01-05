/*
 * Displayable.hpp
 *
 *  Created on: 3 janv. 2016
 *      Author: Quincy
 */

#ifndef VIEW_DISPLAYABLE_HPP_
#define VIEW_DISPLAYABLE_HPP_

#include "RGB.hpp"
#include <string>

using namespace std;

namespace view
{

enum ObjectType { PawnView, PlayerView, CellView, DiceView, MessageView };
enum ObjectSize { PawnX=15, PawnY=15, PlayerX=100, PlayerY=50, CellX=100, CellY=100, DiceSize=100, MessageX=200, MessageY=50 };

class Displayable
{
private:
	RGB _color;
	ObjectType _otype;
public:
	Displayable(ObjectType ot);
	virtual ~Displayable();
	RGB& getColor();
	int randomRGBA();
};

} /* namespace view */
#endif /* VIEW_DISPLAYABLE_HPP_ */

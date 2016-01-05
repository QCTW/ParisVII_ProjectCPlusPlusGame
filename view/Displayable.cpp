/*
 * Displayable.cpp
 *
 *  Created on: 3 janv. 2016
 *      Author: Quincy
 */

#include "Displayable.hpp"
#include <stdlib.h>
#include <ctime>
#include <iostream>

namespace view
{

Displayable::Displayable(ObjectType ot) : _color(randomRGBA(), randomRGBA(), randomRGBA())
{
	this->_otype = ot;
}

Displayable::~Displayable()
{
}

RGB& Displayable::getColor()
{
	return this->_color;
}

int Displayable::randomRGBA()
{
	int nRandom = rand() % 255 + 1;
	return nRandom;
}


} /* namespace view */

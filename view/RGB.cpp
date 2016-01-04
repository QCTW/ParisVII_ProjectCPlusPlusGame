/*
 * RGB.cpp
 *
 *  Created on: 4 janv. 2016
 *      Author: Quincy
 */

#include "RGB.hpp"
#include <iostream>
using namespace std;

namespace view
{

RGB::RGB(int nRed, int nGreen, int nBlue) : R(nRed), G(nGreen), B(nBlue)
{
	cout << "RBG:" << nRed << "," << nGreen << "," << nBlue << endl;
}

RGB::~RGB()
{
}

} /* namespace view */

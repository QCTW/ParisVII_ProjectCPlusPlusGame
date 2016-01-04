/*
 * RGB.hpp
 *
 *  Created on: 4 janv. 2016
 *      Author: Quincy
 */

#ifndef VIEW_RGB_HPP_
#define VIEW_RGB_HPP_

namespace view
{

struct RGB
{
public:
	RGB(int nRed, int nGreen, int nBlue);
	virtual ~RGB();
	int R;
	int G;
	int B;
};

} /* namespace view */

#endif /* VIEW_RGB_HPP_ */

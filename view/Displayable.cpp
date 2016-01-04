/*
 * Displayable.cpp
 *
 *  Created on: 3 janv. 2016
 *      Author: Quincy
 */

#include "Displayable.hpp"
#include "TextLabel.hpp"
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

sf::Sprite Displayable::getDisplayObject()
{
	sf::Sprite displayObj;
	sf::Texture texture;
	switch(this->_otype)
	{
	    case PawnView:
	    {
	    	texture.loadFromFile("resource/blue.gif");
//	    	pawnV.setFillColor(sf::Color(_color.R, _color.G, _color.B));
//	    	pawnV.setOutlineColor(sf::Color::Black);
//	    	pawnV.setOutlineThickness(2);
	    	break;
	    }

	    case CellView:
	    {
	    	texture.loadFromFile("resource/BG.PNG");
//			cellV.setOutlineColor(sf::Color::White);
//			cellV.setOutlineThickness(3);
	    	break;
	    }

	    case PlayerView:
	    {
	    	texture.loadFromFile("resource/Pawn.jpg");
//			playerV.setOutlineColor(sf::Color::White);
//			playerV.setOutlineThickness(3);
	    	break;
	    }

	    case DiceView:
	    {
	    	texture.loadFromFile("resource/Dice.png");
//			diceV.setOutlineColor(sf::Color::White);
//			diceV.setOutlineThickness(3);
	    	break;
	    }

	    case MessageView:
	    {
	    	break;
	    }
	}
	displayObj.setTexture(texture);
    return displayObj;
}

sf::Texture loadTexture(const string strPath)
{
	sf::Texture texture;
	if (!texture.loadFromFile(strPath))
	{
		cout << "Unable to load texture from file:"+strPath << endl;
	}
	texture.setSmooth(true);
	return texture;
}


} /* namespace view */

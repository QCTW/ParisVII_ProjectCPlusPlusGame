/*
 * Window.h
 *
 *  Created on: 1 janv. 2016
 *      Author: Quincy
 */

#ifndef VIEW_WINDOW_HPP_
#define VIEW_WINDOW_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../platform/GameInfo.hpp"
#include "../platform/Platform.hpp"
#include <iostream>
using namespace std;

namespace view
{

class Window
{
private:
    GameInfo* giInfo;
    Platform* pfPlatform;
	void drawPlatform();
    void setEvents(); // Add events
    int nBorderSize;
    int nbCells;
    int nNbOfCellsPerColumn;
    sf::RenderWindow rWindow; // Main window
    sf::Texture cellTexture; // Texture for cell
    sf::Texture pawnTexture; //Texture for pawn
    sf::RectangleShape diceDisplay; //Dice
    sf::Sprite spritePawn;
    sf::RectangleShape rectangleMessageBox;
    sf::Text textMessageBox;
    sf::Font fontGeneral;
    string convertInt2String(int nToConvert);

public:
	Window(GameInfo* gi, Platform* pf);
	virtual ~Window();
	void start(); //Start the GUI
    void refresh(); // Refresh screen
};

} /* namespace view */

#endif /* VIEW_WINDOW_HPP_ */

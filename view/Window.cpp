/*
 * Window.cpp
 *
 *  Created on: 1 janv. 2016
 *      Author: Quincy
 */

#include "Window.hpp"
#include <math.h>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>

namespace view
{

Window::Window(GameInfo* gi, Platform* pf) :
		nBorderSize(2),
		diceDisplay(sf::Vector2f(view::DiceSize, view::DiceSize))
{
	this->giInfo = gi;
	this->pfPlatform = pf;
	this->cellTexture.loadFromFile("resource/BG.jpg");
	this->cellTexture.setSmooth(true);
	this->pawnTexture.loadFromFile("resource/blue.gif");
	this->pawnTexture.setSmooth(true);
	this->fontGeneral.loadFromFile("resource/ComicSansMS.ttf");

	this->nbCells = pfPlatform->getNbCell();
	this->nNbOfCellsPerColumn = (int) sqrt((double) nbCells);
	int nMaxWindowWidth = view::ObjectSize::CellX * nNbOfCellsPerColumn + view::ObjectSize::DiceSize;
	int nMaxWindowHeight = view::ObjectSize::CellY * nNbOfCellsPerColumn + view::ObjectSize::MessageY;
	rWindow.create(sf::VideoMode(nMaxWindowWidth, nMaxWindowHeight), "Game : Serpents et échelles");
}

Window::~Window()
{
}

string Window::convertInt2String(int nToConvert)
{
	ostringstream convert;   // stream used for the conversion
	convert << nToConvert;      // insert the textual representation of 'Number' in the characters in the stream
	return convert.str();
}

void Window::drawPlatform()
{
	int nNbOfX = 0;
	int nNbOfY = 0;
	for(int i=0; i<this->nbCells; i++)
	{
		Cell* cell = pfPlatform->getCell(i);
		if(i%this->nNbOfCellsPerColumn==0 && i!=0)
		{
			nNbOfX = 0;
			nNbOfY++;
		}
		sf::RectangleShape oneCell2Display(sf::Vector2f(CellX, CellY));
		oneCell2Display.setTexture(&cellTexture);
		oneCell2Display.setOutlineThickness(nBorderSize);
		oneCell2Display.setOutlineColor(sf::Color::White);
		oneCell2Display.setPosition(nNbOfX*view::CellX, nNbOfY*view::CellY);
		this->rWindow.draw(oneCell2Display);
		sf::Text oneCellText2Display;
		oneCellText2Display.setFont(fontGeneral);
		oneCellText2Display.setCharacterSize(24);
		oneCellText2Display.setString(this->convertInt2String(cell->getId()+1));
		oneCellText2Display.setPosition(nNbOfX*view::CellX, nNbOfY*view::CellY);
		this->rWindow.draw(oneCellText2Display);
		nNbOfX++;
	}

	Dice* d = giInfo->getDice();
	diceDisplay.setOutlineColor(sf::Color::White);
	diceDisplay.setOutlineThickness(nBorderSize);
	diceDisplay.setFillColor(sf::Color::Yellow);
	diceDisplay.setPosition(nNbOfCellsPerColumn*view::CellX+nBorderSize, 0);
	this->rWindow.draw(diceDisplay);
	sf::Text diceText2Display;
	diceText2Display.setFont(fontGeneral);
	diceText2Display.setColor(sf::Color::Black);
	diceText2Display.setCharacterSize(48);
	diceText2Display.setString(this->convertInt2String(d->GetMoveNumber()));
	diceText2Display.setPosition(nNbOfCellsPerColumn*view::CellX+nBorderSize, 0);
	this->rWindow.draw(diceText2Display);

	int nbPlayers = giInfo->getNbPlayers();
	for(int i=0; i<nbPlayers; i++)
	{
		Player* p = giInfo->getPlayerByID(i);
		sf::RectangleShape onePlayer2Display(sf::Vector2f(PlayerX, PlayerY));
		onePlayer2Display.setOutlineColor(sf::Color::White);
		onePlayer2Display.setOutlineThickness(nBorderSize);
		onePlayer2Display.setFillColor(sf::Color::Red);
		onePlayer2Display.setPosition(nNbOfCellsPerColumn*view::CellX+nBorderSize, i*PlayerY+view::DiceSize);
		this->rWindow.draw(onePlayer2Display);
		sf::Text onePlayerText2Display;
		onePlayerText2Display.setFont(fontGeneral);
		onePlayerText2Display.setColor(sf::Color::Black);
		onePlayerText2Display.setCharacterSize(24);
		onePlayerText2Display.setString(p->getName());
		onePlayerText2Display.setPosition(nNbOfCellsPerColumn*view::CellX+nBorderSize, i*PlayerY+view::DiceSize);
		this->rWindow.draw(onePlayerText2Display);
		RGB& rbg = p->getColor();
		int nbOfPawn = p->getNbPawn();
		for(int n=0; n<nbOfPawn; n++)
		{
			sf::Sprite pawnToDraw;
			pawnToDraw.setTexture(pawnTexture);
			pawnToDraw.setPosition(2, i*view::PawnY+2);
			pawnToDraw.setColor(sf::Color(rbg.R, rbg.G, rbg.B));
			this->rWindow.draw(pawnToDraw);
		}
	}
}

void Window::start()
{
	while (this->rWindow.isOpen())
	{
		setEvents();
		refresh();
	}
}

void Window::setEvents()
{
	// check all the window's events that were triggered since the last iteration of the loop
	sf::Event event;
	while (this->rWindow.pollEvent(event))
	{
		// "close requested" event: we close the window
		if (event.type == sf::Event::Closed)
			this->rWindow.close();
	}
}

void Window::refresh()
{
    // clear the window with black color
	this->rWindow.clear(sf::Color::Black);
	drawPlatform();
	sf::sleep(sf::milliseconds(500)); // Wait 1 second
    // end the current frame
	this->rWindow.display();
}

} /* namespace view */


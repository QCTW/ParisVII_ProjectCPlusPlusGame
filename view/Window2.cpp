/*
 * Window.cpp
 *
 *  Created on: 1 janv. 2016
 *      Author: Quincy
 */

#include "Window.hpp"
#include <math.h>

namespace view
{

Window::Window(GameInfo* gi, Platform* pf) :
		width(600),
		height(600),
		rWindow(sf::VideoMode(width, height), "Game : Serpents et échelles")
{
	this->giInfo = gi;
	this->pfPlatform = pf;
}

Window::~Window()
{
}

void Window::drawPlatform()
{
	int nbCells = pfPlatform->getNbCell();
	int nNbOfCellsPerColumn = (int) sqrt((double) nbCells);
	int nMaxWindowWidth = view::ObjectSize::PawnX * nNbOfCellsPerColumn + view::ObjectSize::DiceSize;
	int nMaxWindowHeight = view::ObjectSize::PawnY * nNbOfCellsPerColumn + view::ObjectSize::MessageY;
	rWindow.setSize(sf::Vector2u(nMaxWindowWidth, nMaxWindowHeight));
	int nNbOfX = 0;
	int nNbOfY = 0;
	for(int i=0; i<nbCells; i++)
	{
		Cell* cell = pfPlatform->getCell(i);
		sf::Sprite cellToDraw = cell->getDisplayObject();
		if(i%nNbOfCellsPerColumn==0 && i!=0)
		{
			nNbOfX=0;
			nNbOfY++;
		}
		cellToDraw.setPosition(nNbOfX*view::CellX, nNbOfY*view::CellY);
		this->rWindow.draw(cellToDraw);
		nNbOfX++;
	}

	Dice* d = giInfo->getDice();
	sf::Sprite diceObj = d->getDisplayObject();
	diceObj.setPosition(nNbOfCellsPerColumn*view::CellX, 0);
	this->rWindow.draw(diceObj);

	int nbPlayers = giInfo->getNbPlayers();
	for(int i=0; i<nbPlayers; i++)
	{
		Player* p = giInfo->getPlayerByID(i);
		sf::Sprite playerLabel = p->getDisplayObject();
		playerLabel.setPosition(nNbOfCellsPerColumn*view::CellX, i*view::PlayerY+view::DiceSize);
		this->rWindow.draw(playerLabel);

		Pawn* pawn = p->getPawn(0);
		sf::Sprite pawnToDraw = pawn->getDisplayObject();
		pawnToDraw.setPosition(2, i*view::PawnY+2);
		this->rWindow.draw(pawnToDraw);
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
    // end the current frame
	this->rWindow.display();
}

} /* namespace view */


#include "Pawn.hpp"
#include <iostream>

int Pawn::pawnsCreated = 0;

Pawn::Pawn() : view::Displayable(view::PawnView)
{
	this->_player = nullptr;
	this->_id = this->pawnsCreated;
	this->cellId = 0;
	this->pawnsCreated++;
}
Pawn::~Pawn()
{
}

Player *Pawn::getPlayer()
{
	return this->_player;
}

void Pawn::setPlayer(Player *player)
{
	if (this->_player == nullptr)
	{
		this->_player = player;
	}
	else
	{
		cout << "[pawn:setPlayer]: The pawn " << this->_id << " is already added to " << this->_player << endl;
	}
}

int Pawn::getId()
{
	return this->_id;
}

void Pawn::setId(int id)
{
	this->_id = id;
}

int Pawn::getCellId()
{
	return this->cellId;
}

void Pawn::setCellId(int id)
{
	this->cellId = id;
}

void Pawn::printInfo()
{
	cout << "[pwn] id N°: " << this->_id << " @: " << this << ", pos:" << this->cellId << " belongs to " << this->_player << endl;
}

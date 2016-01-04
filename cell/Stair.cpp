#include "Stair.hpp"

Stair::Stair(int id, Cell *cell)
: Cell (id)
{
	this->_arrivalCell = cell;
	this->_symbole = 's';
}
Stair::~Stair(){}

Cell *Stair::getArrivalCell(){
	return this->_arrivalCell;
}

void Stair::setArrivalCell(Cell *cell){
	this->_arrivalCell = cell;
}


void Stair::action(Player &player, Pawn &pawn){
	this->removePawn(&pawn);
	cout << this->_arrivalCell->getId() << endl;
	this->getArrivalCell()->add(&pawn);
}
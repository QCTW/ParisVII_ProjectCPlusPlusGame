#include "EmptyCell.hpp"

EmptyCell::EmptyCell(int id)
: Cell(id){
	this->_symbole = 'e';
}

EmptyCell::~EmptyCell(){}
void EmptyCell::action(Player &player, Pawn &pawn){}
#include "GreenCell.hpp"
GreenCell::GreenCell(int id)
: Cell(id){
	this->_symbole = 'g';
}
GreenCell::~GreenCell(){}


// The player can move one more time
void GreenCell::action(Player &player, Pawn &pawn){
	player.setPassMove(true);
}
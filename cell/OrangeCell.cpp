#include "OrangeCell.hpp"

OrangeCell::OrangeCell(int id)
: Cell(id){
	this->_symbole = 'o';
}
OrangeCell::~OrangeCell(){}


void OrangeCell::action(Player &player, Pawn &pawn){
	player.setMoveAgain(true);
}
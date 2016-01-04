#include "SnakeHead.hpp"


SnakeHead::SnakeHead(int id, SnakeTail *tail)
: Cell(id){
	this->_tail = tail;
	this->_symbole = 'h';
}

SnakeHead::~SnakeHead(){}
SnakeTail *SnakeHead::getExtremety(){
	return this->_tail;
}

void SnakeHead::addExtremety(SnakeTail *snakeTail){
	if(this->_tail == 0){
		this->_tail = snakeTail;	
		cout << "[snkhead]: tail added" << endl;
	}
	else{
		cout << "[snkhead]: already has a tail" << endl;
	}
}

void SnakeHead::action(Player &player, Pawn &pawn){
	this->removePawn(&pawn);
	this->getExtremety()->add(&pawn);
}
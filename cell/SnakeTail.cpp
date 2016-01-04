#include "SnakeTail.hpp"

SnakeTail::SnakeTail(int id, SnakeHead *head)
: Cell(id){
	this->_head = head;
	this->_symbole = 't';
}

SnakeTail::~SnakeTail(){}

SnakeHead *SnakeTail::getExtremety(){
	return this->_head;
}

void SnakeTail::addExtremety(SnakeHead *snakeHead){
	if(this->_head == 0){
		this->_head = snakeHead;
		cout << "[snktail: head added" << endl;
	}
	else{
		cout << "[snktail]: already has a head" << endl;
	}
}


void SnakeTail::action(Player &player, Pawn &pawn){
	this->removePawn(&pawn);
	this->getExtremety()->add(&pawn);
}
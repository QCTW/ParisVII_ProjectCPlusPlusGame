#include "Cell.hpp"
#include <iostream>

using namespace std;

Cell::Cell(int id): Displayable(view::CellView), _id(id),_symbole('c'),_pawnMax(-1), _nbPawn(0){
	cout << "[cel:cell]: cell " << this->_id << " @" << this << ", pawns:" << _nbPawn << endl;
}
Cell::~Cell(){}

int Cell::getId(){
	return this->_id;
}

void Cell::setId(int id){
	this->_id = id;
}

char Cell::getSymbole(){
	return this->_symbole;
}

void Cell::setSymbole(char sym){
	this->_symbole = sym;
}

int Cell::getPawnMax(){
	return this->_pawnMax;
}

void Cell::setPawnMax(int nbMax){
	this->_pawnMax = nbMax;
}

bool Cell::isEmpty(){
	if(this->_nbPawn == 0){
		return true;
	}
	else{
		return false;
	}
}
int Cell::getNbPawn(){
	return this->_nbPawn;
}

void Cell::setNbPawn(int nb){
	this->_nbPawn = nb;
}


void Cell::removePawn(Pawn *pawn){
	// cout << "[cell:removePawn]: pawn to remove: " << pawn->getId() << endl;
	for (int i = 0; i < this->_nbPawn; ++i)
	{	
		if(this->tab[i] == pawn){
			this->tab[i] = this->tab[this->_nbPawn-1];
			this->tab[this->_nbPawn-1] = nullptr;
			this->_nbPawn--;
			// cout << "[cel(id)" << this->_id << ":removePawn]:The pawn with id " << pawn->getId() << "has been removed from " << this->getId() << " cell" <<endl; 
			// cout << "[cel:removePawn]:Pawn @ "<< pawn << endl;
		}
	}
}

void Cell::add(Pawn *pawn){

	bool canAdd = true;
	for (int i = 0; i < this->_nbPawn; ++i)
	{
		if(this->tab[i] == pawn){
			canAdd = false;
		}
	}
	if(canAdd){
		this->tab[_nbPawn] = pawn;
		this->_nbPawn++;
		// cout << "[cel(id)" << this->_id <<":add]: Add pawn:" << pawn->getId()<<", total pawns:" <<  this->_nbPawn<<endl;
		// Update of pawn's attribute "cellId"
		pawn->setCellId(this->_id);
	}
	// else{
	// 	cout << "[cell:add]: The pawn" << pawn->getId() << " is already in the cell." << endl;
	// }
}


Pawn *Cell::getPawn(int num){
	return this->tab[num];
}

void Cell::printInfo(){
	cout <<"[cel]nb of pawns: " << this->getNbPawn() << ", id:"<< this->_id<< " @: " << this << 
	"symbole:" << this->_symbole << endl;
}



void action(Player &player,Pawn &pawn){}



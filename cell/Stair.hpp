#ifndef STAIRE_HPP
#define STAIRE_HPP

#include "Cell.hpp"

class Stair : public Cell
{

private: 
	Cell *_arrivalCell;
public:
	Stair(int id, Cell *cell = nullptr);
	~Stair();

	Cell *getArrivalCell();
	void setArrivalCell(Cell *cell);


	void action(Player &player, Pawn &pawn);

};

#endif
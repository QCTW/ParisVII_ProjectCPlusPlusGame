#ifndef EMPTYCELL_HPP
#define EMPTYCELL_HPP

#include "Cell.hpp"

class EmptyCell : public Cell
{
public:
	EmptyCell(int id);
	~EmptyCell();
	void action(Player &player, Pawn &pawn);
};

#endif
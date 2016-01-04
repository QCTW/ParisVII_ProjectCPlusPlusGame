#ifndef GREENCELL_HPP
#define GREENCELL_HPP
#include "Cell.hpp"
class GreenCell : public Cell
{
public:
	GreenCell(int id);
	~GreenCell();
virtual void action(Player &player, Pawn &pawn);
};


#endif
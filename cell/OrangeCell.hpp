#ifndef ORANGECELL_HPP
#define ORANGECELL_HPP
#include "Cell.hpp"

class OrangeCell : public Cell
{
public:
	OrangeCell(int id);
	~OrangeCell();


	// Set the "moveAgainVar on true "
	virtual void action(Player &player, Pawn &pawn);


};


#endif
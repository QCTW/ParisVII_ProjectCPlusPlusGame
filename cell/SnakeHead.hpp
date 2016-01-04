#ifndef SNAKEHEAD_HPP
#define SNAKEHEAD_HPP
#include "Cell.hpp"
#include "SnakeTail.hpp"

// TODO : Implement action in Cell with 3 parameters 
class SnakeTail;
class SnakeHead : public Cell
{
private:
	// The cell linked to this one
	SnakeTail *_tail;
public:
	SnakeHead(int id, SnakeTail *tail = nullptr);
	~SnakeHead();

	SnakeTail *getExtremety();
	void addExtremety(SnakeTail *snakeTail);
	void action(Player &player, Pawn &pawn);
};

#endif
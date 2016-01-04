#ifndef SNAKETAIL_HPP
#define SNAKETAIL_HPP
#include "Cell.hpp"
#include "SnakeHead.hpp"

class SnakeHead;
class SnakeTail : public Cell
{
private:
	// The cell linked to this one
	SnakeHead *_head;
public:
	SnakeTail(int id,SnakeHead *head = nullptr);
	~SnakeTail();

	SnakeHead *getExtremety();
	void addExtremety(SnakeHead *snakeHead);
	void action(Player &player, Pawn &pawn);
};

#endif
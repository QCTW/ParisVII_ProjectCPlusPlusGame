#ifndef HUMAN_HPP
#define HUMAN_HPP
#include "Player.hpp"


class Human : public Player
{

public:
	Human(string name);
	virtual ~Human();
	virtual Pawn *selectPawn();
	virtual string answerQuestion(Question *q);
};

#endif

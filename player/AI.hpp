#ifndef AI_HPP
#define AI_HPP

#include "Player.hpp"

class AI : public Player
{

private:
	bool _intelligent;
public:
	AI(string name, bool intelligent = true);
	virtual ~AI();
	virtual Pawn *selectPawn();
	virtual string answerQuestion(Question *q);	
};


#endif

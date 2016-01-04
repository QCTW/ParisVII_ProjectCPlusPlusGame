#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
#include "Pawn.hpp"
#include "../platform/Platform.hpp"
#include "../platform/Question.hpp"
#include "../view/Displayable.hpp"

using namespace std;
// Class abstraite
class Platform;
class Player : public view::Displayable
{
protected:
	int _id;
	int _nbPawn;

	string _name;
	
	int _rightAnswers;

	bool _moveAgain;
	bool _passMove;

	Pawn *myPawns[5];
	Pawn *selectedPawn;

public:
	static int nbPlayers;
	Player(string name);
	virtual ~Player();
	int getId();

	string getName();
	void setName(string name);
	int getNbPawn();

	// Add a pawn if the player doesn't have this pawn
	void addPawn(Pawn *pawn);

	// Checks whether the pawn is already in the table
	bool hasPawn(Pawn *pawn);

	Pawn *getPawn(int num);
	Pawn *getSelectedPawn();
	void setSelectedPawn(Pawn *pawn);

	int getRightAnswers();
	void incRightAnswers();
	void setRightAnswers(int num);

	bool getMoveAgain();
	void setMoveAgain(bool mvAgain);

	bool getPassMove();
	void setPassMove(bool mvPass);

	void repealEffects();

	virtual string answerQuestion(Question *q);

	void printInfo();

	virtual Pawn *selectPawn() = 0;
	virtual void movePawn(int numberOfStep, Pawn *pawn, Platform *platform);

};

#endif

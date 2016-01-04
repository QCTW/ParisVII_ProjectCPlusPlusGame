#ifndef CELL_HPP
#define CELL_HPP
#include "../player/Pawn.hpp"
#include "../player/Player.hpp"
#include "../view/Displayable.hpp"
//Class abstraite

class Player;
class Pawn;
class Cell : public view::Displayable
{
protected:
	Pawn *tab[20];
	// Position
	int _id;
	// Pour differencier les cases
	char _symbole;

	//Nombre maximal de pions par case 
	// Si -1 alors illimité
	int _pawnMax;
	int _nbPawn;

public:
	Cell(int id);
	virtual ~Cell();
	int getId();
	void setId(int id);
	char getSymbole();
	void setSymbole(char sym);
	int getPawnMax();
	void setPawnMax(int nbMax);
	int getNbPawn();
	void setNbPawn(int nb);

	void add(Pawn *pawn);
	void removePawn(Pawn *pawn);
	Pawn *getPawn(int num);


	bool isEmpty();

	void printInfo();

	// Action of the cell
	// if true then we can move the pawn 
	virtual void action(Player &player, Pawn &pawn) = 0;
};


#endif

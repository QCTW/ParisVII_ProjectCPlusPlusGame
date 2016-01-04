#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include "../cell/Cell.hpp"
#include "../player/Pawn.hpp"

#include <iostream>
using namespace std;
class Cell;
class Platform
{
private:
	// Max nb on the platform
	int nbCell;
	// Nb of added cells
	int addedCell;
	Cell** cellTab;

	/* Test: pour voir s'il y a nb case vide dans 
	 l'intervalle [min,max] */

	// Renvoi un tableau avec les ID des cases vides des snakes
	void stockEmptyCellsIds(int tab[]);

	// Renvoi un tableau avec les ID des cases vides des echelles
	void stockEmptyCellsIds2(int tab[]);

	// Renvoid true si on peux ajouter encore un snake
	bool isPossibleAddSnake(int tab[]);

	// Retourne l'ID possible du snakeTail
	int getSnakeTailId(int idSH, int tab[]);

	// Retourne l'ID possible du snakeHead
	int getSnakeHeadId(int tab[]);

	// Retourne l'ID pour la case d'arrivée de l'echelle
	int getArrivalCellId(int strId);

	// Retourne l'ID pour la case de départ de l'echelle
	int getDepartCellid(int tab[]);


public:
	bool hasEmpty(int nb, int min, int max);

	// Retourne le nb de case vide
	int getNbEmptyCell(int indMin, int indMax);

	Platform(int nbCell);
	~Platform();

	int getNbCell();
	bool add(Cell *c);
	void show();
	Cell* getCell(int num);
	void updateCell(int nbStep, Pawn *pawn);
	void printInfo(bool withCells = false);
	void printCells();

	void showPlatform();

	// Remplie la platforme (ajoute les cases vides)
	void hydrate();

	// TODO: Définir la taille minimale et maximale d'une platforme
	/*Minimum 5 cases*/
	void hydrateWithCells(int nbOrg, int nbGr, int nbSnk, int nbStr);

};

#endif

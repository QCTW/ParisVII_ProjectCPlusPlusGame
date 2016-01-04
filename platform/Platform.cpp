#include "Platform.hpp"
#include "../cell/EmptyCell.hpp"
#include "../cell/OrangeCell.hpp"
#include "../cell/GreenCell.hpp"
#include "../cell/SnakeHead.hpp"
#include "../cell/SnakeTail.hpp"
#include "../cell/Stair.hpp"

Platform::Platform(int nbCell)
{
	this->nbCell = nbCell;
	this->cellTab = new Cell*[nbCell];
	this->addedCell = 0;
	// Initialisation du tableau de cases
	for (int i = 0; i < this->nbCell; ++i)
	{
		this->cellTab[i] = 0;
	}
}
;

Platform::~Platform()
{
	// cout << "The platform has been deleted" << endl;
}
;

int Platform::getNbCell()
{
	return this->nbCell;
}

bool Platform::add(Cell *c)
{
	cout << "[In add] -> Add Cell @:" << c << endl;
	if (cellTab[c->getId()] == 0)
	{
		this->cellTab[c->getId()] = c;
		this->addedCell++;
		return true;
	}
	else
	{
		cout << "A cell at this position exists already!!!" << endl;
		return false;
	}
}

void Platform::show()
{
	cout << this->nbCell << " Cell(s)" << endl;
	for (int i = 0; i < nbCell; ++i)
	{
		cout << this->cellTab[i] << endl;
	}
}

Cell *
Platform::getCell(int num)
{
	return this->cellTab[num];
}

// Moving of a pawn from one Cell to another one
void Platform::updateCell(int nbStep, Pawn *pawn)
{
	// cout << "[plt:updateCell]:Moving of pawn " << pawn->getId() << endl;
	// cout << "[plt:updateCell]: nbCell = " << this->nbCell << endl;
	this->cellTab[pawn->getCellId()]->removePawn(pawn);
	// cout << "[plt]new pos :" << pawn->getCellId() + nbStep << endl;
	//Check wether we are out of the platform
	if ((pawn->getCellId() + nbStep) > this->nbCell-1)
	{
		//We put it at the last cell
		this->cellTab[this->nbCell - 1]->add(pawn);
	}
	else
	{
		//Or we move normally
		this->cellTab[pawn->getCellId() + nbStep]->add(pawn);
	}

	// On applique l'action de la case
	this->cellTab[pawn->getCellId()]->action(*pawn->getPlayer(), *pawn);
}

void Platform::showPlatform()
{
	for (int i = 0; i < this->nbCell; ++i)
	{

		if (this->cellTab[i] != 0)
		{
			cout << "|" << this->getCell(i)->getSymbole() << "|";
		}
		else
		{
			cout << "|" << '0' << "|";
		}

		if ((i + 1) % 10 == 0)
		{
			cout << "" << endl;
		}
	}

	// Retour à la ligne
	cout << "" << endl;
}

void Platform::printInfo(bool withCells)
{
	cout << "[plt]nbofCells: " << this->nbCell << " @: " << this << endl;

	if (withCells)
	{
		for (int i = 0; i < this->nbCell; ++i)
		{
			cellTab[i]->printInfo();
		}
	}
}

void Platform::hydrate()
{
	int cmp = 0;
	for (int i = 0; i < this->nbCell; ++i)
	{
		if (this->cellTab[i] == 0)
		{
			this->cellTab[i] = new EmptyCell(i);
			cmp++;

		}
	}
	// cout << cmp << " empty cell(s)" << endl;
	// cout << this->cellTab[0] << endl;
}

void Platform::hydrateWithCells(int nbOrg, int nbGr, int nbSnk, int nbStr)
{
	/* On crée les cellule uniquement entre la 2 et l'avant derniere position
	 ** le reste est rempli avec des cellules vide */
	cout << "[plt]: " << nbOrg << " orge " << nbGr << " grn " << nbSnk << " snakes to add" << endl;

	int min = 1;
	int max = this->nbCell - 1;
	srand(time(NULL)); // Seed the time
	int finalNum = rand() % (max - min) + min; // Generate the number, assign to variable.

	if ((nbOrg + nbGr + nbSnk + nbStr) <= this->nbCell)
	{
		int i = 0;
		while (i < nbOrg)
		{
			srand(time(NULL));
			finalNum = rand() % (max - min) + min;
			if (this->cellTab[finalNum] == 0)
			{
				this->cellTab[finalNum] = new OrangeCell(finalNum);
				cout << "[plt]: orange cell at postion:" << finalNum << "has been added" << endl;
				++i;
			}
			// cout << "inifite1" << endl;
		}

		i = 0;
		finalNum = 0;

		while (i < nbGr)
		{
			srand(time(NULL));
			finalNum = rand() % (max - min) + min;
			if (this->cellTab[finalNum] == 0)
			{
				this->cellTab[finalNum] = new GreenCell(finalNum);
				cout << "[plt]: green cell at postion:" << finalNum << "has been added" << endl;
				++i;
			}
			// cout << "inifite2" << endl;
		}

		/* Conditions:
		 1 Taille minimale de la platforme est 10 (1first, 1 last, 5 écart entre first et last,
		 deux cases vides avec une case d'ecart).

		 2 Snaketail doit être au moins 5 cases avant la deniere.
		 3 SnakeTail doit avoir au moins une case d'écart entre la snakehead.
		 4 on n'aura pas de cases snake s'il y a moins de 9 case dans la platforme.*/

		int idSH = 0;
		int idST = 0;

		if (this->nbCell > 9)
		{
			// S'il y a au moins 2 fois nbSnk cases vides
			if (this->hasEmpty(nbSnk * 2, 1, this->nbCell - 7))
			{
				// tableau avec les id des cases vides
				int tmpTab[getNbEmptyCell(1, this->nbCell - 7)];
				this->stockEmptyCellsIds(tmpTab);

				// Compte les cell snakes créées
				int snkCreated = 0;
				while (this->isPossibleAddSnake(tmpTab) && (snkCreated < nbSnk))
				{
					// int idSH = 1;
					idSH = getSnakeHeadId(tmpTab);
					idST = this->getSnakeTailId(idSH, tmpTab);
					cout << "idSH: " << idSH << endl;
					cout << "idST: " << idST << endl;
					SnakeHead *sh = new SnakeHead(idSH);
					SnakeTail *st = new SnakeTail(idST);
					sh->addExtremety(st);
					st->addExtremety(sh);

					this->cellTab[idSH] = sh;
					this->cellTab[idST] = st;

					this->stockEmptyCellsIds(tmpTab);

					// idSH++;

					snkCreated++;
				}
			}
		}

		int stairCreated = 0;
		if (this->hasEmpty(nbStr, 1, this->nbCell - 1 - 3))
		{
			int tmpTab[getNbEmptyCell(1, nbCell - 1 - 3)];
			this->stockEmptyCellsIds2(tmpTab);
			int depID;
			int arrID;
			while ((stairCreated < nbStr) && (this->getNbEmptyCell(1, this->nbCell - 1 - 3) >= (nbStr - stairCreated)))
			{
				depID = getDepartCellid(tmpTab);
				arrID = getArrivalCellId(depID);
				cout << "[plt]: depID = " << depID << endl;
				cout << "[plt]: arrID = " << arrID << endl;
				Stair *st = new Stair(depID);
				st->setArrivalCell(this->getCell(arrID));
				this->cellTab[depID] = st;
				stairCreated++;
			}

		}
	}
		this->hydrate();
}

// Min Max inclus
bool Platform::hasEmpty(int nb, int min, int max)
{

	if (min < 0)
	{
		min = 0;
	}
	if(max > this->nbCell - 1){
		max = this->nbCell;
	}


	cout << "min = " << min << ", max = " << max << endl;
	int tmp = 0;

	for (int i = min; i <= max; ++i)
	{
		if (this->cellTab[i] == 0)
		{
			++tmp;
		}
	}
	/*aucune case entre min et max (on ne parle pas d'objet EmptyCell ici)!*/
	cout << "[plt]: has " << tmp << " empty cells in [" << min << "," << max << "]" << endl;
	if (tmp >= nb)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Platform::stockEmptyCellsIds(int tab[])
{
	/* Tableau pour stocker les id des cases vides qu'on peux prendre pour
	 les cases snakes */

	/*Initialisation*/

	cout << "[plt:stockEmptyCellsIds]: Dans [0 " << this->nbCell - 7 - 1 << "]" << endl;
	cout << "[plt:stockEmptyCellsIds]: tableau de " << getNbEmptyCell(1, this->nbCell - 7) << " cases" << endl;
	for (int i = 0; i < getNbEmptyCell(1, this->nbCell - 7); ++i)
	{
		tab[i] = 0;
	}
	cout << "[plt]: Array has been initialized" << endl;
	cout << "[plt]: " << this->nbCell << " cells" << endl;

	int c = 0;
	// Entre la case 1 et (nbCell avec un écart de 5 cases)
	for (int i = 1; i <= this->nbCell - 7; ++i)
	{
		if (this->cellTab[i] == 0)
		{
			tab[c] = i; // Id de la case vide
			++c;
		}
	}

	for (int i = 0; i < c; ++i)
	{
		cout << "[plt]: vide " << tab[i] << endl;
	}

}

bool Platform::isPossibleAddSnake(int tab[])
{

	cout << "[plt:isPossibleAddSnake]: affichage du tableau" << endl;
	// for (int i = 0; i < getNbEmptyCell(1,this->nbCell-7); ++i)
	// {
	// 	cout << " empty: " << tab[i] << endl;
	// }

	int res = 0;
	for (int i = 0; i < getNbEmptyCell(1, this->nbCell - 7); ++i)
	{
		for (int j = i; j < getNbEmptyCell(1, this->nbCell - 7); ++j)
		{
			if ((tab[j] - tab[i]) == 2)
			{
				res++;
			}
		}
	}
	if (res > 0)
	{
		cout << "[plt]: On peut ajouter un snake( sh et st)" << endl;
		return true;
	}
	else
	{
		cout << "[plt]: On ne peut pas ajouter un snake( sh et st)" << endl;
		return false;
	}

}

int Platform::getSnakeTailId(int idSH, int tab[])
{
	cout << "Dans getSnakeTailId" << endl;
	cout << "idSH:" << idSH << endl;

	// tableau temporaire où on va stocker les id des snaketails possibles
	int psbleTab[getNbEmptyCell(idSH, this->nbCell - 7)];
	cout << "-----taille du tableau------" << getNbEmptyCell(idSH, this->nbCell - 7) << endl;
	cout << "-----idSH = " << idSH << endl;

	// Initialisation du tableau
	for (int i = 0; i < getNbEmptyCell(idSH, this->nbCell - 7); ++i)
	{
		psbleTab[i] = 0;
	}
	int c1 = 0; // compteur des id possibles
	for (int i = 0; i < getNbEmptyCell(1, this->nbCell - 7); ++i)
	{

		if ((tab[i] - idSH) > 1)
		{
			psbleTab[c1] = tab[i];
			cout << "possible index is :" << psbleTab[c1] << endl;
			c1++;
		}
	}
	// c1 le nb de case dans psbleTab donc ça va de 0 à c1-1

	c1--; // Indice du derniere element du tableau
	// Prenenons aleatoirement une valeur du tableau

	int ind = 0;
	if (c1 > 0)
	{
		srand(time(NULL));
		ind = rand() % (c1 - 0) + 0;
	}

	cout << "c1= " << c1 << endl;
	cout << "Alea = " << ind << endl;
	cout << "[plt]: valeur alea choisi = " << psbleTab[ind] << endl;
	return psbleTab[ind];

}

int Platform::getNbEmptyCell(int indMin, int indMax)
{
	int res = 0;
	if (indMax > this->nbCell - 1)
	{
		indMax = this->nbCell - 1;
	}

	for (int i = indMin; i <= indMax; ++i)
	{
		if (this->cellTab[i] == 0)
		{
			res++;
		}
	}
	return res;
}

int Platform::getSnakeHeadId(int tab[])
{
	int indLast = getNbEmptyCell(1, this->nbCell - 7);
	int indPreLast = indLast - 1;
	int min = 1;
	int res = 0;
	/* Condition:
	 On prend toutes les cases sauf la deniere (et l'avant derniere s'il y a un écart < 2)
	 */
	if (tab[indLast] - tab[indPreLast] >= 1)
	{
		srand(time(NULL));
		res = rand() % (indPreLast - min) + min;
		return res;
	}
	else
	{
		res = rand() % (indPreLast - 1 - min) + min;
		return res;
	}
}

// La case d'arrive peut être une case de n'importe quel type
int Platform::getArrivalCellId(int strId)
{
	int max = (this->nbCell - 1) - 1; // L'avant derniere case
	int min = strId + 2; // Au moins une case d'écart avec la case de départ
	if (max != min)
	{
		srand(time(NULL));
		int res = 0;
		cout << "[plt:getArrivalCellId]: MIN = " << min << endl;
		cout << "[plt:getArrivalCellId]: MAX = " << max << endl;
		res = rand() % (max - min) + min;
		return res;
	}
	else
	{
		return max;
	}
}

/*Choisie un ID d'une case vide*/
int Platform::getDepartCellid(int tab[])
{
	int min = 1;
	int max = getNbEmptyCell(1, this->nbCell - 1 - 3);

	if (min != max)
	{
		srand(time(NULL));
		int res = 0;
		cout << "[plt:getDepartCellid]: MIN = " << min << endl;
		cout << "[plt:getDepartCellid]: MAX = " << max << endl;
		res = rand() % (max - min) + min;
		return tab[res];
	}
	else
	{
		return tab[max];
	}
}

void Platform::stockEmptyCellsIds2(int tab[])
{
	/* Tableau pour stocker les id des cases vides qu'on peux prendre pour
	 les cases stair */

	/*Initialisation*/

	cout << "[plt:stockEmptyCellsIds2]: Dans [0 " << this->nbCell - 1 - 3 << "]" << endl;
	cout << "[plt:stockEmptyCellsIds2]: tableau de " << getNbEmptyCell(1, this->nbCell - 1 - 3) << " cases" << endl;
	for (int i = 0; i < getNbEmptyCell(1, this->nbCell - 1 - 3); ++i)
	{
		tab[i] = 0;
	}
	cout << "[plt]: Array has been initialized" << endl;
	cout << "[plt]: " << this->nbCell << " cells" << endl;

	int c = 0;
	// Entre la case 1 et (nbCell avec un écart de 5 cases)
	for (int i = 1; i <= this->nbCell - 1 - 3; ++i)
	{
		if (this->cellTab[i] == 0)
		{
			tab[c] = i; // Id de la case vide
			++c;
		}
	}

	for (int i = 0; i < c; ++i)
	{
		cout << "[plt]: vide " << tab[i] << endl;
	}

}

void Platform::printCells()
{
	for (int i = 0; i < this->nbCell; ++i)
	{
		cout << "[plt:printCells]: ID ->" << this->getCell(i)->getId() << ", symbole:" << this->getCell(i)->getSymbole() << ", has" << this->getCell(i)->getNbPawn() << endl;
	}
}





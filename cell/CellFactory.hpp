#ifndef CELLFACTORY_HPP
#define CELLFACTORY_HPP
#include "Cell.hpp"
#include "EmptyCell.hpp"
#include "OrangeCell.hpp"
#include "GreenCell.hpp"
#include "SnakeHead.hpp"
#include "SnakeTail.hpp"
#include "Stair.hpp"


class CellFactory
{
public:
	static int nbEmptyCellCreated;
	static int nbOrangeCreated;
	static int nbGreenCreated;
	static int nbSnakeHeadCreated;
	static int nbSnakeTailCreated;
	static int nbStairCreated;

	CellFactory();
	~CellFactory();

	static EmptyCell *getEmptyCell(int id);
	static OrangeCell *getOrangeCell(int id);
	static GreenCell *getGreenCell(int id);
	static SnakeHead *getSnakeHead(int id);
	static SnakeTail *getSnakeTail(int id);
	static Stair *getStair(int id);



};


#endif
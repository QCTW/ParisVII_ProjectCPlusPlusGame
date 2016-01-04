#include "CellFactory.hpp"

CellFactory::CellFactory(){}
CellFactory::~CellFactory(){}

int CellFactory::nbEmptyCellCreated = 0;
int CellFactory::nbOrangeCreated = 0;
int CellFactory::nbGreenCreated = 0;
int CellFactory::nbSnakeHeadCreated = 0;
int CellFactory::nbSnakeTailCreated = 0;
int CellFactory::nbStairCreated = 0;

EmptyCell *CellFactory::getEmptyCell(int id){
	CellFactory::nbEmptyCellCreated++;
	return new EmptyCell(id);
}
OrangeCell *CellFactory::getOrangeCell(int id){
	CellFactory::nbOrangeCreated++;
	return new OrangeCell(id);
}
GreenCell *CellFactory::getGreenCell(int id){
	CellFactory::nbGreenCreated++;
	return new GreenCell(id);
}
SnakeHead *CellFactory::getSnakeHead(int id){
	CellFactory::nbSnakeHeadCreated++;
	return new SnakeHead(id);
}
SnakeTail *CellFactory::getSnakeTail(int id){
	CellFactory::nbSnakeTailCreated++;
	return new SnakeTail(id);
}
Stair *CellFactory::getStair(int id){
	CellFactory::nbStairCreated++;
	return new Stair(id);
}

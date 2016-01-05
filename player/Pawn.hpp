#ifndef PAWN_HPP
#define PAWN_HPP
#include <string>
#include "../view/Displayable.hpp"
#include "../view/RGB.hpp"
using namespace std;
class Player;
class Pawn : public view::Displayable
{
private:
	int _id;
	Player *_player;

	// Position in cell
	int cellId;
public:
	static int pawnsCreated;

	Pawn();
	~Pawn();

	Player *getPlayer();
	void setPlayer(Player *player);

	int getPosInCell();
	void setPosInCell(int pos);
	int getId();
	void setId(int id);
	int getCellId();
	void setCellId(int id);
	void printInfo();

};

#endif

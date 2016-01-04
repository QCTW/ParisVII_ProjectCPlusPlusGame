#include "all.hpp"

int main(int argc, char const *argv[])
{

	// GAMEINFO
	GameInfo *gi = new GameInfo(1);

	// PLAYERS
	Human *human1 = PlayerFactory::getHumanPlayer("Humanlayer1");
	AI *iaPlayer1 = PlayerFactory::getIAPlayer("IAPlayer1", true);

	// PAWNS
	Pawn *pawn1 = new Pawn();
	// Pawn *pawn2 = new Pawn();
	human1->addPawn(pawn1);
	// human1->addPawn(pawn2);

	Pawn *pawn3 = new Pawn();
	// Pawn *pawn4 = new Pawn();
	iaPlayer1->addPawn(pawn3);
	// iaPlayer1->addPawn(pawn4);

	// PLATFORM
	Platform *plt = new Platform(50);
	plt->hydrateWithCells(10,10,2,1);

	// DICE
	Dice *dice = new Dice(6);

	// ADDING OF GAME OBJECTS
	gi->addPlayer(human1);
	gi->addPlayer(iaPlayer1);
	gi->addPlatform(plt);
	gi->addDice(dice);

	// INITIALISATION
	GameUtils::initializeGame(gi);

	//RUN THE GAME
	GameUtils::play(gi, false);

	return 0;
}

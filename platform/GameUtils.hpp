#ifndef GAMEUTILS_HPP
#define GAMEUTILS_HPP
#include "GameInfo.hpp"
#include "../player/Player.hpp"
#include "../platform/Question.hpp"
#include "../platform/QuestionFactory.hpp"


class GameUtils
{
public:
	GameUtils();
	~GameUtils();

	static void initializeGame(GameInfo *gameinfo, bool generatePawns = false);
	static Player *getWinner(GameInfo *gameinfo);
	static void moveWithQuestion(int steps, Player *player, GameInfo *gi);

	// Returns true if all pawns of the player are in the same cell
	static bool allPawnsSameCell(Player *player);

	static void play(GameInfo *gameinfo, bool questions = false);


};
	

#endif
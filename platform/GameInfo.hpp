#ifndef GAMEINFO_HPP
#define GAMEINFO_HPP
#include "../player/Player.hpp"
#include "../move/Dice.hpp"
class GameInfo
{
private:
	int maxPawnPerCell;
	int nbPlayers;
	int nbPawns;
	Player *players[20];
	Platform *platform;
	Dice *dice;

public:
	GameInfo(int nbPawns = 1, int maxPawnPerCell = 0);
	~GameInfo();
	int getMaxPawnPerCell();
	void setMaxPawnPerCell(int nb);
	int getNbPawns();
	void setNbPawns(int nbPawns);

	int getNbPlayers();

	Player *getPlayerByID(int id);
	void addPlayer(Player *player);
	void removePlayer(Player *player);

	Platform *getPlatform();
	void addPlatform(Platform *platform);

	void addDice(Dice *dice);
	Dice *getDice();

	void showGameStat();

};

#endif

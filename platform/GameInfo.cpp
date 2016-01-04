#include "GameInfo.hpp"

GameInfo::GameInfo(int nbPawns, int maxPawnPerCell) :
		dice(nullptr)
{
	this->maxPawnPerCell = maxPawnPerCell;
	this->nbPlayers = 0;
	this->nbPawns = nbPawns;
	for (int i = 0; i < 20; ++i)
	{
		this->players[i] = nullptr;
	}
	this->platform = nullptr;
}
GameInfo::~GameInfo()
{
}

int GameInfo::getMaxPawnPerCell()
{
	return this->maxPawnPerCell;
}
void GameInfo::setMaxPawnPerCell(int nb)
{
	this->maxPawnPerCell = nb;
}
int GameInfo::getNbPlayers()
{
	return this->nbPlayers;
}

int GameInfo::getNbPawns()
{
	return this->nbPawns;
}

void GameInfo::addPlayer(Player *player)
{
	this->players[player->getId()] = player;
	this->nbPlayers++;
}

Player *GameInfo::getPlayerByID(int id)
{
	Player *res = nullptr;

	for (int i = 0; i < nbPlayers; ++i)
	{
		if (this->players[i]->getId() == id)
		{
			res = this->players[i];
			break;
		}
	}
	return res;
}

void GameInfo::removePlayer(Player *player)
{
	Player *tmp = nullptr;
	int id = player->getId();

	for (int i = 0; i < nbPlayers; ++i)
	{
		if (this->players[i]->getId() == id)
		{
			this->players[i] = tmp;
			break;
		}
	}
}

Platform *GameInfo::getPlatform()
{
	Platform *res = nullptr;
	if (this->platform != nullptr)
	{
		res = this->platform;
	}
	return res;
}

void GameInfo::addPlatform(Platform *platform)
{
	this->platform = platform;
}

void GameInfo::showGameStat()
{
	for (int i = 0; i < this->nbPlayers; ++i)
	{
		cout << "Player: " << this->players[i]->getName() << ", score: " << this->players[i]->getRightAnswers() << endl;
		cout << "MoveAgain: " << this->players[i]->getMoveAgain() << endl;
		cout << "PassMove: " << this->players[i]->getPassMove() << endl;
		cout << "Score: " << this->players[i]->getRightAnswers() << endl;
		for (int j = 0; j < this->nbPawns; ++j)
		{
			cout << "Pawn: " << this->players[i]->getPawn(j)->getId() << ", pos: " << this->players[i]->getPawn(j)->getCellId() << " @ cell: "
					<< platform->getCell(this->players[i]->getPawn(j)->getCellId())->getSymbole() << endl;
		}
	}
}

void GameInfo::addDice(Dice *dice)
{
	this->dice = dice;
}

Dice *GameInfo::getDice()
{
	return this->dice;
}


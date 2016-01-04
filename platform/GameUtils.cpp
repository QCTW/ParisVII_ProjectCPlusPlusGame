#include "GameUtils.hpp"
#include "QuestionFactory.hpp"

GameUtils::GameUtils(){}
GameUtils::~GameUtils(){}

void GameUtils::initializeGame(GameInfo *gameinfo, bool generatePawns){

	// Positionement des tous les pions à la premiere case
	for (int j = 0; j < gameinfo->getNbPlayers(); ++j)
	{
		for (int i = 0; i < gameinfo->getNbPawns(); ++i)
		{
			gameinfo->getPlatform()->getCell(0)->add(gameinfo->getPlayerByID(j)->getPawn(i));
		}
	}

}

Player *GameUtils::getWinner(GameInfo *gameinfo){
	Player *winner = nullptr;
	Platform *plt = gameinfo->getPlatform();

	Cell *cell = plt->getCell(plt->getNbCell() - 1);

	// cout << "LastCell is " << cell->getId() << ", symbole" << cell->getSymbole() << ", nb pawns" <<cell->getNbPawn() <<endl;


	if(gameinfo->getNbPawns() == 1 && cell->getNbPawn() > 0){
		winner = cell->getPawn(0)->getPlayer();
		cout << "WE HAVE A WINNER: " << winner->getName() << endl;
	}
	else{
		if(cell->getNbPawn() > 0){
			for (int i = 0; i < cell->getNbPawn(); ++i)
			{
				if(allPawnsSameCell(cell->getPawn(i)->getPlayer()) == true){
					winner = cell->getPawn(i)->getPlayer();
					cout << "WE HAVE A WINNER: " << winner->getName() << endl;
					break;
				}
			}
		}
	}

	return winner;

}

bool GameUtils::allPawnsSameCell(Player *player){
		// cout << "ici " << endl;
	bool res = true;
	if(player->getNbPawn() == 1){
		res = true;
	}
	else{
		int pos = player->getPawn(0)->getCellId();

		for (int i = 1; i < player->getNbPawn(); ++i)
		{
			if(pos != player->getPawn(i)->getCellId()){
				res = false;
			}
		}
	}
	return res;

}


void GameUtils::play(GameInfo *gameinfo, bool questions){
	int steps = 0;
	Player *currentPlayer = nullptr;
	Platform *plt = gameinfo->getPlatform();
	plt->showPlatform();
	gameinfo->showGameStat();

	if(questions == false){
		while(GameUtils::getWinner(gameinfo) == nullptr ){

			for (int i = 0; i < gameinfo->getNbPlayers(); ++i)
			{

				currentPlayer = gameinfo->getPlayerByID(i);
				cout << currentPlayer->getName() << "'s turn!" << endl;
				steps = gameinfo->getDice()->GetMoveNumber();


				if(currentPlayer->getPassMove() == false){
					currentPlayer->movePawn(steps,currentPlayer->selectPawn(),plt);
				}
				else{
					cout << currentPlayer->getName() << " can't pass this turn" << endl;
					currentPlayer->setPassMove(false);
				}

				while(currentPlayer->getMoveAgain() == true){
					plt->showPlatform();
					// currentPlayer->printInfo();
					gameinfo->showGameStat();
					currentPlayer->setMoveAgain(false);
					cout << currentPlayer->getName() << "'s turn again!" << endl;
					steps = gameinfo->getDice()->GetMoveNumber();
					currentPlayer->movePawn(steps,currentPlayer->selectPawn(),plt);				
				}

				

				plt->showPlatform();
				// currentPlayer->printInfo();
				// plt->printInfo(true);
				gameinfo->showGameStat();
			}
		}
	}
	else{
		while(GameUtils::getWinner(gameinfo) == nullptr ){

			for (int i = 0; i < gameinfo->getNbPlayers(); ++i)
			{

				currentPlayer = gameinfo->getPlayerByID(i);
				cout << currentPlayer->getName() << "'s turn!" << endl;
				steps = gameinfo->getDice()->GetMoveNumber();


				if(currentPlayer->getPassMove() == false){
					// currentPlayer->movePawn(steps,currentPlayer->selectPawn(),plt);
					moveWithQuestion(steps,currentPlayer,gameinfo);
				}
				else{
					cout << currentPlayer->getName() << " can't pass this turn" << endl;
					currentPlayer->setPassMove(false);
				}

				while(currentPlayer->getMoveAgain() == true){
					plt->showPlatform();
					// currentPlayer->printInfo();
					gameinfo->showGameStat();
					currentPlayer->setMoveAgain(false);
					cout << currentPlayer->getName() << "'s turn again!" << endl;
					steps = gameinfo->getDice()->GetMoveNumber();
					// currentPlayer->movePawn(steps,currentPlayer->selectPawn(),plt);			
					moveWithQuestion(steps,currentPlayer,gameinfo);	
				}

				

				plt->showPlatform();
				// currentPlayer->printInfo();
				// plt->printInfo(true);
				gameinfo->showGameStat();
			}
		}
	}

}



void GameUtils::moveWithQuestion(int steps, Player *player, GameInfo *gi){
	player->movePawn(steps,player->selectPawn(),gi->getPlatform());
	QuestionFactory *qf = QuestionFactory::getInstance();
	Question *q = qf->getArithmeticsQuestion();

	gi->getPlatform()->showPlatform();
	gi->showGameStat();

	string answer = "";
	answer = player->answerQuestion(q);


	if(answer != q->getAnswer()){
		// Move backwards
		gi->getPlatform()->updateCell(0-steps,player->getSelectedPawn());

		// Repeal any effects of the cells on player
		player->repealEffects();

		gi->getPlatform()->showPlatform();
		gi->showGameStat();	
		cout << player->getName() << " gives wrong answer!" << endl;
	}
	else{
		player->incRightAnswers();
		cout << player->getName() << " gives right answer!" << endl;
	}
}








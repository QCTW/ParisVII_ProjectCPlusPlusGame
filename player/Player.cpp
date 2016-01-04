#include "Player.hpp"

int Player::nbPlayers = 0;

Player::Player(string name) : Displayable(view::PlayerView)
{
	this->_id = this->nbPlayers;
	this->_nbPawn = 0;
	this->_name = name;
	this->_moveAgain = false;
	this->_passMove = false;
	this->_rightAnswers = 0;
	cout << "[player]: " << this->_name << " has been created" << endl;
	this->nbPlayers++;
	this->selectedPawn = 0;
}
Player::~Player()
{
}

int Player::getId()
{
	return this->_id;
}

Pawn *Player::getPawn(int num)
{
	return this->myPawns[num];
}

string Player::getName()
{
	return this->_name;
}
void Player::setName(string name)
{
	this->_name = name;
}
int Player::getNbPawn()
{
	return this->_nbPawn;
}

void Player::movePawn(int numberOfStep, Pawn *pawn, Platform *platform)
{
	cout << "[player]: " << this->_name << ", moves pawn N°" << pawn->getId() + 1 << endl;
	platform->updateCell(numberOfStep, pawn);
}

void Player::addPawn(Pawn *pawn)
{
	if (!hasPawn(pawn))
	{
		if (this->_nbPawn < 5)
		{
			this->myPawns[this->_nbPawn] = pawn;
			this->_nbPawn++;
			pawn->setPlayer(this);
			cout << "[player]: Pawn added" << endl;
		}
		else
		{
			cout << "[player]: has already 5 pawns" << endl;
		}
	}
}

bool Player::hasPawn(Pawn *pawn)
{
	bool res = false;
	for (int i = 0; i < this->_nbPawn; ++i)
	{
		if (this->myPawns[i] == pawn)
		{
			res = true;
		}
	}
	return res;
}

int Player::getRightAnswers()
{
	return this->_rightAnswers;
}
void Player::incRightAnswers()
{
	this->_rightAnswers++;
}
void Player::setRightAnswers(int num)
{
	this->_rightAnswers = num;
}
bool Player::getMoveAgain()
{
	return this->_moveAgain;
}
void Player::setMoveAgain(bool mvAgain)
{
	this->_moveAgain = mvAgain;
}

bool Player::getPassMove()
{
	return this->_passMove;
}
void Player::setPassMove(bool mvPass)
{
	this->_passMove = mvPass;
}


void Player::repealEffects(){
	this->_passMove = 0;
	this->_moveAgain = 0;
}

string Player::answerQuestion(Question *q){	return "";}


Pawn *Player::selectPawn()
{
	return nullptr;
}

Pawn *Player::getSelectedPawn(){
	return this->selectedPawn;
}

void Player::setSelectedPawn(Pawn *pawn){
	this->selectedPawn = pawn;
}


void Player::printInfo()
{
	cout << "[plr]: Name =" << this->_name << endl;
	cout << "[plr]: ID =" << this->_id << endl;
	cout << "[plr]: NbPawn =" << this->_nbPawn << endl;
	cout << "[plr]: Right answers =" << this->_rightAnswers << endl;
	cout << "[plr]: MoveAgain =" << this->_moveAgain << endl;
	cout << "[plr]: PassMove =" << this->_passMove << endl;
}


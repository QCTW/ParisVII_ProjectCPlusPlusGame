#include "PlayerFactory.hpp"

PlayerFactory::PlayerFactory(){}
PlayerFactory::~PlayerFactory(){}

int PlayerFactory::nbHumanCreated = 0;
int PlayerFactory::nbIACreated = 0;

Human *PlayerFactory::getHumanPlayer(string name){
	Human *hp = new Human("HumanPlayer");	
	if(name != ""){
		hp->setName(name);
	}
	PlayerFactory::nbHumanCreated++;
	return hp;
}
AI *PlayerFactory::getIAPlayer(string name, bool intelligent){
	AI *ia = new AI("IAPlayer", intelligent);	
	if(name != ""){
		ia->setName(name);
	}
	PlayerFactory::nbIACreated++;
	return ia;
}
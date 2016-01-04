#ifndef PLAYERFACTORY_HPP
#define PLAYERFACTORY_HPP
#include "AI.hpp"
#include "Human.hpp"



class PlayerFactory
{
public:
	static int nbHumanCreated;
	static int nbIACreated;

	PlayerFactory();
	~PlayerFactory();
	static Human *getHumanPlayer(string name = "");
	static AI *getIAPlayer(string name = "", bool intelligent = true);

};


#endif
#include "AI.hpp"

AI::AI(string name, bool intelligent): Player (name){
	this->_intelligent = intelligent;
}

AI::~AI(){}

Pawn * AI::selectPawn(){
	/*Selection du pion qui est placé le plus loin par rapport à la case d'arrivée*/
	if(this->_intelligent){
		int minPos = this->myPawns[0]->getCellId(); // Je selectionne la position du premier pion
		int ind = 0;
		for (int i = 0; i < this->_nbPawn; ++i)
		{
			if((this->myPawns[i]->getCellId()) < minPos){
				minPos = this->myPawns[i]->getCellId();
				ind = i;
			}
		};
			// cout << "Pawn " << ind << "@" << this->myPawns[ind]->getCellId() << endl;
		this->selectedPawn = this->myPawns[ind]; 
		return this->myPawns[ind];
	}
	else{
		srand(time(NULL));
		int ind = rand()%((this->_nbPawn));
		this->selectedPawn = this->myPawns[ind];
		return this->myPawns[ind];
	}
}

string AI::answerQuestion(Question *q){
	cout << "Question: " << q->getQuestion() << endl;
	// 100 percent correct answer
	if(this->_intelligent){
		return q->getAnswer();
	}
	// 50 percent correct answer
	else{
		srand( time(NULL) ); //Randomize seed initialization
		int randNum = rand() % 2;
		if(randNum == 0){
			return "";
		}
		else{
			return q->getAnswer();
		}
	}
}

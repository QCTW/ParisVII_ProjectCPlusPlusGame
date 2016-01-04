#include "Human.hpp"

Human::Human(string name): Player (name){}

Human::~Human(){}

Pawn *Human::selectPawn(){
	int indpawn;
	cout << "You have " << this->_nbPawn << " pawns, select one of them" << endl;
	cin >> indpawn;
	while(indpawn > this->_nbPawn || indpawn < 1){
		cout << "Try again" << endl;
		cin >> indpawn;
	}
	this->selectedPawn = this->myPawns[indpawn-1];
	return this->myPawns[indpawn-1];
}


string Human::answerQuestion(Question *q){
	cout << "Question: " << q->getQuestion() << endl;
	string answer = "";
	cin >> answer;
	return answer;
}
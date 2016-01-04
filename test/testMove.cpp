#include <iostream>
#include "../move/Dice.hpp"
#include "../move/MoveFactory.hpp"
#include "../platform/QuestionFactory.hpp"
using namespace std;

int main(void)
{
	Dice* d = MoveFactory::getInstance()->createDice(10);
	cout << "Rand #:" << d->GetMoveNumber() << endl;

	QuestionFactory::getInstance()->setQuestionSheetPath("config/QCM.txt");
	QuestionFactory::getInstance()->getQuestion();
	return 0;
}

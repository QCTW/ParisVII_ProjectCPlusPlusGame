#include "Question.hpp"

void Question::setQuestion(string question)
{
	this->strQuestion = question;
}

void Question::setAnswer(string answer)
{
	this->strAnswer = answer;
}

Question::Question()
{

}

Question::~Question()
{
	this->vArrPossibleAnswers.clear();
}

string Question::getQuestion()
{
	return this->strQuestion;
}
string Question::getAnswer()
{
	return this->strAnswer;
}

string Question::getPossibleAnswers(int nIndex)
{
	if(nIndex<this->vArrPossibleAnswers.size())
	{
		return this->vArrPossibleAnswers[nIndex];
	}

	return "";
}

void Question::addPossibleAnswer(string ans)
{
	this->vArrPossibleAnswers.push_back(ans);
}

int Question::getSizeOfPossibleAnswers()
{
	return this->vArrPossibleAnswers.size();
}

string Question::toString()
{
	string strPossibleAnswers;
	for(int i=0, iMax=getSizeOfPossibleAnswers(); i<iMax; i++)
	{
		strPossibleAnswers = strPossibleAnswers + "\n  " + (this->vArrPossibleAnswers)[i] ;
	}
	return this->strQuestion + "->" + this->strAnswer + strPossibleAnswers;
}

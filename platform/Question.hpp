#ifndef QUESTION_HPP
#define QUESTION_HPP

#include <string>
#include <vector>
#include "QuestionFactory.hpp"
using namespace std;

class Question
{
friend class QuestionFactory; //Only QuestionFactory is allowed to access the setters
private:
	string strQuestion = "N/A";
	string strAnswer = "Answer Not Set";
	vector<string> vArrPossibleAnswers;

	void setQuestion(string question);
	void setAnswer(string answer);
	void addPossibleAnswer(string ans);

public:
	Question();
	~Question();

	string getQuestion();
	string getAnswer();

	string getPossibleAnswers(int nIndex);
	int getSizeOfPossibleAnswers();

	string toString();

};

#endif

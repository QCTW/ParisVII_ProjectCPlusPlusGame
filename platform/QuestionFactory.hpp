#ifndef QUESTIONFACTORY_HPP
#define QUESTIONFACTORY_HPP
#include <vector>
#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Question.hpp"

using namespace std;

class Question;
class QuestionFactory
{

private:
	static QuestionFactory* qfUnique;
	vector<Question*> vQuestions;
	int nCurrentQuestion = -1;
	vector<Question*> loadQuestionsFromFile(const string& strPath);
	string sQCMPath = "config/QCM.txt";

public:
	static QuestionFactory* getInstance();
	Question* getQuestion();
	Question* getArithmeticsQuestion();
	void setQuestionSheetPath(const string& strPath);
};

#endif

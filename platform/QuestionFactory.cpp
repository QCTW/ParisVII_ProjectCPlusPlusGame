#include "QuestionFactory.hpp"

QuestionFactory* QuestionFactory::qfUnique = nullptr;

QuestionFactory* QuestionFactory::getInstance()
{
	if(QuestionFactory::qfUnique == nullptr)
	{
		QuestionFactory::qfUnique = new QuestionFactory();
	}

	return QuestionFactory::qfUnique;
}

vector<Question*> QuestionFactory::loadQuestionsFromFile(const string& strPath)
{
    vector<Question*> vQuestions;
    ifstream csvFile( strPath.c_str() );
    if(!csvFile)
    	cerr << "File " << strPath << " not found." << endl;
    string line;
    int iCount = 0;
    while ( csvFile.good() )
    {
        while(getline(csvFile, line))
        {
        	iCount++;
        	if (line.find("//") == 0)
        	{
        		continue;
        	}
        	else
        	{
            	cout << "Read line " << iCount << ":" << line << endl;
            	string strRest = line;
            	int nSemicolonPos = strRest.find(';');
            	int nSemicolonMatchCount = 0;
            	Question* q = new Question();
            	while(nSemicolonPos != -1)
            	{
                	string strHead = strRest.substr(0, nSemicolonPos);
                	strRest = strRest.substr(nSemicolonPos+1, strRest.size());
                	nSemicolonPos = strRest.find(';');
            		if(nSemicolonMatchCount==0)
            		{
            			q = new Question();
            			q->setQuestion(strHead);
            		}
            		else if (nSemicolonMatchCount==1)
            		{
            			q->setAnswer(strHead);
            		}
            		else
            		{
            			q->addPossibleAnswer(strHead);
            		}
            		nSemicolonMatchCount++;
            	}

            	if(strRest.length()>0)
            		q->addPossibleAnswer(strRest);
        		cout << "Question " << vQuestions.size() << " created: " << q->toString() << endl;
            	vQuestions.push_back(q);
        	}
        }
    }
    return vQuestions;
}

Question* QuestionFactory::getQuestion()
{
	if(vQuestions.size()==0)
	{
		this->nCurrentQuestion = -1;
		vQuestions = loadQuestionsFromFile(this->sQCMPath);
	}

	if(this->nCurrentQuestion >= vQuestions.size())
	{
		cout << "Reach number of max question:" << vQuestions.size() << endl;
		return getArithmeticsQuestion();
	}
	else
	{
		++(this->nCurrentQuestion);
	}
	return vQuestions.at(this->nCurrentQuestion);
}

Question* QuestionFactory::getArithmeticsQuestion()
{
	srand(time(0));
	int nFirst = rand() % 99 + 1;
	srand(time(0));
	int nLast = rand() % 33 + 1;
	srand(time(0));
	int nArithmetic = rand() % 3 + 1;
	ostringstream cFirst, cLast, convertA; // stream used for the conversion
	cFirst << nFirst; // insert the textual representation of 'Number' in the characters in the stream
	char cArithmetic = '+';
	int nAnswer = nFirst + nLast;
	string strQuestion = cFirst.str();
	Question* q = new Question();

	switch(nArithmetic)
	{
		case 2:
			cArithmetic = '-';
			nAnswer = nFirst - nLast;
			break;
		case 3:
			cArithmetic = '*';
			nAnswer = nFirst * nLast;
			break;
		case 4:
			cArithmetic = '/';
			nAnswer = nFirst / nLast;
			break;
	}
	cLast << nLast;
	convertA << nAnswer;
	strQuestion = strQuestion + cArithmetic + cLast.str() + "= ?";
	q->setQuestion(strQuestion);
	q->setAnswer(convertA.str());
	cout << "Question created:" << q->toString() << endl;
	return q;
}

void QuestionFactory::setQuestionSheetPath(const string& strPath)
{
	this->sQCMPath = strPath;
}

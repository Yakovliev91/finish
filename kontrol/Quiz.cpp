#include "Quiz.h"
#include<iostream>
#include<string>
#include <fstream>
using namespace std;

Quiz* quizes;
int countQuizes = 0;


void addQuiz()
{
	ofstream fout;
	fout.open("Quiz.txt", fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen==true)
	{
		Quiz* temp = new Quiz[countQuizes + 1];
		for (int i = 0; i < countQuizes; i++)
		{
			temp[i] = quizes[i];
		}
		
		int countQuestions = 0;
		cout << "Enter name of quiz :";
		cin >> temp[countQuizes].nameQuiz;
		cout << "Enter count of questions :";
		cin >> countQuestions;
	

		temp[countQuizes].countQuestions = countQuestions;
		temp[countQuizes].questions = new Question[countQuestions];

		for (int i = 0; i < countQuestions; i++)
		{
			cout << "Enter question"<<" " << i + 1 << "/5"<<" ";
			cin >> temp[countQuizes].questions[i].questionName;
			cout << "Enter answer question"<<" " << i + 1 << "/5"<<" ";
			cin >> temp[countQuizes].questions[i].answer;
		}

		fout << temp[countQuizes].nameQuiz << endl;
		fout << temp[countQuizes].countQuestions << endl;

		for (int i = 0; i < temp[countQuizes].countQuestions; i++)
		{
			fout << temp[countQuizes].questions[i].questionName << endl;
			fout << temp[countQuizes].questions[i].answer << endl;


		}


		fout.close();
		countQuizes++;
		delete quizes;
		quizes = temp;
		
	}
	else {
		cout << "Error" << endl;
	}


}

void showResult()
{
	for (int i = 0; i < countQuizes; i++)
	{
		cout << quizes[i].nameQuiz << endl;
		for (int j = 0; j < quizes[i].countQuestions; j++)
		{
			cout << quizes[i].questions[j].questionName << "-->" << quizes[i].questions[j].answer << endl;
		}
	}
}

#pragma once
#include<iostream>
#include<string>
#include <fstream>
using namespace std;


struct Question {
	string questionName;
	string answer;
	

};

struct Quiz {

	string nameQuiz;
	Question* questions;
	int countQuestions;
	

};

void addQuiz();
void showResult();
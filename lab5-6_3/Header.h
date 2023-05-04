#pragma once

#include <iostream>
#include <conio.h>
#include <string.h>
#include <algorithm>
#include <list>
#include <string>

using namespace std;

//Компонент
class Question
{
protected:
	string Name;
public:
	Question() {};
	Question(const string& name)
	{
		this->Name = name;
	}
	virtual void PrintQuestion() = 0;
};

//Композит
class CompositeQuestion : public Question
{
private:
	list<Question*> catalogQuestion;
public:
	CompositeQuestion() : Question("") {};
	virtual void PrintQuestion()
	{
		for (list<Question*>::iterator i = catalogQuestion.begin(); i != catalogQuestion.end(); i++)
			(*i)->PrintQuestion();
		cout << endl;
	}

	void AddQuestion(Question* leaf) { catalogQuestion.push_back(leaf); }
	void RemoveQuestion(Question* leaf) { catalogQuestion.remove(leaf); }
};

//Лист
class LeafQuestion : public Question
{
public:
	LeafQuestion(const string& name) : Question(name) {}
	virtual void PrintQuestion() { cout << Name << endl; }
};
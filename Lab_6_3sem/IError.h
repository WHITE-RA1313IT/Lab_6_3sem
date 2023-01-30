#pragma once
#include <iostream>
#include <string>
using namespace std;

class IError {
public:
	int num; 
	virtual void print() {};
};

class IncorrectInput : public IError {
public:
	IncorrectInput() {};
	void print() {
		cout << "Incorrect input.\n\n";
	}
};

class CriticalIncorrectInput : public IError {
public:
	CriticalIncorrectInput() {};
	void print() {
		cout << "Critical incorrect input. You entered a text, not a number.\n\n";
	}
};

class DivisionByZero : public IError {
public:
	DivisionByZero() {};
	void print() {
		cout << "Division by zero.\n\n";
	}
};

int getInt();
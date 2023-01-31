#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class IError {
	vector<string> err;
public:
	int num; 
	virtual void print() {};
	void print_error_list() {
		for (auto x : err) {
			cout << x << endl;
		}
		cout << endl;
	}
};

class IncorrectInput : public IError {
public:
	IncorrectInput() {};
	void print() {
		cout << "Incorrect input.\n";
	}
};

class CriticalIncorrectInput : public IError {
public:
	CriticalIncorrectInput() {};
	void print() {
		cout << "Critical incorrect input. You entered a text, not a number.\n";
	}
};

class DivisionByZero : public IError {
public:
	DivisionByZero() {};
	void print() {
		cout << "Division by zero.\n";
	}
};

int getInt();
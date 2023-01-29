#pragma once
#include <iostream>
#include "IError .h"
int getInt() {
	string input;
	getline(cin, input);
	for (int i = 0; i < input.length(); i++) {
		if (!isdigit(input[i]) || input[i] == ' ') {
			throw IncorrectInput();
			break;
		}
	}
	if (input == "") throw CriticalIncorrectInput();
	return stoi(input);
}
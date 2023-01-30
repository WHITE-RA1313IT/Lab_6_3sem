#include "IError.h"
#include <iostream>
#include <string>
int getInt() {
    string input;
    getline(cin, input);
    for (int i = 0; i < input.length(); i++) {
        if (!isdigit(input[i]) || input[i] == ' ') {
            throw CriticalIncorrectInput();
            break;
        }
    }
    if (input == "") throw CriticalIncorrectInput();
    return stoi(input);
}
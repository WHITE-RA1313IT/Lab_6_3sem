#include "IError.h"
#include <iostream>
#include <string>
int getInt() {
    int n;
    cin >> n;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw CriticalIncorrectInput();
        return 0;
    }
    else return n;

    /*string input;
    getline(cin, input);
    for (int i = 0; i < input.length(); i++) {
        if ((!isdigit(input[i]) && input[i] != '-') || input[i] == ' ' || int(input[i]) > 191) {
            throw CriticalIncorrectInput();
            return 0;
            break;
        }
    }
    if (input == "") throw CriticalIncorrectInput();
    return stoi(input);*/
}
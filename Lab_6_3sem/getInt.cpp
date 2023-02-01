#include "IError.h"
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
}
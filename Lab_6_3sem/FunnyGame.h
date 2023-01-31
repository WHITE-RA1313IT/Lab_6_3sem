#pragma once
#include <iostream>
#include <vector>
using namespace std;

class FunnyGame {
public:
    vector<vector<bool>> game;
    FunnyGame(int const& N);
    bool isWin(vector<int> const& answers);
};

void FunnyGameMenu(vector<IError*>& err);
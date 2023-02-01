#include "IError.h"
#include "FunnyGame.h"
#include <random>

FunnyGame::FunnyGame(int const& N) {
    game.resize(N);
    for (int i = 0; i < N; i++) {
        game[i].resize(N);
        for (int j = 0; j < N; j++) {
            game[i][j] = false;
        }
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, N - 1);
    int true_fields = 0;
    while (true_fields < N / 2) {
        int i = dist(gen), j = dist(gen);
        if (!game[i][j]) {
            game[i][j] = true;
            true_fields++;
        }
    }
}

bool FunnyGame::isWin(vector<int> const& answers) {
    int correct_answers = 0;
    for (auto x : answers) {
        int i, j;

        if (x % game.size() != 0) {
            i = x / game.size();
            j = x % game.size() - 1;
        }
        else {
            i = x / game.size() - 1;
            j = game.size() - 1;
        }

        if (game[i][j]) correct_answers++;   
    }
    if (correct_answers == game.size() / 3) {
        return true;
    }
    return false;
}

void FunnyGameMenu(vector<IError*>& err) {
    cout << char(9475) << char(9476) << "FUNNY GAME" << char(9477) << char(9478) << endl;
    cout << "1) Play;\n";
    cout << "2) Exit to main menu.\n";
    cout << "Your choice: ";

    try {
        int game_choice;
        game_choice = getInt();
        if (game_choice < 1 || game_choice > 2) {
            throw IncorrectInput();
        }
        cout << endl;

        if (game_choice == 1) {
            cout << "Enter the size of the playing field (3-6): ";
            int field_size;
            field_size = getInt();
            if (field_size < 3 || field_size > 6) {
                throw IncorrectInput();
            }

            FunnyGame game1 = FunnyGame(field_size);

            for (auto x : game1.game) {
                for (auto y : x) {
                    cout << y << " ";
                }
                cout << endl;
            }

            vector<int> answers;
            for (int i = 0; i < field_size; i++) {
                int ans;
                cout << "Enter number #" << i + 1 << ": ";
                ans = getInt();
                if (ans < 1 || ans > pow(field_size, 2)) throw IncorrectInput();
                for (int j = 0; j < answers.size(); j++) {
                    if (ans == answers[j]) throw IncorrectInput();
                }
                answers.push_back(ans);
            }

            cout << endl;
            if (game1.isWin(answers)) cout << char(7) << char(9473) << "YOU WIN!" << char(9474) << "\n\n";
            FunnyGameMenu(err);
        }
        else {
            return;
        }
    }

    catch (CriticalIncorrectInput& e) {
        err.push_back(new CriticalIncorrectInput);
        e.print();
        cout << endl;
    }
    catch (IncorrectInput& e) {
        err.push_back(new IncorrectInput);
        e.print();
        cout << endl;
    }
}
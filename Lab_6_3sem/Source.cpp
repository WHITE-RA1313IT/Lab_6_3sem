#include "IError.h"
#include "Complex.h"
#include "FunnyGame.h"

void print_error_list(vector<IError*> err) {
    for (auto x : err) {
        (*x).print();
    }
    cout << endl;
}

int main()
{
    vector<IError*> err;
    while (true) {
        string logger;

        cout << "Select a task:\n";
        cout << "1) Complex numbers;\n";
        cout << "2) Funny Game;\n";
        cout << "3) Output a list of errors;\n";
        cout << "4) Exit.\n";
        cout << "Your choice: ";

        try {
            int choice;
            choice = getInt();
            if (choice < 1 || choice > 4) {
                throw IncorrectInput();
            }
            else {
                cout << endl;
                if (choice == 1) {
                    ComplexMenu(logger, err);
                }
                if (choice == 2) {
                    FunnyGameMenu(err);
                }
                if (choice == 3) {
                    print_error_list(err);
                }
                if (choice == 4) {
                    exit(0);
                }
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
}
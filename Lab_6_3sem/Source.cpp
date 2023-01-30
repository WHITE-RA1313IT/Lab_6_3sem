#include "IError.h"
#include "Complex.h"
#include "FunnyGame.h"

int main()
{
    while (true) {
        string logger;

        cout << "Select a task:\n";
        cout << "1) Complex numbers;\n";
        cout << "2) Funny Game;\n";
        cout << "3) Exit.\n";
        cout << "Your choice: ";

        try {
            int choice;
            choice = getInt();
            if (choice < 1 || choice > 3) {
                throw IncorrectInput();
            }
            else {
                cout << endl;
                if (choice == 1) {
                    ComplexMenu(logger);
                }
                if (choice == 2) {
                    FunnyGameMenu();
                }
                if (choice == 3) {
                    exit(0);
                }
            }
        }

        catch (CriticalIncorrectInput& e) {
            e.print();
        }
        catch (IncorrectInput& e) {
            e.print();
        }
        catch (DivisionByZero& e) {
            e.print();
        }
    }
}
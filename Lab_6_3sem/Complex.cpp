#include <iostream>
#include "IError.h"
#include "Complex.h"
#define _USE_MATH_DEFINES
#include <Math.h>
#include <vector>
#include <string>
using namespace std;

double Complex::radius(double const& x, double const& y) {
    return sqrt(pow(x, 2) + pow(y, 2));
}
double Complex::argument(double const& x, double const& y) {
    if (x > 0) {
        return atan(y / x);
    }
    if (x < 0 && y >= 0) {
        return M_PI + atan(abs(y / x));
    }
    if (x < 0 && y < 0) {
        return -M_PI + atan(abs(y / x));
    }
    if (x == 0 && y > 0) {
        return M_PI / 2;
    }
    if (x == 0 && y < 0) {
        return -M_PI / 2;
    }
    if (x > 0 && y == 0) {
        return 0;
    }
    if (x < 0 && y == 0) {
        return M_PI;
    }
    return 0;
}

string Complex::get_log() {
    return log;
}
void Complex::set_log(string const& other_log) {
    log = other_log;
}

Complex::Complex() {
    first = 0;
    second = 0;
}
Complex::Complex(double const& x, double const& y) {
    first = x;
    second = y;
    rad = radius(first, second);
    arg = argument(first, second);
}

void Complex::add(Complex const& obj1, Complex const& obj2) {
    first = obj1.first + obj2.first;
    second = obj1.second + obj2.second;
}

void Complex::sub(Complex const& obj1, Complex const& obj2) {
    first = obj1.first - obj2.first;
    second = obj1.second - obj2.second;
}

void Complex::mult(Complex const& obj1, Complex const& obj2) {
    first = obj1.first * obj2.first - obj1.second * obj2.second;
    second = obj1.first * obj2.second + obj1.second * obj2.first;
}

void Complex::div(Complex const& obj1, Complex const& obj2) {
    if (obj2.first == 0 && obj2.second == 0) {
        throw DivisionByZero();
    }
    else {
        first = (obj1.first * obj2.first + obj1.second * obj2.second) / (pow(obj2.first, 2) + pow(obj2.second, 2));
        second = (obj1.first * obj2.second - obj1.second * obj2.first) / (pow(obj2.first, 2) + pow(obj2.second, 2));
    }
}

void Complex::exp(int const& degree) {
    log += "EXPONENTIATION\n";

    cout << pow(radius(first, second), degree) * cos(degree * argument(first, second)) << "+";
    cout << pow(radius(first, second), degree) * sin(degree * argument(first, second)) << "i\n";
}

void Complex::complex_sqrt(int const& degree) {
    log += "SQRT\n";

    vector <Complex> roots;
    for (int i = 1; i <= degree; i++) {
        Complex temp_obj;
        temp_obj.first = pow(radius(first, second), 1.0 / degree) * cos((argument(first, second) + 2 * M_PI * i) / degree);
        temp_obj.second = pow(radius(first, second), 1.0 / degree) * sin((argument(first, second) + 2 * M_PI * i) / degree);
        roots.push_back(temp_obj);
    }
    for (int i = 0; i < roots.size(); i++) {
        cout.precision(2);
        cout << roots[i];
        if (i < roots.size() - 1) cout << "; ";
    }
    cout << endl;
}

void Complex::quadratic_equation(int const& a, int const& b, int const& c) {
    log += "COMPLEX ROOTS OF THE QUADRATIC EQUATION\n";

    if (pow(b, 2) - 4 * a * c < 0) {
        cout << -b / (2 * a) << "-" << sqrt(abs(pow(b, 2) - 4 * a * c)) / (2 * a) << "i; ";
        cout << -b / (2 * a) << "+" << sqrt(abs(pow(b, 2) - 4 * a * c)) / (2 * a) << "i\n";
    }
}

void Complex::trigonometric() {
    log += "TRIGONOMETRIC FORM\n";

    cout << radius(first, second) << "*(cos(" << argument(first, second) << ") + i*sin(" << argument(first, second) << "))\n";
}
void Complex::indicative() {
    log += "INDICATIVE FORM\n";

    cout << radius(first, second) << "*e^(" << argument(first, second) << "i)\n";
}

Complex Complex::operator+(Complex const& obj) {
    log += "ADD\n";

    Complex temp;
    temp.add(Complex(first, second), obj);
    return temp;
}

Complex Complex::operator-(Complex const& obj) {
    log += "SUB\n";

    Complex temp;
    temp.sub(Complex(first, second), obj);
    temp.set_log(log);
    return temp;
}

Complex Complex::operator*(Complex const& obj) {
    log += "MULT\n";

    Complex temp;
    temp.mult(Complex(first, second), obj);
    temp.set_log(log);
    return temp;
}

Complex Complex::operator/(Complex const& obj) {
    log += "DIV\n";

    Complex temp;
    temp.div(Complex(first, second), obj);
    temp.set_log(log);
    return temp;
}

bool Complex::operator==(const Complex& obj) {
    log += "EQUIVAL\n";

    if (first == obj.first && second == obj.second) {
        return true;
    }
    else return false;
}

bool Complex::operator!=(const Complex& obj) {
    log += "NONEQUIVAL\n";

    if (first != obj.first || second != obj.second) {
        return true;
    }
    else return false;
}

istream& operator>>(istream& is, Complex& obj) {
    cout << "Enter the valid part: ";
    obj.first = getInt();
    cout << "Enter the imaginary part: ";
    obj.second = getInt();
    return is;
}

ostream& operator<<(ostream& os, Complex const& obj) {
    if (obj.second > 0) os << obj.first << "+" << obj.second << "i";
    else os << obj.first << obj.second << "i";
    return os;
}

void ComplexMenu(string& logger) {
    cout << "Select an operation:\n";
    cout << "1) Addition;\n";
    cout << "2) Subtraction;\n";
    cout << "3) Multiplication;\n";
    cout << "4) Division;\n";
    cout << "5) Trigonometric form;\n";
    cout << "6) Indicative form;\n";
    cout << "7) Exponentiation;\n";
    cout << "8) Finding the root;\n";
    cout << "9) A quadratic equation with complex roots;\n";
    cout << "10) Check log;\n";
    cout << "11) Exit to main menu.\n";
    cout << "Your choice: ";

    try {
        int choice;
        choice = getInt();
        if (choice < 1 || choice > 11) throw IncorrectInput();
        cout << endl;

        Complex a, b;
        switch (choice) {
        case ADD:
            cout << "Enter the first number:\n";
            cin >> a;
            cout << "Enter the second number:\n";
            cin >> b;
            cout << "Result: " << a + b << "\n\n";

            logger += a.get_log();
            ComplexMenu(logger);
            break;

        case SUB:
            cout << "Enter the first number:\n";
            cin >> a;
            cout << "Enter the second number:\n";
            cin >> b;
            cout << "Result: " << a - b << "\n\n";

            logger += a.get_log();
            ComplexMenu(logger);
            break;

        case MULT:
            cout << "Enter the first number:\n";
            cin >> a;
            cout << "Enter the second number:\n";
            cin >> b;
            cout << "Result: " << a * b << "\n\n";

            logger += a.get_log();
            ComplexMenu(logger);
            break;

        case DIV:
            cout << "Enter the first number:\n";
            cin >> a;
            cout << "Enter the second number:\n";
            cin >> b;
            cout << "Result: " << a / b << "\n\n";

            logger += a.get_log();
            ComplexMenu(logger);
            break;

        case TRIGONOMETRIC_FORM:
            cout << "Enter the number:\n";
            cin >> a;
            cout << "Result: ";
            a.trigonometric();
            cout << endl;

            logger += a.get_log();
            ComplexMenu(logger);
            break;

        case INDICATIVE_FORM:
            cout << "Enter the number:\n";
            cin >> a;
            cout << "Result: ";
            a.indicative();
            cout << endl;

            logger += a.get_log();
            ComplexMenu(logger);
            break;

        case EXPONENTIATION:
            cout << "Enter the number:\n";
            cin >> a;
            cout << "Enter the degree: ";
            int degree;
            degree = getInt();
            cout << "Result: ";
            a.exp(degree);
            cout << endl;

            logger += a.get_log();
            ComplexMenu(logger);
            break;

        case SQRT:
            cout << "Enter the number:\n";
            cin >> a;
            cout << "Enter the root degree: ";
            int root_degree;
            root_degree = getInt();
            cout << "Result: ";
            a.complex_sqrt(root_degree);
            cout << endl;

            logger += a.get_log();
            ComplexMenu(logger);
            break;

        case QUADRATIC_EQUATION:
            cout << "Enter the coefficients of the equation (ax^2+bx+c=0):\n";
            int a_coef, b_coef, c_coef;
            cout << "a: ";
            a_coef = getInt();
            cout << "b: ";
            b_coef = getInt();
            cout << "c: ";
            c_coef = getInt();
            cout << "Result: ";
            a.quadratic_equation(a_coef, b_coef, c_coef);
            cout << endl;

            logger += a.get_log();
            ComplexMenu(logger);
            break;

        case LOG:
            cout << logger << endl;
            ComplexMenu(logger);
            break;

        case EXIT:
            break;
        }
    }

    catch (CriticalIncorrectInput& e) {
        e.print();
        ComplexMenu(logger);
    }
    catch (IncorrectInput& e) {
        e.print();
        ComplexMenu(logger);
    }
    catch (DivisionByZero& e) {
        e.print();
        ComplexMenu(logger);
    }
}
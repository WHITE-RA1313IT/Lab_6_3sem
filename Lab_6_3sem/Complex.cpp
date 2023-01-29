#include "Complex.h"
#include "getInt.h"

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
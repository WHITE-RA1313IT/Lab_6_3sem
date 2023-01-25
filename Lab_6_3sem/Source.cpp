#include <iostream>
#define _USE_MATH_DEFINES
#include <Math.h>
#include <vector>
using namespace std;

class Complex {
    double radius(double const& x, double const& y) {
        return sqrt(pow(x, 2) + pow(y, 2));
    }
    double argument(double const& x, double const& y) {
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
public:
    double first, second, rad, arg;
    Complex() {
        first = 0;
        second = 0;
    }
    Complex(double const& x, double const& y) {
        first = x;
        second = y;
        rad = radius(first, second);
        arg = argument(first, second);
    }

    void add(Complex const& obj1, Complex const& obj2) {
        first = obj1.first + obj2.first;
        second = obj1.second + obj2.second;
    }

    void sub(Complex const& obj1, Complex const& obj2) {
        first = obj1.first - obj2.first;
        second = obj1.second - obj2.second;
    }

    void mult(Complex const& obj1, Complex const& obj2) {
        first = obj1.first * obj2.first - obj1.second * obj2.second;
        second = obj1.first * obj2.second + obj1.second * obj2.first;
    }

    void div(Complex const& obj1, Complex const& obj2) {
        if (obj2.first == 0 && obj2.second == 0) {
            throw "Division by zero.";
        }
        else {
            first = (obj1.first * obj2.first + obj1.second * obj2.second) / (pow(obj2.first, 2) + pow(obj2.second, 2));
            second = (obj1.first * obj2.second - obj1.second * obj2.first) / (pow(obj2.first, 2) + pow(obj2.second, 2));
        }
    }

    double exp(int const& degree) {
        return pow(radius(first, second), degree) * (cos(degree * argument(first, second)) + sin(degree * argument(first, second)));
    }

    void complex_sqrt(int const& degree) {
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

    void quadratic_equation(string const& equa) {
        string str = equa;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == ' ') {
                for (int j = i; j < str.length(); j++) {
                    str[j] == str[j + 1];
                }
            }
        }
        for (int i = 0; i < str.length(); i++) {
            
        }
    }

    void trigonometric() {
        cout << radius(first, second) << "*(cos(" << argument(first, second) << ") + i*sin(" << argument(first, second) << "))" << endl;
    }
    void indicative() {
        cout << radius(first, second) << "*e^(" << argument(first, second) << "i)" << endl;
    }

    friend ostream& operator<<(ostream& os, Complex const& obj);
};

ostream& operator<<(ostream& os, Complex const& obj) {
    if (obj.second > 0) os << obj.first << "+" << obj.second << "i";
    else os << obj.first << obj.second << "i";
    return os;
}

int main()
{
    Complex a(1, sqrt(3));
    Complex b(0, -8);
    Complex c;
    c.add(a, b);
    cout << c << endl;
    c.sub(a, b);
    cout << c << endl;
    c.mult(a, b);
    cout << c << endl;
    c.div(a, b);
    cout << c << endl;
    cout << a.exp(18) << endl;
    b.complex_sqrt(2);
}
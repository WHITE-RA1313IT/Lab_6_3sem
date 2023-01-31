#pragma once
#include <iostream>
using namespace std;

class Complex {
    string log;
    double radius(double const& x, double const& y);
    double argument(double const& x, double const& y);
public:
    double first, second, rad, arg;
    string get_log();
    void set_log(string const& other_log);

    Complex();
    Complex(double const& x, double const& y);

    void add(Complex const& obj1, Complex const& obj2);
    void sub(Complex const& obj1, Complex const& obj2);
    void mult(Complex const& obj1, Complex const& obj2);
    void div(Complex const& obj1, Complex const& obj2);
    void exp(int const& degree);
    void complex_sqrt(int const& degree);
    void quadratic_equation(int const& a, int const& b, int const& c);

    void trigonometric();
    void indicative();

    Complex operator+(Complex const& obj);
    Complex operator-(Complex const& obj);
    Complex operator*(Complex const& obj);
    Complex operator/(Complex const& obj);

    friend istream& operator>>(istream& is, Complex& obj);
    friend ostream& operator<<(ostream& os, Complex const& obj);

    bool operator==(const Complex& obj);
    bool operator!=(const Complex& obj);
};

enum COMPLEX_MENU { ADD = 1, SUB, MULT, DIV, TRIGONOMETRIC_FORM, INDICATIVE_FORM, EXPONENTIATION, SQRT, QUADRATIC_EQUATION, LOG, EXIT };
void ComplexMenu(string& logger, vector<IError*>& err);
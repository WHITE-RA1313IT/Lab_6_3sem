#pragma once
#include <iostream>
#define _USE_MATH_DEFINES
#include <Math.h>
#include <vector>
#include <string>
using namespace std;

class Complex {
    string log;
    double radius(double const& x, double const& y);
    double argument(double const& x, double const& y);
public:
    string get_log();
    void set_log(string const& other_log);
    double first, second, rad, arg;
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

istream& operator>>(istream& is, Complex& obj);
ostream& operator<<(ostream& os, Complex const& obj);

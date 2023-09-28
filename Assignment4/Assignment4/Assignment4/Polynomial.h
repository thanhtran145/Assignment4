#pragma once
#include <iostream>
#include<vector>
#include <string>
#include<iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

//input (1) header files inputs validation
char inputChar(string prompt, string lookup);
int inputInteger(string prompt, int startRange, int endRange);
double inputDouble(string prompt);

//precondition: a class that gets the coefficients 
//postcondition: using a vector to keep track of the coefficients
class Polynomial 
{
private:
    vector<double> coefficients;
    bool termsEntered = false;
    bool coefficientsSpecified = false;

public:
    //default constructor
    Polynomial();
    void enterTerms();
    void specifyCoefficients();
    double evaluateExpression(double x);
    Polynomial derivative();
    Polynomial integral();
    void printPolynomial(const Polynomial& poly);

    //member function that has the main menu
    void main();
    //member functions that get me add, subtract, multiply, scalarMultiply
    Polynomial add(const Polynomial& p) const;
    Polynomial subtract(const Polynomial& p) const;
    Polynomial multiply(const Polynomial& p) const;
    Polynomial scalarMultiply(double scalar) const;
};
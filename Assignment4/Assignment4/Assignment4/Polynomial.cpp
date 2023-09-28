#include "Polynomial.h"
#include <cmath>
#include <iostream>

//************************** Contructors **********************************//
Polynomial::Polynomial() {}

//precondition: NA
//postcondition: Resize the number terms, set the terms were entered true so it can tell that we enter the inputs
void Polynomial::enterTerms() 
{
    int numTerms;
    numTerms = inputInteger("\n\t\t\tEnter the number of terms(1.. 100) for the polynomial: ", 1, 100);
    coefficients.resize(numTerms);
    //flag to true so we can then print the coefficients
    termsEntered = true;
}

//precondition: NA
//postcondition: set the coefficents terms numbers 
void Polynomial::specifyCoefficients() 
{
    cout << endl;
    for (size_t i = coefficients.size(); i > 0; --i) {
        string prompt = "\t\t\tEnter the coefficient for term #" + to_string(coefficients.size() - i + 1) + ": ";
        coefficients[i - 1] = inputDouble(prompt);
    }
    //flag it to true so it can show that we went to case 2 
    coefficientsSpecified = true;
}

//precondition: a double parameter
//postcondition: return the result of the expression with specify x value
double Polynomial::evaluateExpression(double x) 
{
    double result = 0;
    for (size_t i = 0; i < coefficients.size(); ++i) {
        result += coefficients[i] * pow(x, i);
    }
    return result;
}

//precondition: NA
//postcondition: return the derivative object, push back, index * the cofficient
Polynomial Polynomial::derivative() 
{
    Polynomial deriv;
    for (size_t i = 1; i < coefficients.size(); ++i) {
        deriv.coefficients.push_back(i * coefficients[i]);
    }
    return deriv;
}
//precondition: NA
//postcondition: return the integral, push back the coefficient then divide the index + 1
Polynomial Polynomial::integral() 
{
    Polynomial integral;
    //add a constant term with coefficient 0
    integral.coefficients.push_back(0);
    for (size_t i = 0; i < coefficients.size(); ++i) {
        integral.coefficients.push_back(coefficients[i] / (i + 1));
    }
    return integral;
}

//precondition: NA 
//postcondition: display main menu
void Polynomial::main() 
{
    system("cls");
    char choice;
    do 
    {
    beginning:
        cout << "\n\t\tA polynomial is an expression consisting of variables(also called indeterminate) and\n"
            "\t\tcoefficients, that involves only the operations of addition, subtraction, multiplication\n"
            "\t\tand non-negative itneger exponentiation of variables\n";
        cout << "\n\t\t3> - Polynomials";
        cout << "\n\t\t" << string(82, char(205));
        cout << "\n\t\t\tA> A Polynomial";
        cout << "\n\t\t\tB> Multiple Polynomials";
        cout << "\n\t\t" << string(82, char(205));
        cout << "\n\t\t\t0> return";
        cout << "\n\t\t" << string(82, char(205)) << "\n";
        choice = inputChar("\t\t\tOption: ", static_cast<std::string>("AB0)"));

        switch (toupper(choice)) {
        case 'A': {
            int choice;
            do {
                system("cls");
                cout << "\n\t\tA> - Single Polynomial";
                cout << "\n\t\t" << string(82, char(205));
                cout << "\n\t\t\t1. Enter the numbers of terms";
                cout << "\n\t\t\t2. Specify the coefficients";
                cout << "\n\t\t\t3. Evaluate expression";
                cout << "\n\t\t\t4. Solve for the derivative";
                cout << "\n\t\t\t5. Solve for the integral";
                cout << "\n\t\t" << string(82, char(205));
                cout << "\n\t\t\t0. return";
                cout << "\n\t\t" << string(82, char(205));
                choice = inputInteger("\n\t\t\tOption: ", 0, 5);

                switch (choice) {
                case 1: {
                    enterTerms();
                    cout << "\n";
                    system("pause");
                    system("cls");
                }
                      break;
                case 2: {
                    if (!termsEntered) {
                        cerr << "\n\t\t\tERROR: 0 term. Please enter the number of terms.\n";
                        cout << "\n";
                        system("pause");
                        system("cls");
                        break;
                    }
                    specifyCoefficients();
                    cout << "\n\t\t\tThe P(x) is entered: ";
                    printPolynomial(*this);
                    cout << "\n";
                    system("pause");
                    system("cls");
                }
                      break;
                case 3: {
                    if (!termsEntered) {
                        cerr << "\n\t\t\tERROR: 0 term. Please re-specify the number of terms.\n";
                        cout << "\n";
                        system("pause");
                        system("cls");
                        break;
                    }
                    if (!coefficientsSpecified) {
                        cout << "\n\t\t\tERROR: expression. Please specify the coefficients.\n";
                        cout << "\n";
                        system("pause");
                        system("cls");
                        break;
                    }
                    cout << "\n\t\t\tP1(x) = ";
                    printPolynomial(*this);
                    double x = inputDouble("\n\t\t\tEnter the value of x to evaluate the polynomial: ");

                    double total = 0;
                    cout << endl;
                    for (int i = coefficients.size() - 1; i >= 0; --i) {
                        double term_value = coefficients[i] * pow(x, i);
                        total += term_value;
                        cout << "\t\t\t" << setw(12) << right << term_value << " <- " << setw(10) << coefficients[i] << "x^" << i << endl;
                    }
                    cout << "\t\t\t+ ";
                    cout << "\n\t\t\t" << string(40, char(205));
                    cout << "\n\t\t" << setw(22) << right << total << endl;
                    cout << "\n";
                    system("pause");
                    system("cls");
                }
                      break;
                case 4: {
                    if (!termsEntered) {
                        cerr << "\n\t\t\tERROR: 0 term. Please re-specify the number of terms.\n";
                        cout << "\n";
                        system("pause");
                        system("cls");
                        break;
                    }
                    if (!coefficientsSpecified) {
                        cout << "\n\t\t\tERROR: expression. Please specify the coefficients.\n";
                        cout << "\n";
                        system("pause");
                        system("cls");
                        break;
                    }
                    cout << "\n\t\t\tPolynomial(x) = ";
                    printPolynomial(*this);
                    cout << "\n\t\t\tDerivative    = ";
                    Polynomial deriv = derivative();
                    printPolynomial(deriv);
                    cout << "\n";
                    system("pause");
                    system("cls");
                }
                      break;
                case 5: {
                    if (!termsEntered) {
                        cerr << "\n\t\t\tERROR: 0 term. Please re-specify the number of terms.\n";
                        cout << "\n";
                        system("pause");
                        system("cls");
                        break;
                    }
                    if (!coefficientsSpecified) {
                        cout << "\n\t\t\tERROR: expression. Please specify the coefficients.\n";
                        cout << "\n";
                        system("pause");
                        system("cls");
                        break;
                    }
                    cout << "\n\t\t\tPolynomial(x) = ";
                    printPolynomial(*this);
                    cout << "\n\t\t\tIntegral      = ";
                    Polynomial integralResult = integral();
                    printPolynomial(integralResult);
                    cout << "\n";
                    system("pause");
                    system("cls");
                }
                      break;
                case 0: {
                    termsEntered = false;
                    coefficientsSpecified = false;
                    cout << endl;
                    system("pause");
                    system("cls");
                    goto beginning;
                }
                }
            } while (true);
        }
                break;
        case 'B': {
            system("cls");
            cout << "\t\tB> Two Polynomials";
            Polynomial p1, p2, result;
            p1.enterTerms();
            p1.specifyCoefficients();
            cout << "\n\t\tThe first polynomial (P1) is entered: ";
            printPolynomial(p1);

            p2.enterTerms();
            p2.specifyCoefficients();
            cout << "\n\t\tThe second polynomial (P2) is entered: ";
            printPolynomial(p2);

            result = p1.add(p2);
            cout << "\n\t\t\tAddition of polynomials       -> P1 + P2 = ";
            printPolynomial(result);

            result = p1.subtract(p2);
            cout << "\t\t\tSubtraction of polynomials    -> P1 - P2 = ";
            printPolynomial(result);

            result = p1.multiply(p2);
            cout << "\t\t\tMultiplication of polynomials -> P1 * P2 = ";
            printPolynomial(result);

            double scalar = inputDouble("\n\t\tEnter a constant value: ");
            cout << endl;
            result = p1.scalarMultiply(scalar);
            cout << "\t\t" << scalar << " * Polynomial(P1) = ";
            printPolynomial(result);

            result = p2.scalarMultiply(scalar);
            cout << "\t\tPolynomial(P2) * " << scalar << " = ";
            printPolynomial(result);
            cout << endl;
            system("pause");
            system("cls");
        }
                break;
        case '0': {
            return;
        }
        }
    } while (true);
}

//precondition: A Polynomial object
//postcondition: Print the polynomials coefficents information
void Polynomial::printPolynomial(const Polynomial& poly) 
{
    bool first_term_printed = false;
    for (int i = poly.coefficients.size() - 1; i >= 0; --i) {
        // Skip terms with a coefficient of 0
        if (poly.coefficients[i] == 0) continue;

        // Handle the first term separately to avoid the leading + sign
        if (!first_term_printed) {
            first_term_printed = true;
            if (poly.coefficients[i] < 0) {
                cout << "- ";
            }
        }
        else {
            if (poly.coefficients[i] >= 0) {
                cout << "+ ";
            }
            else {
                cout << "- ";
            }
        }
        //print the absolute value of the coefficient, the variable x, and the exponent
        if (i > 1) {
            cout << abs(poly.coefficients[i]) << "x^" << i << " ";
        }
        else if (i == 1) {
            cout << abs(poly.coefficients[i]) << "x" << " ";
        }
        else {
            cout << abs(poly.coefficients[i]) << " ";
        }
    }
    cout << endl;
}

//precondition: A Polynomial object
//postcondition: Get the max between both objects, then add it
Polynomial Polynomial::add(const Polynomial& p) const 
{
    int max_degree = std::max(this->coefficients.size(), p.coefficients.size());
    Polynomial result;
    result.coefficients.resize(max_degree, 0);

    for (size_t i = 0; i < this->coefficients.size(); ++i) {
        result.coefficients[i] += this->coefficients[i];
    }

    for (size_t i = 0; i < p.coefficients.size(); ++i) {
        result.coefficients[i] += p.coefficients[i];
    }

    return result;
}

//precondition: A Polynomial object
//postcondition: Get the max between both objects, then subtract it
Polynomial Polynomial::subtract(const Polynomial& p) const {
    int max_degree = max(this->coefficients.size(), p.coefficients.size());
    Polynomial result;
    result.coefficients.resize(max_degree, 0);

    for (size_t i = 0; i < this->coefficients.size(); ++i) {
        result.coefficients[i] += this->coefficients[i];
    }

    for (size_t i = 0; i < p.coefficients.size(); ++i) {
        result.coefficients[i] -= p.coefficients[i];
    }
    return result;
}

//precondition: A Polynomial object
//postcondition: Return the multiplication
Polynomial Polynomial::multiply(const Polynomial& p) const {
    int max_degree = (this->coefficients.size() - 1) + (p.coefficients.size() - 1) + 1;
    Polynomial result;
    result.coefficients.resize(max_degree, 0);

    for (size_t i = 0; i < this->coefficients.size(); ++i) {
        for (size_t j = 0; j < p.coefficients.size(); ++j) {
            result.coefficients[i + j] += this->coefficients[i] * p.coefficients[j];
        }
    }
    return result;
}
//preconditon: A Polynomial object
//postcondition: Loop through the size (coefficeients) then push back the coefficients by index and multiply it
Polynomial Polynomial::scalarMultiply(double scalar) const {
    Polynomial result;
    for (size_t i = 0; i < coefficients.size(); ++i) {
        result.coefficients.push_back(coefficients[i] * scalar);
    }
    return result;
}
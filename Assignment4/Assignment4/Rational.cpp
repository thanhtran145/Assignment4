#include "Rational.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#pragma once

//************************** Contructors **********************************//

// A default constructor that set the numerator to 0 and the denominator to 1.
Rational::Rational()
{
	numerator = 0;
	denominator = 1;
}

// A constructor that accepts the values of the numerator and denominator and throw an exception if the denominator is zero.
Rational::Rational(int newN, int newD)
{
	numerator = newN;
	denominator = newD;
}

// A copy constructor thats accepts the Rational objects and denominator and throw an exception if the denominator is zero.
Rational::Rational(const Rational& obj)
{
	numerator = obj.numerator;
	denominator = obj.denominator;
}

//***************************** Private Methods ************************//

//PreCondition: integer a and b parameter
//PostCondition: return the greatest common divisor between a and b
int Rational::gcd(int a, int b)
{
	if (a == 0 || b == 0)
		return 0;
	else if (a == b)
		return a;
	else if (a > b)
		return gcd(a - b, b);
	else return gcd(a, b - a);
}

//**************************** Public Method *************************//

//PreCondition: NA
//PostCondition: returns a string expression of the numerator/denominator.  
string Rational::toString()
{
	return to_string(numerator) + "/" + to_string(denominator);
}

//PreCondition: NA
//PostCondition: If the denominator is negative, then the negative sign is moved to the numerator and reduce if there is a GCD (greatest common divisor). 
void Rational::normalize()
{
	if (denominator < 0)
	{
		denominator *= -1;
		numerator *= -1;
	}

	int temp = gcd(abs(numerator), abs(denominator));

	if (temp != 0)
	{
		numerator /= temp;
		denominator /= temp;
	}
}

//PreCondition: a Rational object
//PostCondition: negated the rational number  
void Rational::negate(Rational& obj)
{
	obj.setNumerator(numerator * -1);
}


//******************************* Acesssor *********************************//

//PreCondition: NA
//PostCondition: return the numerator private member
int Rational::getNumerator() const
{
	return numerator;
}

//PreCondition: NA
//PostCondition: return the denominator private member
int Rational::getDenominator() const
{
	return denominator;
}

//******************************* Mutator *********************************//

//PreCondition: an interger value
//PostCondition: set the values of the numerator private member
void Rational::setNumerator(int newN)
{
	numerator = newN;
}

//PreCondition: an interger value
//PostCondition: set the values of the denominator private member
void Rational::setDenominator(int newD)
{
	denominator = newD;
}

//******************************* Overloading Operator **************************//

//PreCondition: 2 Rational objects
//PostCondition: return a the object that is the copy of the original object
const Rational Rational::operator =(const Rational& right) 
{
	if (this != &right)
	{
		numerator = right.numerator;
		denominator = right.denominator;
	}

	return *this;
}

//PreCondition: 2 Rational objects
//PostCondition: return a the object that is the result of the multiplication of the 2 rational objects
Rational operator *(const Rational& obj1, const Rational& obj2)
{
	Rational temp;

	temp.numerator = obj1.numerator * obj2.numerator;
	temp.denominator = obj1.denominator * obj2.denominator;

	temp.normalize();

	return temp;
}

//PreCondition: 2 Rational objects
//PostCondition: return a the object that is the result of the division of the 2 rational objects
Rational operator /(const Rational& obj1, const Rational& obj2)
{
	Rational temp;

	temp.numerator = obj1.numerator * obj2.denominator;
	temp.denominator = obj1.denominator * obj2.numerator;

	temp.normalize();

	return temp;
}

//PreCondition: 2 Rational objects
//PostCondition: return a the object that is the result of sum of the 2 rational objects
Rational operator +(const Rational& obj1, const Rational& obj2)
{
	Rational temp;
	
	temp.denominator = obj1.denominator * obj2.denominator;

	temp.numerator = (obj1.numerator * obj2.denominator) + (obj2.numerator * obj1.denominator);

	temp.normalize();

	return temp;
}

//PreCondition: 2 Rational objects
//PostCondition: return a the object that is the difference of the 2 rational objects
Rational operator -(const Rational& obj1, const Rational& obj2)
{
	Rational temp;

	temp.denominator = obj1.denominator * obj2.denominator;

	temp.numerator = (obj1.numerator * obj2.denominator) - (obj2.numerator * obj1.denominator);

	temp.normalize();

	return temp;
}

//PreCondition: a Rational object, with an interger
//PostCondition: return a the object that is the sum of a rational object and a number
Rational operator +(const Rational& obj, const int number)
{
	Rational temp;

	temp.numerator = obj.numerator + (number * obj.denominator);
	temp.denominator = obj.denominator;

	return temp;
}

//PreCondition:  an interger with an Rational object
//PostCondition: return a the object that is the sum of a number and a rational object
Rational operator +(const int number, const Rational& obj)
{
	Rational temp;

	temp.numerator = obj.numerator + (number * obj.denominator);
	temp.denominator = obj.denominator;

	return temp;
}


//PreCondition: a Rational object, with an interger
//PostCondition: return a the object that is the differences of a rational object and a number
Rational operator -(const Rational& obj, const int number)
{
	Rational temp;

	temp.numerator = obj.numerator - (number * obj.denominator);
	temp.denominator = obj.denominator;

	return temp;
}

//PreCondition: an interger with an Rational object
//PostCondition: return a the object that is the differences of a number and a rational object
Rational operator -(const int number, const Rational& obj)
{
	Rational temp;

	temp.numerator = (number * obj.denominator) - obj.numerator;
	temp.denominator = obj.denominator;

	return temp;
}

//PreCondition: a Rational object, with an interger
//PostCondition: return a the object that is the multiplicaton of a rational object and a number
Rational operator *(const Rational& obj, const int number)
{
	Rational temp;

	temp.numerator = obj.numerator * number;
	temp.denominator = obj.denominator;

	return temp;
}

//PreCondition:  an interger with an Rational object
//PostCondition: return a the object that is the mutilplication of a number and a rational object
Rational operator *(const int number, const Rational& obj)
{
	Rational temp;

	temp.numerator = obj.numerator * number;
	temp.denominator = obj.denominator;

	return temp;
}

//PreCondition: a Rational object, with an interger
//PostCondition: return a the object that is the division of a rational object and a number
Rational operator /(const Rational& obj, const int number)
{
	Rational temp;

	temp.numerator = obj.numerator;
	temp.denominator = obj.denominator * number;

	return temp;
}

//PreCondition: a Rational object, with an interger
//PostCondition: return a the object that is the division of a number and a rational object
Rational operator /(const int number, const Rational& obj)
{
	Rational temp;

	temp.numerator = obj.denominator * number;
	temp.denominator = obj.numerator;

	return temp;
}

//PreCondition: 2 Rational objects
//PostCondition: return a flag that compares two Rational numbers are equal
bool operator ==(const Rational& obj1, const Rational& obj2)
{
	return (obj1.numerator * obj2.denominator) == (obj2.numerator * obj1.denominator);
}

//PreCondition: 2 Rational objects
//PostCondition: return a flag which indicate one is lesser than another.
bool operator <(const Rational& obj1, const Rational& obj2)
{
	return (obj1.numerator * obj2.denominator) < (obj2.numerator * obj1.denominator);
}

//PreCondition: 2 Rational objects
//PostCondition: return a flag which indicate one is greater than another.
bool operator >(const Rational& obj1, const Rational& obj2)
{
	return (obj1.numerator * obj2.denominator) > (obj2.numerator * obj1.denominator);
}

//PreCondition: 2 Rational objects
//PostCondition: return a flag which indicate one is greater or equal to than another.
bool operator >=(const Rational& obj1, const Rational& obj2)
{
	return (obj1.numerator * obj2.denominator) >= (obj2.numerator * obj1.denominator);
}

//PreCondition: 2 Rational objects
//PostCondition: return a flag which indicate one is greater or equal to than another.
bool operator <=(const Rational& obj1, const Rational& obj2)
{
	return (obj1.numerator * obj2.denominator) <= (obj2.numerator * obj1.denominator);
}

//PreCondition: 2 Rational objects
//PostCondition: return a flag which indicate one different from another.
bool operator !=(const Rational& obj1, const Rational& obj2)
{
	return (obj1.numerator * obj2.denominator) != (obj2.numerator * obj1.denominator);
}

//PreCondition: a ostream object and a Rational object
//PostCondition: return the object that used for display 
ostream& operator << (ostream& out, Rational obj)
{
	out << obj.toString();
	return out;
}

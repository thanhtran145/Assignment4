#pragma once
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// A rational number is a number that is expressed as the ratio of two integers, where the denominator should not be equal to zero.
// Rational class is designed to expressed the rational number in the form of (numerator) / (denominator) 
class Rational
{
private:
	int numerator;
	int denominator;

	int gcd(int a, int b);

public:

	// ZeroDenominator is used to throw an exception if the denominator is zero.
	class ZeroDenominator
	{
	private:
		string rational;
	public:
		ZeroDenominator()
		{}

		ZeroDenominator(Rational r)
		{
			rational = r.toString();
		}

		string toString()
		{
			return rational;
		}
	};

	Rational();
	Rational(int, int);
	Rational(const Rational&);

	string toString();
	int getNumerator() const;
	int getDenominator() const;

	void normalize();
	void setNumerator(int);
	void setDenominator(int);
	void negate(Rational &);

	const Rational operator =(const Rational&);
	friend Rational operator +(const Rational& obj, const int number);
	friend Rational operator +(const int number, const Rational& obj);
	friend Rational operator -(const int number, const Rational& obj);
	friend Rational operator -(const Rational& obj, const int number);

	friend Rational operator *(const Rational& obj, const int number);
	friend Rational operator *(const int number, const Rational& obj);
	friend Rational operator /(const Rational& obj, const int number);
	friend Rational operator /(const int number, const Rational& obj);

	friend Rational operator *(const Rational& obj1, const Rational& obj2);
	friend Rational operator /(const Rational& obj1, const Rational& obj2);
	friend Rational operator +(const Rational& obj1, const Rational& obj2);
	friend Rational operator -(const Rational& obj1, const Rational& obj2);

	
	friend bool operator ==(const Rational& obj1, const Rational& obj2);
	friend bool operator <(const Rational& obj1, const Rational& obj2);
	friend ostream& operator << (ostream& out, Rational obj);
};




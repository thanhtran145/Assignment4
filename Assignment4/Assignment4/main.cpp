// Name: Thanh Tran
// Date: 09/20/2023
// Desciption: Chapter 4 - Assignments 4

//Credit:
//Joe Bryant& Erik Santana 
//Saul Merino & John Kim 
//Otoniel Torres Bernal
//Christian Hernandez

#include <iostream>
#include "input.h"
#include "Rational.h"

using namespace std;

// Function Prototypes
void rational_menu();
void rational_option_a();

// Main Function
int main()
{
	// Main Menu and Options
	do
	{
		system("cls");
		cout << "\n\tCMPR131 Chapter 4: Complex Numbers, Rational Numbers, Polynomials by Thanh Tran (09/20/21)";
		cout << "\n\t" + string(90, char(205));
		cout << "\n\t\t1> Complex Numbers";
		cout << "\n\t\t2> Rational Numbers";
		cout << "\n\t\t3> Polynomials";

		cout << "\n\t" + string(90, char(196));
		cout << "\n\t\t0. exit";
		cout << "\n\t" + string(90, char(205));

		switch (toupper(inputChar("\n\t\tOption: ", static_cast<string>("1230"))))
		{
		case '0': exit(1); break;
		case '1': break;
		case '2': rational_menu(); break;
		case '3': break;
		default: cout << "\t\tERROR - Invalid option."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

	return EXIT_SUCCESS;
}

void rational_menu()
{
	do 
	{
		system("cls");
		cout << "\n\tA rational number is a number that can be written as a fraction, a/b, where a is numerator and";
		cout << "\n\tb is denominator. Rational numbers are all real numbers, and can be positive or negative. A";
		cout << "\n\tnumber that is not rational is called irrational. Most of the numbers that people use in everyday";
		cout << "\n\tlife are rational.These include fractions, integers and numbers with finite decimal digits.";
		cout << "\n\tIn general, a number that can be written as a fraction while it is in its own form is rational.\n";
		cout << "\n\t2> Rational Numbers";
		cout << "\n\t" + string(100, char(205));
		cout << "\n\t\t A> A Rational Number";
		cout << "\n\t\t B> Multiple Rational Numbers";
		cout << "\n\t" + string(100, char(196));
		cout << "\n\t\t 0> return";
		cout << "\n\t" + string(100, char(205));

		switch (toupper(inputChar("\n\t\tOption: ", static_cast<string>("AB0"))))
		{
		case 'A': system("cls"); rational_option_a(); break;
		case 'B': break;
		case '0': return;
		default: cout << "\t\tERROR - Invalid option."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);
}

void rational_option_a()
{
	Rational rational1;
	Rational rational2;
	int number = 0;

	do
	{
		system("cls");
		cout << "\n\tA> A Rational Number";
		cout << "\n\t" + string(90, char(205));
		cout << "\n\t\t1. Enter the numerator";
		cout << "\n\t\t2. Enter the deminator";
		cout << "\n\t\t3. Display the rational number";
		cout << "\n\t\t4. Normalize the rational number";
		cout << "\n\t\t5. Negate the rational number";
		cout << "\n\t\t6. Add (+) the rational number with a constant";
		cout << "\n\t\t7. Subtract (-) the rational number with a constant";
		cout << "\n\t\t8. Multiply (*) the rational number with a constant";
		cout << "\n\t\t9. Divide(/) the rational number with a constant";
		
		cout << "\n\t" + string(90, char(196));
		cout << "\n\t\t0> return";
		cout << "\n\t" + string(90, char(205));

		switch (inputInteger("\n\t\tOption: ", 0, 9))
		{
		case 1: 
			rational1.setNumerator(inputInteger("\n\t\tEnter an integer for the numerator: "));

			break;
		case 2: 

			try
			{
				int denominator = inputInteger("\n\t\tEnter an integer for the denominator: ");

				// validation
				if (denominator == 0)
				{
					throw Rational::ZeroDenominator();
				}

				rational1.setDenominator(denominator);
			}
			catch (Rational::ZeroDenominator)
			{
				cout << "\n\t\tEXCEPTIONAL ERROR: Cannot have this Rational number with a zero denominator value.\n";
			}
			
			break;
		case 3:

			cout << "\n\t\tRational number R1 = " << rational1.toString() << "\n";

			break;
		case 4:

			rational2 = rational1;
			rational2.normalize();

			cout << "\n\t\tNormalized rational number R2 (a copy of R1)\n";
			cout << "\n\t\t" << rational2 << "\n";

			break;
		case 5:

			rational2 = rational1;
			rational2.negate(rational2);

			cout << "\n\t\tNormalized rational number R2 (a copy of R1)\n";
			cout << "\n\t\t-(" << rational1 << ") = " << rational2 << "\n";
	
			break;
		case 6:

			rational2 = rational1;
			number = inputInteger("\n\t\tEnter an integer value: ");

			rational2 = rational2 + number;
			rational2.normalize();

			cout << "\n\t\tR2 + value";
			cout << "\n\t\t(" + rational1.toString() + ") + " << number << " = " << rational2 << '\n';
			
			rational2 = rational1;
			rational2 = number + rational2;
			rational2.normalize();

			cout << "\n\t\tvalue + R2";
			cout << "\n\t\t" << number << " + (" << rational1 << ") = " << rational2 << '\n';

			break;
		case 7:

			rational2 = rational1;
			number = inputInteger("\n\t\tEnter an integer value: ");

			rational2 = rational2 - number;
			rational2.normalize();

			cout << "\n\t\tR2 - value";
			cout << "\n\t\t(" + rational1.toString() + ") - " << number << " = " << rational2 << '\n';

			rational2 = rational1;
			rational2 = number - rational2;
			rational2.normalize();

			cout << "\n\t\tvalue - R2";
			cout << "\n\t\t" << number << " - (" << rational1 << ") = " << rational2 << '\n';

			break;
		case 8:

			rational2 = rational1;
			number = inputInteger("\n\t\tEnter an integer value: ");

			rational2 = rational2 * number;
			rational2.normalize();

			cout << "\n\t\tR2 * value";
			cout << "\n\t\t(" + rational1.toString() + ") * " << number << " = " << rational2 << '\n';

			rational2 = rational1;
			rational2 = number * rational2;
			rational2.normalize();

			cout << "\n\t\tvalue * R2";
			cout << "\n\t\t" << number << " * (" << rational1 << ") = " << rational2 << '\n';

			break;
		case 9:

			rational2 = rational1;
			number = inputInteger("\n\t\tEnter an integer value: ");

			rational2 = rational2 / number;
			rational2.normalize();

			cout << "\n\t\tR2 / value";
			cout << "\n\t\t(" + rational1.toString() + ") / " << number << " = " << rational2 << '\n';

			rational2 = rational1;
			rational2 = number / rational2;
			rational2.normalize();

			cout << "\n\t\tvalue / R2";
			cout << "\n\t\t" << number << " / (" << rational1 << ") = " << rational2 << '\n';

			break;
		case 0: return;
		default: cout << "\t\tERROR - Invalid option."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);
}

		
/*------------------------------------------------------------------------------------------------*/
/*                                                                                                */
/* Chapter 4 | Project 8                                                                          */
/* Write a program like that of the previous exercise that converts from kilograms and            */
/* grams into pounds and ounces. Use functions for the subtasks.                                  */
/*                                                                                                */
/* Author: Eng. Rafael Del Pino                                                                   */
/*                                                                                                */
/*------------------------------------------------------------------------------------------------*/
#include <iostream>

using namespace std;

void Input(double& in_kg, double& in_g);
void Output(double in_kg, double in_g);
double KilogramToPound(double kilogram);
double KilogramToOunce(double kilogram);
double GramToPound(double gram);
double GramToOunce(double gram);

int main()
{
    double weight_kg = 0.0;
    double weight_g = 0.0;
    char continueAnswer = 0;

    do {
        Input(weight_kg, weight_g);
        Output(weight_kg, weight_g);
    } while (std::cout << "Calculate again? (y/n) ",
        std::cin >> continueAnswer,
        continueAnswer == 'y');

    return 0;
}

void Input(double& in_kg, double& in_g)
{
    cout << "Type a weight value (kg): ";
    cin >> in_kg;

    cout << "Type a weight value (g): ";
    cin >> in_g;
}

void Output(double in_kg, double in_g)
{
    // Set decimal number notation
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << in_kg << " kg = " << KilogramToPound(in_kg) << " lb" << endl;
    cout << in_kg << " kg = " << KilogramToOunce(in_kg) << " oz" << endl;
    cout << in_g << " g = "   << GramToPound(in_g)      << " lb" << endl;
    cout << in_g << " g = "   << GramToOunce(in_g)      << " oz" << endl;
}

double KilogramToPound(double kilogram)
{
    // There are 2.2046 pounds in a kilogram
    const double ONE_KILOGRAM_IS_POUND = 2.2046;

    return kilogram * ONE_KILOGRAM_IS_POUND;
}

double KilogramToOunce(double kilogram)
{
	// There are 2.2046 pounds in a kilogram
    const double ONE_KILOGRAM_IS_POUND = 2.2046;

    // There are 16 ounces in a pound
    const double ONE_POUND_IS_OUNCE = 16;
    
    const double ONE_KILOGRAM_IS_OUNCE = ONE_KILOGRAM_IS_POUND * ONE_POUND_IS_OUNCE;
    return kilogram * ONE_KILOGRAM_IS_OUNCE;
}

double GramToPound(double gram)
{
	// There are 2.2046 pounds in a kilogram
    const double ONE_KILOGRAM_IS_POUND = 2.2046;
	
	// There are 1000 grams in a kilogram
    const double ONE_KILOGRAM_IS_GRAM = 1000;
	
	const double ONE_GRAM_IS_POUND = ONE_KILOGRAM_IS_POUND / ONE_KILOGRAM_IS_GRAM;
    return gram * ONE_GRAM_IS_POUND;
}

double GramToOunce(double gram)
{
    // There are 2.2046 pounds in a kilogram
    const double ONE_KILOGRAM_IS_POUND = 2.2046;

    // There are 16 ounces in a pound
    const double ONE_POUND_IS_OUNCE = 16;

    // There are 1000 grams in a kilogram
    const double ONE_KILOGRAM_IS_GRAM = 1000;

    const double ONE_GRAM_IN_OUNCE = (ONE_KILOGRAM_IS_POUND * ONE_POUND_IS_OUNCE) / ONE_KILOGRAM_IS_GRAM;
    return gram * ONE_GRAM_IN_OUNCE;
}
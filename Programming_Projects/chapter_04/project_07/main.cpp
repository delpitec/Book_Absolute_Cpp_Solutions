/*------------------------------------------------------------------------------------------------*/
/*                                                                                                */
/* Chapter 4 | Project 7                                                                          */
/* Write a program that will read in a weight in pounds and ounces and will output                */
/* the equivalent weight in kilograms and grams. Use at least three functions: one for            */
/* input, one or more for calculating, and one for output. Include a loop that lets               */
/* the user repeat this computation for new input values until the user says he or she            */
/* wants to end the program. There are 2.2046 pounds in a kilogram, 1000 grams in                 */
/* a kilogram, and 16 ounces in a pound.                                                          */
/*                                                                                                */
/* Author: Eng. Rafael Del Pino                                                                   */
/*                                                                                                */
/*------------------------------------------------------------------------------------------------*/

#include <iostream>

using namespace std;

void Input(double& in_lb, double& in_oz);
void Output(double in_lb, double in_oz);
double PoundToKilogram(double pound);
double PoundToGram(double pound);
double OunceToKilogram(double ounce);
double OunceToGram(double ounce);

int main()
{
    double weight_lb = 0.0;
    double weight_oz = 0.0;
    char continueAnswer = 0;

    do {
        Input(weight_lb, weight_oz);
        Output(weight_lb, weight_oz);
    } while (std::cout << "Calculate again? (y/n) ",
        std::cin >> continueAnswer,
        continueAnswer == 'y');

    return 0;
}

void Input(double& in_lb, double& in_oz)
{
    cout << "Type a weight value (lb): ";
    cin >> in_lb;

    cout << "Type a weight value (oz): ";
    cin >> in_oz;
}

void Output(double in_lb, double in_oz)
{
    // Set decimal number notation
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << in_lb << " lb = " << PoundToKilogram(in_lb) << " kg" << endl;
    cout << in_lb << " lb = " << PoundToGram(in_lb) << " g" << endl;
    cout << in_oz << " oz = " << OunceToKilogram(in_oz) << " kg" << endl;
    cout << in_oz << " oz = " << OunceToGram(in_oz) << " g" << endl;
}

double PoundToKilogram(double pound)
{
    // There are 2.2046 pounds in a kilogram
    const double ONE_KILOGRAM_IS_POUND = 2.2046;

    return pound / ONE_KILOGRAM_IS_POUND;
}

double PoundToGram(double pound)
{
    // There are 2.2046 pounds in a kilogram
    const double ONE_KILOGRAM_IS_POUND = 2.2046;

    // There are 1000 grams in a kilogram
    const double ONE_KILOGRAM_IS_GRAM = 1000;

    const double ONE_GRAM_IS_POUND = ONE_KILOGRAM_IS_POUND / ONE_KILOGRAM_IS_GRAM;
    return pound / ONE_GRAM_IS_POUND;
}

double OunceToKilogram(double ounce)
{
    // There are 2.2046 pounds in a kilogram
    const double ONE_KILOGRAM_IS_POUND = 2.2046;

    // There are 16 ounces in a pound
    const double ONE_POUND_IS_OUNCE = 16;

    const double ONE_KILOGRAM_IN_OUNCE = ONE_KILOGRAM_IS_POUND * ONE_POUND_IS_OUNCE;
    return ounce / ONE_KILOGRAM_IN_OUNCE;
}

double OunceToGram(double ounce)
{
    // There are 2.2046 pounds in a kilogram
    const double ONE_KILOGRAM_IS_POUND = 2.2046;

    // There are 16 ounces in a pound
    const double ONE_POUND_IS_OUNCE = 16;

    // There are 1000 grams in a kilogram
    const double ONE_KILOGRAM_IS_GRAM = 1000;

    const double ONE_GRAM_IN_OUNCE = (ONE_KILOGRAM_IS_POUND * ONE_POUND_IS_OUNCE) / ONE_KILOGRAM_IS_GRAM;
    return ounce / ONE_GRAM_IN_OUNCE;
}
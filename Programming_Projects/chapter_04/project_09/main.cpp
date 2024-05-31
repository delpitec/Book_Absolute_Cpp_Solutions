/*------------------------------------------------------------------------------------------------*/
/*                                                                                                */
/* Chapter 4 | Project 9                                                                          */
/* (You should do the previous two programming projects before doing this one.)                   */
/* Write a program that combines the functions of the previous two programming                    */
/* projects. The program asks the user if he or she wants to convert from pounds                  */
/* and ounces to kilograms and grams or from kilograms and grams to pounds and                    */
/* ounces. The program then performs the desired conversion. Have the user respond                */
/* by typing the integer 1 for one type of conversion and 2 for the other. The program            */
/* reads the user’s answer and then executes an if-else statement. Each branch of                 */
/* the if-else statement will be a function call. The two functions called in the                 */
/* if-else statement will have function definitions that are very similar to the programs         */
/* for the previous two programming projects. Thus, they will be fairly complicated               */
/* function definitions that call other functions in their function bodies. Include a             */
/* loop that lets the user repeat this computation for new input values until the user            */
/* says he or she wants to end the program.                                                       */
/* Author: Eng. Rafael Del Pino                                                                   */
/*                                                                                                */
/*------------------------------------------------------------------------------------------------*/
#include <iostream>

using namespace std;

void InputFromImperial(double& in_lb, double& in_oz);
void OutputToMetric(double in_lb, double in_oz);
void InputFromMetric(double& in_kg, double& in_g);
void OutputToImperial(double in_kg, double in_g);
double PoundToKilogram(double pound);
double PoundToGram(double pound);
double OunceToKilogram(double ounce);
double OunceToGram(double ounce);
double KilogramToPound(double kilogram);
double KilogramToOunce(double kilogram);
double GramToPound(double gram);
double GramToOunce(double gram);

int main()
{
    char continueAnswer = 0;
    unsigned int convertion = 0;

    do {
        cout << "Choose the convertion: (1) lb and oz to kg and g or (2) kg and g to lb and oz [1/2]: ";
        cin >> convertion;

        if (convertion == 1)
        {
            double weight_lb = 0.0;
            double weight_oz = 0.0;
            InputFromImperial(weight_lb, weight_oz);
            OutputToMetric(weight_lb, weight_oz);
        }
        else if (convertion == 2)
        {
            double weight_kg = 0.0;
            double weight_g = 0.0;
            InputFromMetric(weight_kg, weight_g);
            OutputToImperial(weight_kg, weight_g);
        }
        else
        {
            ;
        }
    } while (std::cout << "Calculate again? (y/n) ",
        std::cin >> continueAnswer,
        continueAnswer == 'y');

    return 0;
}

void InputFromImperial(double& in_lb, double& in_oz)
{
    cout << "Type a weight value (lb): ";
    cin >> in_lb;

    cout << "Type a lengh value (oz): ";
    cin >> in_oz;
}

void OutputToMetric(double in_lb, double in_oz)
{
    // Set decimal number notation
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << in_lb << " lb = " << PoundToKilogram(in_lb) << " kg" << endl;
    cout << in_lb << " lb = " << PoundToGram(in_lb)     << " g"  << endl;
    cout << in_oz << " oz = " << OunceToKilogram(in_oz) << " kg" << endl;
    cout << in_oz << " oz = " << OunceToGram(in_oz)     << " g"  << endl;
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

void InputFromMetric(double& in_kg, double& in_g)
{
    cout << "Type a weight value (kg): ";
    cin >> in_kg;

    cout << "Type a weight value (g): ";
    cin >> in_g;
}

void OutputToImperial(double in_kg, double in_g)
{
    // Set decimal number notation
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << in_kg << " kg = " << KilogramToPound(in_kg) << " lb" << endl;
    cout << in_kg << " kg = " << KilogramToOunce(in_kg) << " oz" << endl;
    cout << in_g  << " g = "  << GramToPound(in_g)      << " lb" << endl;
    cout << in_g  << " g = "  << GramToOunce(in_g)      << " oz" << endl;
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
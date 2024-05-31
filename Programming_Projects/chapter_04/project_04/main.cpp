/*------------------------------------------------------------------------------------------------*/
/*                                                                                                */
/* Chapter 4 | Project 4                                                                          */
/* Write a program that will read in a length in feet and inches and output the equivalent        */
/* length in meters and centimeters. Use at least three functions: one for input,                 */
/* one or more for calculating, and one for output. Include a loop that lets the user             */
/* repeat this computation for new input values until the user says he or she wants to            */
/* end the program. There are 0.3048 meters in a foot, 100 centimeters in a meter,                */
/* and 12 inches in a foot.                                                                       */
/*                                                                                                */
/* Author: Eng. Rafael Del Pino                                                                   */
/*                                                                                                */
/*------------------------------------------------------------------------------------------------*/
#include <iostream>

using namespace std;

void Input(double& in_ft, double& in_in);
double FeetToMeter(double feet);
double FeetToCentimeter(double feet);
double InchToCentimeter(double inch);
double InchToMeter(double inch);
void Output(double in_ft, double in_in);

int main()
{
    double lenght_ft = 0.0;
    double lenght_in = 0.0;
    char continueAnswer = 0;

    do {
        Input(lenght_ft, lenght_in);
        Output(lenght_ft, lenght_in);
    } while (std::cout << "Calculate again? (y/n) ",
        std::cin >> continueAnswer,
        continueAnswer == 'y');

    return 0;
}

void Input(double& in_foot, double& in_inch)
{
    cout << "Type a lengh value (ft): ";
    cin >> in_foot;

    cout << "Type a lengh value (in): ";
    cin >> in_inch;
}

double FeetToMeter(double feet)
{
    // There are 0.3048 meters in a foot
    const double ONE_FOOT_IS_METER = 0.3048;

    return feet * ONE_FOOT_IS_METER;
}

double FeetToCentimeter(double feet)
{
    // There are 0.3048 meters in a foot
    const double ONE_FOOT_IS_METER = 0.3048;

    // There are 100 centimeters in a meter
    const double ONE_METER_IS_CM = 100;

    const double ONE_FEET_IS_CENTIMETER = ONE_FOOT_IS_METER * ONE_METER_IS_CM;
    return feet * ONE_FEET_IS_CENTIMETER;
}

double InchToMeter(double inch)
{
    // There are 0.3048 meters in a foot 
    const double ONE_FOOT_IS_METER = 0.3048;
    
    // There are 12 inches in a foot.
    const double ONE_FEET_IS_INCH = 12;

    const double ONE_INCH_IS_METER = ONE_FOOT_IS_METER / ONE_FEET_IS_INCH;
    return inch * ONE_INCH_IS_METER;
}

double InchToCentimeter(double inch)
{
    // There are 0.3048 meters in a foot and 12 inches in a foot.
    const double ONE_INCH_IS_METER = 0.3048 / 12;

    // There are 100 centimeters in a meter
    const double ONE_METER_IS_CM = 100;

    return(inch * ONE_INCH_IS_METER * ONE_METER_IS_CM);
}

void Output(double in_ft, double in_in)
{
    // Set decimal number notation
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << in_ft << " ft = " << FeetToMeter(in_ft)      << " m" << endl;
    cout << in_ft << " ft = " << FeetToCentimeter(in_ft) << " cm" << endl;
    cout << in_in << " in = " << InchToMeter(in_in)      << " m" << endl;
    cout << in_in << " in = " << InchToCentimeter(in_in) << " cm" << endl;
}

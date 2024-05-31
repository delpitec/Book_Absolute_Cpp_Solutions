/*------------------------------------------------------------------------------------------------*/
/*                                                                                                */
/* Chapter 4 | Project 5                                                                          */
/* Write a program like that of the previous exercise that converts from meters and centimeters   */
/* into feet and inches. Use functions for the subtasks.                                          */
/*                                                                                                */
/* Author: Eng. Rafael Del Pino                                                                   */
/*                                                                                                */
/*------------------------------------------------------------------------------------------------*/
#include <iostream>

using namespace std;

void Input(double& in_ft, double& in_in);
double MeterToFeet(double meter);
double MeterToInch(double meter);
double CentimeterToFeet(double centimeter);
double CentimeterToInch(double centimeter);
void Output(double in_ft, double in_in);

int main()
{
    double lenght_m = 0.0;
    double lenght_cm = 0.0;
    char continueAnswer = 0;

    do {
        Input(lenght_m, lenght_cm);
        Output(lenght_m, lenght_cm);
    } while (std::cout << "Calculate again? (y/n) ",
        std::cin >> continueAnswer,
        continueAnswer == 'y');

    return 0;
}

void Input(double& in_meter, double& in_centimeter)
{
    cout << "Type a lengh value (m): ";
    cin >> in_meter;

    cout << "Type a lengh value (cm): ";
    cin >> in_centimeter;
}

double MeterToFeet(double meter)
{
    // There are 0.3048 meters in a foot
    const double ONE_FOOT_IS_METER = 0.3048;

    return meter / ONE_FOOT_IS_METER;
}

double MeterToInch(double meter)
{
    // There are 0.3048 meters in a foot and 12 inches in a foot.
    const double ONE_INCH_IS_METER = 0.3048 / 12;

    return meter / ONE_INCH_IS_METER;
}

double CentimeterToFeet(double centimeter)
{
    // There are 0.3048 meters in a foot
    const double ONE_FOOT_IS_METER = 0.3048;

    // There are 100 centimeters in a meter
    const double ONE_METER_IS_CM = 100;

    const double ONE_FEET_IS_CENTIMETER = ONE_FOOT_IS_METER * ONE_METER_IS_CM;
    return centimeter / ONE_FEET_IS_CENTIMETER;
}

double CentimeterToInch(double centimeter)
{
    // There are 0.3048 meters in a foot and 12 inches in a foot.
    const double ONE_INCH_IS_METER = 0.3048 / 12;

    // There are 100 centimeters in a meter
    const double ONE_METER_IS_CM = 100;

    return centimeter / (ONE_INCH_IS_METER * ONE_METER_IS_CM);
}

void Output(double in_m, double in_cm)
{
    // Set decimal number notation
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << in_m  << " = "  << MeterToFeet(in_m)      << " ft" << endl;
    cout << in_m  << " = "  << MeterToInch(in_m)      << " in" << endl;
    cout << in_cm << " = " << CentimeterToFeet(in_cm) << " ft" << endl;
    cout << in_cm << " = " << CentimeterToInch(in_cm) << " in" << endl;
}

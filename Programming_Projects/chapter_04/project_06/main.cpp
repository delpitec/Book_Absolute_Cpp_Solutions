/*------------------------------------------------------------------------------------------------*/
/*                                                                                                */
/* Chapter 4 | Project 6                                                                          */
/* (You should do the previous two programming projects before doing this one.)                   */
/* Write a program that combines the functions in the previous two programming                    */
/* projects. The program asks the user if he or she wants to convert from feet and                */
/* inches to meters and centimeters or from meters and centimeters to feet and inches.            */
/* The program then performs the desired conversion. Have the user respond by typing              */
/* the integer 1 for one type of conversion and 2 for the other conversion. The                   */
/* program reads the user’s answer and then executes an if-else statement. Each                   */
/* branch of the if-else statement will be a function call. The two functions called              */
/* in the if-else statement will have function definitions that are very similar to               */
/* the programs for the previous two programming projects. Thus, they will be fairly              */
/* complicated function definitions that call other functions. Include a loop that lets           */
/* the user repeat this computation for new input values until the user says he or she            */
/* wants to end the program.                                                                      */
/*                                                                                                */
/* Author: Eng. Rafael Del Pino                                                                   */
/*                                                                                                */
/*------------------------------------------------------------------------------------------------*/
#include <iostream>

using namespace std;

void InputFromImperial(double& in_ft, double& in_in);
void OutputToMetric(double in_ft, double in_in);
void InputFromMetric(double& in_ft, double& in_in);
void OutputToImperial(double in_m, double in_cm);
double FeetToMeter(double feet);
double FeetToCentimeter(double feet);
double InchToMeter(double inch);
double InchToCentimeter(double inch);
double MeterToFeet(double meter);
double MeterToInch(double meter);
double CentimeterToFeet(double centimeter);
double CentimeterToInch(double centimeter);

int main()
{
    char continueAnswer = 0;
    unsigned int convertion = 0;

    do {
        cout << "Choose the convertion: (1) ft and in to m and cm or (2) m and cm to ft and in [1/2]: ";
        cin >> convertion;

        if (convertion == 1)
        {
            double lenght_ft = 0.0;
            double lenght_in = 0.0;
            InputFromImperial(lenght_ft, lenght_in);
            OutputToMetric(lenght_ft, lenght_in);
        }
        else if (convertion == 2)
        {
            double lenght_m = 0.0;
            double lenght_cm = 0.0;
            InputFromMetric(lenght_m, lenght_cm);
            OutputToImperial(lenght_m, lenght_cm);
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

void InputFromImperial(double& in_ft, double& in_in)
{
    cout << "Type a lengh value (ft): ";
    cin >> in_ft;

    cout << "Type a lengh value (in): ";
    cin >> in_in;
}

void OutputToMetric(double in_ft, double in_in)
{
    // Set decimal number notation
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << in_ft << " ft = " << FeetToMeter(in_ft)      << " m"  << endl;
    cout << in_ft << " ft = " << FeetToCentimeter(in_ft) << " cm" << endl;
    cout << in_in << " in = " << InchToMeter(in_in)      << " m"  << endl;
    cout << in_in << " in = " << InchToCentimeter(in_in) << " cm" << endl;
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

void InputFromMetric(double& in_m, double& in_cm)
{
    cout << "Type a lengh value (m): ";
    cin >> in_m;

    cout << "Type a lengh value (in): ";
    cin >> in_cm;
}

void OutputToImperial(double in_m, double in_cm)
{
    // Set decimal number notation
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << in_m << " m = "   << MeterToFeet(in_m)       << " ft" << endl;
    cout << in_m << " m = "   << MeterToInch(in_m)       << " in" << endl;
    cout << in_cm << " cm = " << CentimeterToFeet(in_cm) << " ft" << endl;
    cout << in_cm << " cm = " << CentimeterToInch(in_cm) << " in" << endl;
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

/*------------------------------------------------------------------------------------------------*/
/*                                                                                                */
/* Chapter 4 | Project 10                                                                         */
/* (You should do Programming Projects 4.6 and 4.9 before doing this programming                  */
/* project.) Write a program that combines the functions of Programming                           */
/* Projects 4.6 and 4.9. The program asks the user if he or she wants to convert                  */
/* lengths or weights. If the user chooses lengths, then the program asks the user if             */
/* he or she wants to convert from feet and inches to meters and centimeters or from              */
/* meters and centimeters to feet and inches. If the user chooses weights, a similar              */
/* question about pounds, ounces, kilograms, and grams is asked. The program then                 */
/* performs the desired conversion. Have the user respond by typing the integer 1 for             */
/* one type of conversion and 2 for the other. The program reads the user’s answer                */
/* and then executes an if-else statement. Each branch of the if-else statement                   */
/* will be a function call. The two functions called in the if-else statement will                */
/* have function definitions that are very similar to the programs for Programming                */
/* Projects 4.6 and 4.9. Thus, these functions will be fairly complicated function                */
/* definitions that call other functions; however, they will be very easy to                      */
/* write by adapting the programs you wrote for Programming Projects 4.6 and                      */
/* 4.9. Notice that your program will have if-else statements embedded inside of                  */
/* if-else statements, but only in an indirect way. The outer if-else statement                   */
/* will include two function calls, as its two branches. These two function calls will            */
/* each in turn include an if-else statement, but you need not think about that.                  */
/* They are just function calls and the details are in a black box that you create when           */
/* you define these functions. If you try to create a four-way branch, you are probably           */
/* on the wrong track. You should only need to think about two-way branches (even                 */
/* though the entire program does ultimately branch into four cases). Include a loop              */
/* that lets the user repeat this computation for new input values until the user says            */
/* he or she wants to end the program.                                                            */
/*                                                                                                */
/* Author: Eng. Rafael Del Pino                                                                   */
/*                                                                                                */
/*------------------------------------------------------------------------------------------------*/
#include <iostream>

using namespace std;

void ConvertWeight();
void ConvertLenght();
void WeightInputFromImperial(double& in_lb, double& in_oz);
void WeightOutputToMetric(double in_lb, double in_oz);
void WeightInputFromMetric(double& in_kg, double& in_g);
void WeightOutputToImperial(double in_kg, double in_g);
double PoundToKilogram(double pound);
double PoundToGram(double pound);
double OunceToKilogram(double ounce);
double OunceToGram(double ounce);
double KilogramToPound(double kilogram);
double KilogramToOunce(double kilogram);
double GramToPound(double gram);
double GramToOunce(double gram);
void LenghtInputFromImperial(double& in_ft, double& in_in);
void LenghtOutputToMetric(double in_ft, double in_in);
void LenghtInputFromMetric(double& in_ft, double& in_in);
void LenghtOutputToImperial(double in_m, double in_cm);
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
        cout << "Choose the convertion: (1) for lenght or (2) for weight[1/2]: ";
        cin >> convertion;

        if (convertion == 1)
        {
            ConvertLenght();
        }
        else if (convertion == 2)
        {
            ConvertWeight();
        }
    } while (std::cout << "Calculate again? (y/n) ",
        std::cin >> continueAnswer,
        continueAnswer == 'y');

    return 0;
}

void ConvertWeight()
{
    unsigned int convertion = 0;
    
    cout << "Choose the convertion: (1) lb and oz to kg and g or (2) kg and g to lb and oz [1/2]: ";
    cin >> convertion;
    
    if (convertion == 1)
    {
        double weight_lb = 0.0;
        double weight_oz = 0.0;
        WeightInputFromImperial(weight_lb, weight_oz);
        WeightOutputToMetric(weight_lb, weight_oz);
    }
    else if (convertion == 2)
    {
        double weight_kg = 0.0;
        double weight_g = 0.0;
        WeightInputFromMetric(weight_kg, weight_g);
        WeightOutputToImperial(weight_kg, weight_g);
    }
    else
    {
        ;
    }
}

void WeightInputFromImperial(double& in_lb, double& in_oz)
{
    cout << "Type a weight value (lb): ";
    cin >> in_lb;

    cout << "Type a lengh value (oz): ";
    cin >> in_oz;
}

void WeightOutputToMetric(double in_lb, double in_oz)
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

void WeightInputFromMetric(double& in_kg, double& in_g)
{
    cout << "Type a weight value (kg): ";
    cin >> in_kg;

    cout << "Type a weight value (g): ";
    cin >> in_g;
}

void WeightOutputToImperial(double in_kg, double in_g)
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

void ConvertLenght()
{
    unsigned int convertion = 0;

    cout << "Choose the convertion: (1) ft and in to m and cm or (2) m and cm to ft and in [1/2]: ";
    cin >> convertion;

    if (convertion == 1)
    {
        double lenght_ft = 0.0;
        double lenght_in = 0.0;
        LenghtInputFromImperial(lenght_ft, lenght_in);
        LenghtOutputToMetric(lenght_ft, lenght_in);
    }
    else if (convertion == 2)
    {
        double lenght_m = 0.0;
        double lenght_cm = 0.0;
        LenghtInputFromMetric(lenght_m, lenght_cm);
        LenghtOutputToImperial(lenght_m, lenght_cm);
    }
    else
    {
        ;
    }
}

void LenghtInputFromImperial(double& in_ft, double& in_in)
{
    cout << "Type a lengh value (ft): ";
    cin >> in_ft;

    cout << "Type a lengh value (in): ";
    cin >> in_in;
}

void LenghtOutputToMetric(double in_ft, double in_in)
{
    // Set decimal number notation
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << in_ft << " ft = " << FeetToMeter(in_ft) << " m" << endl;
    cout << in_ft << " ft = " << FeetToCentimeter(in_ft) << " cm" << endl;
    cout << in_in << " in = " << InchToMeter(in_in) << " m" << endl;
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

void LenghtInputFromMetric(double& in_m, double& in_cm)
{
    cout << "Type a lengh value (m): ";
    cin >> in_m;

    cout << "Type a lengh value (in): ";
    cin >> in_cm;
}

void LenghtOutputToImperial(double in_m, double in_cm)
{
    // Set decimal number notation
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << in_m << " m = " << MeterToFeet(in_m) << " ft" << endl;
    cout << in_m << " m = " << MeterToInch(in_m) << " in" << endl;
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
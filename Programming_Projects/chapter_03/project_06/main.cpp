/*--------------------------------------------------------------------------------------*/
/*                                                                                      */
/* Chapter 3 | Project 6                                                                */
/* Write a function that computes the average and standard deviation of four scores.    */
/* The standard deviation is defined to be the square root of the average of the four   */
/* values: (s i - a )^2 , where a is the average of the four scores s 1 , s 2 , s 3 ,   */
/* and s4 . The function will have six parameters and will call two other functions.    */
/* Embed the function in a program that allows you to test the function again and again */
/* until you tell the program you are finished.                                         */
/*                                                                                      */
/* Author: Eng. Rafael Del Pino                                                         */
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

double Average(double n1, double n2, double n3, double n4)
{
    return (n1 + n2 + n3 + n4) / 4.0;
}

double AverageDeviation(double avg, double n1, double n2, double n3, double n4)
{
    return (abs(n1 - avg) + abs(n2 - avg) + abs(n3 - avg) + abs(n4 - avg)) / 4.0;
}

double StandardDeviation(double avg, double n1, double n2, double n3, double n4)
{
    return sqrt((pow(n1 - avg, 2) + pow(n2 - avg, 2) + pow(n3 - avg, 2) + pow(n4 - avg, 2)) / 4.0);
}

void PrintAverageDeviationAndStandardDeviation(double avg, double n1, double n2, double n3, double n4)
{
    double averageDeviation = AverageDeviation(avg, n1, n2, n3, n4);
    double standardDeviation = StandardDeviation(avg, n1, n2, n3, n4);
    cout << "Average deviation: " << averageDeviation << endl
         << "Stadard deviation: " << standardDeviation << endl;
}

int main()
{
    double S1 = 0.0;
    double S2 = 0.0;
    double S3 = 0.0;
    double S4 = 0.0;
    char continueAnswer = 0;

    do
    {
        std::cout << "Type fist value....: ";
        std::cin >> S1;
        std::cout << "Type second value..: ";
        std::cin >> S2;
        std::cout << "Type third value...: ";
        std::cin >> S3;
        std::cout << "Type fourth value..: ";
        std::cin >> S4;

        double avarage = Average(S1, S2, S3, S4);

        PrintAverageDeviationAndStandardDeviation(avarage, S1, S2, S3, S4);

    } while (std::cout << "Calculate again? (y/n) ",
        std::cin >> continueAnswer,
        continueAnswer == 'y');

    return 0;
}
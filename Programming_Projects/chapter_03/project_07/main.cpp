/*--------------------------------------------------------------------------------------*/
/*                                                                                      */
/* Chapter 3 | Project 7                                                                */
/* In cold weather, meteorologists report an index called the wind chill factor , which */
/* takes into account the wind speed and the temperature. The index provides a          */
/* measure of the chilling effect of wind at a given air temperature. Wind chill may    */
/* be approximated by the following formula,                                            */
/*                                                                                      */
/*      W = 33 - (((10 * sqrt(v) - v + 10.5)*(33 - t)) / 23.1)                           */
/*                                                                                      */
/*      t = temperature (Celsius degree) Note: t <= 10                                  */
/*      v = wind speed  (m/s)                                                           */
/*                                                                                      */
/* Write a function that returns the wind chill index. Your code should ensure that     */
/* the restriction on the temperature is not violated. Look up some weather reports     */
/* in back issues of a newspaper in your library and compare the wind chill index you   */
/* calculate with the result reported in the newspaper.                                 */
/*                                                                                      */
/* Author: Eng. Rafael Del Pino                                                         */
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
#include <iostream>
#include <cmath>

using namespace std;

double WindChillCalculator(double temp, double spd)
{
   return (33 - (((10.0 * sqrt(spd) - spd + 10.5)*(33.0 - temp)) / 23.1));
}

int main()
{
    double windSpeed = 0.0;
    double temperature = 0.0;

    // Set decimal number notation
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    std::cout << "Type temperature (ºC): ";
    std::cin >> temperature;
    std::cout << "Type wind speed (m/s): ";
    std::cin >> windSpeed;
    
    if (temperature <= 10)
    {
        cout << "Wind chill factor is: " << WindChillCalculator(temperature,windSpeed) << endl;
    }
    else
    {
        cout << "To Wind chill factor calculation, temperature need to be less than 10ºC" << endl;     
    }

    return (0);
}
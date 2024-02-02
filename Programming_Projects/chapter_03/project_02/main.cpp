/*---------------------------------------------------------------------------------------*/
/*                                                                                       */
/* Chapter 3 | Project 2                                                                 */
/* Write a program to gauge the rate of inflation for the past year. The program asks    */
/* for the price of an item (such as a hot dog or a one-carat diamond) both one year     */
/* ago and today. It estimates the inflation rate as the difference in price divided by  */
/* the year-ago price. Your program should allow the user to repeat this calculation     */
/* as often as the user wishes. Define a function to compute the rate of inflation. The  */
/* inflation rate should be a value of type double giving the rate as a percentage, for  */
/* example 5.3 for 5.3%.                                                                 */
/*                                                                                       */
/* Author: Eng. Rafael Del Pino                                                          */
/*                                                                                       */
/*---------------------------------------------------------------------------------------*/
#include <iostream>

using namespace std;

double InflationRate(double oldPrice, double newPrice)
{
    int ret = ((newPrice - oldPrice) / oldPrice)*(100);
    return ret;
}

int main()
{
    
    double oldPrice = 0.0;
    double newPrice = 0.0;
    double percent = 0;
    char continueAnswer = 0;

    // Set decimal number notation
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    do{    
        std::cout << "Type old price (R$): ";
        std::cin >> oldPrice;
        std::cout << "Type new price (R$): ";
        std::cin >> newPrice;
        
        percent = InflationRate(oldPrice, newPrice);
        
        std::cout << "Inflation: " << percent << "%" << std::endl;
    }while(std::cout << "Calculate again? (y/n) ", 
            std::cin >> continueAnswer, 
            continueAnswer == 'y');

    return 0;
}
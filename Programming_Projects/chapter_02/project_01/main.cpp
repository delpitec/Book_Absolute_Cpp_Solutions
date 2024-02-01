/*---------------------------------------------------------------------------------------*/
/*                                                                                       */
/* Chapter 2 | Project 1                                                                 */
/* It is difficult to make a budget that spans several years, because prices are not     */
/* stable. If your company needs 200 pencils per year, you cannot simply use this        */
/* year’s price as the cost of pencils two years from now. Because of inflation the      */
/* cost is likely to be higher than it is today. Write a program to gauge the expected   */
/* cost of an item in a specified number of years. The program asks for the cost of      */
/* the item, the number of years from now that the item will be purchased, and the       */
/* rate of inflation. The program then outputs the estimated cost of the item after      */
/* the specified period. Have the user enter the inflation rate as a percentage, such    */
/* as 5.6 (percent). Your program should then convert the percentage to a decimal        */
/* fraction, such as 0.056, and should use a loop to estimate the price adjusted for     */
/* inflation. ( Hint: Use a loop.)                                                       */
/*                                                                                       */
/* Author: Eng. Rafael Del Pino                                                          */
/*                                                                                       */
/*---------------------------------------------------------------------------------------*/
#include <iostream>

using namespace std;

int main(int ac, char* av[])
{

    double pencilValue = 0.0;
    int estimateYears = 0;
    double inflationRate = 0.0;
    double estimatePencilValue = 0.0;

    // Set decimal number notation 
	cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    std::cout << "Type how much is the pencil unit (R$): ";
    std::cin >> pencilValue; 
    std::cout << "Type how many years from now should the estimate be: ";
    std::cin >> estimateYears; 
    std::cout << "Type the inflation rate (%): ";
    std::cin >> inflationRate; 

    estimatePencilValue = pencilValue;

    for (int i = 0; i < estimateYears; i++){
        estimatePencilValue *= (1 + (inflationRate/100.0)); 
    }

    std::cout << "Estimate value for "<< estimateYears << "years is: R$" << estimatePencilValue << endl;

    return (0);
}
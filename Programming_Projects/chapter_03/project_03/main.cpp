/*---------------------------------------------------------------------------------------*/
/*                                                                                       */
/* Chapter 3 | Project 3                                                                 */
/* Enhance your program from the previous exercise by having it also print out the       */
/* estimated price of the item in one and in two years from the time of the calculation. */
/* The increase in cost over one year is estimated as the inflation rate times the price */
/* at the start of the year. Define a second function to determine the estimated cost    */
/* of an item in a specified number of years, given the current price of the item and    */
/* the inflation rate as arguments.                                                      */
/*                                                                                       */
/* Author: Eng. Rafael Del Pino                                                          */
/*                                                                                       */
/*---------------------------------------------------------------------------------------*/
#include <iostream>

using namespace std;

// Copied and adapted from chap_2_proj_1 example 
double EstimateValueAccordingToInflation(double currentValue, double inflationRate, int estimateYears){
    double estimateItemValue = currentValue;

    for (int i = 0; i < estimateYears; i++){
        estimateItemValue *= (1 + (inflationRate/100.0)); 
    }

    return estimateItemValue;
}

int InflationRate(double oldPrice, double newPrice){
    int ret = ((newPrice - oldPrice) / oldPrice)*(100);
    return ret;
}

int main(){
    
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

        cout << "Inflation: " << percent << "%" << endl 
             << "Estimate value (1st year): R$" << EstimateValueAccordingToInflation(newPrice, percent, 1) << endl
             << "Estimate value (2nd year): R$" << EstimateValueAccordingToInflation(newPrice, percent, 2) << endl;

    }while(std::cout << "Calculate again? (y/n) ", 
            std::cin >> continueAnswer, 
            continueAnswer == 'y');

    return 0;
}
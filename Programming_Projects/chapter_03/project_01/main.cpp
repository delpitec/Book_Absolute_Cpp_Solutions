/*---------------------------------------------------------------------------------------*/
/*                                                                                       */
/* Chapter 3 | Project 1                                                                 */
/* liter is 0.264179 gallons. Write a program that will read in the number of liters     */
/* of gasoline consumed by the user’s car and the number of miles traveled by the        */
/* car and will then output the number of miles per gallon the car delivered. Your       */
/* program should allow the user to repeat this calculation as often as the user wishes. */
/* Define a function to compute the number of miles per gallon. Your program             */
/* should use a globally defined constant for the number of liters per gallon.           */
/*                                                                                       */
/* Author: Eng. Rafael Del Pino                                                          */
/*                                                                                       */
/*---------------------------------------------------------------------------------------*/
#include <iostream>

using namespace std;

double LiterToGallon(double liter){
    const double ONE_LITER_IN_GALLON = 0.264179;   
    return  liter * ONE_LITER_IN_GALLON;
}

int main()
{
    double usedGasL = 0.0;
    double milesTraveled = 0.0;
    double avarege = 0.0;
    char continueAnswer = 0;

    // Set decimal number notation 
	cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    do{
        std::cout << "Type total used gas (L): ";
        std::cin >> usedGasL;
        std::cout << "Type total traveled distance (mi): ";
        std::cin >> milesTraveled;
        
        avarege = milesTraveled / LiterToGallon(usedGasL);
        
        cout << "Avarage: " << avarege << " mi/ga" << endl;

    }while(std::cout << "Calculate again? (y/n) ", 
           std::cin >> continueAnswer, 
           continueAnswer == 'y');
    
    return 0;
}